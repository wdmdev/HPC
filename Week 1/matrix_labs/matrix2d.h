double ** dmalloc_2d(int m, int n);
void dfree_2d(double **A);
double * drand(double* A, int m);
double ** rand_2d(double** A, int m, int n);
double ** mpm(double** A, double** B, double** C, int m, int n);
double ** mtm(double** A, double** B, double** C, int m, int n, int k);
double * mtv(double** A, double* B, double* C, int m, int n);
void dprint(double* A, int m);
void print_2d(double** A, int m, int n);