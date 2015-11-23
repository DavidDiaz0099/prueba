/*
 * button.c
 *
 *  Created on: Nov 20, 2015
 *      Author: PUG
 */
/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: button.c $
 * $Revision: A $
 * $Author: DAVID ANTONIO DIAZ RAMIREZ $
 * 			FRANCISCO JAVIER QUIRARTE PELAYO $ 
 * $Date: 19/11/2015 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** Validation of the debounce of button press and changes the states, based
 * on the 10 ms restriction for valid press
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     | Window Lifter with Scheduler|       1.0              */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: button.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "MAL/button.h"

/* Variables */
/*============================================================================*/
extern T_UWORD rub_State;
static T_UWORD lub_counter_button=0;
extern T_UWORD rub_Movement;
/* Private functions prototypes */
/*============================================================================*/
//void button_validation (void);

/* Private functions */
/*============================================================================*/
void button_validation (void)
{
	
		if((BUTTON_DOWN) && !(BUTTON_UP) && !(ANTI_PINCH))
		{	
			
			lub_counter_button++; /*Increases counter to 10 milliseconds*/
			if(lub_counter_button>=_10_ms) 
			{
				
				rub_Movement=DOWN;
				lub_counter_button=_0_ms;    /* Reset counter*/
				//rub_State=BUTTON_AS_DOWN;
			}
			
			else 
			{
				
				//do_nothing;
			}
		}
				
				
		else if((BUTTON_UP) && !(BUTTON_DOWN))
		{		
			
			lub_counter_button++;  /*Increases counter to 10 milliseconds*/
			if(lub_counter_button>=_10_ms) 
			{
				rub_Movement=UP;
				lub_counter_button=_0_ms;    /* Reset counter*/
				//rub_State=BUTTON_AS_UP;
			}
			
			else
			{
				
				//do_nothing;
			}
		}
		
		else if ((ANTI_PINCH)  && !(BUTTON_DOWN) )
		{
			lub_counter_button++;	            
						if(lub_counter_button>=_10_ms) 
						{
							rub_Movement=PINCH;
							lub_counter_button=_0_ms;  
							//rub_State=ANTIPINCH;
							
						}
						else
						{
							
							//do_nothing;
						}
		}
		else
		{
			
			lub_counter_button=_0_ms;       /* Reset counter*/
			//rub_State=do_nothing;
		}
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */

