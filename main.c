#include "Proj_Int.h"

/*void Print_labyrinth(int** labyrinth)
{
    int i=0, j=0;
}
*/

int main(int argc, char *argv[])
{

    int opt = 0, test_mode = 0;
    int **labyrinth = NULL;
    int C = 0, L = 0, a = 0, b = 0, c = 0, d = 0; // C=columns, L=lines, (a,b)=coordinates of the cell we want to analyse, P= number of grey/black cells
    FILE *fp = NULL;

    if (argc != 3)
    {
        help();
        exit(0);
    }

    //FIXME: inside a loop
    labyrinth = Read_input_file(fp, labyrinth, argv[2], &test_mode, &L, &C, &a, &b ,&c ,&d);
    //Print_labyrinth(labyrinth);
    //Processing(labyrinth);
    //Write_output_file();
    printf("SUCESSO");
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