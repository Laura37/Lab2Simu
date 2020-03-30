
/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008.
Compilado: gcc l2.c -o l2
Fecha: Wed 21 Mar 2020 10:45:16 PM CST.
Librerias: stdio.
Resumen: Ordena de forma ascendente un vector ingresado.
Entrada: Vector de 5 números enteros.
Salida:  El vector ordenado de forma ascendente.
*/

#include <stdio.h> //se incluyen las librerias. Esta para preguntar mediante la terminal al usuario y leer.
#include <ctype.h> //Para saber si es un caracter o un número en este caso.

void main(void)
{
	int a, b, c, d, e; //estas variables adquieren el valor que ingresa la persona.
	int n = 5;
	printf("ingrese 5 números enteros\n"); //Esto pide los números.
	scanf("%d",&a);
	scanf("%d",&b);//Y estos lo leen.
	scanf("%d",&c);
	scanf("%d",&d);
	scanf("%d",&e);
	int reales[] = {a,b,c,d,e}; //Así se crea el vector con los valores que la persona ingresó.


	   void quicksort(int a[], int primero, int ultimo) //Esta es la función de el ordenamiento quicksort.
    {
        int i, j, central; //Se crean las variables i (grupo derecho), j (grupo izquierdo) y central que será la posición de enmedio del vector.
        int pivote;
        central = (primero + ultimo)/2; //Así se obtiene el valor de la posición que esta aproximadamente en medio.
        pivote = a[central]; //El pivote sera el número que está en la posición central.
        i = primero; //Este es el el primer valor del vector
        j = ultimo; //Este es el segundo valor del vector
        do { //Ahora se hará lo siguiente:
            while (a[i] < pivote) i++; //Cuando algún número del vector es menor que que el central, el contador incrementa uno. 
            while (a[j] > pivote) j--; //Cuando algún valor del vector sea mayor que el pivote, el contador decrece por 1.
            if (i <= j) // si i es menor o igual que j.
            {
                int temporal;
                temporal = a[i]; //Esto intercambia a[i] con a[j].
                a[i] = a[j];
                a[j] = temporal;
                i++; //Y se hace la misma condición.
                j--;
            }
        }while (i <= j); //Y esto continua mientras i sea menor o igual que j.

        if (primero < j) //Si el primero es menor que la sublista derecha, la menor al pivote. Hace el mismo proceso con la sublista izquierda.
            quicksort(a, primero, j);
        if (i < ultimo) //Si el grupo derecho es mejor al último valor. Hace el mismo proceso con la sublista derecha.
            quicksort(a, i, ultimo); //hace el mismo proceso pero 
    }

        if(isalpha(a) || isalpha(b) || isalpha(c) || isalpha(d) || isalpha(e))
            printf("Mal!, esa es una letra, no un número entero.\n"); //Esto es por si la persona ingresa una letra en lugar de un número.
        else
        {
            printf("Los números ingresados ordenados de forma ascendente:\n");
            quicksort(reales,0,4); //Se hace el método de ordenamiento para el vector reales 
            for (int i = 0; i < n; i++)
            {
                printf("%d ",reales[i]); //Y con un for se va imprimiendo cada valor de ese nuevo vector ordenado.
            }
            puts("\nFIN");
        }
    
}
