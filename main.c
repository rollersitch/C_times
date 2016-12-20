#include "sayhallo.h"
void swap(int *a, int *b) {
 int tmp;

 *a=30;

 tmp=*a;
 *a = *b;
 *b = tmp;
}

void main() {
  int x=3, y=5;
  int p[3], *pt;

 
   p= &x; //errore
  pt = p;
  p[2] = 100;
  *(p+2) = 100;
  swap(&x,&y);

}
