#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix2d.h"

int main(void){
    time_t start, end;
    float avg_sec;
    int m = 1000;
    int n = 1000;
    int N = 3;
    double** A = dmalloc_2d(m, n);
    double** B = dmalloc_2d(m, n);
    double** C = dmalloc_2d(m, n);

    for (int i = 0; i < N; i++){
        A = rand_2d(A, m, n);
        B = rand_2d(B, m, n);

        time(&start);
        C = mpm(A, B, C, m, n);
        time(&end);

        avg_sec = difftime(end,start);
    }

    avg_sec = avg_sec/N;
    dfree_2d(A);
    dfree_2d(B);
    dfree_2d(C);


    printf("Average time spend on %d x %d matrix addition: %.4lf seconds (%d trials)\n", m, n, avg_sec, N);

    return EXIT_SUCCESS;
}