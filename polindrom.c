#include <stdio.h> //53.9
#include <stdlib.h>

unsigned long long int perevorot(unsigned long long int y)
{
    unsigned long long int m = 0, z = y;
    while (z > 0)
    {
        m = m * 10 + (z) % 10;
        (z) = (z) / 10;
    }
    return (m);
}

void polindrom(unsigned long long int *x)
{
    int i=0; 
    while ((*x) != perevorot(*x))
    {
        i++;
        printf("i= %llu\n", i);
        printf("x= %llu\n", *x);
        printf("p= %llu\n\n", perevorot(*x));
        (*x) += perevorot(*x);
    }

}

int main() 
{
    int m = 0;
    unsigned long long int num;
    do{
    scanf("%llu", &num);
    polindrom(&num);
    printf("***%llu***\n", num);
    }while (num != 0);
}
