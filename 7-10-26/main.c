//Code by pranay 
//date 7-10-26

#include <stdio.h>

int binarynum[4];   /* global: binarynum[i] = bit bi */
int F[16] = {0};    /* everything 0 by default */

void tobinary(int d) {
    for (int i = 0; i < 4; i++)
        binarynum[i] = (d >> i) & 1;
}

int main(void) {
    int minterms[] = {0, 2, 4, 8, 10, 11, 12};

    /* 1 only for the minterms, the rest stay 0 */
    for (int k = 0; k < 7; k++)
        F[minterms[k]] = 1;

    /* truth table */
    printf("Truth table\n");
    printf("Dec b3 b2 b1 b0 | F\n");
    for (int d = 0; d < 16; d++) {
        tobinary(d);
        printf("%2d   %d  %d  %d  %d | %d\n", d,
               binarynum[3], binarynum[2], binarynum[1], binarynum[0], F[d]);
    }

    /* K-map */
    int gray[4] = {0, 1, 3, 2};   /* 00 01 11 10 */
    printf("\nK-map\n");
    printf("b3b2\\b1b0  00  01  11  10\n");
    for (int i = 0; i < 4; i++) {
        int r = gray[i];
        printf("   %d%d      ", (r >> 1) & 1, r & 1);
        for (int j = 0; j < 4; j++)
            printf(" %d   ", F[r * 4 + gray[j]]);
        printf("\n");
    }

    /* equation */
    printf("\nEquation\n");
    printf("F = b1'b0' + b2'b0' + b3 b2' b1\n");

    return 0;
}
