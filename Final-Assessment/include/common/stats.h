/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Analizing an array of unsigned char
 *
 * Element Analiticts:
 * 1. Maximum.
 * 2. Minimum.
 * 3. Mean.
 * 4. Median.
 *
 * @author Ran Malach
 * @date 31/10/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include <stdlib.h>
#include <stdint.h>
#include "platform.h"

void print_array(const uint8_t *, const unsigned int );
/*    Given an array of data and a length, 
        prints the array to the screen   */

void print_statistics(  const uint8_t *, const unsigned int);
/*   A function that prints the statistics of an array 
    including minimum, maximum, mean, and median.   */

void sort_array(uint8_t *, unsigned int);
/*  Given an array of data and a length, 
    sorts the array from largest to smallest.  
    (The zeroth Element should be the largest 
    value, and the last element (n-1) should 
    be the smallest value. )               
    
    Divied & concur algorithm 
    Complexity O(nlogn)
    Space O(1)

    * @param Pointer to the array.
    * @param SIZE of the array.
    * 
    * @return void
    */

const uint8_t find_maximum(const uint8_t* const 
                                   , const unsigned int);
/**
 * @brief Find maximum element of an array
 *
 * Traverse all elements in the array,
 * Find it's maximun value.
 * Complexity O(n)
 * Space O(1)
 * 
 * @param Pointer to the array.
 * @param SIZE of the array.
 * 
 * @return uint8_t - max element.
 */

const uint8_t find_minimum(const uint8_t* const
                                    , const unsigned int);
/**
 * @brief Find minimum element of an array
 *
 * Traverse all elements in the array,
 * Find it's minimum value.
 * Complexity O(n)
 * Space O(1)
 *
 * @param Pointer to the array.
 * @param SIZE of the array 
 * 
 * @return uint8_t - min element.
 */

const uint8_t find_mean(const uint8_t* const
                                , const unsigned int);
/**
 * @brief Find the mean value of an array
 *
 * Traverse and sum all elements in the array,
 * Divide the sum to the array's size.
 * Complexity O(n)
 * Space O(1)
 * 
 * 
 * @param Pointer to the array.
 * @param SIZE of the array
 * 
 * @return uint8_t - Mean value.
 */

const uint8_t find_median(const uint8_t* const
                                            , const unsigned int);
/**
 * @brief Find meadian value of an array
 *
 * Copy the array,
 * Sort the copied array.
 * Complexity O(nlogn)
 * Space O(n)
 * 
 * @param Pointer to the array.
 * @param SIZE of the array
 * 
 * @return uint8_t - element in middle position (case odd SIZE).
 *               Average of two middle position elements
 *                  (Even SIZE).
 */
#endif /* __STATS_H__ */
