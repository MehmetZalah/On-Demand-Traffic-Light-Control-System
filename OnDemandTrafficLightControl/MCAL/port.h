/*
 * port.h
 *
 * Created: 9/14/2022 6:12:24 AM
 *  Author: MohamedSalah
 */ 

#ifndef PORT_H_
#define PORT_H_

#include "registers.h"

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_D
}tPORT_x;

/* Set Custom Names for ATMega32 Registers */
#define DIRECTION_REGISTER_A			DDRA
#define DIRECTION_REGISTER_B			DDRB
#define DIRECTION_REGISTER_D			DDRD

#define PIN_REGISTER_A					PINA
#define PIN_REGISTER_B					PINB
#define PIN_REGISTER_D					PIND

#define TIMER_0_CONTROL_REGISTER		TCCR0
#define TIMER_0_COUNTER_REGISTER		TCNT0
#define TIMER_INTERRUPT_FLAG_REGISTER	TIFR				

#define PORT_REGISTER_A					PORTA
#define PORT_REGISTER_B					PORTB
#define PORT_REGISTER_D					PORTD

/* Define CARS LEDs Ports */
#define CARS_LED_GREEN_PORT				PORT_A
#define CARS_LED_YELLOW_PORT			PORT_A
#define CARS_LED_RED_PORT				PORT_A

/* Define CARS LEDs PIN Connection */
#define CARS_LED_GREEN_PIN				0
#define CARS_LED_YELLOW_PIN				1
#define CARS_LED_RED_PIN				2

/* Define PEDESTRIANS LEDs Ports */
#define PEDESTRIANS_LED_GREEN_PORT		PORT_B
#define PEDESTRIANS_LED_YELLOW_PORT		PORT_B
#define PEDESTRIANS_LED_RED_PORT		PORT_B

/* Define PEDESTRIANS LEDs PIN Connection */
#define PEDESTRIANS_LED_GREEN_PIN		0
#define PEDESTRIANS_LED_YELLOW_PIN		1
#define PEDESTRIANS_LED_RED_PIN			2

/* Define PEDESTRIANS BTN Port */
#define BTN_PEDESTRIANS_PORT			PORT_D

/* Define PEDESTRIANS BTN PIN Connection */
#define BTN_PEDESTRIANS_PIN				2

#endif /* PORT_H_ */