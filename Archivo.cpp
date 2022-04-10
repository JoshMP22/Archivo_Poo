#include "Estudiante.cpp"
#include <iostream>
#include <string.h>

using namespace std;

class Archivo:Estudiante{
	
	Estudiante estudiante= Estudiante();
			
	public: 
	
	FILE* archivo;
		
		void crear(){
		
		char continuar;
		archivo = fopen("Archivo.dat", "ab");
		int codigo, telefono;
		string nombre, apellido, direccion;
		
		do {
		fflush(stdin);				
		
		cout<<"\n                         *** INGRESAR NUEVO ESTUDIANTE *** \n"<<endl;
		cout<<"INGRESE CODIGO:";
		cin>>estudiante.codigo;
		cin.ignore();
		cout<<"INGRESE NOMBRES: ";
		getline(cin,nombre);
		strcpy(estudiante.nombre, nombre.c_str());
		cout<<"INGRESE APELLIDOS: ";
		getline(cin, apellido);
		strcpy(estudiante.apellido, apellido.c_str());
		cout<<"INGRESE DIRECCION: ";
		getline(cin,direccion);
		strcpy(estudiante.direccion, direccion.c_str());
		cout<<"INGRESE TELEFONO: ";
		cin>>estudiante.telefono;
		cin.ignore();
		
		fwrite(&estudiante, sizeof(Estudiante),1,archivo);
		
		cout<<"\n DESA AGREGAR OTRO ESTUDIANTE (s/n): ";
		cin>>continuar;
	
	}while (continuar == 's' || continuar == 'S');
	fclose(archivo);
				
	}
	
	void leer(){
	system("cls");
	archivo= fopen("Archivo.dat", "rb");
	
	if(!archivo){
		
		archivo= fopen("Archivo.dat", "a+w");
	}

	int id=0;
	
	fread(&estudiante, sizeof(Estudiante),1,archivo);
	
		cout<<"_______________________________________________________________________"<<endl;
		cout<<"ID"<<" | "<<"CODIGO"<<" | "<<"     NOMBRES      "<<" | "<<"        APELLIDOS    "<<" | "<<"     DIRECCION    "<<" | "<<"  TELEFONO"<<endl;
		do{
		cout<<"_______________________________________________________________________"<<endl;
		cout<<id<<" | "<<estudiante.codigo<<"       | "<<estudiante.nombre<<"      | "<<estudiante.apellido<<"      | "<<estudiante.direccion<<" | "<<estudiante.telefono<<endl;
		fread(&estudiante, sizeof (Estudiante),1,archivo);
		id++;
		
		}while (feof(archivo)==0);
		fclose(archivo);
		cout<<endl;
		
}

void actualizar (){
	
	archivo= fopen("Archivo.dat", "r+b");
	
	int id;
	
	string nombre, apellido, direccion;
	
	cout<<"INGRESE EL ID DEL ESTUDIANTE QUE DESEA MODIFICAR: ";
	cin>>id;
	
	fseek(archivo,id * sizeof(Estudiante),SEEK_SET);
	
	fflush(stdin);
	cout<<"\n              *** DATOS A MODIFICAR ***       \n";
	cout<<" INGRESE CODIGO: ";
	cin>>estudiante.codigo;
	cin.ignore();
	cout<<" INGRESE NOMBRES: ";
	getline(cin, nombre);
	strcpy(estudiante.nombre, nombre.c_str());
	cout<<" INGRESE APELLIDOS: ";
	getline(cin,apellido);
	strcpy(estudiante.apellido, apellido.c_str());
	cout<<" INGRESE DIRECCION: ";
	getline(cin, direccion);
	strcpy(estudiante.direccion, direccion.c_str());
	cout<<" INGRESE TELEFONO: ";
	cin>>estudiante.telefono;
	cin.ignore();
	
	fwrite(&estudiante, sizeof(Estudiante),1,archivo);
	fclose(archivo);
	system("cls");
	leer();
	cout<<"_________________________________________________________________________"<<endl;
	cout<<"************* MODIFICACION EXITOSA **************"<<endl;
	system("pause");
	
	
	
}


void eliminar(){

		FILE* archivo_temp=fopen("Temporal.dat","w+b"); 
		
		archivo=fopen("Archivo.dat","rb"); 	 
	
		int codigo; 
		Estudiante estudiante; 
		
	                      				                
		cout<<"INGRESE CODIGO DEL ESTUDIANTE A ELIMINAR: "<<endl; 
		cin>>codigo; 
	                                                                                
		while(fread(&estudiante,sizeof(Estudiante),1,archivo)){	
			
			if (codigo != estudiante.codigo) {
			fwrite(&estudiante,sizeof(Estudiante),1,archivo_temp); 
			}
			else{
				cout<<"\n                    ****** ARCHIVO ELIMINADO ****** \n";
				system("pause");
			}
			
			}
	                
		fclose(archivo_temp); 
		fclose(archivo); 
	
	remove("Archivo.dat");
	rename("Temporal.dat", "Archivo.dat");
	
	}
	
};


