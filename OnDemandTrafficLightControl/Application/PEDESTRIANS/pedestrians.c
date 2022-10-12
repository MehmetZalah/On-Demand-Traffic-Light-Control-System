/*
 * pedestrians.c
 *
 * Created: 9/14/2022 9:42:40 AM
 *  Author: MohamedSalah
 */ 
#include "../App.h"
#include "../../SERVICE/DISPLAY/DISPLAY.h"
#include "../../SERVICE/TIME/time.h"
#include "pedestrians.h"

extern tMODE_x currentMode;

static tPedestriansStateHandler pedestriansStateHandler =
{
	.previousState = PEDESTRIANS_STATE_YELLOW,.currentState = PEDESTRIANS_STATE_RED, .nextState = PEDESTRIANS_STATE_RED,
};

/*
 * Function: PEDESTRIANS_Init
 * ----------------------------
 *	Initialize PEDESTRIANS Traffic Light Module
 *
 *	@param void
 */
void PEDESTRIANS_Init(void)
{
	/* Initialize PEDESTRIANS Traffic LEDs with state OFF */
	
	DISPLAY_Init(LED_PEDESTRIANS_GREEN, DISPLAY_STATE_OFF);
	DISPLAY_Init(LED_PEDESTRIANS_YELLOW, DISPLAY_STATE_OFF);
	DISPLAY_Init(LED_PEDESTRIANS_RED, DISPLAY_STATE_OFF);
}

/*
 * Function: PEDESTRIANS_RunState
 * ----------------------------
 *	Turn ON/OFF PEDESTRIANS Traffic LEDs Depending on State
 *
 *	@param PEDESTRIANS_STATE_x: PEDESTRIANS_STATE_GREEN,PEDESTRIANS_STATE_YELLOW,PEDESTRIANS_STATE_RED
 */
void PEDESTRIANS_RunState(tPEDESTRIANS_STATE_x PEDESTRIANS_STATE_x)
{
	/* Display LEDs ON/OFF Depending on PEDESTRIANS_STATE_x */

	switch(PEDESTRIANS_STATE_x)
	{
		case PEDESTRIANS_STATE_GREEN:
		
			DISPLAY_ON(LED_PEDESTRIANS_GREEN);
			DISPLAY_OFF(LED_PEDESTRIANS_YELLOW);
			DISPLAY_OFF(LED_PEDESTRIANS_RED);
			break;
		
		case PEDESTRIANS_STATE_YELLOW:
		
			DISPLAY_OFF(LED_PEDESTRIANS_GREEN);
			DISPLAY_Toggle(LED_PEDESTRIANS_YELLOW);
			DISPLAY_OFF(LED_PEDESTRIANS_RED);
			break;
			
		case PEDESTRIANS_STATE_RED:
		
			DISPLAY_OFF(LED_PEDESTRIANS_GREEN);
			DISPLAY_OFF(LED_PEDESTRIANS_YELLOW);
			DISPLAY_ON(LED_PEDESTRIANS_RED);
			break;
	}
}

/*
 * Function: PEDESTRIANS_UpdateTraffic
 * ----------------------------
 *	Update PEDESTRIANS Traffic State periodically
 *
 *	@param void
 */
void PEDESTRIANS_UpdateTraffic(void)
{
	/* Change States after 5 Secs */
	switch(pedestriansStateHandler.nextState)
	{
		case PEDESTRIANS_STATE_GREEN:
		
			pedestriansStateHandler.currentState = PEDESTRIANS_STATE_GREEN;
		
			PEDESTRIANS_RunState(PEDESTRIANS_STATE_GREEN);
			
			/* Switch to next State if 5 seconds passed */
			if(TIME_SecondsElapsed() == FIVE_SECOND)
			{
				PEDESTRIANS_SetState(PEDESTRIANS_STATE_YELLOW);
			}
		
			break;
		
		case PEDESTRIANS_STATE_YELLOW:
		
			pedestriansStateHandler.currentState = PEDESTRIANS_STATE_YELLOW;
			//pedestriansStateHandler.secCounter++;
		
			PEDESTRIANS_RunState(PEDESTRIANS_STATE_YELLOW);
			
			/* Switch to next State if 5 seconds passed */
			if(TIME_SecondsElapsed() == FIVE_SECOND)
			{
				/* Depend on previousState take next state */
				tPEDESTRIANS_STATE_x nextState = (pedestriansStateHandler.previousState == PEDESTRIANS_STATE_GREEN)? PEDESTRIANS_STATE_RED : PEDESTRIANS_STATE_GREEN;
				PEDESTRIANS_SetState(nextState);
			}
		
			break;
		
		case PEDESTRIANS_STATE_RED:
		
			pedestriansStateHandler.currentState = PEDESTRIANS_STATE_RED;
			
			/* Switch to next State if 5 seconds passed */
			PEDESTRIANS_RunState(PEDESTRIANS_STATE_RED);
			
			if(TIME_SecondsElapsed() == FIVE_SECOND)
			{
				PEDESTRIANS_SetState(PEDESTRIANS_STATE_YELLOW);
			}
			
			break;
	}
}

/*
 * Function: PEDESTRIANS_SetState
 * ----------------------------
 *	Set PEDESTRIANS next state depending on current & previous state
 *
 *	@param PEDESTRIANS_STATE_x: PEDESTRIANS_STATE_GREEN,PEDESTRIANS_STATE_YELLOW,PEDESTRIANS_STATE_RED
 */
void PEDESTRIANS_SetState(tPEDESTRIANS_STATE_x PEDESTRIANS_STATE_x)
{
	switch(pedestriansStateHandler.currentState)
	{
		case PEDESTRIANS_STATE_GREEN:
			pedestriansStateHandler.previousState = pedestriansStateHandler.currentState;
			pedestriansStateHandler.nextState = PEDESTRIANS_STATE_x;
			break;
		
		case PEDESTRIANS_STATE_YELLOW:
			if(currentMode == MODE_PEDESTRIANS)
			{
				pedestriansStateHandler.previousState = PEDESTRIANS_STATE_RED;
			}
			pedestriansStateHandler.nextState = PEDESTRIANS_STATE_x;
			break;
		
		case PEDESTRIANS_STATE_RED:
			pedestriansStateHandler.previousState = pedestriansStateHandler.currentState;
			pedestriansStateHandler.nextState = PEDESTRIANS_STATE_x;
			break;
	}	
}

/*
 * Function: PEDESTRIANS_GetState
 * ----------------------------
 *	Get PEDESTRIANS Current State
 *
 *	@param void
 *	@return PEDESTRIANS_STATE_x: PEDESTRIANS_STATE_GREEN,PEDESTRIANS_STATE_YELLOW,PEDESTRIANS_STATE_RED
 */
tPEDESTRIANS_STATE_x PEDESTRIANS_GetState(void)
{
	return pedestriansStateHandler.currentState;
}