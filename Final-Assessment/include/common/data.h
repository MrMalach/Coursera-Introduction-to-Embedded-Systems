/******************************************************************************
 * Copyright (C) 2021 by Ran Malach
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/


#ifndef DATA_h
#define DATA_H


#include "memory.h"


/**
 * @brief Convert signed number to charecter string.
 *
 * Integer-to-ASCII needs to convert data from a standard integer type into an ASCII string.
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The number you wish to convert is passed in as a signed 32-bit integer.
 * 
 * You should be able to support bases 2 to 16 by specifying the integer value 
 * of the base you wish to convert to (base).
 * 
 * Copy the converted character string to the uint8_t* pointer passed in as a parameter (ptr)
 * The signed 32-bit number will have a maximum string size (Hint: Think base 2).
 * You must place a null terminator at the end of the converted c-string
 * Function should return the length of the converted data (including a negative sign). 
 * Example my_itoa(ptr, 1234, 10) should return an ASCII string length of 5 (including the null terminator).
 * 
 * This function needs to handle signed data.
 * 
 * You may not use any string functions or libraries
 *
 * @param data Number to convert.
 * @param ptr pointer to charecter string
 * @param base base of number.
 *
 * @return Length of the converted data.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief Convert charecter string to signed number. 
 *
 * ASCII-to-Integer needs to convert data back from an ASCII
 *  represented string into an integer type.
 * 
 * All operations need to be performed using pointer arithmetic, not array indexing
 * The character string to convert is passed in as a uint8_t * pointer (ptr).
 * The number of digits in your character set is passed in as a uint8_t integer (digits).
 * You should be able to support bases 2 to 16.
 * The converted 32-bit signed integer should be returned.
 * 
 * This function needs to handle signed data.
 * 
 * You may not use any string functions or libraries
 *
 * @param ptr pointer to charecter string.
 * @param digits Number of digits in string.
 * @param base base of number.
 *
 * @return The number converted.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief Compare two NULL terminated character strings. 
 *
 * 
 * @param s1 pointer to 1st character string.
 * @param s2 pointer to 2nd character string.
 *
 * @return -1 : s1 < s2	,
 *          1 : s1 > s2 ,
 *	        0 : s1 = s2
 */
int8_t my_strcmp(uint8_t* s1, uint8_t* s2);

/**
 * @brief Count NULL terminated character string. 
 *
 * 
 * @param s1 pointer to character string.
 *
 * @return count of characters
 */
size_t my_strlen(uint8_t* ptr);

#endif //DATA_H