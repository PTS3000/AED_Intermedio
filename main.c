#include "Proj_Int.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        help();
        exit(0);
    }
    Read_input_file(argv[2]);

    return 0;
}

void help(void)
{
    printf("Esta é uma mensagem de Ajuda\n"); //FIXME: Create a better help message
}