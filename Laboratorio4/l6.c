/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008.
Compilado: gcc l6.c -o l6 -lm
Fecha: Wed 25 Mar 2020 10:49:21 PM CST.
Librerias: stdio.h, math.h.
Resumen: Calcula 4 sumatorias donde el límite de la sumatoria es n.
Entrada: límite de la sumatoria n.
Salida:  Resultado numérico de las 4 sumatorias.
*/

#include<stdio.h> //Se incluyen las librerias, math.h debido a que se utilizará raíz cuadrada y potencia.
#include<math.h>

void main(void)
{
	int i; //Este será el índice para los ciclos de cada for
	float n; //Este será el valor que ingresa la persona, es decir el límite de la sumatoria.
	int s_a=0; //s_a es la sumatoria del inciso a, y se comienza definiéndola como cero porque será el primer término que se suma.
	double s_b=0, s_c=0, s_d=0; //Lo mismo de arriba para s_b, s_c y s_d.
	printf("Ingrese el límite superios de las sumatorias.\n");
	scanf("%f",&n);

	for(i=1;i<=n;i++) //El primer ciclo for es para hacer la sumatoria hasta que i<=n.
	{
		s_a= s_a + i*i*(i-3); //Por esta razón es que se hace el s_a igual a cero en el inicio, para que el primer término de la sumatoria no afecte.
	}
	printf("La sumatoria 'a' es igual a %d\n", s_a);

	for(i=2;i<=n;i++) //El igual para el inciso b sólo que la sumatoria empieza desde dos ya que en i=1 no está definido.
	{
		s_b= s_b + 3/(i-1);
	}
	printf("La sumatoria 'b' es igual a %.2f\n", s_b); //Esto imprime el resultado final (: o sea, la sumatoria total hasta n.

	for(i=1;i<=n;i++) //En este for se utilizan las funciones de raíz cuadrada y de potencia de la biblioteca de math.h
	{
		s_c= s_c + (1/sqrt(5))*pow(((1+sqrt(5))/2),i) - (1/sqrt(5))*pow(((1-sqrt(5))/2),i);
	}
	printf("La sumatoria 'c' es igual a %.2f\n", s_c);

	for(i=1;i<=n;i++) //Y de igual manera se hace la última sumatoria.
	{
		s_d= s_d + 0.1*(3*pow(2,(i-2))+4); //Lo que va cambiando es las operaciones dentro de cada sumatoria.
	}
	printf("La sumatoria 'd' es igual a %.2f\n", s_d);

}