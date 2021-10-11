#include "Proj_Int.h"

int main(int argc, char *argv[])
{
    int **labyrinth = NULL;
    FILE *fp_in = NULL;
    if (argc != 3)
    {
        help();
        exit(0);
    }
    labyrinth = Read_input_file(fp_in, labyrinth, argv[2]);

    return 0;
}

void help(void)
{
    printf("Esta é uma mensagem de Ajuda\n"); //FIXME: Create a better help message
}