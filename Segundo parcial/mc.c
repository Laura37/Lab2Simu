
/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008
Compilado: gcc mc.c -o mc
Fecha: Sun 26 Apr 2020 08:44:08 AM CST
Librerias: stdio.h, stdlib.h, math.h.
Resumen: realiza el ajuste de mínimos cuadrados a un archivo de texto con los datos de dos variables.
Entrada: Nada
Salida:  valores de m, b para f(x)=mx+b, el coeficiente de correlación "r", f(2024) y la gráfica de f(x) vs los datos.
*/

//Se incluyen las librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Para calcular los coeficientes se necesitan 5 sumatorias de las cuales se harán de forma separada.
//Comenzando por la sumatoria de xiyi:
void main(void)
{
	/*Primero se declaran las variables, dado que el método de mínimos cuadrados requiere el cálculo de múltiples sumatorias
	vamos a calcular las 5 principales que se repiten.*/

	//n será el número de coordenadas y por eso es un entero.
	int n=10;

	/*Acá se definen las cinco sumatorias, "xy" será la sumatoria de x*y, "x" será la sumatoria de x, "y" será la sumatoria de y
	"x_2" será la sumatoria de x**2 y "y_2" será la sumatoria de y**2. Todas se inicializan en cero, ya que se hará la sumatoria
	con un for y el primer valor sumado debe ser cero.*/
	int xy=0;
	int x=0;
	int y=0;
	int x_2=0;
	int y_2=0;

	/*i será el contador para el for, "a" y "b" serán nuestras variables dependientes e independientes de nuestro archivo de datos, "a"
	será el año y "b" será el crecimiento de la población.*/
	int i;
	int a, b;

	/*_________________________________________________________________________________________________________________________________
	___________________________________________________________________________________________________________________________________
	_________________________________________________________________________________________________________________________________*/

	//Ahora se leerá el archivo con los datos.
	//El archivo con los datos se llama crecimiento y deberá estar en la misma carpeta que el ejecutable de este código

	//Se abre el archivo y se coloca "r" para leerlo
	FILE * flujo = fopen("crecimiento","rt");

	/*Ahora se inicia el for para hacer todas las sumatorias que se van a necesitar utilizando los datos de el archivo*/
	for(i=1;i<=n;i++)
	{	
		/*"a" y "b" serán las columnas del archivo, separadas por un "tab" y ambas columnas contienen datos enteros.
		Entonces el for irá escaneándo fila por fila hasta llegar a "n" datos.*/	
		fscanf(flujo,"%d%d", &a, &b);
		xy+=a*b; //Por eso aquí la sumatoria "xy" es igual a "xy" + a*b. ya que a=x y b=y en los datos del archivo.
		x+=a; //De igual manera con el resto de las 5 sumatorias.
		y+=b;
		x_2+=a*a;
		y_2+=b*b;
	}


	/*_________________________________________________________________________________________________________________________________
	___________________________________________________________________________________________________________________________________
	_________________________________________________________________________________________________________________________________*/

	/*Ahora se crean las variables que serán calculadas, para la funcion f(x) = m*x + bi. m es la pentiente y bi el intercepto
	r es el coeficiente de correlación lineal. Dado que no hay error en la medicion de x, no hay error en éstas.*/
	float m;
	float bi;
	double r;

	/*A continuación se calculan utilizando las sumatorias calculadas anterior mente. El valor de r se define como un double porque
	lleva el cálculo de una raíz cuadrada, su argumento debe ser double al igual que el resultado.*/
	m= (n*xy - x*y)/(n*x_2 - x*x);
	bi= (y-m*x)/n;
	r= (n*xy - x*y)/sqrt(((double)n*(double)x_2 - (double)x*(double)x)*((double)n*(double)y_2 - (double)y*(double)y));


	//Se muestran en consolo el resultado de los cánculos.
	printf(" m: %.2f\n b: %.2f\n r: %.4f\n", m,bi,r);

	//Se crea la función "estima" el cual calcula el valor de f(x) dado x. 
	float estima(int A)
	{
		y = m*A + bi;
		return y;
	}

	//Luego se muestra en consola que se estima que en x=2024 hayan estima(2024) mil habitantes. 
	printf("Dentro de 5 años; en el 2024, se entima que los habitantes sean %.0f mil.\n", estima(2024) );



	/*_________________________________________________________________________________________________________________________________
	___________________________________________________________________________________________________________________________________
	_________________________________________________________________________________________________________________________________*/



	//Se creará el archivo script, el cual tendrá los comandos a correr en Gnuplot. Primero se abre y se crea el archivo "script"
	FILE *g = fopen("script","wt");
	//Se específican los rangos:
	fprintf(g, "set xrange [2009:2020]\n");
	fprintf(g, "set yrange [150:270]\n");
	//Se define la función con los valores que calcula este código
	fprintf(g, "f(x)= %.2f*x %.2f\n",m,bi); 
	//Se grafica la función junto con el archivo con los datos.
	fprintf(g, "plot 'crecimiento', f(x)\n");
	//Se cierra el archivo.
	fclose(g);

	//Esto ejecutará el comando entre comillas en la consola por lo tanto gnuplot ejecutará el script (:
	system("gnuplot -p script");
} 







