#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
int main()
{
    srand(time(NULL));
    int **a = NULL;  // Матрица
    float *D = NULL; // Вектор среднего ариф. каждой строки
    int *G = NULL;   // вектор кол-ва отриц. эл. каждого столбца
    int sum = 0;
    size_t i, j, str, stlb, kol_otr;

//Ввод кол-ва строк
    do
    {
        printf("Enter size array\nStrok: ");
        scanf("%lu", &str);
    } while (str < 1);

//Ввод кол-ва столбцов
    do
    {
        printf("Stolbcov: ");
        scanf("%lu", &stlb);
    } while (stlb < 1);

//Создание массива указателей строк
    a = (int **)malloc(str * sizeof(int *));
    if (!(a))
    {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }

//Создание массива указателей столбцов
    for (i = 0; i < str; i++)
    {
        a[i] = (int *)malloc(stlb * sizeof(int));
        if (!(a[i]))
        {
            printf("Error!\n");
            exit(EXIT_FAILURE);
        }
    }
//Заполнение двумерного массива
    for (i = 0; i < str; i++)
    {
        for (j = 0; j < stlb; j++)
        {
            a[i][j] = rand() % 21 - 10;
        }
    }
//Вывод двумерного массива
    for (i = 0; i < str; i++)
    {
        for (j = 0; j < stlb; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }
    printf("\n");

// Вектор среднего ариф. каждой строки
    D = (float *)malloc(str * sizeof(float));
    if (!(D))
    {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }
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

//Вектор кол-ва отрицательных элементов в каждой строке
    G = (int *)malloc(stlb * sizeof(int));
    if (!(G))
    {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }
    printf("\nG = |");
    for (i = 0; i < stlb; i++)
    {
        kol_otr = 0;
        for (j = 0; j < str; j++)
            if (a[j][i] < 0)
                kol_otr += 1;
        G[i] = kol_otr;

        if (i != stlb - 1)
            printf("%d, ", G[i]);
        else
            printf("%d", G[i]);
    }
    printf("|\n");
    
//Освобождение памяти
    free(G);
    free(D);
    for (i = 0; i < str; i++)
        free(a[i]);
    free(a);

    system("PAUSE");
    return (EXIT_SUCCESS);
}