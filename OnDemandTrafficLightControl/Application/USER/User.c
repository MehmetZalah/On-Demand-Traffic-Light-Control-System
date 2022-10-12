/*
 * User.c
 *
 * Created: 9/16/2022 5:01:13 PM
 *  Author: MohamedSalah
 */ 
#include "../App.h"
#include "User.h"
#include "../CARS/cars.h"
#include "../PEDESTRIANS/pedestrians.h"
#include "../../SERVICE/SWITCH/SWITCH.h"
#include "../../SERVICE/TIME/time.h"

tMODE_x currentMode = MODE_NORMAL;

tUSER_LONG_PRESSED_x longPressedStatus = USER_LONG_PRESSED_CLEARED;

/*
 * Function: USER_Init
 * ----------------------------
 *	Initialize USER Module
 *
 *	@param void
 */
void USER_Init(void)
{
	/* Initialize USER Switch */
	SWITCH_Init(SWITCH_PEDESTRIANS);
}

/*
 * Function: USER_Update
 * ----------------------------
 *	Monitor User Action periodically
 *
 *	@param void
 */
void USER_Update(void)
{	
	/* Make sure long pressed switch is cleared*/
	if(USER_longPressedStatus() == USER_LONG_PRESSED_CLEARED)
	{
		/* Check if USER Button is pressed */
		if(SWITCH_GetState(SWITCH_PEDESTRIANS) == SWITCH_STATE_PRESSED && currentMode == MODE_NORMAL)
		{
			/* Change current mode to PEDESTRIANS Mode */
			currentMode = MODE_PEDESTRIANS;
			
			/* Consider it as longPress unless the button is released */
			longPressedStatus = USER_LONG_PRESSED_SET;
			
			/* Get Current CARS State */
			tCARS_STATE_x CARS_STATE_x = CARS_GetState();
			
			/* Take an action depending on CARS State */
			switch(CARS_STATE_x)
			{
				case CARS_STATE_GREEN:
				
					/* Reset Time */
					TIME_ResetSeconds();
														
					/* Update Cars Traffic States */
					CARS_SetState(CARS_STATE_YELLOW);

					/* Update Pedestrians Traffic States */
					PEDESTRIANS_SetState(PEDESTRIANS_STATE_YELLOW);

					break;
					
				case CARS_STATE_YELLOW:
				
					/* Reset Time */
					TIME_ResetSeconds();
								
					/* Update Cars Traffic States */
					CARS_SetState(CARS_STATE_YELLOW);
										
					/* Update Pedestrians Traffic States */
					PEDESTRIANS_SetState(PEDESTRIANS_STATE_YELLOW);

					break;
					
					case CARS_STATE_RED:
					
					/* Reset Time */
					TIME_ResetSeconds();
					
					break;
			}
		}
	}
	else
	{
		/* clear long pressed status if switch is released */
		if(SWITCH_GetState(SWITCH_PEDESTRIANS) == SWITCH_STATE_RELEASED)
		{
			longPressedStatus = USER_LONG_PRESSED_CLEARED;
		}	
	}
	
}

/*
 * Function: USER_longPressedStatus
 * ----------------------------
 *	return long press status
 *
 *	@param void
 *	@return tUSER_LONG_PRESSED_x: USER_LONG_PRESSED_CLEARED, USER_LONG_PRESSED_SET
 */
tUSER_LONG_PRESSED_x USER_longPressedStatus(void)
{
	return longPressedStatus;
}