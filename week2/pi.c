
double my_pi(int N){
    double n = (double) N;
    double pi = 0.0;
    double z = 4/n;
    double y = 0.5/n;

    for (double i = 0.0; i < N; i++){
        double x = (i/n - y);
        pi += 1 / (1 + x*x);
    }

    return pi*z;
}