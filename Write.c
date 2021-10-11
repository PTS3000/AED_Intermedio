#include "Proj_Int.h"

void print_table(int **labyrinth, int L, int C)
{
    int i, j, lin;
    for (i = 1; i <= C; i++)
    {
        if (i == 1)
            printf("   ");
        printf(" %d ", i);
    }
    printf("\n");
    for (i = 0; i < L; i++)
    {
        lin = i + 1;
        if (lin <= 9)
        {
            putchar(' ');
            printf("%d", lin);
            putchar(' ');
        }
        else
        {
            printf("%d", lin);
            putchar(' ');
        }
        for (j = 0; j < C; j++)
        {
            if (labyrinth[i][j] == -1)
                printf("%d ", labyrinth[i][j]);
            else
                printf(" %d ", labyrinth[i][j]);
        }
        putchar('\n');
    }
}

int find_last_period(char *filename)
{
    char *buffer = NULL;
    int value = 0, n_chars = 0;
    for (buffer = filename; *buffer != '\0'; buffer++)
    {
        n_chars++;
        if (*buffer == '.')
            value = n_chars;
    }
    return value;
}
void write_output(FILE *fp_out, int result)
{
    fprintf(fp_out, "%d\n\n", result);
}