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
 * @file stats.c
 * @brief Analizing an array of unsigned char
 *
Element Analiticts:
 * 1. Maximum.
 * 2. Minimum.
 * 3. Mean.
 * 4. Median.
 * 
 * @author Ran Malach
 * @date 31/10/2021
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

}

/* Statistics and Printing Functions Go Here */

void print_array(const unsigned char * A
                  , const unsigned int N){
}

void print_statistics( const unsigned char *A
                        , const unsigned int N){
}

const unsigned char find_maximum(const unsigned char* A
                                            , const unsigned int N ){
}

const unsigned char find_minimum(const unsigned char* A
                                            , const unsigned int N ){
}

const unsigned char find_mean(const unsigned char* A
                                      , const unsigned int N ){
}


const unsigned char find_median(const unsigned char* A
                                        , const unsigned int N ){
}

/* Add other Implementation File Code Here */


void swap(unsigned char* a, unsigned char* b){
}

void sort_array(unsigned char* A, unsigned int N){
}


