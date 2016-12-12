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
 * IcodeILT.c
 *
 *  Created on: 15.4.2015
 *      Author: nxp53811
 */

/*----------------------------------------------------------------------------------------------
 * Includes
 ---------------------------------------------------------------------------------------------*/
#include <ph_Status.h>
//#include <ph_NxpBuild.h>
#include <stdio.h>
#include <icode_common.h>
#include <math.h>


/*----------------------------------------------------------------------------------------------
 * Local macros and definitions
 ---------------------------------------------------------------------------------------------*/
const uint8_t cTableLine[]          = "----------------------------";
const uint8_t cTableLine2[]         = "...............";
const uint8_t cTableReturnMain[]    = "r - RETURN to Main Menu";
const uint8_t cTableReturn[]        = "r - RETURN";
const uint8_t cHelloWord[]          = "Hello Word!";
const uint8_t cTryAgain[]           = "Try Again Please.";
const uint32_t bAccessPassword1     = 0x11111111;
const uint32_t bAccessPassword2     = 0x12345678;
const uint32_t cHelloWord_Size      = sizeof(cHelloWord);


/*----------------------------------------------------------------------------------------------
 * Local variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global variables
 * -------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------
 * Global function prototypes
 ---------------------------------------------------------------------------------------------*/

/*==============================================================================================
 * FUNCTION:   Read_String
 *
 * Description:
 *
 ---------------------------------------------------------------------------------------------*/
phStatus_t Read_String(uint8_t * pBuffer, uint32_t dwLentgh)
    {
    uint32_t i = 0;
    uint32_t j = 0;
    uint8_t bCharacter;

    printf("> ");

    for (i = 0; i < dwLentgh; i++)
        {
        pBuffer[i] = 0;
        }

    while ((bCharacter = fgetc(stdin)) != '\n')
        {
        if (j < dwLentgh)
            {
            pBuffer[j] = bCharacter;
            j++;
            }
        else
            {
            while (fgetc(stdin) != '\n');
            return PH_ERR_SUCCESS;
            }
        }
    printf("\n");

    return PH_ERR_SUCCESS;
    }

/*==============================================================================================
 * FUNCTION:   round
 *
 * Description: Function rounds float numbers in common manner.
 * 				Numbers with decimal part lower than 0.5 to nearest lower integer,
 * 				numbers with decimal part equal and greater than 0.5 to nearest greater integer.
 *
 ---------------------------------------------------------------------------------------------*/
uint16_t round(float number)
{
	uint16_t result;

	if(number - floorf(number) < 0.5)
		result = (uint16_t)floorf(number);
	else
		result = (uint16_t)ceilf(number);

	return result;
}
/* ---------------------------------------------------------------------------------------------
 *   End of File
 ---------------------------------------------------------------------------------------------*/

