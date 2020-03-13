#include <stdio.h>

void main(void)
{
	int N, i=0;
	double ant=0, act=1;
	printf("Se mostrarán N terminos de la secuencia de Fibonacchi, ingrese N:\t");
	scanf("%d",&N);
	printf("%.0lf\n",1.0);
	while(i<N-1)
	{
		act+=ant;
		ant=act-ant;
		printf("%.0lf \n",act);
		i++;
	}

}
