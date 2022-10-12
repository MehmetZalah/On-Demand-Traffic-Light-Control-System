/*
 * pedestrians.h
 *
 * Created: 9/14/2022 9:42:51 AM
 *  Author: MohamedSalah
 */ 


#ifndef PEDESTRIANS_H_
#define PEDESTRIANS_H_

#include "../../Utilities/types.h"

typedef enum
{
	PEDESTRIANS_STATE_GREEN,
	PEDESTRIANS_STATE_YELLOW,
	PEDESTRIANS_STATE_RED,
}tPEDESTRIANS_STATE_x;

typedef enum
{
	PEDESTRIANS_LED_GREEN,
	PEDESTRIANS_LED_YELLOW,
	PEDESTRIANS_LED_RED,
}tPEDESTRIANS_LED_x;

typedef struct
{
	tPEDESTRIANS_STATE_x previousState;
	tPEDESTRIANS_STATE_x currentState;
	tPEDESTRIANS_STATE_x nextState;
}tPedestriansStateHandler;

/*
 * Function: PEDESTRIANS_Init
 * ----------------------------
 *	Initialize PEDESTRIANS Traffic Light Module
 *
 *	@param void
 */
void PEDESTRIANS_Init(void);

/*
 * Function: PEDESTRIANS_RunState
 * ----------------------------
 *	Turn ON/OFF PEDESTRIANS Traffic LEDs Depending on State
 *
 *	@param PEDESTRIANS_STATE_x: PEDESTRIANS_STATE_GREEN,PEDESTRIANS_STATE_YELLOW,PEDESTRIANS_STATE_RED
 */
void PEDESTRIANS_RunState(tPEDESTRIANS_STATE_x PEDESTRIANS_STATE_x);

/*
 * Function: PEDESTRIANS_UpdateTraffic
 * ----------------------------
 *	Update PEDESTRIANS Traffic State periodically
 *
 *	@param void
 */
void PEDESTRIANS_UpdateTraffic(void);

/*
 * Function: PEDESTRIANS_SetState
 * ----------------------------
 *	Set PEDESTRIANS next state depending on current & previous state
 *
 *	@param PEDESTRIANS_STATE_x: PEDESTRIANS_STATE_GREEN,PEDESTRIANS_STATE_YELLOW,PEDESTRIANS_STATE_RED
 */
void PEDESTRIANS_SetState(tPEDESTRIANS_STATE_x PEDESTRIANS_STATE_x);

/*
 * Function: PEDESTRIANS_GetState
 * ----------------------------
 *	Get PEDESTRIANS Current State
 *
 *	@param void
 *	@return PEDESTRIANS_STATE_x: PEDESTRIANS_STATE_GREEN,PEDESTRIANS_STATE_YELLOW,PEDESTRIANS_STATE_RED
 */
tPEDESTRIANS_STATE_x PEDESTRIANS_GetState(void);

#endif /* PEDESTRIANS_H_ */