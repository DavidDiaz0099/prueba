/*
 * Leds.c
 *
 *  Created on: Nov 13, 2015
 *      Author: Frank
 */
#include "Leds.h"

void init_leds (void)
{
	/*initialise outputs for LEDS*/
	SIU.PCR[68].R = 0x0200; /*initialise LED1 from bolero board*/
	SIU.PCR[69].R = 0x0200; /*initialise LED2 from bolero board*/
	SIU.PCR[70].R = 0x0200; /*initialise LED3 from bolero board*/
	SIU.PCR[71].R = 0x0200; /*initialise LED4 from bolero board*/
	
	SIU.GPDO[68].B.PDO = 0;/*initialise LED1 with 0 for security*/
	SIU.GPDO[69].B.PDO = 0;/*initialise LED2 with 0 for security*/
	SIU.GPDO[70].B.PDO = 0;/*initialise LED3 with 0 for security*/
	SIU.GPDO[71].B.PDO = 0;/*initialise LED4 with 0 for security*/
}

