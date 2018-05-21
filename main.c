﻿//10.04.2018 !!!моргаем св/д + файл конфигурации RCC + miniRTOS позволяет выполнять
// задачи через определенный промежуток времени.

#include "main.h"
uint32_t systick_ms; //текущее время счетчика в мс
//**********************************************************************************
//!!!здесь описание задач!!!
#define NUMBERS_OF_TASK	2//общее число задач
//период повторения соответствующей задачи в (мс)
#define TASK1_PERIOD	400 //частота моргания РА0
#define TASK2_PERIOD	800 //частота моргания РА1

//здесь нужно объявить переменные необходимые для работы с задачами и
//раскрыть задачи если их нет в подключенных модулях, например:
//extern uint32_t adc_average_num;//среднее значение буфера ADC-DMA
//extern uint32_t v_volt;//результирующее значение напряжения

void task1(void)//
{
	GPIOA->ODR ^= GPIO_ODR_0; //Инвертируем состояние светодиодов;
}
void task2(void)//
{
	GPIOA->ODR ^= GPIO_ODR_1; //Инвертируем состояние светодиодов;
}
//**********************************************************************************
int main(void)
{
	//**********************************************************************************
	//инициализация всей необходимой переферии
	hse_init();//настройка тактирование
	gpio_init();//конфигураия ног на выход
	//adc_init();//другое по необходимости

	//инициализация SysTick на выдачу прерывания через время TimerTick_1ms
	SysTick_Config(TimerTick_1ms);
	//**********************************************************************************
    while(1)
    {
    	//**********************************************************************************
    	//здесь проверка и выполнение задач
    	static uint32_t task_ms[NUMBERS_OF_TASK];//время когда последний раз выполнялась i-я задача
    	if(time_diff(systick_ms, task_ms[0]) >= TASK1_PERIOD)
		{
			task_ms[0] = systick_ms;
			//здесь то что нужно выполнить в 1-й задаче
			task1();//моргаем РА0
		}
		if(time_diff(systick_ms, task_ms[1]) >= TASK2_PERIOD)
		{
			task_ms[1] = systick_ms;
			//здесь то что нужно выполнить во 2-й задаче
			task2();//моргаем РА1
		}
		//**********************************************************************************
    }//eng while(1)
}//end main()
//********************************************************

//********************************************************

//**********************************************************************************
//Функции, необходимые для работы RTOS:
// Обработчик прерывания. Считаем миллисекунды
void SysTick_Handler(void)
{
	++systick_ms;
}
// функция расчитывает разницу во времени с учетом переполнения счетчика TIM
uint32_t time_diff (uint32_t now, uint32_t before)
{
	return (now >= before) ? (now - before) : (UINT32_MAX - before + now);
}
//**********************************************************************************
