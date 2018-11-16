#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для записи каждого элемента в обратном порядке.
int flip(int _num)
{
    int tmp = _num, a = 0;
    while (tmp > 0)
    {
        a = a * 10 + tmp % 10;
        tmp /= 10;
    }
    return (a);
}

//Функция для определения кол-ва простых чисел в массиве.
int prime_number(int _num)
{
    int j;

    for (j = 2; j <= sqrt(_num); j++)
    {
        if (_num % j == 0)
            return (1); //  1 - Составное число
    }                   //  0 - Простое число

    if (_num % j != 0 && _num != j)
        return (0);
}

int main()
{
    int number_digits, tmp_prime, max = 0;
    scanf("%d", &number_digits);
    int a[number_digits];
    srand(time(NULL));

    for (int i = 0; i < number_digits; i++)
    {
        a[i] = rand() % 10001;
        if (!(prime_number(a[i])))
            tmp_prime++;
        if (a[i] > max)
            max = a[i];
    }

    for (int i = 0; i < number_digits; i++)
        printf("a[%d] = %d\n", i + 1, a[i]);

    printf("Maximum element = %d\n", max);
    printf("Number of Prime numbers = %d\n\n", tmp_prime);
    tmp_prime = 0;
    max = 0;

    for (int i = 0; i < number_digits; i++)
    {
        a[i] = flip(a[i]);
        if (!(prime_number(a[i])))
            tmp_prime++;
        if (a[i] > max)
            max = a[i];
        printf("a[%d] = %d\n", i + 1, a[i]);
    }

    printf("Maximum element = %d\n", max);
    printf("Number of Prime numbers = %d\n", tmp_prime);
}