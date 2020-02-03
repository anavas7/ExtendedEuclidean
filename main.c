#include <stdio.h>
#define DEBUG

void ExtendedEuclid(long a, long b, long *s,long *t, long *d)

{
  //intializing variables 
  long q, r, s1, s2, t1, t2;

  //base statement 
  if (b == 0) {
    *d = a, *s = 1, *t = 0;
    return;
  }

  //setting the value for s and t
  s2 = 1, s1 = 0, t2 = 0, t1 = 1;

  //making the table
  #ifdef DEBUG
  printf("------------------------------");
  printf("-------------------\n");
  printf("q    r    s    t    a    b    ");
  printf("s2   s1   t2   t1\n");
  printf("------------------------------");
  printf("-------------------\n");
  #endif
  
  //Extended Euclidean Algorithm
  while (b > 0) 
  {
    //equations 
    q = a / b, r = a - q * b;
    *s = s2 - q * s1, *t = t2 - q * t1;
    a = b, b = r;
    s2 = s1, s1 = *s, t2 = t1, t1 = *t;
    
    //printing the results 
    #ifdef DEBUG
    printf("%4ld %4ld %4ld %4ld ", q, r, *s, *t);
    printf("%4ld %4ld %4ld %4ld ", a, b, s2, s1);
    printf("%4ld %4ld\n", t2, t1);
    #endif
  }
  *d = a, *s = s2, *t = t2;
  #ifdef DEBUG
  printf("------------------------------");
  printf("-------------------\n");
  #endif
}

int main(void)
{
  long a = 25, b = 60, d, s, t;

  ExtendedEuclid(a, b, &s, &t, &d);
  printf("gcd(%ld, %ld) = %ld  s = %ld t = %ld\n", a, b, d,s, t);
  return 0;
}
