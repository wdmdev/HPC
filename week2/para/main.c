#include "pi.h"
#include "matrix_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifdef _OPENMP
#include <omp.h>
#endif

void matrix_vector(){
    #ifdef _OPENMP
        double start, end;
    #endif

    #ifndef _OPENMP:
        time_t start, end;
    #endif

    float avg_sec;
    int m = 20000;
    int n = 20000;
    int N = 1;
    double** A = dmalloc_2d(m, n);
    double* B = malloc(m * sizeof(double *));
    double* C = malloc(m * sizeof(double *));

    for (int i = 0; i < N; i++){
        A = rand_2d(A, m, n);
        B = drand(B, m);

        #ifdef _OPENMP
            start = omp_get_wtime();
        #endif
        #ifndef _OPENMP
            time(&start);
        #endif

        C = mtv(A, B, C, m, n);

        #ifdef _OPENMP
            end = omp_get_wtime();
        #endif
        #ifndef _OPENMP
            time(&end);
        #endif

        avg_sec = end-start;
    }

    avg_sec = avg_sec/N;
    dfree_2d(A);
    free(B);
    free(C);


    printf("Average time spend on %d x %d matrix vector multiplication: %.4lf seconds (%d trials)\n", m, n, avg_sec, N);
}


void pi(){
    #ifdef _OPENMP
        long N = 10000000000;
        double start, end;
        start = omp_get_wtime();
        double pi = my_pi(N);
        end = omp_get_wtime();

        printf("Seconds spend: %f\n", end-start);
        printf("N: %ld\n", N);
        printf("pi: %f\n", pi);
    #endif
}

int main(int argc, char *argv[]){
    matrix_vector();

    return EXIT_SUCCESS;
}