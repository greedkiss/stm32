#include "wifi.h"
#include "delay.h"
#include "string.h"
#include "stdio.h"


int uart_byte_count=0;
u8 receive_str[USART3_NUM];

u8 MODE[]="AT+CWMODE=1\r\n";
u8 RST[]="AT+RST\r\n";
u8 Router[]="AT+CWJAP=\"office-405\",\"wjy13018025158\"\r\n";
u8 CHECK[]="AT+CIFSR\r\n";
u8 SERVER[]="AT+CIPSTART=\"TCP\",\"39.100.89.12\",8000\r\n"; //连接服务器
char SEND_MOD[50]; //透传


void USART3_init(u32 bound)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE); 
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;  
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	//复用推挽输出
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;//浮空输入
  GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=4 ;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	USART_InitStructure.USART_BaudRate = bound;//一般设置为9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;//字长为8位数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;//一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;//无奇偶校验位
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;	//收发模式

	USART_Init(USART3, &USART_InitStructure); //初始化串口
  USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//开启中断
  USART_Cmd(USART3, ENABLE);
}


void ESP8266_init(void)
{
 	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;    
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;      
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;      
	GPIO_Init(GPIOE,&GPIO_InitStructure);          
	GPIO_SetBits(GPIOE,GPIO_Pin_1);
}

void USART3SendChar(u8 ch)
{      
	while((USART3->SR&0x40)==0);  
  USART3->DR = ch;      
}
/****************************************************************************
* 名    称: void USART3SendChars(u8 *str, u16 strlen)
* 功    能：串口4发送一字符串
* 入口参数：*str：发送的字符串
            strlen：字符串长度
* 返回参数：无
* 说    明： 
****************************************************************************/
void USART3SendChars(u8 *str, u16 strlen)
{ 
	 u16 k= 0 ; 
   do { USART3SendChar(*(str + k)); k++; }   //循环发送,直到发送完毕   
   while (k < strlen); 
} 

void WIFI_init(void)
{
	USART3_init(115200);	    //串口初始化波特率为115200  wifi模块出厂配置的波特率为115200
	
	USART3SendChars(MODE,sizeof(MODE));   
	delay_ms(1000);
	
	USART3SendChars(RST,sizeof(RST));   //重启模块
	delay_ms(1000);	
	

	USART3SendChars(Router,sizeof(Router)); 
	delay_ms(1000);   
	delay_ms(1000);                         


	USART3SendChars(CHECK,sizeof(CHECK));
	delay_ms(1000);
	

	USART3SendChars(SERVER,sizeof(SERVER));  
	delay_ms(1000);
	   
}

void tcp_connect(int len){
	USART3SendChars(SERVER,sizeof(SERVER));  
	delay_ms(1000);
	
	sprintf(SEND_MOD, "AT+CIPSEND=%d\r\n", len);
	
	USART3SendChars((u8*)SEND_MOD,sizeof(SEND_MOD));  
	delay_ms(1000);   
}

void USART3_IRQHandler(void)
{
	u8 rec_data;	    
 	if(USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) 	//接收到数据
	{	 
		rec_data =USART_ReceiveData(USART3); 					//读取接收到的数据
		if(uart_byte_count < 100)
		{
				receive_str[uart_byte_count] = rec_data;			//记录接收到的值
				uart_byte_count ++;//接收数据增加1 
											
		} else {
			uart_byte_count = 0;
		}
	}	
}





