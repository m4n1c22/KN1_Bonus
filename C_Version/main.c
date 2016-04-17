/** 
	\file		:	main.c
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code test.
	\copyright	:	Copyrights reserved @2016
*/

/**

Develop an application that creates hamming codes for a given length, 
required error recognition, and required error correction.
The application should further calculate and explain the error correction 
and error detection of multple words from undefined length of a user 
input

*/

#include <stdio.h>
#include <string.h>

#include "constants.h"
#include "common.h"
#include "hamming_code.h"


int hammingCodeGeneration(char *input_string, Endianess endian_type) {

	int data_bit_length,nearest_power_of_two;

	char hamming_string[MAX_HAMMING_STRING_SIZE];

	data_bit_length = messageLength(input_string, eEXECUTE);

	nearest_power_of_two = closestPowerOfTwo(data_bit_length, eDEBUG);

		
	generateInitialHammingString(input_string, hamming_string, endian_type, eEXECUTE);
	displayBits(hamming_string);
	parityCalculationInHammingString(hamming_string, endian_type, eEXECUTE);
	displayBits(hamming_string);

	return 0;
}


int hammingCodeVerification(char *input_hamming_string, Endianess endian_type) {

	char verify_hamming_string[MAX_HAMMING_STRING_SIZE];
	int error_bit;
	hammingStringCopyWithParityReset(input_hamming_string, verify_hamming_string, endian_type, eEXECUTE);
	displayBits(verify_hamming_string);
	parityCalculationInHammingString(verify_hamming_string, endian_type, eEXECUTE);
	error_bit = parityVerification(input_hamming_string, verify_hamming_string, endian_type, eEXECUTE);
	if(error_bit != 0) {
		printf("Single Bit Error in Bit Position : %d\n", error_bit);
	}
	else {
		printf("No Single Bit errors\n");
	}
	
	return 0;
}

int main(int argc, char const *argv[])
{
	
	if((messageLength((char*)argv[argc-2],eEXECUTE)>=32)&&(messageLength((char*)argv[argc-1],eEXECUTE)>=32)) {
		printf("Hamming Limit for program exceeded. Modify in the program for the same.\n");
	}
	else {
		//Hamming Code Generation
		printf("Hamming Code Generation\n");
		displayBits((char*) argv[argc-2]);
		hammingCodeGeneration((char*) argv[argc-2],eBigEndian);

		printf("Hamming Code Verification\n");
		//Hamming Code Verification
		displayBits((char*) argv[argc-1]);
		hammingCodeVerification((char*)argv[argc-1],eBigEndian);

	}
	return 0;
}
