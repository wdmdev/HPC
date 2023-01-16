#ifdef _OPENMP
#include <omp.h>
#endif

double my_pi(long N){
    double pi = 0.0;
    double x = (double)1/N;
    double y = 0.5*x;
    double z = 4.0*x;

    #pragma omp parallel for \
            shared(y) reduction(+: pi)
    for (int i = 0.0; i < N; i++){
        double h = (double) (i/((double)N) - y);
        double tmp = 1 / (1 + h*h);
        pi = pi + tmp;
    }

    return pi*z;
}