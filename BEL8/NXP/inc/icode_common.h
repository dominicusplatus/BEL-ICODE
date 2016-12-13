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

#ifndef ICODE_COMMON_H
#define ICODE_COMMON_H

#include "xc.h"
#include "math.h"

/*----------------------------------------------------------------------------------------------
 * Includes
----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------
 * Global macros and definitions
----------------------------------------------------------------------------------------------*/
#define  NOT_ANY_ACTION                   0x0002U

#if defined (NXPBUILD__PHAL_I15693) && defined (NXPBUILD__PHPAL_SLI15693)
    #define NXPBUILD_SLI_TAG
#endif

#if defined (NXPBUILD__PHAL_I15693) && defined (NXPBUILD__PHPAL_SLI15693) && defined (NXPBUILD__PHAL_SLI)
    #define NXPBUILD_SLIX_2_TAG
#endif

#if defined NXPBUILD__PHAL_I18000P3M3 && defined NXPBUILD__PHPAL_I18000P3M3
    #define NXPBUILD_ILT_TAG
#endif

/* size of buffer used for buffering before printout to speed up printout */
#define SPRINTF_LONG_BUFFER_SIZE					1
#define SPRINTF_SHORT_BUFFER_SIZE					1
/* maximal number of lines - detected tags printout in one bulk. not recommended to change */
#define MAX_NUMBER_OF_LINES_OF_LIST_PER_PRINTOUT    1

/*----------------------------------------------------------------------------------------------
 * Global variables
----------------------------------------------------------------------------------------------*/
extern const uint8_t cTableLine[];
extern const uint8_t cTableLine2[];
extern const uint8_t cTableReturn[];
extern const uint8_t cTableReturnMain[];
extern const uint8_t cHelloWord[];
extern const uint8_t cTryAgain[];
extern const uint32_t bAccessPassword1;
extern const uint32_t bAccessPassword2;
extern const uint32_t cHelloWord_Size;
/*----------------------------------------------------------------------------------------------
 * Global function prototypes
----------------------------------------------------------------------------------------------*/
extern phStatus_t Read_String(uint8_t * pBuffer, uint32_t dwLentgh);

extern uint16_t round(float number);

#endif // ICODE_COMMON_H
/*----------------------------------------------------------------------------------------------
 * End of file
----------------------------------------------------------------------------------------------*/
