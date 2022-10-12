/*
 * Timer0.c
 *
 * Created: 9/29/2022 2:16:33 AM
 *  Author: MohamedSalah
 */ 
#include "Timer0.h"
#include "../registers.h"
#include "../port.h"

tTIME_x timeStatus = TIME_NOT_ELAPSED;

/*
 * Function: Timer0_Init
 * ----------------------------
 *	Initialize Timer0 peripheral
 *
 *	@param: void 
 */
void Timer0_Init(void)
{
	/* Set Timer Normal Mode */
	TIMER_0_CONTROL_REGISTER = 0x00;
}

/*
 * Function: Timer0_Start
 * ----------------------------
 *	Start Timer0
 *	@calculation:
 *		1 tick = (256 Prescaler) / (1 MHz) = 256us
 *		1 overflow = 256us * 256 count = 65536us
 *		timer start from tick no = (65536us - 50000us) / (256us) = 60.68 ~ 61 tick  
 *
 *	@param: void 
 */
void Timer0_Start(void)
{	
	/* Reset Time elapsed Status */
	timeStatus = TIME_NOT_ELAPSED;
	
	/* Initialize Timer Counter with 61 to reach 50ms */
	TIMER_0_COUNTER_REGISTER = 61;
	
	//DIRECTION_REGISTER_A |= (1<<(6));
	//PORT_REGISTER_A &=~(1<<(6));
	
	/* start timer at 256 Prescaler */
	TIMER_0_CONTROL_REGISTER |= (4<<0);

	/* Wait a single overflow */
	while((TIMER_INTERRUPT_FLAG_REGISTER & (1<<0)) == 0);
		
	/* Clear OverFlow flag */
	TIMER_INTERRUPT_FLAG_REGISTER |= (1<<0);
			
	//PORT_REGISTER_A |=(1<<(6));
	
	/* Update Time elapsed Status */
	timeStatus = TIME_ELAPSED;		
}

/*
 * Function: Timer0_Stop
 * ----------------------------
 *	Stop Timer0
 *
 *	@param: void 
 */
void Timer0_Stop(void)
{
	/* Stop Timer By Set Prescaler 0x00 */
	TIMER_0_CONTROL_REGISTER = 0x00;
}

/*
 * Function: Timer0_getStatus
 * ----------------------------
 *	Stop Timer0
 *
 *	@param: void 
 */
tTIME_x Timer0_getStatus(void)
{
	/* Return Time elapsed Status */
	return timeStatus;
}