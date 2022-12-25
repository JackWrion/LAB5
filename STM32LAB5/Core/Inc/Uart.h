/*
 * Uart.h
 *
 *  Created on: Dec 25, 2022
 *      Author: ASUS
 */

#ifndef INC_UART_H_
#define INC_UART_H_

# define MAX_BUFFER_SIZE 30
uint8_t temp = 0;
uint8_t buffer [ MAX_BUFFER_SIZE ];
uint8_t index_buffer = 0;
uint8_t buffer_flag = 0;

int command_data = 0;
int command_flag = 0;

extern UART_HandleTypeDef huart2;


void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart ) {
	if( huart->Instance == USART2 ) {
		HAL_UART_Receive_IT (& huart2 , & temp , 1) ;
		index_buffer++;
		if (index_buffer >= MAX_BUFFER_SIZE){
			index_buffer = 0;
		}
		buffer[index_buffer] = temp;
		buffer_flag = 1;
	}
}

#endif /* INC_UART_H_ */
