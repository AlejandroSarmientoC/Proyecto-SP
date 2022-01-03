#include <iostream>
using namespace std;
class Busqueda{
	private:
		int *numeros,cantidadNumeros,numeroBuscar;
	public: 
		void pedirDatos();
		void pedirNumero();
		void buscarDatos();	
};
void Busqueda::pedirDatos(){
    cout<<"Cuantos numeros va a tener tu arreglo:";
    cin>>cantidadNumeros;
    numeros=new int[cantidadNumeros];
    for (int i = 0; i < cantidadNumeros; i++)
    {
        cout<<"Numero "<<i+1<<": ";
        cin>>*(numeros+i);
    }
}
void Busqueda:: pedirNumero(){
    cout<<"Que numero quieres buscar de tu arreglo:";
    cin>>numeroBuscar;
}
void Busqueda:: buscarDatos(){
    bool encontrado=false;
    int i=0;
    while (i<cantidadNumeros && encontrado==false)
    {
        if(*(numeros+i)==numeroBuscar){
            encontrado=true;
        }
        i++;
    }
    if (encontrado==true)
    {
        cout<<"Felicidades el numero "<<numeroBuscar<<" si se encuentra en el arreglo.\n";
    }
    else{
        cout<<"El numero "<<numeroBuscar<<" no esta en la lista \n";
    }    
}
