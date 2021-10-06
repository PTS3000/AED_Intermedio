
#include "Proj_Int.h"

int mode_A1(int a, int b, int **labyrinth, int L, int C)
{

    if ((a > (L - 1) || a < 0 || b > (C - 1) || b < 0))
    {
        return -2;
    }

    return labyrinth[a][b];
}

int mode_A2(int a, int b, int **labyrinth, int L, int C)
{
    int i = 0, x = 0, y = 0;
    if ((a > (L - 1) || a < 0 || b > (C - 1) || b < 0))
    {
        return -2;
    }

    int vetor[][2] = {(0, 0), (1, -1), (1, 0), (1, 1), (-1, 0), (0, 1), (-1, -1), (-1, 0), (-1, 1)}; //vector that check the neighbourhood
    for (i = 0; i < 8; i++)
    {
        y = a + vetor[i][1];
        x = b + vetor[i][0];
        if (x > (L - 1) || x < 0 || y > (C - 1) || y < 0)
            return -2;
        if (labyrinth[x][y] == 0)
            return 1;
    }
    return 0;
}

int mode_A3(int a, int b)
{

    return 0;
}

int mode_A4(int a, int b)
{

    return 0;
}

int mode_A5(int a, int b)
{

    return 0;
}

int mode_A6(int a, int b)
{

    return 0;
}

int choose_test(int test_mode, int **labyrinth, int L, int C, int a, int b)
{
    switch (test_mode)

    {
    case 1:
        mode_A1(a, b, labyrinth, L, C);
        break;

    case 2:
        mode_A2(a, b, labyrinth, L, C);
        break;

    case 3:
        mode_A3(a, b);
        break;

    case 4:
        mode_A4(a, b);
        break;

    case 5:
        mode_A5(a, b);
        break;

    case 6:
        mode_A6(a, b);
        break;
    }
}