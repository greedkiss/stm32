#ifndef _WIFI_H
#define _WIFI_H

#include "delay.h"
#include "string.h"
#include "stdio.h"

void ESP8266_init(void);

void WIFI_init(void);

#define USART3_NUM 100

extern u8 receive_str[USART3_NUM];

extern void tcp_connect(int len);

extern void USART3SendChars(u8 *str, u16 strlen);
#endif
