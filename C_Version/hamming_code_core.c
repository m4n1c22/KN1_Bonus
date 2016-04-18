/** 
	\file		:	hamming_code_core.c
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code Core Implementations.
	\copyright	:	Copyrights reserved @2016
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hamming_code_core.h"

/** CORE FUNCTIONS */
int generateInitialHammingStringCoreFunction(char *input_string, char *hamming_string, MODE mode) {

	int i,j;
	j=0;
	for (i = 0; *(input_string + i) != CHARACTER_TERMINATION; )
	{
		if ((j+1)==closestPowerOfTwo((j+1), mode))
		{
			*(hamming_string+j) = '_';
			j++;
		}
		else {
			*(hamming_string+j) = *(input_string+i);
			j++;
			i++;
		}
	}
	*(hamming_string+j) = CHARACTER_TERMINATION;
	
	if(mode == eDEBUG) {
		displayBits(hamming_string);
	}

	return 0;
}

int parityCalculationInHammingStringCoreFunction(char *hamming_string, MODE mode) {

	int i,j,hamming_message_len,parity=0;

	hamming_message_len = messageLength(hamming_string, mode);

	for (i = 0; i < hamming_message_len; i++)
	{
		if(*(hamming_string+i) == '_') {
			*(hamming_string+i) = '0';
			for (j = i+1; j < hamming_message_len; ++j)
			{
				if (((j+1)&(i+1)) != 0)
				{
					 parity ^= (*(hamming_string+j) - ASCII_CONV_ZERO);
				}
			}
			if(mode == eDEBUG) {
				printf("Parity in Bit Position %d : %d\n", (i+1), parity);
			}
			*(hamming_string+i) = parity + ASCII_CONV_ZERO;
			parity = 0;
		}
	}

	if(mode == eDEBUG) {
		displayBits(hamming_string);
	}

	return 0;

}

int hammingStringCopyWithParityResetCoreFunction(char *input_hamming_string, char *new_hamming_string, MODE mode) {

	int len,i;
	len = messageLength(input_hamming_string,mode);
	for (i = 0; i < len; ++i)
	{
		if((i+1)==closestPowerOfTwo((i+1),mode)) {
			*(new_hamming_string+i) = '_';
		}
		else {
			*(new_hamming_string+i) = *(input_hamming_string+i);	
		}

	}
	*(new_hamming_string+i) = CHARACTER_TERMINATION;
	if(mode == eDEBUG) {
		
		displayBits(new_hamming_string);
	}
	return 0;
}

int parityVerificationCoreFunction(char *received_message, char *calculated_parity_message, MODE mode) {

	int len,i,error_bit=0;
	len = messageLength(received_message, mode);
	for (i = 0; i < len; ++i)
	{
		if((i+1)==closestPowerOfTwo((i+1), mode)) {
			if(*(received_message+i) != *(calculated_parity_message+i)) {
				error_bit |= (i+1); 
			}
		}
	}
	if (mode == eDEBUG)
	{
		printf("Error Bit Position %d\n", error_bit);
	}
	return error_bit;	
}