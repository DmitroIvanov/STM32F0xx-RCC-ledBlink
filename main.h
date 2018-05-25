//main.h

#ifndef __MAIN_H__
#define __MAIN_H__

#include <stm32f0xx.h>
#include <system_stm32f0xx.h>
#include "string.h" //Подключение функций Си
#include "stdlib.h"
//**********************************************************************************
//подключаем необходимые модули
#include <rcc_clock_init.h>

//**********************************************************************************
//частота прерывания системного таймера
#define TimerTick_1ms	(48000-1)// 1кГц
#define TimerTick_1us	(48-1) // 1МГц
#define TimerTick_240kHz (200) // 240кГц
#define TimerTick_5us	(240-1)// 200кГц
#define TimerTick_10us	(480-1)// 100кГц
#define TimerTick_100us	(4800-1)// 10кГц

//расчитываем нужную задержку
uint32_t time_diff (uint32_t now, uint32_t before);

#endif /* __MAIN_H_ */
