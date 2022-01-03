#include<iostream>
#include <stdio.h>
using namespace std;
class Quicksort{
	private:
		int izq,der,temporal,pivote;
	public: 
		void qs(int lista[],int limite_izq,int limite_der);	
		void quicksort(int lista[],int n);
		void imprimir(int lista[], int size);
		void imprimirR(int lista[], int inicio, int fin);
};
void Quicksort:: qs(int lista[],int limite_izq,int limite_der)
{
    izq=limite_izq;
    der = limite_der;
    pivote = lista[(izq+der)/2];

    do{
        while(lista[izq]<pivote && izq<limite_der)izq++;
        while(pivote<lista[der] && der > limite_izq)der--;
        if(izq <=der)
        {
            temporal= lista[izq];
            lista[izq]=lista[der];
            lista[der]=temporal;
            izq++;
            der--;

        }

    }while(izq<=der);
    if(limite_izq<der){qs(lista,limite_izq,der);}
    if(limite_der>izq){qs(lista,izq,limite_der);}

}

void Quicksort:: quicksort(int lista[],int n)
{
    qs(lista,0,n-1);
}
void Quicksort::imprimir(int lista[] ,int size) {
	
	cout << "Arreglo: { ";
	for (int i = 0; i < size; i++) {
		cout << lista[i] << " ";
	}
	cout << " }";
}
void Quicksort:: imprimirR(int lista[], int inicio, int fin)
{
    while (inicio < fin)
    {
        int temp = lista[inicio];
        lista[inicio] = lista[fin];
        lista[fin] = temp;
        inicio++;
        fin--;
    }
}    
