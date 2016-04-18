/** 
	\file		:	constants.h
	\author		:	Sreeram Sadasivam
	\brief		:	Constants, macros and enumerations for various headerfiles
	\copyright	:	Copyrights reserved @2016
*/
#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/**MACROS*/
#define MAX_HAMMING_STRING_SIZE		64 		/**Defined as a limiting factor for the size of hamming string generated.*/
#define CHARACTER_TERMINATION		'\0'	/**Null character or some say slash zero indicating end of string.*/
#define ASCII_CONV_ZERO				48		/**48 is the ASCII equivalence of 0.*/

/**Enumerations*/

/**Used to represent the endianess of the system. Some systems are defined to be Big Endian or Little Endian.*/
typedef enum Endianess {
	eLittleEndian 	= 0,	/**Little Endianess is where the Least Significant byte is in the left most entry.*/
	eBigEndian		= 1		/**Big Endian is where the Most Significant byte is in the left most entry.*/
}Endianess;

/**Mode defines the execution mode the program runs..*/
typedef enum MODE {
	eDEBUG 		= 0,	/**Runs in Debug mode*/
	eEXECUTE	= 1		/**Runs in Execution mode.*/
}MODE;

#endif