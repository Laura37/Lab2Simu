
/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008.
Compilado: gcc l1.c -o l1
Fecha: Wed 20 Mar 2020 01:55:03 PM .
Librerias: stdio.
Resumen: escribe los números pares de 2 a 20 de forma descendente o ascendente dependiendo de cómo quiera el usuario.
Entrada: si lo quiere ver descendente o ascendente.
Salida:  vector de forma ascendente o descentente.
*/


#include <stdio.h> //se incluyen las librerias. Esta para preguntar mediante la terminal al usuario y leer.


void main(void)
{
	int pares[] = {2,4,6,8,10,12,14,16,18,20}; //Se define el vector que vamor a ordenar.
	char o; //Esta será la opción que ingresará la persona.
	puts("Se mostrarán los números pares en el rango de dos a 20. Ingrese la letra de la opción de cómo quiere que sean mostrados los elementos\n a) Verlos de forma ascendente\n d) Verlos de forma descendente\n");
	//Puts imprime en la terminal y lo lee.


	while (o = getchar()) //iniciamos un while cuya condición es que la entrada "o" sea un caracter. La función getchar devuelve el siguiente carácter en el buffer del teclado, así no toma en cuenta el enter anterior.
	{
		if(o=='a' || o=='d') //Si dicha entrada es "a" o "d", se sale del while ya que son las opciones que se tienen.
		{
			break;
		}
		while ((o=getchar()) != '\n'); /*Esta es la misma condición del while exterior pero además indica que "o" no es igual a "enter"
		Ya que al ingresar un caracter es un buffer no tome este en cuenta.*/
        puts("Se ingresó una opción no válida, recuerde que las opciones válidas son 'a' o 'b'. De nuevo: se mostrarán los números pares en el rango de dos a 20. Ingrese la letra de la opción de cómo quiere que sean mostrados los elementos: \n a) Verlos de forma ascendente\n d) Verlos de forma descendente\n");
		//Y esto es lo que imprime al ingresar mal un caracter, es decir que no sea ni "a" ni "d".
	}



//Ahora vienen las condiciones para cumplir lo que la persona ingresó.

	if(o=='d') //Aquí quería probar las dos formas que se me ocurrieron para mostrar el vector, imprimiendo cada uno, o con un for.
	{
		printf("\n"); //Esto es sólo para que se vea mejor visualmente.
		for(int i=9;i>=0;i--) //Cuando es "d" es decir descendente i comienza desde la posición 9 y continúa así hasta cero, y va decreciendo por 1.
		{
			printf("%d\n", pares[i]);
		}
	}
		if(o=='a') //Esta es la segunda condición, que lo muestre de fomra ascendente.
	{
		printf("\n");
		for(int i=0;i<10;i++) //Cuando es "a" es decir ascendente i comienza desde la posición 0 y continúa así hasta 9, y va incrementando por 1.
		{
  			printf("%d\n", pares[i]);
		}
	}
}
