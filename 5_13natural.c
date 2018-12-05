#include <stdlib.h>
#include <time.h>



int main()
{
srand(time(NULL));
int i,j,m,n,k=0,s=0,b=0;
scanf("%d", &n);
int A[n], B[n];
for (i=0; i<n;i++)
A[i] = rand()%10;

for (i=0; i<n;i++)
printf("%d  ", A[i]);

for (s=0,i=0; i<n-1; i++)
if (A[i]==A[i+1])// если соседние одинаковые
	{
	for (k=2; i+k<n && A[i]==A[i+k]; k++);
	
	if (k>s) s=k,b=i;// в к хранится кол-во подряд идущих в данной итерации, в S их максимальное число b- номер начала повторяющихся
	}

printf("\n");
for (i=0; i<n;i++)
printf("%d  ", A[i]);
printf("%d %d %d", s, k, b);

}
