//Code by Pranay
//Date: 07/10/2026
#include <stdio.h>

void converter(int n, int *binary)
{
    int binaryq[3];
    int i;

    for (i = 0; i < 3; i++)
    {
        binaryq[i] = n % 2;
        n = n / 2;
    }

    binary[2] = binaryq[2];
    binary[1] = binaryq[1];
    binary[0] = binaryq[0];
}

int main()
{
    int i, X;
    int binary[3];

    printf("N | A B C | X\n");
    printf("------------\n");

    for (i = 0; i < 8; i++)
    {
        converter(i, binary);

        // Majority function: X = AB + AC + BC
        X = (binary[2] & binary[0]) | (binary[0] & binary[1]) | (binary[1] & binary[2]);

        printf("%d | %d %d %d | %d\n", i, binary[0],binary[1],binary[2], X);
    }

    return 0;
}

