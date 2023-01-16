void warmup(){
    // We force the creation of context on the device by allocating and
    // transferring a dummy variable. You will learn about the omp target data
    // construct and the map clause later.
    double dummy = 1.0;
    #pragma omp target data map(tofrom: dummy)
    {
        dummy += 1;
    }
}