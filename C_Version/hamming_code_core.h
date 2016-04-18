/** 
	\file		:	hamming_code_core.h
	\author		:	Sreeram Sadasivam
	\brief		:	Hamming Code Core Methods
	\copyright	:	Copyrights reserved @2016
*/

#include "constants.h"
#include "common.h"


#ifndef HAMMING_CODE_CORE_H_
#define HAMMING_CODE_CORE_H_

/** CORE FUNCTIONS */

/**
	\function name	:	generateInitialHammingStringCoreFunction()
	\function type 	:	Core Function
	\brief			:	Generates the initial hamming string by appending parity bits to the existent input bit string.
						Function transforms the string to be padded with parity bits but, leaves the field of parity bits
						as empty. parityCalculationInHammingStringCoreFunction() calculates the parity bits.

	\param 	input_string 	The input bit string which is transformed into hamming string with padded unset parity bits.
	\param 	hamming_string 	The resultant bit string after the above transformation with padding of unset parity bits.
	\param 	mode 			Dictates the execution mode of the function.

*/
int generateInitialHammingStringCoreFunction(char *input_string, char *hamming_string, MODE mode);

/**
	\function name	:	parityCalculationInHammingStringCoreFunction()
	\function type 	:	Core Function
	\brief			:	parityCalculationInHammingStringCoreFunction() calculates the parity bits in provided hamming string.
						It is generally used with the method generateInitialHammingStringCoreFunction() and also with the methods
						for verification of parity.
	
	\param 	hamming_string 	Hamming string in which parity bits are calculated and set.
	\param 	mode 			Dictates the execution mode of the function.

*/
int parityCalculationInHammingStringCoreFunction(char *hamming_string, MODE mode);

/**
	\function name	:	hammingStringCopyWithParityResetCoreFunction()
	\function type 	:	Core Function
	\brief			:	Generates a hamming string after unsetting all the parity bits later for calculation. Usually used
						for parity verification or even for checking errors. Original is message string is first copied 
						and unset using this method. Later parity is calculated on the newly generated unset hamming string
						by calling the method parityCalculationInHammingStringCoreFunction() internally. Finally verifying
						the parity by calling the method parityVerificationCoreFunction().

	\param 	input_hamming_string 	The input hamming string which is transformed into hamming string with unset parity bits.
	\param 	new_hamming_string 		The resultant bit string after unset parity bits.
	\param 	mode 					Dictates the execution mode of the function.

*/
int hammingStringCopyWithParityResetCoreFunction(char *input_hamming_string, char *new_hamming_string, MODE mode);

/**
	\function name	:	parityVerificationCoreFunction()
	\function type 	:	Core Function
	\brief			:	parityVerificationCoreFunction() verifies the parity bits in provided hamming string. By verifying the 
						resultant parity with the received parity bit string. Generally invoked from parityVerification() interface
						method from application. The method compares the expected parity bits to the one received and obtains the 
						possible single bit errors.
	
	\param 	received_message 			Message which was received by the receiver.
	\param 	calculated_parity_message 	Message which was calculated by the receiver on the received message.
	\param 	mode 						Dictates the execution mode of the function.

*/
int parityVerificationCoreFunction(char *received_message, char *calculated_parity_message, MODE mode);

#endif