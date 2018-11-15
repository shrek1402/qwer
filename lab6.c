#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
//Проверка числа на простоту
int ntrl(int num)
{
    if (num > 9 && num < 100)
    {
        int j;

        for (j = 2; j <= sqrt(num); j++)
        {
            if (num % j == 0)
                return (1); // -1 prostoe
        }                   // 1 и 0 составные

        if (num % j != 0 && num != j)
            return (-1);
    }
    return (0);
}

//Поиск среднего арифметического всего массива
float arithmetick_mean(int *arr, int lot)
{
    float m, k = 0;
    int sum = 0;
    for (int j = 0; j < lot; j++)
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

//Поиск максимума
int max(int *arr, int size)
{
    int max = arr[0];

    for (int j = 0; j < size; j++)
        if (arr[j] > max)
            max = arr[j];

    return (max);
}

//Удаление последнего элемента массива, изменение размера на n-1
void remove_last_item(int **array, int *size)
{
    (*size)--;
    int *tmp = (int *)realloc(*array, *size * sizeof(int));
    if (!(*tmp))
    {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }
        else
            *array = tmp;
}

int main()
{
    int *a;
    int max_1, max_2;
    int i, j;
    int n;
    float arithmetick_mean_1, arithmetick_mean_2;

    srand(time(NULL));
    do
    {
        scanf("%d", &n);
    } while (n < 1);

    printf("#     Znach.     (-1,0,1) \n");
    a = (int *)malloc(n * sizeof(int));
    if (!(a))
    {
        printf("Error!");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
        printf("%-2d%6d%10d\n", i+1, a[i], ntrl(a[i]));
    }

    max_1 = max(a, n);
    arithmetick_mean_1 = arithmetick_mean(a, n);

    printf("The maximum value = %d\n", max_1);
    printf("The average value  = %.1f\n\n", arithmetick_mean_1);

    /////////////////////////////////////////////////////////////////////
    for (i = 0; i < n; i++)
    {

        if (i > 0)
            if (ntrl(a[i - 1]) == -1)
                i--; //Если предыдущей элемент простое число(мы его могли пропустить) вернуться назад

        if (ntrl(a[i]) == -1)       //Если элемент простое число, то
        {
            for (j = i; j < n-1; j++) //Сместить все элементы начиная со следующего на 1 назад
                a[j] = a[j + 1];

            remove_last_item(&a, &n); // Где-то тут ошибка :(
        }
    }

    printf("#     Znach.     (0,1) \n");

    for (i = 1; i <= n; i++)
        printf("%-2d%6d%10d\n", i, a[i], ntrl(a[i]));

    max_2 = max(a, n);
    arithmetick_mean_2 = arithmetick_mean(a, n);

    printf("The maximum value = %d\n", max_2);
    printf("The average value has changed = %.1f\n\n", arithmetick_mean_2);

    max_1 == max_2 ? 
    printf("The maximum value remains the same\n") : 
    printf("The maximum value has changed\n");

    arithmetick_mean_1 == arithmetick_mean_2 ? 
    printf("The average value remains the same\n") : 
    printf("The average value has changed\n");
    
    free(a);
    return (0);
}