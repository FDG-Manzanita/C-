/*
EJERCICIO 1
a)El problema esta en esta linea "insertar_lista(&tabla_hash[nuevo.id],nuevo);"
b)se solucionaria cambiando nuevo.id por "pos" ya que asi llama a la funcion_hash,la cual hace que se pueda dar la clasificacion dentro de la tabla hash.
*/
#include <iostream>
#include <cstdlib>
#define LARGO 10

using namespace std;

struct Pila{
	int tope;
	int elementos[LARGO];
};
struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};

int Pares(Nodo*,int);
int Pares2(Nodo*,int);

Nodo *crearNodo(int,Nodo*);
void insertarNodo(Nodo*&, int,Nodo*);



void crearPila(Pila &p){
	p.tope = -1;
}


void push(Pila &p, int num){
	if(p.tope != LARGO-1){
		p.tope++;
		p.elementos[p.tope] = num;		
	}else{
		cout << "La pila esta llena";
	}
}

void verPila(Pila p){
	cout << "\nPILA BASE: " << endl;
	for(int i=p.tope; i>=0; i--){
		cout << "|" << p.elementos[i] << "|"<< endl;
	}
}

int pop(Pila &p){
	if(p.tope != -1){
		return p.elementos[p.tope--];
	}else{
		cout << "La pila esta vacia";
	}
}
void verPila1(Pila p){
	cout << "\nPILA 1: " << endl;
	for(int i=p.tope; i>=0; i--){
		cout << "|" << p.elementos[i] << "|"<< endl;
	}
}
void verPila2(Pila p){
	cout << "\nPILA 2: " << endl;
	for(int i=p.tope; i>=0; i--){
		cout << "|" << p.elementos[i] << "|"<< endl;
	}
}
void ejer2(Pila p){
Pila Pila1,Pila2;
crearPila(Pila2);
crearPila(Pila1);
verPila(p);
int c=1;	
	while(c<=5){
		int x1 = pop(p);
		push(Pila1,x1);
		int x2 = pop(p);
		push(Pila2,x2);
		c++;
	}
	verPila1(Pila1);
	verPila2(Pila2);}
Nodo* crearNodo(int n,Nodo* padre) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->padre = padre;

    return nuevo_nodo;
}
void insertarNodo(Nodo *&arbol, int n,Nodo*padre) {
    if (arbol == NULL) {
        Nodo *nuevo_nodo = crearNodo(n,padre);
        arbol = nuevo_nodo;
    }
    else { 
        int valorRaiz = arbol->dato; 
        if (n < valorRaiz) {
            insertarNodo(arbol->izq, n,arbol);
        }
        else {
            insertarNodo(arbol->der, n,arbol);
        }
    }
}
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

int Pares2(Nodo* arbol,int n) {
 	
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



//Ejercicios 2,4 y 5


int main(){
	Nodo* arbol = NULL;
	Pila pilab,Pila1,Pila2;
	int x;
	cout<<"\n		----Elija una opcion----"<<endl;
	cout<<"1.) Ejercicio 2"<<endl; 
	cout<<"2.) Ejercicio 4"<<endl;
	
	cout<<"Opcion elegida: ";
	cin>>x;
	switch(x){
		case 1:
			Pila pilab;
			crearPila(pilab);
			int a,b;
			b=1;
			while(b<=10){
			a=rand();
			push(pilab,a);
			b++;
			}
			ejer2(pilab);
		case 2:
		int sa;
	do{
		
		cout << "\t.:MENU:." << endl;
        cout << "1.Insertar un nuevo nodo" << endl;
        cout << "2.Mostrar el arbol" << endl;
        cout << "3.Pares"<<endl;
        cout << "4.Salir" << endl;
        cout << "Opcion: ";
        cin >> sa;
		switch (sa) {
        	case 1:
        		int dato;
            	cout << "Digite un numero: ";
            	cin >> dato;
            	insertarNodo(arbol, dato,NULL);
            	cout << "\n";
            	break;
        	case 2:
        		int contador;
            	cout << "Aqui tienes el arbol impreso de forma recursiva: " << endl;
            	mostrarArbol(arbol, contador);
            	cout << "\n";
            	break;
        	case 3:
        		int n,h;
        		n=0;
        		h=0;
        		h=(Pares(arbol,n))+(Pares2(arbol,n));
        		cout<<"La cantidad de pares es:"<<h<<endl;
			}	
	}while(sa!=4);
			
}
}

/*
EJERCICIO 3
A) el Nodo 15 esta en la profundida: 1
B) Ordenado en post orden seria: 4, 7, 5, 9, 8, 14, 13, 17, 15, 10
*/
