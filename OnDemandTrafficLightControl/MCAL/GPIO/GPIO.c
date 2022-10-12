/*
 * GPIO.c
 *
 * Created: 9/14/2022 6:08:11 AM
 *  Author: MohamedSalah
 */ 

#include "../registers.h"
#include "../port.h"
#include "GPIO.h"

/*
 * Function: GPIO_InitPin
 * ----------------------------
 *	Initialize PORT PIN as GPIO_DIR_x
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *	@param GPIO_DIR_x: GPIO_DIR_INPUT, GPIO_DIR_OUTPUT
 *
 *	@return tGPIO_STATUS_x: GPIO_STATUS_SUCCESS, GPIO_STATUS_ERROR_PORT, GPIO_STATUS_ERROR_PIN, GPIO_STATUS_ERROR_DIR, GPIO_STATUS_ERROR_STATE
 */
tGPIO_STATUS_x GPIO_InitPin(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n, tGPIO_DIR_x GPIO_DIR_x)
{
	/* GPIO_DIR_x ERROR Handling */
	if(GPIO_DIR_x != GPIO_DIR_INPUT && GPIO_DIR_x != GPIO_DIR_OUTPUT)
		return GPIO_STATUS_ERROR_DIR;
	
	/* PORT_PIN_n ERROR Handling*/
	if(PORT_PIN_n < PORT_PIN_0 || PORT_PIN_n > PORT_PIN_7)
		return GPIO_STATUS_ERROR_PIN;
	
	/* Initialize PORT PIN as GPIO_DIR_x */
	switch(PORT_x)
	{
		case PORT_A:
			if(GPIO_DIR_x == GPIO_DIR_OUTPUT)
			{
				// Set (1) to (DIRECTION_REGISTER_A Register) (PORT_PIN_n) bit
				DIRECTION_REGISTER_A |= (1<<(PORT_PIN_n));
			}
			else if(GPIO_DIR_x == GPIO_DIR_INPUT)
			{
				// Set (0) to (DIRECTION_REGISTER_A Register) (PORT_PIN_n) bit
				DIRECTION_REGISTER_A &= ~(1<<(PORT_PIN_n));
			}
			break;
		
		case PORT_B:

			if(GPIO_DIR_x == GPIO_DIR_OUTPUT)
			{
				// Set (1) to (DIRECTION_REGISTER_B Register) (PORT_PIN_n) bit
				DIRECTION_REGISTER_B |=(1<<(PORT_PIN_n));
			}
			else if(GPIO_DIR_x == GPIO_DIR_INPUT)
			{
				// Set (0) to (DIRECTION_REGISTER_B Register) (PORT_PIN_n) bit
				DIRECTION_REGISTER_B &=~(1<<(PORT_PIN_n));
			}
			break;
		
		case PORT_D:
		
			if(GPIO_DIR_x == GPIO_DIR_OUTPUT)
			{
				// Set (1) to (DIRECTION_REGISTER_D Register) (PORT_PIN_n) bit			
				DIRECTION_REGISTER_D |=(1<<(PORT_PIN_n));
			}
			else if(GPIO_DIR_x == GPIO_DIR_INPUT)
			{
				// Set (0) to (DIRECTION_REGISTER_D Register) (PORT_PIN_n) bit
				DIRECTION_REGISTER_D &=~(1<<(PORT_PIN_n));
			}
			break;
			
		default:
		
			return GPIO_STATUS_ERROR_PORT;
			break;
	}
	
	return GPIO_STATUS_SUCCESS;
}

/*
 * Function: GPIO_WritePIN
 * ----------------------------
 *	Set PORT PIN as GPIO_STATE_x
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *	@param GPIO_STATE_x: GPIO_STATE_LOW, GPIO_STATE_HIGH
 *
 *	@return tGPIO_STATUS_x: GPIO_STATUS_SUCCESS, GPIO_STATUS_ERROR_PORT, GPIO_STATUS_ERROR_PIN, GPIO_STATUS_ERROR_DIR, GPIO_STATUS_ERROR_STATE
 */
tGPIO_STATUS_x GPIO_WritePIN(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n, tGPIO_STATE_x GPIO_STATE_x)
{
	/* GPIO_STATE_x ERROR Handling */
	if(GPIO_STATE_x != GPIO_STATE_LOW && GPIO_STATE_x != GPIO_STATE_HIGH)
		return GPIO_STATUS_ERROR_STATE;
		
	/* PORT_PIN_n ERROR Handling*/
	if(PORT_PIN_n < PORT_PIN_0 || PORT_PIN_n > PORT_PIN_7)
		return GPIO_STATUS_ERROR_PIN;
	
	/* Set PORT PIN as GPIO_STATE_x */
	switch(PORT_x)
	{
		case PORT_A:
		
			if(GPIO_STATE_x == GPIO_STATE_HIGH)
			{
				// Set (1) to (PORT_REGISTER_A Register) (PORT_PIN_n) bit
				PORT_REGISTER_A |=(1<<(PORT_PIN_n));
			}
			else if(GPIO_STATE_x == GPIO_STATE_LOW)
			{
				// Set (0) to (PORT_REGISTER_A Register) (PORT_PIN_n) bit
				PORT_REGISTER_A &=~(1<<(PORT_PIN_n));
			}
			break;
		
		case PORT_B:
		
			if(GPIO_STATE_x == GPIO_STATE_HIGH)
			{
				// Set (1) to (PORT_REGISTER_B Register) (PORT_PIN_n) bit
				PORT_REGISTER_B |=(1<<(PORT_PIN_n));
			}
			else if(GPIO_STATE_x == GPIO_STATE_LOW)
			{
				// Set (0) to (PORT_REGISTER_B Register) (PORT_PIN_n) bit
				PORT_REGISTER_B &=~(1<<(PORT_PIN_n));
			}
			break;
			
		default:
		
			return GPIO_STATUS_ERROR_PORT;
			break;
	}
	
	return GPIO_STATUS_SUCCESS;
}

/*
 * Function: GPIO_ReadPIN
 * ----------------------------
 *	Read PORT PIN State
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tGPIO_STATE_x: 	GPIO_STATE_LOW, GPIO_STATE_HIGH, GPIO_STATE_UNDEFINED
 */
tGPIO_STATE_x GPIO_ReadPIN(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n)
{
	/* PORT_PIN_n ERROR Handling*/
	if(PORT_PIN_n < PORT_PIN_0 || PORT_PIN_n > PORT_PIN_7)
		return GPIO_STATE_UNDEFINED;

	/* Read PORT PIN State */
	switch(PORT_x)
	{
		case PORT_A:
				
			if(PIN_REGISTER_A & (1<<PORT_PIN_n))
			{
				return GPIO_STATE_HIGH;
			}
			else
			{
				return GPIO_STATE_LOW;
			}
			break;
		case PORT_B:
					
			if(PIN_REGISTER_B & (1<<PORT_PIN_n))
			{
				return GPIO_STATE_HIGH;
			}
			else
			{
				return GPIO_STATE_LOW;
			}
			break;
		case PORT_D:
			
			if(PIN_REGISTER_D & (1<<PORT_PIN_n))
			{
				return GPIO_STATE_HIGH;
			}
			else
			{
				return GPIO_STATE_LOW;
			}
			break;
			
		default:
		
			return GPIO_STATE_UNDEFINED;
			break;
	}
}

/*
 * Function: GPIO_TogglePIN
 * ----------------------------
 *	Toggle PORT PIN State
 *
 *	@param PORT_x: PORT_A, PORT_B, PORT_D
 *	@param PORT_PIN_n: PORT_PIN_0, PORT_PIN_1, PORT_PIN_2, PORT_PIN_3, PORT_PIN_4, PORT_PIN_5, PORT_PIN_6, PORT_PIN_7
 *
 *	@return tGPIO_STATUS_x: GPIO_STATUS_SUCCESS, GPIO_STATUS_ERROR_PORT, GPIO_STATUS_ERROR_PIN, GPIO_STATUS_ERROR_DIR, GPIO_STATUS_ERROR_STATE
 */
tGPIO_STATUS_x GPIO_TogglePIN(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n)
{
	/* PORT_PIN_n ERROR Handling*/
	if(PORT_PIN_n < PORT_PIN_0 || PORT_PIN_n > PORT_PIN_7)
	return GPIO_STATUS_ERROR_PIN;
	
	/* Toggle PORT PIN State */
	switch(PORT_x)
	{
		case PORT_A:
		
		/* Toggle (PORT_REGISTER_A Register) (PORT_PIN_n) bit */
		PORT_REGISTER_A ^= (1<<PORT_PIN_n);
		break;
		
		case PORT_B:
		
		/* Toggle (PORT_REGISTER_A Register) (PORT_PIN_n) bit */
		PORT_REGISTER_B ^= (1<<PORT_PIN_n);
		break;
		
		default:
		
		return GPIO_STATUS_ERROR_PORT;
		break;
	}
	
	return GPIO_STATUS_SUCCESS;
}