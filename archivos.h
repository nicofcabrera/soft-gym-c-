#include <iostream>
#include <fstream>
#include "bannerAsci.h"
#include <iomanip>
#include <string>

using namespace std;

void registrarSocio(ofstream &socioAgregar);
void verSocios(ifstream &sociosVer);
void buscarSocio(ifstream &socioBuscar);
void modificarSocio(ifstream &socioModificar);
void eliminarSocio(ifstream &socioEliminar);
void ingresoSocio(ifstream &socioIngreso);
void color(int numero);
bool verificar(int dni);

bool cinValidar();

struct Socio{
	string Nombre;
	string Apellido;
	int DNI;
	int Contacto;
	string Domicilio;
	int NroDomicilio;
	string TipoSocio;
}s1,s2;

void registrarSocio(ofstream &socioAgregar){
	system("cls"); //limpieza de consola
	bool bandera = true;
	int contador = 0;
	
	socioAgregar.open("Socios.txt", ios::out | ios::app);
	
	cin.ignore();
	while(bandera){
		registroBanner();
		fflush(stdin);
		
		cout<<"\n\tNombre: ";
		getline(cin, s1.Nombre);
		cout<<"\tApellido: ";
		getline(cin, s1.Apellido);
		cout<<"\tDNI: ";
		cin>>s1.DNI;
		
		if(s1.DNI){
			contador++;
		}
		
		cout<<"\tContacto: ";
		cin>>s1.Contacto;
		
		if(s1.Contacto){
			contador++;
		} 
		
		fflush(stdin);
		cout<<"\tDomicilio: ";
		getline(cin, s1.Domicilio);
		cout<<"\tNro Domicilio: ";
		cin>>s1.NroDomicilio;
		
		if(s1.NroDomicilio){
			contador++;
		}
		
		fflush(stdin);
		cout<<"\n\t('B'= Boxeo 'S'= Spinning 'M'= Musculacion )"<<endl;
		cout<<"\tTipo Socio: ";
		getline(cin, s1.TipoSocio);
		
		if(contador != 3){
			color(4);
			cout<<"\n\n\tIngrese solo numeros en DNI, Contacto y Nro Domicilio."<<endl;
			cout<<"\n\tVuelve a intentar. ";
			system("pause");
			system("cls");
			contador = 0;
			cin.clear();
			system("color 60");
		} else{
			cin.clear();
			bandera = false;
		}
	}
	
	if(verificar(s1.DNI)){
		if (s1.TipoSocio == "b" || s1.TipoSocio == "B") {
			s1.TipoSocio = "Boxeo";
		} else if (s1.TipoSocio == "S" || s1.TipoSocio == "s") {
			s1.TipoSocio = "Spinning";
		} else if (s1.TipoSocio == "M" || s1.TipoSocio == "m") {
			s1.TipoSocio = "Musculacion";
		} else {
			s1.TipoSocio = "null";
		}
		
		socioAgregar<<s1.Nombre<<" "<<s1.Apellido<<" "<<s1.DNI<<" "<<s1.Contacto<<" "<<s1.Domicilio<<" "
		<<s1.NroDomicilio<<" "<<s1.TipoSocio<<endl;
		color(2);
		cout<<"\n\tAGREGADO CON EXITO!"<<endl;
		cout<<"\n\tVolviendo al menu..."<<endl;
		cout<<"\n\t";
		system("pause");
		socioAgregar.close();
	} else{
		color(4);
		cout<<"\n\tEse DNI ya se encuentra registrado."<<endl;
		cout<<"\n\tVolviendo al menu..."<<endl;
		cout<<"\n\t";
		system("pause");
		socioAgregar.close();
	}
}

void verSocios(ifstream &sociosVer){
	system("cls");
	bdBanner();
	
	sociosVer.open("Socios.txt",ios::in);
	
	if(sociosVer.is_open()){
		cout<<"\n\t"<<setw(10)<<left<<"Nombre"<<setw(10)<<left<<"Apellido"<<setw(10)<<left<<"DNI"<<setw(11)<<left<<"Contacto"
		<<setw(15)<<left<<"Domicilio"<<setw(8)<<left<<"NroDomi"<<setw(12)<<left<<"TipoSocio"<<endl;
		
		//Linea punteada, visualizacion tabla.
		cout<<"\t";
		for(int i = 0 ; i < 76 ; i++){
			cout<<"-";
		}		
		cout<<"\n";
		
		sociosVer>>s1.Nombre;
		while(!sociosVer.eof()){
			sociosVer>>s1.Apellido;
			sociosVer>>s1.DNI;
			sociosVer>>s1.Contacto;
			sociosVer>>s1.Domicilio;
			sociosVer>>s1.NroDomicilio;
			sociosVer>>s1.TipoSocio;
			
			cout<<"\t"<<setw(10)<<left<<s1.Nombre<<setw(10)<<left<<s1.Apellido<<setw(10)<<left<<s1.DNI<<setw(11)<<left<<s1.Contacto
			<<setw(15)<<left<<s1.Domicilio<<setw(8)<<left<<s1.NroDomicilio<<setw(12)<<left<<s1.TipoSocio<<endl;

			sociosVer>>s1.Nombre;
		}
	
		sociosVer.close();
		color(2);
		cout<<"\n\t";
		system("pause");
	} else{
		color(4);
		cout<<"\n\tERROR, no existe archivo. "<<endl;
		cout<<"\n\t";
		system("pause");
	}
}

void buscarSocio(ifstream &socioBuscar){
	system("cls");
	buscarBanner();
	bool bandera;
	int auxdni;
	
	socioBuscar.open("Socios.txt", ios::in);
	
	if(socioBuscar.is_open()){
		while(true){
			system("cls");
			buscarBanner();
			cout<<"\n\tIngrese DNI para buscar: ";
			cin>>auxdni;
		
			if(!cin.fail()){
				cin.clear();
				cin.ignore();
				break;
			} else{
				color(4);
				cout<<"\n\tError. Vuelve a ingresar DNI."<<endl;
				cout<<"\n\t";
				system("pause");
				cin.clear();
				cin.ignore();
				system("color 60");
			}	
				
			system("cls");
		}
		
		
		socioBuscar>>s1.Nombre;
		while(!socioBuscar.eof()){
			socioBuscar>>s1.Apellido;
			socioBuscar>>s1.DNI;
			socioBuscar>>s1.Contacto;
			socioBuscar>>s1.Domicilio;
			socioBuscar>>s1.NroDomicilio;
			socioBuscar>>s1.TipoSocio;
			
			if(s1.DNI == auxdni){
				cout<<"\n\tNombre: "<<s1.Nombre<<endl;
				cout<<"\tApellido: "<<s1.Apellido<<endl;
				cout<<"\tDNI: "<<s1.DNI<<endl;
				cout<<"\tContacto: "<<s1.Contacto<<endl;
				cout<<"\tDomicilio: "<<s1.Domicilio<<" "<<s1.NroDomicilio<<endl;
				cout<<"\tTipo Socio: "<<s1.TipoSocio<<"\n"<<endl;
				cout<<"\n\t";
				bandera = true;
				break;
			} else{
				bandera = false;
			}
			
			socioBuscar>>s1.Nombre;
		}
		
		if(!bandera){
			color(4);
			cout<<"\n\tEl DNI ingresado no fue encontrado."<<endl;
		}
			
		socioBuscar.close();
		color(2);
		cout<<"\n\t";
		system("pause");
		
	} else{
		color(4);
		cout<<"\n\tError al abrir el archivo. Intente otra vez...\n"<<endl;
		cout<<"\t";
		system("pause");
	}
}

void modificarSocio(ifstream &socioModificar){
	system("cls");
	modificarBanner();
	bool bandera = false, bandera2 = true;
	int auxdni, contador = 0;
	
	cin.ignore();
	
	socioModificar.open("Socios.txt", ios::in);
	ofstream auxiliar("Auxiliar.txt", ios::out | ios::app);
	
	if(socioModificar.is_open()){
		while(true){
			system("cls");
			modificarBanner();
			fflush(stdin);
			cout<<"\n\tIngrese DNI: ";
			cin>>auxdni;
		
			if(!cin.fail()){
				cin.clear();
				cin.ignore();
				break;
			} else{
				color(4);
				cout<<"\n\tError. Vuelve a ingresar DNI."<<endl;
				cout<<"\n\t";
				system("pause");
				cin.clear();
				cin.ignore();
				system("color 60");
			}
			system("cls");
		}
		
		socioModificar>>s1.Nombre;
		
		while(!socioModificar.eof()){
			socioModificar>>s1.Apellido;
			socioModificar>>s1.DNI;
			socioModificar>>s1.Contacto;
			socioModificar>>s1.Domicilio;
			socioModificar>>s1.NroDomicilio;
			socioModificar>>s1.TipoSocio;
		
			if(auxdni == s1.DNI){
				bandera = true;
				
				while(bandera2){
					fflush(stdin);
					cout<<"\n\tNombre: ";
					getline(cin, s2.Nombre);
					cout<<"\tApellido: ";
					getline(cin, s2.Apellido);
					
					fflush(stdin);
					
					cout<<"\tDNI: ";
					cin>>s2.DNI;
					
					if(s2.DNI){
						contador++;
					}
					
					cout<<"\tContacto: ";
					cin>>s2.Contacto;
					
					if(s2.Contacto){
						contador++;
					}
					
					fflush(stdin);
					
					cout<<"\tDomicilio: ";
					getline(cin, s2.Domicilio);
					cout<<"\tNro Domicilio: ";
					cin>>s2.NroDomicilio;
					
					if(s2.NroDomicilio){
						contador++;
					}
					
					fflush(stdin);
					
					cout<<"\n\t('B'= Boxeo 'S'= Spinning 'M'= Musculacion )"<<endl;
					cout<<"\tTipo Socio: ";
					getline(cin, s2.TipoSocio);
					
				
					
					if(contador != 3){
						contador = 0;
						color(4);
						cout<<"\n\n\tIngrese solo numeros en DNI, Contacto y Nro Domicilio."<<endl;
						cout<<"\n\tVuelve a intentar. "<<endl;
						cout<<"\n\t";
						system("pause");
						system("cls");
						cin.clear();
						system("color 60");
						modificarBanner();
					} else{
						contador = 0;
						bandera2= false;
					}
				}
	
				if (s2.TipoSocio == "b" || s2.TipoSocio == "B") {
					s2.TipoSocio = "Boxeo";
				} else if (s2.TipoSocio == "S" || s2.TipoSocio == "s") {
					s2.TipoSocio = "Spinning";
				} else if (s2.TipoSocio == "M" || s2.TipoSocio == "m") {
					s2.TipoSocio = "Musculacion";
				} else {
					s2.TipoSocio = "null";
				}
				
				auxiliar<<s2.Nombre<<" "<<s2.Apellido<<" "<<s2.DNI<<" "<<s2.Contacto<<" "<<s2.Domicilio<<" "<<
				s2.NroDomicilio<<" "<<s2.TipoSocio<<endl;
				
				color(2);
				cout<<"\n\tUsuario MODIFICADO! "<<endl;
				cout<<"\n\t";
				system("pause");
			} else{
				auxiliar<<s1.Nombre<<" "<<s1.Apellido<<" "<<s1.DNI<<" "<<s1.Contacto<<" "<<s1.Domicilio<<" "
				<<s1.NroDomicilio<<" "<<s1.TipoSocio<<endl;
			}
			socioModificar>>s1.Nombre;
		}
		
		if(!bandera){
			color(4);
			cout<<"\n\tEl usario ingresado no existe.\n"<<endl;
			cout<<"\tVolviendo al Menu Principal..."<<endl;
			cout<<"\n\t";
			system("pause");
		}
	
		
		socioModificar.close();
		auxiliar.close();
		
	} else{
		color(4);
		cout<<"\n\tError al abrir el archivo. \n"<<endl;
		cout<<"\tVolviendo al Menu Principal..."<<endl;
		cout<<"\n\t";
		system("pause");
	}
	
	remove("Socios.txt");
	rename("Auxiliar.txt", "Socios.txt");
}

void eliminarSocio(ifstream &socioEliminar){
	system("cls");
	bool bandera = false;
	int auxDNI, decision;
	
	socioEliminar.open("Socios.txt", ios::in);
	ofstream auxiliar("Auxiliar.txt", ios::out | ios::app);
	
	if(socioEliminar.is_open()){
		while(true){
			system("cls");
			eliminarBanner();
			fflush(stdin);
			cout<<"\n\tIngrese DNI: ";
			cin>>auxDNI;
		
			if(!cin.fail()){
				cin.clear();
				cin.ignore();
				break;
			} else{
				color(4);
				cout<<"\n\tError. Vuelve a ingresar DNI."<<endl;
				cout<<"\n\t";
				system("pause");
				cin.clear();
				cin.ignore();
				system("color 60");
			}
			system("cls");
		}
		
		socioEliminar>>s1.Nombre;
		
		while(!socioEliminar.eof()){
			socioEliminar>>s1.Apellido;
			socioEliminar>>s1.DNI;
			socioEliminar>>s1.Contacto;
			socioEliminar>>s1.Domicilio;
			socioEliminar>>s1.NroDomicilio;
			socioEliminar>>s1.TipoSocio;
			
			fflush(stdin);
		
			if(auxDNI == s1.DNI){
				bandera = true;
				
				if(bandera){
					cout<<"\n\t¿Estas seguro de eliminar el usuario?"<<endl;
					cout<<"\n\t1.SI\t2.NO"<<endl;
					cout<<"\n\tIngrese opcion: ";
					cin>>decision;
					if(decision != 1 || !decision){
						color(2);
						cout<<"\n\tOperacion cancelada. Volviendo al menu."<<endl;
						cout<<"\n\t";
						auxiliar<<s1.Nombre<<" "<<s1.Apellido<<" "<<s1.DNI<<" "<<s1.Contacto<<" "<<s1.Domicilio<<" "
						<<s1.NroDomicilio<<" "<<s1.TipoSocio<<endl;
						cin.clear();
						cin.ignore();
						system("pause");
					} else{
						color(2);
						cout<<"\n\tUsuario ELIMINADO\n"<<endl;
						cout<<"\tVolviendo al Menu Principal..."<<endl;
						cout<<"\n\t";
						system("pause");
					}
				}
			} else{
				auxiliar<<s1.Nombre<<" "<<s1.Apellido<<" "<<s1.DNI<<" "<<s1.Contacto<<" "<<s1.Domicilio<<" "
				<<s1.NroDomicilio<<" "<<s1.TipoSocio<<endl;
			}
			
			socioEliminar>>s1.Nombre;
		}
		
		if(!bandera){
			color(4);
			cout<<"\n\tEl usario ingresado no existe\n"<<endl;
			cout<<"\tVolviendo al Menu Principal..."<<endl;
			cout<<"\n\t";
			system("pause");
		}
		
		socioEliminar.close();
		auxiliar.close();
	} else{
		color(4);
		cout<<"\n\tError al abrir el archivo. Intente otra vez..\n"<<endl;
		cout<<"\tVolviendo al Menu Principal..."<<endl;
		cout<<"\n\t";
		system("pause");
	}
	
	remove("Socios.txt");
	rename("Auxiliar.txt", "Socios.txt");
}

void ingresoSocio(ifstream &socioIngreso){
	system("cls");
	bool bandera;
	int auxdni;
	
	ingresoBanner();
	
	socioIngreso.open("Socios.txt", ios::in);
	
	if(socioIngreso.is_open()){
		while(true){
			cout<<"\n\n\tIngrese DNI para ingresar al salon: ";
			cin>>auxdni;
			
			if(auxdni){
				cin.clear();
				cin.ignore();
				break;
			} else{
				color(4);
				cout<<"\n\tError. Vuelve a ingresar"<<endl;
				cout<<"\n\t";
				system("pause");
				system("cls");
				system("color 60");
				cin.clear();
				cin.ignore();
				ingresoBanner();
			}
			fflush(stdin);
		}
		
		socioIngreso>>s1.Nombre;
		
		while(!socioIngreso.eof()){
			socioIngreso>>s1.Apellido;
			socioIngreso>>s1.DNI;
			socioIngreso>>s1.Contacto;
			socioIngreso>>s1.Domicilio;
			socioIngreso>>s1.NroDomicilio;
			socioIngreso>>s1.TipoSocio;
			
			if(s1.DNI == auxdni){
				system("color a0");
				color(2);
				cout<<"\n\tIngreso correcto!"<<endl;
				cout<<"\n\tHola! "<<s1.Nombre<<" "<<s1.Apellido<<" hoy toca ENTRENAR!."<<endl;
				bandera = true;
				cout<<"\n\t";
				system("pause");
				break;
			} else{
				bandera = false;
			}
			
			socioIngreso>>s1.Nombre;
		}
		
		if(!bandera){
			system("color c0");
			color(4);
			cout<<"\n\tEl DNI ingresado no esta registrado en el Gimnasio.\n"<<endl;
			cout<<"\tVolviendo al Menu Principal..."<<endl;
			cout<<"\n\t";
			system("pause");
		}
	
		socioIngreso.close();
		
	} else{
		color(4);
		cout<<"\n\tError al abrir el archivo. Intente otra vez...\n"<<endl;
		cout<<"\tVolviendo al Menu Principal ... "<<endl;
		cout<<"\n\t";
		system("pause");
	}
}

bool verificar(int dni){
	ifstream leerSocio("Socios.txt", ios::in);
	
	leerSocio>>s2.Nombre;
	while(!leerSocio.eof()){
		leerSocio>>s2.Apellido;
		leerSocio>>s2.DNI;
		leerSocio>>s2.Contacto;
		leerSocio>>s2.Domicilio;
		leerSocio>>s2.NroDomicilio;
		leerSocio>>s2.TipoSocio;
		
		if(s2.DNI == dni){
			leerSocio.close();
			return false;
		}
		
		leerSocio>>s2.Nombre;
	}
	
	leerSocio.close();
	
	return true;
}

void color(int numero){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute(hConsole, numero);
}

bool cinValidar(){
	if(cin.fail()){
		cin.clear();
		cin.ignore();
		return true;
	} else{
		cin.clear();
		cin.ignore();
		return false;
	}
}
