/*
 * Timer0.h
 *
 * Created: 9/29/2022 2:16:19 AM
 *  Author: MohamedSalah
 */ 

#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../Utilities/types.h"

typedef enum
{
	TIME_ELAPSED,
	TIME_NOT_ELAPSED
}tTIME_x;

/*
 * Function: Timer0_Init
 * ----------------------------
 *	Initialize Timer0 peripheral
 *
 *	@param: void 
 */
void Timer0_Init(void);

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
void Timer0_Start(void);

/*
 * Function: Timer0_Stop
 * ----------------------------
 *	Stop Timer0
 *
 *	@param: void 
 */
void Timer0_Stop(void);

/*
 * Function: Timer0_getStatus
 * ----------------------------
 *	Stop Timer0
 *
 *	@param: void 
 */
tTIME_x Timer0_getStatus(void);


#endif /* TIMER0_H_ */