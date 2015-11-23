/*
 * Timer.c
 *
 *  Created on: Nov 1, 2015
 *      Author: Oswaldo Garcia (Hugol)
 */

//Headers used
#include "Timer.h"

int tickflag=0;

/*Functions for use the timer*/

//Function timer configurations
void STM_config_clock(void)
{
	STM.CNT.R = 0;   //initialise counter 
	STM.CH[0].CMP.R = 0xFA00;  //0xFA00 = 1 millisecond
	STM.CH[0].CCR.B.CEN = 1;
	STM.CR.B.FRZ = 0; //on debugging mode you can see the internal clock
	STM.CR.B.CPS = 0;
	STM.CR.B.TEN = 1;
}

void function_time(void){
	if(STM.CH[0].CIR.B.CIF){
	    STM.CH[0].CIR.B.CIF=1; //resets the flag on channel 0
		tickflag=1;  //rise the flag each 1 millisecond
		STM.CNT.R=0; // resets the counter
		
	}
}
