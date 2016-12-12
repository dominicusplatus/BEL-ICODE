/*
*         Copyright (c), NXP Semiconductors Bangalore / India
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

/** \file
* Generic Tag Operation Application Layer Component of Reader Library Framework.
* $Author: jenkins_cm (nxp92197) $
* $Revision: 3068 $ (NfcRdLib_A_Gate_Incremental_V3.092.04.001533 : 2936 )
* $Date: 2015-08-14 19:29:17 +0530 (Fri, 14 Aug 2015) $
*/

#ifndef PHALTOP_H
#define PHALTOP_H

#include <ph_Status.h>
#include <phacDiscLoop.h>
#include <phalT1T.h>
#include <phalMful.h>
#include <phalMfdf.h>
#define __DEBUG

#ifdef __cplusplus
extern "C" {
#endif    /* __cplusplus */


#ifdef NXPBUILD__PHAL_TOP_SW

/** \defgroup phalTop_Sw Component : Software
* @{
*/
#define PHAL_TOP_SW_ID                           0x01U       /**< ID for software tag operation layer */

#define PHAL_TOP_T1T_MAX_MEM_CTRL_TLV            0x01U        /**< Max Memory control TLV count for T1T */
#define PHAL_TOP_T1T_MAX_LOCK_CTRL_TLV           0x01U        /**< Max Lock control TLV count for T1T */
#define PHAL_TOP_T1T_MAX_PROPRIETARY_TLV         0x01U        /**< Max Proprietary TLV count for T1T */
#define PHAL_TOP_T1T_SEGMENT_SIZE                0x80U        /**< T1T Segment size */
#define PHAL_TOP_T1T_BLOCKS_PER_SEGMENT          0x10U        /**< Number of blocks per segment for T1T */
#define PHAL_TOP_T1T_NDEF_NMN                    0xE1U        /**< NDEF magic number for T1T */
#define PHAL_TOP_T1T_NDEF_SUPPORTED_VNO          0x10U        /**< Version Number for T1T */
#define PHAL_TOP_T1T_SEGMENT_END_INDEX           0x68U        /**< T1T Segment End for Tlv  */
#define PHAL_TOP_T1T_BLOCK_LOCK0                 0x70U        /**< T1T block for Lock 0 */
#define PHAL_TOP_T1T_BLOCK_LOCK1                 0x71U        /**< T1T block for Lock 1 */
#define PHAL_TOP_T1T_BLOCK_NMN                   0x08U        /**< T1T block for NDEF Magic Number */
#define PHAL_TOP_T1T_BLOCK_VNO                   0x09U        /**< T1T block for version no */
#define PHAL_TOP_T1T_BLOCK_TMS                   0x0AU        /**< T1T block for tag memory Size */
#define PHAL_TOP_T1T_BLOCK_RWA                   0x0BU        /**< T1T block for read/write Access  */
#define PHAL_TOP_T1T_SEGMENT_START_INDEX         0x0CU        /**< T1T Segment start for TLV */

#define PHAL_TOP_T2T_MAX_MEM_CTRL_TLV            0x01U        /**< Max Memory control TLV count for T2T */
#define PHAL_TOP_T2T_MAX_LOCK_CTRL_TLV           0x01U        /**< Max Lock control TLV count for T2T */
#define PHAL_TOP_T2T_MAX_PROPRIETARY_TLV         0x01U        /**< Max Proprietary TLV count for T2T */
#define PHAL_TOP_T2T_SECTOR_SIZE                 0x400U       /**< T2T sector size - 1024 bytes */
#define PHAL_TOP_T2T_NDEF_MAGIC_NUMBER           0xE1U        /**< NDEF Magical number for T2T */
#define PHAL_TOP_T2T_NDEF_SUPPORTED_VNO          0x10U        /**< Version number for T2T */

#define PHAL_TOP_T3T_BLOCK_SIZE                  0x10U        /**< Number of blocks per segment for T3T */
#define PHAL_TOP_T3T_WRITE_FLAG_ADDRESS          0x09U        /**< Write Flag Byte Location  in Attribute Information Block */
#define PHAL_TOP_T3T_NDEF_SUPPORTED_VNO1         0x10U        /**< Version Number 1 for T3T */
#define PHAL_TOP_T3T_NDEF_SUPPORTED_VNO2         0x11U        /**< Version Number 2 for T3T */

#define PHAL_TOP_T4T_NDEF_SUPPORTED_VNO1         0x10U        /**< Version Number 1 for T4T */
#define PHAL_TOP_T4T_NDEF_SUPPORTED_VNO2         0x20U        /**< Version Number 2 for T4T */

#define PHAL_TOP_T5T_NDEF_SUPPORTED_VNO          0x04U        /**< Version Number for T5T */
#define PHAL_TOP_T5T_NDEF_MAGIC_NUMBER           0xE1U        /**< NDEF Magical Number for T5T for 1-Byte Addressed Commands */
#define PHAL_TOP_T5T_NDEF_MAGIC_NUMBER_2         0xE2U        /**< NDEF Magical Number for T5T for 2-Byte Addressed Commands */

/** \name phalTop Custom Error Codes
*/
/** @{ */
#define PHAL_TOP_ERR_NO_VALID_NDEF_ON_TAG          (PH_ERR_CUSTOM_BEGIN + 0x00)     /**< No valid NDEF Message on tag */
#define PHAL_TOP_ERR_READONLY_TAG                  (PH_ERR_CUSTOM_BEGIN + 0x01)     /**< Tag is Read Only */
#define PHAL_TOP_ERR_INVALID_TAG                   (PH_ERR_CUSTOM_BEGIN + 0x02)     /**< Tag is not NDEF Compatible. */
#define PHAL_TOP_ERR_NOT_FORMATTED                 (PH_ERR_CUSTOM_BEGIN + 0x03)     /**< Tag Not Formatted. */
#define PHAL_TOP_ERR_INVALID_STATE                 (PH_ERR_CUSTOM_BEGIN + 0x04)     /**< Tag state is invalid */
#define PHAL_TOP_ERR_UNSUPPORTED_TAG               (PH_ERR_CUSTOM_BEGIN + 0x05)     /**< Tag with unsupported structure. */
#define PHAL_TOP_ERR_ALREADY_FORMATTED_TAG         (PH_ERR_CUSTOM_BEGIN + 0x06)     /**< Tag already in formatted state. */
#define PHAL_TOP_T4T_ERR_INVALID_LENGTH            (PH_ERR_CUSTOM_BEGIN + 0x43)     /**< T4T tag is Read Only */
#define PHAL_TOP_T5T_ERR_INVALID_PARAM             (PH_ERR_CUSTOM_BEGIN + 0x0B)     /**< T5T tag has invalid Dataparam. */
/** @} */

#ifdef NXPBUILD__PHAL_T1T_SW
/**
* \brief T1T Lock Control TLV parameter structure
*/
typedef struct phalTop_T1T_LockCtrlTlv
{
    uint16_t wOffset;                                             /**< TLV offset */
    uint16_t wByteAddr;                                           /**< Lock bytes start address/offset */
    uint8_t bSizeInBits;                                          /**< Lock bytes size in bits */
    uint8_t bBytesLockedPerBit;                                   /**< Number of bytes locked per lock bit */
}phalTop_T1T_LockCtrlTlv_t;

/**
* \brief T1T Memory Control TLV parameter structure
*/
typedef struct phalTop_T1T_MemCtrlTlv
{
    uint16_t wOffset;                                             /**< TLV offset */
    uint16_t wByteAddr;                                           /**< Reserved memory start address/offset */
    uint8_t bSizeInBytes;                                         /**< Reserved memory size in bytes */
}phalTop_T1T_MemCtrlTlv_t;

/**
* \brief T1T Proprietary TLV parameter structure
*/
typedef struct phalTop_T1T_ProprietaryTlv
{
    uint16_t wOffset;                                             /**< TLV address/offset */
    uint16_t wLength;                                             /**< TLV Length */
}phalTop_T1T_ProprietaryTlv_t;

/**
* \brief T1T Segment parameters
*/
typedef struct phalTop_TIT_Segment
{
    uint8_t bAddress;                                             /**< Current active segment address */
    uint8_t bBlockAddress;                                        /**< Current active block address */
    uint8_t bLockReservedOtp[PHAL_TOP_T1T_BLOCKS_PER_SEGMENT];    /**< Lock/reserved/OTP bytes in current segment */
    uint8_t bValidity;                                            /**< Read data validity */
}phalTop_TIT_Segment_t;
#endif /* NXPBUILD__PHAL_T1T_SW */

#ifdef NXPBUILD__PHAL_MFUL_SW
/**
* \brief T2T Lock Control TLV parameter structure
*/
typedef struct phalTop_T2T_LockCtrlTlv
{
    uint16_t wOffset;                                             /**< TLV offset */
    uint16_t wByteAddr;                                           /**< Lock bytes start address/offset */
    uint8_t bSizeInBits;                                          /**< Lock bytes size in bits */
    uint8_t bBytesLockedPerBit;                                   /**< Number of bytes locked per lock bit */
}phalTop_T2T_LockCtrlTlv_t;

/**
* \brief T2T Memory Control TLV parameter structure
*/
typedef struct phalTop_T2T_MemCtrlTlv
{
    uint16_t wOffset;                                             /**< TLV offset */
    uint16_t wByteAddr;                                           /**< Reserved memory start address/offset */
    uint8_t bSizeInBytes;                                         /**< Reserved memory size in bytes */
}phalTop_T2T_MemCtrlTlv_t;

/**
* \brief T2T Proprietary TLV parameter structure
*/
typedef struct phalTop_T2T_ProprietaryTlv
{
    uint16_t wOffset;                                             /**< TLV address/offset */
    uint16_t wLength;                                             /**< TLV Length */
}phalTop_T2T_ProprietaryTlv_t;

/**
* \brief T2T Sector parameters
*/
typedef struct phalTop_T2T_Sector
{
    uint8_t bAddress;                                            /**< Current active Sector address */
    uint8_t bBlockAddress;                                       /**< Current active block address */
    uint8_t bLockReservedOtp[32];                                /**< Lock/reserved/OTP bytes in current Sector */
    uint8_t bValidity;                                           /**< Read data validity */
}phalTop_T2T_Sector_t;
#endif /* NXPBUILD__PHAL_MFUL_SW */

#ifdef NXPBUILD__PHAL_T1T_SW
/**
* \brief T1T parameter structure
*/
typedef struct phalTop_T1T
{
    void * pAlT1TDataParams;                                                   /**< Pointer to T1T data parameters */
    uint8_t bNdefFormatted;                                                     /**< Tag is NDEF formated or not; 1 - formatted, 0 - not formatted */
    uint8_t bNdefPresence;                                                      /**< NDEF message presence in tag; 1 - present, 0 - not present */
    uint8_t bVno;                                                               /**< NDEF version number */
    uint8_t bTagState;                                                          /**< T1T tag state */
    uint8_t bNdefSupport;                                                       /**< NDEF support by T1T tag; 1 - supported, 0 - not supported */
    uint8_t bRwa;                                                               /**< Tag read/write size */
    uint8_t bTms;                                                               /**< Tag Memory size */
    uint8_t bTagMemoryType;                                                     /**< Tag memory type (static or dynamic) */
    uint8_t bTerminatorTlvPresence;                                             /**< Terminator TLV presence; 1 -present, 0 - not present */
    uint8_t bLockTlvCount;                                                      /**< Number of lock TLV present in tag */
    uint8_t bMemoryTlvCount;                                                    /**< Number of memory TLV present in tag */
    uint8_t bProprietaryTlvCount;                                               /**< Number of proprietary TLV present in tag */
    uint16_t wNdefHeaderAddr;                                                   /**< Header offset of first NDEF message */
    uint16_t wNdefMsgAddr;                                                      /**< NDEF message start address */
    uint16_t wNdefLength;                                                       /**< NDEF message length */
    uint16_t wMaxNdefLength;                                                    /**< Max. supported NDEF length */
    uint8_t bUid[4];                                                            /**< T1T UID */
    phalTop_T1T_MemCtrlTlv_t asMemCtrlTlv[PHAL_TOP_T1T_MAX_MEM_CTRL_TLV];       /**< Memory TLV details for each TLV present */
    phalTop_T1T_LockCtrlTlv_t asLockCtrlTlv[PHAL_TOP_T1T_MAX_LOCK_CTRL_TLV];    /**< Lock TLV details for each TLV present */
    phalTop_T1T_ProprietaryTlv_t asPropTlv[PHAL_TOP_T1T_MAX_PROPRIETARY_TLV];   /**< Proprietary TLV details for each TLV present */
    phalTop_TIT_Segment_t sSegment;                                             /**< Current segment details */
}phalTop_T1T_t;
#endif /* NXPBUILD__PHAL_T1T_SW */

#ifdef NXPBUILD__PHAL_MFUL_SW
/**
* \brief T2T parameter structure
*/
typedef struct phalTop_T2T
{
    void * pAlT2TDataParams;                                                    /**< Pointer to T2T data parameters */
    uint8_t bNdefFormatted;                                                      /**< Tag is NDEF formated or not; 1 - formatted, 0 - not formatted */
    uint8_t bNdefPresence;                                                       /**< NDEF message presence in tag; 1 - present, 0 - not present */
    uint8_t bVno;                                                                /**< NDEF version number */
    uint8_t bTagState;                                                           /**< T2T tag state */
    uint8_t bNdefSupport;                                                        /**< Used for padding */
    uint8_t bRwa;                                                                /**< Tag read/write size */
    uint8_t bTms;                                                                /**< Tag Memory size */
    uint8_t bTagMemoryType;                                                      /**< Tag memory type (static or dynamic) */
    uint8_t bTerminatorTlvPresence;                                              /**< Terminator TLV presence; 1 -present, 0 - not present */
    uint8_t bLockTlvCount;                                                       /**< Number of lock TLV present in tag */
    uint8_t bMemoryTlvCount;                                                     /**< Number of memory TLV present in tag */
    uint8_t bEraseProprietaryTlv;                                                /**< Erase proprietary TLV during write; 1 - erase, 0 - don't erase */
    uint16_t wNdefHeaderAddr;                                                    /**< Header offset of first NDEF message */
    uint16_t wNdefMsgAddr;                                                       /**< NDEF message start address */
    uint16_t wNdefLength;                                                        /**< NDEF message length */
    uint16_t wMaxNdefLength;                                                     /**< Max. supported NDEF length */
    uint8_t bProprietaryTlvCount;                                                /**< Number of proprietary TLV present in tag */
    phalTop_T2T_MemCtrlTlv_t asMemCtrlTlv[PHAL_TOP_T2T_MAX_MEM_CTRL_TLV];        /**< Memory TLV details for each TLV present */
    phalTop_T2T_LockCtrlTlv_t asLockCtrlTlv[PHAL_TOP_T2T_MAX_LOCK_CTRL_TLV];     /**< Lock TLV details for each TLV present */
    phalTop_T2T_ProprietaryTlv_t asPropTlv[PHAL_TOP_T2T_MAX_PROPRIETARY_TLV];    /**< Proprietary TLV details for each TLV present */
    phalTop_T2T_Sector_t sSector;                                                /**< Current segment details */
}phalTop_T2T_t;
#endif /* NXPBUILD__PHAL_MFUL_SW */

#ifdef NXPBUILD__PHAL_FELICA_SW
/**
* \brief T3T parameter structure
*/
typedef struct phalTop_T3T
{
    void * pAlT3TDataParams;                                                     /**< Pointer to Felica data parameters */
    uint8_t bNdefFormatted;                                                      /**< Tag is NDEF formated or not; 1 - formatted, 0 - not formatted */
    uint8_t bNdefPresence;                                                       /**< NDEF message presence in tag; 1 - present, 0 - not present */
    uint8_t bVno;                                                                /**< NDEF version number */
    uint8_t bTagState;                                                           /**< T3T tag state */
    uint8_t bNdefSupport;                                                        /**< NDEF support by T3T tag; 1 - supported, 0 - not supported */
    uint8_t bRwa;                                                                /**< Tag read/write access; 1 - Read/Write, 0 - Read Only */
    uint8_t bNbr;                                                                /**< Number of Blocks that can be read at one time*/
    uint8_t bNbw;                                                                /**< Number of Blocks that can be written at one time*/
    uint16_t bNmaxb;                                                             /**< Maximum number of 'Blocks * 16' available for NDEF data */
    uint32_t wNdefLength;                                                        /**< NDEF message length */
    uint8_t bUid[16];                                                            /**< UID to address T3T */
}phalTop_T3T_t;
#endif /* NXPBUILD__PHAL_FELICA_SW */

#ifdef NXPBUILD__PHAL_MFDF_SW
/**
* \brief T4T parameter structure
*/
typedef struct phalTop_T4T
{
    void * pAlT4TDataParams;                                                     /**< Pointer to T4T data parameters */
    uint8_t bNdefFormatted;                                                      /**< Tag is NDEF formated or not; 1 - formatted, 0 - not formatted */
    uint8_t bNdefPresence;                                                       /**< NDEF message presence in tag; true - present,false - not present */
    uint8_t bVno;                                                                /**< Mapping version number. */
    uint8_t bTagState;                                                           /**< T4T tag state */
    uint8_t bNdefSupport;                                                        /**< NDEF support by T1T tag; 1 - supported, 0 - not supported */
    uint8_t bNdef_FileID[2];                                                     /**< NDEF file ID to Create */
    uint8_t bRa;                                                                 /**< NDEF file read access condition size */
    uint8_t bWa;                                                                 /**< NDEF file write access condition size */
    uint16_t wCCLEN;                                                             /**< Size of CC. Valid CCLEN range 000Fh-FFFEh.*/
    uint16_t bMaxFileSize;                                                       /**< Maximum NDEF file size in bytes */
    uint16_t wNLEN;                                                              /**< Size of the NDEF message stored in the NDEF file. */
}phalTop_T4T_t;
#endif /* NXPBUILD__PHAL_MFDF_SW */

#ifdef NXPBUILD__PHAL_I15693_SW
/**
* \brief T5T parameter structure
*/
typedef struct phalTop_T5T
{
    void *  pAlI15693DataParams;                                                 /**< Pointer to T5T data parameters */
    uint8_t bNdefPresence;                                                       /**< NDEF message presence in tag; 1 - present, 0 - not present */
    uint8_t bVno;                                                                /**< NDEF version number */
    uint8_t bRwa;                                                                /**< Tag read/write size */
    uint8_t bTerminatorTlvPresence;                                              /**< Terminator TLV presence; 1 -present, 0 - not present */
    uint8_t bNdefFormatted;                                                      /**< Tag is NDEF formated or not; 1 - formatted, 0 - not formatted */
    uint8_t bTagState;                                                           /**< T5T tag state */
    uint8_t bMbRead;                                                             /**< Flag bit for multiple read support */
    uint8_t bLockBlock;                                                          /**< Flag bit for Lock command support */
    uint8_t bSplFrm;                                                             /**< Flag bit for special frame support */
    uint8_t bExtendedCommandSupport;                                             /**< Flag bit for extended memory access command support */
    uint8_t bEraseProprietaryTlv;                                                /**< Erase proprietary TLV during write; 1 - erase, 0 - don't erase */
    uint8_t bOptionFlag;                                                         /**< Option Flag PH_ON = Enable, PH_OFF = Disable */
    uint16_t wMlen;                                                              /**< Tag Memory size */
    uint16_t wNdefHeaderAddr;                                                    /**< Header offset of first NDEF message */
    uint16_t wNdefMsgAddr;                                                       /**< NDEF message start address */
    uint16_t wNdefLength;                                                        /**< NDEF message length */
    uint16_t wMaxNdefLength;                                                     /**< Max. supported NDEF length */
    uint16_t bBlockSize;                                                         /**< T5T block size supported by card */
    uint16_t bMaxBlockNum;                                                       /**< Maximum block number supported by Card */
}phalTop_T5T_t;
#endif /* NXPBUILD__PHAL_I15693_SW */

/**
* \brief Tag Operations parameter structure
*/
typedef struct  phalTop_Sw_DataParams
{
    uint16_t wId;                                 /**< Layer ID for this component, NEVER MODIFY! */
    uint8_t bTagType;                             /**< Tag type */
    void * pT1T;                                  /**< Pointer to T1T parameter structure */
    void * pT2T;                                  /**< Pointer to T2T parameter structure */
    void * pT3T;                                  /**< Pointer to T3T parameter structure */
    void * pT4T;                                  /**< Pointer to T4T parameter structure */
    void * pT5T;                                  /**< RFU : Pointer to T5T parameter structure */
}phalTop_Sw_DataParams_t;

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on error type
*/
phStatus_t phalTop_Sw_Init(
    phalTop_Sw_DataParams_t * pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    uint16_t wSizeOfDataParams,                   /**< [In] Specifies the size of the data parameter structure. */
    void * pTopT1T,                               /**< [In] Pointer to T1T parameter structure. */
    void * pTopT2T,                               /**< [In] Pointer to T2T parameter structure. */
    void * pTopT3T,                               /**< [In] Pointer to T3T parameter structure. */
    void * pTopT4T,                               /**< [In] Pointer to T4T parameter structure. */
    void * pTopT5T                                /**< [In] RFU : Pointer to T5T parameter structure. */
    );
/** @} */
#endif /* NXPBUILD__PHAL_TOP_SW */

#ifdef NXPBUILD__PHAL_TOP

/** \defgroup phalTop Tag Operation Layer
* \brief This component implements NFC tag operations for different NFC tag types T1T, T2T, T3T, T4T and T5T.
* To perform any operation like Read, Write, Lock, Format and Erase on the tag, the tag should be
* activated first as shown in the below block diagram. Any read/write operation is possible on the tag only
* if the tag is in NDEF format. Refer NFC Forum tag operation specifications.
*
* \image html TOP_BlockDiagram.png
*
* @{
*/
/**
* \name Tag types
* \brief Tag types are used to set tag type through \ref phalTop_SetConfig with \ref PHAL_TOP_CONFIG_TAG_TYPE type
*/
/*@{*/
#define PHAL_TOP_TAG_TYPE_T1T_TAG                   0x01U                /**< Type 1 tag. */
#define PHAL_TOP_TAG_TYPE_T2T_TAG                   0x02U                /**< Type 2 tag. */
#define PHAL_TOP_TAG_TYPE_T3T_TAG                   0x03U                /**< Type 3 tag. */
#define PHAL_TOP_TAG_TYPE_T4T_TAG                   0x04U                /**< Type 4 tag. */
#define PHAL_TOP_TAG_TYPE_T5T_TAG                   0x05U                /**< Type 5 tag. */
/*@}*/

/**
* \name Configuration types
* \brief Use these macros in \ref phalTop_SetConfig to configure tags before calling \ref phalTop_FormatNdef, \ref phalTop_WriteNdef etc.
*/
/*@{*/
#define PHAL_TOP_CONFIG_TAG_TYPE                    0x00U                /**< Set/Get tag type. Should be configured before calling any API. */
#define PHAL_TOP_CONFIG_TAG_FORMATTABLE             0x01U                /**< Get T1T tag format-able or not. */

#define PHAL_TOP_CONFIG_T1T_NDEF_VNO                0x02U                /**< Set/Get T1T NDEF version number. Set before format operation. */
#define PHAL_TOP_CONFIG_T1T_TMS                     0x03U                /**< Set/Get tag memory size. Set before format operation. */
#define PHAL_TOP_CONFIG_T1T_RW_ACCESS               0x04U                /**< Set/Get tag R/W access. */
#define PHAL_TOP_CONFIG_T1T_TERMINATOR_TLV          0x05U                /**< Set/Get Terminator TLV presence. */
#define PHAL_TOP_CONFIG_T1T_MAX_NDEF_LENGTH         0x06U                /**< Get max NDEF length. */
#define PHAL_TOP_CONFIG_T1T_GET_TAG_STATE           0x07U                /**< Get T1T state. */

#define PHAL_TOP_CONFIG_T2T_NDEF_VNO                0x08U                /**< Set/Get T2T NDEF version number. Set before format operation. */
#define PHAL_TOP_CONFIG_T2T_TMS                     0x09U                /**< Set/Get tag memory size. Set before format operation.*/
#define PHAL_TOP_CONFIG_T2T_RW_ACCESS               0x0AU                /**< Set/Get tag R/W access. */
#define PHAL_TOP_CONFIG_T2T_TERMINATOR_TLV          0x0BU                /**< Set/Get Terminator TLV presence. */
#define PHAL_TOP_CONFIG_T2T_PROPRIETARY_TLV         0x0CU                /**< Set/Get Proprietary TLV erase. */
#define PHAL_TOP_CONFIG_T2T_MAX_NDEF_LENGTH         0x0DU                /**< Get Max NDEF Length. */
#define PHAL_TOP_CONFIG_T2T_GET_TAG_STATE           0x0EU                /**< Get T2T state. */

#define PHAL_TOP_CONFIG_T3T_NDEF_VNO                0x0FU                /**< Set/Get T3T NDEF version number. Set before format operation. */
#define PHAL_TOP_CONFIG_T3T_NBR                     0x10U                /**< Set/Get T3T NBR(Number of blocks read Simultaneously). Set before format operation. */
#define PHAL_TOP_CONFIG_T3T_NBW                     0x11U                /**< Set/Get T3T NBW(Number of blocks write Simultaneously). Set before format operation. */
#define PHAL_TOP_CONFIG_T3T_MAX_NDEF_LENGTH         0x12U                /**< Set/Get T3T Max NDEF length - Nmaxb (Maximum NDEF data supported by tag). Set before format operation. */
#define PHAL_TOP_CONFIG_T3T_RW_ACCESS               0x13U                /**< Get T3T tag R/W access. */
#define PHAL_TOP_CONFIG_T3T_GET_TAG_STATE           0x14U                /**< Get T3T state. */

#define PHAL_TOP_CONFIG_T4T_NDEF_FILE_ID            0x15U                /**< Set NDEF file ID. Set before format operation. */
#define PHAL_TOP_CONFIG_T4T_NDEF_VNO                0x16U                /**< Set/Get T4T NDEF version number. Set before format operation. */
#define PHAL_TOP_CONFIG_T4T_WRITE_ACCESS            0x17U                /**< Set/Get tag-write access. Set before format operation. */
#define PHAL_TOP_CONFIG_T4T_MAX_NDEF_FILE_SIZE      0x18U                /**< Set/Get Max NDEF length. Set before format operation. */
#define PHAL_TOP_CONFIG_T4T_READ_ACCESS             0x19U                /**< Get tag Read access. */
#define PHAL_TOP_CONFIG_T4T_GET_TAG_STATE           0x1AU                /**< Get T4T state. */
#define PHAL_TOP_CONFIG_T4T_NLEN                    0x1BU                /**< Get NDEF Length. */

#define PHAL_TOP_CONFIG_T5T_NDEF_VNO                0x1CU                /**< Set/Get T5T NDEF version number. Set before format operation. */
#define PHAL_TOP_CONFIG_T5T_MLEN                    0x1DU                /**< Set/Get T5T NDEF data area */
#define PHAL_TOP_CONFIG_T5T_RW_ACCESS               0x1EU                /**< Set/Get tag write access. Set before format operation. */
#define PHAL_TOP_CONFIG_T5T_TERMINATOR_TLV          0x1FU                /**< Set/Get Terminator-TLV presence. */
#define PHAL_TOP_CONFIG_T5T_MBREAD                  0x20U                /**< Set/Get T5T multi-block read support */
#define PHAL_TOP_CONFIG_T5T_LOCKBLOCK               0x21U                /**< Set/Get T5T Lock block command support */
#define PHAL_TOP_CONFIG_T5T_SPL_FRM                 0x22U                /**< Set/Get T5T special frame support */
#define PHAL_TOP_CONFIG_T5T_GET_TAG_STATE           0x23U                /**< Set/Get T5T tag state */
#define PHAL_TOP_CONFIG_T5T_MAX_NDEF_LENGTH         0x24U                /**< Get Max NDEF length. */
#define PHAL_TOP_CONFIG_T5T_PROPRIETARY_TLV         0x25U                /**< Set/Get T5T proprietary TLV status */
#define PHAL_TOP_CONFIG_T5T_OPTIONAL_FLAG           0x26U                /**< Set/Get T5T option Flag */
/*@}*/

/**
* \name T1T TLV types
*/
/*@{*/
#define PHAL_TOP_T1T_NULL_TLV                       0x00U                /**< NULL TLV. */
#define PHAL_TOP_T1T_LOCK_CTRL_TLV                  0x01U                /**< Lock Control TLV. */
#define PHAL_TOP_T1T_MEMORY_CTRL_TLV                0x02U                /**< Memory Control TLV. */
#define PHAL_TOP_T1T_NDEF_TLV                       0x03U                /**< NDEF Message TLV. */
#define PHAL_TOP_T1T_PROPRIETARY_TLV                0xFDU                /**< Proprietary TLV. */
#define PHAL_TOP_T1T_TERMINATOR_TLV                 0xFEU                /**< Terminator TLV. */
/*@}*/

/**
* \name T2T TLV types
*/
/*@{*/
#define PHAL_TOP_T2T_NULL_TLV                       0x00U                /**< NULL TLV. */
#define PHAL_TOP_T2T_LOCK_CTRL_TLV                  0x01U                /**< Lock Control TLV. */
#define PHAL_TOP_T2T_MEMORY_CTRL_TLV                0x02U                /**< Memory Control TLV. */
#define PHAL_TOP_T2T_NDEF_TLV                       0x03U                /**< NDEF Message TLV. */
#define PHAL_TOP_T2T_PROPRIETARY_TLV                0xFDU                /**< Proprietary TLV. */
#define PHAL_TOP_T2T_TERMINATOR_TLV                 0xFEU                /**< Terminator TLV. */
/*@}*/

/**
* \name T4T TLV types
*/
/*@{*/
#define PHAL_TOP_T4T_NDEF_TLV                       0x04U                /**< NDEF Message TLV. */
#define PHAL_TOP_T4T_PROPRIETARY_TLV                0x05U                /**< Proprietary TLV. */
/*@}*/

/**
* \name T5T TLV types
*/
/*@{*/
#define PHAL_TOP_T5T_NDEF_TLV                       0x03U                /**< NDEF Message TLV. */
#define PHAL_TOP_T5T_PROPRIETARY_TLV                0xFDU                /**< Proprietary TLV. */
#define PHAL_TOP_T5T_TERMINATOR_TLV                 0xFEU                /**< Terminator TLV. */
/*@}*/

/**
* \name T1T Tag States
*/
/*@{*/
#define PHAL_TOP_T1T_STATE_UNKNOWN                  0x00U                /**< Default initial state. */
#define PHAL_TOP_T1T_STATE_INITIALIZED              0x01U                /**< Initialized state. */
#define PHAL_TOP_T1T_STATE_READONLY                 0x02U                /**< Read Only state. */
#define PHAL_TOP_T1T_STATE_READWRITE                0x04U                /**< Read/Write state. */
/*@}*/

/**
* \name T2T Tag States
*/
/*@{*/
#define PHAL_TOP_T2T_STATE_UNKNOWN                  0x00U                /**< Default initial state. */
#define PHAL_TOP_T2T_STATE_INITIALIZED              0x01U                /**< Initialized state. */
#define PHAL_TOP_T2T_STATE_READONLY                 0x02U                /**< Read Only state. */
#define PHAL_TOP_T2T_STATE_READWRITE                0x04U                /**< Read/Write state. */
/*@}*/

/**
* \name T3T Tag States
*/
/*@{*/
#define PHAL_TOP_T3T_STATE_UNKNOWN                  0x00U                /**< Default initial state. */
#define PHAL_TOP_T3T_STATE_INITIALIZED              0x01U                /**< Initialized state. */
#define PHAL_TOP_T3T_STATE_READONLY                 0x02U                /**< Read-only state. */
#define PHAL_TOP_T3T_STATE_READWRITE                0x04U                /**< Read/Write state. */
/*@}*/

/**
* \name T4T Tag States
*/
/*@{*/
#define PHAL_TOP_T4T_STATE_UNKNOWN                  0x00U                /**< Default initial state. */
#define PHAL_TOP_T4T_STATE_INITIALIZED              0x01U                /**< Initialized state. */
#define PHAL_TOP_T4T_STATE_READONLY                 0x02U                /**< Read only state. */
#define PHAL_TOP_T4T_STATE_READWRITE                0x04U                /**< Read/Write state. */
/*@}*/

/**
* \name T5T Tag States
*/
/*@{*/
#define PHAL_TOP_T5T_STATE_UNKNOWN                  0x00U                /**< Default initial state. */
#define PHAL_TOP_T5T_STATE_INITIALIZED              0x01U                /**< Initialized state. */
#define PHAL_TOP_T5T_STATE_READONLY                 0x02U                /**< Read Only state. */
#define PHAL_TOP_T5T_STATE_READWRITE                0x04U                /**< Read/Write state. */
/*@}*/

/**
* \name T1T Memory type
*/
/*@{*/
#define PHAL_TOP_T1T_TAG_MEMORY_TYPE_STATIC         0x00U                /**< Static memory type */
#define PHAL_TOP_T1T_TAG_MEMORY_TYPE_DYNAMIC        0x01U                /**< Dynamic memory type */
/*@}*/

/**
* \name T2T Memory type
*/
/*@{*/
#define PHAL_TOP_T2T_TAG_MEMORY_TYPE_STATIC         0x00U                /**< Static memory type */
#define PHAL_TOP_T2T_TAG_MEMORY_TYPE_DYNAMIC        0x01U                /**< Dynamic memory type */
/*@}*/

/**
* \name T1T R/W access type
*/
/*@{*/
#define PHAL_TOP_T1T_CC_RWA_RW                      0x00U                /**< Read/Write access */
#define PHAL_TOP_T1T_CC_RWA_RO                      0x0FU                /**< Read Only access */
/*@}*/

/**
* \name T2T R/W access type
*/
/*@{*/
#define PHAL_TOP_T2T_CC_RWA_RW                      0x00U                /**< Read/Write access */
#define PHAL_TOP_T2T_CC_RWA_RO                      0x0FU                /**< Read Only access */
/*@}*/

/**
* \name T3T R/W access type
*/
/*@{*/
#define PHAL_TOP_T3T_AIB_RWA_RW                     0x01U                /**< Read/Write access */
#define PHAL_TOP_T3T_AIB_RWA_RO                     0x00U                /**< Read Only access */
/*@}*/

/**
* \name T3T Write Flag access type
*/
/*@{*/
#define PHAL_TOP_T3T_WRITE_FLAG_SET                 0x0FU                /**< Write Flag to SET during Write in Progress */
#define PHAL_TOP_T3T_WRITE_FLAG_RESET               0x00U                /**< Write Flag to RESET after Write is Done */
/*@}*/

/**
* \name T4T R/W access type
*/
/*@{*/
#define PHAL_TOP_T4T_NDEF_FILE_READ                 0x00U                /**< Read/Write access */
#define PHAL_TOP_T4T_NDEF_FILE_WRITE_ACCESS         0x00U                /**< Read/Write access */
#define PHAL_TOP_T4T_NDEF_FILE_NO_WRITE_ACCESS      0xFFU                /**< Read Only access */
/*@}*/

/**
* \name T5T R/W access type
*/
/*@{*/
#define PHAL_TOP_T5T_CC_RWA_RW                     0x00U                /**< Read/Write access */
#define PHAL_TOP_T5T_CC_RWA_RO                     0x03U                /**< Read Only access */
/*@}*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phalTop/src/Sw/phalTop_Sw.h"

#define phalTop_ReadNdef(pDataParams, pData, pLength) \
        phalTop_Sw_ReadNdef( (phalTop_Sw_DataParams_t *)pDataParams, pData, pLength)

#define phalTop_WriteNdef(pDataParams, pData, pLength) \
        phalTop_Sw_WriteNdef( (phalTop_Sw_DataParams_t *)pDataParams, pData, pLength)

#define phalTop_CheckNdef(pDataParams, pNdefPresence) \
        phalTop_Sw_CheckNdef( (phalTop_Sw_DataParams_t *)pDataParams, pNdefPresence)

#define phalTop_Reset(pDataParams) \
        phalTop_Sw_Reset( (phalTop_Sw_DataParams_t *)pDataParams)

#define phalTop_SetConfig(pDataParams, wConfig, wValue) \
        phalTop_Sw_SetConfig( (phalTop_Sw_DataParams_t *)pDataParams, wConfig, wValue)

#define phalTop_GetConfig(pDataParams, wConfig, pValue) \
        phalTop_Sw_GetConfig( (phalTop_Sw_DataParams_t *)pDataParams, wConfig, pValue)

#define phalTop_EraseNdef(pDataParams) \
        phalTop_Sw_EraseNdef( (phalTop_Sw_DataParams_t *)pDataParams)

#define phalTop_FormatNdef(pDataParams) \
        phalTop_Sw_FormatNdef( (phalTop_Sw_DataParams_t *)pDataParams)

#else



/**
* \brief Format Tag to write NDEF message.
* Used to Format New/Non-NDEF tag to NDEF tag.
*
* <em>Description :</em> The caller has to ensure that \ref phalTop_CheckNdef is called before
* calling phalTop_FormatNdef and check if the tag is format-able or not using \ref phalTop_GetConfig.
* If \ref phalTop_CheckNdef returns that tag is supported then this API will format the tag so that
* it is NDEF compatible and in case of T2T a valid NDEF message is written and in case of other
* tags the contents of the tag will not be valid. User can call \ref phalTop_WriteNdef to write a new
* NDEF message on to the tag.
* Note: In case of T4T \ref phalTop_FormatNdef API will only format MIFARE DESFire card to be T4T compliant. \n\n
* \return Status code
* \retval #PH_ERR_SUCCESS                 Operation successful.
* \retval #PH_ERR_UNSUPPORTED_COMMAND     If tag is not format-able or in some different state.
* \retval Other Depending on implementation and underlying component.
*/
phStatus_t phalTop_FormatNdef(
    void * pDataParams            /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief Read NDEF message from tag.
*
* <em>Description :</em> The caller has to ensure that \ref phalTop_CheckNdef is called before
* calling phalTop_ReadNdef. If \ref phalTop_CheckNdef returns valid NDEF present on tag
* then phalTop_ReadNdef should be called otherwise error code is returned. User has to
* parse data according to NDEF specification to validate data as an NDEF.\n\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
* \retval #PH_ERR_PROTOCOL_ERROR No valid NDEF present on tag.
* \retval Other Depending on implementation and underlying component.
*/
phStatus_t phalTop_ReadNdef(
    void * pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
    uint8_t * pData,              /**< [Out] NDEF data from the tag. User has to allocate memory accordingly */
    uint16_t * pLength            /**< [Out] NDEF data length. */
    );

/**
* \brief Write NDEF message into tag.
*
* <em>Description :</em> The caller has to ensure that \ref phalTop_CheckNdef is called before
* calling phalTop_WriteNdef. If it is a new tag then \ref phalTop_FormatNdef should be called
* to create NDEF tag. Then phalTop_WriteNdef should be called otherwise error code is returned.\n
* <em>Note :</em> In case of T2T tag a valid NDEF must be present before calling this API.
* So to make it convenient \ref phalTop_FormatNdef can be used to write a default NDEF message
* and then phalTop_WriteNdef API can be used to write NDEF Message.\n\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
* \retval #PHAL_TOP_ERR_NOT_FORMATTED Non Formatted tag.
* \retval Other Depending on implementation and underlying component.
*/
phStatus_t phalTop_WriteNdef(
    void * pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
    uint8_t * pData,              /**< [In] NDEF data to be written to tag. User has to allocate memory accordingly */
    uint16_t wLength              /**< [In] Length of NDEF data to be written. */
    );

/**
* \brief Check for NDEF message presence and check for different TLVs
*
* <em>Description :</em> The caller has to ensure that tag activation and authentication is done
* before calling phalTop_CheckNdef. Also \ref phalTop_SetConfig should be called to configure the
* tag used. Only after phalTop_CheckNdef is called any other operation on tag can be performed.\n\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other depending on implementation and underlying component.
*/
phStatus_t phalTop_CheckNdef(
    void * pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
    uint8_t * pNdefPresence       /**< [Out] NDEF data Presence; 1 - NDEF present, 0 - Not present. */
    );

/**
* \brief Reset tag operation parameters
*
* <em>Description :</em> User can call phalTop_Reset to reset all the parameters which are modified
* when \ref phalTop_CheckNdef, \ref phalTop_WriteNdef or \ref phalTop_ReadNdef API's are called.\n\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
phStatus_t phalTop_Reset(
    void * pDataParams            /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief Erase NDEF message
*
* <em>Description :</em> By calling phalTop_EraseNdef, NDEF message stored on the tag would be erased
* and the NDEF length would be zero to indicate that there is no NDEF Message on tag. User can call
* \ref phalTop_CheckNdef to make sure that there is a valid NDEF present on tag then
* phalTop_EraseNdef can be called to erase otherwise no operation would be performed.\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
phStatus_t phalTop_EraseNdef(
    void * pDataParams            /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief Set configuration parameter.
*
* <em>Description :</em> Before calling \ref phalTop_CheckNdef, \ref phalTop_WriteNdef, \ref
* phalTop_ReadNdef API's or \ref phalTop_FormatNdef, user needs to call phalTop_SetConfig to configure
* different parameters as per the tag used based on User need. After configuring a particular tag
* by calling phalTop_SetConfig, all these parameters are set during further operations (refer Configuration
* Parameters to know how particular parameter used during Top Operations. User can also refer T1T, T2T, T3T
* T4T or T5T Specifications to know in detail).\n\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
*/
phStatus_t phalTop_SetConfig(
    void * pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
    uint16_t wConfig,             /**< [In] Configuration Identifier. */
    uint16_t wValue               /**< [In] Configuration Value. */
    );

/**
* \brief Get configuration parameter.
*
* <em>Description :</em> After calling \ref phalTop_CheckNdef, \ref phalTop_WriteNdef, \ref
* phalTop_ReadNdef API's or \ref phalTop_FormatNdef, user can call phalTop_GetConfig to get different
* parameters as per the tag used based on User need. After a valid operation on a particular tag
* all the parameters of the tag are updated and user can call phalTop_GetConfig to know the values (refer
* Configuration Parameters to know how particular parameter used during Top Operations. User can also refer
* T1T, T2T, T3T, T4T or T5T Specifications to know in detail).\n\n
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
*/
phStatus_t phalTop_GetConfig(
    void * pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
    uint16_t wConfig,             /**< [In] Configuration identifier. */
    uint16_t * pValue             /**< [Out] Configuration value. */
    );

/** @} */

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PHAL_TOP */

#ifdef __cplusplus
} /* Extern C */
#endif

#ifdef __DEBUG
/* This API is available only for debugging purpose and test bench */
/**
* \brief   Assigns the component data parameter to one of the filed in
*          T1T parameter based on the option
*
* \return  Error code
* \retval  #PH_ERR_INVALID_PARAMTER  If invalid option was passed
* \retval  #PH_ERR_SUCCESS           on success
*
*/
phStatus_t phalTop_SetPtr(
    void * pDataParams,           /**< [In] Pointer to this layer's parameter structure */
    void * pT1T,                  /**< [In] Pointer to tag Type 1 parameter structure */
    void * pT2T,                  /**< [In] Pointer to tag Type 2 parameter structure */
    void * pT3T,                  /**< [In] Pointer to tag Type 3 parameter structure */
    void * pT4T,                  /**< [In] Pointer to tag Type 4 parameter structure */
    void * pT5T                   /**< [In] Pointer to tag Type 4 parameter structure */
    );
#endif /* __DEBUG */
#endif  /* PHALTOP_H */
