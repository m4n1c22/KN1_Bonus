/** 
	\file		:	hamming_code_convenience.h
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code Convenience Methods
	\copyright	:	Copyrights reserved @2016
*/

#include "constants.h"
#include "common.h"


#ifndef HAMMING_CODE_CONVENIENCE_H_
#define HAMMING_CODE_CONVENIENCE_H_


int generateInitialHammingString(char *input_string,char *hamming_string,Endianess endian_type) {

	int i,j;
	if(endian_type == eLittleEndian) {
		j=0;
		for (i = 0; *(input_string + i) != CHARACTER_TERMINATION; )
		{
			if ((j+1)==closestPowerOfTwo((j+1),eEXECUTE))
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
	}
	else {

	}
	return 0;
}

int parityCalculationInHammingString(char *hamming_string,Endianess endian_type) {

	int i,j,hamming_message_len,parity=0;

	hamming_message_len = messageLength(hamming_string,eEXECUTE);

	if (endian_type == eLittleEndian) {
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
				printf("Parity in Bit Position %d : %d\n", (i+1), parity);
				*(hamming_string+i) = parity + ASCII_CONV_ZERO;
				parity = 0;
			}
		}
	}
}

int hammingStringCopyWithParityReset(char *input_hamming_string, char *new_hamming_string) {

	int len,i;
	len = messageLength(input_hamming_string,eEXECUTE);
	for (i = 0; i < len; ++i)
	{
		if((i+1)==closestPowerOfTwo((i+1),eEXECUTE)) {
			*(new_hamming_string+i) = '_';
		}
		else {
			*(new_hamming_string+i) = *(input_hamming_string+i);	
		}

	}
	*(new_hamming_string+i) = CHARACTER_TERMINATION;
	return 0;
}

int parityVerification(char *received_message, char *calculated_parity_message, Endianess endian_type) {

	int len,i,error_bit=0;
	len = messageLength(received_message,eEXECUTE);
	if (endian_type == eLittleEndian) {
		for (i = 0; i < len; ++i)
		{
			if((i+1)==closestPowerOfTwo((i+1),eEXECUTE)) {
				if(*(received_message+i) != *(calculated_parity_message+i)) {
					error_bit |= (i+1); 
				}
			}
		}
	}
	else {

	}
	return error_bit;	
}

#endif