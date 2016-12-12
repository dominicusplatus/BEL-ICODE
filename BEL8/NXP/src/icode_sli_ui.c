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
#include <phhalHw.h>

/* PAL Headers */
#include <phpalSli15693.h>

/*AL Headers*/
#include <phalI15693.h>
#include <phalSli.h>

/* user Headers */
#include <icode_sli_ui.h>
#include <icode_sli_commands.h>
#include <icode_common.h>

#ifdef NXPBUILD_SLI_TAG
/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/
#define BLOCK_NUM_READ_SINGLE_BLOCK                      0
#define BLOCK_NUM_WRITE_SINGLE_BLOCK                     0
#define FIRST_BLOCK_NUM_READ_MULTIPLE_BLOCKS             0
#define NUM_OF_BLOCKS_READ_MULTIPLE_BLOCKS               4

/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local function prototypes
 ---------------------------------------------------------------------------------------------*/
phStatus_t CommandsMenu_SLIX(parameters_sli_t *pDataParam);
phStatus_t InventoryPopulation_SLI(parameters_sli_t *pDataParam);
phStatus_t NumberInventoriedTags_SLI(parameters_sli_t *pDataParam);
phStatus_t ListTags_SLI(parameters_sli_t *pDataParam);
phStatus_t ChooseTag_SLI(parameters_sli_t *pDataParam);
phStatus_t ReadSingleBlock_SLI(parameters_sli_t *pDataParam);
phStatus_t WriteSingleBlock_SLI(parameters_sli_t *pDataParam);
phStatus_t ReadMultipleBlocks_SLI(parameters_sli_t *pDataParam);
phStatus_t ResetToReady_SLI(parameters_sli_t *pDataParam);
phStatus_t ResetToReadyAllTagsLoop_SLI(parameters_sli_t *pDataParam);
phStatus_t StayQuiet_SLI(parameters_sli_t *pDataParam);

#ifdef NXPBUILD_SLIX_2_TAG
phStatus_t CommandsMenu_SLIX2(parameters_sli_t *pDataParam);
phStatus_t SetPassword_SLI(parameters_sli_t *pDataParam);
phStatus_t WritePassword_SLI(parameters_sli_t *pDataParam);
phStatus_t LockPassword_SLI(parameters_sli_t *pDataParam);
phStatus_t ProtectPage_SLI(parameters_sli_t *pDataParam);
phStatus_t GetNXPSystemInformation_SLI(parameters_sli_t *pDataParam);
phStatus_t StayQuietPersistent_SLI(parameters_sli_t *pDataParam);
phStatus_t FastInventoryPopulation_SLI(parameters_sli_t *pDataParam);
#endif

/*==============================================================================================
 * FUNCTION: ISO15693_Init
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ISO15693_Init(
                       parameters_sli_t                  *pDataParamSLI,
                       phpalSli15693_Sw_DataParams_t     *pPalDataParam,
                       phalI15693_Sw_DataParams_t        *pAlDataParam,
                       phalSli_Sw_DataParams_t           *pAlSliDataParam,
                       phhalHw_Rc663_DataParams_t        *pHalDataParam,
                       phPlatform_DataParams_t           *pPlatformDataParam
                       )
   {
   phStatus_t    status;

   pDataParamSLI->pHal = pHalDataParam;
   pDataParamSLI->pPal = pPalDataParam;
   pDataParamSLI->pAl  = pAlDataParam;
   pDataParamSLI->pAlSli  = pAlSliDataParam;
   pDataParamSLI->pPlatform = pPlatformDataParam;

   pDataParamSLI->sAccessParam.bAddressModeOnOff = PH_OFF;

   /* Initialize the 1800p3m3 PAL component */
   status = phpalSli15693_Sw_Init(pPalDataParam, sizeof(phpalSli15693_Sw_DataParams_t), pHalDataParam);
   CHECK_STATUS(status);

   /* Initialize the 15693 AL component */
   status = phalI15693_Sw_Init(pAlDataParam, sizeof(phalI15693_Sw_DataParams_t), pPalDataParam);
   CHECK_STATUS(status);

#ifdef NXPBUILD_SLIX_2_TAG
   /* Initialize the SLI AL component */
   status = phalSli_Sw_Init(pAlSliDataParam, sizeof(phalSli_Sw_DataParams_t), pPalDataParam);
   CHECK_STATUS(status);
#endif

   return status;
   }


/*==============================================================================================
 * FUNCTION: SLI_Main_menu
 *
 * Description: Pointer to HAL and OSAL components must be passed. With this approach
 *              - passing two parameters one by one - it is more obvious which hardware
 *              sources the SLI application consumes. It uses one timer in
 *              Reset To Ready Loop to count seconds.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t MainMenu_SLI(void *pHal, void *pPlatform)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bStayInMenu = 1;

    /* PAL variables*/
    phpalSli15693_Sw_DataParams_t         spalSli15693;           /* PAL 15693 component */

    /* AL variables*/
    phalI15693_Sw_DataParams_t            salI15693;              /* AL 15693 component */

    /* SLIX-2 custom commands API */
    phalSli_Sw_DataParams_t           	   salSli;             	   /* AL SLI custom component */

    /* demo application variables */
    parameters_sli_t                      sDataParamSLI;          /* AL user component */

    /* Initialize the 15693 components */
    status = ISO15693_Init(&sDataParamSLI, &spalSli15693, &salI15693, &salSli, pHal, pPlatform);
    CHECK_STATUS(status);

#ifdef NXPBUILD_SLIX_2_TAG

    while ((status == PH_ERR_SUCCESS) && (bStayInMenu))
        {
        printf("\nSLI - MAIN MENU -\n"
        	   "%s\n"
        	   " i - SLIX    Inventory\n"
        	   " s - SLIX-2  Inventory\n"
        	   "%s\n"
        	   "%s\n\n", cTableLine, cTableLine2, cTableReturnMain);

        Read_String (bString,1);

        switch (bString[0])
            {
            case 'i':
                /* call functions menu for inventory SLIX tags - read - write commands*/
                status = CommandsMenu_SLIX(&sDataParamSLI);
                break;

            case 's':
                /* call functions menu for inventory SLIX-2 tags - read - write commands*/
                status = CommandsMenu_SLIX2(&sDataParamSLI);
                break;

            case 'r':
                /* return to upper menu of UI */
                bStayInMenu = 0;
                break;

            default:
                printf("%s\n",cTryAgain);
                break;
            }
        }
#else
    /* only SLIX tags are provided */
    /* call functions menu for inventory SLIX tags - read - write commands*/
    status = CommandsMenu_SLIX(&sDataParamSLI);
#endif

    return status;
    }


/*==============================================================================================
 * FUNCTION: CommandsMenu_SLIX
 *
 * Description: Functions performs printout of the SLIX user interface - SLIX menu.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t CommandsMenu_SLIX(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[3];
    uint8_t       bStayInMenu = 1;

    bString[0] = 'i';

    while ((status == PH_ERR_SUCCESS) && (bStayInMenu))
        {
        switch(bString[0])
            {
            case '1':
                printf("SLIX - read\n"
                	   "%s\n",cTableLine);
                status = ReadSingleBlock_SLI(pDataParam);
                break;

            case '2':
                printf("SLIX - write\n"
                	   "%s\n",cTableLine);
                status = WriteSingleBlock_SLI(pDataParam);
                break;

            case '3':
                printf("SLIX - read multiple blocks\n"
                	   "%s\n",cTableLine);
                status = ReadMultipleBlocks_SLI(pDataParam);
                break;

            case '4':
                printf("SLIX - Stay Quiet\n"
                	   "%s\n",cTableLine);
                /* call menu function performing stay */
                status = StayQuiet_SLI(pDataParam);
                break;

            case '5':
                printf("SLIX - reset to ready\n");
                /* call menu function performing */
                status = ResetToReady_SLI(pDataParam);
                break;
            case '6':
                printf("Reset to ready Loop\n"
                	   "%s\n",cTableLine);
                status = ResetToReadyAllTagsLoop_SLI(pDataParam);
                break;

            case 'i':
                printf("SLIX - Inventory\n"
                	   "%s\n",cTableLine);
                pDataParam->sDetectionParam.bFastInventoryRead = PH_OFF;
                status = InventoryPopulation_SLI(pDataParam);
                CHECK_STATUS(status);
                status = ListTags_SLI(pDataParam);
                CHECK_STATUS(status);
                status = ChooseTag_SLI(pDataParam);
                CHECK_STATUS(status);
                break;

            case 'n':
                printf("SLIX - Number of Inventoried Tags\n");
                status = NumberInventoriedTags_SLI(pDataParam);
                CHECK_STATUS(status);
                break;

            case 'r':
                /* return to upper menu of UI */
                bStayInMenu = 0;
                break;

            default:
                printf("%s\n",cTryAgain);
                break;
            }

        if (bStayInMenu)
            {
            /* display the menu in the console */
            printf("\nSLIX - COMMANDS -\n"
            	   "%s\n",cTableLine);
            printf("1 - Read Single Block       (read block (0x%2.2X) - 4 bytes)\n"
            	   "2 - Write Single Block      (write 4 bytes to block (0x%2.2X))\n"
            	   "3 - Read Multiple Blocks    (read 2 blocks (8 bytes) from 0x%2.2X to 0x%2.2X)\n",
            		BLOCK_NUM_READ_SINGLE_BLOCK,
            		BLOCK_NUM_WRITE_SINGLE_BLOCK,
            		FIRST_BLOCK_NUM_READ_MULTIPLE_BLOCKS, FIRST_BLOCK_NUM_READ_MULTIPLE_BLOCKS + NUM_OF_BLOCKS_READ_MULTIPLE_BLOCKS - 1);
            printf("4 - Stay Quiet              (put selected tag into Stay Quite state)\n"
            	   "5 - Reset tag(s) to ready   (one shot Reset To Ready command)\n"
            	   "6 - Broadcast reset loop    (non-addressed transmission of Reset To Ready command)\n"
            	   "%s\n"
            	   "i - Inventory               (detection of all tags in the RF field)\n"
            	   "n - Number of Tags          (endless loop inventory - for exit please press the LPCXpresso Restart button)\n"
            	   "%s\n\n", cTableLine2, cTableReturn);

            /* read the choise */
            Read_String (bString,1);

            /* this menu has to finish with OK status */
            status = PH_ERR_SUCCESS;
            }
        }
    return status;
    }


/*==============================================================================================
 * FUNCTION: InventoryPopulation_SLI
 *
 * Description: Function performs the inventory of tags which are placed in the RF field
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t InventoryPopulation_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t     status;

    /* Field reset must not be performed here because if a tag was in the Quiet state, then
     * power off would mate it enter to the Ready state, while user would not be aware */

    status = phhalHw_ApplyProtocolSettings(pDataParam->pHal, (uint8_t)(PHHAL_HW_CARDTYPE_ISO15693 & 0xFF));
    CHECK_STATUS(status);

    status = InventoryPopullation_15693(pDataParam);

    if((status & PH_COMPID_MASK) == ERROR_SLI_OVERFLOW_NUMBER_OF_DETECTED_TAGS)
    	{
    	printf("More tags detected than maximum software limit.\n");
    	status = PH_ERR_SUCCESS;
    	}

    return status;
    }


/*==============================================================================================
 * FUNCTION: NumberInventoriedTags_SLI
 *
 * Description: Function performs endless loop of inventory of all tags in the field.
 *              Current number of present tags is printed on the console.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t NumberInventoriedTags_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status;
    uint32_t      dwCounter = 0;
    uint32_t      i;

    while (1)
        {
        dwCounter++;

        status = phhalHw_FieldReset(pDataParam->pHal);
        CHECK_STATUS(status);

        status = phhalHw_ApplyProtocolSettings(pDataParam->pHal, (uint8_t)(PHHAL_HW_CARDTYPE_ISO15693 & 0xFF));
        CHECK_STATUS(status);

        status = InventoryPopullation_15693(pDataParam);
        CHECK_STATUS(status);

        if (!(dwCounter%10))
            {
            printf("number of detected tags:\n");
            }
        printf("%d\n",     pDataParam->sDetectionParam.bTotalTagsFound);
        }
    for (i=0x1000000; i>0; i--);

    return status;
    }


/*==============================================================================================
 * FUNCTION: ListTags_SLI
 *
 * Description: Function prints out the table of SLI tags data.
 *              Data consists of number of detected tags, tag type and UID
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ListTags_SLI(parameters_sli_t *pDataParam)
    {
    uint32_t   i,j;
    uint32_t printBuffIndex = 1;
    char printBuff[SPRINTF_LONG_BUFFER_SIZE];
    uint16_t listLineCounter = 0;

    printf("\n%s\n"
    	   "number of detected tags: %d\n", cTableLine, pDataParam->sDetectionParam.bTotalTagsFound);

    if(pDataParam->sDetectionParam.bTotalTagsFound > 0)
        {
        printf("%s\n"
        	   "|No.|  type  | UID |\n"
        	   "%s\n", cTableLine, cTableLine);

        for (i = 0; i < pDataParam->sDetectionParam.bTotalTagsFound; i++)
            {
            /* print number */
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "|%3d| ", i+1);
            switch(pDataParam->pIdentifier[i].tagType)
                {
                case Sli:
                    printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "  SLI   | ");
                    break;
                case Slix:
                    printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "  SLIX  | ");
                    break;
                case Slix2:
                    printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "  SLIX2 | ");
                    break;
                case Sli_RFU:
                    printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], " SLI RFU | ");
                    break;
                default:
                    printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], " Invalid | ");
                    break;
                }

            /* print UID */
            for (j = UID_15693_BYTE_LENGTH; j > 0; j--)
                {
            	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%2.2X ", pDataParam->pIdentifier[i].UID[j - 1]);
                }
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "|\n");

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
        printf("%s\n", cTableLine);
        }

    return PH_ERR_SUCCESS;
    }


/*==============================================================================================
 * FUNCTION: ChooseTag_SLI
 *
 * Description: Function performs Tag selection on the basis of user choose,
 *              UID of the tag is stored and will be used as mask for commands execution
 **
 ---------------------------------------------------------------------------------------------*/
phStatus_t ChooseTag_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status;
    uint8_t       bString[3];
    uint32_t      i;
    uint32_t      dwTagNumber;
    int printBuffIndex = 1;
    char printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    if ((pDataParam->sDetectionParam.bTotalTagsFound != 0) && (pDataParam->sDetectionParam.bTotalTagsFound <= MAX_NUM_DETECTED_SLI_TAGS))
        {
        do
            {
            /* if there is only one tag inventoried, this one is automatically set as chosen */
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

            /* the choosen value has to be from relevant range (1 - max) or 0 = return*/
            if ((dwTagNumber != 0) && (dwTagNumber <= MAX_NUM_DETECTED_SLI_TAGS))
                {
                printf("choice > %d\n\n", dwTagNumber);
                dwTagNumber--; // correct the selected number

                /* check the scale, if enter number is not out of range */
                if (dwTagNumber < pDataParam->sDetectionParam.bTotalTagsFound)
                    {
                    /* copy the UII to the MASK field */
                    memcpy(pDataParam->sDetectionParam.aUIDMask, &pDataParam->pIdentifier[dwTagNumber].UID, UID_15693_BYTE_LENGTH);
                    /* set the adressed mode to be able work only with the chosen tag */
                    pDataParam->pPal->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;  /**< UID field is included in command frame. */
                    /* print UID */
                    for (i = UID_15693_BYTE_LENGTH; i > 0; i--)
                        {
                    	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%2.2X ", pDataParam->sDetectionParam.aUIDMask[i - 1]);
                        }
                    printf("UID: %s\n", printBuff);
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
        memset( pDataParam->sDetectionParam.aUIDMask, 0x00,UID_15693_BYTE_LENGTH);
        status = PH_ERR_SUCCESS;
        }

    return status;
    }


/*==============================================================================================
 * FUNCTION: Read_SLI
 *
 * Description: This function reads block 0 from a previously chosen tag
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ReadSingleBlock_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t	status;
    uint8_t	bIndex;
    uint8_t tmpPrintBuffer[SLI_BLOCK_SIZE + 1]; //this is due to printf purpose
    int printBuffIndex = 1;
    char printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    /* set the block number for reading */
    pDataParam->sReadSingleBlock.bBlockNum = BLOCK_NUM_READ_SINGLE_BLOCK;

    status = ReadSingleBlock_15693(pDataParam);

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
        for(bIndex = 0; bIndex < pDataParam->sReadSingleBlock.wRxLength; bIndex++)
            {
        	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%02X ", pDataParam->sReadSingleBlock.aReadBlockBuffer[bIndex]);
            }
        printf("Block number %d\n"
               "%d bytes read:\n"
               "%s\n", pDataParam->sReadSingleBlock.bBlockNum,
			   	   	 pDataParam->sReadSingleBlock.wRxLength,
					 printBuff);

        /* copy content of the read block to first 4 bytes of the tmpPrintBuffer */
        memcpy(tmpPrintBuffer, pDataParam->sReadSingleBlock.aReadBlockBuffer, SLI_BLOCK_SIZE);
        /* at the end of the tmpPrintBuffer append end of string character */
        tmpPrintBuffer[SLI_BLOCK_SIZE] = '\0';

        printf("Content =  %s\n", tmpPrintBuffer);
        }
    else
        {
        /* status is returned at the end of the function */
        printf("ERROR - Read\n");
        }
    return status;
    }


/*==============================================================================================
 * FUNCTION: Write_SLI
 *
 * Description: This function writes 4 bytes to block 0 on a previously chosen tag
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t WriteSingleBlock_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t	status;
    uint8_t	bIndex;
    uint8_t	bString[1];
    int printBuffIndex = 1;
	char printBuff[SPRINTF_SHORT_BUFFER_SIZE];

    uint8_t aStringToWrite[SLI_BLOCK_SIZE] = {'N','X','P','_'};

    pDataParam->sWriteSingleBlock.bBlockNum = BLOCK_NUM_WRITE_SINGLE_BLOCK;

    /* firstly user has to choose whether to write to previously chosen tag or to all tags in the RF field */
    printf("1 - addressed mode - write to previously chosen tag\n"
    	   "2 - non addressed mode - write to all tags\n");
    Read_String(bString, 1);
    while(bString[0] != '1' && bString[0] != '2')
        {
        printf("invalid input, please retry\n");
        Read_String(bString, 1);
        }

    if(bString[0] == '1')
        /* write to previously chosen tag */
        pDataParam->sAccessParam.bAddressModeOnOff = PH_ON;
    else
        /* write to all tags in the RF field */
        pDataParam->sAccessParam.bAddressModeOnOff = PH_OFF;


    /* further user chooses which content shall be written to the block */
    printf("1 - write \"NXP_\" to block %d\n", BLOCK_NUM_WRITE_SINGLE_BLOCK);
    printf("2 - clear block %d\n", BLOCK_NUM_WRITE_SINGLE_BLOCK);
    Read_String(bString, 1);
    while(bString[0] != '1' && bString[0] != '2')
        {
        printf("invalid input, please retry\n");
        Read_String(bString, 1);
        }

    if(bString[0] == '1')
        /* NXP_ shall be written to the block */
        memcpy(pDataParam->sWriteSingleBlock.aWriteBlockBuffer, aStringToWrite, SLI_BLOCK_SIZE);
    else
        /* four zeros shall be written to the block */
        memset(pDataParam->sWriteSingleBlock.aWriteBlockBuffer, 0x00, SLI_BLOCK_SIZE);

    status = WriteSingleBlock_15693(pDataParam);

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
        for(bIndex = 0; bIndex < sizeof(pDataParam->sWriteSingleBlock.aWriteBlockBuffer); bIndex++)
            {
        	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%02X ", pDataParam->sWriteSingleBlock.aWriteBlockBuffer[bIndex]);
            }

        printf("Sequence %s written successfully to block %d\n", printBuff, pDataParam->sWriteSingleBlock.bBlockNum);
        }
    else
        {
        /* status is returned at the end of the function */
        printf("ERROR - Write\n");
        }
    return status;
    }

/*==============================================================================================
 * FUNCTION: ReadMultipleBlocks_SLI
 *
 * Description: This function reads blocks 0 and 1 from previously chosen tag beginning
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ReadMultipleBlocks_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t	status;
    uint16_t	bIndex;
    int			printBuffIndex = 1;
	char		printBuff[SPRINTF_LONG_BUFFER_SIZE];
	uint16_t	listLineCounter = 0;

    pDataParam->sReadMultipleBlocks.bFirstBlockNo = FIRST_BLOCK_NUM_READ_MULTIPLE_BLOCKS;
    pDataParam->sReadMultipleBlocks.wNumOfBlocks  = NUM_OF_BLOCKS_READ_MULTIPLE_BLOCKS;

    status = ReadMultipleBlocks_15693(pDataParam);

    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
        {
    	printf("%d bytes read:\n"
    	        	   "Block number | Block content\n", pDataParam->sReadMultipleBlocks.wRxLength);

        for(bIndex = 0; bIndex < pDataParam->sReadMultipleBlocks.wRxLength; bIndex++)
            {
            if(bIndex % SLI_BLOCK_SIZE == 0)
                {
            	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1],
            			"%02X           | ", pDataParam->sReadMultipleBlocks.bFirstBlockNo + bIndex / 4);
                }

            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1],
            		"%02X ", pDataParam->sReadMultipleBlocks.pReadBuff[bIndex]);

            if(bIndex % SLI_BLOCK_SIZE == 3 && bIndex > 0)
                {
            	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "\n");

            	if(++listLineCounter == MAX_NUMBER_OF_LINES_OF_LIST_PER_PRINTOUT || bIndex >= pDataParam->sReadMultipleBlocks.wRxLength - 1)
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
            }

        printf("Content =  %s\n", pDataParam->sReadMultipleBlocks.pReadBuff);
        }
    else
        {
        /* status is returned at the end of the function */
        printf("ERROR - ReadMultipleBlocks\n");
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION: StayQuiet_SLI
 *
 * Description: This function makes enter a previously chosen tag to the Quiet state
 * 		Stay Quiet must always be requested in Addressed mode.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t StayQuiet_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;

    status = StayQuiet_15693(pDataParam);

    if(status == PH_ERR_SUCCESS)
        {
        printf("Request transfered successfully\n");
        }
    else
	{
	printf("ERROR - Stay Quiet\n");
	status = PH_ERR_SUCCESS;
	}

    return status;
    }

/*==============================================================================================
 * FUNCTION:	ResetToReady_SLI
 *
 * Description:	This function transfers previously chosen tag to the Ready state
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ResetToReady_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t	status = PH_ERR_SUCCESS;
    uint8_t	bString[1];

    /* firstly user has to choose whether to write to previously chosen tag or to all tags in the RF field */
    printf("1 - addressed mode - reset to ready previously chosen tag\n"
    	   "2 - non addressed mode - reset to ready all tags\n");
    Read_String(bString, 1);
    while(bString[0] != '1' && bString[0] != '2')
        {
        printf("invalid input, please retry\n");
        Read_String(bString, 1);
        }

    if(bString[0] == '1')
        {
        /* write to previously chosen tag */
        pDataParam->sAccessParam.bAddressModeOnOff = PH_ON;
        }
    else
        {
        /* write to all tags in the RF field */
        pDataParam->sAccessParam.bAddressModeOnOff = PH_OFF;
        }

    status = ResetToReady_15693(pDataParam);

    if(status != PH_ERR_SUCCESS)
        {
        printf("ERROR - Reset to Ready\n");
        status = PH_ERR_SUCCESS;
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION: ResetToReadyAllTagsLoop_SLI
 *
 * Description: This function transfers all the tags currently in the RF field to the Ready state
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ResetToReadyAllTagsLoop_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t	status = PH_ERR_SUCCESS;
    uint8_t	bString[1];

    printf("Please, type how many seconds (1 - 9) do you need to broadcast Reset To Ready.\n");

    Read_String(bString, 1);

    while((bString[0] > '9' || bString[0] < '1') && bString[0] != 'r' && bString[0] != 'R')
        {
        printf("Invalid input, please retry (1 - 9 or 'r' for return)\n");
        Read_String(bString, 1);
        }

    if(bString[0] <= '9' && bString[0] >= '1')
        {
        pDataParam->sResetToReadyLoop.bResetLoopDuration = (uint32_t)atoi((char *) &bString[0]);
        printf("duration: %d\n", pDataParam->sResetToReadyLoop.bResetLoopDuration);
        status = ResetToReadyAllTagsLoop_15693(pDataParam);

        if(status == PH_PLATFORM_ERR_NO_FREE_TIMER)
            {
            printf("no free timer available\n");
            return PH_ERR_SUCCESS;
            }

        if(status == PH_PLATFORM_ERR_INVALID_TIMER)
            {
            printf("internal error - try to use invalid timer\n");
            status = PH_ERR_SUCCESS;
            }

        if(status == PH_ERR_SUCCESS)
            {
            printf("tags reseted\n");
            }
        }
    else
        {
        printf("\n");
        status = PH_ERR_SUCCESS;
        }

    return status;
    }


#ifdef NXPBUILD_SLIX_2_TAG
/*==============================================================================================
 * FUNCTION: CommandsMenu_SLIX2
 *
 * Description: Functions performs printout of the SLIX-2 user interface - SLIX-2 menu.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t CommandsMenu_SLIX2(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bStayInMenu = 1;

    /* set the case "inventory" like a first step in the menu */
    bString[0] = 'i';

    while ((status == PH_ERR_SUCCESS) && (bStayInMenu))
        {
        switch(bString[0])
            {
            case '1':
                printf("SLIX-2 - Read\n"
                	   "%s\n", cTableLine);
                status = ReadSingleBlock_SLI(pDataParam);
                break;

            case '2':
                printf("SLIX-2 - Write\n"
                	   "%s\n", cTableLine);
                status = WriteSingleBlock_SLI(pDataParam);
                break;

            case '3':
                printf("SLIX-2 - Read Multiple Blocks\n"
                	   "%s\n", cTableLine);
                status = ReadMultipleBlocks_SLI(pDataParam);
                break;

            case '4':
                printf("SLIX-2 - Get NXP System Information\n"
                	   "%s\n", cTableLine);
                /* call functions menu for getting system and protection information*/
                status = GetNXPSystemInformation_SLI(pDataParam);
                break;

            case '5':
                printf("SLIX-2 - Set Password\n"
                	   "%s\n", cTableLine);
                status = SetPassword_SLI(pDataParam);
                break;

            case '6':
                printf("SLIX-2 - Write Password\n"
                	   "%s\n", cTableLine);
                status = WritePassword_SLI(pDataParam);
                break;

            case '7':
                printf("SLIX-2 - Lock Password\n"
                	   "%s\n", cTableLine);
                status = LockPassword_SLI(pDataParam);
                break;

            case '8':
                printf("SLIX-2 - Protect Page\n"
                	   "%s\n", cTableLine);
                status = ProtectPage_SLI(pDataParam);
                break;

            case 'q':
                printf("Stay Quiet\n"
                	   "%s\n", cTableLine);
                status = StayQuiet_SLI(pDataParam);
                break;

            case 'p':
                printf("Stay Quiet Persistent\n"
                	   "%s\n", cTableLine);
                status = StayQuietPersistent_SLI(pDataParam);
                break;

            case 's':
                printf("Reset To Ready\n"
                	   "%s\n", cTableLine);
                status = ResetToReady_SLI(pDataParam);
                break;

            case 'x':
                printf("Reset to ready Loop\n"
                	   "%s\n", cTableLine);
                status = ResetToReadyAllTagsLoop_SLI(pDataParam);
                break;

            case 'i':
                printf("SLIX - Inventory\n");
                pDataParam->sDetectionParam.bFastInventoryRead = PH_ON;
                status = InventoryPopulation_SLI(pDataParam);
                CHECK_STATUS(status);
                status = ListTags_SLI(pDataParam);
                CHECK_STATUS(status);
                status = ChooseTag_SLI(pDataParam);
                CHECK_STATUS(status);
                break;

            case 'f':
            	printf("SLIX-2 - Fast Inventory\n");
            	pDataParam->sDetectionParam.bFastInventoryRead = PH_ON;
            	status = FastInventoryPopulation_SLI(pDataParam);
            	CHECK_STATUS(status);
            	status = ListTags_SLI(pDataParam);
            	CHECK_STATUS(status);
            	status = ChooseTag_SLI(pDataParam);
            	CHECK_STATUS(status);
            	break;

            case 'n':
                printf("SLIX - Number of Inventoried Tags\n");
                status = NumberInventoriedTags_SLI(pDataParam);
                CHECK_STATUS(status);
                break;

            case 'r':
                /* return to upper menu of UI */
                bStayInMenu = 0;
                break;

            default:
                printf("%s\n",cTryAgain);
                break;
            }

        if (bStayInMenu)
            {
            /* display the menu in the console */
            printf("\nSLIX-2 - COMMANDS -\n"
            	   "%s\n", cTableLine);
            printf("1 - Read Single Block       (read block (0x%2.2X) - 4 bytes)\n"
            	   "2 - Write Single Block      (write 4 bytes to block (0x%2.2X))\n"
            	   "3 - Read Multiple Blocks    (read 2 blocks (8 bytes) from 0x%2.2X to 0x%2.2X)\n",
            		BLOCK_NUM_READ_SINGLE_BLOCK,
            		BLOCK_NUM_WRITE_SINGLE_BLOCK,
            		FIRST_BLOCK_NUM_READ_MULTIPLE_BLOCKS, FIRST_BLOCK_NUM_READ_MULTIPLE_BLOCKS + NUM_OF_BLOCKS_READ_MULTIPLE_BLOCKS - 1);
            printf("4 - Get NXP System Information\n"
            	   "5 - Set Password            (enter password to access protected part of tag)\n"
            	   "6 - Write Password          (change access password on the tag)\n"
            	   "7 - Lock Password           (!!! permanent lock of access password on the tag (irreversible!!!))\n"
            	   "8 - Protect Page            (activates Protect feature on the tag)\n"
            	   "q - Stay Quiet              (put selected tag into Stay Quite state)\n"
            	   "p - Stay Quiet Persistent   (put selected tag into Stay Quite Persistent state)\n"
            	   "s - Reset tag(s) to ready   (one shot Reset To Ready command)\n"
            	   "x - Broadcast reset loop    (non-addressed transmission of Reset To Ready command)\n"
            	   "%s\n"
            	   "i - Inventory               (detection of all tags in the RF field)\n"
            	   "f - Fast Inventory          (detection of all SLIX-2 tags in the RF field)\n"
            	   "n - Number of Tags          (endless loop inventory - for exit please press the LPCXpresso Restart button)\n"
            	   "%s\n\n", cTableLine2, cTableReturn);

            /* read the choise */
            Read_String (bString,1);

            /* this menu has to finish with OK status */
            status = PH_ERR_SUCCESS;
            }
        }
    return status;
    }

/*==============================================================================================
 * FUNCTION: FastInventoryPopulation_SLI
 *
 * Description: Function performs the inventory of tags which are placed in the RF field
 *              using FastInventoryRead command.
 * 				This detection is less successful than InventoryPopulation_SLI(), it might overlook
 * 				some tags unpredictably.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t FastInventoryPopulation_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t     status;

    /* Field reset must not be performed here because if a tag was in the Quiet state, then
     * power off would mate it enter to the Ready state, while user would not be aware */

    status = phhalHw_ApplyProtocolSettings(pDataParam->pHal, (uint8_t)(PHHAL_HW_CARDTYPE_ISO15693 & 0xFF));
    CHECK_STATUS(status);

    status = FastInventoryPopullation_15693(pDataParam);

    if((status & PH_COMPID_MASK) == ERROR_SLI_OVERFLOW_NUMBER_OF_DETECTED_TAGS)
    	{
    	printf("More tags detected than maximum software limit.\n");
    	status = PH_ERR_SUCCESS;
    	}

    return status;
    }

/*==============================================================================================
 * FUNCTION: GetNXPSystemInformation_SLI
 *
 * Description: Function performs Get NXP System Information command. Information from response
 * 				printouts in summary list.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t GetNXPSystemInformation_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t status;

    uint32_t printBuffIndex = 1;
    char printBuff[SPRINTF_LONG_BUFFER_SIZE];

	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "  SLI   | ");

    status = GetNXPSystemInformation_Slix2(pDataParam);

    if(status == PH_ERR_SUCCESS)
        {
        /* info about protection pointer */
    	printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "Protection pointer:     0x%2.2X\n", pDataParam->sGetNxpSystemInfo.bProtectionPointer);

        /* info about protection condition */
        printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "Protection conditions:  0x%2.2X\n", pDataParam->sGetNxpSystemInfo.bProtectionCondition);
        printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%s\n",cTableLine2);

        /*   - CONDITIONS -   */

        if (pDataParam->sGetNxpSystemInfo.bProtectionCondition & PAGE_L_READ_PASSWORD_PROTECTION_STATUS_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "L page read   - PROTECTED\n");
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "L page read   - NOT PROTECTED\n");
            }

        if (pDataParam->sGetNxpSystemInfo.bProtectionCondition & PAGE_L_WRITE_PASSWORD_PROTECTION_STATUS_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "L page write  - PROTECTED\n");
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "L page write  - NOT PROTECTED\n");
            }

        if (pDataParam->sGetNxpSystemInfo.bProtectionCondition & PAGE_H_READ_PASSWORD_PROTECTION_STATUS_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "H page read   - PROTECTED\n");
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "H page read   - NOT PROTECTED\n");
            }

        if (pDataParam->sGetNxpSystemInfo.bProtectionCondition & PAGE_H_WRITE_PASSWORD_PROTECTION_STATUS_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "H page write  - PROTECTED\n");
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "H page write  - NOT PROTECTED\n");
            }

        printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "%s\n",cTableLine2);

        /*  --- SYTEM INFORMATION ---  */

        if (pDataParam->sGetNxpSystemInfo.bLockBits & LOCK_BIT_AFI_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "AFI    - locked\n");
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "AFI    - not locked\n");
            }

        if (pDataParam->sGetNxpSystemInfo.bLockBits & LOCK_BIT_EAS_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "EAS    - locked\n");
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "EAS    - not locked\n");
            }

        if(pDataParam->sGetNxpSystemInfo.bLockBits & LOCK_BIT_DSFID_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "DSFID  - locked\n", pDataParam->sGetNxpSystemInfo.bLockBits);
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "DSFID  - not locked\n");
            }

        if(pDataParam->sGetNxpSystemInfo.bLockBits & LOCK_BIT_PPL_MASK)
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "PPL    - locked\n", pDataParam->sGetNxpSystemInfo.bLockBits);
            }
        else
            {
            printBuffIndex += sprintf(&printBuff[printBuffIndex - 1], "PPL    - not locked\n");
            }

        printf("%s", printBuff);
        }
    else if(status == ERROR_SLI_UNSUPPORTED_COMMAND)
	{
	printf("ERROR - Get NXP System Information command is not supported by chosen tag\n");
	status = PH_ERR_SUCCESS;
	}
    else
	{
	printf("ERROR - Get NXP System Information\n");
	}


    return status;
    }

/*==============================================================================================
 * FUNCTION: SetPassword_SLI
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t SetPassword_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bBadChoise;
    uint8_t       bString[8];
    uint32_t      dwPassword;

    /* printout options for which operations the access via set password command is set */
    printf("1 - enter the password to access \"reading\" operations\n"
    	   "2 - enter the password to access \"writing\" operations\n");

    bBadChoise = PH_OFF; // default bad choice is false
    Read_String (bString,1);

    switch(bString[0])
        {
        case '1':
            /* set the password identifier for READ operations */
            pDataParam->sAccessParam.bPwdIdentifier = PHAL_SLI_PWD_READ;
            break;
        case '2':
            /* set the password identifier for WRITE operations */
            pDataParam->sAccessParam.bPwdIdentifier = PHAL_SLI_PWD_WRITE;
            break;
        default:
            bBadChoise = PH_ON;
            printf("%s\n",cTryAgain);
            break;
        }

    if (!bBadChoise)
        {
        /* enter the access password for corresponding operation */
        printf("enter the current password to access the tag (32-bit MSB first - hex: 0xXXXXXXXX)\n");
        Read_String (bString,8);
        dwPassword = strtoul((char *)bString, NULL, 16);
        printf("Entered password is: 0x%8.8X\n", dwPassword);
        /* copy the entered password to the access structure -> to hold it generally,
         * it will be used for write password command */
        memcpy(pDataParam->sAccessParam.aPassword, &dwPassword, ACCESS_PASWORD_LENGTH);

         status = GetRandomNumberSetPWD_Slix2(pDataParam);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            if (pDataParam->sAccessParam.bPwdIdentifier == PHAL_SLI_PWD_READ)
                {
                printf("The password for \"reading\" operations is set. \n");
                }
            if (pDataParam->sAccessParam.bPwdIdentifier == PHAL_SLI_PWD_WRITE)
                {
                printf("The password for \"writing\" operations is set. \n");
                }
            }
        else if(status == ERROR_SLI_UNSUPPORTED_COMMAND)
            {
        	/* SLIX-2 specification, after bad password set, necessary to perform POR Power-On-Reset , or unsupported command */
        	printf("ERROR - Incorrect password or Set Password command is not supported by chosen tag\n");
            printf("Please, it is necessary to remove tag from the field and insert it back after enter a wrong password.\n");
            status = PH_ERR_SUCCESS;
            }
        else
            {
            /* status is returned at the end of the function */
        	printf("ERROR - Set Password\n");
            status = PH_ERR_SUCCESS;
            }
        }
    return status;
    }

/*==============================================================================================
 * FUNCTION: WritePassword_SLI
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t WritePassword_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint32_t      dwPassword;
    uint8_t       bString[8];

    /* set the password identifier for READ and WRITE operations only */
    if ((pDataParam->sAccessParam.bPwdIdentifier & PHAL_SLI_PWD_READ) || (pDataParam->sAccessParam.bPwdIdentifier & PHAL_SLI_PWD_WRITE))
        {
        if (pDataParam->sAccessParam.bPwdIdentifier == PHAL_SLI_PWD_READ)
             {
            printf("\"Reading\" operations password setting.\n");
             }
         if (pDataParam->sAccessParam.bPwdIdentifier == PHAL_SLI_PWD_WRITE)
             {
             printf("\"Writing\" operations password setting.\n");
             }
         /* enter the access password for corresponding operation */
        printf("Please enter new password (32-bit MSB first - hex: 0xXXXXXXXX)\n");
        Read_String (bString,8);
        dwPassword = strtoul((char *)bString, NULL, 16);
        printf("new password is: 0x%8.8X\n", dwPassword);

        /* copy the entered password to the access structure -> to hold it generally */
        memcpy(pDataParam->sAccessParam.aPassword, &dwPassword, ACCESS_PASWORD_LENGTH);

        status = WritePassword_Slix2(pDataParam);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            printf("OK - access password written \n");
            }
        else if(status == ERROR_SLI_UNSUPPORTED_COMMAND)
            {
            printf("ERROR - Write Password command is not supported by chosen tag\n");
            status = PH_ERR_SUCCESS;
            }
        else
            {
            /* status is returned at the end of the function */
            printf("ERROR - Write Password\n");
            status = PH_ERR_SUCCESS;
            }
        }
    else
        {
        printf("ERROR - not chosen operation R/W\n");
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION: LockPassword_SLI
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t LockPassword_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;

    /* set the password identifier for READ and WRITE operations only */
    if ((pDataParam->sAccessParam.bPwdIdentifier & PHAL_SLI_PWD_READ) || (pDataParam->sAccessParam.bPwdIdentifier & PHAL_SLI_PWD_WRITE))
        {
        status = LockPassword_Slix2(pDataParam);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            printf("OK - access password has been permanently locked\n");
            }
        else if(status == ERROR_SLI_UNSUPPORTED_COMMAND)
            {
            printf("ERROR - Lock Password command is not supported by chosen tag\n");
            status = PH_ERR_SUCCESS;
            }
        else
            {
            /* status is returned at the end of the function */
            printf("ERROR - Lock Password\n"
            	   "%s\n"
            	   "NOTE: before calling \"Lock Password\" command, please call \"Set Password\" function.\n", cTableLine2);
        status = PH_ERR_SUCCESS;
            }
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION: ProtectPage_SLI
 *
 * Description: Function performs Protect Page command.
 *              !!!Attention: Protection option is saved despite not lock operation is not sucessful.
 *              Choosing option adds it to previous ones - cumulative behaveiour.
 *              Only option '5' clears all previous options. It is recommended to clear protection
 *              when switching to among tags to avoid unaware transfer of protection options betewwn tags.
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t ProtectPage_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;
    uint8_t       bString[1];
    uint8_t       bBadChoise;

    printf("1 - protect page L for reading\n"
    	   "2 - protect page H for reading\n"
    	   "3 - protect page L for writing\n"
    	   "4 - protect page H for writing\n"
    	   "5 - clear protection\n"
    	   "%s\n"
    	   "NOTE: before calling \"Protect Page\" command, please call \"Set Password\" function to enter READ and WRITE password.\n", cTableLine2);

    bBadChoise = PH_OFF; // default bad choice is false
    Read_String (bString,1);

    switch(bString[0])
        {
        case '1':
            pDataParam->sProtection.bProtectionStatus |= PAGE_L_READ_PASSWORD_PROTECTION_STATUS_MASK;
            break;
        case '2':
            pDataParam->sProtection.bProtectionStatus |= PAGE_H_READ_PASSWORD_PROTECTION_STATUS_MASK;
            break;
        case '3':
            pDataParam->sProtection.bProtectionStatus |= PAGE_L_WRITE_PASSWORD_PROTECTION_STATUS_MASK;
            break;
        case '4':
            pDataParam->sProtection.bProtectionStatus |= PAGE_H_WRITE_PASSWORD_PROTECTION_STATUS_MASK;
            break;
        case '5':
            /* clear protection by clearing the protection status register */
            pDataParam->sProtection.bProtectionStatus = 0x00;
            break;
        default:
            bBadChoise = PH_ON;
            printf("%s\n",cTryAgain);
            break;
        }

    if (!bBadChoise)
        {
        /* set the protection pointer address, where is the border between the page L and page H */
        pDataParam->sProtection.bProtectionPointer = 0x0A;  // this address is only example
        status = ProtectPage_Slix2(pDataParam);

        if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
            {
            printf("OK - The page has been protected\n");
            }
        else if(status == ERROR_SLI_UNSUPPORTED_COMMAND)
            {
            printf("ERROR - Protect Page command is not supported by chosen tag\n");
            status = PH_ERR_SUCCESS;
            }
        else
            {
            /* status is returned at the end of the function */
            printf("ERROR - Protect Page\n");
            status = PH_ERR_SUCCESS;
            }
        }

    return status;
    }

/*==============================================================================================
 * FUNCTION:	StayQuietPersistent_SLI
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t StayQuietPersistent_SLI(parameters_sli_t *pDataParam)
    {
    phStatus_t    status = PH_ERR_SUCCESS;

    status = StayQuietPersistent_Slix2(pDataParam);

    if(status == PH_ERR_SUCCESS)
        {
        printf("Request transfered successfully\n");
        }
    else if(status == ERROR_SLI_UNSUPPORTED_COMMAND)
        {
        printf("ERROR - Stay Quiet Persistent command is not supported by chosen tag\n");
        status = PH_ERR_SUCCESS;
        }
    else
        {
        printf("ERROR - Stay Quite Persistent\n");
        status = PH_ERR_SUCCESS;
        }


    return status;
    }

#endif // NXPBUILD_SLIX_2_TAG

#endif // NXPBUILD_SLI_TAG

/* ---------------------------------------------------------------------------------------------
 *   End of File
 ---------------------------------------------------------------------------------------------*/


