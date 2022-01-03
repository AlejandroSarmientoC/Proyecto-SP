/***********************************************************************
 * Universidad de las Fuerzas Armadas Espe
 * Module:  Aplicativo
 * Author:  Esteven Nacimba 
 * Fecha de creacion: 27/12/2021 15:00pm
 * Fecha de modificacion:  27/12/2021 23:00pm
 * Materia: Estructura de Datos Nrc: 7167
 ***********************************************************************/
/*8.4.10. Dado un vector x de n elementos reales, donde n es impar, diseñar una función que 
calcule y devuelva la mediana de ese vector. La mediana es el valor tal que la mitad 
de los números son mayores que el valor y la otra mitad son menores. Escribir un 
programa que compruebe la función.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void funcion(int *,int);
void leer(int *,int);
void metodoBurbuja(int *, int );
void recorrerCE(int *, int );
void comparar(int *,int , int );
void mediana(int);
void funcion(int *vec, int n){
	int j;
	for(j=0;j<n;j++){
		printf("Ingresar valor en posicion %i: ",j+1);
		scanf("%i",(vec+j));
	}
}

void leer(int *vec, int n){
	int j;
	cout<<endl;
	for(j=0;j<n;j++){
		printf("\t%i\n",*(vec+j));
	}
}

void metodoBurbuja(int *vec, int n)
{
	for(int i=0;i<n;i++)
	{
		recorrerCE(vec,n);
	}
}

void recorrerCE(int *vec, int n)
{                                                

	for(int j=0;j<n-1;j++)
		{
			comparar(vec,j,n);
		}                  
}

void comparar(int *arr,int j, int n)
{                                               
	int aux;
	if(*(arr+j)>*(arr+j+1))
	{
		aux=*(arr+j);
		*(arr+j)=*(arr+j+1);
		*(arr+j+1)=aux;
	}
}


int main() {
	int i;
	printf("Ingresar dimension del vector: ");
	cin>> i;
	int *vec = new int[i];
	funcion(vec,i);
	metodoBurbuja(vec,i);
	printf("vector ordenado: ");
	leer(vec,i);
	if(i%2!=0)
		cout<<"la mediana es: "<<*(vec + i/2)<<endl;
	else
		cout<<"la mediana es: "<<(*(vec+i/2 - 1)+*(vec+i/2))/2<<endl;
		
	system("pause");
	return 0;
	
  
}


