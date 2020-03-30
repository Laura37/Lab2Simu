/*
Autor: Laura Portillo (:
Compilador: gcc (Ubuntu 9.2.1-9ubuntu2) 9.2.1 20191008.
Compilado: gcc l4.c -o l4 -lm
Fecha: Sat 28 Mar 2020 08:17:07 PM CST.
Librerias: stdio.h, math.h.
Resumen: este código calcula ciertas operaciones entre matrices 
		como suma, resta, multiplicación por una constante,
		inversa de una matriz, transpuesta de una matriz, reducción
		de Gauss, reducción de Gauss-Jordan y determinante de una matriz.
Entrada: una constante y los elementos de dos matrices de 3x3.
Salida:  matriz por constante, suma y resta de matrices, multiplicación
		de matrices, determinante de matriz, transpuesta de matriz, 
		inversa de matriz, reducción de Gauss y Gauss-Jordan de matriz.
*/


#include<stdio.h> //Se incluyen las librerias.
#include<math.h> //Esta se utilizará para calcular una potencia.

void main(void)
{
	int i, j; //Estos serán los contadores de los for. Los "i" serán para filas y los "j" para columnas.
	float c; //Esta será la constante que ingresa la persona.
	float matA[3][3], matB[3][3]; //matA y matB serán las matrices que ingresa la persona. serán de 3x3. Es un arreglo de dos dimensiones

	printf("Ingrese una constante 'c'.\n"); //Aquí se le pide a la persona que ingrese una constante.
	scanf("%f",&c); //Y esto lee dicha constante y la almacena.
 
 
	printf("Ingrese los elementos de la primera matriz matA.\n"); //Ahora se ingresarán los elementos de la matriz uno por uno con un for.
 
	for (i = 0; i < 3; i++)
    	for (j = 0; j < 3; j++) //Como se mencionó antes, "i" es para las filas y "j" para las columnas.
        {
      		printf("Ingrese el valor para el elemento matA[%d][%d]:", i, j); //Y con esto va indicando cada posición de la matriz.
         	scanf("%f", &matA[i][j]); //Y lo va almacenando en cada espacio de el arreglo de dos dimensiones.
        }
 
	printf("Ingrese los elementos de la segunda matriz matB.\n"); //De igual forma se hace para la siguiente matriz matB.
 
	for (i = 0; i < 3; i++)
    {
		for (j = 0 ; j < 3; j++)
        {
      		printf("Ingrese el valor para el elemento matB[%d][%d]:", i, j);
        	scanf("%f", &matB[i][j]);
        }
    }


// Ahora se le mostrarán al usuario las matrices ingresadas:

printf("\n");
printf("La matriz matA ingresada es:\n"); 
for (i = 0; i < 3; i++) //Esto imprime cada uno de los componentes de cada matriz
	{
		for (j = 0 ; j < 3; j++)
      	{
			printf("%.0f\t", matA[i][j]); // el signo /t es de "tab" para que cada columna esté separada por un espacio.
      	}
		printf("\n"); //Este enter es para que cada fila esté separada por un enter y así se pueda mostrar al usuario como matriz cuadrada.
	}

printf("\n");
printf("La matriz matB ingresada es:\n"); //De igual manera se muestra al usuario la matriz matB ingresada.
for (i = 0; i < 3; i++)
	{
		for (j = 0 ; j < 3; j++)
      	{
			printf("%.0f\t", matB[i][j]);
      	}
		printf("\n");
	}

printf("\n");
printf("El valor de la constante 'c' ingresado es: %.0f\n", c);

/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/


//Multiplicación por escalar.

	printf("\n");
	printf("c*matA:\n");
	float cons[3][3]; //Esta será la matriz resultante luego de haber multiplicado la matriz matA por una constante.
	for (i = 0; i < 3; i++)
	{
		for (j = 0 ; j < 3; j++)
      	{
         	cons[i][j] = c*matA[i][j]; //Con esto se multiplica cada elemento de la matriz por la constante y se almacena en la nueva matriz.
         	printf("%.0f\t", cons[i][j]);
      	}
		printf("\n");
	}


/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/
   
// Suma y resta de matrices.

	printf("\n");
	printf("matA + matB:\n");
	float sum[3][3]; //Esta será la matriz resultante de haber sumando ambas matrices.
	for (i = 0; i < 3; i++)
	{
		for (j = 0 ; j < 3; j++)
      	{
         	sum[i][j] = matA[i][j] + matB[i][j]; //Con un for se va sumando cada elemento correspondiente al elemento de la otra matriz.
         	printf("%.0f\t", sum[i][j]); //Esto imprime el resultado de la suma.
      	}
		printf("\n");
	}

	printf("\n");
	float res[3][3];
	printf("matA - matB:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0 ; j < 3; j++)
      	{
         	res[i][j] = matA[i][j] - matB[i][j]; //De igual forma con la resta, sólo que ahora cambia el signo de la operación.
         	printf("%.0f\t", res[i][j]); //Esto imprime el resultado de la resta.
      	}
		printf("\n");
	}


/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/



	printf("\n");
	float mul[3][3]; //Esta será la matriz resultante de haber multiplicado las otras dos matrices.
	printf("matA*matB:\n");
   	for (i = 0; i < 3; i++)
	{
		for (j = 0 ; j < 3; j++)
      	{
      		/*Para multiplicar matrices se toma de la matriz izquiera las filas y de la derecha las columnas
      		cada elemto de la fila se va multiplicando por el elemento correspondiente a la columa y luego se
      		suma el resultado de las tres multiplicaciones (ya que es una matriz de 3x3) luego, ese valor se 
      		almacena en la matriz mul en la posición correspondiente a la intersección de la fila y la columna
      		que se estén tomando.*/
         	mul[i][j] = matA[i][0]*matB[0][j] + matA[i][1]*matB[1][j] + matA[i][2]*matB[2][j]; 
         	printf("%.0f\t", mul[i][j]); //Esto imprime la matriz final mul, que es el resultado de la multiplicación.
      	}
		printf("\n"); //Esto es sólo por orden visual (es un enter.)
	}

/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/


//Encontrar el determinante.
	printf("\n");
	float det(float A[3][3]) //Se crea una función que calcule el determinante de cualquier función (nos servirá más adelante.)
	{
		/*Para el determinante de una matriz de 3x3 se utiliza de definición de abajo, consiste en ir calculando
		el determinante de las matrices 2x2 que conforman la matriz al tapar la fila 1 y luego ir tapando la 
		columna 1, 2 ,3. y entre operación se multiplica por el valor que esta tapado por la fila en la columna 
		y se van intercalando los signos.*/
		int det; //det será la variable que ocupe el valor de la determinante de dicha matriz.
		det = A[0][0]*(A[1][1]*A[2][2] - A[1][2]*A[2][1]) - A[0][1]*(A[1][0]*A[2][2]- A[1][2]*A[2][0]) + A[0][2]*(A[1][0]*A[2][1] - A[1][1]*A[2][0]);
	}
	printf("det(matA):%.0f\n",det(matA)); //Esto imprime el valor de determinante de matA. Ya que nombro a la función y de argumento pongo matA.



/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/


//Calculo de la transpuesta de una matriz.


	printf("\n");
	float trans(float B[3][3]) //Se creará la función que calculara la transpuesta de cualquier matriz.
	{
		float trans[3][3]; //Esta será la matriz resultante de haber calculado la transpuesta de una matriz.
   		for (i = 0; i < 3; i++)
		{
			for (j = 0 ; j < 3; j++)
      		{
         		trans[i][j]= B[j][i]; //La transpuesta consiste en intercambiar columnas por filas y se hace de esta manera.
         		printf("%.0f\t", trans[i][j]);
      		}
			printf("\n");
		}
	}
	printf("La matriz transpuesta de matB:\n");
	trans(matB); //Dado que la función transpuesta ya incluye el imprimir a la función resultante sólo es necesario poner la función y su argumento.
	printf("\n");
	

/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/




	//Para encontrar la inversa de la matriz el procedimiento es mucho más largo.

	

	float inv(float C[3][3])
	{
		float M[3][3]; //Esta es la matriz de M que sirve para calcular los cofactores de una matriz.
		float Co[3][3]; //está será la matriz de cofactores.

		/*La matriz de M consiste en calcular el determinante de la matriz correspondiente al trazar 
		líneas donde la intersección es una componente de la matriz a la que se quiere sacar la inversa
		por lo tanto al una componente de la matriz M correspondiente a la matriz a la cual se le desea 
		calcular su inversa. A continuación se calcula cada elemento de la matriz M correspondiente a 
		la matriz C (la matriz a la que se desea encontrar su inversa). La matriz M es necesaria para 
		calcular la matriz de cofactores.*/
		M[0][0] = C[1][1]*C[2][2] - C[1][2]*C[2][1]; 
		M[0][1] = C[1][0]*C[2][2] - C[1][2]*C[2][0];
		M[0][2] = C[1][0]*C[2][1] - C[1][1]*C[2][0];
		M[1][0] = C[0][1]*C[2][2] - C[0][2]*C[2][1];
		M[1][1] = C[0][0]*C[2][2] - C[0][2]*C[2][0];
		M[1][2] = C[0][0]*C[2][1] - C[0][1]*C[2][0];
		M[2][0] = C[0][1]*C[1][2] - C[0][2]*C[1][1];
		M[2][1] = C[0][0]*C[1][2] - C[0][2]*C[1][0];
		M[2][2] = C[0][0]*C[1][1] - C[0][1]*C[1][0];

		/*Ahora se calculará la matriz de cofactores */

		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
				{
					Co[i][j] = pow(-1,i+j)*M[i][j]; //Está es la definición de la matriz de cofactores, utilizando cada elemento de la matriz M.
				}
		}

		//Ahora se calculará el adjunto de la función C (la función a la cual se desea encontrar su inversa).
		float adjC[3][3];
		for (i = 0; i < 3; i++)
		{
			for (j = 0 ; j < 3; j++)
      		{
         		adjC[i][j] = Co[j][i]; //El adjunto de C es la transpuesta de la matriz de cofactores Co.
      		}
		}


		//Ahora sí, por fin se calculará la matriz inversa.

		float invC[3][3]; //Esta matriz será la resultante de calcular la inversa de la matriz C.
		float m = det(C); //Pero primero determinar el determinante de la función.
		float x = 1/m; //Este valor será multiplicado abajo para obtener la inversa.
		for (i = 0; i < 3; i++)
		{
			for (j = 0 ; j < 3; j++)
      		{
         		invC[i][j] = x*adjC[i][j]; //La matriz inversa es el adjunto de C por 1/det(C).
         		printf("%.2f\t", invC[i][j]); //Esto imprime la matriz inversa.
      		}
			printf("\n");
		}
	}

	//Condición importante!!
	if(det(matA)==0) //Si el determinante de la matriz es cero entonces esa matriz NO TIENE INVERSA.
		printf("La matriz matA no tiene inversa ya que su determinante es cero.\n");
	if(det(matA)!=0) //En el caso de que el determinante sea distinto de cero entonces se calcula la inversa haciendo uso de la función definida arriba.
	{
		printf("La inversa de la matriz matA:\n");
		inv(matA); //Como la función ya incluye imprimir la matriz, entonces sólo se nombra la función.
		printf("\n");
	}


/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/


//Ahora la reducción de Gauss de mat A.


	printf("\n");
	printf("La reducción de Gauss de matA:\n");
	float c1, c2, c3; //Estos serán los valores por los que hay que multiplicar una fila para que al restarla o sumarla con otra algún valor sea cero.
	if(det(matA)==0) //El mensaje que imprime el código si este if se cumple explica porqué esta condición toma papel aquí.
	{
		printf("La reducción de Gauss consiste en que los elementos debajo de la diagonal sean iguales a cero. Esto es útil al resolver sistemas de ecuaciones. Ya que el determinante de matA es cero significa que el sistema tiene infinitas soluciones, por lo que no hay manera de formar una matriz donde los elementos de la diagonal sean distintos de cero y que debajo de la diagonal hayan ceros. Por lo tanto no es posible encontrar la reducción de Gauss para la matriz matA.\n");
	}
	else //Ahora viene la parte divertida!!
	{
		/*Para Gauss se desea que las componentes [1][0], [2][0], [2][1] de la matriz seran cero*/
		if(matA[1][0] != 0)  //Entonces si alguna de esas es cero ya está. Vamos a ir por casos, en los casos de que alguna no sea cero.
		{
			if(matA[0][0] == 0) //Pero antes hay que comprobar si la componente [0][0] no es cero, ya que se utilizará para encontrar C1.
			{
				float temporal[3][3]; //Esta será una matriz temporal que ayudará a intercambiar filas(:
				for (int i = 0; i < 3; ++i) //Entonces si la componente [0][0] es cero se intercambia esta fila 1 por la fila dos, y dado el if externo sabemos que ahora la nueva componente [0][0] no es cero.
				{
					temporal[0][i]= matA[0][i]; //Esto es para intercambiar matrices.
					matA[0][i] = matA[1][i];
					matA[1][i] = temporal[0][i];
				}
			}
			else //Si en un principio esa no es cero, entonces no hay que intercambiar ninguna fila y se prosigue a lo siguiente:
			{
				/*Lo que se busca es que el elemento [1][0] sea cero (en eso consite Gauss) entonces se hará lo usual de 
				multiplicar una fila por un número y luego se le restará a la fila donde está el elemento que se desea que sea cero.*/
				c1 = matA[1][0]/matA[0][0];  //Este es el valor por el cual hay que multiplicar la fila para que el elemento [1][0] sea cero.
				for (int i = 0; i < 3; ++i)
				{
				matA[1][i] = matA[1][i] - c1*matA[0][i];   //Finalmente se reemplazza la fila [1] por la fila [1] menos C1 multiplicado por la fila [0].
				}
			}	
		}

		if(matA[2][0] != 0) //Y se sigue el mismo procedimiento para los otros valores que se desean que sean cero.
		{
			if(matA[0][0] == 0)
			{
				float temporal2[3][3];
				for (int i = 0; i < 3; ++i)
				{
					temporal2[0][i]= matA[0][i]; //Esto es para intercambiar matrices.
					matA[0][i] = matA[2][i];
					matA[2][i] = temporal2[0][i];
				}
			}
			else
			{
				c2 = matA[2][0]/matA[0][0];
				for (int i = 0; i < 3; ++i)
				{
				matA[2][i] = matA[2][i] - c2*matA[0][i]; 
				}
			}	
		}

		if(matA[2][1] != 0)
		{
			if(matA[1][1] == 0)
			{
				float temporal3[3][3];
				for (int i = 0; i < 3; ++i)
				{
					temporal3[1][i]= matA[1][i]; //Esto es para intercambiar matrices.
					matA[1][i] = matA[2][i];
					matA[2][i] = temporal3[1][i];
				}
			}
			else
			{
				c3 = matA[2][1]/matA[1][1];
				for (int i = 0; i < 3; ++i)
				{
				matA[2][i] = matA[2][i] - c3*matA[1][i]; 
				}
			}	
		}

		for (i = 0; i < 3; i++)
			{
				for (j = 0 ; j < 3; j++)
      			{
         			printf("%.0f\t", matA[i][j]); //Y por último se imprime la nueva matriz matA, reducida por Gauss. o sea, los elementos bajo la diagonal ahora son cero.
      			}
				printf("\n");
			}
	}
	


/*____________________________________________________________________________________________________________
______________________________________________________________________________________________________________
_____________________________________________________________________________________________________________*/




//Reducción Gauss- Jordan de matB:
/*Para la reducción de Gauss Jordan se hace el mismo proceso que para Gauss DOS VECES
Una vez para hacer ceros los elementos debajo de la diagonal y otra vez para hacer ceros
los elementos arriba de la diagonal, se hace le mismo procedimiento, sólo hay una pequeña
variación para los ceros de arriba de la diagonal, dicha variación se encuentra comentada
más abajo (cuando ocurre la variación).
*/


printf("\n");
	printf("La reducción de Gauss-Jordan de matB:\n");
	float r1, r2, r3; //Estos serán los elemtos por los que hay que multiplicar la matriz.
	if(det(matB)==0) //Si el determinante de matB es cero no calculará la matriz de Gauss-Jordan debido a lo que se explica en el print de abajo.
	{
		printf("La reducción de Gauss-Jordan consiste en que los elementos debajo de la diagonal y arriba de la diagonal sean iguales a cero. Esto es útil al resolver sistemas de ecuaciones. Ya que el determinante de matB es cero significa que el sistema tiene infinitas soluciones, por lo que no hay manera de formar una matriz donde los elementos de la diagonal sean distintos de cero y que debajo de la diagonal y arriba hayan ceros. Por lo tanto no es posible encontrar la reducción de Gauss-Jordan para la matriz matB.\n");
	}
	else
	{
		if(matB[1][0] != 0)
		{
			if(matB[0][0] == 0)
			{
				float rtemporal[3][3];
				for (int i = 0; i < 3; ++i)
				{
					rtemporal[0][i]= matB[0][i]; //Esto es para intercambiar matrices.
					matB[0][i] = matB[1][i];
					matB[1][i] = rtemporal[0][i];
				}
			}
			else
			{
				r1 = matB[1][0]/matB[0][0];
				for (int i = 0; i < 3; ++i)
				{
				matB[1][i] = matB[1][i] - r1*matB[0][i]; 
				}
			}	
		}

		if(matB[2][0] != 0)
		{
			if(matB[0][0] == 0)
			{
				float rtemporal2[3][3];
				for (int i = 0; i < 3; ++i)
				{
					rtemporal2[0][i]= matB[0][i]; //Esto es para intercambiar matrices.
					matB[0][i] = matB[2][i];
					matB[2][i] = rtemporal2[0][i];
				}
			}
			else
			{
				r2 = matB[2][0]/matB[0][0];
				for (int i = 0; i < 3; ++i)
				{
				matB[2][i] = matB[2][i] - r2*matB[0][i]; 
				}
			}	
		}

		if(matB[2][1] != 0)
		{
			if(matB[1][1] == 0)
			{
				float rtemporal3[3][3];
				for (int i = 0; i < 3; ++i)
				{
					rtemporal3[1][i]= matB[1][i]; //Esto es para intercambiar matrices.
					matB[1][i] = matB[2][i];
					matB[2][i] = rtemporal3[1][i];
				}
			}
			else
			{
				r3 = matB[2][1]/matB[1][1];
				for (int i = 0; i < 3; ++i)
				{
				matB[2][i] = matB[2][i] - r3*matB[1][i]; 
				}
			}	
		}

//Para la parte de arriba de la diagonal. Aquí es donde hay una pequeña variación.

		if(matB[1][2] != 0)
		{
			/*La pequeña variación se encuentra a continuación. Ahora no se comprueba si la componente [2][2] en este caso
			es igual a cero pero de igual forma se hace la división. Eso es porque dicha componente no puede ser igual a cero.
			No puede ser igual a cero porque las componentes [2][0] y [2][1] ya son cero por la parte anterior, y si este fuera
			cero entonces la determinante de la matriz sería cero, y de ser así nunca hubiera realizado todo este proceso por la
			condición que se puso al inicio. Ya que al intercambiar filas no cambia sino el signo de el determinante, entonces
			si inicialmete el determinante de la matriz matB es cero por más que se intercambien filas o se multipliquen filas 
			el determinante continuará siendo cero. Por lo que para el resto de valores arriba de la diagonal no hay que 
			intercambiar ninguna fila y sólo reducir a ceros los elemtos [1][2], [0][2] y [0][1] con el procedimiento que ya 
			se explicó en el código.*/
			r1 = matB[1][2]/matB[2][2]; 
			for (int i = 0; i < 3; ++i)
			{
			matB[1][i] = matB[1][i] - r1*matB[2][i]; 
			}
		}

		if(matB[0][2] != 0)
		{
			r2 = matB[0][2]/matB[2][2];
			for (int i = 0; i < 3; ++i)
			{
			matB[0][i] = matB[0][i] - r2*matB[2][i]; 
			}
		}

		if(matB[0][1] != 0)
		{
				r3 = matB[0][1]/matB[1][1];
				for (int i = 0; i < 3; ++i)
				{
				matB[0][i] = matB[0][i] - r3*matB[1][i]; 
				}
		}

		for (i = 0; i < 3; i++)
			{
				for (j = 0 ; j < 3; j++)
      			{
         			printf("%.0f\t", matB[i][j]); //Esto imprime la nueva matriz matB reducida a la forma Gauss-Jordan
      			}
				printf("\n");
			}

	//Fin del código(:
	}
	
}