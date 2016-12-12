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
 * Example Source for NfcrdlibEx1_BasicDiscoveryLoop.
 * Please refer Readme.txt file  for  Hardware Pin Configuration, Software Configuration and steps to build and
 * execute the project which is present in the same project directory.
 * $Author: nxp62726 $
 * $Revision: 1.0 $
 * $Date: 2014-07-25 15:04:36 +0530 (Fri, 25 Jul 2014) $
 *
 * History:
 * BK: Generated 12. Jun 2014
 * PC: Generated 25. Nov 2012
 *
 */

#include <cr_section_macros.h>
#include <NXP/crp.h>

/**
 * Header for hardware configuration: bus interface, reset of attached reader ID, onboard LED handling etc.
 * */
#include <phhwConfig.h>

/**
 * Reader Library Headers
 */
#include <ph_Status.h>

/* OSAL Headers */
#include <phPlatform.h>

/* HAL Headers */
#include <phhalHw.h>

/* BAL Headers */
#include <phbalReg.h>

/* ILT */
#include <icode_ilt_ui.h>
#include <icode_sli_ui.h>
#include <icode_common.h>

#include <stdio.h>

__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;


/*******************************************************************************
 **   Global Variable Declaration
 *******************************************************************************/
/* HAL variables*/
phhalHw_Rc663_DataParams_t          sHalReader;                // HAL component
uint8_t                             bHalBufferTx[256];         /* HAL TX buffer. Size 256 - Based on maximum FSL */
uint8_t                             bHalBufferRx[256];         /* HAL RX buffer. Size 256 - Based on maximum FSL */

/* BAL variables*/
phbalReg_Stub_DataParams_t          sBalReader;                /* BAL component holder */

/*OSAL variables*/
phPlatform_DataParams_t             sPlatform;	               /* Platform component holder */

/* aplk. variables */
uint8_t                            bString[1];  // global string-charakter variable

/*----------------------------------------------------------------------------------------------
 * Local function prototypes
 ---------------------------------------------------------------------------------------------*/


/* ============================================================================================
 * main
 *
 * ------------------------------------------------------------------------------------------*/
int main (void)
    {
    phStatus_t    status;
    uint8_t       bReg;

    uint8_t       bStayInMenu = 1;
    void          *pHal;

    printf("   ---  ICODE Demo Project  ---\n\n");

    /* Set the interface link for the internal chip communication */
    Set_Interface_Link();

    /* Set LED port pin to output */
    Set_Port();

    /* Ensure, that the LED is off */
    LedOff();

    /* Perform a hardware reset */
    Reset_reader_device();

    Set_Interrupt();

    /* Initialize the Reader BAL (Bus Abstraction Layer) component */
    PH_CHECK_SUCCESS_FCT(status, phbalReg_Stub_Init(&sBalReader, sizeof(phbalReg_Stub_DataParams_t)));

    /* Initialize the Osal Stub component */
    PH_CHECK_SUCCESS_FCT(status, phPlatform_Init(&sPlatform));

    /* Initialize the timer component */
    PH_CHECK_SUCCESS_FCT(status, phPlatform_Timer_Init(&sPlatform));

    /* Initialize the OSAL Events. */
    PH_CHECK_SUCCESS_FCT(status, phOsal_Event_Init());

    /* initialize the 'hardware abstraction layer' HAL: */
    /* use the RC663 Reader IC, glue it together with the BAL component */
    status = phhalHw_Rc663_Init(
          &sHalReader,
          sizeof(phhalHw_Rc663_DataParams_t),
          &sBalReader,
          0,
          bHalBufferTx,
          sizeof(bHalBufferTx),
          bHalBufferRx,
          sizeof(bHalBufferRx)
    );
    CHECK_SUCCESS(status);

    /* Set the parameter to use the SPI interface */
    sHalReader.bBalConnectionType = PHHAL_HW_BUS;

    /* Set the generic pointer */
    pHal = &sHalReader;

    PH_CHECK_SUCCESS_FCT(status, phbalReg_OpenPort(&sBalReader));

    printf("Initialization complete\n");

    PH_CHECK_SUCCESS_FCT(status, phhalHw_Rc663_Cmd_SoftReset(pHal));

    /* Read the version of the reader IC. This software is dedicated for RC663, thus hardware dependent read register can be used. */
    phhalHw_Rc663_ReadRegister(&sHalReader, PHHAL_HW_RC663_REG_VERSION, &bReg);
    printf("The version number of the reader IC is: %02X\n", bReg);

    if(bReg != 0x18)
    	{
    	printf("The version number of the reader IC is INCORRECT.\n"
    			"Please check the connection of the reader and MCU, then relaunch the software.\n");
    	return -1;
    	}

    /* Reset the Rf field */
    PH_CHECK_SUCCESS_FCT(status, phhalHw_FieldReset(pHal));

#if defined NXPBUILD_ILT_TAG && defined NXPBUILD_SLI_TAG

    while ((status == PH_ERR_SUCCESS) && (bStayInMenu))
        {
        printf("\nMain MENU\n"
                "%s\n"
                "1 - ILT tags handling\n"
                "2 - SLI tags handling\n"
                "e - Exit\n",cTableLine);

        Read_String (bString,1);
        switch(bString[0])
            {
            case '1':
                status = MainMenu_ILT(pHal);
                CHECK_STATUS(status);
                break;
            case '2':
                status = MainMenu_SLI(pHal, &sPlatform);
                CHECK_STATUS(status);
                break;
            case 'e':
                bStayInMenu = 0;
                break;
            default:
                printf("Try again\n");
                break;
            }

        /* wait some time (100 milisecond)*/
        status = phPlatform_Timer_Wait(&sPlatform, PH_PLATFORM_TIMER_UNIT_MS, 100);
        CHECK_STATUS(status);
        }
#else

#ifdef NXPBUILD_ILT_TAG
    printf("ILT tags handling\n");
    status = MainMenu_ILT(pHal);
    CHECK_STATUS(status);
#endif

#ifdef NXPBUILD_SLI_TAG
    printf("SLI tags handling\n");
    status = MainMenu_SLI(pHal, &sPlatform);
    CHECK_STATUS(status);
#endif

#endif

    printf("Application has been STOP\n Thank you for your time :-) \n");

    return 0;
    }

/*----------------------------------------------------------------------------------------------
 * End of File
 ---------------------------------------------------------------------------------------------*/



