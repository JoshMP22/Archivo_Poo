#include "Archivo.cpp"
#include <iostream>
#include <string.h>

using namespace std; 

int main(){
	
	Archivo arc= Archivo();
		
	int op;
	
	do{
	system("cls");
	arc.leer();
	cout<<"__________________________________________________________________________________"<<endl;
	cout<<"\n               *** MENU ***\n";
	cout<<" 1. INGRESAR ESTUDIANTE"<<endl;
	cout<<" 2. ACTUALIZAR DATOS DE ESTUDIANTE"<<endl;
	cout<<" 3. ELIMINAR ESTUDIANTE"<<endl;
	cout<<" 0. SALIR"<<endl;
	cin>>op;
	if (op==1){
	arc.crear();
	}
	else if (op==2){
	arc.actualizar();
	}
	else if (op==3){
	arc.eliminar();
	}
	
	
	}while (op!=0);
	
	
	
	
	
	
	return 0;
}
