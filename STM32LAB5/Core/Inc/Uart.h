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


void HAL_UART_RxCpltCallback ( UART_HandleTypeDef * huart ) {
	if( huart->Instance == USART2 ) {
		buffer [index_buffer++] = temp ;
		if( index_buffer == 30) index_buffer = 0;
		buffer_flag = 1;
		HAL_UART_Receive_IT (& huart2 , & temp , 1) ;
	}

}

#endif /* INC_UART_H_ */
