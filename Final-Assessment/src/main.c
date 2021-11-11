
#include "course1.h"


int main()
{
  #ifdef COURSE1
    #ifdef VERBOSE
      PRINTF("Calling course1()\n");
    #endif
    if( course1() )
    {
      return -1; 
    } 
  #endif
  return 0;
}