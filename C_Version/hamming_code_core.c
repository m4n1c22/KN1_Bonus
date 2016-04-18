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

	int i,j,input_string_len;
	
	j=0;
	/**Calculating the hamming message length*/
	input_string_len = messageLength(input_string,mode);
	/**Loop to generate a hamming outline string with unset parity bits.*/
	for (i = 0; i<input_string_len; )
	{
		/**Condition check to verify if the bit position is a parity position or not.*/
		if ((j+1)==closestPowerOfTwo((j+1), mode))
		{
			/**Set the bit position as empty as indicated by the character _*/
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
	/**To check if the mode being executed was debug or not.*/
	if(mode == eDEBUG) {
		/**function call to display the bitstring.*/
		displayBits(hamming_string);
	}

	return 0;
}

int parityCalculationInHammingStringCoreFunction(char *hamming_string, MODE mode) {

	int i,j,hamming_message_len,parity=0;
	/**Calculating the hamming message length*/
	hamming_message_len = messageLength(hamming_string, mode);
	/** Loop which calculates the parity bits values from the provided message string.*/
	for (i = 0; i < hamming_message_len; i++) {
		
		/**
			Check if the read bit position is a parity bit or not.
			Principle used behind the parity bits unset and set is the priciple used in
			Turing machines when played around with marking messages.
		*/
		if(*(hamming_string+i) == '_') {
			/**Setting it to zero before proceeding.*/
			*(hamming_string+i) = '0';
			/**Loop which calculates the parity of the given message for the corresponding parity bit.*/
			for (j = i+1; j < hamming_message_len; ++j) {
				/**Check if the read bit position matches the parity bit position range.*/
				if (((j+1)&(i+1)) != 0) {
					 /**XORing the incoming bit position with the present parity value.*/
					 parity ^= (*(hamming_string+j) - ASCII_CONV_ZERO);
				}
			}
			/**To check if the mode being executed was debug or not.*/
			if(mode == eDEBUG) {
				/**Prints the resultant parity value.*/
				printf("Parity in Bit Position %d : %d\n", (i+1), parity);
			}
			/**
				Since the values are stored as characters. The resultant parity is converted to equivalent
				character and stored in the hamming string.
			*/
			*(hamming_string+i) = parity + ASCII_CONV_ZERO;
			/**temporary variable for calculatin parity is reset.*/
			parity = 0;
		}
	}
	/**To check if the mode being executed was debug or not.*/
	if(mode == eDEBUG) {
		/**function call to display the bitstring.*/
		displayBits(hamming_string);
	}

	return 0;

}

int hammingStringCopyWithParityResetCoreFunction(char *input_hamming_string, char *new_hamming_string, MODE mode) {

	int len,i;
	/**Calculating the incoming hamming message length*/
	len = messageLength(input_hamming_string,mode);
	/**Loop which unsets all the parity bits in the hamming string.*/
	for (i = 0; i < len; ++i) {
		/**Condition to check if the read bit position is a parity bit position or not.*/
		if((i+1)==closestPowerOfTwo((i+1),mode)) {
			/**Set the bit position as empty as indicated by the character _ */
			*(new_hamming_string+i) = '_';
		}
		else {
			*(new_hamming_string+i) = *(input_hamming_string+i);	
		}

	}
	*(new_hamming_string+i) = CHARACTER_TERMINATION;
	
	/**To check if the mode being executed was debug or not.*/
	if(mode == eDEBUG) {
		/**function call to display the bitstring.*/
		displayBits(new_hamming_string);
	}
	return 0;
}

int parityVerificationCoreFunction(char *received_message, char *calculated_parity_message, MODE mode) {

	int len,i,error_bit=0;
	/**Calculating the incoming hamming message length*/
	len = messageLength(received_message, mode);
	/**Loop which calculates the single bits error if present in the received message.*/
	for (i = 0; i < len; ++i) {
		/**Condition to check if the read bit position is a parity bit position or not.*/
		if((i+1)==closestPowerOfTwo((i+1), mode)) {
			/**Condition to check if the received parity message is different from the calculated one.*/
			if(*(received_message+i) != *(calculated_parity_message+i)) {
				/**If different OR/concatenate the erroroneous bit position by performing logical OR.*/
				error_bit |= (i+1); 
			}
		}
	}
	/**To check if the mode being executed was debug or not.*/
	if (mode == eDEBUG) {
		/**Printing the erroroneous bit position.*/
		printf("Error Bit Position %d\n", error_bit);
	}
	/** Erroroneous bit position.*/
	return error_bit;	
}