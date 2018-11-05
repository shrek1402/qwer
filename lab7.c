#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int **a = NULL;  // Матрица
    float *D = NULL; // Вектор среднего ариф. каждой строки
    int *G = NULL;   // вектор кол-ва отриц. эл. каждого столбца
    int sum = 0, i, j, str, stlb, kol_otr = 0;

    printf("Enter size array\nStrok: ");
    scanf("%d", &str);

    printf("Stolbcov: ");
    scanf("%d", &stlb);

    a = (int **)malloc(str * sizeof(int *));

    for (i = 0; i < str; i++)
    {
        a[i] = (int *)malloc(stlb * sizeof(int));
    }

    for (i = 0; i < str; i++)
    {
        for (j = 0; j < stlb; j++)
        {
            a[i][j] = rand() % 21 - 10;
        }
    }
    for (i = 0; i < str; i++)
    {
        for (j = 0; j < stlb; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }

    printf("\n");

    D = (float *)malloc(str * sizeof(float));
    printf("D = ");
    for (i = 0; i < str; i++)
    {
        sum = 0;
        for (j = 0; j < stlb; j++)
        {
            sum += a[i][j];
        }

        D[i] = ((float)sum / (float)stlb);

        if (i == 0)
            printf("|%4.1f|\n", D[0]);
        else
            printf("    |%4.1f|\n", D[i]);
    }

    G = (int *)malloc(stlb * sizeof(int));
    printf("\nG = |");
    for (i = 0; i < str; i++)
    {
        kol_otr = 0;
        for (j = 0; j < stlb; j++)
            if (a[j][i] < 0)
                kol_otr += 1;
        G[i] = kol_otr;
        if (i != str - 1)
            printf("%d, ", G[i]);
        else
            printf("%d", G[i]);
    }
    printf("|");
}