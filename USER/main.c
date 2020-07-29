/*************************************************************************************
�ļ����ƣ�main.c
��    ����V1.0
��    �ڣ�2020-5-11
��    ����Eric Xie
˵    ����������ֻΪʵ��485ͨѶ  ������Ҫʵ���ߺͷ��������ڸ���Ӧ�ã����ڴ˻�������������
		  ��������������
�޸���־��



**************************************************************************************/

/* ����ͷ�ļ� */
#include "led.h"		
#include "key.h"
#include "delay.h"		
#include "sys.h"
#include "usart.h"
#include "timer.h"
#include "rs485.h"
#include "demo.h"
#include "wifi.h"


int main(void)
{ 
	delay_init();	    							//��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);	//����ϵͳ�ж����ȼ�����4	 
	uart_init(115200);								//��ʼ������1 ���ڴ�ӡ���� ������Ϊ115200
	LED_Init();		  								//��ʼ��LED
	KeyInit();										//��ʼ������
	ESP8266_init();
	RS485_Init(9600);								//��ʼ��485���� ������Ϊ9600
	printf("chongqi\n");
	TIMER3_Init(999,71);							//��ʱ��3��ʼ�� ����1ms
	WIFI_init();

	while(1)
	{
		UartDriver();								//�������ݴ���
		TestOpr();									//���Թ��ܺ���
	}
}