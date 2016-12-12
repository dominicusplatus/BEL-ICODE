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
* Timer of MicroController Platform.
* $Author: jenkins_cm (nxp92197) $
* $Revision: 3068 $ (NfcRdLib_A_Gate_Incremental_V3.092.04.001533 : 2879 )
* $Date: 2015-08-14 19:29:17 +0530 (Fri, 14 Aug 2015) $
*
*/

#include <ph_Status.h>
#include <ph_NxpBuild.h>

#ifdef NXPBUILD__PH_PLATFORM

#include <phPlatform.h>
#include "phOsal_Lpc17xx_Int.h"
#include <LPC17xx.h>
#include <lpc17xx_timer.h>
#include <lpc17xx_wdt.h>

phStatus_t phPlatform_Init(phPlatform_DataParams_t  *pDataParams )
{
    pDataParams->wId = PH_COMP_PLATFORM;
    return PH_ERR_SUCCESS;
}

phStatus_t phPlatform_Timer_Init(phPlatform_DataParams_t  *pDataParams )
{
    /* Lets be ready with the timer */
    phOsal_Lpc17xx_Int_Timer_Init(pDataParams);
    return PH_ERR_SUCCESS;
}

phStatus_t phPlatform_Timer_Create(phPlatform_DataParams_t  *pDataParams,
                                   uint32_t                 *pTimerId
                                   )
{
    phOsal_Lpc17xx_Int_Timer_Create(pDataParams, pTimerId);

    if (*pTimerId == -1)
    {
        /* No timer found, need to return error */
        return PH_ADD_COMPCODE(PH_PLATFORM_ERR_NO_FREE_TIMER,  PH_COMP_PLATFORM);
    }
    else
    {
        return PH_ERR_SUCCESS;
    }
}

phStatus_t phPlatform_Timer_Reset(phPlatform_DataParams_t  *pDataParams,
                                  uint32_t                  dwTimerId
                                  )
{
    phOsal_Lpc17xx_Int_Reset_Timer32(dwTimerId);
    return PH_ERR_SUCCESS;
}

phStatus_t phPlatform_Timer_Wait(phPlatform_DataParams_t  *pDataParams,
                                 uint8_t                   bTimerDelayUnit,
                                 uint16_t                  wDelay
                                 )
{
    uint32_t    dwTimerId;
    phStatus_t  status;

    status = phPlatform_Timer_Create(pDataParams, &dwTimerId);
    if(status == PH_ERR_SUCCESS)
    {
        phOsal_Lpc17xx_Int_Enable_Timer32(dwTimerId);
        if (bTimerDelayUnit == PH_PLATFORM_TIMER_UNIT_MS)
        {
            /* Delay in terms of Milli seconds */
            phOsal_Lpc17xx_Int_Delay32Ms(dwTimerId, wDelay);
        }
        else
        {
            /* Delay in terms of Micro seconds */
            phOsal_Lpc17xx_Int_Delay32Us(dwTimerId, wDelay);
        }
        status = phPlatform_Timer_Delete(pDataParams, dwTimerId);
        return status;
    }
    else
    {
        /* Return error status */
        return status;
    }
}

phStatus_t phPlatform_Timer_Start(phPlatform_DataParams_t  *pDataParams,
                                  uint32_t                  dwTimerId,
                                  uint32_t                  dwRegTimeCnt,
                                  uint16_t                  wOption,
                                  ppCallBck_t               pApplicationCallback,
                                  void                     *pContext
                                  )
{
    phStatus_t status;
    status = phOsal_Lpc17xx_Int_Timer_Register(pDataParams, dwTimerId, dwRegTimeCnt, wOption, pApplicationCallback, pContext);

    if (status == PH_ERR_SUCCESS)
    {
        return PH_ERR_SUCCESS;
    }
    else
    {
        return PH_ADD_COMPCODE(PH_PLATFORM_ERR_INVALID_TIMER, PH_COMP_PLATFORM);
    }
}

phStatus_t phPlatform_Timer_GetElapsedDelay(phPlatform_DataParams_t  *pDataParams,
                                            uint32_t                  dwTimerId,
                                            uint16_t                  wOption,
                                            uint32_t                  *dwGetElapsedDelay
                                            )
{
    phStatus_t status;
    status = phOsal_Lpc17xx_Int_Timer_GetElapsedDelay(pDataParams, dwTimerId, wOption, dwGetElapsedDelay);

    if (status == PH_ERR_SUCCESS)
    {
        return PH_ERR_SUCCESS;
    }
    else
    {
        return PH_ADD_COMPCODE(PH_PLATFORM_ERR_INVALID_TIMER, PH_COMP_PLATFORM);
    }
}

phStatus_t phPlatform_Timer_Delete(phPlatform_DataParams_t  *pDataParams,
                                   uint32_t                  dwTimerId
                                   )
{
    phStatus_t status;
    status = phOsal_Lpc17xx_Int_Timer_Delete(pDataParams, dwTimerId);
    if (status == PH_ERR_INTERNAL_ERROR)
    {
        return PH_ADD_COMPCODE(PH_PLATFORM_ERR_INVALID_TIMER, PH_COMP_PLATFORM);
    }
    else
    {
        return PH_ERR_SUCCESS;
    }
}

phStatus_t phPlatform_Timer_Stop(phPlatform_DataParams_t  *pDataParams,
                                 uint32_t                  dwTimerId
                                 )
{
    phStatus_t status;
    status = phOsal_Lpc17xx_Int_Timer_Stop(dwTimerId);

    if (status == PH_ERR_SUCCESS)
    {
        return status;
    }
    else
    {
        return PH_ADD_COMPCODE(PH_PLATFORM_ERR_INVALID_TIMER, PH_COMP_PLATFORM);
    }
}

phStatus_t phPlatform_Timer_ExecCallback(phPlatform_DataParams_t  *pDataParams,
                                         uint32_t                  dwTimerId
                                         )
{
    if (dwTimerId < LPC17XX_MAX_TIMERS)
    {
        /* Call the call back function */
        if (pDataParams->gTimers[dwTimerId].pApplicationCallback != NULL)
        {
            (pDataParams->gTimers[dwTimerId].pApplicationCallback)(pDataParams->gTimers[dwTimerId].pContext);
        }
    }
    return PH_ERR_SUCCESS;
}

#endif /* NXPBUILD__PH_PLATFORM */
/******************************************************************************
**                            End Of File
******************************************************************************/
