#ifndef __RS485_H
#define __RS485_H			

#include "sys.h"	 								  


/* ����������ã�����������ڸ��������⼸��� */
#define	RS485_PROT		GPIOB					//���ڶ˿�
#define RS485_GPIO_RCC	RCC_APB2Periph_GPIOB	//���ڶ˿�GPIOʱ��
#define RS485_TX_Pin	GPIO_Pin_10				//����TXD����
#define RS485_RX_Pin	GPIO_Pin_11				//����RXD����
#define RS485_USART_RCC	RCC_APB1Periph_USART3	//���ڹ���ʱ��
#define RS485_USART_NUM	USART3					//����ͨ��

/* 485ģʽ������������ ����������������⼸��� */
#define	RS485_MODE_PROT	GPIOD					//RS485ģʽ���ƶ˿�
#define RS485_MODE_Pin	GPIO_Pin_11				//RS485ģʽ��������
#define RS485_MODE_RCC	RCC_APB2Periph_GPIOD	//RS485ģʽ���ƶ˿�GPIOʱ��
#define RS485_TX_EN		PDout(11)				//485ģʽ����.0,����;1,����

/* ����봮���жϽ��գ��벻Ҫע�����º궨�� */
#define EN_USART3_RX 	1						//0,������;1,����.


extern u8 RS485Busy ;

void RS485_Init(u32 bound);
void RS485_RW_Opr(u8 ucAddr,u8 ucCmd,u16 ucReg,u16 uiDate);
void UartDriver(void);
void UartRxMonitor(u8 ms);


#endif	   















