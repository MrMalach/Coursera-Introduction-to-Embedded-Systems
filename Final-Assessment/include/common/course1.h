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


#ifndef COURSE1_H
#define COURSE1_H


#include "data.h"


/**
 * @brief Calls all functions in order to check the final assessment.
 *
 * @return 0 if successfull -1 else.
 */
int8_t course1();


/**
 * @brief atoi() & itoa() check.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_data1();


/**
 * @brief atoi() & itoa() check.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_data2();


/**
 * @brief Test non-overlapped memmove.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_memmove1();

/**
 * @brief Test overlapped memmove where there is overlap of the 
 *          end of destination and start of the source regions.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_memmove2();

/**
 * @brief Test overlapped memmove where there is overlap of the 
 *          start of destination and end of the source regions.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_memmove3();

/**
 * @brief Test memcopy.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_memcopy();


/**
 * @brief Test memset and memzero.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_memset();

/**
 * @brief Test reverse.
 *
 * @return 0 if successfull -1 else.
 */
int8_t test_reverse();


#endif //COURSE1_H