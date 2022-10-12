/*
 * GPIO_Test.c
 *
 * Created: 10/11/2022 5:39:32 PM
 *  Author: MohamedSalah
 */ 
#include "GPIO.h"
#include "GPIO_Test.h"

volatile tTEST_x test;

tTEST_x GPIO_TEST(void)
{
	GPIO_InitPinTest();
	
	GPIO_WritePINTest();
	
	GPIO_ReadPINTest();
	
	GPIO_TogglePINTest();
}

tTEST_x GPIO_InitPinTest(void)
{
	
	/************************************************************************/
	/* Test 1
	/* Input Date: PORT_A,PORT_PIN_0,GPIO_DIR_INPUT
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_InitPin(PORT_A,PORT_PIN_0,GPIO_DIR_INPUT) == GPIO_STATUS_SUCCESS)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 2
	/* Input Date: 4,PORT_PIN_0,GPIO_DIR_INPUT
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_InitPin(4,PORT_PIN_0,GPIO_DIR_INPUT) == GPIO_STATUS_ERROR_PORT)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	
	/************************************************************************/
	/* Test 3
	/* Input Date: PORT_B,9,GPIO_DIR_INPUT
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_InitPin(PORT_B,9,GPIO_DIR_INPUT) == GPIO_STATUS_ERROR_PIN)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 4
	/* Input Date: PORT_B,PORT_PIN_3,5
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_InitPin(PORT_B,PORT_PIN_3,5) == GPIO_STATUS_ERROR_DIR)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
}

tTEST_x GPIO_WritePINTest(void)
{
	
	/************************************************************************/
	/* Test 1
	/* Input Date: PORT_A,PORT_PIN_0,GPIO_STATE_HIGH
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_WritePIN(PORT_A,PORT_PIN_0,GPIO_STATE_HIGH) == GPIO_STATUS_SUCCESS)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 2
	/* Input Date: PORT_A,PORT_PIN_0,GPIO_STATE_HIGH
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_WritePIN(8,PORT_PIN_0,GPIO_STATE_HIGH) == GPIO_STATUS_ERROR_PORT)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	
	/************************************************************************/
	/* Test 3
	/* Input Date: PORT_B,9,GPIO_STATE_HIGH
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_WritePIN(PORT_B,9,GPIO_STATE_HIGH) == GPIO_STATUS_ERROR_PIN)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 4
	/* Input Date: PORT_B,PORT_PIN_4,8
	/* Expected Result: TEST_PASS
	/************************************************************************/
	if(GPIO_WritePIN(PORT_B,PORT_PIN_4,8) == GPIO_STATUS_ERROR_STATE)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
}

tTEST_x GPIO_ReadPINTest(void)
{
	
	/************************************************************************/
	/* Test 1
	/* Input Date: PORT_A,PORT_PIN_3
	/* Expected Result: TEST_PASS
	/************************************************************************/
		
	GPIO_InitPin(PORT_A,PORT_PIN_3,GPIO_DIR_OUTPUT);
	GPIO_WritePIN(PORT_A,PORT_PIN_3,GPIO_STATE_HIGH);
	
	if(GPIO_ReadPIN(PORT_A,PORT_PIN_3) == GPIO_STATE_HIGH)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 2
	/* Input Date: PORT_A,PORT_PIN_3
	/* Expected Result: TEST_PASS
	/************************************************************************/
		
	GPIO_InitPin(PORT_A,PORT_PIN_3,GPIO_DIR_OUTPUT);
	GPIO_WritePIN(PORT_A,PORT_PIN_3,GPIO_STATE_LOW);
	
	if(GPIO_ReadPIN(PORT_A,PORT_PIN_3) == GPIO_STATE_LOW)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	
	/************************************************************************/
	/* Test 3
	/* Input Date: 9,PORT_PIN_1
	/* Expected Result: TEST_PASS
	/************************************************************************/
		
	GPIO_InitPin(9,PORT_PIN_1,GPIO_DIR_OUTPUT);
	GPIO_WritePIN(9,PORT_PIN_1,GPIO_STATE_LOW);
	
	if(GPIO_ReadPIN(9,PORT_PIN_1) == GPIO_STATE_UNDEFINED)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 4
	/* Input Date: PORT_B,10
	/* Expected Result: TEST_PASS
	/************************************************************************/
		
	GPIO_InitPin(PORT_B,10,GPIO_DIR_OUTPUT);
	GPIO_WritePIN(PORT_B,10,GPIO_STATE_LOW);
	
	if(GPIO_ReadPIN(PORT_B,10) == GPIO_STATE_UNDEFINED)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
}

tTEST_x GPIO_TogglePINTest(void)
{
		
	/************************************************************************/
	/* Test 1
	/* Input Date: PORT_A,PORT_PIN_0
	/* Expected Result: TEST_PASS
	/************************************************************************/
		
	GPIO_InitPin(PORT_A,PORT_PIN_0,GPIO_DIR_OUTPUT);
	GPIO_WritePIN(PORT_A,PORT_PIN_0,GPIO_STATE_HIGH);
	
	if(GPIO_TogglePIN(PORT_A,PORT_PIN_0) == GPIO_STATUS_SUCCESS)
	{
		if(GPIO_ReadPIN(PORT_A,PORT_PIN_0) == GPIO_STATE_LOW)
		{
			test = TEST_PASS;
		}
		else
		{
			test = TEST_FAILED;
		}
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 2
	/* Input Date: PORT_A,PORT_PIN_3
	/* Expected Result: TEST_PASS
	/************************************************************************/
		
	GPIO_InitPin(PORT_A,PORT_PIN_3,GPIO_DIR_OUTPUT);
	GPIO_WritePIN(PORT_A,PORT_PIN_3,GPIO_STATE_LOW);
	
	if(GPIO_TogglePIN(PORT_A,PORT_PIN_3) == GPIO_STATUS_SUCCESS)
	{
		if(GPIO_ReadPIN(PORT_A,PORT_PIN_3) == GPIO_STATE_HIGH)
		{
			test = TEST_PASS;
		}
		else
		{
			test = TEST_FAILED;
		}
	}
	else
	{
		test = TEST_FAILED;
	}
	
	
	/************************************************************************/
	/* Test 3
	/* Input Date: 7,PORT_PIN_3
	/* Expected Result: TEST_PASS
	/************************************************************************/
			
	if(GPIO_TogglePIN(7,PORT_PIN_3) == GPIO_STATUS_ERROR_PORT)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
	/************************************************************************/
	/* Test 4
	/* Input Date: PORT_A,11
	/* Expected Result: TEST_PASS
	/************************************************************************/
			
	if(GPIO_TogglePIN(PORT_A,11) == GPIO_STATUS_ERROR_PIN)
	{
		test = TEST_PASS;
	}
	else
	{
		test = TEST_FAILED;
	}
	
}