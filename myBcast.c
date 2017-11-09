#include <mpi.h>
#include <stdio.h>

#define MAXARRAY 20

int iniarray(int n, int *array) {
        int i;
        for (i = 0; i < n; i++)
                array[i] = i;
        return i;
}

void printarray(int n, int *array) {
        int i = 0;
        printf("[ ");
        for (; i < n; i++) {
                if (i == n - 1)
                        printf("%d ", array[i]);
                else
                        printf("%d, ", array[i]);
        }
        printf("]\n");
}


void myBcast(void *data, int numelem, MPI_Datatype datatype, int root, MPI_Comm communicator){


        int size, rank, dest, source, count, tag=111;
        char inmsg, outmsg='x';
        int mensaje;
        MPI_Status Stat;

        MPI_Init(NULL, NULL);
        MPI_Comm_rank(MPI_COMM_WORLD, &rank);

        if (rank == 0) {
         dest;
         mensaje = 777;
         for (dest = 1; dest < 4; dest++){

         MPI_Send(&mensaje, 1, MPI_INT, dest,tag , MPI_COMM_WORLD);

         }

        }else if (rank == 1) {
        source = 0;
        MPI_Recv(&mensaje, 1,MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);


        printf("Nodo %d: Received %d char(s) from Nodo %d with tag %d \n",
                   rank,mensaje , Stat.MPI_SOURCE, Stat.MPI_TAG);

        }else if (rank == 2) {
 	 source = 0;
         MPI_Recv(&mensaje, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);


         printf("Nodo %d: Received %d char(s) from Nodo %d with tag %d \n",
                   rank,mensaje , Stat.MPI_SOURCE, Stat.MPI_TAG);

        }else if (rank == 3) {

          source = 0;
          MPI_Recv(&mensaje, 1, MPI_INT, source, tag, MPI_COMM_WORLD, &Stat);


         printf("Nodo %d: Received %d char(s) from Nodo %d with tag %d \n",
                   rank,mensaje , Stat.MPI_SOURCE, Stat.MPI_TAG);

         }

        MPI_Finalize();


}

int main(int argc, char** argv) {
        int arreglo[MAXARRAY];

        iniarray(MAXARRAY, arreglo);

        myBcast(arreglo, MAXARRAY, MPI_INT, 0, MPI_COMM_WORLD);

}
