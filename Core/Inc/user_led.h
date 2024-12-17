#ifndef __USER_LED_H
#define __USER_LED_H


#include "main.h"

#define LED_BLUE                1  // PB1    
#define LED_GREEN               2  // PB0
#define LED_RED                 3  // PB5
#define LED_PORT                GPIOB


extern void LED_Task();
extern void LED_Test(void);
extern void LED_On(int type);
extern void LED_Off(int type);


#endif

