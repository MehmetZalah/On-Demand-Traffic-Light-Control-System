/*
 * App.h
 *
 * Created: 9/14/2022 6:11:31 AM
 *  Author: MohamedSalah
 */ 

#ifndef APP_H_
#define APP_H_

typedef enum
{
	MODE_NORMAL,
	MODE_PEDESTRIANS
}tMODE_x;

/*
 * Function: APP_Init
 * ----------------------------
 *	Initialize Application Modules
 *
 *	@param void
 */
void APP_Init(void);

/*
 * Function: APP_Start
 * ----------------------------
 *	Start Application Functions
 *
 *	@param void
 */
void APP_Start(void);

#endif /* APP_H_ */