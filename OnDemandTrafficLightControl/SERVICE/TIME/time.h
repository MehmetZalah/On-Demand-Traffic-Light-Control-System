/*
 * time.h
 *
 * Created: 9/16/2022 4:18:36 PM
 *  Author: MohamedSalah
 */ 

#ifndef TIME_H_
#define TIME_H_

#include "../../Utilities/types.h"

#define FIVE_SECOND 5
#define ONE_SECOND 1
#define COUNTING 0

/*
 * Function: TIME_Init
 * ----------------------------
 *	Initialize TIME Module
 *
 *	@param: void
 */
void TIME_Init(void);

/*
 * Function: TIME_Update
 * ----------------------------
 *	Start Timer periodically
 *
 *	@param: void
 */
void TIME_Update(void);

/*
 * Function: TIME_OneSecondElapsed
 * ----------------------------
 *	Check if timeInMilliSeconds reached 1000ms and reset timeInMilliSeconds to 0
 *
 *	@return: ONE_SECOND, COUNTING
 */
uint8_t TIME_OneSecondElapsed(void);

/*
 * Function: TIME_SecondsElapsed
 * ----------------------------
 *	return time elapsed in seconds
 *
 *	@return timeInSeconds: uint8_t value elapsed
 */
uint8_t TIME_SecondsElapsed(void);

/*
 * Function: TIME_ResetSeconds
 * ----------------------------
 *	reset timeInSeconds to start from 0
 *
 *	@param void
 */
void TIME_ResetSeconds(void);

#endif /* TIME_H_ */