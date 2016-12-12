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

#ifndef ICODE_ILT_COMMANDS_H
#define ICODE_ILT_COMMANDS_H


/*----------------------------------------------------------------------------------------------
 * Includes
----------------------------------------------------------------------------------------------*/
#include <icode_common.h>

/* HAL Headers */
#include <phhalHw.h>

/* PAL Headers */
#include <phpalI18000p3m3.h>

/*AL Headers*/
#include <phalI18000p3m3.h>

#ifdef NXPBUILD_ILT_TAG

/*----------------------------------------------------------------------------------------------
 * Global macros and definitions
----------------------------------------------------------------------------------------------*/
#define  SIMPLE_INVENTORY_RANGE                 0
#define  ACCESS_MASK_LEN                        2
#define  STORED_CRC_BUFFER_LEN                  2
#define  STORED_UII_BUFFER_LEN                  20
#define  DATA_BUFF_LEN                          20
#define  ACTIVATE_CARD_WITHOUT_MASK             0

/* list of the ERROR message */
#define  ERROR_CARD_ACTIVATE                    0x0001
#define  ERROR_REQUEST_RN                       0x0002
#define  ERROR_READ                             0x0003
#define  ERROR_WRITE_UNKNOWN                    0x0004
#define  ERROR_WRITE_PASSWORD_UNKNOWN           0x0005
#define  ERROR_LOCK_UNKNOWN                     0x0006
#define  ERROR_LOCK_ON_NOT_ACCESSED				0x0007
#define  ERROR_ACCESS_UNKNOWN                   0x0008
#define  ERROR_ACCESS_PASSWOD                   0x0009
#define  ERROR_ILT_OVERFLOW_NUMBER_OF_DETECTED_TAGS 0x000A

#define  LENGTH_BYTE                            8
#define  LENGTH_WORD                            16
#define  WORD_PTR_LEN                           4

#define  MAX_NUM_DETECTED_ITL_TAGS              1


#define  I18000P3M3_MEM_STARTING_ADDRESS        0
#define  I18000P3M3_MEM_ACCESS_PASSWORD_ADDRESS 2
#define  ACCESS_PASSWORD_MEMORY_LENGTH          2
#define  WHOLE_MEMORY_BANK                      0
#define  MAX_NUM_OF_ROUNDS                      0x0F
#define  USER_ID_START_ADDRESS                  0x02
#define  USER_ID_MASK_NUMBER_OF_BYTES           6*2 // number of UII words is 6, words*2 = length of the field
#define  USER_ID_MASK_LENGTH_IN_BITS            USER_ID_MASK_NUMBER_OF_BYTES * 8     // 2 last words of UII field - not of UII memory bank

#define  WORD_POINTER_LENGTH_8_BIT              0
#define  WORD_POINTER_LENGTH_16_BIT             1
#define  WORD_POINTER_LENGTH_24_BIT             2
#define  WORD_POINTER_LENGTH_32_BIT             3

#define  LOCK_NO_ACTION                         0x00

#define  LOCK_MASK_KILL_PWD_READ_WRITE          0x80
#define  LOCK_MASK_KILL_PWD_PERMALOCK           0x40
#define  LOCK_ACTION_KILL_PWD_READ_WRITE        0x80
#define  LOCK_ACTION_KILL_PWD_PERMALOCK         0x40

#define  LOCK_MASK_ACCESS_PWD_READ_WRITE        0x20
#define  LOCK_MASK_ACCESS_PWD_PERMALOCK         0x10
#define  LOCK_ACTION_ACCESS_PWD_READ_WRITE      0x20
#define  LOCK_ACTION_ACCESS_PWD_PERMALOCK       0x10

#define  LOCK_MASK_UII_MEM_WRITE                0x08
#define  LOCK_MASK_UII_MEM_PERMALOCK            0x04
#define  LOCK_ACTION_UII_MEM_WRITE              0x08
#define  LOCK_ACTION_UII_MEM_PERMALOCK          0x04

#define  LOCK_MASK_TID_MEM_WRITE                0x02
#define  LOCK_MASK_TID_MEM_PERMALOCK            0x01
#define  LOCK_ACTION_TID_MEM_WRITE              0x02
#define  LOCK_ACTION_TID_MEM_PERMALOCK          0x01

#define  LOCK_MASK_USER_MEM_WRITE               0x80
#define  LOCK_MASK_USER_MEM_PERMALOCK           0x40
#define  LOCK_ACTION_USER_MEM_WRITE             0x80
#define  LOCK_ACTION_USER_MEM_PERMALOCK         0x40

typedef struct ilt_access
    {
    uint32_t   dwAccessLockOnOff;                  /* access password change is (un)locked for writing */
    uint8_t    pMask[ACCESS_MASK_LEN];             /* 10bit Mask Field */
    uint8_t    pAction[ACCESS_MASK_LEN];           /* 10bit Action Field */
    uint8_t    pAccessPassword[WORD_PTR_LEN];      /* access password tag field 2x 16bit (words) */
    uint8_t    pUserAccessPassword[WORD_PTR_LEN];  /* access password entered by user - field 2x 16bit (words) */
    uint8_t    bSimpleTagDetectionOnOff;
    }ilt_access_t;

typedef struct ilt_tranfer
    {
    uint8_t    bCoverCoding;
    uint8_t    bBankMemory;
    uint8_t    pWordPtr[WORD_PTR_LEN];
    uint8_t    bWordPtrLen;
    uint8_t    bNumOfBytes;
    uint8_t    bWordCount;
    uint8_t    *pRxBuffer;
    uint16_t   wRxBitLength;
    uint8_t    pData[DATA_BUFF_LEN];               /* universal buffer for data transfer */
    }ilt_tranfer_t;

typedef struct tag_identifiers
    {
    uint8_t    StoredUII[STORED_UII_BUFFER_LEN];
    uint8_t    StoredCRC[STORED_CRC_BUFFER_LEN];
    uint8_t    bNumOfBytesXPC;
    } tag_identifiers_t;

typedef struct itl_detection_param
    {
    uint8_t    bTarget;
    uint8_t    bDivideRatio;
    uint8_t    bModulation;
    uint8_t    bMemoryBank;
    uint8_t    bTRext;
    uint8_t    bSelection;
    uint8_t    bSession;
    uint8_t    bNumRounds;             // this is the bQ parameter
    uint32_t   bTotalTagsFound;
    uint8_t    pBitPointer[WORD_PTR_LEN];
    uint8_t    bBitPointerLength;
    uint8_t    UIIMask[USER_ID_MASK_NUMBER_OF_BYTES];
    uint8_t    bMaskBitLength;
    uint8_t    bTruncate;
    uint8_t    StoredCRC[STORED_CRC_BUFFER_LEN];
    } itl_detection_param_t;

typedef struct parameters_itl
    {
    itl_detection_param_t              sDetectionParam;
    tag_identifiers_t                  pIdentifier[MAX_NUM_DETECTED_ITL_TAGS];
    ilt_access_t                       sAccess;
    ilt_tranfer_t                      sTransfer;
    phhalHw_Rc663_DataParams_t         *pHal;            // HAL component
    phpalI18000p3m3_Sw_DataParams_t    *pPal;            // PAL 18000p3m3 component
    phalI18000p3m3_Sw_DataParams_t     *pAl;             // AL 18000p3m3 component
    } parameters_itl_t;

/*----------------------------------------------------------------------------------------------
 * Global variables
----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------
 * Global function prototypes
----------------------------------------------------------------------------------------------*/
extern phStatus_t SimpleInventory_18000p3m3(parameters_itl_t *pDataParam);
extern phStatus_t Inventory_18000p3m3(parameters_itl_t *pDataParam);
extern phStatus_t Read_18000p3m3(parameters_itl_t *pDataParam);
extern phStatus_t Write_18000p3m3(parameters_itl_t *pDataParam);
extern phStatus_t Write_Password_18000p3m3(parameters_itl_t *pDataParam);
extern phStatus_t Lock_18000p3m3(parameters_itl_t *pDataParam);

#endif // NXPBUILD_ILT_TAG

#endif // ICODE_ILT_COMMANDS_H
/*----------------------------------------------------------------------------------------------
 * End of file
----------------------------------------------------------------------------------------------*/


