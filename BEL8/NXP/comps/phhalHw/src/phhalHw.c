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

/** \file
* Generic HAL Component of Reader Library Framework.
* $Author: jenkins_cm (nxp92197) $
* $Revision: 3068 $ (NfcRdLib_A_Gate_Incremental_V3.092.04.001533 : 2673 )
* $Date: 2015-08-14 19:29:17 +0530 (Fri, 14 Aug 2015) $
*
* History:
*  CHu: Generated 19. May 2009
*
*/

#include <phhalHw.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHHAL_HW_RC663
#include "Rc663/phhalHw_Rc663.h"
#include "../intfs/phhalHw_Rc663_Cmd.h"
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
#include "Rc523/phhalHw_Rc523.h"
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
#include "Rd70x/phhalHw_Rd70x.h"
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RC632
#include "Rc632/phhalHw_Rc632.h"
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_RD710
#include "Rd710/phhalHw_Rd710.h"
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
#include "Mp300/phhalHw_Mp300.h"
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
#include "Callback/phhalHw_Callback.h"
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
#include "SamAV2/phhalHw_SamAV2.h"
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
#include "RdCardSim/phhalHw_RdCardSim.h"
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
#include "MfcCrypto/phhalHw_MfcCrypto.h"
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
#include "RdFpgaV6/phhalHw_RdFpgaV6.h"
#endif /* NXPBUILD__PHHAL_HW_RDFPGAV6 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
#include "PN7462AU/phhalHw_PN7462AU.h"
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
#include "DUT/phhalHw_DUT.h"
#endif /* NXPBUILD__PHHAL_HW_DUT */

#ifdef NXPBUILD__PHHAL_HW



#ifndef _WIN32
phStatus_t phhalHw_Nfc_IC_Init(
                              phhalHw_Nfc_Ic_DataParams_t  * pDataParams,
                              uint16_t wSizeOfDataParams,
                              void * pBalDataParams,
                              void * pKeyStoreDataParams,
                              uint8_t * pTxBuffer,
                              uint16_t wTxBufSize,
                              uint8_t * pRxBuffer,
                              uint16_t wRxBufSize
                              )
{
    phStatus_t PH_MEMLOC_REM status = PH_ERR_SUCCESS;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Nfc_IC_Init");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

#ifdef NXPBUILD__PHHAL_HW_RC523
    /* Initialize the Reader HAL (Hardware Abstraction Layer) component */
    status = phhalHw_Rc523_Init(
                                &pDataParams->sHal,
                                sizeof(phhalHw_Rc523_DataParams_t),
                                pBalDataParams,
                                pKeyStoreDataParams,
                                pTxBuffer,
                                wTxBufSize,
                                pRxBuffer,
                                wRxBufSize
                                );
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RC663
    /* Initialize the Reader HAL (Hardware Abstraction Layer) component */
    status = phhalHw_Rc663_Init(
                                &pDataParams->sHal,
                                sizeof(phhalHw_Rc663_DataParams_t),
                                pBalDataParams,
                                pKeyStoreDataParams,
                                pTxBuffer,
                                wTxBufSize,
                                pRxBuffer,
                                wRxBufSize
                                );
#endif /* NXPBUILD__PHHAL_HW_RC663 */

    return status;
}
#endif

#ifdef _WIN32
phStatus_t phhalHw_WriteRegister(
                                 void * pDataParams,
                                 uint8_t bAddress,
                                 uint8_t bValue
                                 )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_WriteRegister");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bAddress);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bValue);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bAddress_log, &bAddress);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bValue_log, &bValue);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_WriteRegister((phhalHw_Rc663_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_WriteRegister((phhalHw_Rc523_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_WriteRegister((phhalHw_Rd70x_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_WriteRegister((phhalHw_Rd710_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_WriteRegister((phhalHw_Mp300_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_WriteRegister((phhalHw_Callback_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_WriteRegister((phhalHw_SamAV2_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_WriteRegister((phhalHw_RdCardSim_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_WriteRegister((phhalHw_MfcCrypto_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_WriteRegister((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_WriteRegister((phhalHw_Rc632_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#if 0
#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_WriteRegister((phhalHw_Rc632_DataParams_t *)pDataParams, bAddress, bValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */
#endif
    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_ReadRegister(
                                void * pDataParams,
                                uint8_t bAddress,
                                uint8_t * pValue
                                )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_ReadRegister");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bAddress);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pValue);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bAddress_log, &bAddress);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_ReadRegister((phhalHw_Rc663_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_ReadRegister((phhalHw_Rc523_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_ReadRegister((phhalHw_Rd70x_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_ReadRegister((phhalHw_Rd710_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_ReadRegister((phhalHw_Mp300_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_ReadRegister((phhalHw_Callback_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_ReadRegister((phhalHw_SamAV2_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_ReadRegister((phhalHw_RdCardSim_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_ReadRegister((phhalHw_MfcCrypto_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_ReadRegister((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_ReadRegister((phhalHw_Rc632_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#if 0
#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_ReadRegister((phhalHw_DUT_DataParams_t *)pDataParams, bAddress, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */
#endif

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, pValue_log, pValue);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

#endif /* ifdef _WIN32 */

#ifndef NXPRDLIB_REM_GEN_INTFS

phStatus_t phhalHw_Exchange(
                            void * pDataParams,
                            uint16_t wOption,
                            uint8_t * pTxBuffer,
                            uint16_t wTxLength,
                            uint8_t ** ppRxBuffer,
                            uint16_t * pRxLength
                            )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Exchange");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wOption);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pTxBuffer);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(ppRxBuffer);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wOption_log, &wOption);
    PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, pTxBuffer_log, pTxBuffer, wTxLength);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    if (wTxLength) PH_ASSERT_NULL (pTxBuffer);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_Exchange((phhalHw_Rc663_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_Exchange((phhalHw_Rc523_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_Exchange((phhalHw_Rd70x_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_Exchange((phhalHw_Rd710_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_Exchange((phhalHw_Mp300_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_Exchange((phhalHw_Callback_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_Exchange((phhalHw_SamAV2_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_Exchange((phhalHw_RdCardSim_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_Exchange((phhalHw_MfcCrypto_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_Exchange((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_Exchange((phhalHw_Rc632_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_Exchange((phhalHw_PN7462AU_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_Exchange((phhalHw_DUT_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
#ifdef NXPBUILD__PH_LOG
    if ((((status & PH_ERR_MASK) == PH_ERR_SUCCESS) ||
        ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING) ||
        ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)) &&
        !(wOption & PH_EXCHANGE_BUFFERED_BIT) &&
        (ppRxBuffer != NULL))
    {
        PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, ppRxBuffer_log, *ppRxBuffer, *pRxLength);
    }
#endif
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_ApplyProtocolSettings(
    void * pDataParams,
    uint8_t bMode
    )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_ApplyProtocolSettings");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bMode);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bMode_log, &bMode);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_ApplyProtocolSettings((phhalHw_Rc663_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_ApplyProtocolSettings((phhalHw_Rc523_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_ApplyProtocolSettings((phhalHw_Rd70x_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_ApplyProtocolSettings((phhalHw_Rd710_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_ApplyProtocolSettings((phhalHw_Mp300_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_ApplyProtocolSettings((phhalHw_Callback_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_ApplyProtocolSettings((phhalHw_SamAV2_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_ApplyProtocolSettings((phhalHw_RdCardSim_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_ApplyProtocolSettings((phhalHw_MfcCrypto_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_ApplyProtocolSettings((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, bMode);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_ApplyProtocolSettings((phhalHw_Rc632_DataParams_t *)pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_ApplyProtocolSettings((phhalHw_PN7462AU_DataParams_t *) pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_ApplyProtocolSettings((phhalHw_DUT_DataParams_t *) pDataParams, bMode);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_SetConfig(
                             void * pDataParams,
                             uint16_t wConfig,
                             uint16_t wValue
                             )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_SetConfig");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wConfig);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wValue);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wConfig_log, &wConfig);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wValue_log, &wValue);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_SetConfig((phhalHw_Rc663_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_SetConfig((phhalHw_Rc523_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_SetConfig((phhalHw_Rd70x_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_SetConfig((phhalHw_Rd710_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_SetConfig((phhalHw_Mp300_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_SetConfig((phhalHw_Callback_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_SetConfig((phhalHw_SamAV2_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_SetConfig((phhalHw_RdCardSim_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_SetConfig((phhalHw_MfcCrypto_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_SetConfig((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_SetConfig((phhalHw_Rc632_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_SetConfig((phhalHw_PN7462AU_DataParams_t *) pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_SetConfig((phhalHw_DUT_DataParams_t *) pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_MfcAuthenticateKeyNo(
                                        void * pDataParams,
                                        uint8_t bBlockNo,
                                        uint8_t bKeyType,
                                        uint16_t wKeyNo,
                                        uint16_t wKeyVersion,
                                        uint8_t * pUid
                                        )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_MfcAuthenticateKeyNo");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bBlockNo);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bKeyType);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wKeyNo);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wKeyVersion);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pUid);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bBlockNo_log, &bBlockNo);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bKeyType_log, &bKeyType);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wKeyNo_log, &wKeyNo);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wKeyVersion_log, &wKeyVersion);
    PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, pUid_log, pUid, 4);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pUid);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_MfcAuthenticateKeyNo(
            (phhalHw_Rc663_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_MfcAuthenticateKeyNo(
            (phhalHw_Rc523_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_MfcAuthenticateKeyNo(
            (phhalHw_Rd70x_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_MfcAuthenticateKeyNo(
            (phhalHw_Rd710_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_MfcAuthenticateKeyNo(
            (phhalHw_Mp300_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_MfcAuthenticateKeyNo(
            (phhalHw_Callback_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_MfcAuthenticateKeyNo(
            (phhalHw_SamAV2_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_MfcAuthenticateKeyNo(
            (phhalHw_RdCardSim_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_MfcAuthenticateKeyNo(
            (phhalHw_MfcCrypto_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_MfcAuthenticateKeyNo(
            (phhalHw_RdFpgaV6_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_MfcAuthenticateKeyNo(
            (phhalHw_Rc632_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_MfcAuthenticateKeyNo(
            (phhalHw_DUT_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            wKeyNo,
            wKeyVersion,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_MfcAuthenticate(
                                   void * pDataParams,
                                   uint8_t bBlockNo,
                                   uint8_t bKeyType,
                                   uint8_t * pKey,
                                   uint8_t * pUid
                                   )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_MfcAuthenticate");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bBlockNo);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bKeyType);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pKey);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pUid);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bBlockNo_log, &bBlockNo);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bKeyType_log, &bKeyType);
    PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, pKey_log, pKey, 6);
    PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, pUid_log, pUid, 4);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pKey);
    PH_ASSERT_NULL (pUid);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_MfcAuthenticate(
            (phhalHw_Rc663_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_MfcAuthenticate(
            (phhalHw_Rc523_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_MfcAuthenticate(
            (phhalHw_Rd70x_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_MfcAuthenticate(
            (phhalHw_Rd710_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_MfcAuthenticate(
            (phhalHw_Mp300_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_MfcAuthenticate(
            (phhalHw_Callback_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_MfcAuthenticate(
            (phhalHw_SamAV2_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_MfcAuthenticate(
            (phhalHw_RdCardSim_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_MfcAuthenticate(
            (phhalHw_MfcCrypto_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_MfcAuthenticate(
            (phhalHw_RdFpgaV6_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_MfcAuthenticate(
            (phhalHw_Rc632_DataParams_t *)pDataParams,
            bBlockNo,
            bKeyType,
            pKey,
            pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_MfcAuthenticate((phhalHw_PN7462AU_DataParams_t *)pDataParams,
                bBlockNo, bKeyType, pKey, pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_MfcAuthenticate((phhalHw_DUT_DataParams_t *)pDataParams,
                bBlockNo, bKeyType, pKey, pUid);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_GetConfig(
                             void * pDataParams,
                             uint16_t wConfig,
                             uint16_t * pValue
                             )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_GetConfig");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wConfig);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pValue);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wConfig_log, &wConfig);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
        case PHHAL_HW_RC663_ID:
            status = phhalHw_Rc663_GetConfig((phhalHw_Rc663_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
        case PHHAL_HW_RC523_ID:
            status = phhalHw_Rc523_GetConfig((phhalHw_Rc523_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
        case PHHAL_HW_RD70X_ID:
            status = phhalHw_Rd70x_GetConfig((phhalHw_Rd70x_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
        case PHHAL_HW_RD710_ID:
            status = phhalHw_Rd710_GetConfig((phhalHw_Rd710_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
        case PHHAL_HW_MP300_ID:
            status = phhalHw_Mp300_GetConfig((phhalHw_Mp300_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
        case PHHAL_HW_CALLBACK_ID:
            status = phhalHw_Callback_GetConfig((phhalHw_Callback_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
        case PHHAL_HW_SAMAV2_ID:
            status = phhalHw_SamAV2_GetConfig((phhalHw_SamAV2_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
        case PHHAL_HW_RDCARDSIM_ID:
            status = phhalHw_RdCardSim_GetConfig((phhalHw_RdCardSim_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
        case PHHAL_HW_MFCCRYPTO_ID:
            status = phhalHw_MfcCrypto_GetConfig((phhalHw_MfcCrypto_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
        case PHHAL_HW_RDFPGAV6_ID:
            status = phhalHw_RdFpgaV6_GetConfig((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
        case PHHAL_HW_RC632_ID:
            status = phhalHw_Rc632_GetConfig((phhalHw_Rc632_DataParams_t *)pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_GetConfig((phhalHw_PN7462AU_DataParams_t *) pDataParams,wConfig, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_GetConfig((phhalHw_DUT_DataParams_t *) pDataParams,wConfig, pValue);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

        default:
            status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
            break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, pValue_log, pValue);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_FieldOn(
                           void * pDataParams
                           )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_FieldOn");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_FieldOn((phhalHw_Rc663_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_FieldOn((phhalHw_Rc523_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_FieldOn((phhalHw_Rd70x_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_FieldOn((phhalHw_Rd710_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_FieldOn((phhalHw_Mp300_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_FieldOn((phhalHw_Callback_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_FieldOn((phhalHw_SamAV2_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_FieldOn((phhalHw_RdCardSim_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_FieldOn((phhalHw_MfcCrypto_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_FieldOn((phhalHw_RdFpgaV6_DataParams_t *)pDataParams);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_FieldOn((phhalHw_Rc632_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_FieldOn((phhalHw_PN7462AU_DataParams_t *) pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_FieldOn((phhalHw_DUT_DataParams_t *) pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */
    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_FieldOff(
                            void * pDataParams
                            )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_FieldOff");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_FieldOff((phhalHw_Rc663_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_FieldOff((phhalHw_Rc523_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_FieldOff((phhalHw_Rd70x_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_FieldOff((phhalHw_Rd710_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_FieldOff((phhalHw_Mp300_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_FieldOff((phhalHw_Callback_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_FieldOff((phhalHw_SamAV2_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_FieldOff((phhalHw_RdCardSim_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_FieldOff((phhalHw_MfcCrypto_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_FieldOff((phhalHw_RdFpgaV6_DataParams_t *)pDataParams);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_FieldOff((phhalHw_Rc632_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_FieldOff((phhalHw_PN7462AU_DataParams_t *) pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_FieldOff((phhalHw_DUT_DataParams_t *) pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */
    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_FieldReset(
                              void * pDataParams
                              )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_FieldReset");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_FieldReset((phhalHw_Rc663_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_FieldReset((phhalHw_Rc523_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_FieldReset((phhalHw_Rd70x_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_FieldReset((phhalHw_Rd710_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_FieldReset((phhalHw_Mp300_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_FieldReset((phhalHw_Callback_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_FieldReset((phhalHw_SamAV2_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_FieldReset((phhalHw_RdCardSim_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_FieldReset((phhalHw_MfcCrypto_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_FieldReset((phhalHw_RdFpgaV6_DataParams_t *)pDataParams);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_FieldReset((phhalHw_Rc632_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */
#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_FieldReset((phhalHw_PN7462AU_DataParams_t *) pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_FieldReset((phhalHw_DUT_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */
    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_Wait(
                        void * pDataParams,
                        uint8_t bUnit,
                        uint16_t wTimeout
                        )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Wait");
    /*PH_LOG_HELPER_ALLOCATE_PARAMNAME(pDataParams);*/
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bUnit);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wTimeout);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bUnit_log, &bUnit);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wTimeout_log, &wTimeout);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_Wait((phhalHw_Rc663_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_Wait((phhalHw_Rc523_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_RD70X
    case PHHAL_HW_RD70X_ID:
        status = phhalHw_Rd70x_Wait((phhalHw_Rd70x_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD70X */

#ifdef NXPBUILD__PHHAL_HW_RD710
    case PHHAL_HW_RD710_ID:
        status = phhalHw_Rd710_Wait((phhalHw_Rd710_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_RD710 */

#ifdef NXPBUILD__PHHAL_HW_MP300
    case PHHAL_HW_MP300_ID:
        status = phhalHw_Mp300_Wait((phhalHw_Mp300_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_MP300 */

#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_Wait((phhalHw_Callback_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */

#ifdef NXPBUILD__PHHAL_HW_SAMAV2
    case PHHAL_HW_SAMAV2_ID:
        status = phhalHw_SamAV2_Wait((phhalHw_SamAV2_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_SAMAV2 */

#ifdef NXPBUILD__PHHAL_HW_RDCARDSIM
    case PHHAL_HW_RDCARDSIM_ID:
        status = phhalHw_RdCardSim_Wait((phhalHw_RdCardSim_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_RDCARDSIM */

#ifdef NXPBUILD__PHHAL_HW_MFCCRYPTO
    case PHHAL_HW_MFCCRYPTO_ID:
        status = phhalHw_MfcCrypto_Wait((phhalHw_MfcCrypto_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_MFCCRYPTO */

#ifdef NXPBUILD__PHHAL_HW_RDFPGAV6
    case PHHAL_HW_RDFPGAV6_ID:
        status = phhalHw_RdFpgaV6_Wait((phhalHw_RdFpgaV6_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /*NXPBUILD__PHHAL_HW_RDFPGAV6*/

#ifdef NXPBUILD__PHHAL_HW_RC632
    case PHHAL_HW_RC632_ID:
        status = phhalHw_Rc632_Wait((phhalHw_Rc632_DataParams_t *)pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC632 */

#ifdef NXPBUILD__PHHAL_HW_PN7462AUHW
    case PHHAL_HW_PN7462AU_ID:
        status = phhalHw_PN7462AU_Wait((phhalHw_PN7462AU_DataParams_t *) pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_PN7462AUHW */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_Wait((phhalHw_DUT_DataParams_t *) pDataParams, bUnit, wTimeout);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_Transmit(
                           void * pDataParams,
                           uint16_t wOption,
                           uint8_t * pTxBuffer,
                           uint16_t wTxLength
                           )
{

    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Transmit");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wOption);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pTxBuffer);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wOption_log, &wOption);
    PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, pTxBuffer_log, pTxBuffer, wTxLength);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    if (wTxLength) PH_ASSERT_NULL (pTxBuffer);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_Transmit((phhalHw_Rc663_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_Transmit((phhalHw_Rc523_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_Transmit((phhalHw_DUT_DataParams_t *) pDataParams, wOption, pTxBuffer, wTxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_Receive(
                           void * pDataParams,
                           uint16_t wOption,
                           uint8_t ** ppRxBuffer,
                           uint16_t * pRxLength
                           )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Receive");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wOption);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(ppRxBuffer);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wOption_log, &wOption);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_Receive((phhalHw_Rc663_DataParams_t *)pDataParams, wOption, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_Receive((phhalHw_Rc523_DataParams_t *)pDataParams, wOption, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#ifdef NXPBUILD__PHHAL_HW_DUT
    case PHHAL_HW_DUT_ID:
        status = phhalHw_DUT_Recieve((phhalHw_DUT_DataParams_t *) pDataParams, wOption, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHHAL_HW_DUT */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
#ifdef NXPBUILD__PH_LOG
    if ((((status & PH_ERR_MASK) == PH_ERR_SUCCESS) ||
        ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING) ||
        ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)) &&
        !(wOption & PH_EXCHANGE_BUFFERED_BIT) &&
        (ppRxBuffer != NULL))
    {
        PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, ppRxBuffer_log, *ppRxBuffer, *pRxLength);
    }
#endif
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_Autocoll(
                            void * pDataParams,
                            uint16_t wMode,
                            uint8_t ** ppRxBuffer,
                            uint16_t * pRxLength,
                            uint16_t * pProtParams
                            )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Autocoll");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(wMode);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(ppRxBuffer);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_DEBUG, wMode_log, &wMode);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        /* RC663 doesn't support Target Mode */
        status = PH_ADD_COMPCODE(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_HAL);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_Autocoll((phhalHw_Rc523_DataParams_t *)pDataParams, wMode, ppRxBuffer, pRxLength, pProtParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */
#ifdef NXPBUILD__PHHAL_HW_CALLBACK
    case PHHAL_HW_CALLBACK_ID:
        status = phhalHw_Callback_Autocoll((phhalHw_Callback_DataParams_t *)pDataParams, wMode, ppRxBuffer, pRxLength, pProtParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_CALLBACK */
    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

#ifdef NXPBUILD__PH_LOG
    if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS &&
        (ppRxBuffer != NULL))
    {
        PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, ppRxBuffer_log, *ppRxBuffer, *pRxLength);
    }
#endif
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
    return status;
}

phStatus_t phhalHw_Lpcd(
                        void * pDataParams
                        )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_Lpcd");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

     /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_Cmd_Lpcd((phhalHw_Rc663_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = PH_ADD_COMPCODE(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_AsyncAbort(
                              void * pDataParams
                              )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_AsyncAbort");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_AsyncAbort((phhalHw_Rc663_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_AsyncAbort((phhalHw_Rc523_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

phStatus_t phhalHw_I18000p3m3Inventory(
                                       void * pDataParams,
                                       uint8_t * pSelCmd,
                                       uint8_t bSelCmdLen,
                                       uint8_t bNumValidBitsinLastByte,
                                       uint8_t * pBeginRndCmd,
                                       uint8_t bTSprocessing,
                                       uint8_t ** ppRxBuffer,
                                       uint16_t * wRxBufferLen
                                       )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_I18000p3m3Inventory");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(pSelCmd);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bNumValidBitsinLastByte);
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(bTSprocessing);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pSelCmd);
    PH_ASSERT_NULL (pBeginRndCmd);
    PH_ASSERT_NULL (ppRxBuffer);
    PH_ASSERT_NULL (wRxBufferLen);

    PH_LOG_HELPER_ADDPARAM_BUFFER(PH_LOG_LOGTYPE_DEBUG, pSelCmd_log, pSelCmd, bSelCmdLen);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bNumValidBitsinLastByte_log, &bNumValidBitsinLastByte);
    PH_LOG_HELPER_ADDPARAM_UINT8(PH_LOG_LOGTYPE_DEBUG, bTSprocessing_log, &bTSprocessing);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_I18000p3m3Inventory(
            (phhalHw_Rc663_DataParams_t *)pDataParams,
            pSelCmd,
            bSelCmdLen,
            bNumValidBitsinLastByte,
            pBeginRndCmd,
            bTSprocessing,
            ppRxBuffer,
            wRxBufferLen);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */
    /* TBD Add PN518 Inventory HAL function */
    /* case PHHAL_HW_PN518_ID: */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    return status;
}

phStatus_t phhalHw_I18000p3m3ResumeInventory(
                                             void * pDataParams,
                                             uint8_t ** ppRxBuffer,
                                             uint16_t * wRxBufferLen
                                             )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_I18000p3m3ResumeInventory");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (ppRxBuffer);
    PH_ASSERT_NULL (wRxBufferLen);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_I18000p3m3ResumeInventory(
            (phhalHw_Rc663_DataParams_t *)pDataParams,
            ppRxBuffer,
            wRxBufferLen);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    return status;
}

phStatus_t phhalHw_DeInit(
                          void * pDataParams
                          )
{
    phStatus_t PH_MEMLOC_REM status;

    PH_LOG_HELPER_ALLOCATE_TEXT(bFunctionName, "phhalHw_DeInit");
    PH_LOG_HELPER_ALLOCATE_PARAMNAME(status);
    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_ENTER);
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);

        PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
        PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
        PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_RC663
    case PHHAL_HW_RC663_ID:
        status = phhalHw_Rc663_DeInit((phhalHw_Rc663_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC663 */

#ifdef NXPBUILD__PHHAL_HW_RC523
    case PHHAL_HW_RC523_ID:
        status = phhalHw_Rc523_DeInit((phhalHw_Rc523_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_RC523 */

    default:
        status = PH_ADD_COMPCODE(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    PH_LOG_HELPER_ADDSTRING(PH_LOG_LOGTYPE_INFO, bFunctionName);
    PH_LOG_HELPER_ADDPARAM_UINT16(PH_LOG_LOGTYPE_INFO, status_log, &status);
    PH_LOG_HELPER_EXECUTE(PH_LOG_OPTION_CATEGORY_LEAVE);

    return status;
}

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PHHAL_HW */
