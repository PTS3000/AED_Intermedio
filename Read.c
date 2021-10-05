#include "Proj_Int.h"

/**
 * @brief Function that reads the labyrinth of from the given file and dinamically stores the information contained in it
 * 
 * @param fp 
 * @param filename 
 * @param test_mode 
 * @return int** 
 */

int ** Read_input_file(FILE *fp, char *filename, int *test_mode)
{
    int C = 0, L = 0, a = 0, b = 0, P = 0; // C=columns, L=lines, (a,b)=coordinates of the cell we want to analyse, P= number of grey/black cells
    int i, x = 0, y = 0, v = 0, count = 0; // (x,y) = grey/black cells coordinates, v=value of respective cell
    
    if ((fp = fopen(filename, "r")) == NULL) //inicio da leitura do ficheiro
        {
            printf("Error when reading the input file.\n");
            fclose(fp);
            exit(EXIT_FAILURE);
        }
    fscanf(fp, "%d %d", &L, &C);
    fscanf(fp, "%d %d A%d", &a, &b, &*test_mode);

    // Dynamic allocation of the main labyrinth

    int **labyrinth = (int **)calloc(L, sizeof(int *));
    for (i = 0; i < L; i++)
        labyrinth[i] = (int *)calloc(C, sizeof(int));

    fscanf(fp, "%d", &P);
    while ((fscanf(fp, "%d %d %d", &x, &y, &v) == 3) && (count < P))
    {
        if (v > 0){
            labyrinth[x-1][y-1] = v;    //remember that the coordinate (0,0) represents the (1,1) cell
            count ++;
        }
    }
    return labyrinth;
}