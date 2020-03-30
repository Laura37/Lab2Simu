
/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008.
Compilado: gcc l3.c -o l3 -lm
Fecha: Wed 22 Mar 2020 11:49:21 PM CST.
Librerias: stdio.h, math.h.
Resumen: Determina la magnitud de dos vectores, la suma, el producto punto y el producto vectorial entre los dos vectores.
Entrada: Coordenadas de dos vectores.
Salida:  Magnitud, suma, producto escalar y producto vectorial.
*/

#include <stdio.h> //se incluyen las librerias. Esta para preguntar mediante la terminal al usuario y leer.

#include <math.h> //Esta para sacar la raiz cuadrada de un número


int main(void)
{

int a, b, c, o, p, q; //Estas variables serán ocupadas por los valores que ingrese la persona.
printf("Ingrese las coordenadas de un vector A: x1, x2, x3 separadas por un enter\n"); //Se ingresan las coordenadas una por una.
scanf("%d",&a);
scanf("%d",&b);
scanf("%d",&c);
int A[] = {a,b,c}; //Se crea el vector de las primeras coordenadas.
printf("Ingrese las coordenadas de un segundo vector B: y1, y2, y3 separadas por un enter\n");
scanf("%d",&o);
scanf("%d",&p);
scanf("%d",&q);
int B[] = {o,p,q}; //Se crea el vector de las segundas coordenadas.


void magnitud(int a[]) //Se crea la función que calcula la magnitud.
{
	double k; //para la función sqrt() o sea, raiz cuadrada el módulo debe ser un double.
	k = a[0]*a[0] + a[1]*a[1] + a[2]*a[2]; //Esto es por definición.
	printf("%f\n",sqrt(k)); //E imprime la raiz cuadrada de dicha expresión.
}

void suma(int a[], int b[]) //Se crea la función que calcula la suma de los dos vectores.
{
	int i= a[0] + b[0]; //Se va calculando la suma de cada componente, y luego con un for se imprimen todas las componentes.
	int j= a[1] + b[1];
	int k= a[2] + b[2];
	int s[] = {i, j, k};
	for(i=0;i<3;i++)
	{
		printf("%d\t", s[i]);
	}
}

void pescalar(int a[], int b[]) //Se crea la función que calcula el producto punto entre los dos vectores.
{
	int i= a[0]*b[0]; //De igual forma esto es por definición.
	int j= a[1]*b[1];
	int k= a[2]*b[2];
	int pe = i + j + k;
	printf("%d\n",pe );
}

void pvectorial(int a[], int b[]) //Se crea la función que calcula el producto vectorial entre los dos vectores.
{
	int i= a[1]*b[2] - a[2]*b[1]; //Con este se van calculando cada una de las componentes por separado.
	int j= a[2]*b[0] - a[0]*b[2];
	int k= a[0]*b[1] - a[1]*b[0];
	int pv[] = {i,j,k};
	for(i=0;i<3;i++) //Y con un for se imprimen como un vector.
	{
		printf("%d\t", pv[i]);
	}
}
	//magnitud de cada vector
	printf("a) La magnitud del vector A es:\n"); //Luego se pone el título de lo que se va a mostrar.
	magnitud(A); //Y se hace empleo de la función respectiva con el vector respectivo.
	printf("a) La magnitud del vector B es:\n");
	magnitud(B);
	printf("\nb) La suma de los dos vectores es A+B = B+A =\n");
	suma(A,B);
	printf("\nc) El producto escalar entre los dos vectores es: A.B = B.A =\n");
	pescalar(A,B);
	printf("\nd) El producto vectorial entre los dos vectores: AxB =\n");
	pvectorial(A,B);
	printf("\nd) El producto vectorial entre los dos vectores: BxA =\n");
	pvectorial(B,A);
	printf("\n");
	printf("FIN\n"); //Con esto se finaliza el texto mostrado.

return(0);

}





