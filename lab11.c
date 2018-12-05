#include<stdio.h>
#include <time.h>
#include<stdlib.h>
int kr_5(int **array)
{
    int i, j,k=0;

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            if (array[i][j] % 5 == 0 && array[i][j]!=0)
                k++;
    return (k);
}

int main()
{
    int **a=NULL,i,j;

    a = (int **)malloc(5 * sizeof(int *));
    if (!(a))
    {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }

    //Создание массива указателей столбцов
    for (i = 0; i < 5; i++)
    {
        a[i] = (int *)malloc(5 * sizeof(int));
        if (!(a[i]))
        {
            printf("Error!\n");
            exit(EXIT_FAILURE);
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
    printf("Kol-vo elementov kratnih 5: %d\n", kr_5(a));
}
