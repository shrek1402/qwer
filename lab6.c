#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int ntrl(int num)
{
    if (num > 9 && num < 100)
    {
        int j;

        for (j = 2; j <= sqrt(num); j++)
        {
            if (num % j == 0)
                return (1); // -1 prostoe
        }

        if (num % j != 0 && num != j)
            return (-1);
    }
    else
        return (0);
}

float arithmetick_mean(int *arr, int lot)
{
    float m, sum = 0, k = 0;

    for (int j = 1; j <= lot; j++)
    {
        sum = sum + arr[j];
        k++;
    }

    m = (sum / k);

    if (k)
        return (m);
    else
        return (-1);
}

int max(int *arr, int size)
{
    int max = arr[0];

    for (int j = 0; j <= size; j++)
        if (arr[j] > max)
            max = arr[j];

    return (max);
}

void remove_last_item(int **array, int *size)
{
    (*size)--;
    *array = (int *)realloc(*array, *size * sizeof(int));
    if (!(*array))
        printf("error\n");
}

int main()
{
    int *a;
    int i, j, k = 0, m, n, max_1, max_2;
    float arithmetick_mean_1, arithmetick_mean_2;

    srand(time(NULL));
    scanf("%d", &n);
    printf("#    Znach.  (-1,0,1) \n");
    a = (int *)malloc(n * sizeof(int));

    for (i = 1; i <= n; i++)
    {
        a[i] = rand() % 100 + 1;
        printf("%-2d%6d%10d\n", i, a[i], ntrl(a[i]));
    }

    max_1 = max(a, n);
    arithmetick_mean_1 = arithmetick_mean(a, n);

    printf("The maximum value = %d\n", max_1);
    printf("The average value  = %.1f\n\n\n\n", arithmetick_mean_1);

    for (i = 1; i <= n; i++)
    {
        if (a[i - 1] == -1)
            i--;
        if (ntrl(a[i]) == -1)
        {
            for (j = i; j < n; j++)
                a[j] = a[j + 1];
            i--;
            remove_last_item(&a, &n);
        }
    }

    printf("#    Znach.    (0,1) \n");

    for (i = 1; i <= n; i++)
        printf("%-2d%6d%10d\n", i, a[i], ntrl(a[i]));

    max_2 = max(a, n);
    arithmetick_mean_2 = arithmetick_mean(a, n);

    printf("The maximum value = %d\n", max_2);
    printf("The average value has changed = %.1f\n\n\n\n", arithmetick_mean_2);

    max_1 == max_2 ? printf("The maximum value remains the same\n") : printf("The maximum value has changed\n");

    arithmetick_mean_1 == arithmetick_mean_2 ? printf("The average value remains the same\n") : printf("The average value has changed\n");
    system("PAUSE");
}