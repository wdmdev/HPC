#include <stdio.h>
#include <stdlib.h>
#include "mandel.h"
#include "writepng.h"

#ifdef _OPENMP
#include <omp.h>
#endif



int
main(int argc, char *argv[]) {

    int   width, height;
    int	  max_iter;
    int   *image;

    width    = 2601;
    height   = 2601;
    max_iter = 400;

    // command line argument sets the dimensions of the image
    if ( argc == 2 ) width = height = atoi(argv[1]);

    image = (int *)malloc( width * height * sizeof(int));
    if ( image == NULL ) {
       fprintf(stderr, "memory allocation failed!\n");
       return(1);
    }

    double start = omp_get_wtime();
    #pragma omp parallel
    mandel(width, height, image, max_iter);
    double end = omp_get_wtime();

    printf("Runtime: %f seconds\n", end-start);

    writepng("mandelbrot.png", image, width, height);

    return(0);
}
