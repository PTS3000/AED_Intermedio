#include "Proj_Int.h"

int mode_A1(int a, int b, int **labyrinth, int L, int C) //type of cell
{

    if ((a > L || a < 0 || b > C || b < 0))
    {
        return -2;
    }
    return labyrinth[a - 1][b - 1];
}

int mode_A2(int a, int b, int **labyrinth, int L, int C) //any white cell
{
    int i, x = 1, y = 1;
    int vetor[][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {-1, 0}}; //vector that check the neighbourhood

    for (i = 0; i < 5; i++)
    {
        y = a + vetor[i][0];
        x = b + vetor[i][1];
        if (x > L || x < 0 || y > C || y < 0)
            return -2;
        if (labyrinth[x - 1][y - 1] == 0)
            return 1;
    }
    return 0;
}

int mode_A3(int a, int b, int **labyrinth, int L, int C) //any grey cell
{

    int i, x = 0, y = 0;
    int vetor[][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {-1, 0}}; //vector that check the neighbourhood

    for (i = 0; i < sizeof(vetor[5][2] / (2 * sizeof(int))); i++)
    {
        y = a + vetor[i][0];
        x = b + vetor[i][1];
        if (x > L || x < 0 || y > C || y < 0)
            return -2;
        if (labyrinth[x - 1][y - 1] > 0)
            return 1;
    }
    return 0;
}

int mode_A4(int a, int b, int **labyrinth, int L, int C) //any black cell
{

    int i, x = 1, y = 1;
    int vetor[][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {-1, 0}}; //vector that check the neighbourhood

    for (i = 0; i < 5; i++) //for (i = 0; i < sizeof(vetor[5][2] / (2 * sizeof(int))); i++)
    {
        y = a + vetor[i][0];
        x = b + vetor[i][1];
        if (x > L || x < 0 || y > C || y < 0)
            return -2;
        if (labyrinth[x - 1][y - 1] == -1)
        {
            printf("x-1:%d y-1:%d v:%d\n", x - 1, y - 1, labyrinth[x][y]);
            return 1;
        }
    }
    return 0;
}

int mode_A5(int a, int b, int **labyrinth, int L, int C)
{
    if (labyrinth[a - 1][b - 1] <= 0)
        return -1;
    if (((0 < a) && (a < L)) && ((0 < b) && (b < C)))
    {

        if ((labyrinth[a - 2][b - 1] == 0 && labyrinth[a][b - 1] == 0) || (labyrinth[a - 1][b - 2] == 0 && labyrinth[a - 1][b] == 0))
            return 1;
    }
    if ((a == 1 && b == 1) || (a == L && b == C) || (a == L && b == 1) || (a == C && b == 1))
        return 0;
    if ((a == 1) || (a == L))
    {

        if ((labyrinth[a - 2][b - 1] == 0 && labyrinth[a][b - 1] == 0))
            return 1;
    }

    if ((b == 1) || (b == C))
    {

        if ((labyrinth[a - 2][b - 1] == 0 && labyrinth[a][b - 1] == 0))
            return 1;
    }

    return 0;
}

/*
int traversed(int x, int y, int **traversed_path, int L, int C, int *size_traversed)
{
    int i;
    for (i = 0; i < (*size_traversed); i++)
    {
        if (x == traversed_path[i][0] && y == traversed_path[i][1]) return 1;
    }
    return 1;
}

int try(int x,int y, int **labyrinth, int **traversed_path, int x_finish, int y_finish, int *size_traversed, int L, int C)
{
    if (x < 0 || y < 0 || x > L-1 || y > C-1) return 0;
    if (traversed(x, y, traversed_path, L, C, size_traversed) || labyrinth[x][y] > 0) return 0;
    //colocar no traversed_path
    labyrinth[x][y] = -3;
    (*size_traversed)++;
    if (x == x_finish && y == y_finish)
    {
        //tirar do traversed_path
        return 1;
    }
    else
    {
        try(x - 1, y, labyrinth, traversed_path, x_finish, y_finish, size_traversed, L, C);
        try(x + 1, y, labyrinth, traversed_path, x_finish, y_finish, size_traversed, L, C);
        try(x, y + 1, labyrinth, traversed_path, x_finish, y_finish, size_traversed, L, C);
        try(x, y - 1, labyrinth, traversed_path, x_finish, y_finish, size_traversed, L, C);
    }
    //tirar dos traversed_path
    return 0;
    

}


int mode_A6(int a, int b, int l, int c, int **labyrinth, int **traversed_path, int *size_traversed, int L, int C)
{

    return try(a, b, labyrinth, traversed_path, l, c, size_traversed, L, C);
    return 0;
}
*/
int **allocate_table(int **labyrinth, int C, int L)
{
    int i;
    labyrinth = (int **)malloc(L * sizeof(int *)); //allocates lines
    for (i = 0; i < L; i++)
        labyrinth[i] = (int *)calloc(C, sizeof(int)); //allocates columns
    return labyrinth;
}

int choose_test(char *test_mode, int **labyrinth, int L, int C, int a, int b)
{
    if (strcmp(test_mode, "A1") == 0)
        return mode_A1(a, b, labyrinth, L, C);
    if (strcmp(test_mode, "A2") == 0)
        return mode_A2(a, b, labyrinth, L, C);
    if (strcmp(test_mode, "A3") == 0)
        return mode_A3(a, b, labyrinth, L, C);
    if (strcmp(test_mode, "A4") == 0)
        return mode_A4(a, b, labyrinth, L, C);
    if (strcmp(test_mode, "A5") == 0)
        return mode_A5(a, b, labyrinth, L, C);
    if (strcmp(test_mode, "A6") == 0)
        return mode_A6(a, b, l, c, labyrinth, traversed_path, &size_traversed, L, C);
    return 0;
}