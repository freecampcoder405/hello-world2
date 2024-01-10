#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#define MCW MPI_COMM_WORLD

int main(int argc, char *argv[])
{
    int rank, size, x;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    MPI_Status status;
    int len=96+size;
    int buffer[96+size];
    MPI_Buffer_attach(buffer, len);
    if (rank == 0)
    {
        int array[size - 1];
        printf("Enter %d elements : ", size - 1);
        for (int i = 0; i < size - 1; i++)
        {
            scanf("%d", &array[i]);
        }
        for (int i = 0; i < size - 1; i++)
        {
            MPI_Bsend(&array[i], 1, MPI_INT, i + 1, i + 1, MCW);
        }
    }
    else
    {
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, rank, MCW, &status);
        if (rank % 2 == 0)
        {
            printf("Received digit: %d in process: %d, cube value : %d\n", num, rank, num * num * num);
        }
        else
        {
            printf("Received digit: %d in process: %d, square value : %d\n", num, rank, num * num);
        }
    }

    MPI_Finalize();
    return 0;
}

// student@lpcp-21:~/210905164/L2$ mpiexec -n 4 ./q3
// Enter 3 elements : 5
// 4
// 3
// Received digit: 5 in process: 1, square value : 25
// Received digit: 4 in process: 2, cube value : 64
// Received digit: 3 in process: 3, square value : 9
