
/* 头文件 */
#include "demo.h"
#include "key.h"
#include "rs485.h"
#include "usart.h"
#include "delay.h"

int device = 5;
u32 time = 0;
int i = 1;



/****************************************************************************************************
 * 函数名称： void TestOpr(void)
 * 入口参数：无
 * 返回  值：无
 * 功能说明：用按键模拟实现 和从机通读测试，从机可用PC机的串口调试助手来接收，应答等操作
 *           READ按键按下后，向从机(PC模拟)发送读命令  从机(PC端模拟应答)后，按键再按方有效
 *			 WRITE按键按下后，向从机(PC模拟)发送写命令 从机(PC端模拟应答)后，按键再按方有效
 ***************************************************************************************************/
void TestOpr(void)
{
	//u8 ucKeyVal = 0;
	//NH3传感器
	//设备号0x05
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
//		//一个轮询已经做完，睡眠间隔时间
//			time = 0;
//			device = 6;
//		}
		if(i == 1){
			i = 0;
			RS485_RW_Opr(0x02, READ, 0x00, 0x02);
		}
		else if(i == 0){
			i = 1;
			printf("氨气\n");
			RS485_RW_Opr(0x05, READ, 0x00, 0x01);
		}
	}
}

void countTime(){
	time++;
}
