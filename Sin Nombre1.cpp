#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *next;
};

void eliminarLista(nodo *&,int &);
void agregar(nodo **, int);
void listar(nodo *);
nodo* buscar(nodo *, int);

int main(){
	int valorBuscado;
	nodo* pBuscado;
	
	nodo *lista = NULL;
	
	agregar(&lista,2);
	listar(lista);
	agregar(&lista,3);
	listar(lista);
	
	cout << "Valor a buscar: ";
	cin >> valorBuscado;
	
	pBuscado = buscar(lista, valorBuscado);
	
	if(pBuscado == NULL){
		cout << valorBuscado << " no se encuentra en la lista";
	}else{
		cout << pBuscado->dato << " existe en el listado";
	}
	

}

nodo* buscar(nodo *head, int dato){
	while(head != NULL){
		if(head->dato == dato){
			return head;
		}else{
			head = head->next;
		}
	}
	return NULL;
}


void listar(nodo *head){
	
	nodo *p;
	cout << "Lista: ";
	for(p=head; p!=NULL; p=p->next){
		cout << p->dato << " ->";
	}
	
	cout << "\n";
}

void agregar(nodo **head, int dato){
	nodo *nuevo;
	nuevo = new nodo;
	
	nuevo->dato = dato;
	nuevo->next = NULL;
	
	nuevo->next = *head;
	*head = nuevo;
}
void eliminarLista(Nodo *&lista,int &n){
	Nodo *aux = lista
	n = aux -> dato;
	lista = aux ->siguiente;
	delete aux;
}

