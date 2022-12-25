/*
 * uart_communiation.h
 *
 *  Created on: Dec 25, 2022
 *      Author: ASUS
 */

#ifndef INC_UART_COMMUNIATION_H_
#define INC_UART_COMMUNIATION_H_

#include "Uart.h"

extern ADC_HandleTypeDef hadc1;
uint32_t ADC_value;
int change = 0;
char str[100];


void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){
	ADC_value = HAL_ADC_GetValue(&hadc1);
	change = 1;
}


void uart_communication_fsm(){
	if (command_data == 1){

		if (change && timer2_flag == 1){
			change = 0;
			setTimer2(1000);
			int len = sprintf(str, "!ADC=%lu#\n\r", ADC_value);
			HAL_UART_Transmit(&huart2, (void*)str , len , 1000);
		}
	}

	if (command_flag == 1){
		int len = sprintf(str, "!STOP=%lu#\n\r", ADC_value);
		HAL_UART_Transmit(&huart2, (void*)str , len , 1000);
		command_data = 0;
		command_flag = 0;
	}
}






#endif /* INC_UART_COMMUNIATION_H_ */
