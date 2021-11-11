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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t len)
{
  if(src == dst)
    return dst;

  uint8_t* out = dst;
  
  if(dst > src)
  {
    dst += len - 1;
    src += len - 1;
    while(  len--  )
    {
      *dst-- = *src--;
    }
  }
  else
  {
    while( len-- )
    {
      *dst++ = *src++;
    }
  }

  return out;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t len)
{
  if(src == dst)
    return dst;
  uint8_t* out = dst;
  while( len--)
  {
    *dst++ = *src++;
  }
  return out;
}

uint8_t * my_memset(uint8_t * src, size_t len, uint8_t value)
{
  uint8_t* out = src;
  for( ; src < out + len ; ++src)
    *src = value;
  return out;
}

uint8_t * my_memzero(uint8_t * src, size_t len)
{
  return my_memset(src, len, 0);
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
  uint8_t l = 0;
  uint8_t r = length - 1;
  while(r > l)
  {
    uint8_t tmp = *(src + l);
    *(src + l) = *(src + r);
    *(src + r) = tmp;
    ++l;
    --r;
  }
  return src;
}

int32_t * reserve_words(size_t length)
{
  size_t wordSize = sizeof(int32_t);
  return malloc(length * wordSize);
}

void free_words(int32_t * src)
{
  free((void*)src);
}