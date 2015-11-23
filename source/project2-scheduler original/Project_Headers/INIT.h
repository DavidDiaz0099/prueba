/*
 * INIT.h
 *
 *  Created on: Nov 12, 2015
 *      Author: HP 240
 */

#ifndef INIT_H_
#define INIT_H_

#include "MPC5606B.h"

//States of switches
#define Button_pressed		0
#define Button_not_pressed	1

//Ports of switches
#define SW1		64
#define SW2		65
#define SW3		66
#define SW4		67

//State of leds
#define LED_on 		1 
#define LED_off		0

//The led bar
#define LED1		0
#define LED2		1
#define LED3		2
#define LED4		3
#define LED5		4
#define LED6		5
#define LED7		6
#define LED8		7
#define LED9		8
#define LED10		9

#define LED_1		68
#define LED_2		69
#define LED_3		70
#define LED_4		71


extern void INIT(void);

#endif /* INIT_H_ */
