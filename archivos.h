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
void controlStock();
void altaStock(ofstream &stock);
void bajaStock(ifstream &bstock);
void modificacionStock(ifstream &mstock);
void verStock(ifstream &vstock);
int menuStock();
bool verificarStock(int codigo);
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


struct Articulo{
	string nombre;
	int codigo;
	int cantidad;
}a1,a2;

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

// ################## CONTROL STOCK ##############

/*
-> Funcion Control Stock
	> Alta stock
	> Baja Stock
	> Modificacion Stock
	> Ver Stock Total
	> Salir

*/

void controlStock() {
	int opcion;
	ofstream Escritura;
	ifstream Lectura;
	
	do{
		system("color 60");
		opcion = menuStock();
		
		switch(opcion){
			case 1:
				altaStock(Escritura);
			break;
			case 2:
				bajaStock(Lectura);
			break;
			case 3:
				modificacionStock(Lectura);
			break;
			case 4:
				verStock(Lectura);
			break;
			case 5:
				cout<<"\n\tSaliendo de Modulo Stock..."<<endl;
				cout<<"\t";
				system("pause");
			break;
			default:
				cout<<"\n\tEl numero ingresado no coincide con niguno del Menu."<<endl;
				cout<<"\t";
				system("pause");
			break;
		}
		
		
	}while(opcion != 5);

}

void altaStock(ofstream &stock){
	system("cls"); //limpieza de consola
	bool bandera = true;
	int contador = 0;
	
	stock.open("Stock.txt", ios::out | ios::app);
	
	while(bandera){
		altaStockBanner();
		fflush(stdin);
		
		cout<<"\n\tCodigo: ";
		cin>>a1.codigo;
		cout<<"\tNombre: ";
		fflush(stdin);
		getline(cin, a1.nombre);
		cout<<"\tCantidad: ";
		cin>>a1.cantidad;
		
		if(a1.codigo){
			contador++;
		}

		if(a1.cantidad){
			contador++;
		} 
		
		if(contador != 2){
			color(4);
			cout<<"\n\n\tIngrese solo numeros en Codigo y Cantidad."<<endl;
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
	
	if(verificarStock(a1.codigo)){
		stock<<a1.codigo<<" "<<a1.nombre<<" "<<a1.cantidad<<endl;
		color(2);
		cout<<"\n\tAGREGADO CON EXITO!"<<endl;
		cout<<"\n\tVolviendo al menu..."<<endl;
		cout<<"\n\t";
		system("pause");
		stock.close();	
	}else{
		color(4);
		cout<<"\n\tEse Codigo ya se encuentra registrado."<<endl;
		cout<<"\n\tVolviendo al menu..."<<endl;
		cout<<"\n\t";
		system("pause");
		stock.close();
	}
}

void bajaStock(ifstream &bstock){
	system("cls");
	bool bandera = false;
	int auxStock, decision;
	
	bstock.open("Stock.txt", ios::in);
	ofstream auxiliar("Auxstock.txt", ios::out | ios::app);
	
	if(bstock.is_open()){
		while(true){
			system("cls");
			bajaStockBanner();
			fflush(stdin);
			cout<<"\n\tIngrese Codigo: ";
			cin>>auxStock;
		
			if(!cin.fail()){
				cin.clear();
				cin.ignore();
				break;
			} else{
				color(4);
				cout<<"\n\tError. Vuelve a ingresar Codigo Stock."<<endl;
				cout<<"\n\t";
				system("pause");
				cin.clear();
				cin.ignore();
				system("color 60");
			}
			system("cls");
		}
		
		bstock>>a1.codigo;
		while(!bstock.eof()){
			bstock>>a1.nombre;
			bstock>>a1.cantidad;
			
			fflush(stdin);
		
			if(auxStock == a1.codigo){
				bandera = true;
				
				cout<<"\n\t------------------------------"<<endl;
				cout<<"\tCodigo: "<<a1.codigo<<endl;
				cout<<"\tNombre: "<<a1.nombre<<endl;
				cout<<"\tCantidad: "<<a1.cantidad<<endl;
				cout<<"\t------------------------------"<<endl;
				
				
				if(bandera){
					cout<<"\n\t\t¿Estas seguro de eliminar completamente el Stock?"<<endl;
					cout<<"\n\t\t1.SI\t2.NO"<<endl;
					cout<<"\n\t\tIngrese opcion: ";
					cin>>decision;
					if(decision != 1 || !decision){
						color(2);
						cout<<"\n\tOperacion cancelada. Volviendo al menu."<<endl;
						cout<<"\n\t";
						auxiliar<<a1.codigo<<" "<<a1.nombre<<" "<<a1.cantidad<<endl;
						cin.clear();
						cin.ignore();
						system("pause");
					} else{
						color(2);
						cout<<"\n\tCodigo Stock ELIMINADO\n"<<endl;
						cout<<"\tVolviendo al Menu..."<<endl;
						cout<<"\n\t";
						system("pause");
					}
				}
			} else{
				auxiliar<<a1.codigo<<" "<<a1.nombre<<" "<<a1.cantidad<<endl;
			}
			
			bstock>>a1.codigo;
		}
		
		if(!bandera){
			color(4);
			cout<<"\n\tEl codigo ingresado no existe\n"<<endl;
			cout<<"\tVolviendo al Menu. "<<endl;
			cout<<"\n\t";
			system("pause");
		}
		
		bstock.close();
		auxiliar.close();
	} else{
		color(4);
		cout<<"\n\tError al abrir el archivo. Intente otra vez..\n"<<endl;
		cout<<"\tVolviendo al Menu Principal..."<<endl;
		cout<<"\n\t";
		system("pause");
	}
	
	remove("Stock.txt");
	rename("Auxstock.txt", "Stock.txt");
}

void modificacionStock(ifstream &mstock){
	system("cls");
	modificarStockBanner();
	bool bandera = false, bandera2 = true;
	int auxCodigo, contador = 0;
	
	cin.ignore();
	
	mstock.open("Stock.txt", ios::in);
	ofstream auxiliar("Auxstock.txt", ios::out | ios::app);
	
	if(mstock.is_open()){
		while(true){
			system("cls");
			modificarStockBanner();
			fflush(stdin);
			cout<<"\n\tIngrese Codigo: ";
			cin>>auxCodigo;
		
			if(!cin.fail()){
				cin.clear();
				cin.ignore();
				break;
			} else{
				color(4);
				cout<<"\n\tError. Vuelve a ingresar Codigo."<<endl;
				cout<<"\n\t";
				system("pause");
				cin.clear();
				cin.ignore();
				system("color 60");
			}
			system("cls");
		}
		
		mstock>>a1.codigo;
		while(!mstock.eof()){
			mstock>>a1.nombre;
			mstock>>a1.cantidad;
		
			if(auxCodigo == a1.codigo){
				bandera = true;
				
				while(bandera2){
					fflush(stdin);
					cout<<"\n\tCodigo: ";
					cin>>a2.codigo;
					if(a2.codigo){
						contador++;
					}
					cin.ignore();
					cout<<"\tNombre: ";
					getline(cin, a2.nombre);
					
					fflush(stdin);
					
					cout<<"\tCantidad: ";
					cin>>a2.cantidad;
					
					if(a2.cantidad){
						contador++;
					}
					
					fflush(stdin);
					
					if(contador != 2){
						contador = 0;
						color(4);
						cout<<"\n\n\tIngrese solo numeros en Codigo y Cantidad."<<endl;
						cout<<"\n\tVuelve a intentar. "<<endl;
						cout<<"\n\t";
						system("pause");
						system("cls");
						cin.clear();
						system("color 60");
						modificarStockBanner();
					} else{
						contador = 0;
						bandera2= false;
					}
				}

				auxiliar<<a2.codigo<<" "<<a2.nombre<<" "<<a2.cantidad<<endl;
				color(2);
				cout<<"\n\tStock MODIFICADO! "<<endl;
				cout<<"\n\t";
				system("pause");
			} else{
				auxiliar<<a1.codigo<<" "<<a1.nombre<<" "<<a1.cantidad<<endl;
			}
			mstock>>a1.codigo;
		}
		
		if(!bandera){
			color(4);
			cout<<"\n\tEl codigo ingresado no existe.\n"<<endl;
			cout<<"\tVolviendo al Menu Principal..."<<endl;
			cout<<"\n\t";
			system("pause");
		}
	
		
		mstock.close();
		auxiliar.close();
		
	} else{
		color(4);
		cout<<"\n\tError al abrir el archivo. \n"<<endl;
		cout<<"\tVolviendo al Menu Principal..."<<endl;
		cout<<"\n\t";
		system("pause");
	}
	
	remove("Stock.txt");
	rename("Auxstock.txt", "Stock.txt");
}

void verStock(ifstream &vstock){
	system("cls");
	totalStockBanner();
	
	vstock.open("Stock.txt",ios::in);
	
	if(vstock.is_open()){
		cout<<"\n\t"<<setw(7)<<left<<"Codigo"<<setw(20)<<left<<"Nombre"<<setw(8)<<left<<"Cantidad"<<endl;
		
		//Linea punteada, visualizacion tabla.
		cout<<"\t";
		for(int i = 0 ; i < 35 ; i++){
			cout<<"-";
		}		
		cout<<"\n";
		
		vstock>>a1.codigo;
		while(!vstock.eof()){
			vstock>>a1.nombre;
			vstock>>a1.cantidad;
						
			cout<<"\t"<<setw(7)<<left<<a1.codigo<<setw(20)<<left<<a1.nombre<<setw(4)<<left<<a1.cantidad<<endl;

			vstock>>a1.codigo;
		}
	
		vstock.close();
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

bool verificarStock(int codigo){
	ifstream verStock("Stock.txt", ios::in);
	
	verStock>>a2.codigo;
	while(!verStock.eof()){
		verStock>>a2.nombre;
		verStock>>a2.cantidad;
		
		if(a2.codigo == codigo){
			verStock.close();
			return false;
		}
		
		verStock>>a2.codigo;
	}
	
	verStock.close();
	
	return true;
}

int menuStock(){
	int x;
	system("cls");
	stockBanner();
	
	cout<<"\n\n\t1. Alta Stock"<<endl;
	cout<<"\t2. Baja Stock"<<endl;
	cout<<"\t3. Modificacion Stock"<<endl;
	cout<<"\t4. Ver Stock Total"<<endl;
	cout<<"\t5. Salir"<<endl;
	cout<<"\n\n\tDigite una opcion: ";
	cin>>x;
	
	return x;
}

/* ############ FIN MODULO STOCK ###############3*/
///////////////////////////s

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
