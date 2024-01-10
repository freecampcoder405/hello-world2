#include<mpi.h>
#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[]){
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	int x=2;
	printf("%dth Pow of %d rank is %f \n", x,rank+1, pow(x,rank+1));
	MPI_Finalize();
	return 0;
}

// student@lpcp-21:~/210905164/L1$ mpicc q1.c -o q1 -lm
// student@lpcp-21:~/210905164/L1$ mpiexec -n 5 ./q1
// 2th Pow of 1 rank is 2.000000 
// 2th Pow of 2 rank is 4.000000 
// 2th Pow of 4 rank is 16.000000 
// 2th Pow of 3 rank is 8.000000 
// 2th Pow of 5 rank is 32.000000 
