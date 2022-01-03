#include <iostream>
#include "Busqueda.h"
#include <stdlib.h>
using namespace std;
int menu();
int main()
{
	Busqueda obj;
 	int opc;
 	int tam;
 	string valorElemento;
 	int buscar;
 	string datoBuscar;
 	do{
 		opc = menu(); //Se llama al menú de opciones y se asigna la opción escogida a la variable “opc”
 		switch(opc){
 		case 1:
 			system("cls");
 			cout << "________________________________________________ \n";
 			cout << "\n DIGITE EL NUMERO DE ELEMENTOS DEL VECTOR \n";
 			cout << "________________________________________________ \n \n";
 			cout << "Cuantos elementos tendra en vector: ";
 			cin >> tam;
 			obj.setTamano(tam);
 			cout << "________________________________________________ \n";
 			cout << "\n DIGITE LOS VALORES DE LOS ELEMENTOS DEL VECTOR \n";
 			cout << "________________________________________________ \n \n";
 			for (int i=0; i<=obj.getTamano()-1; i++){
 				cout << "Digite el valor del elemento " << i << ": ";
 				cin >> valorElemento;
 				obj.setVector(i, valorElemento);
 			}
 			cout << "\n \n";
 			break;
 		case 2:
 			system("cls");
 			cout << "________________________________________________ \n";
 			cout << "\n BUSQUEDA BINARIA \n";
 			cout << "________________________________________________ \n \n";
 			cout << "Digite el dato que desea buscar: ";
 			cin >> datoBuscar;
 			buscar = obj.bsuquedaBinaria(datoBuscar);
 			if (buscar != -1){
 				cout << "\n";
 				cout << "El dato " << datoBuscar << " SE ENCUENTRA en la posicion " << buscar << " del vector";
 			}else{
 				cout << "\n";
 				cout << "El dato NO SE ENCUENTRA dentro del vector";
 			}
 			cout << "\n \n";
 			break;
 		case 3:
 			system("cls");
 			cout << "________________________________________________ \n";
 			cout << "\n DATOS DEL VECTOR \n";
 			cout << "________________________________________________ \n \n";
 			for (int i=0; i<=obj.getTamano()-1; i++){
 				cout << "Dato de la posicion " << i << ": " << obj.getVector(i) << "\n";
 			}
 			cout << "\n \n";
 			break;
 	}
 }while(opc != 3);
 return 0;
}

int menu(){
 	int opcion = 0;
 	cout << "________________________________________________ \n";
 	cout << "\n ESCOJA UNA OPCION  \n";
 	cout << "________________________________________________ \n \n";
 	cout << "1. Llenar el Vector \n";
 	cout << "2. Busqueda Binaria \n";
 	cout << "3. Mostrar Elementos del Vector \n";
 	cout << "________________________________________________ \n";
 	do{
 		
 		cout << "\nSeleccione una opcion del 1 al 3: ";
 		cin >> opcion;
 	}while(opcion <= 0 || opcion > 3);
 	return opcion;
}
