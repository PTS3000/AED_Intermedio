#include "Proj_Int.h"

/**
 * @brief Function that reads the labyrinth of from the given file and dinamically stores the information contained in it
 * 
 * @param fp_in 
 * @param filename 
 * @param test_mode 
 * @return int** 
 */

int **Read_input_file(FILE *fp_in, int **labyrinth, char *filename, int *test_mode, int *L, int *C, int *a, int *b, int *c, int *d)
{
    int i, x = 0, y = 0, v = 0, count = 0, P = 0; //P= number of grey/black cells, (x,y) = grey/black cells coordinates, v=value of respective cell

    if ((fp_in = fopen(filename, "r")) == NULL) //inicio da leitura do ficheiro
    {
        printf("Error when reading the input file.\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }
    fscanf(fp_in, "%d %d", &*L, &*C);
    fscanf(fp_in, "%d %d A%d", &*a, &*b, &*test_mode);
    if (*test_mode == 6)
        fscanf(fp_in, "%d %d", &*c, &*d);
    // Dynamic allocation of the main labyrinth

    labyrinth = (int **)calloc(*L, sizeof(int *)); //allocates lines
    for (i = 0; i < *L; i++)
        labyrinth[i] = (int *)calloc(*C, sizeof(int)); //allocates columns

    fscanf(fp_in, "%d", &P);
    while ((fscanf(fp_in, "%d %d %d", &x, &y, &v) == 3) && (count < P))
    {
        labyrinth[x - 1][y - 1] = v; //remember that the coordinate (0,0) represents the (1,1) cell
        count++;
    }
    fclose(fp_in);
    return labyrinth;
}

void free_labyrinth(int **labyrinth, int L, int C)
{
    int i;
    for (i = 0; i < C; i++)
    {
        free(labyrinth[i]);
    }
    free(labyrinth);
    return;
}