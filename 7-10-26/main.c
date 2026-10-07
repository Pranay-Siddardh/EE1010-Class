//Code by Pranay
//Date: 07/10/2026
#include <stdio.h>

void converter(int n, int *A, int *B, int *C)
{
    int binary[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        binary[i] = n % 2;
        n = n / 2;
    }

    *A = binary[2];
    *B = binary[1];
    *C = binary[0];
}

int main()
{
    int i, A, B, C, X;

    printf("N | A B C | X\n");
    printf("------------\n");

    for (i = 0; i < 8; i++)
    {
        converter(i, &A, &B, &C);

        // Majority function: X = AB + AC + BC
        X = (A & B) | (A & C) | (B & C);

        printf("%d | %d %d %d | %d\n", i, A, B, C, X);
    }

    return 0;
}

