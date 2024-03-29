/***********************************************************************//**
 * @file	: lpc17xx_libcfg.h
 * @purpose	: Library configuration file
 * @version	: 1.0
 * @date	: 26. Mar. 2009
 * @author	: HieuNguyen
 **************************************************************************
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * products. This software is supplied "AS IS" without any warranties.
 * NXP Semiconductors assumes no responsibility or liability for the
 * use of the software, conveys no license or title under any patent,
 * copyright, or mask work right to the product. NXP Semiconductors
 * reserves the right to make changes in the software without
 * notification. NXP Semiconductors also make no representation or
 * warranty that such application will be suitable for the specified
 * use without further testing or modification.
 **************************************************************************/

#ifndef LPC17XX_LIBCFG_H_
#define LPC17XX_LIBCFG_H_

#include "lpc_types.h"


#define _GPIO			0x01

#define _UART			0x01
#define _UART0			0x01
#define _UART1			0x01
#define _UART2			0x01
#define _UART3			0x01

#define _SSP			0x01

#define _I2C			0x01
#define _PWM			0x01
#define _TIM			0x01

#ifdef  DEBUG
/*******************************************************************************
* @brief		The CHECK_PARAM macro is used for function's parameters check.
* 				It is used only if the library is compiled in DEBUG mode.
* @param[in]	expr - If expr is false, it calls check_failed() function
*                    	which reports the name of the source file and the source
*                    	line number of the call that failed.
*                    - If expr is true, it returns no value.
* @return		None
*******************************************************************************/
#define CHECK_PARAM(expr) ((expr) ? (void)0 : check_failed((uint8_t *)__FILE__, __LINE__))
#else
#define CHECK_PARAM(expr)
#endif /* DEBUG */

/************************** GLOBAL/PUBLIC FUNCTION DECLARATION *********************************/

#ifdef  DEBUG
void check_failed(uint8_t *file, uint32_t line);
#endif

#endif /* LPC17XX_LIBCFG_H_ */
