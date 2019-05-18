#include <stdio.h>
int main()
{
   size_t foo;
   unsigned long foo2;

   printf("foo = %lu,size_t=%lu,u_long=%lu\n", (unsigned long) foo, sizeof(foo), sizeof(foo2));
   printf("Hello, World!");
   return 0;
}
