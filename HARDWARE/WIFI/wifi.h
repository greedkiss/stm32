#ifndef _WIFI_H
#define _WIFI_H

#include "delay.h"
#include "string.h"
#include "stdio.h"

void ESP8266_init(void);

void WIFI_init(void);

#define UART4_NUM 100

extern u8 receive_str[UART4_NUM];

extern void tcp_connect(int len);

extern void uart4SendChars(u8 *str, u16 strlen);
#endif
