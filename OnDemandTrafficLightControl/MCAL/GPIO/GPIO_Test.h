/*
 * GPIO_Test.h
 *
 * Created: 10/11/2022 5:40:03 PM
 *  Author: MohamedSalah
 */ 

#ifndef GPIO_TEST_H_
#define GPIO_TEST_H_

typedef enum
{
	TEST_PASS,
	TEST_FAILED
}tTEST_x;

tTEST_x GPIO_TEST(void);
tTEST_x GPIO_InitPinTest(void);
tTEST_x GPIO_WritePINTest(void);
tTEST_x GPIO_ReadPINTest(void);
tTEST_x GPIO_TogglePINTest(void);

#endif /* GPIO_TEST_H_ */