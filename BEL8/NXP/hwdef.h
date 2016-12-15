/* 
 * File:   hwdef.h
 * Author: rzazo_000
 *
 * Created on 15 grudnia 2016, 17:10
 */

#ifndef HWDEF_H
#define	HWDEF_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "xc.h"
    
    
#define SYS_PERI_CLK                40000000
    

#define SPISRAM_CS_TRIS             (TRISBbits.TRISB14)
#define SPISRAM_CS_IO               (LATBbits.LATB14)

#define SPISRAM_SPI_CLK             1000000

#define SPISRAM__SPI_ID             SPI_CHANNEL1
#define SPISRAM_SSPBUF             (SPI1BUF)
#define SPISRAM_SPICON1            (SPI1CON)
#define SPISRAM_SPICON1bits        (SPI1CONbits)

#define SPI_SRAM_CON_ON_MASK        _SPI1CON_ON_MASK
#define SPI_SRAM_CKE_ON_MASK        _SPI1CON_CKE_MASK
#define SPI_SRAM_MSTEN_ON_MASK      _SPI1CON_MSTEN_MASK

#define SPISRAM_SCK_TRIS           (TRISDbits.TRISD10)
#define SPISRAM_SDI_TRIS           (TRISCbits.TRISC4)
#define SPISRAM_SDO_TRIS           (TRISDbits.TRISD0)

#define SPISRAM_SPIBRG             (SPI1BRG)
#define SPISRAM_SPISTATbits        (SPI1STATbits)
    
  #define SRAM_SPI_ON_BIT          (SPISRAM_SPICON1bits.ON)
 #define SRAM_PROPER_SPICON1  (SPI_SRAM_CON_ON_MASK  | SPI_SRAM_CKE_ON_MASK | SPI_SRAM_MSTEN_ON_MASK)


#ifdef	__cplusplus
}
#endif

#endif	/* HWDEF_H */

