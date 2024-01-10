#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define MCW MPI_COMM_WORLD

 
int main(int argc, char *argv[]) {
    int rank, size, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    MPI_Status status;
    if (rank == 0) {
        printf("Enter a value in master process: ");
        scanf("%d", &x);
        MPI_Ssend(&x, 1, MPI_INT, 1, 1, MCW);
        printf("I have sent %d from process 0\n", x);
        MPI_Recv(&x, 1, MPI_INT, size-1, 1, MCW, &status);
        printf("I have received %d in process 0\n", x);
    } else {
        MPI_Recv(&x, 1, MPI_INT, rank-1, 1, MCW, &status);
        printf("I have received %d in process %d\n", x, rank);
        x = x+1;
        if (rank == size-1) {
            MPI_Ssend(&x, 1, MPI_INT, 0, 1, MCW);
        } else {
            MPI_Ssend(&x, 1, MPI_INT, rank+1, 1, MCW);
        }
    }
    MPI_Finalize();
    return 0;
}

// student@lpcp-21:~/210905164/L2$ mpicc q4.c -o q4 
// student@lpcp-21:~/210905164/L2$ mpiexec -n 4 ./q4
// Enter a value in master process: 5
// I have sent 5 from process 0
// I have received 8 in process 0
// I have received 5 in process 1
// I have received 6 in process 2
// I have received 7 in process 3
