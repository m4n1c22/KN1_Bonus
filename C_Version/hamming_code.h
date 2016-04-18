/** 
	\file		:	hamming_code.h
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code Convenience Methods
	\copyright	:	Copyrights reserved @2016
*/

#include "constants.h"
#include "common.h"
#include "hamming_code_core.h"

#ifndef HAMMING_CODE_H_
#define HAMMING_CODE_H_

/** Interface Methods */

/**Interface call for the core function generateInitialHammingStringCoreFunction()*/
int generateInitialHammingString(char *input_string, char *hamming_string, Endianess endian_type, MODE mode);
/**Interface call for the core function parityCalculationInHammingStringCoreFunction()*/
int parityCalculationInHammingString(char *hamming_string,Endianess endian_type, MODE mode);
/**Interface call for the core function hammingStringCopyWithParityResetCoreFunction()*/
int hammingStringCopyWithParityReset(char *input_hamming_string, char *new_hamming_string, Endianess endian_type, MODE mode);
/**Interface call for the core function parityVerificationCoreFunction())*/
int parityVerification(char *received_message, char *calculated_parity_message, Endianess endian_type, MODE mode);

#endif