/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008.
Compilado: gcc l5.c -o l5
Fecha: Wed 23 Mar 2020 12:30:21 PM CST.
Librerias: stdio.h.
Resumen: Determina el factorial de un número natural.
Entrada: número entero.
Salida:  El factorial de ese número.
*/

#include<stdio.h> //Se incluyen las librerias.

int factorial(int i); //Se declara la función factorial.

void main(void) //La función principal para calcular el factorial de un número.
{
	int n;
	printf("Ingrese un número y se calculará su factorial.\n"); //Se le pide a la persona que ingrese ese número.
	scanf("%d",&n);

	if(n<0)
		printf("Este programa calcula factoriales de enteros positivos.\n"); //Si n es menor que cero mostrar este mensaje, ya que no existe factorial para números negativos.
	if(n>=0) //Ahora si n es mayor o igual a cero sí calculará el factorial.
	{
		printf("el factorial de %d es %d.\n", n, factorial(n)); //Esto imprime el cálculo del factorial.
	}
}

int factorial(int i) //ahora definimos cómo funciona la función factorial.
{
	if(i==0 || i<0) //Si n=0 entonces el factorial de 0 es 1. Pero ¿porque incluímos la opción de que i<0 si ya dijimos que no sirve para números negativos? explicación en el comentario de abajo.
		return 1;
	else
		return i*factorial(i-1); 
	/*/La razón de lo anterior es porque en algún momento aquí habría en (i-1) un número negativo, por lo que se hace que factorial(i<0)
	sea uno, para que a partir de que (i-1) en "i*factorial(i-1)" el término "factorial(i-1)" vaya dando uno, así que cuando eso
	comienza a tomar valores negativos -o cero- no importa porque lo multiplicará por uno sin alterar el valor deseado que es hasta i=1.*/ 
}