#include<mpi.h>
#include<stdio.h>

int main(int argc, char *argv[]){
	int rank,size;
	char str[]="HeLLo";
	int len=5;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	if(rank>=len){
		printf("Current rank is %d, greater than string length\n",rank);
	}
	else{
		printf("%dth position of string %c toggled\n",rank,str[rank]);
		str[rank]+=32;
	}
	MPI_Finalize();
	return 0;

}

// student@lpcp-21:~/210905164/L1$ mpiexec -n 6 ./q4
// 3th position of string L toggled
// Current rank is 5, greater than string length
// 0th position of string H toggled
// 1th position of string e toggled
// 2th position of string L toggled
// 4th position of string o toggled
