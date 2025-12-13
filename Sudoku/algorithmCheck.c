#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int i = 2, j = 1, n = 4;
    int sqN = (int)floor(sqrt(n));
    int ib = floor(i/sqN);
    int jb = floor(j/sqN);
    printf("the block pos is %d, %d \n", ib, jb);
    int wsI = ib*sqN;
    int wsJ = jb*sqN;
    printf("the start pos is %d, %d \n", wsI, wsJ);
    int esI = (ib*sqN) + sqN-1;
    int esJ = (jb*sqN) + sqN-1;
    printf("the end pos is %d, %d", esI, esJ);
    return 0;
}