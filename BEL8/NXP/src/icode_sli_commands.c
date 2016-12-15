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
#include <phpalSli15693.h>

/*AL Headers*/
#include <phalI15693.h>

#include <phalSli.h>

#include <icode_sli_ui.h>
#include <icode_sli_commands.h>

#ifdef NXPBUILD_SLI_TAG

/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local function prototypes
 ---------------------------------------------------------------------------------------------*/
static phStatus_t InventoryPopullation_15693_Int(parameters_sli_t *pDataParams, uint8_t *aMaskBuffer, uint8_t bMaskBitLength);
static phStatus_t FastInventoryPopullation_15693_Int(parameters_sli_t *pDataParams, uint8_t *aMaskBuffer, uint8_t bMaskBitLength);
static eSliType testSliType(uint8_t *bUid);
static void setTimeoutFlag(void* pContext);

/*==============================================================================================
 * FUNCTION: 	Inventory_Popullation_15693
 *
 * Description: This function performs Inventory command, to get list of all the 156593 tag
 *              in the field. It applies no mask to get all the tags, with any UID.
 *              The Inventory process is interrupted as soon ss number of detected tags reaches
 *              limit value MAX_NUM_DETECTED_SLI_TAGS.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t InventoryPopullation_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t	status;

    uint8_t aMaskBuffer[8];
    memset(aMaskBuffer, 0, sizeof(aMaskBuffer));
    memset(pDataParams->pIdentifier, 0, sizeof(pDataParams->pIdentifier));
    pDataParams->sDetectionParam.bTotalTagsFound = 0;
    /* clear the addressed mode to be able perform inventory with all tags in the field */
    pDataParams->pPal->bFlags &= (~PHPAL_SLI15693_FLAG_ADDRESSED);

    status = InventoryPopullation_15693_Int(pDataParams, aMaskBuffer, 0);

    return status;
    }

/*==============================================================================================
 * FUNCTION: 	Inventory_Popullation_Sli_Int
 *
 * Description: This function performs Inventory command to get as much tags matching
 *              with given Mask as possible.	It is executed in recursive way, with termination
 *              condition, when input parameter bMaskBitLength growths over 64.
 *              Length of SLI UID is 64 bits according specification.
 *              The Inventory process is interrupted as soon ss number of detected tags reaches
 *              limit value MAX_NUM_DETECTED_SLI_TAGS.
 *
 ---------------------------------------------------------------------------------------------*/
static phStatus_t InventoryPopullation_15693_Int(parameters_sli_t *pDataParams, uint8_t *aMaskBuffer, uint8_t bMaskBitLength)
    {
    phStatus_t	status;
            
    uint16_t    wCollisionLogReg = 0;
    uint8_t 	i;

    /* values in this variables are not utilised, we just need to pass input parameters to RdLib PAL functions */
    static uint8_t	bUidLengthDummy;
    static uint8_t	bDataDummy = 0;
    static uint16_t	wDataLengthDummy = 0;
    static uint8_t	bDsfid;

    if(bMaskBitLength > 64)
	return PH_ERR_INVALID_PARAMETER;

    status = phpalSli15693_Inventory(
            pDataParams->pPal,
            PHPAL_SLI15693_FLAG_DATA_RATE,
            0,
            aMaskBuffer,
            bMaskBitLength,
            &bDsfid,
            pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID);

    for(i = 0; i < 16; i++)
        {
        if(status == PH_ERR_SUCCESS)
            {
            pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].tagType =
                    testSliType(pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID);
            if(pDataParams->sDetectionParam.bTotalTagsFound < MAX_NUM_DETECTED_SLI_TAGS)
            	pDataParams->sDetectionParam.bTotalTagsFound++;
            else
            	return ERROR_SLI_OVERFLOW_NUMBER_OF_DETECTED_TAGS;
            }
        else if(((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR ||
                (status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR))
            {
            wCollisionLogReg |= 1 << i;
            }
        else
            {
            /* Do nothing. PH_ERR_IO_TIMEOT means no tag has answered thus the reader can step to next slot */
            }

        /* Next slot */
        status = phpalSli15693_SendEof(
        	pDataParams->pPal,
        	PHPAL_SLI15693_EOF_NEXT_SLOT,
        	&bDsfid,
        	pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID,
        	&bUidLengthDummy,
        	&bDataDummy,
        	&wDataLengthDummy);
        }

    if((status & PH_COMPID_MASK) == PH_ERR_IO_TIMEOUT)
    	status = PH_ERR_SUCCESS;

    if (wCollisionLogReg)
        {
        for (i = 0; i < 16; i++)
            {
            if (wCollisionLogReg & (1 << i))
                {
                if (bMaskBitLength % 8 < 4)
                    {
                    aMaskBuffer[bMaskBitLength / 8] &= 0xF0;
                    aMaskBuffer[bMaskBitLength / 8] |= i;
                    }
                else
                    {
                    aMaskBuffer[bMaskBitLength / 8] &= 0x0F;
                    aMaskBuffer[bMaskBitLength / 8] |= i << 4;
                    }

                //TODO ? REDO NON RECURSIVE
                status = InventoryPopullation_15693_Int(pDataParams, aMaskBuffer, bMaskBitLength + 4);

                if(status == PH_ERR_INVALID_PARAMETER)
                    break;
                }
            }
        }

    return status;

    }

/*==============================================================================================
 * FUNCTION: 	FastInventory_Popullation_15693
 *
 * Description: This function performs FastInventoryRead command, to get list of all the 156593 tag
 *              in the field. It applies no mask to get all the tags, with any UID.
 *              The Inventory process is interrupted as soon as number of detected tags reaches
 *              limit value MAX_NUM_DETECTED_SLI_TAGS.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t FastInventoryPopullation_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t	status;

    uint8_t aMaskBuffer[8];
    memset(aMaskBuffer, 0, sizeof(aMaskBuffer));
    memset(pDataParams->pIdentifier, 0, sizeof(pDataParams->pIdentifier));
    pDataParams->sDetectionParam.bTotalTagsFound = 0;
    /* clear the addressed mode to be able perform inventory with all tags in the field */
    pDataParams->pPal->bFlags &= (~PHPAL_SLI15693_FLAG_ADDRESSED);

    //TODO - NON RECURSIVE
    status = FastInventoryPopullation_15693_Int(pDataParams, aMaskBuffer, 0);

    return status;
    }

/*==============================================================================================
 * FUNCTION: 	FastInventory_Popullation_Sli_Int
 *
 * Description: This function performs Inventory command to get as much tags matching
 *              with given Mask as possible. It is executed in recursive way, with termination
 *              condition, when input parameter bMaskBitLength growths over 64.
 *              Length of SLI UID is 64 bits according specification.
 *              The Inventory process is interrupted as soon as number of detected tags reaches
 *              limit value MAX_NUM_DETECTED_SLI_TAGS.
 *
 ---------------------------------------------------------------------------------------------*/

static phStatus_t FastInventoryPopullation_15693_Int(parameters_sli_t *pDataParams, uint8_t *aMaskBuffer, uint8_t bMaskBitLength)
    {
    phStatus_t	status;
    uint16_t    wCollisionLogReg = 0;
    uint8_t 	i;
    int8_t		j;

    /* values in this variables are not utilized, we just need to pass input parameters to RdLib PAL functions */
    static uint8_t	bUidLengthDummy;
    static uint8_t	aDataDummy[4];
    static uint16_t	wDataLengthDummy = 0;
    static uint8_t	bDsfid;

    status = phpalSli15693_FastInventoryRead(pDataParams->pPal,
    											PHPAL_SLI15693_FLAG_DATA_RATE | PHPAL_SLI15693_FLAG_OPTION,
    											0x00,
    											aMaskBuffer,
    											bMaskBitLength,
    											0x00,//BlockNo
    											0x01,//NoOfBlocks
    											&pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID[0],
    											&bUidLengthDummy,
    											aDataDummy,
    											&wDataLengthDummy);

    for(i = 0; i < 16; i++)
        {
        if(status == PH_ERR_SUCCESS)
            {
    		if(bMaskBitLength >= 4)
    		{
    			for(j = 0; j < 7; j++)
    				pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID[7 - j] = pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID[7 - j - (bMaskBitLength + 4)/8];

    			/* 16 slot counter operates with upper nibble, final byte of UID must be merged  */
    			if(bMaskBitLength % 8 == 4)
    				pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID[bMaskBitLength / 8] = (aMaskBuffer[bMaskBitLength / 8] & 0x0F)| i << 4;
    			/* 16 slot counter operates with lower nibble */
    			else
    			{
    				memcpy(&pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID[0], aMaskBuffer, bMaskBitLength / 8);
    			}
    		}

            pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].tagType =
                    testSliType(pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID);

            if(pDataParams->sDetectionParam.bTotalTagsFound < MAX_NUM_DETECTED_SLI_TAGS)
            	pDataParams->sDetectionParam.bTotalTagsFound++;
            else
            	return ERROR_SLI_OVERFLOW_NUMBER_OF_DETECTED_TAGS;
            }
        else if(((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR ||
                (status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR))
            {
            wCollisionLogReg |= 1 << i;
            }
        else
            {
            /* Do nothing. PH_ERR_IO_TIMEOT means no tag has answered thus the reader can step to next slot */
            }

    		pDataParams->pPal->bFlags |= 0x40;
    		pDataParams->pPal->bUidBitLength = 0 + bMaskBitLength;

    		/* Next slot */
    		status = phpalSli15693_SendEof(
    					pDataParams->pPal,
    					PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ,
    					&bDsfid,
    					pDataParams->pIdentifier[pDataParams->sDetectionParam.bTotalTagsFound].UID,
    					&bUidLengthDummy,
    					aDataDummy,
    					&wDataLengthDummy);
        }

    if((status & PH_COMPID_MASK) == PH_ERR_IO_TIMEOUT)
    	status = PH_ERR_SUCCESS;

    if (wCollisionLogReg)
        {
        for (i = 0; i < 16; i++)
            {
            if (wCollisionLogReg & (1 << i))
                {
                if (bMaskBitLength % 8 < 4)
                    {
                    aMaskBuffer[bMaskBitLength / 8] &= 0xF0;
                    aMaskBuffer[bMaskBitLength / 8] |= i;
                    }
                else
                    {
                    aMaskBuffer[bMaskBitLength / 8] &= 0x0F;
                    aMaskBuffer[bMaskBitLength / 8] |= i << 4;
                    }

                //TODO - NON RECURSIVE
                status = FastInventoryPopullation_15693_Int(pDataParams, aMaskBuffer, bMaskBitLength + 4);

                if(status == PH_ERR_INVALID_PARAMETER)
                    break;
                }
            }
        }

    return status;

    }

/*==============================================================================================
 * FUNCTION:		ReadSingleBlock_15693
 *
 * Description:		This function performs Read Single Block command in addressed mode.
 *                  It reads a block from tag specified by a UIDMask.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ReadSingleBlock_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t	status;

    uint8_t	*pRxBuff;

    /* copy the UII to the MASK field */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
    /* set the adressed mode to be able work only with the chosen tag */
    pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;  /**< UID field is included in command frame. */

    status =  phalI15693_ReadSingleBlock(
            pDataParams->pAl,
            PHAL_I15693_OPTION_OFF,
            pDataParams->sReadSingleBlock.bBlockNum,
            &pRxBuff,
            &pDataParams->sReadSingleBlock.wRxLength);

    /* Clear addressed flag of the NFC Reader Library component */
    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    memcpy(pDataParams->sReadSingleBlock.aReadBlockBuffer, pRxBuff, pDataParams->sReadSingleBlock.wRxLength);

    return status;
    }

/*==============================================================================================
 * FUNCTION:		WriteSingleBlock_15693
 *
 * Description:		This function performs Write Single Block either in addressed or
 *                   non addressed mode - depending on how requested form user interface.
 *                   In addressed mode it writes one block of tag specified by a UIDMask.
 * 			         In non addressed mode it writes one block of all tags present in the field.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t WriteSingleBlock_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t status;

    /* if addressed mode selected, set the addressed flag in the NFC Reader Library interface
     * and copy custom UID to the dedicated array in the Library */
    if(pDataParams->sAccessParam.bAddressModeOnOff == PH_ON)
	{
	memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
	pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
	/* set the addressed mode to be able work only with the chosen tag */
	pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;
	}
    else /* Non Addressed mode requested - to all tags shall be written */
        {
        pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;
        }

    status =  phalI15693_WriteSingleBlock(
            pDataParams->pAl,
            PHAL_I15693_OPTION_OFF,
            pDataParams->sWriteSingleBlock.bBlockNum,
            pDataParams->sWriteSingleBlock.aWriteBlockBuffer,
            SLI_BLOCK_SIZE);

    /* Clear the Reader Library addressed flag. Next custom command shall not need
     * to be requested in the addressed mode. */
    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    return status;
    }

/*==============================================================================================
 * FUNCTION:		ReadMultipleBlock_15693
 *
 * Description:		This function performs Read Multiple Blocks in addressed mode.
 *                  It reads blocks from tag specified by a UIDMask.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ReadMultipleBlocks_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t status;

    /* copy UID from applicaion structure to RdLib PAL structure.
     * This is necessary for addressed mode. */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
    /* set the addressed mode to be able work only with the chosen tag */
    pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;  /**< UID field is included in command frame. */

    status =  phalI15693_ReadMultipleBlocks(
                pDataParams->pAl,
                PHAL_I15693_OPTION_OFF,
                pDataParams->sReadMultipleBlocks.bFirstBlockNo,
                pDataParams->sReadMultipleBlocks.wNumOfBlocks,
                &pDataParams->sReadMultipleBlocks.pReadBuff,
                &pDataParams->sReadMultipleBlocks.wRxLength);

    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    return status;
    }

/*==============================================================================================
 * FUNCTION: 		ResetToReady_15693
 *
 * Description: This function performs Reset To Ready either in addressed or non addressed mode
 *              - depending on request from user interface.
 *
 * Preconditions:	aUIDMask must contain UID of tag, that is currently in the RF field.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ResetToReady_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t	status;

    /* if addressed mode selected, set the addressed flag in the NFC Reader Library interface
     *  and copy custom UID to the dedicated array in the Library */
    if (pDataParams->sAccessParam.bAddressModeOnOff == PH_ON)
        {
        /* copy UID from application structure to RdLib PAL structure. This is necessary for addressed mode. */
        memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
        pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
        /* set the addressed mode to be able work only with the chosen tag */
        pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;
        }
    else /* Non addressed mode selected - all tags shall be reset to ready */
        {
        pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;
        }

    status = phpalSli15693_ResetToReady(pDataParams->pPal);

    /* Clear addressed flag of the NFC Reader Library component */
    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    return status;
    }

/*==============================================================================================
 * FUNCTION:	setTimeoutFlag
 *
 * Description:	This is callback function used by ResetToReadyAllTagsLoop_15693().
 * 		It is called when timer finishes counting.
 * 		It sets local variable resetToReadyTimeoutFlag of the ResetToReadyAllTagsLoop_15693()
 * 		to allow the software leave the infinite reset to ready loop.
 *
 ---------------------------------------------------------------------------------------------*/
static void setTimeoutFlag(void* pContext)
    {
    *((uint8_t *) pContext) = PH_ON;
    }

/*==============================================================================================
 * FUNCTION:	ResetToReadyAllTagsLoop_15693
 *
 * Description: This function performs Reset To Ready command repeatedly for given amount of time.
 * 		       It is alternative to "oneshot" ResetToReady_15693() function.
 * 		       This function does not provide addressed mode, it transmits to all tag in RF field.
 * 		During execution of the function, one Platform timer is consumed.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ResetToReadyAllTagsLoop_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t	status;
    uint32_t	dwTimerId = PH_PLATFORM_INVALID_TIMER_ID;
    uint8_t	resetToReadyTimeoutFlag = PH_OFF;

    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    status = phPlatform_Timer_Create(pDataParams->pPlatform , &dwTimerId);

    if(status == PH_PLATFORM_ERR_NO_FREE_TIMER)
        {
        return status;
        }
    else
        {
        /* clear the reset timeout flag before starting timer */
        resetToReadyTimeoutFlag = PH_OFF;

        phPlatform_Timer_Reset(pDataParams->pPlatform, dwTimerId);

        phPlatform_Timer_Start(pDataParams->pPlatform,
                dwTimerId,
                (uint32_t)(1000*pDataParams->sResetToReadyLoop.bResetLoopDuration),
                PH_PLATFORM_TIMER_UNIT_MS,
                setTimeoutFlag,//pApplication_callback,
                &resetToReadyTimeoutFlag);

        pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

        while(resetToReadyTimeoutFlag != PH_ON)
            {
            status = phpalSli15693_ResetToReady(pDataParams->pPal);
            }
        /* prepare the flag for further possible reset to ready loop */
        resetToReadyTimeoutFlag = PH_OFF;
        /* Release timer, it is no more needed in this reset loop */
        phPlatform_Timer_Reset(pDataParams->pPlatform, dwTimerId);
        status = phPlatform_Timer_Delete(pDataParams->pPlatform, dwTimerId);

        }
    return status;
    }

/*==============================================================================================
 * FUNCTION:	StayQuiet_15693
 *
 * Description: This function performs Stay Quiet command. ADDRESSED mode is set by the
 *              NFC Reader Library to satisfy ISO15693 specification.
 * 		       It is not possible to recognize whether requested tag has been really put to
 * 		       Quiet state or the command has not been caught (tag out of range of RF field),
 * 		       because the tag gives no response in both the situations.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t StayQuiet_15693(parameters_sli_t *pDataParams)
    {
    phStatus_t status;

    /* ADDRESSED mode is mandatory to this command and ADDRESS flag in PAL structure is set by the Reader Library */
    /* copy UID from application structure to RdLib PAL structure. This is necessary for addressed mode. */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
    /* ADDRESS flag in PAL structure is set by the Reader Library */

    status = phpalSli15693_StayQuiet(pDataParams->pPal);

    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    return status;
    }

/*==============================================================================================
 * FUNCTION:	testSliType
 *
 * Description: This function identifies SLI tag with given UID whether it is SLI, SLIX, SLIX2
 *              or SLI_RFU.
 *              The identification is based on 36th and 37th bit of given 64 bit long UID.
 *
 ---------------------------------------------------------------------------------------------*/
static eSliType testSliType(uint8_t *bUid)
    {
    eSliType   tagType;

    switch((bUid[4] >> 3) & 0x03)
        {
        case 0:
            tagType = Sli;
            break;
        case 1:
            tagType = Slix2;
            break;
        case 2:
            tagType = Slix;
            break;
        case 3:
            tagType = Sli_RFU;
            break;
        }

    return tagType;
    }

#ifdef NXPBUILD_SLIX_2_TAG
/*==============================================================================================
 * FUNCTION:	GetNXPSystemInformation_Slix2
 *
 * Description:	This function performs Get NXP System Information command.
 *
 * return values:
 * 		ERROR_SLI_UNSUPPORTED_COMMAND: command not supported by requested tag.
 ---------------------------------------------------------------------------------------------*/
phStatus_t GetNXPSystemInformation_Slix2(parameters_sli_t *pDataParams)
    {
    phStatus_t	   status;

    pDataParams->pPal->wAdditionalInfo = 0;

    status = phalSli_GetNxpSystemInfo(
            pDataParams->pAlSli,
            &pDataParams->sGetNxpSystemInfo.bProtectionPointer,
            &pDataParams->sGetNxpSystemInfo.bProtectionCondition,
            &pDataParams->sGetNxpSystemInfo.bLockBits,
            pDataParams->sGetNxpSystemInfo.aFeatureFlags);

    /* Test the Library output for unsupported command by tag.
     * This means that specific error code has been received from tag.
     * During testing when a tag did not support this command only 0x0F error code (unknown error) has been observed. */
    if((status == (PH_COMP_PAL_SLI15693 | PH_ERR_CUSTOM_BEGIN)) &&
	    (pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNSUPPORTED_COMMAND ||
    	     pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNKNOWN_ERROR)
      )
    	status = ERROR_SLI_UNSUPPORTED_COMMAND;

    return status;
    }

/*==============================================================================================
 * FUNCTION:	GetRandomNumberSetPWD_Slix2
 *
 * Description: This function performs Get Random Number command with
 * 				immediate subsequent Set Password (both) in addressed mode
 *              over tag specified by aUIDMask.
 *
 * return values:
 * 		ERROR_SLI_UNSUPPORTED_COMMAND: command not supported by requested tag.
 ---------------------------------------------------------------------------------------------*/
phStatus_t GetRandomNumberSetPWD_Slix2(parameters_sli_t *pDataParams)
    {
    phStatus_t    status;
    uint8_t       aTempPassword[4];

    /* copy the UII to the MASK field */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    /* set the adressed mode to be able work only with the chosen tag */
    pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;  /**< UID field is included in command frame. */

    pDataParams->pPal->wAdditionalInfo = 0;

    /* copy the general entered password only for Set Password command execution, because
     * called function: phalSli_GetRandomNumberSetPWD returns password XOR-ed
     * with random number */
    memcpy(aTempPassword, pDataParams->sAccessParam.aPassword, ACCESS_PASWORD_LENGTH);

    status = phalSli_GetRandomNumberSetPWD(
            pDataParams->pAlSli,
            pDataParams->sAccessParam.bPwdIdentifier,
            aTempPassword);

    /* Test the Library output for unsupported command by tag.
     * This means that specific error code has been received from tag.
     * During testing when a tag did not support this command only 0x0F error code (unknown error) has been observed. */
    if((status == (PH_COMP_PAL_SLI15693 | PH_ERR_CUSTOM_BEGIN)) &&
	    (pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNSUPPORTED_COMMAND ||
	     pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNKNOWN_ERROR)
       )
	status = ERROR_SLI_UNSUPPORTED_COMMAND;

    return status;
    }

/*==============================================================================================
 * FUNCTION:	WritePassword_Slix2
 *
 * Description: This function performs Write Password command in addressed mode
 *              over tag specified by aUIDMask.
 *
 * return values:
 * 		ERROR_SLI_UNSUPPORTED_COMMAND: command not supported by requested tag.
 ---------------------------------------------------------------------------------------------*/
phStatus_t WritePassword_Slix2(parameters_sli_t *pDataParams)
    {
    phStatus_t    status;

    /* copy the UII to the MASK field */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    /* set the addressed mode to be able work only with the chosen tag */
    pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;  /**< UID field is included in command frame. */

    pDataParams->pPal->wAdditionalInfo = 0;

    status = phalSli_WritePWD(
            pDataParams->pAlSli,
            pDataParams->sAccessParam.bPwdIdentifier,
            pDataParams->sAccessParam.aPassword);

    /* Test the Library output for unsupported command by tag.
     * This means that specific error code has been received from tag.
     * During testing when a tag did not support this command only 0x0F error code (unknown error) has been observed. */
    if((status == (PH_COMP_PAL_SLI15693 | PH_ERR_CUSTOM_BEGIN)) &&
    	    (pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNSUPPORTED_COMMAND ||
    	     pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNKNOWN_ERROR)
       )
	status = ERROR_SLI_UNSUPPORTED_COMMAND;

    return status;
    }

/*==============================================================================================
 * FUNCTION: LockPassword_Slix2
 *
 * Description: This function performs Lock Password command.
 *
 * return values:
 * 		ERROR_SLI_UNSUPPORTED_COMMAND: command not supported by requested tag.
 ---------------------------------------------------------------------------------------------*/
phStatus_t LockPassword_Slix2(parameters_sli_t *pDataParams)
    {
    phStatus_t    status;

    pDataParams->pPal->wAdditionalInfo = 0;

    status = phalSli_LockPWD(
            pDataParams->pAlSli,
            pDataParams->sAccessParam.bPwdIdentifier);

    /* Test the Library output for unsupported command by tag.
     * This means that specific error code has been received from tag.
     * During testing when a tag did not support this command only 0x0F error code (unknown error) has been observed. */
    if((status == (PH_COMP_PAL_SLI15693 | PH_ERR_CUSTOM_BEGIN)) &&
    	    (pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNSUPPORTED_COMMAND ||
    	     pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNKNOWN_ERROR)
      )
	status = ERROR_SLI_UNSUPPORTED_COMMAND;

    return status;
    }

/*==============================================================================================
 * FUNCTION:	ProtectPage_Slix2
 *
 * Description:	This function performs Protect Page command in addressed mode
 *              over tag specified by aUIDMask.
 *
 * return values:
 * 		ERROR_SLI_UNSUPPORTED_COMMAND: command not supported by requested tag.
 ---------------------------------------------------------------------------------------------*/
phStatus_t ProtectPage_Slix2(parameters_sli_t *pDataParams)
    {
    phStatus_t    status;

    /* copy the UII to the MASK field */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
    /* set the adressed mode to be able work only with the chosen tag */
    pDataParams->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;  /**< UID field is included in command frame. */

    pDataParams->pPal->wAdditionalInfo = 0;

    status = phalSli_ProtectPage(
            pDataParams->pAlSli,
            pDataParams->sProtection.bProtectionPointer,
            pDataParams->sProtection.bProtectionStatus);

    /* Test the Library output for unsupported command by tag.
     * This means that specific error code has been received from tag.
     * During testing when a tag did not support this command only 0x0F error code (unknown error) has been observed. */
    if((status == (PH_COMP_PAL_SLI15693 | PH_ERR_CUSTOM_BEGIN)) &&
	    (pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNSUPPORTED_COMMAND ||
    	     pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNKNOWN_ERROR)
      )
	status = ERROR_SLI_UNSUPPORTED_COMMAND;

    return status;
    }

/*==============================================================================================
 * FUNCTION: StayQuietPersistent_Slix2
 *
 * Description: This function performs Stay Quiet Persistent command. ADDRESSED mode is set by
 *              the NFC Reader Library to satisfy ISO15693 specification. It is not possible
 *              to recognize whether requested tag has been really put to Quiet Persistent state
 *              or the command has not been caught (tag out of range of RF field),
 *              because the tag gives no response in both the situations.
 *
 * return values:
 * 		ERROR_SLI_UNSUPPORTED_COMMAND: command not supported by requested tag.
 ---------------------------------------------------------------------------------------------*/
phStatus_t StayQuietPersistent_Slix2(parameters_sli_t *pDataParams)
    {
    phStatus_t	status;

    /* ADDRESSED mode is mandatory to this command and ADDRESS flag in PAL structure is set by the Reader Library */
    /* copy UID from application structure to RdLib PAL structure. This is necessary for addressed mode. */
    memcpy(pDataParams->pPal->pUid, pDataParams->sDetectionParam.aUIDMask, UID_15693_BYTE_LENGTH);
    pDataParams->pPal->bUidBitLength = PHPAL_SLI15693_UID_LENGTH * 8;
    /* ADDRESS flag in PAL structure is set by the Reader Library */

    pDataParams->pPal->wAdditionalInfo = 0;

    status = phpalSli15693_StayQuietPersistent(pDataParams->pPal);

    /* clear the addressed flag in Library component */
    pDataParams->pPal->bFlags &= ~PHPAL_SLI15693_FLAG_ADDRESSED;

    /* Test the Library output for unsupported command by tag.
     * This means that specific error code has been received from tag.
     * During testing when a tag did not support this command only 0x0F error code (unknown error) has been observed. */
    if((status == (PH_COMP_PAL_SLI15693 | PH_ERR_CUSTOM_BEGIN)) &&
	    (pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNSUPPORTED_COMMAND ||
    	     pDataParams->pPal->wAdditionalInfo == ERROR_CODE_15693_UNKNOWN_ERROR)
      )
	status = ERROR_SLI_UNSUPPORTED_COMMAND;

    return status;
    }

#endif // NXPBUILD_SLIX_2_TAG



#endif // NXPBUILD_SLI_TAG
/* ---------------------------------------------------------------------------------------------
 *   End of File
 ---------------------------------------------------------------------------------------------*/
