/*
 * BUTTON.c
 *
 * Created: 9/14/2022 6:09:12 AM
 *  Author: MohamedSalah
 */ 

#include "button.h"
#include "../../MCAL/port.h"
#include "../../MCAL/GPIO/GPIO.h"

/*
 * Function: BTN_Init
 * ----------------------------
 *	Initialize PORT PIN
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: 	PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tBTN_STATUS_x: 	BTN_STATUS_SUCCESS, BTN_STATUS_ERROR
 */
tBTN_STATUS_x BTN_Init(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n)
{
	/* Initialize PORT PIN as INPUT */
	if(GPIO_InitPin(PORT_x, PORT_PIN_n, GPIO_DIR_INPUT) == GPIO_STATUS_SUCCESS)
	{
		return BTN_STATUS_SUCCESS;
	}
	else
	{
		return BTN_STATUS_ERROR;
	}
}

/*
 * Function: BTN_GetState
 * ----------------------------
 *	Return PORT PIN State HIGH/LOW
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tGPIO_STATE_x: GPIO_STATE_LOW, GPIO_STATE_HIGH, GPIO_STATE_UNDEFINED
 */
tGPIO_STATE_x BTN_GetState(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n)
{
	/* Return PORT PIN State HIGH/LOW */
	return GPIO_ReadPIN(PORT_x, PORT_PIN_n);
}