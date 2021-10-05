#include "Proj_Int.h"

int main(int argc, char *argv[])
{

    int opt = 0, test_mode = 0;
    int** labyrinth = NULL;
    FILE *fp;

    if (argc < 3)
    {
        help();
        exit(0);
    }

    while ((opt = getopt(argc, argv, "shq")) != -1)
    {
        switch (opt)
        {
        }

        //FIXME: inside a loop
        labyrinth = Read_input_file(fp, argv[2], &test_mode);
        Print_labyrinth(labyrinth);
        Processing(labyrinth);
        Write_output_file();

        return 0;
    }
}

/**
 * @brief 
 * 
 */
void help(void)
{
    printf("Esta é uma mensagem de Ajuda\n"); //FIXME: Create a better help message
}