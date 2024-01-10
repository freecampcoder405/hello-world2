#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if((rank+1)%2==0){
		printf("My rank is %d: Hello\n",rank+1);
	}
	else{
		printf("My rank is %d: World\n",rank+1);
	}
	MPI_Finalize();
	return 0;

}
// student@lpcp-21:~/210905164/L1$ mpicc q2.c -o q2
// student@lpcp-21:~/210905164/L1$ mpiexec -n 7 ./q2
// My rank is 1: World
// My rank is 2: Hello
// My rank is 5: World
// My rank is 6: Hello
// My rank is 3: World
// My rank is 4: Hello
// My rank is 7: World
// student@lpcp-21:~/210905164/L1$ 

