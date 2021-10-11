#include "Proj_Int.h"

/**
 * @brief Function that reads the labyrinth of from the given file and dinamically stores the information contained in it
 * 
 * @param fp_in 
 * @param filename 
 * @param test_mode 
 * @return int** 
 */

int **Read_input_file(FILE *fp_in, int **labyrinth, char *filename)
{
    
    int **traversed_path = NULL;
    int *size_traversed = NULL;




    int x = 0, y = 0, v = 0, count = 0, P = 0, result = 0;      //P= number of grey/black cells, (x,y) = grey/black cells coordinates, v=value of respective cell
    int C = 0, L = 0, a = 0, b = 0, c = 0, d = 0, num_char = 0; // C=columns, L=lines, (a,b)=coordinates of the cell we want to analyse, P= number of grey/black cells
    char *test_mode = (char *)calloc(3, sizeof(char));

    //meter numa funcao
    num_char = find_last_period(filename);
    char *name = (char *)calloc((num_char + 5), sizeof(char));
    if (name == NULL)
    {
        fprintf(stderr, "Not enough memory available!\n");
        exit(5);
    }
    strncpy(name, filename, num_char);
    strcat(name, "sol1");

    if ((fp_in = fopen(filename, "r")) == NULL) //inicio da leitura do ficheiro
    {
        printf("Error when reading the input file1.\n");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }
    while ((fscanf(fp_in, "%d %d", &L, &C)) != EOF)
    {
        if ((fscanf(fp_in, "%d %d %s", &a, &b, test_mode)) != 3)
        {
            printf("Error reading data from input file2.\n");
            exit(0);
        }
        if (strcmp(test_mode, "A6") == 0)
            if ((fscanf(fp_in, "%d %d", &c, &d)) != 2)
            {
                printf("Error reading data from input file3.\n");
                exit(0);
            }
        // Dynamic allocation of the main labyrinth
        labyrinth = allocate_table(labyrinth, C, L);

        if ((fscanf(fp_in, "%d", &P)) != 1)
        {
            printf("Error reading data from input file.\n");
            exit(0);
        }
        while ((fscanf(fp_in, "%d %d %d", &x, &y, &v) == 3) && (count < P))
        {
            labyrinth[x - 1][y - 1] = v; //remember that the coordinate (0,0) represents the (1,1) cell
            count++;
        }
        //print_table(labyrinth, L, C);
        result = choose_test(test_mode, labyrinth, L, C, a, b, c, d, traversed_path, size_traversed);
        write_output_file(name, result, filename);
        free_labyrinth(labyrinth, L, C);
        count = 0;
    }
    fclose(fp_in);
    free(test_mode);
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