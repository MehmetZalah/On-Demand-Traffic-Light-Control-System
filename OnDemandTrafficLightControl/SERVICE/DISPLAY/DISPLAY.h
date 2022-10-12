/*
 * DISPLAY.h
 *
 * Created: 9/28/2022 2:07:31 AM
 *  Author: MohamedSalah
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

typedef enum
{
	DISPLAY_STATE_OFF,
	DISPLAY_STATE_ON,
}tDISPLAY_STATE_x;

typedef enum
{
	LED_CARS_GREEN,
	LED_CARS_YELLOW,
	LED_CARS_RED,
	LED_PEDESTRIANS_GREEN,
	LED_PEDESTRIANS_YELLOW,
	LED_PEDESTRIANS_RED
}tLED_x;

/*
 * Function: DISPLAY_Init
 * ----------------------------
 *	Initialize LED_x with DISPLAY_STATE_x
 *
 *	@param tLED_x: LED_CARS_GREEN,LED_CARS_YELLOW,LED_CARS_RED,LED_PEDESTRIANS_GREEN,LED_PEDESTRIANS_YELLOW,LED_PEDESTRIANS_RED
 *	@param tDISPLAY_STATE_x: DISPLAY_STATE_OFF, DISPLAY_STATE_ON,
 */
void DISPLAY_Init(tLED_x LED_x, tDISPLAY_STATE_x DISPLAY_STATE_x);

/*
 * Function: DISPLAY_SetState
 * ----------------------------
 *	Set LED_x State with DISPLAY_STATE_x
 *
 *	@param tLED_x: LED_CARS_GREEN,LED_CARS_YELLOW,LED_CARS_RED,LED_PEDESTRIANS_GREEN,LED_PEDESTRIANS_YELLOW,LED_PEDESTRIANS_RED
 *	@param tDISPLAY_STATE_x: DISPLAY_STATE_OFF, DISPLAY_STATE_ON,
 */
void DISPLAY_SetState(tLED_x LED_x, tDISPLAY_STATE_x DISPLAY_STATE_x);

/*
 * Function: DISPLAY_Toggle
 * ----------------------------
 *	Toggle LED_x State
 *
 *	@param tLED_x: LED_CARS_GREEN,LED_CARS_YELLOW,LED_CARS_RED,LED_PEDESTRIANS_GREEN,LED_PEDESTRIANS_YELLOW,LED_PEDESTRIANS_RED
 */
void DISPLAY_Toggle(tLED_x LED_x);

/*
 * Function: DISPLAY_ON
 * ----------------------------
 *	Set LED_x State On
 *
 *	@param tLED_x: LED_CARS_GREEN,LED_CARS_YELLOW,LED_CARS_RED,LED_PEDESTRIANS_GREEN,LED_PEDESTRIANS_YELLOW,LED_PEDESTRIANS_RED
 */
void DISPLAY_ON(tLED_x LED_x);

/*
 * Function: DISPLAY_OFF
 * ----------------------------
 *	Set LED_x State Off
 *
 *	@param tLED_x: LED_CARS_GREEN,LED_CARS_YELLOW,LED_CARS_RED,LED_PEDESTRIANS_GREEN,LED_PEDESTRIANS_YELLOW,LED_PEDESTRIANS_RED
 */
void DISPLAY_OFF(tLED_x LED_x);

#endif /* LED_H_ */