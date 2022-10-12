/*
 * User.h
 *
 * Created: 9/16/2022 5:01:23 PM
 *  Author: MohamedSalah
 */ 


#ifndef USER_H_
#define USER_H_

typedef enum
{
	USER_LONG_PRESSED_CLEARED,
	USER_LONG_PRESSED_SET
}tUSER_LONG_PRESSED_x;

/*
 * Function: USER_Init
 * ----------------------------
 *	Initialize USER Module
 *
 *	@param void
 */
void USER_Init(void);

/*
 * Function: USER_Update
 * ----------------------------
 *	Monitor User Action periodically
 *
 *	@param void
 */
void USER_Update(void);

/*
 * Function: USER_longPressedStatus
 * ----------------------------
 *	return long press status
 *
 *	@param void
 *	@return tUSER_LONG_PRESSED_x: USER_LONG_PRESSED_CLEARED, USER_LONG_PRESSED_SET
 */
tUSER_LONG_PRESSED_x USER_longPressedStatus(void);


#endif /* USER_H_ */