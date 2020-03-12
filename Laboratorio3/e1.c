
/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc e1.c -o e1
Fecha: Wed 11 Mar 2020 05:49:02 PM CST
Librerias: stdio
Resumen: Determina si el valor ingresado es primo o no.
Entrada: Número natural N
Salida:  es primo o no es primo.
*/




//incluir librerias.
#include <stdio.h>

//Se creará la función principal.

void main(void)
{
	/*Declarar las varibales, "N" será el valor que ingresa la persona, "i" es el contador y comienza desde dos, 
	ya que si comenzara desde uno, todos los números divididos entre uno no tienen residuo, y lo que se quiere determinar es si el número
	ingresado "N" no tiene un residuo al dividirse dentro de otro número que no sea 1 ó "N", lo cual indicaría que no es primo. La variable
	"primo" indica si el número es primo o no. Cuando "primo"=0 entonces no es primo, cuando "primo"=1 entonces sí es primo y cuando 
	"primo"=3 ó "primo"=4 entonces no es ni primo ni compuesto.*/


	int N,i=2,primo=1; //Se inician las variables de esta forma, en el while se explica el porqué
	//Se solicita que ingrese el valor
	printf("Se determinará si el valor ingresado es primo, ingrese N:\t"); //Este es el mensaje que se muestra a la persona \t es de "tab"
	scanf("%d",&N); /*Ya que lee el valor ingresado como entero, entonces si la persona ingresa otro tipo de variable, el programa termina
	y no hace nada, */
	if(N==1 || N==0) //Esto es debido a que uno y cero no son ni primos ni compuestos.
		primo=3;
	if(N==2)
		primo=1; //Se mantiene igual, esta línea no es necesaria pero igual la dejo.
	if(N<0) //Esta condición es porque los números negativos no forman parte de los naturales, por lo tanto no son ni primos ni compuestos.
		primo=4;

	while(i<N && primo==1) /*La condición del while es de que el contador sea menor que N, así usará los números desde i=2 hasta i=N-1.
	De esta manera no va a hacer la división dentro de 1, ni tampoco dentro de N, ya que estos siempre dan residuo cero. La otra condición
	establece que el número que está ingresando es primo, ya que si no lo fuera no tendría sentido seguir probando con los demás numeros 
	porque con que tenga un divisor distinto de 1 y de él mismo ya no es primo. Por lo tanto, si "i" llega a "N-1" o si "primo"=(0,3,4) el while 
	termina ya que no vuelve a empezar.*/
	{
		if(N%i==0) //Esta condición establece que el residuo de "N" dentro de "i" sea cero.
			primo=0; //Si la condición de arriba se cumple entonces la variable "primo"=0, es decir que el número no es primo.
		i++; /*Como la variable es un entero entonces se le aumenta 1 a "i" para pasar al siguiente número del contador "i" que se 
		encuentra en el rango (i=2,i=N-1).*/
	}

	if(primo==0) /*Ahora si el while terminó y "primo"=0 quiere decir que no es un número primo, es decir que tiene otros divisores distindos
	de uno y de él mismo.*/
		printf("El número ingresado '%d', no es primo.\n",N); //La consola imprime esta respuesta.
	if(primo==1) //En el caso que "primo"=1 el número ingresado es primo.
		printf("El número ingresado '%d', sí es primo.\n",N); //La consola imprime esta respuesta.
	if(primo==3)//En el caso que "primo"=3 el número ingresado no es primo ni compuesto.
		printf("El número ingresado '%d', no es ni primo ni compuesto. El uno y el cero, por convenio, no se consideran ni primos ni compuestos.\n",N);
	if(primo==4)//En el caso que "primo"=4 el número ingresado no es primo ni compuesto.
		printf("El número ingresado '%d' no es ni primo ni compuesto, ya que no forma parte del conjunto de los números naturales.\n",N);
		
}
