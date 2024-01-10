#include "mpi.h"
#include <stdio.h>

int main(int argc, char *argv[]) {

    int rank, size, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Status status;

    if(rank == 0) {
        printf("Enter a value in master process:");
        scanf("%d", &x);

        MPI_Send(&x, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        fprintf(stdout, "I have sent %d from process 0\n", x);
        fflush(stdout);
    } else {
        MPI_Recv(&x, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
        fprintf(stdout, "I have received %d in process 1\n", x);
        fflush(stdout);
    }

    MPI_Finalize();
    return 0;
}

// student@lpcp-21:~/210905164/L2$ mpicc ex.c -o q1 
// student@lpcp-21:~/210905164/L2$ mpiexec -n 5 ./q1
// Enter a value in master process:7
// I have sent 7 from process 0
// I have received 7 in process 1
// 7
// 7
// 7
// ^C[mpiexec@lpcp-21] Sending Ctrl-C to processes as requested
// [mpiexec@lpcp-21] Press Ctrl-C again to force abort
