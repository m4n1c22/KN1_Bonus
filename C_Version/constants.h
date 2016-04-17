/** 
	\file		:	constants.h
	\author		:	Sreeram Sadasivam
	\brief		:	Constants, macros and enumerations for various headerfiles
	\copyright	:	Copyrights reserved @2016
*/
#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/**MACROS*/
#define MAX_HAMMING_STRING_SIZE		64
#define CHARACTER_TERMINATION		'\0'
#define ASCII_CONV_ZERO				48

/**Enumerations*/
typedef enum Endianess {
	eLittleEndian 	= 0,
	eBigEndian		= 1
}Endianess;

typedef enum MODE {
	eDEBUG 		= 0,
	eEXECUTE	= 1
}MODE;

#endif