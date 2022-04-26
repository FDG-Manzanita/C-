#include <iostream>
#include <cstdlib>
#define MAX 10

using namespace std;

struct Cola{
	int head, tail, cant;
	int elementos[MAX];
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
		cout << "\nEncolando numero " << num << "...";
		c.elementos[c.tail] = num;
		c.cant++;
		if(c.tail == MAX -1){
			c.tail = 0;
		}else{
			c.tail++;
		}
		
	}
}


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
		cout <<"\nDesencolando numero " << num << "...";
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

//int num_random{
//	cout << rand();}

int main(){
	Cola cola;
	crearCola(cola);
	int a,b;
	b=0;
	while(b<=10){
		a=rand();
		encolar(cola,a);
		b++;
	}
	verCola(cola);
}
