#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mpi.h"
 
int main(int argc, char * argv[])
{
    int rank, size, end = 100000, i, count = 0, reduced_count, reduced_end;
    double x, y, z, pi;
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    srand48(time(NULL));
    if(rank != 0)
    {
        for(i = 0; i < end; ++i)
        {
            x = (double)random() / RAND_MAX;
            y = (double)random() / RAND_MAX;
            z = sqrt((x * x) + (y * y));
            if(z <= 1) ++count;
        }
    }
    MPI_Reduce(&count, &reduced_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&end, &reduced_end, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    reduced_end -= end;
    if(rank == 0)
    {
        pi = ((double)reduced_count / (double)reduced_end) * 4.0;
        printf("Pi is %.20f\nValid points %i\nAll points %d\n", pi, reduced_count, reduced_end);
    }
    MPI_Finalize();
    return 0;
}
