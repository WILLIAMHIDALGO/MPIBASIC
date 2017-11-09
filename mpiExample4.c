#include <stdio.h>
#include "mpi.h"

int main(int argc,char *argv[]){
	int i; 
	int sumTotal;
	int sum;
	int start, end, size, rank;


	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	// Defina aqui el segmento que debe procesar una tarea
	// El inicio del segmento en la variable 'start', el fin del segmento
	// la variable 'end'
	if(rank == 0) 
	{
		start = 1;
		end = 20000;
		for(i = start; i <= end; i++)
		{
    		sum = sum + i;
		}
		MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("El cálculo del proceso %d es: %d \n", rank, sum);
	}
	else if(rank == 1) 
	{
		start = 20001;
		end = 40000;
		for(i = start; i <= end; i++)
		{
    		sum = sum + i;
		}
		MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("El cálculo del proceso %d es: %d \n", rank, sum);
	}
	else if(rank == 2) 
	{
		start = 40001;
		end = 60000;
		for(i = start; i <= end; i++)
		{
    		sum = sum + i;
		}
		MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("El cálculo del proceso %d es: %d \n", rank, sum);
	}
	else if(rank == 3) 
	{
		start = 60001;
		end = 80000;
		for(i = start; i <= end; i++)
		{
    		sum = sum + i;
		}
		MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("El cálculo del proceso %d es: %d \n", rank, sum);
	}
	else if(rank == 4) 
	{
		start = 80001;
		end = 100000;
		for(i = start; i <= end; i++)
		{
    		sum = sum + i;
		}
		MPI_Reduce(&sum, &sumTotal, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
		printf("El cálculo del proceso %d es: %d \n", rank, sum);
	}
	// Utilice la funcion 'MPI_Reduce' para guardar en la variable 
	// 'sumTotal' la suma parcial de todos las tareas 
	//printf ("\nTotal: %d\n",sumTotal);
	printf("Suma total: %d \n", sumTotal);
	MPI_Finalize();
	
	return 0;
}



