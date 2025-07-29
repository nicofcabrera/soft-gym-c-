#include <iostream>
#include <fstream> //Libreria manejo de archivos
#include <windows.h> //Libreria propia del SO Windows
#include <stdio.h> //Libreria manejo de colores fondo y fuentesss
#include "archivos.h"

using namespace std;

//Prototipo funciones
int menu();

int main(){
	
	ofstream Escritura;
	ifstream Lectura;
	int opcion;
	
	do{
		system("mode con: cols=100 lines=30");
		system("color 60");
		
		opcion = menu();
		
		switch(opcion){
			case 1:
				registrarSocio(Escritura);
			break;
			case 2:
				verSocios(Lectura);
			break;
			case 3:
				buscarSocio(Lectura);
			break;
			case 4:
				modificarSocio(Lectura);
			break;
			case 5:
				eliminarSocio(Lectura);
			break;
			case 6:
				ingresoSocio(Lectura);
			break;
			case 7:
				cout<<"\n\tGracias por utilizar nuestro sistema! Cerrando sistema..."<<endl;
				Sleep(3000);
				break;
			default:
				cout<<"\n\tEl numero ingresado no coincide con niguno del Menu. Volviendo al menu..."<<endl;
				Sleep(4000);
		}
		
	}while(opcion != 7);


	
	return 0;
}

int menu(){
	int x;
	system("cls");
	banner();
	
	cout<<"\n\n\t1. Registrar Socio"<<endl;
	cout<<"\t2. Listado de Socios."<<endl;
	cout<<"\t3. Buscar Socio"<<endl;
	cout<<"\t4. Modificar Socio"<<endl;
	cout<<"\t5. Eliminar Socio"<<endl;
	cout<<"\t6. Ingreso Socio"<<endl;
	cout<<"\t7. Salir"<<endl;
	cout<<"\n\n\tDigite una opcion: ";
	cin>>x;
	
	return x;
}
