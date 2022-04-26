#include <iostream>

#define CAPACIDAD 10
using namespace std;

struct empleado{
	int id;
	string nombre;
	string apellido;
	int edad;
};



struct nodo{
	empleado emp;	
	nodo* next;
};


void inicializar_tabla_hash(nodo*[]);
int funcion_hash(int id);
void insertar_hash(nodo*[], empleado);
void insertar_lista(nodo**, empleado);

void imprimir_hash(nodo*[]);
void imprimir_lista(nodo*);


int main(){
	nodo* tabla_hash[CAPACIDAD];
	
	inicializar_tabla_hash(tabla_hash);
	
	empleado e;
	
	cout << "ID: ";
	cin >> e.id;  //e.id = 12345;
	cout << "Nombre: ";
	cin >> e.nombre; //e.nombre = "Juan";
	cout << "Apellido: ";
	cin >> e.apellido;//e.apellido = "Perez";
	cout << "Edad: ";
	cin >> e.edad; //e.edad = 45;
	
	empleado e2;
	
	cout << "ID: ";
	cin >> e2.id;  //e.id = 12345;
	cout << "Nombre: ";
	cin >> e2.nombre; //e.nombre = "Juan";
	cout << "Apellido: ";
	cin >> e2.apellido;//e.apellido = "Perez";
	cout << "Edad: ";
	cin >> e2.edad; //e.edad = 45;
	
	//AGREGAR EMPLEADO A LA TABLA HASH
	insertar_hash(tabla_hash, e);
	insertar_hash(tabla_hash, e2);
	
	//IMPRIMIR TABLA HASH
	imprimir_hash(tabla_hash);
	
	
}


void inicializar_tabla_hash(nodo* tabla_hash[]){
	for(int i=0; i < CAPACIDAD ; i++){
		tabla_hash[i] = NULL;
	}
}

int funcion_hash(int id){
	return id%CAPACIDAD;
}

void insertar_hash(nodo* tabla_hash[], empleado nuevo){
	int indice = funcion_hash(nuevo.id);
	
	insertar_lista(&tabla_hash[nuevo.id],nuevo);
}

void insertar_lista(nodo **head, empleado nuevo){
	nodo* nuevo_nodo;
	nuevo_nodo = new nodo;
	
	nuevo_nodo->emp = nuevo;
	
	
	nuevo_nodo->next = *head;
	*head = nuevo_nodo;
}

void imprimir_hash(nodo* tabla_hash[]){
	for(int i=0; i < CAPACIDAD ; i++){
		cout << "\nTH[" << i << "] ->";
		imprimir_lista(tabla_hash[i]);
	}
}

void imprimir_lista(nodo *head){
	while( head != NULL){
		cout << head->emp.nombre << " " << head->emp.edad << " ->";
		head= head->next;
	}
	cout << "NULL";
}

