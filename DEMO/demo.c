
/* ͷ�ļ� */
#include "demo.h"
#include "key.h"
#include "rs485.h"
#include "usart.h"
#include "delay.h"

int device = 5;
u32 time = 0;
int i = 1;



/****************************************************************************************************
 * �������ƣ� void TestOpr(void)
 * ��ڲ�������
 * ����  ֵ����
 * ����˵�����ð���ģ��ʵ�� �ʹӻ�ͨ�����ԣ��ӻ�����PC���Ĵ��ڵ������������գ�Ӧ��Ȳ���
 *           READ�������º���ӻ�(PCģ��)���Ͷ�����  �ӻ�(PC��ģ��Ӧ��)�󣬰����ٰ�����Ч
 *			 WRITE�������º���ӻ�(PCģ��)����д���� �ӻ�(PC��ģ��Ӧ��)�󣬰����ٰ�����Ч
 ***************************************************************************************************/
void TestOpr(void)
{
	//u8 ucKeyVal = 0;
	//NH3������
	//�豸��0x05
	if(!RS485Busy){
//		if(device == 5 || time > ){
//			RS485_RW_Opr(0x05, READ, 0x00, 0x01);
//		}else if(device == 4){
//			RS485_RW_Opr(0x04, READ, 0x00, 0x02);
//		}else if(device == 3){
//			RS485_RW_Opr(0x03, READ, 0x00, 0x03);
//		}else if(device == 2){
//			RS485_RW_Opr(0x02, READ, 0x00, 0x02);
//		}else if(device == 1){
//			RS485_RW_Opr(0x01, READ, 0x00, 0x02);
//		}else if(device == 0){
//		//һ����ѯ�Ѿ����꣬˯�߼��ʱ��
//			time = 0;
//			device = 6;
//		}
		if(i == 1){
			i = 0;
			RS485_RW_Opr(0x02, READ, 0x00, 0x02);
		}
		else if(i == 0){
			i = 1;
			printf("����\n");
			RS485_RW_Opr(0x05, READ, 0x00, 0x01);
		}
	}
}

void countTime(){
	time++;
}
