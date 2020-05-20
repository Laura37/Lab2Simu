



/*
Autor: Laura Portillo
Compilador: 
Compilado:
Fecha: 
Librerias: iostream, math, stdlib
Resumen: Es un cohete que se alcanza una altura máxima, se queda sin combustible y vuelve a caer.
*/

//Se incluyen las librerias.
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
using namespace std; 

//Se crea la clase cohete.
class Cohete{
	//Atributos
	public:
		float E_o, TSFC, CD, A, m_o, m_fo, t, y, v;
	public:
	//Métodos
	Cohete(float, float, float, float, float, float); //Constructor
	void datosTrayectoria();
};

//inicializando constructor
Cohete::Cohete(float _E_o, float _TSFC, float _CD, float _A, float _m_o, float _m_fo) /*, float _t, float _y, float _v*/
{
	E_o = _E_o;
	TSFC = _TSFC;
	m_o = _m_o;
	m_fo = _m_fo;
	CD = _CD;
	A = _A;
}

/*_____________________________________________________________________________________________________________________
_______________________________________________________________________________________________________________________
_______________________________________________________________________________________________________________________
_____________________________________________________________________________________________________________________*/

//Se define la función de datosTrayectora la cual dará todo lo que pide el problema. (Parte importante).


void Cohete::datosTrayectoria()
{

	// Definición de las constantes
 	const float G = 6.693*pow(10,-11); //Constante de gravitación universal.
 	const float R_T = 6.378*pow(10,6); //Radio de la Tierra.
 	const float M_T = 5.9736*pow(10,24); // Masa de la Tierra.
 	const float R =  287.06; //Constante ideal del gas-
 	const float L = 6.5*pow(10,-3); //Constante térmica de la atmósfera.
 	const float g_o = 9.81; //Gravedad a nivel del mar.
 	const float T_o = 288.15; //Temperatura a nivel del mar.
 	const int P_o = 101325; //Presión a nivel del mar.

	float delta = 0.001;
	//inicializar las variables:

	t = 0;
	v = 0;
	y = 0;

	//Primero cálculo de la aceleración, masa combistible, gravedad
	float g = (G*M_T)/pow((R_T+y),2); //Gravedad
	float m_f = m_fo;
	float m_c = m_o + m_f;
	float rho = (P_o/R*T_o)*pow((1- ((L*y)/T_o)),((g_o)/(R*L)));
	float F_a = rho*CD*A*v*abs(v)/2; 
	float a = (E_o - F_a - m_c*g)/m_c; //Aceleración.
	float vn;
	float tmax, ymax, tc;
	FILE *pf = fopen("trayectoria","wt");
	fprintf(pf, "%f\t %f\t %f\n",t, y, v);
	while(y>=0)
	{


		t+=delta;
		vn = v + a*delta;
		y = y + delta*v;
		g = (G*M_T)/pow((R_T+y),2); //Gravedad
	

			m_f = m_f -(TSFC*E_o)*delta;
			if (m_f<0)
			{
				m_f = 0;
				E_o = 0;
				tc = t; //Tiempo en el que se agota el combustible.
			} 
		m_c = m_o + m_f;
		F_a = rho*CD*A*vn*abs(vn)/2; 
		if(y < (T_o/L))
		{
			rho = (P_o/R*T_o)*pow((1- ((L*y)/T_o)),((g_o)/(R*L)));
		}
		else{
			rho = 0;
		}
		

		a = (E_o - F_a - m_c*g)/m_c; //Aceleración.
		
		if(v*vn<=0 && t!=0){
			tmax =t;
			ymax =y;
		}
		v = vn;
		

		fprintf(pf, "%f\t %f\t %f\n",t, y, v);

	}

	cout << "La altura máxima alcanzada es: " << ymax <<" en el tiempo: "<< tmax <<endl;
	cout << "El instante de tiempo en el que se agota el combustible es: " << tc << endl;
	cout << "El instante de tiempo en el que se produce el impacto en el suelo: "<< t <<endl;
	fclose(pf);	


	FILE *flujo = fopen("script","wt");
	fprintf(flujo, "plot 'trayectoria' u 1:3 \n");
	fclose(flujo);

	FILE *flujo2 = fopen("script2","wt");
	fprintf(flujo2, "plot 'trayectoria' u 1:2 \n");
	fclose(flujo2);

	FILE *flujo3 = fopen("script3","wt");
	fprintf(flujo3, "plot 'trayectoria' u 2:3 \n");
	fclose(flujo3);

	//Esto ejecutará el comando entre comillas en la consola por lo tanto gnuplot ejecutará el script (:
	system("gnuplot -p script");
	system("gnuplot -p script2");
	system("gnuplot -p script3");

}



/*_____________________________________________________________________________________________________________________
_______________________________________________________________________________________________________________________
_______________________________________________________________________________________________________________________
_____________________________________________________________________________________________________________________*/







int main()
{
//Se crean los 3 objetos:

printf("Para el cohete 1:\n");

Cohete cohete1 = Cohete(3*pow(10,7), 3.248*pow(10,-4), 61.27, 201.06, 1.1*pow(10,5), 1.5*pow(10,6));
cohete1.datosTrayectoria();

printf("\n");

printf("Para el cohete 2:\n");

Cohete cohete2 = Cohete(2.7*pow(10,7), 2.248*pow(10,-4), 61.27, 201.06, 1.1*pow(10,5), 1.5*pow(10,6));
cohete2.datosTrayectoria();

printf("\n");

printf("Para el cohete 3:\n");

Cohete cohete3 = Cohete(2.5*pow(10,7), 2.248*pow(10,-4), 70.25, 215.00, 1.8*pow(10,5), 2.1*pow(10,6));
cohete3.datosTrayectoria();



return 0;
}