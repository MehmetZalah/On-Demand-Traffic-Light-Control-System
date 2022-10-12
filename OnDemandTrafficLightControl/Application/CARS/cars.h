/*
 * cars.h
 *
 * Created: 9/14/2022 9:42:12 AM
 *  Author: MohamedSalah
 */ 

#ifndef CARS_H_
#define CARS_H_

#include "../../Utilities/types.h"

typedef enum
{
	CARS_STATE_GREEN,
	CARS_STATE_YELLOW,
	CARS_STATE_RED,	
}tCARS_STATE_x;

typedef enum
{
	CARS_LED_GREEN,
	CARS_LED_YELLOW,
	CARS_LED_RED,
}tCARS_LED_x;

typedef struct
{
	tCARS_STATE_x previousState;
	tCARS_STATE_x currentState;
	tCARS_STATE_x nextState;
}tCarsStateHandler;

/*
 * Function: CARS_Init
 * ----------------------------
 *	Initialize Cars Traffic Light Module
 *
 *	@param void
 */
void CARS_Init(void);

/*
 * Function: CARS_RunState
 * ----------------------------
 *	Turn ON/OFF Cars Traffic LEDs Depending on State
 *
 *	@param CARS_STATE_x: CARS_STATE_GREEN,CARS_STATE_YELLOW,CARS_STATE_RED
 */
void CARS_RunState(tCARS_STATE_x CARS_STATE_x);

/*
 * Function: CARS_UpdateTraffic
 * ----------------------------
 *	Update Cars Traffic State periodically
 *
 *	@param void
 */
void CARS_UpdateTraffic(void);

/*
 * Function: CARS_SetState
 * ----------------------------
 *	Set CARS next state depending on current & previous state
 *
 *	@param CARS_STATE_x: CARS_STATE_GREEN,CARS_STATE_YELLOW,CARS_STATE_RED
 */
void CARS_SetState(tCARS_STATE_x CARS_STATE_x);

/*
 * Function: CARS_GetState
 * ----------------------------
 *	Get Cars Current State
 *
 *	@param void
 *	@return tCARS_STATE_x: CARS_STATE_GREEN,CARS_STATE_YELLOW,CARS_STATE_RED
 */
tCARS_STATE_x CARS_GetState(void);

#endif /* CARS_H_ */