#include "mpi.h"
#include<stdio.h>

void ErrorHandler(int ecode){
	if(ecode != MPI_SUCCESS){
		char error_string[100];
		int len,error_class;
		MPI_Error_class(ecode,&error_class);
		MPI_Error_string(ecode,error_string,&len);
		printf("%d %s\n",ecode,error_string);
		MPI_Error_string(error_class,error_string,&len);
		printf("%d %s\n",error_class,error_string);
	}
}

int main(int argc,char* argv[]){
	int rank,error_code,size,fact = 1,factsum,i;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
	for(i=1;i<=rank+1;i++){
		fact = fact*i;
	}
	error_code = MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
	ErrorHandler(error_code);
	if(rank == size-1){
		printf("Sum of all factorial: %d",factsum);
	}
	MPI_Finalize();
	return 0;
}