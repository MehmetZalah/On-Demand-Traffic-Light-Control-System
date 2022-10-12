/*
 * cars.c
 *
 * Created: 9/14/2022 9:42:22 AM
 *  Author: MohamedSalah
 */ 
#include "../App.h"
#include "../../SERVICE/DISPLAY/DISPLAY.h"
#include "../../SERVICE/SWITCH/SWITCH.h"
#include "../../SERVICE/TIME/time.h"
#include "cars.h"

extern tMODE_x currentMode;

static tCarsStateHandler carsStateHandler =
{
	.previousState = CARS_STATE_YELLOW, .currentState = CARS_STATE_GREEN, .nextState = CARS_STATE_GREEN
};

/*
 * Function: CARS_Init
 * ----------------------------
 *	Initialize Cars Traffic Light Module
 *
 *	@param void
 */
void CARS_Init(void)
{
	/* Initialize Cars Traffic LEDs with state OFF */
	
	DISPLAY_Init(LED_CARS_GREEN, DISPLAY_STATE_OFF);
	DISPLAY_Init(LED_CARS_YELLOW, DISPLAY_STATE_OFF);
	DISPLAY_Init(LED_CARS_RED, DISPLAY_STATE_OFF);
}

/*
 * Function: CARS_RunState
 * ----------------------------
 *	Turn ON/OFF Cars Traffic LEDs Depending on State
 *
 *	@param CARS_STATE_x: CARS_STATE_GREEN,CARS_STATE_YELLOW,CARS_STATE_RED
 */
void CARS_RunState(tCARS_STATE_x CARS_STATE_x)
{
	/* Display LEDs ON/OFF Depending on CARS_STATE_x */
	
	switch(CARS_STATE_x)
	{
		case CARS_STATE_GREEN:
		
			DISPLAY_ON(LED_CARS_GREEN);
			DISPLAY_OFF(LED_CARS_YELLOW);
			DISPLAY_OFF(LED_CARS_RED);
			break;
			
		case CARS_STATE_YELLOW:
		
			DISPLAY_OFF(LED_CARS_GREEN);
			DISPLAY_Toggle(LED_CARS_YELLOW);
			DISPLAY_OFF(LED_CARS_RED);
			break;
			
		case CARS_STATE_RED:
		
			DISPLAY_OFF(LED_CARS_GREEN);
			DISPLAY_OFF(LED_CARS_YELLOW);
			DISPLAY_ON(LED_CARS_RED);
			break;
	}
}

/*
 * Function: CARS_UpdateTraffic
 * ----------------------------
 *	Update Cars Traffic State periodically
 *
 *	@param void
 */
void CARS_UpdateTraffic(void)
{
	/* Change States after 5 Secs */
	switch(carsStateHandler.nextState)
	{
		case CARS_STATE_GREEN:
		
			carsStateHandler.currentState = CARS_STATE_GREEN;
			
			CARS_RunState(CARS_STATE_GREEN);
			
			/* Switch to next State if 5 seconds passed */
			if(TIME_SecondsElapsed() == FIVE_SECOND)
			{
				CARS_SetState(CARS_STATE_YELLOW);				
				currentMode = MODE_NORMAL;
			}
			
			break;
		
		case CARS_STATE_YELLOW:
		
			carsStateHandler.currentState = CARS_STATE_YELLOW;
		
			CARS_RunState(CARS_STATE_YELLOW);

			/* Switch to next State if 5 seconds passed */
			if(TIME_SecondsElapsed() == FIVE_SECOND)
			{	
				/* Depend on previousState take next state */
				tCARS_STATE_x nextState = (carsStateHandler.previousState == CARS_STATE_GREEN)? CARS_STATE_RED : CARS_STATE_GREEN;
				CARS_SetState(nextState);
				
				currentMode = MODE_NORMAL;
			}
			
			break;
			
		case CARS_STATE_RED:
			
			carsStateHandler.currentState = CARS_STATE_RED;
			
			CARS_RunState(CARS_STATE_RED);
			
			/* Switch to next State if 5 seconds passed */
			if(TIME_SecondsElapsed() == FIVE_SECOND)
			{
				CARS_SetState(CARS_STATE_YELLOW);								
				currentMode = MODE_NORMAL;
			}			
			break;
	}
}

/*
 * Function: CARS_SetState
 * ----------------------------
 *	Set CARS next state depending on current & previous state
 *
 *	@param CARS_STATE_x: CARS_STATE_GREEN,CARS_STATE_YELLOW,CARS_STATE_RED
 */
void CARS_SetState(tCARS_STATE_x CARS_STATE_x)
{
	/* Set Next State depending on Current & previous state*/	
	switch(carsStateHandler.currentState)
	{
		case CARS_STATE_GREEN:
			carsStateHandler.previousState = carsStateHandler.currentState;
			carsStateHandler.nextState = CARS_STATE_x;
			break;
		
		case CARS_STATE_YELLOW:
		
			if(currentMode == MODE_PEDESTRIANS)
			{
				carsStateHandler.previousState = CARS_STATE_GREEN;
			}
			carsStateHandler.nextState = CARS_STATE_x;
			break;
			
		case CARS_STATE_RED:
			carsStateHandler.previousState = carsStateHandler.currentState;
			carsStateHandler.nextState = CARS_STATE_x;
			break;
	}
}

/*
 * Function: CARS_GetState
 * ----------------------------
 *	Get Cars Current State
 *
 *	@param void
 *	@return tCARS_STATE_x: CARS_STATE_GREEN,CARS_STATE_YELLOW,CARS_STATE_RED
 */
tCARS_STATE_x CARS_GetState(void)
{
	return carsStateHandler.currentState;
}