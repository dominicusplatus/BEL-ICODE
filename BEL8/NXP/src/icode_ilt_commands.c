/*
*         Copyright (c), NXP Semiconductors Gratkorn / Austria
*
*                     (C)NXP Semiconductors
*       All rights are reserved. Reproduction in whole or in part is
*      prohibited without the written consent of the copyright owner.
*  NXP reserves the right to make changes without notice at any time.
* NXP makes no warranty, expressed, implied or statutory, including but
* not limited to any implied warranty of merchantability or fitness for any
*particular purpose, or that the use will not infringe any third party patent,
* copyright or trademark. NXP must not be liable for any loss or damage
*                          arising from its use.
*/

/*
 * IcodeILT.c
 *
 *  Created on: 15.4.2015
 *      Author: nxp53811
 */

/*----------------------------------------------------------------------------------------------
 * Includes
 ---------------------------------------------------------------------------------------------*/
#include <ph_Status.h>
#include <phhwConfig.h>

/* PAL Headers */
#include <phpalI18000p3m3.h>

/*AL Headers*/
#include <phalI18000p3m3.h>

#include <stdio.h>
#include <icode_ilt_ui.h>
#include <icode_ilt_commands.h>

#include <icode_common.h>

#include "math.h"

#ifdef NXPBUILD_ILT_TAG

/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/
#define  NO_TAG_DETECTED                        0
#define  TAG_IN_THE_FIELD                       1
#define  NUMBER_OF_TAGS_OUT_OF_RAGNE            0xFF


/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local function prototypes
 ---------------------------------------------------------------------------------------------*/

/*==============================================================================================
 * FUNCTION: SimpleInventory_18000p3m3
 *
 * Description: Function only detects if some 18000p3m3 tag is placed in the reader's RF field.
 *              Each inventory of the tags starts with BeginRound command.
 *
 * Preconditions: Number of slots is set to 0, because there is necessary only check the tag.
 *                In case more than one tag is placed in the RF field, function BeginRound
 *                returns anti-collision error.
 *
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t SimpleInventory_18000p3m3(parameters_itl_t *pDataParam) // mask is a field
    {
    phStatus_t    status;
    uint8_t       aStoredCRC[] = {0x00,0x00};
    uint8_t       bNumRounds = SIMPLE_INVENTORY_RANGE;

    /* for simple card detection the masked mode is switched off */
    pDataParam->sAccess.bSimpleTagDetectionOnOff = PH_OFF;

    /* BeginRound with one slot */
    status = phpalI18000p3m3_BeginRound(
            pDataParam->pPal,                         /**< [In] Pointer to this layer's parameter structure. */
            1,                                        /**< [In] Divide ratio. */
            pDataParam->sDetectionParam.bModulation,  /**< [In] Cycles per symbol. */
            pDataParam->sDetectionParam.bTRext,       /**< [In] Indicates whether a pilot tone shall be used in the T=>R pre-amble (#PH_ON) or not (#PH_OFF). */
            pDataParam->sDetectionParam.bSelection,   /**< [In] Indicates which tags shall take part of the inventory round. */
            pDataParam->sDetectionParam.bSession,     /**< [In] Indicates the session of the inventory round. */
            0,                                        /**< [In] RFU (1 bit). */
            bNumRounds,                               /**< [In] Indicates the number of slots in a round (2^Q slots). */
            aStoredCRC);                              /**< [Out] Stored CRC of a responding tag. This buffer has to be 2 bytes long. */

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
        pDataParam->sDetectionParam.bTotalTagsFound = TAG_IN_THE_FIELD;
        memcpy(pDataParam->pIdentifier[0].StoredCRC,aStoredCRC, sizeof(aStoredCRC));

        /* copy also the UDI in case the one tag is in the field */
        }
    else if((status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR ||
            (status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
        {
        pDataParam->sDetectionParam.bTotalTagsFound = NUMBER_OF_TAGS_OUT_OF_RAGNE;
        memset(pDataParam->pIdentifier[0].StoredCRC,0xFF, STORED_CRC_BUFFER_LEN);
        }
    else
        {
        pDataParam->sDetectionParam.bTotalTagsFound = NO_TAG_DETECTED;
        }

    return PH_ERR_SUCCESS;
    }


/*==============================================================================================
 * FUNCTION: Inventory_18000p3m3
 *
 * Description: function performs Inventory algorithm, to get list of all the 18000p3m3 tags
 *              placed in the field. Inventory breaks as soon as number of detected tags reaches
 *              limit value MAX_NUM_DETECTED_ITL_TAGS.
 *              UII and CRC are stored to application structure for next processing.
 *              Q parameter which determines number of rounds (initial value of SlotCounter)
 *              is calculated by adaptive algorithm considering current results of detection.
 *              See ISO18000p3m3 specification: Annex G
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Inventory_18000p3m3(parameters_itl_t *pDataParam) // mask is a field
    {
    phStatus_t    status = PH_ERR_INTERNAL_ERROR;
    uint16_t      wNumSlotsDec;
    uint8_t       bCardsPresent;
    uint8_t       * pRxBuffer;
    uint16_t      wRxBitLength;
    /* bQ determines current number of rounds by formula: SlotCounter after BeginRoun or ResizeRound = 2^Q. */
    uint8_t       bQ =  pDataParam->sDetectionParam.bNumRounds;
    uint8_t       aStoredCRC[]={0,0};
    uint8_t       bTemp;

    float32_t	  C = 0.3;  /* constant used in adaptation algorithm. See ISO180003m3 specification Annex G */
    float32_t	  fQ = 4.0; /* float representation of current value of the Q parameter */

    /* for inventory the masked mode is switched on -> to be able to choose tag from batch */
    pDataParam->sAccess.bSimpleTagDetectionOnOff = PH_ON;
    /* set the default number of found tags */
    pDataParam->sDetectionParam.bTotalTagsFound = NO_TAG_DETECTED;

    /* BeginRound with one slot */
    status = phpalI18000p3m3_BeginRound(
            pDataParam->pPal,                         /**< [In] Pointer to this layer's parameter structure. */
            1,                                        /**< [In] Divide ratio. */
            pDataParam->sDetectionParam.bModulation,  /**< [In] Cycles per symbol. */
            pDataParam->sDetectionParam.bTRext,       /**< [In] Indicates whether a pilot tone shall be used in the T=>R pre-amble (#PH_ON) or not (#PH_OFF). */
            pDataParam->sDetectionParam.bSelection,   /**< [In] Indicates which tags shall take part of the inventory round. */
            pDataParam->sDetectionParam.bSession,     /**< [In] Indicates the session of the inventory round. */
            0,                                        /**< [In] RFU (1 bit). */
            bQ,                               /**< [In] Indicates the number of slots in a round (2^Q slots). */
            aStoredCRC);                              /**< [Out] Stored CRC of a responding tag. This buffer has to be 2 bytes long. */

    do
        {
        /* Reset card present state */
        bCardsPresent = PH_OFF;

        /* Calculate number of slots in decimal */
        wNumSlotsDec = (uint16_t)(1 << bQ);

        /* Do for all further requested slots */
        while (wNumSlotsDec--)
            {
        	fQ = round(fQ);
            /* Multiple labels found in current slot */
            if (((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR) ||
                    ((status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR))
                {
                bCardsPresent = PH_ON;
                /* if more tags detected in particular time slot, INCrement float Q
                 * but must not overflow 15 */
                fQ = 15 < fQ + C ? 15 : fQ + C;

                /* Store collision error in case it can't be resolved */
                }
            else
                {
                /* Store timeout error if integrity / collision error has not happened */
                if ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
                    {
                	/* if no tag detected in particular time slot, DEcrement float Q
                	 * but must not underflow zero */
                	fQ = 0 > fQ - C ? 0 : fQ - C;
                    }
                /* Return on success or other errors */
                else
                    {
                    /* More cards are available if this one succeed after a previous integrity error */
                    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
                        {
                        /* Perform ACK */
                        status = phpalI18000p3m3_Ack(
                                pDataParam->pPal,
                                PH_OFF,
                                NULL,
                                &pRxBuffer,
                                &wRxBitLength);
                        }

                    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
                        {
                        bTemp = pDataParam->sDetectionParam.bTotalTagsFound;

                        pDataParam->pIdentifier[bTemp].bNumOfBytesXPC = wRxBitLength/8;

                        memcpy(pDataParam->pIdentifier[bTemp].StoredCRC,aStoredCRC, 2);
                        memcpy(pDataParam->pIdentifier[bTemp].StoredUII,pRxBuffer, pDataParam->pIdentifier[bTemp].bNumOfBytesXPC);

                        if(pDataParam->sDetectionParam.bTotalTagsFound < MAX_NUM_DETECTED_ITL_TAGS)
                        	pDataParam->sDetectionParam.bTotalTagsFound++;
                        else
                        	return ERROR_ILT_OVERFLOW_NUMBER_OF_DETECTED_TAGS;

                        }
                    }
                }

            /* Not the last slot -> Send NextSlot */
            if (wNumSlotsDec > 0)
                {
                /* Send NextSlot command */
                status = phpalI18000p3m3_NextSlot(pDataParam->pPal, aStoredCRC);
                }
            }

        /* Resize the round if possible */
        if ((bCardsPresent != PH_OFF) && (bQ <= MAX_NUM_OF_ROUNDS))
            {
        	/* Do as many ResizeRound increments or decrements as needed until
        	 * bQ representing current Q in tag(s) equals fQ calculated adaptively.
        	 * If they equal, just do ResizeRound without change of Q because SlotCounter counted down to zero.*/
        	do
        		{
        		if(round(fQ) == bQ)
        			{
        				status = phpalI18000p3m3_ResizeRound(
        									pDataParam->pPal,
											PHPAL_I18000P3M3_UPDN_NOCHANGE,
											aStoredCRC);
        			}
        		else
        			{
        			if(round(fQ) > bQ)
        				{
        				status = phpalI18000p3m3_ResizeRound(
        									pDataParam->pPal,
											PHPAL_I18000P3M3_UPDN_INCREMENT,
											aStoredCRC);
						bQ++;
        				}
        			else //(round(Q_float) < bQ--)
        				{
        				status = phpalI18000p3m3_ResizeRound(
        									pDataParam->pPal,
											PHPAL_I18000P3M3_UPDN_DECREMENT,
											aStoredCRC);
        				bQ--;
        				}
					}
        		}
        	while(round(fQ) != bQ);

            }
        }while ((bCardsPresent != PH_OFF) && (bQ <= MAX_NUM_OF_ROUNDS));

    return PH_ERR_SUCCESS;
    }


/*==============================================================================================
 * FUNCTION: Read_18000p3m3
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Read_18000p3m3(parameters_itl_t *pDataParam)
    {
    phStatus_t    status;
    uint8_t       *pRxBuffer;

    /* in case simple card detection, the mask length is set to 0x00 -> not used masked mode */
    if (!pDataParam->sAccess.bSimpleTagDetectionOnOff)
        {
        pDataParam->sDetectionParam.bMaskBitLength = ACTIVATE_CARD_WITHOUT_MASK;
        }

    /* Activate card - command covers Select, Begin_round Ack and Req_RN commands execution,
	 * which are necessary for activation */

    /* Select one particular tag determined by UII 16 bytes long */
    status = phpalI18000p3m3_Select(
    						pDataParam->pPal,
							pDataParam->sDetectionParam.bTarget,
							0,
							PHPAL_I18000P3M3_MEMBANK_UII,
							pDataParam->sDetectionParam.pBitPointer,
							pDataParam->sDetectionParam.bBitPointerLength,
							pDataParam->sDetectionParam.UIIMask,
							pDataParam->sDetectionParam.bMaskBitLength,
							pDataParam->sDetectionParam.bTruncate);

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
    /* Begin round and perform just one round.
     * Selected tag chooses slot num 0 since Q param is 0.
     * Output from successful begin round is used for later Req_RN. */
    status =  phpalI18000p3m3_BeginRound(
    						pDataParam->pPal,
							pDataParam->sDetectionParam.bDivideRatio,
							pDataParam->sDetectionParam.bModulation,
							pDataParam->sDetectionParam.bTRext,
							pDataParam->sDetectionParam.bSelection,
							pDataParam->sDetectionParam.bSession,
							0,//RFU
							0,//Q param
							pDataParam->pAl->abHandle);
        }

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
    /* CRC is ensured by Begin Round */
    status = phpalI18000p3m3_Ack(
    						pDataParam->pPal,
							PHPAL_I18000P3M3_ACK_USE_CRC,
							pDataParam->pAl->abHandle,
							&pDataParam->sTransfer.pRxBuffer,
							&pDataParam->sTransfer.wRxBitLength);
        }

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
    	pDataParam->pAl->bHandleValid = PH_ON;

    	/* Perform Req_Rn. Despite USE_HANDLE macro is passed, in fact CRC is used. */
        status = phalI18000p3m3_ReqRn(pDataParam->pAl,
        							  PHAL_I18000P3M3_REQRN_USE_HANDLE,
									  &pRxBuffer);

        memcpy(pDataParam->pAl->abHandle, pRxBuffer, 2);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
                {
                status = phalI18000p3m3_Access(
                        pDataParam->pAl,                          /**< [In] Pointer to this layer's parameter structure. */
                        pDataParam->sTransfer.bCoverCoding,       /**< [In] Option parameter. */
                        pDataParam->sAccess.pUserAccessPassword); /**< [In] Full access password; uint8_t[4] */
                }

            if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
                {
                status = phalI18000p3m3_Read(
                        pDataParam->pAl,                           /**< [In] Pointer to this layer's parameter structure. */
                        pDataParam->sTransfer.bBankMemory,         /**< [In] Memory bank where the read shall be performed. */
                        pDataParam->sTransfer.pWordPtr,            /**< [In] Starting read adress. */
                        pDataParam->sTransfer.bWordPtrLen,         /**< [In] Length of the pointer in bytes; 1,2,3 or 4. */
                        pDataParam->sTransfer.bWordCount,          /**< [In] Number of bytes to read. */
                        &pDataParam->sTransfer.pRxBuffer,          /**< [Out] Header and requested memory words. */
                        &pDataParam->sTransfer.wRxBitLength);      /**< [Out] Number of received bits. */

                if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
                    {
                    /* status is returned at the end of the function */
                    status = ERROR_READ;
                    }
                }
            else if ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
                {
                status = ERROR_ACCESS_PASSWOD;
                }
            else
                {
                status = ERROR_ACCESS_UNKNOWN;
                }
            }
        else
            {
            /* status is returned at the end of the function */
            status = ERROR_REQUEST_RN;
            }

        }
    else
        {
        /* status is returned at the end of the function */
        status = ERROR_CARD_ACTIVATE;
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION: Write_18000p3m3
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Write_18000p3m3(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_INTERNAL_ERROR;
    uint8_t       * pData;
    uint8_t       * pRxBuffer;
    uint32_t      dwCount;

    /* in case simple card detection, the mask length is set to 0x00 -> not used masked mode */
    if (!pDataParam->sAccess.bSimpleTagDetectionOnOff)
        {
        pDataParam->sDetectionParam.bMaskBitLength = ACTIVATE_CARD_WITHOUT_MASK;
        }

    /* Activate card - command covers Select, Begin_round Ack and Req_RN commands execution,
     * which are necessary for activation */

    /* Select one particular tag determined by UII 16 bytes long */
    status = phpalI18000p3m3_Select(
    						pDataParam->pPal,
							pDataParam->sDetectionParam.bTarget,
							0,
							PHPAL_I18000P3M3_MEMBANK_UII,
							pDataParam->sDetectionParam.pBitPointer,
							pDataParam->sDetectionParam.bBitPointerLength,
							pDataParam->sDetectionParam.UIIMask,
							pDataParam->sDetectionParam.bMaskBitLength,
							pDataParam->sDetectionParam.bTruncate);

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
    	{
	/* Begin round and perform just one round.
	 * Selected tag chooses slot num 0 since Q param is 0.
	 * Output from successful begin round is used for later Req_RN. */
    status =  phpalI18000p3m3_BeginRound(
							pDataParam->pPal,
							pDataParam->sDetectionParam.bDivideRatio,
							pDataParam->sDetectionParam.bModulation,
							pDataParam->sDetectionParam.bTRext,
							pDataParam->sDetectionParam.bSelection,
							pDataParam->sDetectionParam.bSession,
							0,//RFU
							0,//Q param
							pDataParam->pAl->abHandle);
    	}

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
	/* CRC is ensured by Begin Round */
    status = phpalI18000p3m3_Ack(
    						pDataParam->pPal,
							PHPAL_I18000P3M3_ACK_USE_CRC,
							pDataParam->pAl->abHandle,
							&pDataParam->sTransfer.pRxBuffer,
							&pDataParam->sTransfer.wRxBitLength);
        }

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
    	{
    	pDataParam->pAl->bHandleValid = PH_ON;

    	/* Perform Req_Rn. Despite USE_HANDLE macro is passed, in fact CRC is used. */
    	status = phalI18000p3m3_ReqRn(pDataParam->pAl,
            							  PHAL_I18000P3M3_REQRN_USE_HANDLE,
    									  &pRxBuffer);

    	memcpy(pDataParam->pAl->abHandle, pRxBuffer, 2);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
                {
                status = phalI18000p3m3_Access(
                        pDataParam->pAl,                          /**< [In] Pointer to this layer's parameter structure. */
                        pDataParam->sTransfer.bCoverCoding,       /**< [In] Option parameter. */
                        pDataParam->sAccess.pUserAccessPassword); /**< [In] Full access password; uint8_t[4] */
                }

            if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
                {
                /* set the pointer to the data transfer field */
                pData = pDataParam->sTransfer.pData;

                for (dwCount = 0; dwCount < pDataParam->sTransfer.bWordCount; dwCount++)
                    {
                    /* command WRITE could write only 2 bytes or 1 word at time, which correspond with one block size */
                    status = phalI18000p3m3_Write(
                            pDataParam->pAl,                         /**< [In] Pointer to this layer's parameter structure. */
                            pDataParam->sTransfer.bCoverCoding,      /**< [In] Option parameter. */
                            pDataParam->sTransfer.bBankMemory,       /**< [In] Memory bank where the write shall be performed. */
                            pDataParam->sTransfer.pWordPtr,          /**< [In] Starting write adress. */
                            pDataParam->sTransfer.bWordPtrLen,       /**< [In] Length of the pointer in bytes; 1,2,3 or 4. */
                            pData);            /**< [In] Word to write; uint8_t[2]. */

                    if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
                        {
                    	/* If the writing operation failed and non of the 18000p3m3 specified error codes was detected
                    	 * return general write error. */
                    	if((status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_OTHER &&
                    			(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_MEMORY_OVERRUN &&
								(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_MEMORY_LOCKED &&
								(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_INSUFFICIENT_POWER &&
								(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_NON_SPECIFIC)
                    		{
                    		status = ERROR_WRITE_UNKNOWN;
                    		}
                        break;
                        }
                    /* set the next position at the data buffer */
                    pData++;
                    pData++;
                    /* set the next block address */
                    pDataParam->sTransfer.pWordPtr[0]++;
                    }
                }
            else if ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
                {
                status = ERROR_ACCESS_PASSWOD;
                }
            else
                {
                status = ERROR_ACCESS_UNKNOWN;
                }

            }
        else
            {
            /* status is returned at the end of the function */
            status = ERROR_REQUEST_RN;
            }
        }
    else
        {
        /* status is returned at the end of the function */
        status = ERROR_CARD_ACTIVATE;
        }

    return status;
    }


/*==============================================================================================
 * FUNCTION: Write_Password_18000p3m3
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Write_Password_18000p3m3(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_INTERNAL_ERROR;
    uint8_t       * pData;
    uint8_t       * pRxBuffer;
    uint32_t      dwCount;

    /* in case simple card detection, the mask length is set to 0x00 -> not used masked mode */
    if (!pDataParam->sAccess.bSimpleTagDetectionOnOff)
        {
        pDataParam->sDetectionParam.bMaskBitLength = ACTIVATE_CARD_WITHOUT_MASK;
        }

    /* Activate card - command covers Select, Begin_round Ack and Req_RN commands execution,
     * which are necessary for activation */

    /* Select one particular tag determined by UII 16 bytes long */
    status = phpalI18000p3m3_Select(
    						pDataParam->pPal,
							pDataParam->sDetectionParam.bTarget,
							0,
							PHPAL_I18000P3M3_MEMBANK_UII,
							pDataParam->sDetectionParam.pBitPointer,
							pDataParam->sDetectionParam.bBitPointerLength,
							pDataParam->sDetectionParam.UIIMask,
							pDataParam->sDetectionParam.bMaskBitLength,
							pDataParam->sDetectionParam.bTruncate);

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
	/* Begin round and perform just one round.
	 * Selected tag chooses slot num 0 since Q param is 0.
	 * Output from successful begin round is used for later Req_RN. */
    status = phpalI18000p3m3_BeginRound(
    						pDataParam->pPal,
							pDataParam->sDetectionParam.bDivideRatio,
							pDataParam->sDetectionParam.bModulation,
							pDataParam->sDetectionParam.bTRext,
							pDataParam->sDetectionParam.bSelection,
							pDataParam->sDetectionParam.bSession,
							0,//RFU
							0,//Q param
							pDataParam->pAl->abHandle);
        }

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
	/* CRC is ensured by Begin Round */
    status = phpalI18000p3m3_Ack(
    						pDataParam->pPal,
							PHPAL_I18000P3M3_ACK_USE_CRC,
							pDataParam->pAl->abHandle,
							&pDataParam->sTransfer.pRxBuffer,
							&pDataParam->sTransfer.wRxBitLength);
        }

	if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
		pDataParam->pAl->bHandleValid = PH_ON;

		/* Perform Req_Rn. Despite USE_HANDLE macro is passed, in fact CRC is used. */
		status = phalI18000p3m3_ReqRn(pDataParam->pAl,
                							  PHAL_I18000P3M3_REQRN_USE_HANDLE,
        									  &pRxBuffer);

		memcpy(pDataParam->pAl->abHandle, pRxBuffer, 2);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            /* set the pointer to the data transfer field */
            pData = pDataParam->sAccess.pAccessPassword;

            for (dwCount=0; dwCount < pDataParam->sTransfer.bWordCount; dwCount++)
                {
                /* command WRITE could write only 2 bytes or 1 word at time, which correspond with one block size */
                status = phalI18000p3m3_Write(
                        pDataParam->pAl,                          /**< [In] Pointer to this layer's parameter structure. */
                        pDataParam->sTransfer.bCoverCoding,       /**< [In] Option parameter. */
                        pDataParam->sTransfer.bBankMemory,        /**< [In] Memory bank where the write shall be performed. */
                        pDataParam->sTransfer.pWordPtr,           /**< [In] Starting write adress. */
                        pDataParam->sTransfer.bWordPtrLen,        /**< [In] Length of the pointer in bytes; 1,2,3 or 4. */
                        pData);            /**< [In] Word to write; uint8_t[2]. */

                if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
                    {
                	/* If the writing operation failed and non of the 18000p3m3 specified error codes was detected
                	 * return general write error. */
                	if((status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_OTHER &&
                			(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_MEMORY_OVERRUN &&
							(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_MEMORY_LOCKED &&
							(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_INSUFFICIENT_POWER &&
							(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_NON_SPECIFIC)
                		{
                		status = ERROR_WRITE_PASSWORD_UNKNOWN;
                		}
                    break;
                    }
                /* set the next position at the data buffer */
                pData++;
                pData++;
                /* set the next block address */
                pDataParam->sTransfer.pWordPtr[0]++;
                }
            }
         else
            {
            /* status is returned at the end of the function */
            status = ERROR_REQUEST_RN;
            }
        }
    else
        {
        /* status is returned at the end of the function */
        status = ERROR_CARD_ACTIVATE;
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION: Lock_18000p3m3
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Lock_18000p3m3(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_INTERNAL_ERROR;
    uint8_t       * pRxBuffer;

    /* in case simple card detection, the mask length is set to 0x00 -> not used masked mode */
    if (!pDataParam->sAccess.bSimpleTagDetectionOnOff)
        {
        pDataParam->sDetectionParam.bMaskBitLength = ACTIVATE_CARD_WITHOUT_MASK;
        }

    /* Activate card - command covers Select, Begin_round Ack and Req_RN commands execution,
     * which are necessary for activation */

    /* Select one particular tag determined by UII 16 bytes long */
    status = phpalI18000p3m3_Select(
       						pDataParam->pPal,
   							pDataParam->sDetectionParam.bTarget,
   							0,
   							PHPAL_I18000P3M3_MEMBANK_UII,
   							pDataParam->sDetectionParam.pBitPointer,
   							pDataParam->sDetectionParam.bBitPointerLength,
   							pDataParam->sDetectionParam.UIIMask,
   							pDataParam->sDetectionParam.bMaskBitLength,
   							pDataParam->sDetectionParam.bTruncate);

	if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
   	/* Begin round and perform just one round.
   	 * Selected tag chooses slot num 0 since Q param is 0.
   	 * Output from successful begin round is used for later Req_RN. */
	status =  phpalI18000p3m3_BeginRound(
   							pDataParam->pPal,
   							pDataParam->sDetectionParam.bDivideRatio,
   							pDataParam->sDetectionParam.bModulation,
   							pDataParam->sDetectionParam.bTRext,
   							pDataParam->sDetectionParam.bSelection,
   							pDataParam->sDetectionParam.bSession,
   							0,//RFU
   							0,//Q param
   							pDataParam->pAl->abHandle);
		}

	if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
   	/* CRC is ensured by Begin Round */
	status = phpalI18000p3m3_Ack(
       						pDataParam->pPal,
   							PHPAL_I18000P3M3_ACK_USE_CRC,
   							pDataParam->pAl->abHandle,
   							&pDataParam->sTransfer.pRxBuffer,
   							&pDataParam->sTransfer.wRxBitLength);
		}

	if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
       	{
       	pDataParam->pAl->bHandleValid = PH_ON;

       	/* Perform Req_Rn. Despite USE_HANDLE macro is passed, in fact CRC is used. */
       	status = phalI18000p3m3_ReqRn(pDataParam->pAl,
               							  PHAL_I18000P3M3_REQRN_USE_HANDLE,
       									  &pRxBuffer);

       	memcpy(pDataParam->pAl->abHandle, pRxBuffer, 2);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
                {
                status = phalI18000p3m3_Access(
                        pDataParam->pAl,                          /**< [In] Pointer to this layer's parameter structure. */
                        pDataParam->sTransfer.bCoverCoding,       /**< [In] Option parameter. */
                        pDataParam->sAccess.pUserAccessPassword); /**< [In] Full access password; uint8_t[4] */
                }

            if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
                {
                status = phalI18000p3m3_Lock(
                        pDataParam->pAl,
                        pDataParam->sAccess.pMask,
                        pDataParam->sAccess.pAction);

                if ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
                    {
                    /* status is returned at the end of the function */
                    status = ERROR_LOCK_ON_NOT_ACCESSED;
                    }
                else if((status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_OTHER &&
            			(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_MEMORY_OVERRUN &&
						(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_MEMORY_LOCKED &&
						(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_INSUFFICIENT_POWER &&
						(status & PH_COMPID_MASK) != PHAL_I18000P3M3_ERR_NON_SPECIFIC)
                	{/*do nothing*/}
                else
                	status = ERROR_LOCK_UNKNOWN;
                }
            else if ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
                {
                status = ERROR_ACCESS_PASSWOD;
                }
            else
                {
                status = ERROR_ACCESS_UNKNOWN;
                }
            }
        else
            {
            /* status is returned at the end of the function */
            status = ERROR_REQUEST_RN;
            }
        }
    else
        {
        /* status is returned at the end of the function */
        status = ERROR_CARD_ACTIVATE;
        }

    return status;
    }

#endif
/* ---------------------------------------------------------------------------------------------
 *   End of File
 ---------------------------------------------------------------------------------------------*/
