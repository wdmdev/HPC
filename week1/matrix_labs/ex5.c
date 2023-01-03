#include <cblas.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix2d.h"

int main(void){
    time_t start, end;
    float avg_sec;
    int m = 3;
    int n = 3;
    int k = 4;
    float alpha = 1.0;
    float beta = 0.0;
    int N = 1;
    double** A = dmalloc_2d(m, k);
    double** B = dmalloc_2d(k, n);
    double** C = dmalloc_2d(m, n);

    for (int i = 0; i < N; i++){
        A = rand_2d(A, m, k);
        B = rand_2d(B, k, n);

        time(&start);
	    cblas_dgemm(CblasRowMajor,CblasNoTrans, CblasNoTrans, m, n, k, alpha, A[0], m, B[0], k, beta, C[0], m);
        time(&end);

        avg_sec = difftime(end,start);
    }

    avg_sec = avg_sec/N;
    dfree_2d(A);
    dfree_2d(B);
    dfree_2d(C);


    printf("Average time spend on %d x %d matrix multiplication: %.4lf seconds (%d trials)\n", m, n, avg_sec, N);

    return EXIT_SUCCESS;
}
