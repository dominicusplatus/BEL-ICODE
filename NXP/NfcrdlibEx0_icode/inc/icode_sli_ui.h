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

#ifndef ICODE_SLI_UI_H
#define ICODE_SLI_UI_H

/*----------------------------------------------------------------------------------------------
 * Includes
----------------------------------------------------------------------------------------------*/
#include <icode_common.h>

/* HAL Headers */
#include <phhalHw.h>

/* PAL Headers */
#include <phpalSli15693.h>

/*AL Headers*/
#include <phalI15693.h>

#ifdef NXPBUILD_SLI_TAG

/*----------------------------------------------------------------------------------------------
 * Global macros and definitions
----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------
 * Global variables
----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------
 * Global function prototypes
----------------------------------------------------------------------------------------------*/
extern phStatus_t MainMenu_SLI(void *pHal, void *pPlatform);

#endif // NXPBUILD_SLI_TAG

#endif // ICODE_SLI_UI_H
/*----------------------------------------------------------------------------------------------
 * End of file
----------------------------------------------------------------------------------------------*/
