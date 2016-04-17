/** 
	\file		:	common.h
	\author		:	Sreeram Sadasivam
	\brief		:	Common methods and convenience methods are defined here.
	\copyright	:	Copyrights reserved @2016
*/

#include "constants.h"
#include <stdio.h>
#include <stdlib.h>	


#ifndef COMMON_H_
#define COMMON_H_


int displayBits(char *bit_string);

int messageLength(char *message,MODE mode);

int closestPowerOfTwo(int input_number,MODE mode);

int bitStringReversal(char *input_bit_string, char *reverse_bit_string, MODE mode);

int bitStringCopy(char *src_bit_string, char *dest_bit_string, MODE mode);

#endif