#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  
  int a = atoi(argv[1]);
  int b  = atoi(argv[2]);
  printf("Initial value of a: %d\n", a);
  printf("Initial value of b: %d\n", b);
  a = a+b;
  b = a-b;
  a = a-b;
  printf("Swapped value of a: %d\n", a);
  printf("Swapped value of b: %d\n", b);
  
}
