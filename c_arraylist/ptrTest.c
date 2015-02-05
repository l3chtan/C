#include <stdio.h>
 
int main ()
{
   int  var;
   int  *ptr;
   int  **pptr;

   var = 3000;

   /* take the address of var */
   ptr = &var;

   /* take the address of ptr using address of operator & */
   pptr = &ptr;

//   printf("Value of var = %d\n", var );
   printf("Value available at ptr = %p\n", ptr );
   printf("Value available at *pptr = %p\n", *pptr);

   return 0;
}