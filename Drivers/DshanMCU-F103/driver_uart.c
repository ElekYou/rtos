// SPDX-License-Identifier: GPL-3.0-only
/*
 * Copyright (c) 2008-2023 100askTeam : Dongshan WEI <weidongshan@qq.com> 
 * Discourse:  https://forums.100ask.net
 */
 
/*  Copyright (C) 2008-2023 深圳百问网科技有限公司
 *  All rights reserved
 *
 * 免责声明: 百问网编写的文档, 仅供学员学习使用, 可以转发或引用(请保留作者信息),禁止用于商业用途！
 * 免责声明: 百问网编写的程序, 可以用于商业用途, 但百问网不承担任何后果！
 * 
 * 本程序遵循GPL V3协议, 请遵循协议
 * 百问网学习平台   : https://www.100ask.net
 * 百问网交流社区   : https://forums.100ask.net
 * 百问网官方B站    : https://space.bilibili.com/275908810
 * 本程序所用开发板 : DShanMCU-F103
 * 百问网官方淘宝   : https://100ask.taobao.com
 * 联系我们(E-mail): weidongshan@qq.com
 *
 *          版权所有，盗版必究。
 *  
 * 修改历史     版本号           作者        修改内容
 *-----------------------------------------------------
 * 2023.08.04      v01         百问科技      创建文件
 *-----------------------------------------------------
 */




#include "driver_uart.h"
#include "driver_lcd.h"
#include "driver_timer.h"
#include "usart.h"

#include <stdio.h>

#define DEBUG_UART_TIMEOUT 500

extern UART_HandleTypeDef huart1;
static UART_HandleTypeDef * g_HDebugUART = &huart1;

/**********************************************************************
 * 函数名称： UART_Init
 * 功能描述： UART初始化函数
 * 输入参数： 无
 * 输出参数： 无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人	      修改内容
 * -----------------------------------------------
 * 2023/08/05	     V1.0	  韦东山	      创建
 ***********************************************************************/
void UART_Init(void)
{
}


int fputc(int c, FILE *f) 
{
    (void)f;
    HAL_UART_Transmit(g_HDebugUART, (const uint8_t *)&c, 1, DEBUG_UART_TIMEOUT);
    return c;
}

int fgetc(FILE *f)
{
    uint8_t ch = 0;
    (void)f;

    /* Clear the Overrun flag just before receiving the first character */
    __HAL_UART_CLEAR_OREFLAG(g_HDebugUART);

    /* Wait for reception of a character on the USART RX line and echo this
    * character on console */
    HAL_UART_Receive(g_HDebugUART, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    HAL_UART_Transmit(g_HDebugUART, (uint8_t *)&ch, 1, HAL_MAX_DELAY);
    return ch;    
}


/**********************************************************************
 * 函数名称： UART_Test
 * 功能描述： UART测试程序
 * 输入参数： 无
 * 输出参数： 无
 *            无
 * 返 回 值： 0 - 成功, 其他值 - 失败
 * 修改日期        版本号     修改人        修改内容
 * -----------------------------------------------
 * 2023/08/05        V1.0     韦东山       创建
 ***********************************************************************/
void UART_Test(void)
{    
    char c;
    
    UART_Init();

    LCD_PrintString(0, 0, "Use Serial Tool on PC to test UART");

    printf("100ask UART test:\n\r");
    while (1)
    {
        c = fgetc(NULL);
        printf("\n\rget %c\n\r", c);
    }
}
