/** 
	\file		:	hamming_code.c
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code Convenience Methods.
	\copyright	:	Copyrights reserved @2016
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hamming_code.h"


/** Interface Methods */
int generateInitialHammingString(char *input_string, char *hamming_string, Endianess endian_type, MODE mode) {

	char reverse_string[MAX_HAMMING_STRING_SIZE];
	if(endian_type == eLittleEndian) {
		
		generateInitialHammingStringCoreFunction(input_string, hamming_string, mode);
	}
	else {

		bitStringReversal(input_string, reverse_string, mode);
		generateInitialHammingStringCoreFunction(reverse_string, hamming_string, mode);	
		bitStringReversal(hamming_string, reverse_string, mode);
		bitStringCopy(reverse_string, hamming_string, mode);
	}
	return 0;
}

int parityCalculationInHammingString(char *hamming_string,Endianess endian_type, MODE mode) {

	char reverse_string[MAX_HAMMING_STRING_SIZE];
	if (endian_type == eLittleEndian) {
		parityCalculationInHammingStringCoreFunction(hamming_string, mode);
	}
	else {

		bitStringReversal(hamming_string, reverse_string, mode);
		parityCalculationInHammingStringCoreFunction(reverse_string, mode);	
		bitStringReversal(reverse_string, hamming_string, mode);
		bitStringCopy(reverse_string, hamming_string, mode);
	}
	return 0;
}

int hammingStringCopyWithParityReset(char *input_hamming_string, char *new_hamming_string, Endianess endian_type, MODE mode) {


	char input_hamming_string_reverse[MAX_HAMMING_STRING_SIZE], new_hamming_string_reverse[MAX_HAMMING_STRING_SIZE];

	if (endian_type == eLittleEndian) {

		hammingStringCopyWithParityResetCoreFunction(input_hamming_string, new_hamming_string, mode);
	}
	else {
		bitStringReversal(input_hamming_string, input_hamming_string_reverse, mode);
		hammingStringCopyWithParityResetCoreFunction(input_hamming_string_reverse, new_hamming_string_reverse, mode);
		bitStringReversal(new_hamming_string_reverse, new_hamming_string, mode);	
	}
	return 0;
}

int parityVerification(char *received_message, char *calculated_parity_message, Endianess endian_type, MODE mode) {

	int error_bit=0, message_length;
	char received_message_reverse[MAX_HAMMING_STRING_SIZE], calculated_parity_message_reverse[MAX_HAMMING_STRING_SIZE];

	if (endian_type == eLittleEndian) {

		error_bit = parityVerificationCoreFunction(received_message, calculated_parity_message, mode);		
	}
	else {
		message_length = messageLength(received_message, mode);
		bitStringReversal(received_message, received_message_reverse, mode);
		bitStringReversal(calculated_parity_message, calculated_parity_message_reverse, mode);
		error_bit = parityVerificationCoreFunction(received_message_reverse, calculated_parity_message_reverse, mode);
		error_bit = message_length - error_bit;
	}
	return error_bit;	
}

