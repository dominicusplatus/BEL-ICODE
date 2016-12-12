==============================================================================
Readme - Software for the CLEV663B Blueboard 3.0

==============================================================================

1. Document purpose
-------------------
This document describes the steps to be followed to execute the ICODE-SLI/ILT example package as well as known problems 
and restrictions.

This example will demonstrate inventorying, reading and writing ICODE-SLI/ILT tags. 

2. Restrictions
---------------
a) The Software is restricted to CLEV663B Blueboard with Cortex M3 LPC1769 micro-controller from NXP. The APIs are intended 
   for NXP contact-less reader ICs only, as such the APIs are not to be ported to any technology from any other vendor.
b) NXP will not support porting to any other vendor platform. 
c) This software project requires NFC Reader Library version 3.062.
d) To compile and execute this project, you also need NxpNfcRdLib project and the LPC1769 MCU project to be imported in the 
   LPCXpresso Workspace.

3. Package contains:
--------------------
�   .cproject
�   .project
�   src
�	inc
�   Readme.txt (this readme file) 

4. Mandatory material, not included
-----------------------------------
a) LPCXpresso IDE as described on the web site:
    http://www.lpcware.com/lpcxpresso
b) LPCXpresso LPC1769 development board with CLEV663B Blueboard.

5. Hardware Pin Configuration:
------------------------------
a) Before starting the application ensure the following hardware change has been done on the
   CLEV663B 3.0 board - R35 need to be de-soldered and placed to the pads of R34. This is needed to connect
   the IRQ pin of the CLRC663 to the correct GPIO of the micro-controller.

6. Software Configuration:
--------------------------
    The Software can be compiled for Cortex M3 LPC1769 micro-controller from NXP only.
	
7. Steps to follow:
-------------------
Step 1: Opening the package in LPCXpresso
a) For running this application, connect the system comprising of LPC1769 and CLEV663B board to the PC.
b) Create a new LpcXpresso workspace and import this project along with NxpNfcRdLib and Lpc1769 Project to get it compiled.
c) Build the project
d) Start the "Debug" session of LPCXpresso which will first flash the executable and start the task.
e) When this application is running on LPC1769+CLEV663B setup, one will see a minimalistic user interface guiding the user
   through the different options of the example.


==============================================================================
Software usage is restricted to following hardware:

	CLEV663B Blueboard 3.0
	RC663 Board v5.0 	(Blueboard - Hamburg 2013)
	LPCXpresso LPC1769

==============================================================================

*--------------------------*
*   RC663 Blueboard v5.0   *
*--------------------------*

- this part describes only HW setting of the RC663 Blueboard 5.0

8. Hardware Configuration:
--------------------------
a) setting of the SPI, I2C or UART communication interface is described in document AN11506.

b) CLEV663B 5.0's GPIO P1_4 (pin #20) and P1_5 (pin #21) have to be connected together. The best method is to solder a bridge between these pins directly on the Blueboard.
   This connection causes that IRQ signal of CLRC663 is connected to the LPCXpresso LPC1769 from GPIO P1_31 to the GPIO P0_2. This cross connection is necessary
   because LPC1769 could handle external interrupts only from PORT_0 and PORT_2 (see chapter 13).

9. Software setting:
---------------------
a) Based on the cross connection from point 8.b), it is necessary to make one change to the software. 
   Changes are touched only Lpc1769/phhwConfig.c source file.
   Comment #define BLUEBOARD_RC663_VER_3_0
   and uncomment #define BLUEBOARD_RC663_VER_5_0