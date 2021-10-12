#include "Proj_Int.h"

/**
 * @brief 
 * 
 * @param fp_in 
 * @param labyrinth 
 * @param filename 
 */

void Read_input_file(char *filename)
{
    int x = 0, y = 0, v = 0, count = 0, P = 0, result = 0; //P= number of grey/black cells, (x,y) = grey/black cells coordinates, v=value of respective cell
    int C = 0, L = 0, a = 0, b = 0, c = 0, d = 0;          // C=columns, L=lines, (a,b)=coordinates of the cell we want to analyse, P= number of grey/black cells
    short **labyrinth = NULL;
    char test_mode[3];
    char *out_name = NULL; //name of the output file

    FILE *fp_in = NULL, *fp_out = NULL;

    fp_in = open_inputfile(fp_in, filename);
    out_name = allocate_outputname(out_name, filename);
    fp_out = open_outputfile(fp_out, out_name);

    while ((fscanf(fp_in, "%d %d", &L, &C)) == 2)
    {
        if ((fscanf(fp_in, "%d %d %s", &a, &b, test_mode)) != 3)
            error(fp_in, fp_out, out_name, filename);

        if (strcmp(test_mode, "A6") == 0)
            if ((fscanf(fp_in, "%d %d", &c, &d)) != 2)
                error(fp_in, fp_out, out_name, filename);

        if ((fscanf(fp_in, "%d", &P)) != 1)
            error(fp_in, fp_out, out_name, filename);

        labyrinth = allocate_table(labyrinth, C, L); // Dynamic allocation of the main labyrinth

        while (count < P)
        {
            if ((fscanf(fp_in, "%d %d %d", &x, &y, &v) != 3))
            {
                free_labyrinth(labyrinth, C);
                error(fp_in, fp_out, out_name, filename);
            }
            labyrinth[x - 1][y - 1] = v; //remember that the coordinate (0,0) represents the (1,1) cell
            count++;
        }
        print_table(labyrinth, L, C);
        result = choose_test(test_mode, labyrinth, L, C, a, b, c, d);
        write_output(fp_out, result);
        free_labyrinth(labyrinth, C);
        count = 0;
    }
    free(out_name);
    fclose(fp_in);
    fclose(fp_out);
    return;
}

void free_labyrinth(short **labyrinth, int C)
{
    short i;
    for (i = 0; i < C; i++)
    {
        free(labyrinth[i]);
    }
    free(labyrinth);
    return;
}

char *allocate_outputname(char *out_name, char *in_name)
{
    short num_char = 0;
    num_char = find_last_period(in_name);
    out_name = (char *)calloc((num_char + 5), sizeof(char));
    if (out_name == NULL)
    {
        fprintf(stderr, "Not enough memory available!\n");
        exit(5);
    }
    strncpy(out_name, in_name, num_char);
    strcat(out_name, "sol1");

    return out_name;
}

void error(FILE *fp_in, FILE *fp_out, char *filename_in, char *filename_out)
{
    printf("Error when reading data.\n");
    fclose(fp_in);
    fclose(fp_out);
    free(filename_out);
    free(filename_in);
    exit(0);
}

FILE *open_inputfile(FILE *fp_in, char *filename)
{
    if ((fp_in = fopen(filename, "r")) == NULL)
    {
        printf("Error when reading the input file.\n");
        free(filename);
        exit(1);
    }
    return fp_in;
}

FILE *open_outputfile(FILE *fp_out, char *filename)
{
    if ((fp_out = fopen(filename, "a")) == NULL)
    {
        printf("Error when writing the output file.\n");
        free(filename);
        exit(1);
    }
    return fp_out;
}
char *get_inputfilename(char **argv, char *filename)
{
    if (strcmp(argv[1], "-s") == 0)
    {
        if ((filename = (char *)malloc((strlen(argv[2]) + 1) * sizeof(char))) == NULL)
        {
            printf("Error when trying to get memory to allocate input file name!\n");
            exit(0);
        }
        strcpy(filename, argv[2]);
    }
    else
    {
        if ((filename = (char *)malloc((strlen(argv[1]) + 1) * sizeof(char))) == NULL)
        {
            printf("Error when trying to get memory to allocate input file name!\n");
            exit(0);
        }
        strcpy(filename, argv[1]);
    }

    return filename;
}