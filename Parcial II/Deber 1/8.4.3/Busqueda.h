#include <iostream>
using namespace std;
class Busqueda{
	private:
 		int tamano;
 		string* Vector;
 		void limpiar();
 	public:
 		Busqueda();
 		void setTamano(int N);
 		int getTamano();
 		void setVector(int p, string ve);
 		string getVector(int p);
 		void ordenarIntercambio();
	//Declaración del método que retorna la posición del dato buscado, utilizando el método de búsqueda binaria
	//el método recibe como parámetro el dato que se desea buscar dentro del arreglo.
 		int bsuquedaBinaria(string dato);
};
Busqueda::Busqueda()
{
 	tamano = 0;
 	Vector = NULL;
}

void Busqueda::limpiar(){
	
 	if (tamano > 0 ) 
	{
 		tamano = 0;
 		delete []Vector;
 	}
}
void Busqueda::setTamano(int N){
 	tamano = N;
 	if (N > 0)
	{
 		Vector = new string[N];
 	}
}
int Busqueda::getTamano()
{
	return tamano;
}
void Busqueda::setVector(int p, string ve){
 	Vector[p] = ve;
}
string Busqueda::getVector(int p){
 	return Vector[p];
}
//implementación del método de ordenamiento por intercambio. Este método se utiliza para ordenar el vector y
//realizar la búsqueda con el método de búsqueda binaria.
void Busqueda::ordenarIntercambio(){
 	int i,j;
 	string temp;
 	for (i=0; i<=getTamano()-1; i++){
 		for (j=i+1; j<=getTamano()-1; j++){
 			if (getVector(i) > getVector(j)){
 				temp = getVector(i);
 				setVector(i, getVector(j));
 				setVector(j, temp);
 				}
 			}
 		}
}
//Implementación del método de búsqueda binaria. 
int Busqueda::bsuquedaBinaria(string dato){
	
 	int posicion, izq, der, centro; //Estas 4 variables almacenan posiciones del vector.
 	ordenarIntercambio();
 	izq = 0; //Primera posición del vector
 	der = getTamano()-1; //Ultima posición del vector
//Se asigna el valor de -1 a la variable posición para devolver este valor en el supuesto caso de que no se
//encuentre dato buscado dentro del vector.
 	posicion = -1;
//Mientra que no se llegue al final del vector y no se haya encontrado el dato buscado en el vector.
 	while ((izq <= der) && (posicion == -1)){
//Se busca cual es la posición del dato que se encuentra en el centro del vector.
 		centro = (izq + der) / 2;
 		if (dato == getVector(centro)){
 			posicion = centro;
 			}else{
 				if (dato < getVector(centro)){
 					der = centro-1;
 					}else{
 						izq = centro+1;
 					}
 				}
 		}
 return posicion;
}

 


