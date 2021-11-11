#include "course1.h"


int8_t course1()
{
    /* Array of function pointers   */
    int8_t (*test[8])();
    /* Initialize all elements      */
    test[0] = test_data1;
    test[1] = test_data2;
    test[2] = test_memmove1;
    test[3] = test_memmove2;
    test[4] = test_memmove3;
    test[5] = test_memcopy;
    test[6] = test_memset;
    test[7] = test_reverse;
    
    for(int i = 0 ; i < 8 ; ++i)
    /*  Loop all functions. 
        Case one is not successful, 
        return its value.       */
    {
        uint8_t e = (*test[i])();
        if( e ) 
            return e;
    }
    return 0;
}


int8_t test_data1()
{ 
    int32_t numberToConvert = -4093;
    uint32_t base = 16;
    /*  Max int will take 31 (chars) bits
      + NULL termination + minus sign. 
      = 33 chars = 33 / 4 words
      = ceil(8.25 words) = 9 words        */
    const int32_t numWordsToReserve = 9;
    uint8_t* ptr = (uint8_t*)reserve_words(numWordsToReserve);
    if( ! ptr )
        return -1;

    uint8_t digits = my_itoa(numberToConvert, ptr, base);
    int32_t value = my_atoi(ptr, digits, base);
    #ifdef VERBOSE
        PRINTF("\n~~~~~~~~~~~~~~~~\n");
        PRINTF("test_data1() : \n");
        PRINTF("Number to test = %d\n", numberToConvert);
        PRINTF("my_itoa (base %d)= %s\n", base, ptr);
        PRINTF("my_atoi (base %d) = %d\n", base, value);
    #endif
    free_words((int32_t*)ptr);

    if( value != numberToConvert)
        return 1;
    return 0;
}

int8_t test_data2()
{ 
    int32_t numberToConvert = INT_MAX;
    uint32_t base = 8;
    /*  Max int will take 31 (chars) bits
      + NULL termination + minus sign. 
      = 33 chars = 33 / 4 words
      = ceil(8.25 words) = 9 words        */
    const int32_t numWordsToReserve = 9;
    uint8_t* ptr = (uint8_t*)reserve_words(numWordsToReserve);
    if( ! ptr )
        return -1;

    uint8_t digits = my_itoa(numberToConvert, ptr, base);
    int32_t value = my_atoi(ptr, digits, base);
    #ifdef VERBOSE
        PRINTF("\n~~~~~~~~~~~~~~~~\n");
        PRINTF("test_data2() : \n");
        PRINTF("Number to test = %d\n", numberToConvert);
        PRINTF("my_itoa (base %d) = %s\n", base, ptr);
        PRINTF("my_atoi (base %d) = %d\n", base, value);
    #endif
    free_words((int32_t*)ptr);

    if( value != numberToConvert)
        return 1;
    return 0;
}

int8_t test_memmove1()
{
    uint8_t src[20] = "MrMalach";
    
    uint8_t* dst = src + 10;
    my_memmove(src, dst, my_strlen(src) + 1);
    #ifdef VERBOSE
        PRINTF("~~~~~~~~~~~~~~~~\n");
        PRINTF("test_memmove1() \nNo overlap : \n");
        PRINTF("src = %s\ndst = %s\n",src, dst);
    #endif
    return my_strcmp(src, dst);
}

int8_t test_memmove2()
{
    const uint8_t offset = 5;
    uint8_t str[] = "MrMalach";
    uint8_t src[20] = {0};
    my_memmove(str, &src[offset], my_strlen(str) + 1);
    uint8_t* dst = src;

    my_memmove(src + offset, dst, my_strlen(&src[offset]) + 1);
    #ifdef VERBOSE
        PRINTF("~~~~~~~~~~~~~~~~\n");
        PRINTF("test_memmove2()\n");
        PRINTF("Overlap = %d \n@ end of source beginning of dst : \n", offset);
        PRINTF("Original = %s\ndst      = %s\n",str, dst);
        PRINTF("src due overlap = %s\n", src + offset);
    #endif
    return my_strcmp(str, dst);
}

int8_t test_memmove3()
{
    const uint8_t offset = 5;
    uint8_t str[] = "MrMalach";
    uint8_t src[20] = {0};
    my_memmove(str, src, my_strlen(str) + 1);
    uint8_t* dst = src + offset;

    my_memmove(src, dst, my_strlen(src) + 1);
    #ifdef VERBOSE
        PRINTF("~~~~~~~~~~~~~~~~\n");
        PRINTF("test_memmove3() : \n");
        PRINTF("Overlap = %d \n@ end of dest beginning of source : \n", offset);
        PRINTF("Original = %s\ndst      = %s\n",str, dst);
        PRINTF("src due overlap = %s\n", src);
    #endif
    return my_strcmp(str, dst);
}

int8_t test_memcopy()
{
    const uint8_t offset = 10;
    uint8_t str[] = "MrMalach";
    uint8_t src[20] = {0};
    my_memcopy(str, src, my_strlen(str) + 1);
    uint8_t* dst = src + offset;

    my_memcopy(src, dst, my_strlen(src) + 1);
    #ifdef VERBOSE
        PRINTF("~~~~~~~~~~~~~~~~\n");
        PRINTF("test_memcopy() : \n");
        PRINTF("Original = %s\ndst      = %s\n",str, dst);
    #endif
    return my_strcmp(str, dst);
}

int8_t test_memset()
{
    /* Set value & length for mem set */
    const uint8_t value = 9;
    const uint8_t length = 15;

    uint8_t A[length + 1];
    A[length] = '\0';

    my_memset(A, length, value);
    #ifdef VERBOSE
        PRINTF("~~~~~~~~~~~~~~~~\n");
        PRINTF("test_memset() : \n");
        PRINTF("After memset (value = %d):\n", value);
    #endif
    print_array(A, (unsigned int)length);

    /* Validate correct functionality */
    for(uint8_t i = 0 ; i < length ; ++i)
        if( A[i] != value)
            return -1;

    my_memzero(A, length);
    #ifdef VERBOSE
        PRINTF("After memzero:\n");
    #endif
    print_array(A, (unsigned int)length);
    //PRINTF("%s\n", A);
    
    /* Validate correct functionality */
    for(uint8_t i = 0 ; i < length ; ++i)
        if( A[i] != 0)
            return -1;

    return 0;
}

int8_t test_reverse()
{
    /* Set length for array to test */
    const uint8_t length = 26;
    

    uint8_t A[length + 1];
    A[length] = '\0';

    for(uint8_t i = 0 ; i < length ; ++i)
        A[i] = i + 'a';
    #ifdef VERBOSE
        PRINTF("~~~~~~~~~~~~~~~~\n");
        PRINTF("test_reverse(): \n");
        PRINTF("Array to reverse:\n");
        PRINTF("%s\n", A);
    #endif
    my_reverse(A, length);
    #ifdef VERBOSE
        PRINTF("After reverse:\n");
        PRINTF("%s\n", A);
    #endif
    for(uint8_t i = 0 ; i < length ; ++i)
        if(A[i] != length - i - 1 + 'a')
            return -1;
    return 0;

}
