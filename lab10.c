
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void replace_even_element(int **array, int _str, int _stlb)
{
    int i, j;

    for (i = 0; i < _str; i++)
        for (j = 0; j < _stlb; j++)
            if (array[i][j] % 2 == 0)
                array[i][j] = 0;
}

int main()
{
    srand(time(NULL));
    int str, stlb, i, j, **a = NULL;
    do
    {
        printf("Enter size array\nStrok: ");
        scanf("%d", &str);
    } while (str < 1);

    //Ввод кол-ва столбцов
    do
    {
        printf("Stolbcov: ");
        scanf("%d", &stlb);
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
            a[i][j] = rand() % 10;
        }
    }
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stlb; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }
    printf("\n");
    replace_even_element(a, str, stlb);
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < stlb; j++)
            printf("%4d", a[i][j]);

        printf("\n");
    }
}
