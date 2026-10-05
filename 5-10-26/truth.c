//Code By Pranay
//Date 5-10-26

#include <stdio.h>

int main() {
    int a, b, c;

    // Print headers
    printf("A  B  C | abc  a'bc ab'c abc' | Output (F)\n");
    printf("------------------------------------------\n");

    // Loop through all 8 binary combinations
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            for (c = 0; c <= 1; c++) {
                
                // Evaluate individual product terms
                int term1 = a && b && c;          // abc
                int term2 = (!a) && b && c;       // a'bc
                int term3 = a && (!b) && c;       // ab'c
                int term4 = a && b && (!c);       // abc'
                
                // Final Boolean Output (ORing the terms together)
                int F = term1 || term2 || term3 || term4;

                // Print the current row evaluation
                printf("%d  %d  %d |  %d    %d    %d    %d   |    %d\n", 
                       a, b, c, term1, term2, term3, term4, F);
            }
        }
    }

    return 0;
}

