//main.h
//10.04.2018

#ifndef __MAIN_H__
#define __MAIN_H__

#include <stm32f0xx.h>
#include <system_stm32f0xx.h>
#include "string.h" //ѕодключение функций —и
#include "stdlib.h"
//**********************************************************************************
//подключаем необходимые модули
#include <rcc_clock_init.h>

//**********************************************************************************
//частота прерывани€ системного таймера
#define TimerTick_1ms	(48000-1)// 1к√ц
#define TimerTick_1us	(48-1) // 1ћ√ц
#define TimerTick_240kHz (200) // 240к√ц
#define TimerTick_5us	(240-1)// 200к√ц
#define TimerTick_10us	(480-1)// 100к√ц
#define TimerTick_100us	(4800-1)// 10к√ц

//расчитываем нужную задержку
uint32_t time_diff (uint32_t now, uint32_t before);

#endif /* __MAIN_H_ */
