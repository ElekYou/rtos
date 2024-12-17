#include "user_led.h"
#include "cmsis_os.h"


void LED_Task()
{
    while (1)
    {
        LED_Test();
    }
}

void LED_Test()
{
    LED_On(LED_BLUE);
    osDelayUntil(1000);
    LED_Off(LED_BLUE);
    osDelayUntil(1000);
}

void LED_On(int type)
{
    switch (type)
    {
    case LED_BLUE:
        HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_1, GPIO_PIN_RESET);
        break;
    case LED_RED:
        HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_5, GPIO_PIN_RESET);
        break;
    case LED_GREEN:
        HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_0, GPIO_PIN_RESET);
        break;
    
    default:
        break;
    }
}

void LED_Off(int type)
{
    switch (type)
    {
    case LED_BLUE:
        HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_1, GPIO_PIN_SET);
        break;
    case LED_RED:
        HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_5, GPIO_PIN_SET);
        break;
    case LED_GREEN:
        HAL_GPIO_WritePin(LED_PORT, GPIO_PIN_0, GPIO_PIN_SET);
        break;
    
    default:
        break;
    }
}


