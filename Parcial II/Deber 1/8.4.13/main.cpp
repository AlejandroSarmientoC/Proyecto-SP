/*
Se trata de resolver el siguiente problema escolar. Dadas las notas de los alumnos de
un colegio en el primer curso de bachillerato, en las diferentes asignaturas (5, por
comodidad), se trata de calcular la media de cada alumno, la media de cada
asignatura, la media total de la clase y ordenar los alumnos por orden decreciente de
notas medias individuales
*/
#include <iostream>
#include <vector>

using namespace std;

struct Alumno{
    double notas[5];
    double media;
};

void ingresarAlumnos(vector<Alumno> &alumnos, int n){
    for(int i = 0; i < n; i++){
        Alumno alumno;
        cout << "Ingrese nota 1: ";
        cin >> alumno.notas[0];
        cout << "Ingrese nota 2: ";
        cin >> alumno.notas[1];
        cout << "Ingrese nota 3: ";
        cin >> alumno.notas[2];
        cout << "Ingrese nota 4: ";
        cin >> alumno.notas[3];
        cout << "Ingrese nota 5: ";
        cin >> alumno.notas[4];
        alumno.media = (alumno.notas[0] + alumno.notas[1] + alumno.notas[2] + alumno.notas[3] + alumno.notas[4]) / 5;
        alumnos.push_back(alumno);
    }
}
void mediaAsignatura(vector<Alumno> &alumnos, int n){
    double mediaAsignatura[5];
    for(int i = 0; i < 5; i++){
        double suma = 0;
        for(int j = 0; j < n; j++){
            suma += alumnos[j].notas[i];
        }
        mediaAsignatura[i] = suma / n;
    }
    for(int i = 0; i < 5; i++){
        cout << "Media de la asignatura " << i + 1 << ": " << mediaAsignatura[i] << endl;
    }
}
void mediaAlumno(vector<Alumno> &alumnos, int n){
    for(int i = 0; i < n; i++){
        double suma = 0;
        for(int j = 0; j < 5; j++){
            suma += alumnos[i].notas[j];
        }
        alumnos[i].media = suma / 5;
    }
    //imprimir
    for(int i = 0; i < n; i++){
        cout << "Media del alumno " << i + 1 << ": " << alumnos[i].media << endl;
    }
}

void mediaTotal(vector<Alumno> &alumnos, int n){
    double suma = 0;
    for(int i = 0; i < n; i++){
        suma += alumnos[i].media;
    }
    cout << "Media total: " << suma / n << endl;
}
void ordenarAlumnos(vector<Alumno> &alumnos, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(alumnos[j].media < alumnos[j + 1].media){
                Alumno aux = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = aux;
            }
        }
    }
    //imprimir
    for(int i = 0; i < n; i++){
        cout << "Media del alumno " << i + 1 << ": " << alumnos[i].media << endl;
    }
}

int main(){
    int opcion, n;
    vector<Alumno> alumnos;
    do{
        cout << "\tMENU" << endl;
        cout << "1. Ingresar notas" << endl;
        cout << "2. Media de cada alumno" << endl;
        cout << "3. Media de cada asignatura" << endl;
        cout << "4. Media total de la clase" << endl;
        cout << "5. Ordenar alumnos por notas" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "Ingrese el numero de alumnos: ";
                cin >> n;
                ingresarAlumnos(alumnos, n);
                system("pause");
                break;
            case 2:
                mediaAlumno(alumnos, n);
                system("pause");
                break;
            case 3:
                mediaAsignatura(alumnos, n);
                system("pause");
                break;
            case 4:
                mediaTotal(alumnos, n);
                system("pause");
                break;
            case 5:
                ordenarAlumnos(alumnos, n);
                system("pause");
                break;
            case 6:
                cout << "Saliendo..." << endl;
                system("pause");
                break;
            default:
                cout << "Opcion invalida" << endl;
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 6);
    return 0;
}

