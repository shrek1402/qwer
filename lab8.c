#include <stdio.h>
#include <string.h>
#include <conio.h>

main()
{

    int i, j, gr_left, gr_right, g_1, g_2;
    int k = 0, k_max;
    char st[100];

    printf("Vvedite sctroky: ");
    gets(st);

    printf("Stroka: %s\n", st);
    for (i = gr_right; i <= strlen(st); i++)
        if (st[i] == ' ' || st[i] == '\0')
        {
            k = 0;
            gr_left = gr_right;
            gr_right = i;

            for (j = gr_left; j < gr_right; j++)
                if (st[j] == 't' || st[j] == 'T')
                    k++;
            if (k > k_max)
            {
                k_max = k;
                g_1 = gr_left;
                g_2 = gr_right;
            }
        }
    for (i = g_1 + 1; i < g_2; i++)
        printf("%c", st[i]);
}