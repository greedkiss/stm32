#ifndef __KEY_H
#define __KEY_H

#include "sys.h"

/* ����GPIO�������ã���������������ţ��޸������⼸���ֵ���� */
#define KEY_PORT			GPIOF
#define KEY_READ_Pin		GPIO_Pin_2
#define KEY_WRITE_Pin		GPIO_Pin_3
#define KEY_RCC				RCC_APB2Periph_GPIOF
#define KEY_READ			GPIO_ReadInputDataBit(KEY_PORT,KEY_READ_Pin)				
#define KEY_WRITE  			GPIO_ReadInputDataBit(KEY_PORT,KEY_WRITE_Pin)	

#define PRES_READ			1
#define PRES_WRITE			2

void KeyInit(void);
u8 KeyScan(unsigned char ucMode);

#endif
