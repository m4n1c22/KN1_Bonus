/** 
	\file		:	hamming_code.c
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

/**MACROS*/
#define MAX_HAMMING_STRING_SIZE		64
#define CHARACTER_TERMINATION		'\0'
#define ASCII_CONV_ZERO				48

/**Enumeration*/
typedef enum Endianess {
	eLittleEndian 	= 0,
	eBigEndian		= 1
}Endianess;

typedef enum MODE {
	eDEBUG 		= 0,
	eEXECUTE	= 1
}MODE;


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

int hammingCodeGeneration(char *input_string, Endianess endian_type) {

	int data_bit_length,nearest_power_of_two;

	char hamming_string[MAX_HAMMING_STRING_SIZE];

	data_bit_length = messageLength(input_string,eEXECUTE);

	nearest_power_of_two = closestPowerOfTwo(data_bit_length,eDEBUG);

	if(endian_type == eLittleEndian) {
		
		generateInitialHammingString(input_string,hamming_string,eLittleEndian);
		displayBits(hamming_string);
		parityCalculationInHammingString(hamming_string,eLittleEndian);
		displayBits(hamming_string);
	}	
	else {

	}
	return 0;
}

int main(int argc, char const *argv[])
{
	
	if(messageLength((char*)argv[argc-1],eEXECUTE)>=32) {
		printf("Hamming Limit for program exceeded. Modify in the program for the same.\n");
	}
	else {
		displayBits((char*) argv[argc-1]);
		hammingCodeGeneration((char*) argv[argc-1],eLittleEndian);
	}
	return 0;
}
