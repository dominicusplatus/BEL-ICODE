/*==============================================================================================
 *         Copyright (c), NXP Semiconductors
 *
 *       All rights are reserved. Reproduction in whole or in part is
 *      prohibited without the written consent of the copyright owner.
 *  NXP reserves the right to make changes without notice at any time.
 * NXP makes no warranty, expressed, implied or statutory, including but
 * not limited to any implied warranty of merchantability or fitness for any
 *particular purpose, or that the use will not infringe any third party patent,
 * copyright or trademark. NXP must not be liable for any loss or damage
 *                          arising from its use.
 */

/*==============================================================================================
 *
 *   File name:  hw_config.c
 *
 *  Created on:
 *      Author: nxp62726
 *
 *     Hystory:
 */

/*----------------------------------------------------------------------------------------------
 * Includes
 ---------------------------------------------------------------------------------------------*/
#include <xc.h>
#include <ph_TypeDefs.h>
#include <ph_Status.h>
#include <phhalHw.h>
#include <phbalReg.h>

#include <phbalReg_Stub.h>

#include <ph_NxpBuild.h>
#include <ph_Status.h>
#include <phOsal.h>

#include "phhwConfig.h"


//TODO - microchip impl replace PERI
#define GPIO_GetIntStatus(a,b,c) 0
#define GPIO_SetDir(a,b,c) Nop()
#define GPIO_SetValue(a,b) Nop() 
#define GPIO_ClearValue(a,b) Nop() 
#define GPIO_IntCmd(a,b,c) Nop() 
#define GPIO_ReadValue(a)   0   //Nop() 
#define GPIO_ClearInt(a,b) Nop() 


/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/
#if defined (NXPBUILD__PHHAL_HW_RC523) && defined (NXPBUILD__PHHAL_HW_RC663)
#error ** Mismatch reader device - PN512 and RC663 are enabled together **
#endif

#define BLUEBOARD_RC663_VER_3_0
//#define BLUEBOARD_RC663_VER_5_0

#if defined (BLUEBOARD_RC663_VER_5_0) && defined (BLUEBOARD_RC663_VER_3_0)
#error ** Mismatch reader device - Blueboard RC663 version 3.0 and 5.0 together **
#endif


/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Local function declaration
 ---------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global function prototypes
 ---------------------------------------------------------------------------------------------*/


/* **************************************
 * Initialize interface link            *
 * **************************************/

/* =============================================================================================
 * Function:    Set_Interface_Link
 *
 * brief:
 *   Initialize interface link
 *   GPIOSetDir sets the direction in GPIO port.
 *   1 out, 0 input
 *
 *   GPIOSetValue sets/clears a bitvalue in a specific bit position
 *   in GPIO portX(X is the port number.)
 *   Our RC523 will act in slave mode. START and STOP conditions are
 *   generated by the master.
 *
 * -------------------------------------------------------------------------------------------*/
void Set_Interface_Link(void)
{

#if defined NXPBUILD__PHHAL_HW_RC523
#ifdef SPI_USED
    /* note any pinout setting from reason the PNEV512B has interface setting realized
     * by solder resistors on the PCB
     */
#endif /* SPI_USED */
#ifdef I2C_USED

        /* Set direction of pins as output to set for I2C address of attached reader */
        GPIO_SetDir(PORT0, PIN_AD0, SET_OUT);
        GPIO_SetDir(PORT0, PIN_AD1, SET_OUT);
        GPIO_SetDir(PORT0, PIN_AD2, SET_OUT);

        /* Set PN512 I2C address to 0x50 */
        GPIO_ClearValue(PORT0, PIN_AD0);
        GPIO_ClearValue(PORT0, PIN_AD1);
        GPIO_ClearValue(PORT1, PIN_AD2);
#endif /* I2C_USED */
#endif /* NXPBUILD__PHHAL_HW_RC523 */

#if defined NXPBUILD__PHHAL_HW_RC663
#ifdef SPI_USED

    /* Set port pin P2.4 - IFSEL0 to output */
    GPIO_SetDir(PORT2, PIN_IFSEL0, SET_OUT);

    /* Set port pin P2.5 - IFSEL1 to output */
    GPIO_SetDir(PORT2, PIN_IFSEL1, SET_OUT);

    /* Select SPI link -> IFSEL0 = 0 & IFSEL1 = 1 */
    /* IFSEL0 = 0 */
    GPIO_ClearValue(PORT2, PIN_IFSEL0);

    /* IFSEL1 = 1 */
    GPIO_SetValue(PORT2, PIN_IFSEL1);

    /* Set port pin P0.17 - I2C address bit AD0 to output */
    /* AD0 = 0 */
    GPIO_SetDir(PINSEL_PORT_0, (1 << 17), SET_OUT);

#endif /* SPI_USED */

#ifdef I2C_USED

    /* Set port pin P2.4 - IFSEL0 to output */
    GPIO_SetDir(PORT2, PIN_IFSEL0, SET_OUT);

    /* Set port pin P2.5 - IFSEL1 to output */
    GPIO_SetDir(PORT2, PIN_IFSEL1, SET_OUT);

    /* Select I2C link -> IFSEL0 = 1 & IFSEL1 = 0 */
    /* IFSEL0 = 1 */
    GPIO_SetValue(PORT2, PIN_IFSEL0);

    /* IFSEL1 = 0 */
    GPIO_ClearValue(PORT2, PIN_IFSEL1);

    /* Set port pin P0.17 - I2C address bit AD0 to output */
    GPIO_SetDir(PORT0, PIN_AD0, SET_OUT);

    /* Set port pin P0.15 - I2C address bit AD1 to output */
    GPIO_SetDir(PORT0, PIN_AD1, SET_OUT);

    /* Select I2C adresss -> AD0 = AD1 = 0 */
    /* AD0 = 0 */
    GPIO_ClearValue(PORT0, PIN_AD0);

    /* AD1 = 0 */
    GPIO_ClearValue(PORT0, PIN_AD1);
#endif /* I2C_USED */

#endif /* NXPBUILD__PHHAL_HW_RC663 */
}

/*==============================================================================================
 * Function: IRQ Pin Connection Check b/w LPC1769 and Pn512
 *
 * brief:    Used to check if Pn512 IRQ Pin is connected to LPC1769 External Interrupt 3 (EInt-3).
 *
 * @return:  PH_ON(1)  - IRQ Pin is NOT connected.
 *           PH_OFF(0) - IRQ Pin is connected.
 * -------------------------------------------------------------------------------------------*/
void Check_Pn512IRQ_LPC1769(void)
{
    uint32_t volatile i;
    uint32_t wPort2_Last = 0;
    uint32_t wPort2 = 0;

    /* Setting LPC P2-13 pin as an Input. */
    GPIO_SetDir(2,1<<13,0);

    /* Setting LPC P0-28 pin as an Output. */
    GPIO_SetDir(0,1<<28,1);

    /* Writing 0 to port0 28th pin*/
    GPIO_ClearValue(0,1<<28);

    /* delay of 1 ms */
    for (i = 0x2800; i > 0; i --);

    wPort2_Last = GPIO_ReadValue(2);

    /* Writing 1 to port0 28th pin*/
    GPIO_SetValue(0,1<<28);

    /* delay of 1 ms */
    for (i = 0x2800; i > 0; i --);

    wPort2 = GPIO_ReadValue(2);

    if(wPort2 == wPort2_Last)
    {
        /* IRQ Pin is NOT connected properly. */
        DEBUG_PRINTF("\nPn512 IRQ Pin is NOT connected to LPC1769 External Interrupt 3 (EInt-3).\nPlease solder Pn512 Board as mentioned in the Release Notes.\n");
        DEBUG_PRINTF("\n\n    Execution Halted.......    \n");
        while(1);
    }
    else
    {
        /* Clear and Reset the Port0-28 pin. */

        /* Writing 0 to port0 28th pin*/
        GPIO_ClearValue(0,1<<28);

        /* Setting LPC P0-28 pin as an Input. */
        GPIO_SetDir(0,1<<28,0);
    }
}

/*==============================================================================================
 * Function:    Reset_reader_device
 *
 * brief:   This function resets an attached reader IC. In PIN_RESET macro is a correct pin .
 *
 * -------------------------------------------------------------------------------------------*/
void Reset_reader_device(void)
{
uint32_t volatile i;

#if defined NXPBUILD__PHHAL_HW_RC523
    /* Reset for PN512 is 1-0-1 */
    /* NRST_512 = P0.27 */
    /* Set port pin to output */
    GPIO_SetDir(PINSEL_PORT_0, PIN_RESET, SET_OUT);

    /* RSET signal high */
    GPIO_SetValue(PINSEL_PORT_0, PIN_RESET);

    /* delay of 1 ms */
    for (i = 0x2800; i > 0; i --);

    /* RSET signal low to Reset PN512 */
    GPIO_ClearValue(PINSEL_PORT_0, PIN_RESET);

    /* delay of 1 ms */
    for (i = 0x2800; i > 0; i --);

    /* RSET signal high */
    GPIO_SetValue(PINSEL_PORT_0, PIN_RESET);

    /* delay of 1 ms */
    for (i = 0x2800; i > 0; i --);
#endif
#if defined NXPBUILD__PHHAL_HW_RC663
    /* Set port pin - PDOWN to output */
    GPIO_SetDir(PORT0, PIN_RESET, SET_OUT );

    /* send the reset pulse 0-1-0 to reset device */
    /* RSET signal low - PDOWN to '0' */
    GPIO_ClearValue(PORT0, PIN_RESET);

    /* delay of ~1,2 ms */
    for (i = 0x2800; i > 0; i --);

    /* RSET signal high to reset the RC663 IC - PDOWN to '1' */
    GPIO_SetValue(PORT0, PIN_RESET);

    /* delay of ~1,2 ms */
    for (i = 0x2800; i > 0; i --);

    /* RSET signal low - PDOWN to '0' */
    GPIO_ClearValue(PORT0, PIN_RESET);

    /* delay of ~1,2 ms */
    for (i = 0x2800; i > 0; i --);

#endif
}
/* **************************************
 * handle GPIO                          *
 * **************************************/

/*==============================================================================================
 * Function:    GPIO_Init
 *
 * brief:
 *
 * -------------------------------------------------------------------------------------------*/
void GPIO_Init(void)
{
    /* there is a different name for the GPIO driver module for each LPC processor which comes
     * from drivers.
     * GPIO interface is consolidated via this function calling.
     */

    /* this is empty function for LPC1769 */
    /* GPIOInit(); */
}

/*==============================================================================================
 * Function:    Set_Port
 *
 * brief:
 *
 * -------------------------------------------------------------------------------------------*/
void Set_Port(void)
{
#ifndef TUSA
    /* Set LED port pin to output */
    GPIO_SetDir( LED_PORT, LED_BIT, SET_OUT );
#endif
}

/*==============================================================================================
 * Function:    LedOn
 *
 * brief:   switch the LED on
 *
 * -------------------------------------------------------------------------------------------*/
void LedOn(void)
{
    GPIO_SetValue( LED_PORT, LED_BIT );
}

/*==============================================================================================
 * Function:    LedOff
 *
 * brief:   switch the LED off
 *
 * -------------------------------------------------------------------------------------------*/
void LedOff(void)
{
    GPIO_ClearValue( LED_PORT, LED_BIT );
}

#ifdef NXPBUILD__PHHAL_HW_RC523
/*==============================================================================================
 * Data structure dedicated to keep important data from application.
 *
 * params:      pHal    [in]    Pointer to RdLib HAL data parameter component. Its used to handle
 *                              registers of reader IC when configured the interrupts by the Set_Interrupt()
 *                              function.
 *              pOsal   [in]    Pointer to OSAL parameter component. Necessary to call a correct
 *                              application callback from within timer interrupt handler.
 *              pData   [in]    Pointer to data from the application. The data are expected to be
 *                              handled within IRQ handlers of this project.
 * -------------------------------------------------------------------------------------------*/
static struct
{
    void            *pHal;
    void            *pOsal;
    volatile void   *pData_ready;
    volatile void   *pExitLoopback;
}appData;

/*==============================================================================================
 * Function:    appDataInit
 *
 * brief:       This function configures pin IRQ on MCU side and IRQ generation on reader IC.
 *              In result dedicated interrupt requests from reader IC are escalated to the host MCU.
 *              The function is used by NFC Target.
 *
 * params:      pHal    [in]    Pointer to RdLib HAL data parameter component. Its used to handle
 *                              registers of reader IC when configured the interrupts by the Set_Interrupt()
 *                              function.
 *              pOsal   [in]    Pointer to OSAL parameter component. Necessary to call a correct
 *                              application callback from within timer interrupt handler.
 *              pData   [in]    Pointer to data from the application. The data are expected to be
 *                              handled within IRQ handlers of this project. *
 * -------------------------------------------------------------------------------------------*/
void appDataInit( void  *pHal,
                  void  *pOsal,
                  void  *pData,
                  void  *pExitLoopback)
{
    appData.pHal              = pHal;
    appData.pOsal             = pOsal;
    appData.pData_ready       = pData;
    appData.pExitLoopback     = pExitLoopback;

    return;
}
#endif /* NXPBUILD__PHHAL_HW_RC523 */
/*==============================================================================================
 * Function:    Set_Interrupt
 *
 * brief:       This function is called when interrupt from attached PN512 IC occurs.
 *              It resets MCU and reader IC to state to be able to detect another IRQ.
 *
 * -------------------------------------------------------------------------------------------*/
void Set_Interrupt(void)
{
#if defined NXPBUILD__PHHAL_HW_RC523
    /* Enable IRQ Interrupts */
    __enable_irq();

    GPIO_ClearInt(2, 1<<13);

    /* Enable External Interrupt */
    NVIC_EnableIRQ(EINT3_IRQn);

    /* Configure the LPC17xx GPIO 2.13 as Interrupt input */
    GPIO_SetDir(2, 1<<13, 0);

    /* Enable receiving interrupt on the pin */
    GPIO_IntCmd(2, 1<<13, 1);

    GPIO_ClearInt(2, 1<<13);

    return;
#endif
#if defined NXPBUILD__PHHAL_HW_RC663
    /* Enable IRQ Interrupts */
    __enable_irq();

    /* Enable External Interrupt */
 //   NVIC_EnableIRQ(EINT3_IRQn);
    
#if defined BLUEBOARD_RC663_VER_3_0
    /* Configure the LPC17xx GPIO 2.12 as Interrupt input */
    GPIO_SetDir(2, 1<<12, 0);

    /* Enable receiving interrupt on the pin */
    GPIO_IntCmd(2, 1<<12, 1);

    GPIO_ClearInt(2, 1<<12);
#endif

#if defined BLUEBOARD_RC663_VER_5_0
    /* Configure the LPC17xx GPIO 2.12 as Interrupt input */
    GPIO_SetDir(PORT0, 1<<2, 0);

    /* Enable receiving interrupt on the pin */
    GPIO_IntCmd(PORT0, 1<<2, 1);

    GPIO_ClearInt(PORT0, 1<<2);
#endif
    return;
#endif
}

/*==============================================================================================
 * Function:    PN512_IRQHandler
 *
 * brief:   Pin of interrupt EINT3 is attached to interrupt output pin of PN512. The purpose of
 *              this interrupt handler is to detect RF signal from an External Peer .
 *
 * -------------------------------------------------------------------------------------------*/
void PN512_IRQHandler()
{
    uint32_t    regVal;
    uint16_t    status = 0;

#if defined NXPBUILD__PHHAL_HW_RC523
    /* Read the interrupt status of GPIO 2.13 */
    regVal = GPIO_GetIntStatus(2, 13, 1);
    if (regVal == 1)
    {
        status = phOsal_Event_Post(E_PH_OSAL_EVT_RF, E_PH_OSAL_EVT_SRC_ISR, E_PH_OSAL_EVT_DEST_HAL);
        CHECK_STATUS(status);
        GPIO_ClearInt(2, 1<<13);
    }

    return;
#endif
#if defined NXPBUILD__PHHAL_HW_RC663
    /* Read the interrupt status of GPIO 2.13 */
#if defined BLUEBOARD_RC663_VER_3_0
    regVal = GPIO_GetIntStatus(2, 12, 1);
    if (regVal == 1)
    {
        status = phOsal_Event_Post(E_PH_OSAL_EVT_RF, E_PH_OSAL_EVT_SRC_ISR, E_PH_OSAL_EVT_DEST_HAL);
        CHECK_STATUS(status);
        GPIO_ClearInt(2, 1<<12);
    }
#endif

#if defined BLUEBOARD_RC663_VER_5_0
    regVal = GPIO_GetIntStatus(PORT0, 2, 1);
    if (regVal == 1)
    {
        status = phOsal_Event_Post(E_PH_OSAL_EVT_RF, E_PH_OSAL_EVT_SRC_ISR, E_PH_OSAL_EVT_DEST_HAL);
        CHECK_STATUS(status);
        GPIO_ClearInt(PORT0, 1<<2);
    }
#endif

    return;
#endif
}

/*----------------------------------------------------------------------------------------------
 * End of file
 ---------------------------------------------------------------------------------------------*/
