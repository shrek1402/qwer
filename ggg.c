#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int magic_cube(int **array, int size)
{
    int i, con = 0, hui = 0, j;
    for (j = 0; j < size; j++)
        con += array[0][j];

    for (i = 0; i < size; i++)
    {
        hui = 0;
        for (j = 0; j < size; j++)
            hui += array[i][j];

        if (hui != con)
            return (-1);
    }
    {
        for (i = 0; i < size; i++)
        {
            hui = 0;
            {
                for (j = 0; j < size; j++)
                    hui += array[j][i];

                if (hui != con)
                    return (-1);
            }
        }
    }
    return (1);
}

int main()
{
    int **a;
    int i, j, n;
    srand(time(NULL));
    
    scanf("%d", &n);
    a = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i++)
    {
        a[i] = (int *)malloc(n * sizeof(int));
    }

    do
    {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] = rand() % 11;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
                printf("%-4d", a[i][j]);

            printf("\n");
        }
        printf("\n");

    } while (magic_cube(a, n) == -1);

    for (i = n - 1; i > 0; i--)
    {
        free(a[i]);
    }
    free(a);


    //kjljhkjgfjhd
    system("PAUSE");
}