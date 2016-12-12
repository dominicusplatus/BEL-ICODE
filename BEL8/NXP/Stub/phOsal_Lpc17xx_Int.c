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
* LPC17xx OSAL Component of Reader Library Framework.
* $Author: jenkins_cm (nxp92197) $
* $Revision: 3068 $ (NfcRdLib_A_Gate_Incremental_V3.092.04.001533 : 2879 )
* $Date: 2015-08-14 19:29:17 +0530 (Fri, 14 Aug 2015) $
*
* History:
*  PC: Generated 23. Aug 2012
*
*/
#include <ph_Status.h>

#ifdef NXPBUILD__PH_PLATFORM

#include "phOsal_Lpc17xx_Int.h"
#include <phOsal.h>

static phPlatform_DataParams_t* pTimerOsal;

/**
* \brief      TIMER IRQ Handlers
*/
void TIMER0_IRQHandler(void)
{
  
    /* This is the only timer we are going to use for call backs  */
    phPlatform_Timer_ExecCallback(pTimerOsal, 0);

    return;
}

void TIMER1_IRQHandler(void)
{
   
    phPlatform_Timer_ExecCallback(pTimerOsal, 1);

    return;
}

void TIMER2_IRQHandler(void)
{
    
    phPlatform_Timer_ExecCallback(pTimerOsal, 2);

    return;
}


/*
 * Timers handling functions */
void phOsal_Lpc17xx_Int_Timer_Init(phPlatform_DataParams_t *pDataParams)
{
    uint8_t count = 0;

    /* Initialize the timer structure */
    for (count = 0; count < LPC17XX_MAX_TIMERS; count++)
    {
        pDataParams->gTimers[count].dwTimerId   = count;
        pDataParams->gTimers[count].bTimerFree = TIMER_FREE;
    }

    /* Also keep the timers ready with all the default settings.
      This also does the job of registering the IRQ with NVIC */
    phOsal_Lpc17xx_Int_Init_Timer32(0, LPC17XX_DEFAULT_TIME_INTERVAL);
    phOsal_Lpc17xx_Int_Init_Timer32(1, LPC17XX_DEFAULT_TIME_INTERVAL);
    phOsal_Lpc17xx_Int_Init_Timer32(2, LPC17XX_DEFAULT_TIME_INTERVAL);
    phOsal_Lpc17xx_Int_Init_Timer32(3, LPC17XX_DEFAULT_TIME_INTERVAL);

    pTimerOsal = pDataParams;
}

void phOsal_Lpc17xx_Int_Timer_Create(phPlatform_DataParams_t *pDataParams,
        uint32_t *pTimerId)
{

}

phStatus_t phOsal_Lpc17xx_Int_Timer_Register(phPlatform_DataParams_t  *pDataParams,
                                             uint32_t                      dwTimerId,
                                             uint32_t                      dwRegTimeCnt,
                                             uint16_t                      wOption,
                                             ppCallBck_t                   pApplicationCallback,
                                             void                         *pContext
                                             )
{

    return PH_ERR_SUCCESS;
}

phStatus_t phOsal_Lpc17xx_Int_Timer_GetElapsedDelay(phPlatform_DataParams_t  *pDataParams,
                                                    uint32_t                      dwTimerId,
                                                    uint16_t                      wOption,
                                                    uint32_t                     *dwGetDelay
                                                    )
{

    return PH_ERR_SUCCESS;
}

phStatus_t phOsal_Lpc17xx_Int_Timer_Stop(uint32_t dwTimerId)
{

    return PH_ERR_SUCCESS;
}

phStatus_t phOsal_Lpc17xx_Int_Timer_Delete(phPlatform_DataParams_t *pDataParams, uint32_t dwTimerId)
{

    return PH_ERR_SUCCESS;
}

void phOsal_Lpc17xx_Int_Delay32Ms(uint32_t dwTimerId, uint32_t delayInMs)
{
 

    return;
}

void phOsal_Lpc17xx_Int_Delay32Us(uint32_t dwTimerId, uint32_t delayInUs)
{
    
    return;
}

void phOsal_Lpc17xx_Int_Enable_Timer32(uint32_t dwTimerId)
{
   
    return;
}

void phOsal_Lpc17xx_Int_Disable_Timer32(uint32_t dwTimerId)
{
    
    return;
}

void phOsal_Lpc17xx_Int_Reset_Timer32(uint32_t dwTimerId)
{
   
    return;
}

void phOsal_Lpc17xx_Int_Init_Timer32(uint32_t dwTimerId, uint32_t TimerInterval)
{

    return;
}

void phOsal_Lpc17xx_Int_Load_TimerMs(uint32_t dwTimerId, uint32_t dwTimerInterval)
{
  
    return;
}

void phOsal_Lpc17xx_Int_Load_TimerUs(uint32_t dwTimerId, uint32_t dwTimerInterval)
{
   
    return;
}

void phOsal_Lpc17xx_Int_Get_TimerMs(uint32_t dwTimerId, uint32_t *delayInMs)
{
  
    return;
}

void phOsal_Lpc17xx_Int_Get_TimerUs(uint32_t dwTimerId, uint32_t *delayInUs)
{
  
    return;
}

#endif /* NXPBUILD__PH_PLATFORM */
