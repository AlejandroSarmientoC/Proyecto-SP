#include<iostream>
#include"Quicksort.h"
using namespace std;
int main(){
	Quicksort q;
	int lista[] ={33,45,67,8,12,32,56,7,9,10,22,45,98,9};
    int size = sizeof(lista)/sizeof(int);
    cout<<"Lista desordenada \n";
    q.imprimir(lista,size);
    q.quicksort(lista,size);
    cout<<"\nLista ordenada \n";
    q.imprimir(lista,size);
     cout<<"\nLista ordenada \n";
    q.imprimirR(lista,0,size-1);
    q.imprimir(lista,size);
}

