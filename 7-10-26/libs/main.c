#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "listgen.h"
#include "listfun.h"

int main(void) {
avyuh *A, *B, *C, *temp;
temp= loadList("vertices.dat", 2, 3);
A = Listcol(temp,0);
B = Listcol(temp,1);
C = Listcol(temp,2);



return 0;
}
