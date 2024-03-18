/*
 * uart.h
 *
 *  Created on: Mar 11, 2024
 *      Author: POS
 */

#ifndef INC_UART_H_
#define INC_UART_H_


#include "main.h"
#include <stdio.h>


void initUart(UART_HandleTypeDef *inHuart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
uint8_t getChar();

#endif /* INC_UART_H_ */
