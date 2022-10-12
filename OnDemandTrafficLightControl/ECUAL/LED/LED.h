/*
 * LED.h
 *
 * Created: 9/14/2022 6:08:45 AM
 *  Author: MohamedSalah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/GPIO/GPIO.h"

typedef enum
{
	LED_STATUS_SUCCESS,
	LED_STATUS_ERROR
}tLED_STATUS_x;

/*
 * Function: LED_Init
 * ----------------------------
 *	Initialize PORT PIN
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: 	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tLED_STATUS_x: LED_STATUS_SUCCESS, LED_STATUS_ERROR
 */
tLED_STATUS_x LED_Init(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);

/*
 * Function: LED_SetState
 * ----------------------------
 *	Set PORT PIN HIGH/LOW
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tLED_STATUS_x: LED_STATUS_SUCCESS, LED_STATUS_ERROR
 */
tLED_STATUS_x LED_SetState(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n,tGPIO_STATE_x GPIO_STATE_x);

/*
 * Function: LED_Toggle
 * ----------------------------
 *	Toggle PORT PIN
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tLED_STATUS_x: LED_STATUS_SUCCESS, LED_STATUS_ERROR
 */
tLED_STATUS_x LED_Toggle(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);

#endif /* LED_H_ */