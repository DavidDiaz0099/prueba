
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
/*================================================================================================*/
#include "HAL/MPC5606B.h"                          //This is the header file describing the register
                               //set for MPC560xBx family of MCUs. It supports the following devices.

#include "HAL/GPIO.h"                               //Configuration of input push buttons and macros.
#include "HAL/type_definitions.h"                          //Public type header file for the coreHAL.
#include "MAL/Button.h"   //Validation of the debounce of button press and changes the states, based.
                                                          //on the 10 ms restriction for valid press.
#include "MAL/LED.h"    //Turn on the LED bar to indicate the initializacion of the window as closed.
#include "HAL/Exceptions.h"           //Setup of IVPR to point to the EXCEPTION_HANDLERS memory area 
                                                                //defined in the linker command file.
                                                             //Default setup of the IVORxx registers. 
#include "HAL/IntcInterrupts.h"            //Contains defines for utilising the Interrupt Controller
                                //in the MPC56xx/PX MCU families. There are also function prototypes
                                                        //for the common interrupt handling routines.
#include "HAL/PIT.h" //Initialisation and configuration of periodic interrupt timer,set flag for 1ms.
#include "HAL/PLL.h"
#include "MAL/Scheduler.h"                                            //control the task implemented.
#include "Application/Window_Lifter.h"//Definition of functions and periodic times for state machine.

/* Private functions prototypes */
/*============================================================================*/
//void disableWatchdog(void);
//int main(void);

/* Private functions */
/*============================================================================*/
void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}

/*Private finction2 main*/
/*============================================================================*/
int main(void) {
	initModesAndClock();
	initPeriClkGen();				
					/* Disable Watchdog */
					disableWatchdog();
					/*Initialize LEDs, turn on LEDs */
					GPIO_config();
					window_closed();
					/*Initialize Interrupts */
					INTC_InitINTCInterrupts();
					/*Initialize Exception Handlers */
					EXCEP_InitExceptionHandlers();
					PIT_device_init();
					PIT_channel_config(PITCHANNEL_0 );
					PIT_channel_active(PITCHANNEL_0);
					INTC.CPR.B.PRI=0;
					INTC_InstallINTCInterruptHandler(PIT_channel0_ISR,59,1);  
					/* Install Interrupt routine for this specific channel */
					init_Counters();
					Sch_Ex();
  /* Loop forever */
  for (;;) {
  }
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */



