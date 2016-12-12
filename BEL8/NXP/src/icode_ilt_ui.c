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

/* user Headers */
#include <icode_ilt_ui.h>
#include <icode_ilt_commands.h>
#include <icode_common.h>

#ifdef NXPBUILD_ILT_TAG

/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/
#define DEFAULT_INITIAL_VALUE_OF_Q_INVENTORY_PARAMETER			6
/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local function prototypes
 ---------------------------------------------------------------------------------------------*/
phStatus_t ISO18000p3m3_Init(parameters_itl_t                  *pDataParamILT,
                             phpalI18000p3m3_Sw_DataParams_t   *pPalDataParam,
                             phalI18000p3m3_Sw_DataParams_t    *pAlDataParam,
                             phhalHw_Rc663_DataParams_t        *pHalDataParam);
phStatus_t SimpleInventory_ILT(parameters_itl_t *pDataParam);
phStatus_t InventoryPopulation_ILT(parameters_itl_t *pDataParam);
phStatus_t NumberInventoriedTags_ILT(parameters_itl_t *pDataParam);
phStatus_t ChooseTag(parameters_itl_t *pDataParam);
phStatus_t CommandsMenu_ILT(parameters_itl_t *pDataParam);
phStatus_t Commands_Menu_Simple_Inventory(parameters_itl_t *pDataParam);
phStatus_t ListTags_ILT(parameters_itl_t *pDataParam);
phStatus_t Read_ILT(parameters_itl_t *pDataParam);
phStatus_t Write_ILT(parameters_itl_t *pDataParam);
phStatus_t Access_ILT(parameters_itl_t *pDataParam);
phStatus_t SetAccess_ILT(parameters_itl_t *pDataParam);
phStatus_t Lock_ILT(parameters_itl_t *pDataParam);
phStatus_t List_Detection_18000p3m3(parameters_itl_t *pDataParam);
phStatus_t Set_Mask_18000p3m3( uint8_t * pMask, uint8_t bNumber);
phStatus_t SetConfig_18000p3m3(parameters_itl_t *pDataParam);
phStatus_t Default_SetConfig_18000p3m3(parameters_itl_t *pDataParam);
static void ErrorStatusHandler(phStatus_t status);


/*==============================================================================================
 * FUNCTION: ISO18000p3m3_Init
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ISO18000p3m3_Init(
                       parameters_itl_t                  *pDataParamILT,
                       phpalI18000p3m3_Sw_DataParams_t   *pPalDataParam,
                       phalI18000p3m3_Sw_DataParams_t    *pAlDataParam,
                       phhalHw_Rc663_DataParams_t        *pHalDataParam
                       )
   {
   phStatus_t    status;

   pDataParamILT->pHal = pHalDataParam;
   pDataParamILT->pPal = pPalDataParam;
   pDataParamILT->pAl  = pAlDataParam;

   /* Initialize the 1800p3m3 PAL component */
   PH_CHECK_SUCCESS_FCT(status, phpalI18000p3m3_Sw_Init(pPalDataParam, sizeof(phpalI18000p3m3_Sw_DataParams_t), pHalDataParam));

   /* Initialize the 18000p3m3 AL component */
   PH_CHECK_SUCCESS_FCT(status, phalI18000p3m3_Sw_Init(pAlDataParam, sizeof(phalI18000p3m3_Sw_DataParams_t), pPalDataParam));

   return status;
   }


/*==============================================================================================
 * FUNCTION: MainMenu_ILT
 *
 * Description: Function declares and sets pointers to HAL, PAL and AL to initialize ISO18000
 *              parameters structure.
 *              ILT commands user menu is starting.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t MainMenu_ILT(void *pHal)
    {
    phStatus_t    status = PH_ERR_SUCCESS;

    /* PAL variables*/
    phpalI18000p3m3_Sw_DataParams_t       spalI18000p3m3;            /* PAL 18000p3m3 component */
    /* AL variables*/
    phalI18000p3m3_Sw_DataParams_t        salI18000p3m3;             /* AL 18000p3m3 component */
    
    /* demo application variables */
    parameters_itl_t                      sDataParamILT;

    /* Initialize the 1800p3m3 components */
    status = ISO18000p3m3_Init(&sDataParamILT, &spalI18000p3m3, &salI18000p3m3, pHal);
    CHECK_STATUS(status);

    status = Default_SetConfig_18000p3m3(&sDataParamILT);
    CHECK_STATUS(status);

    status = CommandsMenu_ILT(&sDataParamILT);
    CHECK_STATUS(status);


    return PH_ERR_SUCCESS;
    }


/*==============================================================================================
 * FUNCTION: CommandsMenu_ILT
 *
 * Description:
 *                Functions performs the ILT user interface.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t CommandsMenu_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[3];
    uint8_t       bStayInMenu = 1;

    while ((status == PH_ERR_SUCCESS) && (bStayInMenu))
        {
        /* display the menu in the console */
         printf("\n"
        		"ILT - COMMANDS -\n"
        		"%s\n"
        		"1 - Read                    (read 12 Bytes of user memory at address: 0x00)\n"
        		"2 - Write                   (write 12 bytes to user memory at address: 0x00)\n"
        		"3 - Access Password         (set/read access password to the tag)\n"
        		"4 - set Access Password     (set user password to software memory for accessing password protected tag)\n"
        		"5 - Lock                    (lock the user memory on tag for write)\n"
        		"%s\n"
        		"i - Inventory               (detection of all tags in the RF field)\n"
        		"n - Number of Tags          (endless loop inventory - for exit please press the LPCXpresso Restart button)\n"
        		"s - Single Tag Detection    (single tag operations)\n"
         	 	"c - Configuration Setting   (detection parameters settings)\n"
         	 	"%s\n\n",cTableLine, cTableLine2, cTableReturn);

         /* read the choise */
         Read_String (bString,1);

         switch(bString[0])
            {
            case '1':
                printf("ILT - READ -\n");
                printf("%s\n",cTableLine);
                status = Read_ILT(pDataParam);
                break;

            case '2':
                printf("ILT - WRITE -\n");
                printf("%s\n",cTableLine);
                status = Write_ILT(pDataParam);
                break;

            case '3':
                printf("ILT - ACCESS -\n");
                printf("%s\n",cTableLine);
                status = Access_ILT(pDataParam);
                break;

            case '4':
                printf("ILT - set Access Password -\n");
                printf("%s\n",cTableLine);
                status = SetAccess_ILT(pDataParam);
                break;

            case '5':
                printf("ILT - set LOCK -\n");
                printf("%s\n",cTableLine);
                status = Lock_ILT(pDataParam);
                break;

            case 'i':
                printf("ILT - Inventory\n");
                status = InventoryPopulation_ILT(pDataParam);
                CHECK_STATUS(status);
                status = ListTags_ILT(pDataParam);
                CHECK_STATUS(status);
                status = ChooseTag(pDataParam);
                CHECK_STATUS(status);
                break;

            case 'n':
                printf("ILT - Number of Inventoried Tags\n");
                status = NumberInventoriedTags_ILT(pDataParam);
                CHECK_STATUS(status);
                break;

            case 's':
                printf("ILT - Single Tag Detection\n");
                status = SimpleInventory_ILT(pDataParam);
                CHECK_STATUS(status);
                status = List_Detection_18000p3m3(pDataParam);
                CHECK_STATUS(status);
                break;

            case 'c':
                printf("ILT - Configuration Setting\n");
                status = SetConfig_18000p3m3(pDataParam);
                break;

            case 'r':
                bStayInMenu = 0;
                break;

            default:
                printf("%s\n",cTryAgain);
                break;
            }
        }
    return PH_ERR_SUCCESS;
    }


/*==============================================================================================
 * FUNCTION: InventoryPopulation_ILT
 *
 * Description: Function performs the inventory of tags which are place to the RF field
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t InventoryPopulation_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t     status;

    status = phhalHw_FieldReset(pDataParam->pHal);
    CHECK_STATUS(status);

    status = phhalHw_ApplyProtocolSettings( pDataParam->pHal, (uint8_t)(PHHAL_HW_CARDTYPE_I18000P3M3 & 0xFF));
    CHECK_STATUS(status);

    status = Inventory_18000p3m3(pDataParam);
    if((status & PH_COMPID_MASK) == ERROR_ILT_OVERFLOW_NUMBER_OF_DETECTED_TAGS)
		{
    	printf("More tags detected than maximum software limit.\n");
    	status = PH_ERR_SUCCESS;
		}

    return status;
    }

/*==============================================================================================
 * FUNCTION: NumberInventoriedTags_ILT
 *
 * Description: Function performs endless loop of inventory of all tags in the field.
 *              Current number of present tags is printed on the console.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t NumberInventoriedTags_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t     status;
    uint32_t      dwCounter = 0;

    while (1)
        {
        dwCounter++;

        status = phhalHw_FieldReset(pDataParam->pHal);
        CHECK_STATUS(status);

        status = phhalHw_ApplyProtocolSettings( pDataParam->pHal, (uint8_t)(PHHAL_HW_CARDTYPE_I18000P3M3 & 0xFF));
        CHECK_STATUS(status);

        status = Inventory_18000p3m3(pDataParam);
        CHECK_STATUS(status);

        if (!(dwCounter%10))
            {
            printf("number of detected tags:\n");
            }
        printf("%d\n", pDataParam->sDetectionParam.bTotalTagsFound);
        }

    return PH_ERR_SUCCESS;
    }

/*==============================================================================================
 * FUNCTION: ChooseTag
 *
 * Description: Function performs Tag selection on the basis of user choose,
 *              UII of the tag is stored and will be used as mask for commands execution
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ChooseTag(parameters_itl_t *pDataParam)
    {
    phStatus_t    status;
    uint8_t       bString[3];
    uint8_t       bTempLength;
    uint32_t      dwTagNumber;
    uint32_t      i;
    int printBuffIndex = 1;
    char printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    if ((pDataParam->sDetectionParam.bTotalTagsFound != 0) && (pDataParam->sDetectionParam.bTotalTagsFound <= MAX_NUM_DETECTED_ITL_TAGS))
        {
        do
            {
            /* if there is only one tag inventoried, this one is automatically set as choosen */
            if (pDataParam->sDetectionParam.bTotalTagsFound == 1)
                {
                bString[0] = '1';
                bString[1] = 0;
                }
            else
                {
                /* there is detected relevant number of tag from range (1 - max) */
                printf("\nchoose a Tag from range (1 - %d) decimal \n", pDataParam->sDetectionParam.bTotalTagsFound);
                printf("0 - return\n");

                /* read the string from "console" */
                Read_String (bString,3);
                }
            /* convert string to integer (32bit) */
            dwTagNumber = (uint32_t)atoi((char *)bString);

            /* the choosen value has to be from relevant range (1 - max) */
            if ((dwTagNumber != 0) && (dwTagNumber <= MAX_NUM_DETECTED_ITL_TAGS))
                {
                printf("choice > %d\n\n", dwTagNumber);
                dwTagNumber--; // correct the selected number

                /* check the scale, if enter number is not out of range */
                if (dwTagNumber < pDataParam->sDetectionParam.bTotalTagsFound)
                    {
                    /* set the bit address where the mask is applied */
                    pDataParam->sDetectionParam.pBitPointer[0] = 0x20;
                    /* format of the bitPointer is byte */
                    pDataParam->sDetectionParam.bBitPointerLength  = WORD_POINTER_LENGTH_8_BIT;
                    /* store the length of UII words */
                    bTempLength = (pDataParam->pIdentifier[dwTagNumber].StoredUII[0] >> 3);
                    /* calculation number of bits of the UII */
                    pDataParam->sDetectionParam.bMaskBitLength = bTempLength * LENGTH_WORD;

                    /* set the address to beginning of the UII address,
                     * zero word is StoredPC
                     * first word is beginning of the UII */

                    /* copy the UII to the MASK field -> will be used during access commands execution */
                    memcpy(pDataParam->sDetectionParam.UIIMask, &pDataParam->pIdentifier[dwTagNumber].StoredUII[2], (bTempLength*2) );

                    /* printing the chosen UII */
                    for (i = 0; i < USER_ID_MASK_NUMBER_OF_BYTES; i++)
                        {
                    	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%2.2X ", pDataParam->sDetectionParam.UIIMask[i]);
                        }
                    printf("UII: %s\n", printBuff);
                    status = PH_ERR_SUCCESS;
                    }
                else
                    {
                    /* user chose the number out of range */
                    status = PH_ERR_INVALID_PARAMETER;
                    }
                }
            else
                {
        	if (dwTagNumber == 0)
        	    {
        	    status = PH_ERR_ABORTED;
        	    printf("no tag chosen\n");
        	    }
        	else
        	    {
        	    /* user chose the number out of range */
        	    status = PH_ERR_INVALID_PARAMETER;
        	    }
                }

            if (status == PH_ERR_INVALID_PARAMETER)
                {
                printf("entered number is out of range\nPlease, type another number\n");
                }

            } while(status == PH_ERR_INVALID_PARAMETER);
        }
    else
        {
        /* there is not detected any tag or the number of tags is out of range */
        printf("No Tag detected. \n Please, repeat the INVENTORY (press 'i')\n");
        status = PH_ERR_LENGTH_ERROR;
        }

    if (status != PH_ERR_SUCCESS)
        {
        /* set the default error value to the CRC and UII buffer */
        memset( pDataParam->sDetectionParam.StoredCRC, 0xFF,2);
        status = PH_ERR_SUCCESS;
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION:   ListTags_ILT
 *
 * Description: Function prints out the table of ILT tags data.
 *              Data consists of number of detected tags, CRC, whole PC/XC packet (which
 *              consists of the UII) and UII length
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ListTags_ILT(parameters_itl_t *pDataParam)
    {
    uint32_t   i,j;
    int printBuffIndex;
    char printBuff[SPRINTF_LONG_BUFFER_SIZE];
    uint16_t listLineCounter = 0;

    if(pDataParam->sDetectionParam.bTotalTagsFound > 0)
        {
        printf("\n%s\n"
        	   "number of detected tags: %d\n", cTableLine, pDataParam->sDetectionParam.bTotalTagsFound);
        printf("%s\n"
        	   "|No.|  CRC  | PC/XC | UII length \n"
        	   "%s\n", cTableLine, cTableLine);

        printBuffIndex = 1;
        for (i=0;i<pDataParam->sDetectionParam.bTotalTagsFound;i++)
            {
            /* buffer CRC for printing */
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1],
                    "|%3d| %2.2X %2.2X | ",i+1,
                    pDataParam->pIdentifier[i].StoredCRC[0],
                    pDataParam->pIdentifier[i].StoredCRC[1]);
            /* buffer PC/XPC for printing */
            for (j=0;j<pDataParam->pIdentifier[i].bNumOfBytesXPC;j++)
                {
                printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%2.2X ", pDataParam->pIdentifier[i].StoredUII[j]);
                }
            /* buffer UII length for printing */
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "| %2d |\n", (pDataParam->pIdentifier[i].StoredUII[0] >> 3));

            /* do printouts only when 25 lines buffered, or entire list is buffered */
            if(++listLineCounter == MAX_NUMBER_OF_LINES_OF_LIST_PER_PRINTOUT || i >= pDataParam->sDetectionParam.bTotalTagsFound - 1)
                {
                printf("%s", printBuff);
                listLineCounter = 0;
                printBuffIndex = 1;
                }
            else
                {
                continue;
                }
            }

        printf("%s\n",cTableLine);
        }
    return PH_ERR_SUCCESS;
    }


/*==============================================================================================
 * FUNCTION:   Read_ILT
 *
 * Description: Function by default reads 6 words (12 bytes) from the address 0 from user memory
 *              bank.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Read_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint32_t      dwLoop;
    int printBuffIndex = 1;
    char printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    pDataParam->sTransfer.bBankMemory = PHPAL_I18000P3M3_MEMBANK_USER;
    memset(pDataParam->sTransfer.pWordPtr, 0, WORD_PTR_LEN);
    pDataParam->sTransfer.pWordPtr[0] = I18000P3M3_MEM_STARTING_ADDRESS;
    pDataParam->sTransfer.bWordCount = cHelloWord_Size/2;

    status = Read_18000p3m3(pDataParam);

    pDataParam->sTransfer.bNumOfBytes = pDataParam->sTransfer.wRxBitLength/8;

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
        printf("Memory Bank    = %X\n"
               "Memory Address = %X\n"
               "Data Length    = %d words\n",
               pDataParam->sTransfer.bBankMemory,
               pDataParam->sTransfer.pWordPtr[0],
               pDataParam->sTransfer.bNumOfBytes/2);

        for(dwLoop = 0; dwLoop < pDataParam->sTransfer.bNumOfBytes; dwLoop++)
            {
        	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%02X ", pDataParam->sTransfer.pRxBuffer[dwLoop]);
            }
        printf("memory content : 0x %s\n", printBuff);
        printf("Content =  %s\n",pDataParam->sTransfer.pRxBuffer);
        }
    else
        {
        ErrorStatusHandler(status);
        status = PH_ERR_SUCCESS;
        }
    return status;
    }


/*==============================================================================================
 * FUNCTION:   Write_ILT
 *
 * Description: Function by default writes 6 words (12 bytes) from the address 0 from user memory
 *              bank.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Write_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bBadChoise;

    printf("1 - write \"Hello word!\" to USER memory\n"
    	   "2 - clear USER memory\n"
    	   "%s\n",cTableLine2);

    bBadChoise = PH_OFF; // default bad choice is false
    Read_String (bString,1);

    switch(bString[0])
        {
        case '1':
            /* content of the string cHelloWord is copied to the data buffer */
            strncpy((char *)pDataParam->sTransfer.pData, (char *)cHelloWord, cHelloWord_Size);
            break;

        case '2':
            /* data buffer is cleaned by 0 "zero" content */
            memset(pDataParam->sTransfer.pData, 0x00, sizeof(pDataParam->sTransfer.pData));
            break;

        default:
            bBadChoise = PH_ON;
            printf("%s\n",cTryAgain);
            break;
        }

    if (!bBadChoise)
        {
        pDataParam->sTransfer.bBankMemory = PHPAL_I18000P3M3_MEMBANK_USER;
        pDataParam->sTransfer.pWordPtr[0] = I18000P3M3_MEM_STARTING_ADDRESS;
        pDataParam->sTransfer.bWordCount = cHelloWord_Size/2;
        /* data for writing are in the buffer pDataParam->sTransfer.pData */
        status = Write_18000p3m3(pDataParam);
        }

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
        printf("Data have been written.\n"
        	   "Memory Bank    = %X\n"
               "Memory Address = %X\n"
               "Data Length    = %d words\n",
               pDataParam->sTransfer.bBankMemory,
               I18000P3M3_MEM_STARTING_ADDRESS,
               pDataParam->sTransfer.bWordCount);
        }
    else
        {
        ErrorStatusHandler(status);
        status = PH_ERR_SUCCESS;
        }

    return status;
    }


/*==============================================================================================
 * FUNCTION:   Access_ITL
 *
 * Description: Function writes and reads access password to the tag at address 02h
 *              in the memory bank 00 - reserved memory
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Access_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bBadChoise;
    uint8_t       bNumber;
    uint32_t      dwTemp;
    uint32_t      dwLoop;
    int			  printBuffIndex = 1;
    char		  printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    printf("ACCESS on the Tag is (%1.1X): ", pDataParam->sAccess.dwAccessLockOnOff);
    if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
        {
        printf("ON\n");
        }
    else
        {
        printf("OFF\n");
        }

    printf("%s\n"
    	   "1 - write access password to the tag : 0x00000000\n"
    	   "2 - write access password to the tag : 0x11111111\n"
    	   "3 - write access password to the tag : 0x12345678\n"
    	   "4 - read  access password from the tag\n"
    	   "5 - use the ACCESS command on the tag\n"
    	   "%s\n",cTableLine2, cTableLine2);


    bBadChoise = PH_OFF; // default bad choice is false
    Read_String (bString,1);

    switch(bString[0])
        {
        case '1':
            /* data buffer is cleaned by 0 "zero" content */
            memset(pDataParam->sAccess.pAccessPassword, 0x00, sizeof(pDataParam->sAccess.pAccessPassword));
            break;

        case '2':
            /* default access password "0x 11 11 11 11" is written at the address 0x20 to 0x3F of RESERVED memory bank */
            memcpy(pDataParam->sAccess.pAccessPassword, &bAccessPassword1, sizeof(pDataParam->sAccess.pAccessPassword));
            break;

        case '3':
            /* default access password "0x 12 34 56 78" is written at the address 0x20 to 0x3F of RESERVED memory bank */
            memcpy(pDataParam->sAccess.pAccessPassword, &bAccessPassword2, sizeof(pDataParam->sAccess.pAccessPassword));
            break;

        case '4':
            /* data buffer is cleaned by 0 "zero" content */
            bBadChoise = PH_ON;
            pDataParam->sTransfer.bBankMemory = PHPAL_I18000P3M3_MEMBANK_RESERVED;
            pDataParam->sTransfer.pWordPtr[0] = I18000P3M3_MEM_ACCESS_PASSWORD_ADDRESS;
            pDataParam->sTransfer.bWordCount = ACCESS_PASSWORD_MEMORY_LENGTH;
            dwTemp = pDataParam->sAccess.dwAccessLockOnOff;
            pDataParam->sAccess.dwAccessLockOnOff = PH_OFF;
            status = Read_18000p3m3(pDataParam);
            pDataParam->sAccess.dwAccessLockOnOff = dwTemp;
            pDataParam->sTransfer.bNumOfBytes = pDataParam->sTransfer.wRxBitLength/8;

            if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
                {
                printf("Memory Bank    = %X\n"
                       "Memory Address = %X\n"
                       "Data Length    = %d words\n",
                       pDataParam->sTransfer.bBankMemory,
                       pDataParam->sTransfer.pWordPtr[0],
                       pDataParam->sTransfer.bNumOfBytes/2);

                for(dwLoop = pDataParam->sTransfer.bNumOfBytes; dwLoop > 0; dwLoop--)
                    {
                	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%02X ", pDataParam->sTransfer.pRxBuffer[dwLoop-1]);
                    }
                printf("memory content : 0x %s\n", printBuff);
                printf("text content   : %s\n",pDataParam->sTransfer.pRxBuffer);
                }
            else
                {
                ErrorStatusHandler(status);
                status = PH_ERR_SUCCESS;
                }
            break;

        case '5':
            printf("Would you like to use the ACCESS command on the Tag?\n"
            	   "0 - No\n"
                   "1 - Yes\n");
            Read_String (bString,1);
            bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)
            if ((!bNumber)||(bNumber == 1))
                {
                pDataParam->sAccess.dwAccessLockOnOff = bNumber;
                printf("ACCESS feature of the Tag is (%1.1X): ", pDataParam->sAccess.dwAccessLockOnOff);
                if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
                    {
                    printf("ON\n");
                    }
                else
                    {
                    printf("OFF\n");
                    }
                }
            else
                {
                printf("%s\n",cTryAgain);
                }
            bBadChoise = PH_ON;
            break;

        default:
            bBadChoise = PH_ON;
            printf("%s\n",cTryAgain);
            break;
        }

    if (!bBadChoise)
        {
        /* data for writing are in the buffer pDataParam->sAccess.pData */
        pDataParam->sTransfer.bBankMemory = PHPAL_I18000P3M3_MEMBANK_RESERVED;
        pDataParam->sTransfer.pWordPtr[0] = I18000P3M3_MEM_ACCESS_PASSWORD_ADDRESS;
        pDataParam->sTransfer.bWordCount = (uint8_t)sizeof(pDataParam->sAccess.pAccessPassword)/2;

        /* data buffer is cleaned by 0 "zero" content */
        status = Write_Password_18000p3m3(pDataParam);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            /* calculate number of received bytes without CRC 16 bits */
            printf("Access password has been written\n");
            }
        else
            {
            ErrorStatusHandler(status);
            status = PH_ERR_SUCCESS;
            }
        }

    return status;
    }


/*==============================================================================================
 * FUNCTION:   SetAccess_ITL
 *
 * Description: Set the access password to the access structure. Access structure is an input
 *              parameter of the Access command
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t SetAccess_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bBadChoise;
    uint32_t      dwLoop;
    int			  printBuffIndex = 1;
	char		  printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    printf("Please select one of the following user access passwords: \n"
    	   "%s\n"
    	   "1 - 0x00000000\n"
    	   "2 - 0x11111111\n"
    	   "3 - 0x12345678\n"
    	   "4 - read user access password\n"
    	   "%s\n", cTableLine2, cTableLine2);


    bBadChoise = PH_OFF; // default bad choice is false
    Read_String (bString,1);

    switch(bString[0])
        {
        case '1':
            /* data buffer is cleaned by 0 "zero" content */
            memset(pDataParam->sAccess.pUserAccessPassword, 0x00, sizeof(pDataParam->sAccess.pAccessPassword));
            break;

        case '2':
            /* default access password "0x 11 11 11 11" is written at the address 0x20 to 0x3F of RESERVED memory bank */
            memcpy(pDataParam->sAccess.pUserAccessPassword, &bAccessPassword1, sizeof(pDataParam->sAccess.pAccessPassword));
            break;

        case '3':
            /* default access password "0x 12 34 56 78" is written at the address 0x20 to 0x3F of RESERVED memory bank */
            memcpy(pDataParam->sAccess.pUserAccessPassword, &bAccessPassword2, sizeof(pDataParam->sAccess.pAccessPassword));
            break;

        case '4':
            /* skip any action, only stored user access password is printed out */
            break;

        default:
            bBadChoise = PH_ON;
            printf("%s\n",cTryAgain);
            break;
        }

    if (!bBadChoise)
        {
        for(dwLoop = WORD_PTR_LEN; dwLoop > 0; dwLoop--)
            {
        	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%02X ", pDataParam->sAccess.pUserAccessPassword[dwLoop-1]);
            }
        printf("User password is set to : 0x %s\n", printBuff);
        printf("ACCESS on the Tag is (%1.1X): ", pDataParam->sAccess.dwAccessLockOnOff);
        if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
            {
            printf("ON\n");
            }
        else
            {
            printf("OFF\n");
            }
        printf("\n");
        }

    return status;
    }
/*==============================================================================================
 * FUNCTION:   Lock_ILT
 *
 * Description: Function performs lock command 0xC5
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Lock_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bBadChoise;

    printf("1 - lock user memory for write (write is possible only if tag is in secured state (access pswd is set))\n"
    	   "2 - unlock user memory for write (write is always possible (secure and open state)) \n",cTableLine , cTableLine);

    bBadChoise = PH_OFF; // default bad choice is false

    /*   - MASK - */
    /* |  7-6 |   5-4  | 3-2 | 1-0 |
     * -----------------------------
     * | Kill | Access | UII | TID |  = pDataParam->sAccess.pMask[0]
     * | User |    0   |  0  |  0  |  = pDataParam->sAccess.pMask[1]
     */

    /*   - ACTION - */
    /* |  7-6 |   5-4  | 3-2 | 1-0 |
     * -----------------------------
     * | Kill | Access | UII | TID |  = pDataParam->sAccess.pAction[0]
     * | User |    0   |  0  |  0  |  = pDataParam->sAccess.pAction[1]
     */

    Read_String (bString,1);
    switch(bString[0])
        {
        case '1':
            /* SET MASK - ACTIVATE ACTION */

            /* set the mask to access password handle */
            pDataParam->sAccess.pMask[0] = LOCK_NO_ACTION;
            pDataParam->sAccess.pMask[1] = LOCK_MASK_USER_MEM_WRITE;
            /* set the action to assert lock the access password */
            pDataParam->sAccess.pAction[0] = LOCK_NO_ACTION;
            pDataParam->sAccess.pAction[1] = LOCK_ACTION_USER_MEM_WRITE;
            break;

        case '2':
            /* SET MASK - DESELECT ACTION */

            /* set the mask to access password handle */
            pDataParam->sAccess.pMask[0] = LOCK_NO_ACTION;
            pDataParam->sAccess.pMask[1] = LOCK_MASK_USER_MEM_WRITE;
            /* set the action to de-assert lock the access password */
            pDataParam->sAccess.pAction[0] = LOCK_NO_ACTION;
            pDataParam->sAccess.pAction[1] = LOCK_NO_ACTION;
            break;

        default:
            bBadChoise = PH_ON;
            printf("%s\n",cTryAgain);
            break;
        }

    if (!bBadChoise)
        {
        /* data for writing are in the buffer pDataParam->sAccess.pData */
        status = Lock_18000p3m3(pDataParam);
        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            /* calculate number of received bytes without CRC 16 bits */
            printf("Lock command has been finished with success.\n");
            }
        else
            {
            ErrorStatusHandler(status);
            status = PH_ERR_SUCCESS;
            }
        }

    return status;
    }


/*==============================================================================================
 * FUNCTION:   List_Detection_18000p3m3
 *
 * Description: Function prints out the detection status immediately after simple inventory
 *              detection. Only in case one tag is placed in the RF field, the CRC of this tag
 *              is displayed
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t List_Detection_18000p3m3(parameters_itl_t *pDataParam)
    {
    uint8_t   aStoredCRC[2];

    printf("\n%s\n",cTableLine);
    memcpy(aStoredCRC, pDataParam->pIdentifier[0].StoredCRC, sizeof(aStoredCRC));
    if (pDataParam->sDetectionParam.bTotalTagsFound == 1)
        {
        printf("Tag detected: CRC: 0x%02X%02X\n", aStoredCRC[0], aStoredCRC[1]);
        }
    else if(pDataParam->sDetectionParam.bTotalTagsFound > 1)
        {
        printf("Multiple tags detected.\n");
        }
    else
        {
        printf("NO tag detected !!!\n"  );
        }

    printf("%s\n",cTableLine);

    return PH_ERR_SUCCESS;
    }

/*==============================================================================================
 * FUNCTION: SimpleInventory_ILT
 *
 * Description: Function performs the inventory based on the Beging_Round command. It is possible
 *              to recognize if a tag based on ISO18000p3m3 is placed in the RF field.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t SimpleInventory_ILT(parameters_itl_t *pDataParam)
    {
    phStatus_t     status;

    status = phhalHw_FieldReset(pDataParam->pHal);
    CHECK_STATUS(status);

    status = phhalHw_ApplyProtocolSettings( pDataParam->pHal, (uint8_t)(PHHAL_HW_CARDTYPE_I18000P3M3 & 0xFF));
    CHECK_STATUS(status);

    status = SimpleInventory_18000p3m3(pDataParam);
    CHECK_STATUS(status);

    return PH_ERR_SUCCESS;
    }

/*==============================================================================================
 * FUNCTION:   SetConfig_18000p3m3
 *
 * Description: Function performs the setting menu, where is possible to set custom general
 *              parameters that affect detection
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t SetConfig_18000p3m3(parameters_itl_t *pDataParam)
    {
    uint8_t        bString[3];
    uint8_t        bStayInConfig = 1;
    uint8_t        bNumber;

    do
        {
        printf("\n"
        	   "ILT - configuration -\n"
        	   "%s\n"
        	   "1 - set Access\n"
        	   "2 - Divide ratio\n"
        	   "3 - Modulation\n"
        	   "4 - TRext\n"
        	   "5 - Selection\n"
        	   "6 - Session\n"
        	   "7 - Q parameter\n"
        	   "%s\n"
        	   "0 - set to default setting\n"
        	   "r - RETURN to Main Menu\n", cTableLine, cTableLine2);

        Read_String (bString,1);

        switch (bString[0])
            {
            case '1':
                printf("Would you like to use the ACCESS command on the Tag?\n"
                	   "0 - No\n"
                       "1 - Yes\n");
                Read_String (bString,1);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)
                if ((!bNumber)||(bNumber == 1))
                    {
                    pDataParam->sAccess.dwAccessLockOnOff = bNumber;
                    printf("ACCESS feature of the Tag is (%1.1X): ", pDataParam->sAccess.dwAccessLockOnOff);
                    if (pDataParam->sAccess.dwAccessLockOnOff == PH_ON)
                        {
                        printf("ON\n");
                        }
                    else
                        {
                        printf("OFF\n");
                        }
                    }
                else
                    {
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '2':
                printf("What should the division ratio be?\n"
                	   "0 - 424KHz\n"
                	   "1 - 847KHz\n");
                Read_String (bString,1);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)
                if ((!bNumber)||(bNumber == 1))
                    {
                    pDataParam->sDetectionParam.bDivideRatio = bNumber;
                    }
                else
                    {
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '3':
                printf("What should the modulation be?\n"
                	   "0 - FM0\n"
                	   "1 - Miller 8\n"
                	   "2 - Manchester 2\n"
                	   "3 - Manchester 4\n");
                Read_String (bString,1);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)

                if ( bNumber < 4 )
                    {
                    pDataParam->sDetectionParam.bModulation = bNumber;
                    }
                else
                    {
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '4':
                printf("What should the TRext be?\n"
                	   "0 - No pilot tone\n"
                	   "1 - pilot tone\n");
                Read_String (bString,1);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)
                if ((!bNumber)||(bNumber == 1))
                    {
                    pDataParam->sDetectionParam.bTRext = bNumber;
                    }
                else
                    {
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '5':
                printf("What should be selected?\n"
                	   "0 - All\n"
                	   "1 - All\n"
                	   "2 - ~SL\n"
                	   "3 - SL\n");
                Read_String (bString,1);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)

                if ( bNumber < 4 )
                    {
                    pDataParam->sDetectionParam.bSelection = bNumber;
                    }
                else
                    {
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '6':
                printf("Which Session should be targeted?\n"
                	   "0 - S0\n"
                	   "2 - S2\n");
                Read_String (bString,1);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)

                if (( !bNumber )||( bNumber == 2 ))
                    {
                    pDataParam->sDetectionParam.bSession = bNumber;
                    }
                else
                    {
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '7':
                printf("Please type value for Q parameter in range 0 - 15:\n"
                	   "Note: nonnumber character means 0\n");
                Read_String (bString,2);
                bNumber = (uint8_t)atoi((char *)bString);   // convert string to byte (8-bit)

                if (( bNumber <= MAX_NUM_OF_ROUNDS))
                    {
                    pDataParam->sDetectionParam.bNumRounds = bNumber;
                    printf("Q parameter set to %d. Reader will perform %d rounds.\n",
                	    pDataParam->sDetectionParam.bNumRounds, 1 << (pDataParam->sDetectionParam.bNumRounds));
                    }
                else
                    {
                    printf("Your enter number is wrong = %d\n", bNumber);
                    printf("%s\n",cTryAgain);
                    }
                break;

            case '0':
                Default_SetConfig_18000p3m3(pDataParam);
                printf("Default parameters setting has been executed !\n");
                break;

            case 'r':
                bStayInConfig = 0;
                break;

            default:
                printf("%s\n",cTryAgain);
                break;
            }
        }   while (bStayInConfig);

    return PH_ERR_SUCCESS;
    }

/*==============================================================================================
 * FUNCTION:   Default_SetConfig_18000p3m3
 *
 * Description: this is a set of default values and parameters, which are set after software reset
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Default_SetConfig_18000p3m3(parameters_itl_t *pDataParam)
    {
    /* ------------------------------------------------------------------------------------ */
    /* parameters which specify the detection */
    pDataParam->sDetectionParam.bTarget         = PHPAL_I18000P3M3_TARGET_INVENTORIED_S0;
    pDataParam->sDetectionParam.bDivideRatio    = PHPAL_I18000P3M3_LF_847KHZ;
    pDataParam->sDetectionParam.bModulation     = PHPAL_I18000P3M3_M_MANCHESTER_4;
    pDataParam->sDetectionParam.bMemoryBank     = PHPAL_I18000P3M3_MEMBANK_UII;
    pDataParam->sDetectionParam.bNumRounds      = DEFAULT_INITIAL_VALUE_OF_Q_INVENTORY_PARAMETER;
    pDataParam->sDetectionParam.bSelection      = PHPAL_I18000P3M3_SEL_ALL_00;
    pDataParam->sDetectionParam.bSession        = PHPAL_I18000P3M3_SESSION_S0;
    pDataParam->sDetectionParam.bTRext          = PH_OFF;
    pDataParam->sDetectionParam.bTotalTagsFound = 0;
    memset(pDataParam->sDetectionParam.StoredCRC,0,sizeof(pDataParam->sDetectionParam.StoredCRC));

    /* tag selection via mask */
    /* reset the pointer where the mask is applied  */
    memset(pDataParam->sDetectionParam.pBitPointer, 0, sizeof(pDataParam->sDetectionParam.pBitPointer));
    /* format of the bitPointer is byte */
    pDataParam->sDetectionParam.bBitPointerLength  = WORD_POINTER_LENGTH_8_BIT;
    /* reset the mask content */
    memset(pDataParam->sDetectionParam.UIIMask, 0, sizeof(pDataParam->sDetectionParam.UIIMask));
    /* reset the mask bits number - if length is zero mask is not applied and the selection is not restricted to the mask*/
    pDataParam->sDetectionParam.bMaskBitLength = 0;
    /* truncate is not asserted */
    pDataParam->sDetectionParam.bTruncate = 0;

    /* ------------------------------------------------------------------------------------ */
    /* parameters which specify the data transfer (read/write/access) */

    pDataParam->sTransfer.bCoverCoding = PHAL_I18000P3M3_AC_NO_COVER_CODING;
    memset(pDataParam->sTransfer.pWordPtr,0,sizeof(pDataParam->sTransfer.pWordPtr));
    pDataParam->sTransfer.bWordPtrLen = WORD_POINTER_LENGTH_8_BIT;
    /* default access to the tag is set to OFF -> access is realized without password */
    pDataParam->sAccess.dwAccessLockOnOff = PH_OFF;
    /* default access password for user is 0x11111111 */
    memcpy(pDataParam->sAccess.pUserAccessPassword, &bAccessPassword1, sizeof(pDataParam->sAccess.pAccessPassword));
    /* IGOR */
    memset(pDataParam->sAccess.pUserAccessPassword, 0x00, sizeof(pDataParam->sAccess.pAccessPassword));

    return PH_ERR_SUCCESS;
    }

/*==============================================================================================
 * FUNCTION: ErrorStatusHandler
 *
 * Description: Function handles error states during ILT tags handling
 *
 ---------------------------------------------------------------------------------------------*/
static void ErrorStatusHandler(phStatus_t status)
    {
	switch (status)
		{
		case ERROR_CARD_ACTIVATE:
			printf("ERROR - Activate Card : Tag is not in the RF field or is not inventoried)\n");
			break;

		case ERROR_REQUEST_RN:
			printf("ERROR - Req_Rn: Tag is not in the RF field\n");
			break;

		case ERROR_READ:
			printf("ERROR - Read\n");
			break;

		case ERROR_WRITE_UNKNOWN:
		case PHAL_I18000P3M3_ERR_OTHER | PH_COMP_AL_I18000P3M3:
			printf("ERROR - Write : Unknown error\n");
			break;

		case PHAL_I18000P3M3_ERR_MEMORY_OVERRUN | PH_COMP_AL_I18000P3M3:
			printf("ERROR - Write : The specified memory location does not exist or the EPC length field"
					" is not supported by the tag");
			break;
		case PHAL_I18000P3M3_ERR_MEMORY_LOCKED | PH_COMP_AL_I18000P3M3:
			printf("ERROR - Write : The specified memory location is locked. "
					"Please Access the tag before Write command usage\n");
			break;
		case PHAL_I18000P3M3_ERR_INSUFFICIENT_POWER | PH_COMP_AL_I18000P3M3:
			printf("ERROR - Write : Insufficient power. Tag is on border of reader field range or"
					" it is shielded by other tags.\n"
					"It is recommended to read the just written part of tag memory. "
					"Only part of requested information might have been written.\n");
			break;

		case PHAL_I18000P3M3_ERR_NON_SPECIFIC | PH_COMP_AL_I18000P3M3:
			printf("ERROR - Write : Non-specific error");
			break;

		case ERROR_WRITE_PASSWORD_UNKNOWN:
			printf("ERROR - Write Password : Unknown error\n");
			break;

		case ERROR_LOCK_ON_NOT_ACCESSED:
			printf("ERROR - Lock : Please, access the tag before Lock command usage - turn Access command ON\n");
			break;

		case ERROR_LOCK_UNKNOWN:
			printf("ERROR - Lock : Unknown error\n");
			break;

		case ERROR_ACCESS_UNKNOWN:
			printf("ERROR - Access : Unknown error with Access command\n");
			break;

		case ERROR_ACCESS_PASSWOD:
			printf("ERROR - Wrong Access Password\n");
			break;

		default:
			printf("Unknown Error: %4.4X", status);
			break;
		}
    }

#endif

/* ---------------------------------------------------------------------------------------------
 *   End of File
 ---------------------------------------------------------------------------------------------*/

