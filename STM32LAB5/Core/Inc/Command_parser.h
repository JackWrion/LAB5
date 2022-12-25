/*
 * Command_parser.h
 *
 *  Created on: Dec 25, 2022
 *      Author: ASUS
 */

#ifndef INC_COMMAND_PARSER_H_
#define INC_COMMAND_PARSER_H_

#include "Uart.h"

uint8_t state = '0'; //default

void command_parser_fsm(){

	switch(state){
	case '0':
		if (buffer[index_buffer] == '!') state = '!';
		break;

	case '!':
		if (buffer[index_buffer] == 'R') state = 'R';
		else if (buffer[index_buffer] == 'O') {
			setTimer1(3000);
			state = 'O';
		}
		else state = '0';
		break;

	case 'R':
		if (buffer[index_buffer] == 'S') state = 'S';
		else state = '0';
		break;
	case 'S':
		if (buffer[index_buffer] == 'T') state = 'T';
		else state = '0';
		break;
	case 'T':
		if (buffer[index_buffer] == '#') {
			setTimer2(1000);
			command_data = 1;
			state = '0';
		}
		else state = '0';
		break;

	case 'O':
		if (buffer[index_buffer] == 'K') state = 'K';
		else state = '0';
		break;
	case 'K':
		if (buffer[index_buffer] == '#') {
			setTimer2(1000);
			command_flag = 1;
			state = '0';
		}
		else state = '0';
		break;

	}

}



#endif /* INC_COMMAND_PARSER_H_ */
