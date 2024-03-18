/*
 * uart.c
 *
 *  Created on: Mar 11, 2024
 *      Author: POS
 */

#include "uart.h"
#include <stdio.h>

UART_HandleTypeDef *myHuart;

#define rxBufferMax 255


int rxBufferGp; //get pointer read
int rxBufferPp; // put pointer write
uint8_t rxBuffer[rxBufferMax];
uint8_t rxChar;

void initUart(UART_HandleTypeDef *inHuart){
	myHuart = inHuart;
	HAL_UART_Receive_IT(myHuart, &rxChar, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	rxBuffer[rxBufferPp++] = rxChar;
	rxBufferPp %= rxBufferMax;
	HAL_UART_Receive_IT(myHuart, &rxChar, 1);

}

uint8_t getChar(){

		uint8_t result;
		if(rxBufferGp == rxBufferPp) return 0;
		result = rxBuffer[rxBufferGp ++];
		rxBufferGp %= rxBufferMax;
		return result;
}

int _write(int file, char *p, int len)
{
	HAL_UART_Transmit(myHuart,p,len,10);
	return len;
}
