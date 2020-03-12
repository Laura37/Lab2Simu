
/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc e2.c -o e2
Fecha: Wed 11 Mar 2020 05:49:02 PM CST
Librerias: stdio
Resumen: Muestra los números primos que se encuentran en un rango de números.
Entrada: Límite superior y límite inferior del rango.
Salida:  Números primos del rango ingresado.
*/



//incluir las librerias.
#include <stdio.h>

void main(void) //Se crea la función principal.
{
	int N1, N2; //Se definen las dos variables que ingresará la persona.
	printf("Se determinarán los números primos en un rango de números enteros. Ingrese el límite inferior\n"); //Se le pide a la persona que ingrese el límite inferior.
	scanf("%d", &N1); //Lo lee y lo almacena en la variable N1. Si no es un entero entonces no funcionaría.
	printf("Ingrese el límite superior\n"); //Se le pide a la persona que ingrese el límite superior.
	scanf("%d", &N2); //Lo lee y lo almacena como N2.

	while(N1<=N2) /*Comienza el while mientras N1 sea menor que N2, así cuando N1=N2 termina el rango. En el caso de que N1 sea mayor que N2
	es decir, que el límite inferior sea mayor que el superior, el programa no hará nada y se terminará.*/
	{
		int i=2,primo=1; /*Se definen las variables de esta forma para comenzar el while que determina si un número es primo.
		Se asume que es primo o sea primo=1 hasta que encuentra un número que hace que primo=0. */
		if(N1<0 || N1==0 || N1==1) //Pero si N1 toma estos valores entonces no es primo y primo=0.
			primo=0;
		while(i<N1 && primo==1) /*Este es el while que determina si el número actual del rango es primo o no. Si N=2 entonces 
		no hay problema porque antes se definió el primo=1*/
		{
			if(N1%i==0) /*Si no tiene residuo entonces es primo, ya que para que sea primo debe ser divisible entre otro número
			que no sea 1 o él mismo, por la misma razón se inicia con i=2.*/
				primo=0; //Entonces se hace primo=0 si la condición anterior se cumple y termina el while.
			i++; /*Como la variable es un entero entonces se le aumenta 1 a "i" para pasar al siguiente número del contador "i" que se 
		encuentra en el rango (i=2,i=N-1).*/
		}
		if(primo==1) //Luego de que termina el while anterior se evalua si el resultado es primo=1, es decir que sea primo.
		printf("%d \n",N1); //Si esto se cumple entonces imprime ese número, ya que el programa busca imprimir los números primos de un rango.
		N1++; //Esto le suma 1 a N1 para continuar al siguiente número del rango establecido por la persona.
	}
}