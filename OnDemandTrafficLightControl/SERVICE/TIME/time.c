/*
 * time.c
 *
 * Created: 9/16/2022 4:18:22 PM
 *  Author: MohamedSalah
 */ 

#include "time.h"
#include "../../MCAL/TIMER0/Timer0.h"

/* Initialize timeInMilliSeconds Counter */
uint16 timeInMilliSeconds = 0;

/* Initialize timeInSeconds Counter */
uint8_t timeInSeconds = 0;

/*
 * Function: TIME_Init
 * ----------------------------
 *	Initialize TIME Module
 *
 *	@param: void
 */
void TIME_Init(void)
{
	/* Initialize Timer0 */
	Timer0_Init();
}

/*
 * Function: TIME_Update
 * ----------------------------
 *	Start Timer periodically
 *
 *	@param: void
 */
void TIME_Update(void)
{	
	/* Start Timer */
	Timer0_Start();
	
	/* Check if 50ms elapsed */
	if(Timer0_getStatus() == TIME_ELAPSED)
	{		
		/* Increment timeInMilliSeconds with 50ms */
		timeInMilliSeconds += 50;
	}
	
	/* Check if 1000ms elapsed */
	if(timeInMilliSeconds == 1000)
	{
		/* Increment timeInMilliSeconds with 1s */
		timeInSeconds++;		
	}
	
	/* Check if 5 Sec is elapsed */
	if(timeInSeconds > FIVE_SECOND)
	{
		timeInSeconds = 1;
	}
	
}

/*
 * Function: TIME_OneSecondElapsed
 * ----------------------------
 *	Check if timeInMilliSeconds reached 1000ms and reset timeInMilliSeconds to 0
 *
 *	@return: ONE_SECOND, COUNTING
 */
uint8_t TIME_OneSecondElapsed(void)
{
	/* Check if timeInMilliSeconds reached 1000ms */
	if(timeInMilliSeconds == 1000)
	{					
		timeInMilliSeconds = 0;
		return ONE_SECOND;
	}
	else
	{
		return COUNTING;
	}
}

/*
 * Function: TIME_SecondsElapsed
 * ----------------------------
 *	return timeInSeconds
 *
 *	@return timeInSeconds: uint8_t value elapsed
 */
uint8_t TIME_SecondsElapsed(void)
{
	return timeInSeconds;
}

/*
 * Function: TIME_ResetSeconds
 * ----------------------------
 *	reset timeInSeconds to start from 0
 *
 *	@param void
 */
void TIME_ResetSeconds(void)
{
	timeInSeconds = 0;
}