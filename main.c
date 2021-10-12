/*                                                                                                                                       
  ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______ 
 /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/ 
 /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/ 
                                                                                                                                       
                                                                                                                                       

__________        .__    .___                               .___        .__  .__    __________                              .__    .___      
\______   \_____  |__| __| _/___________  ______   ____   __| _/ _____  |  | |  |   \______   \___.__.____________    _____ |__| __| _/______
 |       _/\__  \ |  |/ __ |/ __ \_  __ \/  ___/  /  _ \ / __ |  \__  \ |  | |  |    |     ___<   |  |\_  __ \__  \  /     \|  |/ __ |/  ___/
 |    |   \ / __ \|  / /_/ \  ___/|  | \/\___ \  (  <_> ) /_/ |   / __ \|  |_|  |__  |    |    \___  | |  | \// __ \|  Y Y  \  / /_/ |\___ \ 
 |____|_  /(____  /__\____ |\___  >__|  /____  >  \____/\____ |  (____  /____/____/  |____|    / ____| |__|  (____  /__|_|  /__\____ /____  >
        \/      \/        \/    \/           \/              \/       \/                       \/                 \/      \/        \/    \/                                                                                                                                        
                                                                                                                                 
Realizado com amor e carinho por:  

Ricardo Silva, nº 100071
Luís Parra, nº 100008        

No glorioso ano letivo 2021/2022, para a cadeira de Algoritmos e Estruturas de Dados,
no âmbito da Licenciatura Bolonha em Engenharia Eletrotécnica e de Computadores. 

  ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______   ______ 
 /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/ 
 /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/  /_____/ 
 
 =========================================================================================================================================
 */
#include "Proj_Int.h"

int main(int argc, char *argv[])
{
    char *filename = NULL;
    if (argc != 3)
    {
        help();
        exit(0);
    }
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
    Read_input_file(filename);
    free(filename);
    return 0;
}

void help(void)
{
    printf("Esta é uma mensagem de Ajuda\n"); //FIXME: Create a better help message
}