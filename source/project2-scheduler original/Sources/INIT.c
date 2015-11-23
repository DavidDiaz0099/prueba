/*
 * INIT.c
 *
 *  Created on: Nov 12, 2015
 *      Author: HP 240
 */

#include "INIT.h"

void INIT()
{
	char count1;
	/* Initialise PLL before turning it on: */

	ME.RUN[0].R = 0x001F0074;       	/* RUN0 cfg: 16MHzIRCON,OSC0ON,PLL0ON,syclk=PLL */
	
	ME.RUNPC[0].R    = 0x00000010; 	  	/* Peri. Cfg. 0 settings: only run in RUN0 mode */
	ME.PCTL[SW1].R   = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	ME.PCTL[SW2].R   = 0x0000;
	ME.PCTL[SW3].R   = 0x0000;
	ME.PCTL[SW4].R   = 0x0000;
	ME.PCTL[LED_1].R = 0x0000;         	/* MPC56xxB/S SIUL:  select ME.RUNPC[0] */	
	ME.PCTL[LED_2].R = 0x0000;
	ME.PCTL[LED_3].R = 0x0000;
	ME.PCTL[LED_4].R = 0x0000;
										/* Mode Transition to enter RUN0 mode: */
	ME.MCTL.R = 0x40005AF0;         	/* Enter RUN0 Mode & Key */
	ME.MCTL.R = 0x4000A50F;         	/* Enter RUN0 Mode & Inverted Key */  

	
/*  INIT BUTTONS BOARD                      */
	for(count1 = 64; count1 <= 67; count1++)
	{
		SIU.PCR[count1].R = 0x0101;
		
	}
/*********************************************/
	
	
/*  INIT LEDS BOARD                        */
	for(count1 = 68; count1 <= 71; count1++)
		{
			SIU.PCR[count1].R = 0x0200;
			SIU.GPDO[count1].B.PDO = 1;
		}
/*********************************************/
	
	
/*  INIT OUTPUTS IN PORTA                    */
	for(count1 = 0; count1 <= 12; count1++)
			{
				SIU.PCR[count1].R = 0x0200;
				SIU.GPDO[count1].B.PDO = 0;
			}				
/*********************************************/	
}





