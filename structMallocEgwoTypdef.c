#include <stdio.h>
#include <stdlib.h>

struct rec
{
  int i;
  float Pi;
  char A;
};

int main ()
{
  struct rec *ptr_one;
  ptr_one  = (struct rec *) malloc (sizeof(struct rec));

  /* FRIST ATTEMPT TO COMPILE generated 8 errors:
   * structMallocEgwoTypdef.c:16:10: error: member reference type 'struct rec *' is a pointer; did you mean
      to use '->'?
  ptr_one.i = 10;
  ~~~~~~~^
         ->
structMallocEgwoTypdef.c:17:10: error: member reference type 'struct rec *' is a pointer; did you mean
      to use '->'?
  ptr_one.PI = 3.14;
  ~~~~~~~^
         ->
structMallocEgwoTypdef.c:17:11: error: no member named 'PI' in 'struct rec'
  ptr_one.PI = 3.14;
  ~~~~~~~ ^
structMallocEgwoTypdef.c:18:10: error: member reference type 'struct rec *' is a pointer; did you mean
      to use '->'?
  ptr_one.A = 'a';
  ~~~~~~~^
         ->
structMallocEgwoTypdef.c:20:38: error: member reference type 'struct rec *' is a pointer; did you mean
      to use '->'?
  printf("First value: %d\n", ptr_one.i);
                              ~~~~~~~^
                                     ->
structMallocEgwoTypdef.c:21:39: error: member reference type 'struct rec *' is a pointer; did you mean
      to use '->'?
  printf("Second value: %d\n", ptr_one.PI);
                               ~~~~~~~^
                                      ->
structMallocEgwoTypdef.c:21:40: error: no member named 'PI' in 'struct rec'
  printf("Second value: %d\n", ptr_one.PI);
                               ~~~~~~~ ^
structMallocEgwoTypdef.c:22:38: error: member reference type 'struct rec *' is a pointer; did you mean
      to use '->'?
  printf("Third value: %d\n", ptr_one.A);
                              ~~~~~~~^
                                     ->

  SWITCHING TO TRADITIONAL REFERENCING OF VALUES WITHIN STRUCTS
  */
  ptr_one->i = 10;
  ptr_one->PI = 3.14;
  ptr_one->A = 'a';
  
  printf("First value: %d\n", ptr_one->i);
  printf("Second value: %d\n", ptr_one->PI);
  printf("Third value: %d\n", ptr_one->A);

  free(ptr_one);

  return 0;
}
