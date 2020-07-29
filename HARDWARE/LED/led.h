#ifndef __LED_H
#define __LED_H	 

#include "sys.h"

/* 根据实际的硬件连接更改下面这几项即可 */
#define LED_PROT	GPIOG					//LED端口
#define LED_PIN		GPIO_Pin_13				//LED引脚
#define LED_RCC		RCC_APB2Periph_GPIOG	//LED->GPIO时钟
#define LED 		PGout(13)				//PB.3

void LED_Init(void);						//申明初始化函数
void LedPoint(u16 uiCycle);					//led闪烁处理函数

		 				    
#endif
