#include "data.h"
#include <math.h>

#ifdef ARRAY_OF_STRUCTS
double 
distance(particle_t *p, int n) {
    
    double dist = 0.0;

    for (int i = 0; i < n; i++){
        double x = p[i].x;
        double y = p[i].y;
        double z = p[i].z;
        dist += sqrt(x * x + y * y + z * z);
    }

    return dist;
}
#else
double 
distance(particle_t p, int n) {

    double dist = 0.0;

    for (int i = 0; i < n; i++){
        double x = p.x[i];
        double y = p.y[i];
        double z = p.z[i];
        dist += sqrt(x*x + y*y + z*z);
    }
    
    return dist;
}
#endif
