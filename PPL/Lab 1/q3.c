#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int x=4,y =2;
	if(rank%4==0){
		printf("Addition: %d\n", x+y);
	}
	else if(rank%4==1){
		printf("Sub: %d\n", x-y);
	}
	else if(rank%4==2){
		printf("Multiply: %d\n", x*y);
	}
	else{
		printf("Div: %d\n", x/y);
	}
	MPI_Finalize();
	return 0;
}

// student@lpcp-21:~/210905164/L1$ mpicc q3.c -o q3
// student@lpcp-21:~/210905164/L1$ mpiexec -n 4 ./q3
// Addition: 6
// Sub: 2
// Multiply: 8
// Div: 2
