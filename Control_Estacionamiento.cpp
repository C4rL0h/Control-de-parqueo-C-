/*
****Proyecto: Control de Parqueo
****Autor: CARLOS RAFAEL HUIT ESCOBAR
****Descripción: Este proyecto tiene la capacidad de ingresar un vehículos asignando número de parqueo
    así también, calcula el costo del parqueo en monto de Quetzales Guatemaltecos.
*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;
//Prototipado
void menu();
void ingreso();
void egreso();
void consultar();
void disponible();

//Estructuras

struct parqueo{
    int numero_estacionamiento;
    int ocupado; // Si esta ocupado tendra valor 1 si esta libre valor 0
    int entrada;
    int salida;
    string placa;
}lugar[40];

struct vehiculo {
    string placa;
    int codigo;
};


int main(){

    for(int i = 1; i<41; i++){
        lugar[i].numero_estacionamiento =i;
    }
    menu();
    return 0;
}
//Menu
void menu(){

    int opcion;

    do {
        system("cls");
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Ingreso" << endl;
        cout << "2. Egreso" << endl;
        cout << "3. Consultar" << endl;
        cout << "4. Parqueos disponibles" << endl;
        cout << "5. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingreso();
                system("pause>nul");
                break;

            case 2:
                system("pause>nul");
                egreso();
                break;

            case 3:
                consultar();
                system("pause>nul");
                break;

            case 4:
                system("pause>nul");
                break;
        }
    } while (opcion != 5);

}

void ingreso( ){

    string placa;
    int parqueo;
    int hora;

    cout <<"Ingrese la placa del vehiculo"<<endl;
    cin >>placa;

    cout<<"Hora de ingreso: "<<endl;
    cin>>hora;

    cout<<"Numero de parqueo:"<<endl;
    cin>>parqueo;

    //comprobar si esta ocupado, sino asigna el espacio
    if(lugar[parqueo].ocupado==0){
        lugar[parqueo].ocupado=1;
        lugar[parqueo].entrada=hora;
        lugar[parqueo].placa=placa;
        cout<<"Guardado correctamente en el numero de lugar: "<<parqueo<<endl;
        system("pause>nul");
        menu();

    }else{
        cout<<"El lugar esta ocupado, intentar de nuevo"<<endl;
        system("pause>nul");
        ingreso();
    }


}

void egreso(){

    string placa;
    int parqueo;
    int hora;
    int total;

    cout<<"Numero de parqueo:"<<endl;
    cin>>parqueo;

    cout <<"Placa del vehiculo: "<<lugar[parqueo].placa<<endl;
    cout <<"Hora de ingreso: "<<lugar[parqueo].entrada<<endl;

    cout<<"Hora de egreso: "<<endl;
    cin>>hora;

    //comprobar si esta ocupado, sino asigna el espacio
    if(lugar[parqueo].ocupado==1){
        lugar[parqueo].ocupado=0;
        lugar[parqueo].salida=hora;
       // lugar[parqueo].placa=placa;
        total= (lugar[parqueo].entrada - lugar[parqueo].salida)*-5;
        cout<<"El total a pagar es de : Q."<<total<<endl;
        system("pause>nul");
        menu();

    }else{
        cout<<"El lugar no esta ocupado, intentar de nuevo"<<endl;
        system("pause>nul");
        ingreso();
    }
}
void consultar(){
    cout<<"Nivel1"<<endl;
    for(int i = 0; i<20;i++){
        if (lugar[i].ocupado==1){//Si el lugar que indica la posicion de i esta ocupado
            cout<<"Lugar No.:"<<i<<" Ocupado. "<<endl;
        }else{
            cout<<"Lugar No.:"<<i<<" Libre. "<<endl;
        }
    }
        cout<<"Nive 2"<<endl;
    for(int i = 20; i<40;i++){
        if (lugar[i].ocupado==1){//Si el lugar que indica la posicion de i esta ocupado
            cout<<"Lugar No.:"<<i<<" Ocupado. "<<endl;
        }else{
            cout<<"Lugar No.:"<<i<<" Libre. "<<endl;
        }
    }
    system("pause>nul");
    menu();
}

void disponible(){
        cout<<"Nivel1"<<endl;
    for(int i = 0; i<20;i++){
        if (lugar[i].ocupado==1){//Si el lugar que indica la posicion de i esta ocupado
        }else{
            cout<<"Lugar No.:"<<i<<" Libre. "<<endl;
        }
    }
        cout<<"Nive 2"<<endl;
    for(int i = 20; i<40;i++){
        if (lugar[i].ocupado==1){//Si el lugar que indica la posicion de i esta ocupado
        }else{
            cout<<"Lugar No.:"<<i<<" Libre. "<<endl;
        }
    }
    system("pause>nul");
    menu();
}
