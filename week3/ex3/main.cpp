#include <stdio.h>
#include <stdlib.h>
#include "mandel_omp.h"
#include "mandel.h"
#include "writepng.h"
#include "warm.h"

#ifdef _OPENMP
#include <omp.h>
#endif



int
main(int argc, char *argv[]) {

    bool gpu = 0;
    if (argc >= 2){
        gpu = argv[1];
    }
    bool warm = 0;
    if (argc >= 3){
        warm = argv[2];
    }

    int   width, height;
    int	  max_iter;
    int   *image;

    width    = 2601;
    height   = 2601;
    max_iter = 400;

    if (warm){
        warmup();
    }

    image = (int *)malloc( width * height * sizeof(int));
    if ( image == NULL ) {
       fprintf(stderr, "memory allocation failed!\n");
       return(1);
    }

    double start = omp_get_wtime();
    if (gpu)
    {
        mandel_gpu(width, height, image, max_iter);
    }
    else
    {
        mandel(width, height, image, max_iter);
    }
    double end = omp_get_wtime();

    printf("Runtime: %f seconds\n", end-start);

    writepng("mandelbrot.png", image, width, height);

    return(0);
}
