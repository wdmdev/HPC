#include "pi.h"
#include <time.h>
#include <stdio.h>

int main(int argc, char *argv[]){
    time_t start, end;

    // int * N;
    // N = argv[1];

    int N = 1000000000;


    time(&start);
    double pi = my_pi(N);
    time(&end);

    printf("Seconds spend: %f\n", difftime(end,start));
    printf("N: %d\n", N);
    printf("pi: %f\n", pi);
}