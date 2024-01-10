#include "mpi.h"
#include <stdio.h>
#include <string.h>
#define MCW MPI_COMM_WORLD

void word_toggle(char *word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            word[i] += 32;
        }
    }
}

int main(int argc, char *argv[])
{
    int rank, size;
    char word[100];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    MPI_Status status;

    if (rank == 0)
    {
        printf("Enter a word in master process:");
        scanf("%s", word);
        MPI_Ssend(word, 100, MPI_CHAR, 1, 1, MCW);
        fprintf(stdout, "I have sent the word %s from process %d\n", word, rank);
        fflush(stdout);
        MPI_Recv(word, 100, MPI_CHAR, 1, 1, MCW, &status);
        printf("After toggle word is: %s\n", word);
    }
    else
    {
        MPI_Recv(word, 100, MPI_CHAR, 0, 1, MCW, &status);
        fprintf(stdout, "I have received the word %s in process %d\n", word, rank);
        fflush(stdout);
        word_toggle(word);
        MPI_Ssend(word, 100, MPI_CHAR, 0, 1, MCW);
    }

    MPI_Finalize();
    return 0;
}

//  mpiexec -n 2 ./q1
// Enter a word in master process:you
// I have sent the word you from process 0
// I have received the word you in process 1
// After toggle word is: YOU

