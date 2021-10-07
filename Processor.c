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
    int vetor[][2] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {-1, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}}; //vector that check the neighbourhood

    for (i = 0; i < 9; i++)
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
    int vetor[][2] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {-1, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}}; //vector that check the neighbourhood

    for (i = 0; i < 9; i++)
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
    int vetor[][2] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {-1, 0}, {0, 1}, {-1, -1}, {-1, 0}, {-1, 1}}; //vector that check the neighbourhood

    for (i = 0; i < 9; i++)
    {
        y = a + vetor[i][0];
        x = b + vetor[i][1];
        if (x > L || x < 0 || y > C || y < 0)
            return -2;
        if (labyrinth[x - 1][y - 1] == -1)
        {
            printf("x-1:%d y-1:%d v:%d\n", x - 1, y - 1, labyrinth[x - 1][y - 1]);
            return 1;
        }
    }
    return 0;
}

int mode_A5(int a, int b, int **labyrinth, int L, int C)
{
    int i, x = 1, y = 1;
    int vetor[][2] = {{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}}; //Center-North-West-South-East

    for (i = 0; i < 5; i++)
    {
        y = a + vetor[i][0];
        x = b + vetor[i][1];
        if ((i == 0 && (labyrinth[x - 1][y - 1] == 0 || labyrinth[x - 1][y - 1] == -1)) && (x > L || x < 0 || y > C || y < 0))
            return -1;
        if (labyrinth[x - 1][y - 1] == -1)
            return 1;
    }
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
        return mode_A1(a, b, labyrinth, L, C);
        break;
    case 2:
        return mode_A2(a, b, labyrinth, L, C);
        break;
    case 3:
        return mode_A3(a, b, labyrinth, L, C);
        break;
    case 4:
        return mode_A4(a, b, labyrinth, L, C);
        break;
    case 5:
        return mode_A5(a, b, labyrinth, L, C);
        break;
    case 6:
        return mode_A6(a, b);
        break;
    }
    return 0;
}