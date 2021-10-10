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

void write_output_file(FILE *fp_out, int result, char *filename)
{
    char *name = (char *)malloc((strlen(filename) + 6) * sizeof(char));
    if (name == NULL)
    {
        fprintf(stderr, "Not enough memory available!\n");
        exit(5);
    }
    strcpy(name, filename);
    strcat(name, ".sol1");
    if ((fp_out = fopen(name, "a")) == NULL) //inicio da leitura do ficheiro
    {
        printf("Error when writing the output file.\n");
        fclose(fp_out);
        exit(EXIT_FAILURE);
    }
    fprintf(fp_out, "%d\n\n", result);
    free(name);
    fclose(fp_out);
}