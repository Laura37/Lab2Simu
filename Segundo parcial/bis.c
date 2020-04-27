/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc bis.c -o bis
Sun 26 Apr 2020 08:46:43 AM CST
Librerias: stdio.h, math.h, stdlib.h.
Resumen: cálcula la raíz de una función por el método de bisección y genera una gráfica en gnuplot con la función.
Entrada: Nada
Salida:  La raíz aproximada y la gráfica de la función.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Se definen los prototipos.
double f(double x);
double pi(double a, double b);
double redo(double a, int b);
double error(double p, double p_);


/*_________________________________________________________________________________________________________________________________
___________________________________________________________________________________________________________________________________
_________________________________________________________________________________________________________________________________*/

//Se inicia la función principal
void main(void)
{
	/*Se definen las variabless del problema. "a" y "b" serán los extremos iniciales de nuestro intervalo. Dado que la función es 
	asintótica cerca del cero se eligió un intervalo bastante pequeño, de 0.02 de diferencia. Esto luego de haber visto la gráfica
	a una escala mayor. Y se espera que la raíz se encuentre en ese intervalo. "p" será el valor del punto medio y "e" será el error
	o la tolerancia. El error se inicia en 1 para asumir que al inicio el error es del 100%.
	en ese intervalo. Son double para mayor precisión*/
	double a=0.63, b=0.65;
	double p;
	double e=1;


/*_________________________________________________________________________________________________________________________________
___________________________________________________________________________________________________________________________________
_________________________________________________________________________________________________________________________________*/

	/*Se comienza con un while, es decir: el código calculará el valor de p hasta que la condición del while deje de cumplirse 
	decidí que lo hará hasta que el error sea del 0.1%, ya que al elegir que sea del 1% no es tan preciso, ya que la función es 
	asintótica la distancia entre cada p es muy pequeña en ese intervalo.*/
	while(redo(e,4)!=0.001) //"redo()" es la función que creé que aproxima redondea a cierto número de cifras, en este caso 4.
	{
		/*Ahora este es el método de bisección, se calcula p en el intervalo [a,b]. "pi()" es la función que calcula p, y se van 
		evaluando las distintas condiciones. "f()" es la función que se está trabajando para encontrar su raíz.*/
		p=pi(a,b);
		if(f(a)*f(b)>0)
		{
			/*Para esta conición primero se evalua el error el cual se calcula con "error()" que es la función creada en este programa
			el cual evalua el "p" anterior menos el "p" acutal. Y dada esta condición el "p" actual es cambiar "a" por "p". Luego de calcular
			el error, se cambia el valor de "a" por "p" para el siguiente calculo que hará la función while.*/
			e = error(pi(p,b),pi(a,b));
			a=p;	
		}
		else if(f(a)*f(b)<0)
		{
			/*Para esta conición primero se evalua el error el cual se calcula con "error()" que es la función creada en este programa
			el cual evalua el "p" anterior menos el "p" acutal. Y dada esta condición el "p" actual es cambiar "b" por "p". Luego de calcular
			el error, se cambia el valor de "b" por "p" para el siguiente calculo que hará la función while.*/
			e = error(pi(a,p),pi(a,b));
			b=p;
		}
		else if(redo(f(a)*f(b),3)==0.00)
		{
			/*En en caso de que "f(a)*f(b)" sea aproximadamente igual a cero signifa que hemos encontrado la raíz, por lo tanto se define 
			a "e=0" para que termine el programa y se salga del while. Se hace el redondeo a que sea redondeado a tres cifras significativas
			y que ese redondeo sea igual a "0.00" Si esta condición nunca se cumple, entonces el while terminará cuando
			el error sea del 0.1%. Y pues, dado que esta raíz entonces p es la raíz.*/
			p=p;
			e = 0;
		}
	}

	/*Luego de que termina el while quiere decir que se tiene un valor aproximado a la raíz, por lo que se imprime este valor en consola
	con 5 cifras decimales*/
	printf("%.5f\n", p);


/*_________________________________________________________________________________________________________________________________
___________________________________________________________________________________________________________________________________
_________________________________________________________________________________________________________________________________*/



	/*Ahora los comandos para generar la gráfica de f(x) y ver su comportamiento. Se creará el archivo script, el cual tendrá los 
	comandos a correr en Gnuplot. Primero se abre y se crea el archivo "script1"*/
	FILE *g = fopen("script1","wt");
	//Se específican los rangos: Muy pequeños ya que por ser asintótica se desea hacer un gran zoom a la función.
	fprintf(g, "set xrange [0.6:0.68]\n"); 
	fprintf(g, "set yrange [-0.05:0.05]\n");
	//Se define la función con los valores que calcula este código
	fprintf(g, "f(x)= x - 2**(-x)\n"); 
	fprintf(g, "set grid\n"); //Esto es para ver cuándo para por cero.
	//Se grafica la función.
	fprintf(g, "plot f(x)\n");
	//Se cierra el archivo.
	fclose(g);

	//Esto ejecutará el comando entre comillas en la consola por lo tanto gnuplot ejecutará el script (:
	system("gnuplot -p script1");


/*_________________________________________________________________________________________________________________________________
___________________________________________________________________________________________________________________________________
_________________________________________________________________________________________________________________________________*/

	//Ahora luego de mostrar la gráfica, se muestra la comparación de la gráfica con el valor obtenido
	printf("La gráfica está a una escala muy pequeña pero si se cambia el rango de la gráfica se podría observar su comportamiento asintótico, es por ello que se eligió ese rango para comenzar a trabajar. Se observa que el valor obternido '%.5f' se encuentra cercano al valor de cero. Y que se trabaja con números muy pequeños por lo que se eligió que el error debe ser del 0.1 porciento. La escala a la cual se encuentra la gráfica muestra que en el eje de x los valores aumentan por 0.01, y en el eje y por 0.02. Así que la distancia entre el valor encontrado y el valor real es del orden de 10E-3. Así que es un valor muy cercano de la raíz real que podría diferir en 0.001. Si se desea una raíz más acercada a la real el intervalo inicial debe ser aún más pequeño y el error aún más pequeño ya que la función es asintótica. Pero mi máquina no tiene el poder computacional necesario para hacerlo rápido. Por lo tanto esta es una buena aproximación.\n", p);
}



/*_________________________________________________________________________________________________________________________________
___________________________________________________________________________________________________________________________________
_________________________________________________________________________________________________________________________________*/


//Ahora se definen las funciones (:

/*pi es la función que calcula el punto medio entre "a" y "b", es parte del método de bisección.*/
double pi(double a, double b)
{
	double p;
	p=(a+b)/2;
	return p;
}

/*f es la función con la que se está trabando y de la cual se deben encontrar sus raíces.*/
double f(double x)
{
	double f;
	f = x - pow(2,-x);
	return f;
}


/*Esta función redondea valores, el primer argumento es el valor a redondear y el segundo es el número de
cifras a las que se desea redondear. La parte de la función es un método puramente matemático de redondeo*/
double redo(double a, int b)
{
	return ((float)((int)(a * pow(10, b) + 0.5))) / pow(10, b);
}


/*Y esta función calcula el error entre cada punto medio calculado. "p" es el actual y "p_" es el anterior
esto es parte del método de bisección.*/
double error(double p, double p_)
{
	double e;
	e= (p-p_)/p;
	return e;
}