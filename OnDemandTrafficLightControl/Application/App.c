/*
 * App.c
 *
 * Created: 9/14/2022 6:09:49 AM
 *  Author: MohamedSalah
 */ 
#include "App.h"
#include "USER/User.h"
#include "CARS/cars.h"
#include "PEDESTRIANS/pedestrians.h"
#include "../SERVICE/TIME/time.h"

/*
 * Function: APP_Init
 * ----------------------------
 *	Init Application Modules
 *
 *	@param void
 */
void APP_Init(void)
{
	/* Initialize Time Module */
	TIME_Init();
		
	/* Initialize User Button Module */
	USER_Init();
		
	/* Initialize CARS Traffic Light Module */
	CARS_Init();
		
	/* Initialize PEDESTRIANS Traffic Light Module */
	PEDESTRIANS_Init();
}

/*
 * Function: APP_Start
 * ----------------------------
 *	Start Application Functions
 *
 *	@param void
 */
void APP_Start(void)
{
	/* Scan user button each 50ms */
	USER_Update();
	
	/* Reduce power consumption by updating states every 1 sec */
	if(TIME_OneSecondElapsed())
	{
		/* Check and UPDATE Cars Traffic Light each 1 sec */
		CARS_UpdateTraffic();
		
		/* Check and UPDATE PEDESTRIANS Traffic Light each 1 sec */
		PEDESTRIANS_UpdateTraffic();	
	}
	
	/* 50ms timer update */
	TIME_Update();
}