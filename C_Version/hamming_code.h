/** 
	\file		:	hamming_code.h
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code Convenience Methods
	\copyright	:	Copyrights reserved @2016
*/

#include "constants.h"
#include "common.h"


#ifndef HAMMING_CODE_H_
#define HAMMING_CODE_H_

/** CORE FUNCTIONS */
int generateInitialHammingStringCoreFunction(char *input_string, char *hamming_string, MODE mode);

int parityCalculationInHammingStringCoreFunction(char *hamming_string, MODE mode);

int hammingStringCopyWithParityResetCoreFunction(char *input_hamming_string, char *new_hamming_string, MODE mode);

int parityVerificationCoreFunction(char *received_message, char *calculated_parity_message, MODE mode);

/** Interface Methods */
int generateInitialHammingString(char *input_string, char *hamming_string, Endianess endian_type, MODE mode);

int parityCalculationInHammingString(char *hamming_string,Endianess endian_type, MODE mode);

int hammingStringCopyWithParityReset(char *input_hamming_string, char *new_hamming_string, Endianess endian_type, MODE mode);

int parityVerification(char *received_message, char *calculated_parity_message, Endianess endian_type, MODE mode);

#endif