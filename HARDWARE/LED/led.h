#ifndef __LED_H
#define __LED_H	 

#include "sys.h"

/* ����ʵ�ʵ�Ӳ�����Ӹ��������⼸��� */
#define LED_PROT	GPIOE					//LED�˿�
#define LED_PIN		GPIO_Pin_5				//LED����
#define LED_RCC		RCC_APB2Periph_GPIOE	//LED->sGPIOʱ��
#define LED 		PEout(5)				//PB.3

void LED_Init(void);						//������ʼ������
void LedPoint(u16 uiCycle);					//led��˸������

		 				    
#endif
