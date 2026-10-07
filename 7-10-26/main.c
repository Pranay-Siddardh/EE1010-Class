//Code by Pranay
//Date: 05/10/2026

#include <stdio.h>

int X(int a, int b, int c)
{
    return (a & b) | (a & c) | (b & c);
}

int main()
{
    int a, b, c, d, e;
    int lhs, rhs;
    int result;

    /* ================= IDENTITY A ================= */

    printf("\nIDENTITY A\n");
    printf("X(a,b,X(c,d,e)) = X(X(a,b,c),d,e)\n");
    printf("a b c d e | LHS RHS | Equal\n");
    printf("-----------------------------\n");

    result = 1;

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            for (c = 0; c <= 1; c++)
            {
                for (d = 0; d <= 1; d++)
                {
                    for (e = 0; e <= 1; e++)
                    {
                        lhs = X(a, b, X(c, d, e));
                        rhs = X(X(a, b, c), d, e);

                        printf("%d %d %d %d %d |  %d   %d  | %d\n",
                               a, b, c, d, e, lhs, rhs, lhs == rhs);

                        if (lhs != rhs)
                            result = 0;
                    }
                }
            }
        }
    }

    printf("Identity A: %s\n", result ? "TRUE" : "FALSE");


    /* ================= IDENTITY B ================= */

    printf("\nIDENTITY B\n");
    printf("X(a,b,X(a,b,c)) = X(a,b,c)\n");
    printf("a b c | LHS RHS | Equal\n");
    printf("-----------------------\n");

    result = 1;

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            for (c = 0; c <= 1; c++)
            {
                lhs = X(a, b, X(a, b, c));
                rhs = X(a, b, c);

                printf("%d %d %d |  %d   %d  | %d\n",
                       a, b, c, lhs, rhs, lhs == rhs);

                if (lhs != rhs)
                    result = 0;
            }
        }
    }

    printf("Identity B: %s\n", result ? "TRUE" : "FALSE");


    /* ================= IDENTITY C ================= */

    printf("\nIDENTITY C\n");
    printf("X(a,b,X(a,c,d)) = X(a,b,a) AND X(c,d,c)\n");
    printf("a b c d | LHS RHS | Equal\n");
    printf("--------------------------\n");

    result = 1;

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            for (c = 0; c <= 1; c++)
            {
                for (d = 0; d <= 1; d++)
                {
                    lhs = X(a, b, X(a, c, d));

                    rhs = X(a, b, a) & X(c, d, c);

                    printf("%d %d %d %d |  %d   %d  | %d\n",
                           a, b, c, d, lhs, rhs, lhs == rhs);

                    if (lhs != rhs)
                        result = 0;
                }
            }
        }
    }

    printf("Identity C: %s\n", result ? "TRUE" : "FALSE");


    /* ================= IDENTITY D ================= */

    printf("\nIDENTITY D\n");
    printf("X(a,b,c) = X(a,X(a,b,c),X(a,c,c))\n");
    printf("a b c | LHS RHS | Equal\n");
    printf("-----------------------\n");

    result = 1;

    for (a = 0; a <= 1; a++)
    {
        for (b = 0; b <= 1; b++)
        {
            for (c = 0; c <= 1; c++)
            {
                lhs = X(a, b, c);
                rhs = X(a, X(a, b, c), X(a, c, c));

                printf("%d %d %d |  %d   %d  | %d\n",
                       a, b, c, lhs, rhs, lhs == rhs);

                if (lhs != rhs)
                    result = 0;
            }
        }
    }

    printf("Identity D: %s\n", result ? "TRUE" : "FALSE");

    return 0;
}
