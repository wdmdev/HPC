#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    bool bug = 0;
    if (argc == 2) 
    {
        bug = atoi(argv[1]);
    }

    // Check for available devices.
    if (omp_get_num_devices() < 1 || omp_get_default_device() < 0){
        fprintf(stderr, "No devices found. Run 'nvidia-smi' to check.\n");
        exit(1);
    }

    printf("Warming up device %i ... \n", omp_get_default_device()); 
    fflush(stdout);

    // We force the creation of context on the device by allocating and
    // transferring a dummy variable. You will learn about the omp target data
    // construct and the map clause later.
    double dummy = 1.0;
    #pragma omp target data map(tofrom: dummy)
    {
        dummy += 1;
    }


    #pragma omp target teams parallel \
            num_teams(108) thread_limit(4*32)
    {
        int thread_id = omp_get_thread_num();
        int team_threads = omp_get_num_threads();
        int team_id = omp_get_team_num();
        int global_thread_id = thread_id + team_id * team_threads;
        int total_global_threads =  team_threads * omp_get_num_teams();

        if (bug) 
        {
            if (global_thread_id == 100) { int *a = (int*) 0x10000; *a = 0; }
        }


        printf("Hello world! I'm thread %d out of %d in team %d. My global thread id is %d out of %d\n", 
        thread_id, team_threads, team_id, global_thread_id, total_global_threads);
    }

    return(0);
}
