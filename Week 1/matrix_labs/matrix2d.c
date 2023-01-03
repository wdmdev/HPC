#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

// allocate a double-prec m x n matrix
double **
dmalloc_2d(int m, int n) {
    if (m <= 0 || n <= 0) return NULL;
    double **A = malloc(m * sizeof(double *));
    if (A == NULL) return NULL;
    A[0] = malloc(m*n*sizeof(double));
    if (A[0] == NULL) {
        free(A);
        return NULL;
    }
    for (int i = 1; i < m; i++)
        A[i] = A[0] + i * n;
    return A;
}

// de-allocting memory, allocated with dmalloc_2d
void
dfree_2d(double **A) {
    free(A[0]);
    free(A);
}

//Creates a vector of size m with random numbers
double *
drand(double* A, int m){
    for(int i = 0; i < m;i++)
            A[i] = rand()%100;

    return A;
}

//Creates a m x n matrix with random numbers
double **
rand_2d(double** A, int m, int n){
    for(int i = 0; i < m;i++)
    	for(int j = 0; j < n;j++)
            A[i][j] = rand()%100;

    return A;
}

/*
Matrix plus Matrix (mpm)

Adds two m×n matrices A and B, and stores the result in matrix C.

Input: pointers to matrix A and B, row size m, column size n.
Returns: pointer to matrix C
*/
double ** mpm(double** A, double** B, double** C, int m, int n){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
            
    return C;
}

/*
Matrix times Vector (mtv)

Multiplies a m×n matrix A and size n vector B, and stores the result in vector C.

Input: pointers to matrix A and vector B and their row size m, and column size n.
Returns: pointer to vector C
*/
double * mtv(double** A, double* B, double* C, int m, int n){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            C[i] += A[i][j] *  B[j];
            
    return C;
}

/*
Matrix time Matrix (mtm)

Multiplies m x k matrix A and n x k matrix B, and stores the result in m x n matrix C.

Input: pointers to m x k matrix A and n x k matrix B and their sizes.
Returns: pointer to m x n matrix C
*/
double ** mtm(double** A, double** B, double** C, int m, int n, int k){
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int l = 0; l < k; l++)
                C[i][j] += A[i][l] * B[l][j];
            
    return C;
}

//Prints vector 
void dprint(double* A, int m){
    for (int i = 0; i < m; i++){
        printf("%f\n", A[i]);
    }
}

//Prints 2d matrix
void print_2d(double** A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j =0; j < n; j++){
            printf("%f ", A[i][j]);
        }
        printf("\n");
    }
}