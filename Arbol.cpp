#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};

void menu();
Nodo *crearNodo(int,Nodo*);
void insertarNodo(Nodo*&, int,Nodo*);
void mostrarArbol(Nodo*, int);
bool busqueda(Nodo*, int);
int Pares(Nodo*,int);
int Pares2(Nodo*,int);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);
void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destruirNodo(Nodo*);
Nodo* arbol = NULL;


int alturaAB(Nodo* arbol){
    int AltIzq, AltDer;

    if(arbol==NULL){
	
        return -1;
    
	}else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

int main()
{
	int contador = 1;
    menu();
}
//Función del menu
void menu() {
    int dato, opcion,contador= 0;

    do {
        cout << "\t.:MENU:." << endl;
        cout << "1.Insertar un nuevo nodo" << endl;
        cout << "2.Mostrar el arbol" << endl;
        cout << "3.Buscar un elemento en el arbol" << endl;
        cout << "4.Recorrer el arbol en PreOrden" << endl;
        cout << "5.Recorrer el arbol en InOrden" << endl;
        cout << "6.Recorrer el arbol en PostOrden" << endl;
        cout << "7.Eliminar un nodo del arbol" << endl;
        cout << "8.Pares"<<endl;
        cout << "9.Salir" << endl;
        cout << "10.Largo"<< endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            cout << "Digite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato,NULL);
            cout << "\n";
            system("pause");
            break;
        case 2:
            cout << "Aqui tienes el arbol impreso de forma recursiva: " << endl;
            mostrarArbol(arbol, contador);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout <<"\n" <<"Introduce el dato que estas buscando ";
            cin >> dato;
            if (busqueda(arbol, dato) == true) {
                cout << "\n" << "El elemento " << dato << " si se encuentra en el arbol" << endl;
            }
            else {
                cout << "\n" << "El elemento " << dato << " no se encuentra en el arbol" << endl;
            }
            system("pause");
            break;
        case 4:
            cout << "\nRecorrido en PreOrden: " << endl;
            preOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        case 5:
            cout << "\nRecorrido en InOrden: " << endl;
            inOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        case 6:
            cout << "\nRecorrido en PostOrden: " << endl;
            postOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
        case 7:
            cout << "\nDigite el numero que desea eliminar:";
            cin >> dato;
            eliminar(arbol, dato);
            cout << "\n";
            system("pause");
            break;
        case 8:
        	int num = 0;
        	int htotal=0;
        	htotal=(Pares(arbol,num))+(Pares2(arbol,num));
        	cout<<"La cantidad de pares es:"<<h<<endl;
        	system("pause");
        	
        case 9:
        	int alto;
            alto = alturaAB(arbol);
            cout << " La altura es : "<< alto << endl;
            break;
    }
        system("cls");
    } while (opcion != 10);
}
//Función para crear un nuevo nodo
Nodo* crearNodo(int n,Nodo* padre) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}
//Función para insertar nodos en el árbol
void insertarNodo(Nodo *&arbol, int n,Nodo*padre) {
    if (arbol == NULL) { //Si el arbol está vacío
        Nodo *nuevo_nodo = crearNodo(n,padre);
        arbol = nuevo_nodo;
    }
    else { // Si el arbol tiene un nodo o más
        int valorRaiz = arbol->dato; // Obtener valor de la raíz
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n,arbol);
        }
        else {
            insertarNodo(arbol->der, n,arbol);
        }
    }
}
//Función para mostrar el arbol
void mostrarArbol(Nodo* arbol, int cont) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout <<"    ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}
// Función para buscar un dato en el arbol
bool busqueda(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return false;
    }
    else if (arbol->dato == n){
        return true;
    }
    else if (n <arbol->dato) {
        return busqueda(arbol->izq, n);
    }
    else {
        return busqueda(arbol->der, n);
    }
}
// Funcion para recorrido en profundidad - PreOrden
void preOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
// Funcion para recorrido en profundidad - InOrden
void inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}
// Funcion para recorrido en profundidad - PostOrden
void postOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}
// Funcion para eliminar un nodo del arbol
void eliminar(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return;
    }
    else if (n < arbol->dato) { //Si el valor es menor
        eliminar(arbol->izq, n); // Busca por la izquierda
    }
    else if (n > arbol->dato) { // Si el valor es mayor
        eliminar(arbol->der, n); //Busca por la derecha
    }
    else {
        eliminarNodo(arbol);
    }
}
// Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo* nodoEliminar) {
    if (nodoEliminar->izq && nodoEliminar->der) {
        Nodo* menor = minimo(nodoEliminar->der); // Primero te vas hacia la derecha
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    }
    else if (nodoEliminar->izq) {
        reemplazar(nodoEliminar, nodoEliminar->izq);
        destruirNodo(nodoEliminar);
    }
    else if (nodoEliminar->der) {
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else { // No tiene hijos
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}
// Función para determinar el nodo más izquierdo posible
Nodo* minimo(Nodo* arbol) {
    if (arbol == NULL) {
        return NULL;
    }
    if (arbol->izq) { // Si tiene hijo izquierdo
        return minimo(arbol->izq); // retorna el hijo izquierdo
    }
    else { // Si no tiene hijo izquierdo (significa que él es el más izquierdo)
        return arbol; // se retorna a sí mismo
    }
}
// Función para reemplazar dos nodos
void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
    if (arbol->padre) {
        //arbol->padre hay que asignarle su nuevo hijo
        if (arbol->dato == arbol->padre->izq->dato) {
            arbol->padre->izq = nuevoNodo;
        }
        else if (arbol->dato == arbol->padre->der->dato) {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        // Procedemos a asignarle su nuevo padre
        nuevoNodo->padre = arbol->padre;
    }
}
// Función para destruir un nodo
void destruirNodo(Nodo* nodo) {
    nodo->izq = NULL;
    nodo->der = NULL;
    delete nodo;
}

int Pares(Nodo* arbol,int n){
 
    if (arbol == NULL) 
		{  
		return n;		
		}else{
		
	if (arbol->dato%2==0) 
		{
		n++;
		}
	(Pares(arbol->izq,n));
	
	
	}
}
	int Pares2(Nodo* arbol,int n)
 {
 	
    if (arbol == NULL) 
		{  
		return n;		
		}else{
		
	if (arbol->dato%2==0) 
		{
		n++;
		}
	
	(Pares(arbol->der,n));
	
	}
}



