/***********************************************************************
 * Universidad de las Fuerzas Armadas Espe
 * Module:  Aplicativo
 * Author:  Esteven Nacimba 
 * Fecha de creacion: 27/12/2021 15:00pm
 * Fecha de modificacion:  27/12/2021 23:00pm
 * Materia: Estructura de Datos Nrc: 7167
 ***********************************************************************/
/*8.4.11. Escribir la función de ordenación correspondiente al método radix para poner 
en orden alfabético una lista de n nombres.
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <string>

using std::string;
using namespace std;
void radixSort(string [], int );
void leer(string *, int );

void funcion(string *vec, int n){

	char nombre[50];
	for(int i=0; i<n; i++){
		fflush(stdin);
		cout<<"Ingrese nombre "<<i+1<<": ";
		cin.getline(nombre,51,'\n');
		*vec++=nombre;
	}	

}


void leer(string *vec, int n){
	for(int i=0; i<n; i++){;
		cout<<*vec++<<endl;
	}
}


int main(int argc, char** argv) {
 
	int n;
	printf("Ingresar dimension del vector: ");
	cin>> n;
	string *vec = new string[n];
	funcion(vec,n);
	puts("arreglo original");
	leer(vec,n);
    radixSort(vec, n);
    puts("arreglo ordenado:");
	leer(vec,n);
	system("PAUSE");
	return 0;
}


int getMax(string *arr, int n){
    int max = (arr+0)->size();
    for (int i = 1; i < n; i++){
        if ((arr+i)->size()>max)
            max = (arr+i)->size();
    }
    return max;
}

void countSort(string *a, int size, int k){
    string *b = NULL; int *c = NULL;
    b = new string[size];
    c = new int[257];

    for (int i = 0; i <257; i++){
        c[i] = 0;
    }
    for (int j = 0; j <size; j++){   
        c[k < a[j].size() ? (int)(unsigned char)a[j][k] + 1 : 0]++;         
    }

    for (int f = 1; f <257; f++){
        c[f] += c[f - 1];
    }

    for (int r = size - 1; r >= 0; r--){
        b[c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0] - 1] = a[r];
        c[k < a[r].size() ? (int)(unsigned char)a[r][k] + 1 : 0]--;
    }

    for (int l = 0; l < size; l++){
        a[l] = b[l];
    }

    delete[] b;
    delete[] c;
}

void radixSort(string *b, int r){
    int max = getMax(b, r);
    for (int j = max; j > 0; j--){
        countSort(b, r, j - 1);
    }

}


