- Udacity EgFWD NanoDegree
- On-Demand Traffic Light Control System
- Eng. Mohamed Salah Abdelfatah

#	System Description
## System Overview
-	A set of automatically operated colored lights Red, yellow and Green for controlling traffic at road junctions and pedestrian crossings.
-	Crosswalk buttons let the signal operations know that someone is planning to cross the street, so the light adjusts, giving the pedestrian enough time to get across.
## System Functionality
-	Cars' LEDs will be changed every five seconds starting from Green then yellow then red then yellow then Green.
-	The Yellow LED will blink for five seconds before moving to Green or Red LEDs.
-	Change from normal mode to pedestrian mode when the pedestrian button is pressed.
-	If pressed when the cars' Red LED is on, the pedestrian's Green LED and the cars' Red LEDs will be on for five seconds, this means that pedestrians can cross the street while the pedestrian's Green LED is on.
-	If pressed when the cars' Green LED is on or the cars' Yellow LED is blinking, the pedestrian Red LED will be on then both Yellow LEDs start to blink for five seconds, then the cars' Red LED and pedestrian Green LEDs are on for five seconds, this means that pedestrian must wait until the Green LED is on.
-	At the end of the two states, the cars' Red LED will be off and both Yellow LEDs start blinking for 5 seconds and the pedestrian's Green LED is still on.
-	After the five seconds the pedestrian Green LED will be off and both the pedestrian Red LED and the cars' Green LED will be on.
-	Traffic lights signals are going to the normal mode again.
## System Hardware
-	1x AVR Microcontroller ATMega32
-	2x Red LEDs
-	2x Yellow LEDs
-	2x Green LEDs
-	1x Push Button
-	6x 220 Ohm Resistors
-	1x 10k Ohm Resistor
## System Schematic
### Circuit
![Schematic](https://user-images.githubusercontent.com/19867149/194759648-f97a60f9-de6c-4b63-bb62-508204d19ca1.png)
### Connection
-	ATmega32 microcontroller
-	One push button connected to INT0 pin for pedestrian
-	Three LEDs for cars - Green, Yellow, and Red, connected on port A, pins 0, 1, and 2
-	Three LEDs for pedestrians - Green, Yellow, and Red, connected on port B, pins 0, 1, and 2
# System Design
## System Static Architecture
### System Layers
![AppLayers drawio](https://user-images.githubusercontent.com/19867149/194788716-17d7d555-6409-4ce7-a43c-96274988eff9.png)
### System Drivers
- MCAL Drivers: GPIO, TIMER0
- ECUAL Drivers: HAL_LED, HAL_BUTTON
- SERVICE Drivers: DISPLAY drive HAL_LED, SWITCH drive HAL_BUTTON, TIME drive TIMER0
### Systems APIs
#### APPLICATION LAYER
##### CARS Module
```
typedef enum
{
CARS_STATE_GREEN,
CARS_STATE_YELLOW,
CARS_STATE_RED
}tCARS_STATE_x;

typedef enum{
CARS_LED_GREEN,
CARS_LED_YELLOW,
CARS_LED_RED
}tCARS_LED_x;

typedef struct
{
tCARS_STATE_x previousState;
tCARS_STATE_x currentState;
tCARS_STATE_x nextState;
uint8_t secCounter;
}tCarsStateHandler;

void CARS_Init(void);
void CARS_UpdateTraffic(void);
void CARS_RunState(tCARS_STATE_x CARS_STATE_x);
void CARS_SetState(tCARS_STATE_x CARS_STATE_x);
tCARS_STATE_x CARS_GetState(void);
```
##### PEDESTRIANS Module
```
typedef enum
{
PEDESTRIANS_STATE_GREEN,
PEDESTRIANS_STATE_YELLOW,
PEDESTRIANS_STATE_RED
}tPEDESTRIANS_STATE_x;

typedef enum
{
PEDESTRIANS_LED_GREEN,
PEDESTRIANS_LED_YELLOW,
PEDESTRIANS_LED_RED
}tPEDESTRIANS_LED_x;

typedef struct
{
tPEDESTRIANS_STATE_x previousState;
tPEDESTRIANS_STATE_x currentState;
tPEDESTRIANS_STATE_x nextState;
uint8_t secCounter;
}tPedestriansStateHandler;

void PEDESTRIANS_Init(void);
void PEDESTRIANS_UpdateTraffic(void);
void PEDESTRIANS_RunState(tPEDESTRIANS_STATE_x PEDESTRIANS_STATE_x);
void PEDESTRIANS_SetState(tPEDESTRIANS_STATE_x PEDESTRIANS_STATE_x);
tPEDESTRIANS_STATE_x PEDESTRIANS_GetState(void);
```
##### USER Module
```
typedef enum
{
USER_LONG_PRESSED_CLEARED,
USER_LONG_PRESSED_SET
}tUSER_LONG_PRESSED_x;

void USER_Init(void);
void USER_Update(void);
tUSER_LONG_PRESSED_x USER_longPressedStatus(void);
```
#### SERVICE LAYER
#####	DISPLAY Module:
```
typedef enum
{
DISPLAY_STATE_OFF,
DISPLAY_STATE_ON
}tDISPLAY_STATE_x;

typedef enum
{
LED_CARS_GREEN,
LED_CARS_YELLOW,
LED_CARS_RED,
LED_PEDESTRIANS_GREEN,
LED_PEDESTRIANS_YELLOW,
LED_PEDESTRIANS_RED
}tLED_x;

void DISPLAY_Init(tLED_x LED_x, tDISPLAY_STATE_x DISPLAY_STATE_x);
void DISPLAY_SetState(tLED_x LED_x, tDISPLAY_STATE_x DISPLAY_STATE_x);
void DISPLAY_Toggle(tLED_x LED_x);
void DISPLAY_ON(tLED_x LED_x);
void DISPLAY_OFF(tLED_x LED_x);
```
#####	SWITCH Module:
```
typedef enum
{
SWITCH_PEDESTRIANS
}tSWITCH_x;

typedef enum
{
SWITCH_STATE_RELEASED,
SWITCH_STATE_PRESSED
}tSWITCH_STATE_x;

void SWITCH_Init(tSWITCH_x SWITCH_x);
tSWITCH_STATE_x SWITCH_GetState(tSWITCH_x SWITCH_x);
```
#####	TIME Module:
```
void TIME_Init(void);
void TIME_Update(void);
uint8_t TIME_OneSecondElapsed(void);
uint8_t TIME_SecondsElapsed(void);
```
####	ECUAL:
#####	LED Module:
```
typedef enum
{
	LED_STATUS_SUCCESS,
	LED_STATUS_ERROR
}tLED_STATUS_x;

tLED_STATUS_x LED_Init(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);
tLED_STATUS_x LED_SetState(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n,tGPIO_STATE_x GPIO_STATE_x);
tLED_STATUS_x LED_Toggle(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);
```
#####	BUTTON Module:
```
typedef enum
{
	BTN_STATUS_SUCCESS,
	BTN_STATUS_ERROR
}tBTN_STATUS_x;

tBTN_STATUS_x BTN_Init(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);
tGPIO_STATE_x BTN_GetState(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);
```
####	MCAL:
#####	GPIO:
```
typedef enum
{
	GPIO_STATE_LOW,
	GPIO_STATE_HIGH,
	GPIO_STATE_UNDEFINED
}tGPIO_STATE_x;

typedef enum
{
	GPIO_STATUS_SUCCESS,
	GPIO_STATUS_ERROR_PORT,
	GPIO_STATUS_ERROR_PIN,
	GPIO_STATUS_ERROR_DIR,
	GPIO_STATUS_ERROR_STATE
}tGPIO_STATUS_x;

typedef enum
{
GPIO_DIR_INPUT,
GPIO_DIR_OUTPUT
}tGPIO_DIR_x;

typedef enum
{
PORT_PIN_0,
PORT_PIN_1,
PORT_PIN_2,
PORT_PIN_3,
PORT_PIN_4,
PORT_PIN_5,
PORT_PIN_6,
PORT_PIN_7,
}tPORT_PIN_n;

tGPIO_STATUS_x GPIO_InitPin(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n, tGPIO_DIR_x GPIO_DIR_x);
tGPIO_STATUS_x GPIO_WritePIN(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n, tGPIO_STATE_x GPIO_STATE_x);
tGPIO_STATE_x GPIO_ReadPIN(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);
tGPIO_STATUS_x GPIO_TogglePIN(tPORT_x PORT_x, tPORT_PIN_n PORT_PIN_n);
```
##### TIMER0:
```
typedef enum
{
TIME_ELAPSED,
TIME_NOT_ELAPSED
}tTIME_x;

void Timer0_Init(void);
void Timer0_Start(void);
void Timer0_Stop(void);
tTIME_x Timer0_getStatus(void);
```
## System Periodic Functions
![MS-APPPeriodicFunctions drawio](https://user-images.githubusercontent.com/19867149/195183841-699ea73f-51c1-4ac9-9151-0af5976e17a5.png)
# System Flow Chart
![MS-Startup drawio](https://user-images.githubusercontent.com/19867149/195183983-caa20b13-e192-4514-8cb8-3e6d96e2d39e.png)


![MS-APPModule drawio](https://user-images.githubusercontent.com/19867149/195183978-ff64fbb6-aa2e-4627-ae7f-5a0e8d7f30d9.png)


![MS-TIMEModule drawio](https://user-images.githubusercontent.com/19867149/195183907-d51c3cb3-dfd2-48b8-9b05-8fcf85f7dbd8.png)


![MS-USERModule drawio](https://user-images.githubusercontent.com/19867149/195183896-591da824-b335-4b6a-9d51-e891866859b9.png)


![MS-CARSModule drawio](https://user-images.githubusercontent.com/19867149/195183874-245f3604-3bf0-44d1-b331-474ef6186257.png)


![MS-PEDESTRIANSModule drawio](https://user-images.githubusercontent.com/19867149/195183885-311abd59-c9c4-4536-b089-3fb9224d3039.png)
