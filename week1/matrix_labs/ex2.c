#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix2d.h"

int main(void){
    time_t start, end;
    float avg_sec;
    int m = 3;
    int n = 3;
    int N = 1;
    double** A = dmalloc_2d(m, n);
    double* B = malloc(m * sizeof(double *));
    double* C = malloc(m * sizeof(double *));

    for (int i = 0; i < N; i++){
        A = rand_2d(A, m, n);
        B = drand(B, m);

        time(&start);
        C = mtv(A, B, C, m, n);
        time(&end);

        avg_sec = difftime(end,start);
    }

    avg_sec = avg_sec/N;
    dfree_2d(A);
    free(B);
    free(C);


    printf("Average time spend on %d x %d matrix vector multiplication: %.4lf seconds (%d trials)\n", m, n, avg_sec, N);

    return EXIT_SUCCESS;
}