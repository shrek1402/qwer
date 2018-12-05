#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{

	int i, j=0, gr_left=0, gr_right=0, g_1, g_2,m=0;
	int k = 0, k_max=0;
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
	printf("Bolshe vsego t: ");
	for (m = g_1; m < g_2; m++)
		if (st[m] != ' ')
			printf("%c", st[m]);
	printf("\n");
	system("PAUSE");
	return(0);
}
