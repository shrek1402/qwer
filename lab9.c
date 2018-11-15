#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
    struct data
    {
        int num;
        char fio[20];
        char gender[1]; //-1 women 1 man
        int gr;
        int gpnr;
    } tmp;
    struct data data_array[] = {1, "Anisimov U. P.", "M", 1940, 1957,
                                2, "Ivanov I. N.", "M", 1980, 1999,
                                3, "Mahova O. I.", "W", 1960, 1980,
                                4, "Ogarev K. M.", "M", 1971, 1990,
                                5, "Egorova P. K.", "W", 1993, 2011,
                                6, "Galikova O. I.", "W", 1972, 1990,
                                7, "Sotnikov T. S.", "M", 1943, 1960,
                                8, "Kamov V. I.", "M", 1979, 2005,
                                9, "Lebedev A. A.", "M", 1959, 1981,
                                10, "Dimova V. V.", "W", 1991, 2010};

    int n = sizeof(data_array) / sizeof(data_array[0]);
    for (int i = 0; i < n; i++)
        printf("%-6d%-20s%-s%8d%8d \n", data_array[i].num, data_array[i].fio,
               data_array[i].gender, data_array[i].gr, data_array[i].gpnr);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 9; j++)
            if (strcmp(data_array[j].fio, data_array[j + 1].fio) > 0)
            {
                tmp = data_array[j];
                data_array[j] = data_array[j + 1];
                data_array[j + 1] = tmp;
            }

    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%-6d%-20s%-s%8d%8d \n", data_array[i].num, data_array[i].fio,
               data_array[i].gender, data_array[i].gr, data_array[i].gpnr);
}