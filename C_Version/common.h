/** 
	\file		:	common.h
	\author		:	Sreeram Sadasivam
	\brief		:	Common methods and convenience methods are defined here.
	\copyright	:	Copyrights reserved @2016
*/

#include "constants.h"

#ifndef COMMON_H_
#define COMMON_H_


/**
	Function to display the bit String. Usually used for debugging the code in use.
*/
int displayBits(char *bit_string) {
	
	for (int i = 0; *(bit_string + i) != CHARACTER_TERMINATION; ++i)
	{
		printf("%c", *(bit_string + i));
	}
	printf("\n");
	return 0;
}

int messageLength(char *message,MODE mode) {

	int len;
	for (len = 0; *(message+len) != CHARACTER_TERMINATION; ++len);

	if(mode == eDEBUG) {
		printf("MessageLength : %d\n", len);
	}
	return len;
}

int closestPowerOfTwo(int input_number,MODE mode) {

	int value = input_number;
	value--;
	value |= value>>1;
	value |= value>>2;
	value |= value>>4;
	value |= value>>8;
	value |= value>>16;
	value++;
	if (mode == eDEBUG)
	{
		printf("closestPowerOfTwo : %d\n", value);
	}
	return value;
}

#endif