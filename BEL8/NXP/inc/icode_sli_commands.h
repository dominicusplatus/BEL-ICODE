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
 * IcodeILT.h
 *
 *  Created on: 15.4.2015
 *      Author: nxp53811
 */

#ifndef ICODE_SLI_COMMANDS_H
#define ICODE_SLI_COMMANDS_H


/*----------------------------------------------------------------------------------------------
 * Includes
----------------------------------------------------------------------------------------------*/
#include <icode_common.h>

/* HAL Headers */
#include <phhalHw.h>
#include <ph_Status.h>

/* PAL Headers */
#include <phpalSli15693.h>

/*AL Headers*/
#include <phalI15693.h>
#include <phalSli.h>

/*Platform Headers*/
#include <phPlatform.h>

#ifdef NXPBUILD_SLI_TAG

/*----------------------------------------------------------------------------------------------
 * Global macros and definitions
----------------------------------------------------------------------------------------------*/
#define MAX_NUM_DETECTED_SLI_TAGS		4

/* SLI constants */
#define UID_15693_BYTE_LENGTH			8
#define SLI_BLOCK_SIZE					4
#define ACCESS_PASWORD_LENGTH			4

/* 15693 Response error code definition */
#define ERROR_CODE_15693_UNSUPPORTED_COMMAND	0x01	/* The command is not supported, i.e. the request code is not recognized. */
#define ERROR_CODE_15693_UNKNOWN_ERROR			0x0F	/* Unknown error. */

/* SLIX2 bit masks */
#define LOCK_BIT_AFI_MASK			0x01
#define LOCK_BIT_EAS_MASK			0x02
#define LOCK_BIT_DSFID_MASK                     0x04
#define LOCK_BIT_PPL_MASK			               0x08

#define PAGE_L_READ_PASSWORD_PROTECTION_STATUS_MASK      0x01
#define PAGE_L_WRITE_PASSWORD_PROTECTION_STATUS_MASK     0x02
#define PAGE_H_READ_PASSWORD_PROTECTION_STATUS_MASK      0x10
#define PAGE_H_WRITE_PASSWORD_PROTECTION_STATUS_MASK     0x20

/* error codes of SLI command module */
#define ERROR_SLI_UNSUPPORTED_COMMAND           		 PH_ERR_CUSTOM_BEGIN + 0
#define ERROR_SLI_OVERFLOW_NUMBER_OF_DETECTED_TAGS		 PH_ERR_CUSTOM_BEGIN + 1


typedef enum eSliType_e
    {
    Sli,	/* 00b */
    Slix2,	/* 01b */
    Slix,	/* 10b */
    Sli_RFU	/* RFU */
    } eSliType;

typedef struct sli_tag_identifiers
    {
    uint8_t 	UID[UID_15693_BYTE_LENGTH];
    eSliType	tagType;			/* this parameter is determined by 36th and 37th bits of UID.
						     purpose is to provide info about sli type quickly
						     without necessity of masking UID*/
    } sli_tag_identifiers_t;

typedef struct sli_tag_helper
    {
    uint8_t    bTagsFound;
    } sli_tag_helper_t;

typedef struct sli_read_single_block
    {
    uint8_t		   bBlockNum;
    const uint8_t	bOption;
    uint8_t		   aReadBlockBuffer[SLI_BLOCK_SIZE];
    uint16_t		wRxLength;
    } sli_read_single_block_t;

typedef struct sli_write_single_block
    {
    uint8_t		   bBlockNum;
    const uint8_t	bOption;
    uint8_t		   aWriteBlockBuffer[SLI_BLOCK_SIZE];
    } sli_write_single_block_t;

typedef struct sli_read_multiple_blocks
    {
    const uint8_t	bOption;
    uint8_t       bFirstBlockNo;
    uint16_t      wNumOfBlocks;
    uint8_t       *pReadBuff;
    uint16_t      wRxLength;
    } sli_read_multiple_blocks_t;

typedef struct sli_detection_param
    {
    uint32_t   bTotalTagsFound;
    uint8_t    bFastInventoryRead;
    uint8_t    aUIDMask[UID_15693_BYTE_LENGTH];
    } sli_detection_param_t;

typedef struct sli_access_param
    {
    uint8_t    bPwdIdentifier;
    uint8_t    aPassword[ACCESS_PASWORD_LENGTH];
    uint8_t    aPassword_Old[ACCESS_PASWORD_LENGTH];

    uint8_t    bAddressModeOnOff;
    } sli_access_param_t;

typedef struct sli_get_nxp_system_info
    {
    uint8_t    bProtectionPointer;        /**< [Out] Protection pointer address; 8 bits. */
    uint8_t    bProtectionCondition;      /**< [Out] Protection conditions for the password protection; 8 bits. */
    uint8_t    bLockBits;                 /**< [Out] Lock bits settings; 8 bits. */
    uint8_t    aFeatureFlags[8];          /**< [Out] Supported commands and features; 32 bits (+) additional  32 bits if EXT flag is set. */
    } sli_get_nxp_system_info_t;

typedef struct sli_protection
    {
    uint8_t    bProtectionPointer;        /**< [In] Page number - Protection pointer address, 8 bits. */
    uint8_t    bProtectionStatus;         /**< [In] New protection status; Refer to the PHAL_SLI_PROTECTION_* definitions. */
    } sli_protection_t;


typedef struct sli_reset_to_ready_loop
    {
    uint8_t    bResetLoopDuration;        /**< [In] Specifies how many seconds will the ResetToReadyAllTagsLoop_15693() function broadcast.
						  For this purpose there is used one timer provided by OSAL. */
    } sli_reset_to_ready_loop_t;

typedef struct parameters_sli
    {
    sli_detection_param_t              sDetectionParam;
    sli_access_param_t                 sAccessParam;
    sli_tag_identifiers_t              pIdentifier[MAX_NUM_DETECTED_SLI_TAGS];

    sli_read_single_block_t            sReadSingleBlock;
    sli_write_single_block_t           sWriteSingleBlock;
    sli_read_multiple_blocks_t	       sReadMultipleBlocks;
    sli_get_nxp_system_info_t          sGetNxpSystemInfo;
    sli_protection_t                   sProtection;
    sli_reset_to_ready_loop_t	       sResetToReadyLoop;

    phhalHw_Rc663_DataParams_t         *pHal;            // HAL component
    phpalSli15693_Sw_DataParams_t      *pPal;            // PAL 15693 component
    phalI15693_Sw_DataParams_t         *pAl;             // AL 15693 component
    phalSli_Sw_DataParams_t	           *pAlSli;	         // AL SLI
    void			                   *pPlatform;           // Platform component

    } parameters_sli_t;

/*----------------------------------------------------------------------------------------------
 * Global variables
----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------
 * Global function prototypes
----------------------------------------------------------------------------------------------*/
extern phStatus_t InventoryPopullation_15693(parameters_sli_t *pDataParams);
extern phStatus_t ReadSingleBlock_15693(parameters_sli_t *pDataParams);
extern phStatus_t WriteSingleBlock_15693(parameters_sli_t *pDataParams);
extern phStatus_t ReadMultipleBlocks_15693(parameters_sli_t *pDataParams);
extern phStatus_t StayQuiet_15693(parameters_sli_t *pDataParam);
extern phStatus_t ResetToReady_15693(parameters_sli_t *pDataParams);
extern phStatus_t ResetToReadyAddressed_15693(parameters_sli_t *pDataParams);
extern phStatus_t ResetToReadyAllTags_15693(parameters_sli_t *pDataParams);
extern phStatus_t ResetToReadyAllTagsLoop_15693(parameters_sli_t *pDataParams);

#ifdef NXPBUILD_SLIX_2_TAG
	extern phStatus_t FastInventoryPopullation_15693(parameters_sli_t *pDataParams);
    extern phStatus_t GetNXPSystemInformation_Slix2(parameters_sli_t *pDataParams);
    extern phStatus_t GetRandomNumberSetPWD_Slix2(parameters_sli_t *pDataParams);
    extern phStatus_t WritePassword_Slix2(parameters_sli_t *pDataParams);
    extern phStatus_t LockPassword_Slix2(parameters_sli_t *pDataParams);
    extern phStatus_t ProtectPage_Slix2(parameters_sli_t *pDataParams);
    extern phStatus_t StayQuietPersistent_Slix2(parameters_sli_t *pDataParam);
#endif // NXPBUILD_SLIX_2_TAG

/*----------------------------------------------------------------------------------------------
 * Private function prototypes
----------------------------------------------------------------------------------------------*/
#endif // NXPBUILD_SLI_TAG

#endif // ICODE_SLI_COMMANDS_H
/*----------------------------------------------------------------------------------------------
 * End of file
----------------------------------------------------------------------------------------------*/
