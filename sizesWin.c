#include <stdio.h>
#include <limits.h>

// Compile under windows: 
// cl /EHsc sizes.c

// Functions prototype for size_t <-> {int | u_long} conversion 
int size_t2int(size_t);
size_t  int2size_t(int);
unsigned long size_t2u_long(size_t);
  
int main()
{
   size_t  sizet=5, sizet2=21474836470;
   //ssize_t ssizet=6;
   int     int1=7, int2=-8;
   unsigned long uns_long=10;

   printf("Lengths in bytes: size_t=%zu, int=%zu, u_long=%zu\n", sizeof(sizet), sizeof(int1), sizeof(uns_long));
   //printf("Lengths in bytes: size_t=%lu, int=%lu, u_long=%lu, ssize=%zu\n", sizeof(sizet), sizeof(int1), sizeof(uns_long), sizeof(ssizet));
   printf("INT_MAX=%d, __SIZE_MAX__=%zu\n", INT_MAX, SIZE_MAX);
   
   printf("INT: size_t2int.VAL=%d, size_t2int.SIZE=%zu, int2size_t.VAL=%zu, int2size_t.SIZE=%zu\n", size_t2int(sizet),sizeof(size_t2int(sizet)), int2size_t(int1), sizeof(int2size_t(int1)) );

   printf("U_LONG: size_t2ulong=%lu, int2size_t=%zu\n", size_t2u_long(sizet), sizeof( size_t2u_long(sizet) ) );

   /* Negative numbers */   
   printf("INT-,: size_t2int=%d, int2size_t=%zu\n", size_t2int(sizet2), int2size_t(int2) );
   printf("converted sizes: int=%zu, size_t=%zu\n", sizeof(size_t2int(sizet2)), sizeof(int2size_t(int2)) );
  
   return 0;
}

int size_t2int(size_t val) {
  if (val <= INT_MAX) {
    return (int)(val);
  }
  else {
    printf("ERROR: size_t value larger than allowed  by int type\n");
    return -1;
  }
}

/*
int size_t2int(size_t val) {
  return (val <= INT_MAX) ? (int)(ssize_t)val : -1;
}
*/
size_t int2size_t(int val) {
  return (val < 0) ? SIZE_MAX : (size_t)((unsigned)(val));
}

unsigned long size_t2u_long(size_t val) {
  return (val > ULONG_MAX) ? ULONG_MAX : (unsigned long)(val);
}
