#include <conio.h>
#include <stdio.h>

int main(void)
{
    char ch='s';
    while (ch != 13)
    {
        kbhit();
        ch = getch();
        printf("Stepa huy!", getch());
    }
}