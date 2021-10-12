#include "Proj_Int.h"

int mode_A1(int a, int b, short **labyrinth, int L, int C) //type of cell
{

    if ((a > L || a < 0 || b > C || b < 0))
    {
        return -2;
    }
    return labyrinth[a - 1][b - 1];
}

int mode_A2(int a, int b, short **labyrinth, int L, int C) //any white cell
{
    int i, x = 1, y = 1;
    short vetor[][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {-1, 0}}; //vector that check the neighbourhood

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

int mode_A3(int a, int b, short **labyrinth, int L, int C) //any grey cell
{

    int i, x = 0, y = 0;
    int vetor[][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {-1, 0}}; //vector that check the neighbourhood

    for (i = 0; i < sizeof(vetor[5][2] / (2 * sizeof(short))); i++)
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

int mode_A4(int a, int b, short **labyrinth, int L, int C) //any black cell
{

    int i, x = 1, y = 1;
    int vetor[][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {-1, 0}}; //vector that check the neighbourhood

    for (i = 0; i < 5; i++) //for (i = 0; i < sizeof(vetor[5][2] / (2 * sizeof(short))); i++)
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

int mode_A5(int a, int b, short **labyrinth, int L, int C)
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

int mode_A6(int a, int b, int l, int c, short **labyrinth, int L, int C)
{
    int n_pairs = ((2 * (L - 1) * (C - 1)) + C - 1 + L - 1); //n max num of pairs = 2LC - L - C
    short **pairs_data = create_pairs(labyrinth, n_pairs, L, C);
    short *id = NULL;
    if ((id = (short *)calloc(L * C, sizeof(short))) == NULL)
    {
        printf("Error when allocating memory!\n");
        free_labyrinth(labyrinth, C);
        free_pairs(pairs_data, n_pairs, L, C);
        exit(1);
    }

    int start = get_index(a, b, C), finish = get_index(l, c, C), result = 0;
    result = compressed_weighted_quick_union(id, (L * C) - 1, pairs_data, n_pairs, start, finish);
    free_pairs(pairs_data, n_pairs, L, C);
    free(id);
    return result;
}

short **allocate_table(short **labyrinth, int C, int L)
{
    int i;
    labyrinth = (short **)malloc(L * sizeof(short *)); //allocates lines
    for (i = 0; i < L; i++)
        labyrinth[i] = (short *)calloc(C, sizeof(short)); //allocates columns
    return labyrinth;
}

int choose_test(char *test_mode, short **labyrinth, int L, int C, int a, int b, int c, int d)

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
        return mode_A6(a, b, c, d, labyrinth, L, C);

    return 0;
}
void free_pairs(short **pairs, int n_pairs, int L, int C)
{
    int i;
    for (i = 0; i < n_pairs; i++)
    {
        free(pairs[i]);
    }
    free(pairs);
}

short **create_pairs(short **labyrinth, int n_pairs, int L, int C)
{

    int i = 0, j = 0, k = 0;

    short **pairs = (short **)calloc(n_pairs, sizeof(short *));
    for (i = 0; i < n_pairs; i++)
        pairs[i] = (short *)calloc(2, sizeof(short));

    for (i = 0; i <= L - 1; i++)
    {
        for (j = 0; j <= C - 1; j++)
        {
            if (j != (C - 1))
            {
                if ((labyrinth[i][j] == 0) && (labyrinth[i][j + 1] == 0))
                {
                    pairs[k][0] = get_index(j, i, C);
                    pairs[k][1] = get_index(j + 1, i, C);
                    printf("%hd-%hd\n", pairs[k][0], pairs[k][1]);
                    k++;
                }
            }
            if (i != (L - 1))
            {
                if ((labyrinth[i][j] == 0) && (labyrinth[i + 1][j] == 0))
                {
                    pairs[k][0] = get_index(j, i, C);
                    pairs[k][1] = get_index(j, i + 1, C);
                    printf("%hd-%hd\n", pairs[k][0], pairs[k][1]);
                    k++;
                }
            }
            /*if (i != (C - 1) &&  != (L - 1))
            {

                if ((labyrinth[i][j] == 0) && (labyrinth[i][j + 1] == 0))
                {
                    pairs[k][0] = get_index(j, i, C);
                    pairs[k][1] = get_index(j + 1, i, C);
                    printf("%hd-%hd\n", pairs[k][0], pairs[k][1]);
                    k++;
                }
                if ((labyrinth[i][j] == 0) && (labyrinth[i + 1][j] == 0))
                {
                    pairs[k][0] = get_index(j, i, C);
                    pairs[k][1] = get_index(j, i + 1, C);
                    printf("%hd-%hd\n", pairs[k][0], pairs[k][1]);
                    k++;
                }*/
        }
    }
    return pairs;
}
int get_index(int x, int y, int C)
{
    return (y * C) + x;
}

int compressed_weighted_quick_union(short *id, int N, short **pairs, int n_pairs, int start, int finish)
{

    int i, j, t, x;
    short *sz = (short *)malloc(N * sizeof(short));
    if (sz == NULL)
    {
        printf("Error when allocating memory!\n");
        exit(1);
    }
    /* initialize; all disconnected */
    for (i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    short k = 0;
    /* read while there is data */
    for (k = 0; k < n_pairs; k++)
    {
        /* do search first */
        for (i = pairs[k][0]; i != id[i]; i = id[i])
            ;
        for (j = pairs[k][1]; j != id[j]; j = id[j])
            ;

        if (i == j)
        {
            /* already in the same set; discard */
            continue;
        }

        /* pair has new info; must perform union; pick right direction */
        if (sz[i] < sz[j])
        {
            id[i] = j;
            sz[j] += sz[i];
            t = j;
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
            t = i;
        }
        /* retrace the path and compress to the top */
        for (i = pairs[k][0]; i != id[i]; i = x)
        {
            x = id[i];
            id[i] = t;
        }
        for (j = pairs[k][1]; j != id[j]; j = x)
        {
            x = id[j];
            id[j] = t;
        }
    }

    for (int raiz = 0; raiz < N; raiz++)
    {
        if (id[raiz] == raiz)
        {
            printf("\n%d-", raiz);
            for (int j = 0; j < N; j++)
            {
                if ((j != raiz) && (id[j] == raiz))
                    printf("%d-", j);
            }
        }
    }

    free(sz);
    if (id[start] == id[finish])
        return 1;
    else
    {
        return 0;
    }
}
