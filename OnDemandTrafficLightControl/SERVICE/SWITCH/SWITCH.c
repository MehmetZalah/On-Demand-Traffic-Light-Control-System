/*
 * SWITCH.c
 *
 * Created: 9/28/2022 3:05:58 AM
 *  Author: MohamedSalah
 */ 

#include "SWITCH.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "../../ECUAL/BUTTON/BUTTON.h"

/*
 * Function: SWITCH_Init
 * ----------------------------
 *	Initialize SWITCH_x
 *
 *	@param SWITCH_x: SWITCH_PEDESTRIANS 
 */
void SWITCH_Init(tSWITCH_x SWITCH_x)
{
	/* Initialize SWITCH_x */
	
	switch(SWITCH_x)
	{
		case SWITCH_PEDESTRIANS:
		BTN_Init(BTN_PEDESTRIANS_PORT, BTN_PEDESTRIANS_PIN);
		break;
	}
}

/*
 * Function: SWITCH_GetState
 * ----------------------------
 *	Return SWITCH_x State
 *
 *	@param SWITCH_x: SWITCH_PEDESTRIANS 
 */
tSWITCH_STATE_x SWITCH_GetState(tSWITCH_x SWITCH_x)
{
	/* Return SWITCH_x State */
	
	tGPIO_STATE_x btnState = GPIO_STATE_LOW;
	
	switch(SWITCH_x)
	{
		case SWITCH_PEDESTRIANS:

		btnState = BTN_GetState(BTN_PEDESTRIANS_PORT, BTN_PEDESTRIANS_PIN);

		if(btnState == GPIO_STATE_LOW)
		{
			return SWITCH_STATE_RELEASED;
		}
		else
		{
			return SWITCH_STATE_PRESSED;
		}
	}

	return SWITCH_STATE_RELEASED;
}