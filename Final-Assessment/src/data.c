#include "data.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    if(base < 2 || base > 16)
    // As constrained
        return -1;

    if(data == 0)
    //  Case the data is zero
    {
        *ptr = '0';
        *(ptr + 1) = '\0';
        return 1;
    }

    uint8_t isNegative = 0;

    if(data & (1 << 31))
    /*  Case negative (msb == 1)
        convert to positive(2's complement). */
    {
        isNegative = 1;
        // Toggle all bits & add 1.
        data ^= 0xffffffff;
        ++data;
    }

    // Its gonna be easier to reverse the string later.
    *ptr = '\0';
    //  Index for ptr
    uint8_t i = 1;
    
    while( data > 0 )
    /* Loop all digits of data & store vals 
        @ (ptr + i) mem location    */
    {
        uint8_t tmp = data % base;
        /* The ternary exp is for base > 10 
                ( ..., 8, 9, a, b, ...)     */
        *(ptr + i) = (tmp < 10) ? ('0' + tmp) : ('a' - 10 + tmp);

        data /= base;
        ++i;
    }

    if( isNegative )
    // Add minus sign if negative & advance the index i
        *(ptr + i++) = '-';

    // Reverse memory
    my_reverse(ptr, i);

    return i;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{

    if(base < 2 || base > 16)
    // As constrained
        return -1;

    int32_t out = 0;
    
    uint8_t isNegative = 0;

    if( *ptr == '-')
    {
        isNegative = 1;
    }
    
    for( uint8_t* i = ptr + isNegative; 
                i < ptr + digits - 1 ; ++i)
    {
        /* The ternary exp is for base > 10 
           digits = ..., 8, 9, a, b, ...  */
        out = out * base + *i + (*i > '9' ? 10 -'a' : -'0');
    }
    
    if( isNegative )
    /* Turn to minus (2's complement)
       Toggle all bits & add 1     */
    {
        out ^= 0xffffffff;
        ++out;
    }

    return out;

}

int8_t my_strcmp(uint8_t* s1, uint8_t* s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return 0;
	if (*s1 != *s2)
		return (*s1 > *s2) ? 1 : -1;
	
	return my_strcmp(s1 + 1, s2 + 1);
}

size_t my_strlen(uint8_t* ptr)
{
    size_t out = 0;
    while(*(ptr + out++) != '\0');
    return out - 1;
}
