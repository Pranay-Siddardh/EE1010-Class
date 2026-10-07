//code by pranay date 7-10-26

#include <stdio.h>

int binarynum[4];   /* global: binarynum[i] = bit bi */
int F[16];

void tobinary(int d) {
    for (int i = 0; i < 4; i++)
        binarynum[i] = (d >> i) & 1;
}

/* F = b1'b0' + b2'b0' + b3 b2' b1, read from the global array */
int boolean_F(void) {
    int b0 = binarynum[0];
    int b1 = binarynum[1];
    int b2 = binarynum[2];
    int b3 = binarynum[3];

    return (!b1 && !b0) || (!b2 && !b0) || (b3 && !b2 && b1);
}

int main(void) {
    /* compute F for every input using the Boolean logic */
    for (int d = 0; d < 16; d++) {
        tobinary(d);
        F[d] = boolean_F();
    }

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
