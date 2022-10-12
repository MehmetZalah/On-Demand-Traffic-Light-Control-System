/*
 * SWITCH.h
 *
 * Created: 9/28/2022 3:06:09 AM
 *  Author: MohamedSalah
 */ 

#ifndef SWITCH_H_
#define SWITCH_H_

typedef enum
{
	SWITCH_PEDESTRIANS,
}tSWITCH_x;

typedef enum
{
	SWITCH_STATE_RELEASED,
	SWITCH_STATE_PRESSED
}tSWITCH_STATE_x;

/*
 * Function: SWITCH_Init
 * ----------------------------
 *	Initialize SWITCH_x
 *
 *	@param SWITCH_x: SWITCH_PEDESTRIANS 
 */
void SWITCH_Init(tSWITCH_x SWITCH_x);

/*
 * Function: SWITCH_GetState
 * ----------------------------
 *	Return SWITCH_x State
 *
 *	@param SWITCH_x: SWITCH_PEDESTRIANS 
 */
tSWITCH_STATE_x SWITCH_GetState(tSWITCH_x SWITCH_x);


#endif /* SWITCH_H_ */