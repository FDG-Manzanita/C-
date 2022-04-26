#include <iostream>
#include <cstdlib>
#define MAX 10
#define LARGO 10

using namespace std;




struct Nodo {
    int dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
};

struct Cola{
	int head, tail, cant;
	int elementos[MAX];
};
struct Pila{
	int tope;
	int elementos[LARGO];
};
void crearCola(Cola &c){
	c.head=0;
	c.tail=0;
	c.cant=0;
}

bool llena(Cola c){
//	return c.cant == MAX;	
	if(c.cant == MAX){
		return true;
	}else{
		return false;
	}
}

bool vacia(Cola c){
	return c.cant == 0;
}

void encolar(Cola &c, int num){
	if(llena(c)){
		cout << "\nLa cola esta llena";
	}else{
		c.elementos[c.tail] = num;
		c.cant++;
		if(c.tail == MAX -1){
			c.tail = 0;
		}else{
			c.tail++;
		}
		
	}
}

Nodo *crearNodo(int,Nodo*);
void insertarNodo(Nodo*&, int,Nodo*);
void mostrarArbol(Nodo*, int);
void preOrden(Nodo*);
Nodo* arbol = NULL;

int desencolar(Cola &c){
	if(vacia(c)){
		cout << "\nLa cola esta vacia";
	}else{
		//desencolar
		
		int num = c.elementos[c.head];
		c.cant--;
		if(c.head == MAX -1){
			c.head = 0;
		}else{
			c.head++;
		}
		//cout <<"\nDesencolando numero " << num << "...";
		return num;
	}
}

void verCola(Cola c){
	int i = c.head;
	int cont = 0;
	cout << "\nCOLA: |" ;
	while(cont < c.cant){
		cout << c.elementos[i] << "|";
		if(i == MAX-1){
			i=0;
		}else{
			i++;
		}
		cont++;
	}
}
int pop(Pila &p){
	if(p.tope != -1){
		return p.elementos[p.tope--];
	}else{
		cout << "La pila esta vacia";
	}
}
void push(Pila &p, int num){
	if(p.tope != LARGO-1){
		p.tope++;
		p.elementos[p.tope] = num;		
	}else{
		cout << "La pila esta llena";
	}
}

Cola cola_invertir(Cola c){
	Pila Pila1;
	int x1,s,se,a;
	s=1;
	se=1;
	a= c.cant;
	while(s<=a){
	x1= desencolar(c);
	push(Pila1,x1);
	s++;
	}
	while(se<=a){
	x1=pop(Pila1);
	encolar(c,x1);
	se++;
	}
	return(c);
}
void Consultar(Cola c){
	Cola a=cola_invertir(c);
	int b=desencolar(a);
	encolar(a,b);
	cout<<"El ultimo numero es: "<<b<<endl;
}
//int num_random{
//	cout << rand();}


int main(){
	Cola cola,c;
	crearCola(cola);
	int dato,contador= 0;
	Pila Pila1;
	crearCola(c);
	int a,x;
	while (x!=9){
	cout<<"	\n	:::::::MENU:::::::"<<endl;
	cout << ":::::::COLAS::::::"<<endl;
	cout << "1.- Colocar elemento en la cola" <<endl;
	cout << "2.- Ver cola"<<endl;
	cout << "3.- Eliminar 1 elemento"<<endl;
	cout << "4.- Invertir"<<endl;
	cout << "5.- Consultar el ultimo elemento de la cola"<<endl;
	cout << ":::::ARBOL:::::"<<endl;
	cout << "6.- Insetar elemento al arbol"<<endl;
	cout << "7.- Mostrar arbol"<<endl;
	cout << "8.- Imprimir en PreOrder"<<endl;
	cout << "9.- Salir"<<endl;
	cout << "Elija la opcion: " ;
	cin>> x;
	switch (x){
	
		case 1:
			cout<<"Que elemento colocara: ";
			cin>>a;
			encolar(cola,a);
			break;
		case 2:
			verCola(cola);
			break;
		case 3:
			desencolar(cola);
			break;
		case 4:
			cola=cola_invertir(cola);
			break;
		case 5:
			Consultar(cola);
			break;
		case 6:
			cout << "Digite un numero: ";
            cin >> dato;
            insertarNodo(arbol, dato,NULL);
            cout << "\n";
            system("pause");
            break;
		case 7:
			cout << "Aqui tienes el arbol impreso de forma recursiva: " << endl;
            mostrarArbol(arbol, contador);
            cout << "\n";
            system("pause");
            break;
		case 8:
			cout << "\nRecorrido en PreOrden: " << endl;
            preOrden(arbol);
            cout << "\n\n";
            system("pause");
            break;
		
}
}
}

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
