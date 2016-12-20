#include <string.h>
#include <stdio.h>
int main() {
  char str[60];
  
  for(i=0; i < 10; i++) {
     str[i] = '0' + i;
  } 

  for(i=0; i < 25; i++) {
     str[i] = 'A' + i;
  } 


  strcpy(str, "hallo world");
  printf("%s, len=%d\n", str, strlen(str));

}

