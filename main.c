#include "Proj_Int.h"

/*void Print_labyrinth(int** labyrinth)
{
    int i=0, j=0;
}
*/

int main(int argc, char *argv[])
{
    int test_mode = 0, result = 0, **labyrinth = NULL;
    int C = 0, L = 0, a = 0, b = 0, c = 0, d = 0; // C=columns, L=lines, (a,b)=coordinates of the cell we want to analyse, P= number of grey/black cells
    FILE *fp_in = NULL, *fp_out = NULL;

    if (argc != 3)
    {
        help();
        exit(0);
    }

    //FIXME: inside a loop
    labyrinth = Read_input_file(fp_in, labyrinth, argv[2], &test_mode, &L, &C, &a, &b, &c, &d);
    print_table(labyrinth, L, C); //optional
    result = choose_test(test_mode, labyrinth, L, C, a, b);
    write_output_file(fp_out, result, argv[2]);
    free_labyrinth(labyrinth, L, C);
    printf("**%d**\n", result);
    return 0;
}

/**
 * @brief 
 * 
 */
void help(void)
{
    printf("Esta é uma mensagem de Ajuda\n"); //FIXME: Create a better help message
}