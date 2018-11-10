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
    return (0);
}

float arithmetick_mean(int *arr, size_t lot)
{
    float m, k = 0;
    int sum = 0;
    for (size_t j = 1; j <= lot; j++)
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

int max(int *arr, size_t size)
{
    int max = arr[1];

    for (size_t j = 1; j <= size; j++)
        if (arr[j] > max)
            max = arr[j];

    return (max);
}

void remove_last_item(size_t **array, size_t *size)
{
    (*size)--;
    unsigned int *tmp = (int *)realloc(*array, *size * sizeof(int));
    if (!(*array))
        printf("Error!\n");
    else
        *array = tmp;
}

int main()
{
    int *a;
    int max_1, max_2;
    size_t i,j;
    size_t n;
    float arithmetick_mean_1, arithmetick_mean_2;

    srand(time(NULL));
    do
    {
        scanf("%U", &n);
    } while (n < 1);

    printf("#     Znach.     (-1,0,1) \n");
    a = (int *)malloc(n * sizeof(int));
        if(!(a))
        {
            printf("Error!");
            exit(EXIT_FAILURE);
        }
    for (i = 1; i <= n; i++)
    {
        a[i] = rand() % 100 + 1;
        printf("%-2u%6d%10d\n", i, a[i], ntrl(a[i]));//, a[i], ntrl(a[i]));
        //printf("%-2lu%6lu%10d\n", i, a[i], ntrl(a[i]));
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

    printf("#     Znach.     (0,1) \n");

    for (i = 1; i <= n; i++)
        printf("%-2u%6d%10d\n", i, a[i], ntrl(a[i]));

    max_2 = max(a, n);
    arithmetick_mean_2 = arithmetick_mean(a, n);

    printf("The maximum value = %d\n", max_2);
    printf("The average value has changed = %.1f\n\n\n\n", arithmetick_mean_2);

    max_1 == max_2 ? 
    printf("The maximum value remains the same\n") : 
    printf("The maximum value has changed\n");

    arithmetick_mean_1 == arithmetick_mean_2 ? 
    printf("The average value remains the same\n") :
    printf("The average value has changed\n");
    system("PAUSE");
    free(a);
    return(0);
}