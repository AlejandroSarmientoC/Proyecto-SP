/*
Escribir una función que elimine los elementos duplicados de un vector ordenado.
Utilizando el método de Quicksort.
*/
#include <iostream>

using namespace std;

void crearArreglo(int*, int);
void imprimirArreglo(int*, int);
void eliminarDuplicados(int*, int);
void quickSort(int*, int, int);

int main(){
    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;
    int *arreglo = new int[n];
    crearArreglo(arreglo, n);
    cout << "Arreglo original: " << endl;
    imprimirArreglo(arreglo, n);
    cout << "Arreglo ordenado: " << endl;
    quickSort(arreglo, 0, n-1);
    imprimirArreglo(arreglo, n);
    eliminarDuplicados(arreglo, n);
    
    return 0;
}

void crearArreglo(int *arreglo, int n){
    for(int i = 0; i < n; i++){
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> arreglo[i];
    }
}
void imprimirArreglo(int *arreglo, int n){
    for(int i = 0; i < n; i++){
        cout << arreglo[i] << " ";
    }
    cout << endl;
}
void eliminarDuplicados(int *arreglo, int n){
    int i = 0;
    int j = 1;
    while(j < n){
        if(arreglo[i] != arreglo[j]){
            i++;
            arreglo[i] = arreglo[j];
        }
        j++;
    }
    i++;
    cout << "Arreglo sin duplicados: " << endl;
    imprimirArreglo(arreglo, i);
}
void quickSort(int *arreglo, int izq, int der){
    int i = izq;
    int j = der;
    int pivote = arreglo[(izq + der) / 2];
    while(i <= j){
        while(arreglo[i] < pivote){
            i++;
        }
        while(arreglo[j] > pivote){
            j--;
        }
        if(i <= j){
            int temp = arreglo[i];
            arreglo[i] = arreglo[j];
            arreglo[j] = temp;
            i++;
            j--;
        }
    }
    if(izq < j){
        quickSort(arreglo, izq, j);
    }
    if(i < der){
        quickSort(arreglo, i, der);
    }
}