#include <iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *next;
};

void agregar(nodo **, int);
void listar(nodo *);
void cantidad(nodo *);
void eliminarLista(nodo *&,int &);
void invertirLista(nodo *);
void elim(nodo *&);

int main(){
	int dato;
	int x,a,n;
	a=1;
	nodo* pBuscado;
	nodo*lista=NULL;
	while(a!=0){
	
	cout<<"\n		----Elija una opcion----"<<endl;
	cout<<"1.) Agregar un número al inicio de la lista"<<endl; /// AL INICIO
	cout<<"2.) Agregar un número al final de la lista"<<endl;
	cout<<"3.) Eliminar primer elemento de la lista "<<endl;  ///EN CASO DE QUE NO HAYAN ELEMENTOS PARA ELIMINAR MANDAR MENSAJE
	cout<<"4.) Borrar toda la lista"<<endl;
	cout<<"5.) Mostrar la cantidad de elementos que tiene la lista"<<endl;
	cout<<"6.) Imprimir la lista por pantalla"<<endl;
	cout<<"7.) Invertir la lista e imprimirla"<<endl;		/// esta claro
	cout<<"8.) Invertir la lista mediante un subproceso recursivo"<<endl;		//Igual pero no se como hacerla
	cout<<"9.) Salir\n\n";
	cout<<"Opcion elegida: ";
	cin>>x;
	
	switch(x){
		case 9:
			a=0;
			cout<<"Muchas gracias por usar nuestro programa ATTE Grupo F UwU";
			break;
		case 2:
			cout<<"Coloque el numero que quiere ingresar:";
			cin>>n;
			agregar(&lista,n);
			break;
		case 3:
			elim(lista);
			break;
		case 4:
			eliminarLista(lista,n);
			break;
		case 5:
			cantidad(lista);
			break;
		case 6:
			listar(lista);
			break;
		case 7:
			
			break;
	}
}

}

void agregar(nodo **head, int dato){
	nodo *nuevo;
	nuevo = new nodo;
	
	nuevo->dato = dato;
	nuevo->next = NULL;
	
	nuevo->next = *head;
	*head = nuevo;
}

void listar(nodo *head){
	
	nodo *p;
	cout << "Lista: ";
	for(p=head; p!=NULL; p=p->next){
		cout << p->dato << " ->";
	}
	
	cout << "\n";
}

void cantidad (nodo *head){
	int cont;
	nodo *p;
	cont=0;
	for(p=head; p!=NULL; p=p->next){ 
		cont++;
		
	}

	cout <<"La cantidad de elementos en la lista es: "<< cont;
}

void eliminarLista(nodo *&lista,int &n){
	while(lista !=NULL ){
			nodo *aux = lista;
			n = aux -> dato;
			lista = aux ->next;
			delete aux;
	}
}

void elim(nodo *&lista){
	if(lista!=NULL){
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = lista;
		while(aux_borrar -> next != NULL){
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> next;
			if (aux_borrar == NULL){
				lista = lista -> next;
				delete anterior;
				listar(lista);                                                              
				break;
			}
		}
	}
	else
	cout<<"No hay elementos"<<endl;
}

