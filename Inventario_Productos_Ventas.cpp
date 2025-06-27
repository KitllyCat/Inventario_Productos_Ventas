/*Inventario de Productos y Ventas
Objetivo: Desarrollar un programa que permita registrar, listar, buscar, actualizar y eliminar productos, así como gestionar las ventas.
Requisitos:
• Define una estructura Producto con los campos: nombre (cadena), precio (flotante).
• Define una estructura Venta con los campos: idVenta (entero), producto (cadena), cantidad (entero), precioTotal (flotante).
• Implementa un menú con las siguientes opciones:
	A: Registrar un nuevo producto.
	B: Listar los productos registrados.
	C: Buscar un producto por nombre.
	D: Actualizar los datos de un producto.
	E: Eliminar un producto.
	F: Registrar una venta.
	G: Listar las ventas realizadas.
	H: Calcular el total de ventas realizadas.
	S: Salir del programa.
• El menú debe estar ciclado y permitir volver al menú principal después de cada opción.*/
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
const int tam=99;
int cantPro=0;
int indice;

struct Producto{
    string nombre;
    float precio;
};
Producto prod[tam];
struct Venta{
    int idVenta;
    string producto;
    int cant;
    float precioT;
};
Venta vent[tam];

void registrarNuevoProducto(){
	if(cantPro>=tam){
        cout<<"Ya no se pueden agregar más productos. Límite alcanzado~!!!";
        Sleep(2000);
        system("cls");
        return;
    }
	Producto aniadir;
	
	cout<<"----- Añadir Nuevo Producto -----"<<endl<<endl;
	cout<<"Ingrese el nombre del producto a añadir: ";
	getline(cin, aniadir.nombre);
	int salirE=0;
	do{
		cout<<endl<<"Ingrese el precio del producto: ";
   		cin>>aniadir.precio;
    	if(cin.fail()||aniadir.precio<=0){
            cout<<"El precio tiene que ser solo con números!!!"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
            salirE=0;
        }else{
        	salirE=1;
        	break;
        }
    }while(salirE!=1);
	cin.ignore();
    prod[cantPro]=aniadir;
    cantPro++;
	cout<<endl<<"El producto se añadio correctamente, regresando al menu..."<<endl;
    Sleep(2000);
    system("cls");
}

void listarProductos(){
	if(cantPro==0){
        cout<<"No existen productos que se puedan mostrar!!!";
        Sleep(2000);
        system("cls");
        return;
    }
    for(int i=0;i<cantPro;i++){
    	cout<<i+1<<"._ Producto:"<<endl<<endl;
        cout<<"Nombre del Producto :"<<prod[i].nombre<<endl;
        cout<<"Precio actual: "<<prod[i].precio<<endl;
        cout<<endl<<"----------------------------------"<<endl<<endl;
	}
    cout<<endl<<"Presione enter para volver al menu principal...";
	cin.get();
	system("cls");
}

int main(){	
	SetConsoleOutputCP(CP_UTF8);
	int opcion;
	int salir=0;
	do{
		do{
			cout<<"-----Inventario de Productos y Ventas-----"<<endl<<endl;
			cout<<"Elija la opcion que desea realizar en el programa:"<<endl;
			cout<<"1) Registrar un nuevo producto"<<endl;
			cout<<"2) Listar todos los productos registrados"<<endl;
			cout<<"3) Buscar un producto por su nombre"<<endl;
			cout<<"4) Actualizar los datos de un producto"<<endl;
			cout<<"5) Eliminar un producto"<<endl;
			cout<<"6) Registrar una nueva venta"<<endl;
			cout<<"7) Listar las ventas ya realizadas"<<endl;
			cout<<"8) Calcular el total de ventas realizadas"<<endl;
			cout<<"9) Salir del programa"<<endl;
			cout<<"Selecione su opcion: ";
			cin>>opcion;
			cin.ignore();
			cout<<endl;
			if(cin.fail()||opcion<=0){
	            cout<<"La opcion debe ser un número!!!"<<endl;
	            cin.clear();
	            cin.ignore(1000, '\n');
	            Sleep(1500);
				system("cls");
				salir=0;
	        }else{
	        	salir=1;
	        	break;
	        }
		}while(salir!=1);
		
		switch(opcion){
			case 1:{
			system("cls");
			registrarNuevoProducto();
			break;
			}
			case 2:{
			system("cls");
			listarProductos();
			break;
			}
			case 3:{
			//buscarProductoNombre();
			break;
			}
			case 4:{
			//actualizarDatosProducto();
			break;
			}
			case 5:{
			//eliminarProducto();
			break;
        	}
			case 6:{
			//registrarNuevaVenta();
			break;
			}
			case 7:{
			//listarVentasRealizadas();
			break;
			}
			case 8:{
			//calcularTotalVentas();
			break;
			}
			case 9:{
				system("cls");
				cout<<"Saliendo del programa..."<<endl;
				break;
			}
			default:{
				cout<<"Opción invalida!!! Intente de nuevo..."<<endl;
				Sleep(1500);
				system("cls");
				break;
			}			
		}
	}while(opcion!=9);
	return 0;
}