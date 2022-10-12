/*
 * OnDemandTrafficLightControl.c
 *
 * Created: 9/14/2022 6:02:02 AM
 * Author : MohamedSalah
 */ 

#include "Application/App.h"
#include "Application/CARS/cars.h"
#include "SERVICE/SWITCH/SWITCH.h"
#include "Application/PEDESTRIANS/pedestrians.h"
#include "stdio.h"
#include "MCAL/GPIO/GPIO_Test.h"

//#define TEST_MODULES
#define RUN_APP

int main(void)
{
#ifdef RUN_APP

	/* Initialize App Modules*/
	APP_Init();
	
    while(1) 
    {
		/* Run App */
		APP_Start();
    }
#endif

#ifdef TEST_MODULES

	GPIO_TEST();

#endif
	

}

