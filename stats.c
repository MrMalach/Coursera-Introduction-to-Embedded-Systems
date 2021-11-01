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

  unsigned int N = SIZE;
  print_array(test, N);
  print_statistics(test, N);
  
}

/* Statistics and Printing Functions Go Here */

void print_array(const unsigned char * A
                  , const unsigned int N){
  printf("~~~~~~~~\n   Array\n~~~~~~~~\n[ ");
  for(int i = 0 ; i < N ; ++i)
    printf("%d ", A[i]);
  printf("]\n");
}

void print_statistics( const unsigned char *A
                        , const unsigned int N){
  unsigned char max = find_maximum(A, N);
  unsigned char min = find_minimum(A, N);
  unsigned char mean = find_mean(A, N);
  unsigned char median = find_median(A, N);

  printf("~~~~~~~~~~~~~~~~~~\n");
  printf(" Array statistics\n");
  printf("~~~~~~~~~~~~~~~~~~\n");
  printf("Max Element  = %d\n", max);
  printf("Min Element  = %d\n", min);
  printf("Mean Value   = %d\n", mean);
  printf("Median Value = %d\n", median);
  printf("~~~~~~~~~~~~~~~~~~\n");

}

const unsigned char find_maximum(const unsigned char* A
                                            , const unsigned int N ){
  unsigned char max_val = 0;
  for(int i = 0 ; i < SIZE ; ++i){
    if(A[i] > max_val){
      max_val = A[i];
    }
  }
  return max_val;
}

const unsigned char find_minimum(const unsigned char* A
                                            , const unsigned int N ){
  unsigned char min_val = 255;
  for(int i = 0 ; i < SIZE ; ++i){
    if(A[i] < min_val){
      min_val = A[i];
    }
  }
  return min_val;
}

const unsigned char find_mean(const unsigned char* A
                                      , const unsigned int N ){
  unsigned int sum = 0;
  for(int i = 0 ; i < SIZE ; ++i){
    sum += (unsigned int)A[i];
  }
  return (unsigned char)(sum / SIZE);
}


const unsigned char find_median(const unsigned char* A
                                        , const unsigned int N ){
    /* copy and sort the array */

  unsigned char sorted_A[SIZE];
  for(int i = 0 ; i < SIZE ; ++i){
    sorted_A[i] = A[i];
  }

  sort_array(sorted_A, SIZE);

  if(SIZE & 1) // Case odd array size
    return sorted_A[SIZE /2];
  return (sorted_A[(SIZE - 1) /2] + sorted_A[SIZE /2]) /2;
}

/* Add other Implementation File Code Here */


void swap(unsigned char* a, unsigned char* b){
/*  swap func for quicksort */
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sort_array(unsigned char* A, unsigned int N){
/*  O(nlogn) Quick Sort Algorithm implementation  */
    if(N < 2)
        return;
    int l = 0;
    int r = N - 2;
    int p = N - 1;
    while(r > l){
        if(A[l] >= A[p]) 
          ++l;
        if(A[r] <= A[p]) 
          --r;
        if(A[r] >= A[p] && A[l] <= A[p] && r > l)
            swap(&A[l], &A[r]);
    }
    if(A[r] > A[p]) 
      ++r;
    swap(&A[r], &A[p]);
    sort_array(A, r);
    sort_array(&A[r + 1], N - (r + 1));
}


