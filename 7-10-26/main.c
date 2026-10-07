//code by pranay
//date 7-10-26

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void fun(int A[], int n) {
    for (int i = 0; i <= n - 2; i++)
        for (int j = 0; j <= n - i - 2; j++)
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
}

int uniform100(void) {
    double r = (double)rand() / RAND_MAX;  /* [0,1] */
    return (int)(r * 100 + 0.5);           /* integer 0-100 */
}

int main(void) {
    int A[N];
    srand((unsigned)time(NULL));

    for (int i = 0; i < N; i++)
        A[i] = uniform100();

    fun(A, N);

    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);
    printf("\n");
    return 0;
}
