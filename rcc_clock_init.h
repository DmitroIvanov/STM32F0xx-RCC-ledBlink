//rcc_clock_init.h

#ifndef __RCC_CLOCK_INIT_H__
#define __RCC_CLOCK_INIT_H__

#include <stm32f0xx.h>
#include <system_stm32f0xx.h>
#include "string.h" //Подключение функций Си
#include "stdlib.h"

void hsi_init (void);
//тактирование осуществл от HSI умноженое на коэф PLL
//PF0, PF1 - можно использовать как обычные GPIO

void hse_init (void);
//тактирование осуществл от HSЕ умноженое на коэф PLL

void pll_config();
//позволяет переконфигурировать частоту тактирования от PLL

void gpio_init();
//настройка тактирования переферии GPIO на вход, выход, альтернативную функцию

#endif /* __RCC_CLOCK_INIT_H__ */
