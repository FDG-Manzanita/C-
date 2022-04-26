#include <iostream>
#include <cstdlib>
#define LARGO 10

using namespace std;

struct Pila{
	int tope;
	int elementos[LARGO];
};


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
	cout << "\nPILA: " << endl;
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
/Pila Pila1,Pila2;
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

int main(){
	Pila mipila,Pila1,Pila2;
	int x;
	cout<<"\n		----Elija una opcion----"<<endl;
	cout<<"1.) Ejercicio 2"<<endl; /// AL INICIO
	cout<<"2.) Ejercicio 4"<<endl;
	cout<<"3.) Salir\n\n";
	cout<<"Opcion elegida: ";
	cin>>x;
	switch(x){
		case 1:
			Pila mipila;
			crearPila(mipila);
			int a,b;
			b=1;
			while(b<=10){
			a=rand();
			push(mipila,a);
			b++;
			}
			ejer2(mipila);
}
}
