/***********************************************************************
 * Universidad de las Fuerzas Armadas Espe
 * Module:  Aplicativo
 * Author:  Esteven Nacimba 
 * Fecha de creacion: 27/12/2021 15:00pm
 * Fecha de modificacion:  27/12/2021 23:00pm
 * Materia: Estructura de Datos Nrc: 7167
 ***********************************************************************/
/*8.4.12. Escribir una función de búsqueda binaria aplicado a un array ordenado 
descendentemente.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void funcion(int *,int);
void leer(int *,int);
int *metodoBurbuja(int *, int );
void recorrerCE(int *, int );
void comparar(int *,int , int );
int busqueda(int *, int ,int,int);
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


int *metodoBurbuja(int *vec, int n)
{
	for(int i=0;i<n;i++)
	{
		recorrerCE(vec,n);
	}
	return vec;
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
	if(*(arr+j)<*(arr+j+1))
	{
		aux=*(arr+j);
		*(arr+j)=*(arr+j+1);
		*(arr+j+1)=aux;
	}
}

int busqueda(int *vec, int x, int min, int max) {
  
  while (min <= max) {
    int med = max + (max - min) / 2;

    if (*(vec+med)== x)
      return med;

    if (*(vec+med) < x)
      min = med + 1;

    else
      max = med - 1;
  }

  return -1;
}

int main() {
	int i,num,loc=-1;
	printf("Ingresar dimension del vector: ");
	cin>> i;
	int *vec = new int[i];
	int *aux = new int[i];
	funcion(vec,i);
	aux=metodoBurbuja(vec,i);
	printf("vector ordenado: ");
	leer(vec,i);
	cout<<"Ingrese el numero que desea buscar: ";
    cin>>num;
    loc = busqueda(aux, num,0, i-1);

   if(loc != -1)
   {
      cout<<num<<" se encontro en la posicion: "<<loc;
   }
   else
   {
      cout<<"no se pudo encontrar";
   }
		
	system("pause");
	return 0;
	
  
}


