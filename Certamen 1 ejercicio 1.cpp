#include <iostream> 
#include <cstdlib>

using namespace std;
struct nodo{
	int dato;
	nodo *next;
};

void factorial(int );
void multiplos(int,int);
void AgregarRandom(nodo**,int);
void listar(nodo *);
int buscarlista(nodo *, int );
void promediar(nodo *);


///Ejercicio 1
int main(){
		int x,n,m,a;
	a=1;
	while(a!=0){
	
	cout<<"\n		----Elija una opcion----"<<endl;
	cout<<"0.) Salir"<<endl;
	cout<<"1.) Imprimir los n primeros multiplos de un numero ingresado por pantalla"<<endl;
	cout<<"2.) Factorial de n"<<endl;
	cout<<"Opcion elegida: ";
	cin>>x;
	switch(x){
		case 0:
			a=0;
			break;
		case 1:
			cout<<"\nDele un valor a n: ";
			cin>>n;
			cout<<"\nDele una cantidad de multiplos: ";
			cin>>m;
			multiplos(n,m);
			break;
		case 2:
			cout<<"\nDele un valor a n: ";
			cin>>n;
			factorial(n);
			break;
		case 3:
			cout<<"Opcion no valida";
			a=0;
			break;
	}
}
}
void factorial(int n){
		int suma,produto,contador;
		suma=1;
		contador=1;
		while (n>= contador){
			suma=contador*suma;
			contador++;
		}
		cout<<"Resultado de "<<n<<" factorial es: "<<suma<<endl;

}
void multiplos(int n,int m){
	int contador,a;
	contador=1;
	while(contador<=m){
		a=contador*n;
		contador++;
		cout<<a<<endl;
		}
}

/*
Ejercicio 2
La funcion "f" pide como parametros 2 numeros los cuales son 25 para "num" y 5 para "div",
luegos estos pasan por un if el cual verifica si "num" es mayor que 1 para luego ver el resto de la division entre 25 y 5,y como este da 0 se muestra en pantalla "5",
luego se llama a si misma con con una division entre 25/5 siento esta 
la nueva variable "num" y div que es 5 sigue siendo 5,quedando como "num"=5 y "div"=5
Ahora se repite lo del inicio,entra al if ya que num>1,se verifica el resto de la division y esta da 0 y muestra en pantalla "5",
se llama a si misma la funcion con la modificacion del parametro "num" ahora siendo 5/5 (o sea 1) y div se sigue quedando igual,
al llamarse de nuevo a si misma con "num=1" y "div=5" no entra al if ya que "num" no es mayor a 1 y se queda en un bucle 
aumentando en 1 a "div" sin final y como no tiene ninguna linea entremedio para poder separar los valores mostrados en pantalla se muestran juntos
mostrando en pantalla:
55
*/
/*
Efercicio 3,4,5 y 6
 




int main(){
	int dato;
	int x,a,n;
	a=1;
	nodo* pBuscado;
	nodo*lista=NULL;
	while(a!=0){
	
	cout<<"\n		----Elija una opcion----"<<endl;
	cout<<"0.) Salir"<<endl;
	cout<<"1.) Agregar un valor random a la lista"<<endl;
	cout<<"2.) Buscar un valor y mostrar su posicion (Recordad que -1 significa que no esta en la lista)"<<endl;
	cout<<"3.) Promediar los valores de la lista"<<endl;
	cout<<"4.) Mostrar lista"<<endl;
	cout<<"Opcion elegida: ";
	cin>>x;
	
	switch(x){
		case 0:
			a=0;
			cout<<"Muchas gracias por usar mi programa ATTE Benjamin Ramirez UwU";
			break;
		case 1:
			cout<<"Cuantos nodos desea agregar: ";
			cin>>n;
			AgregarRandom(&lista,n);
			break;
		case 2:
			cout << "Valor a buscar: ";
			cin >> dato;
			cout<<"El valor solicitado esta en la posicion: "<<buscarlista(lista,dato);
			break;
		case 3:
			promediar(lista);
			break;
		case 4:
			listar(lista);
			break;
	}
}

}



void AgregarRandom(nodo **head,int n){
	int dato,cont;
	cont=1;
	while(n>=cont){
		dato=rand();
	nodo *nuevo;
	nuevo = new nodo;
	
	nuevo->dato = dato;
	nuevo->next = NULL;
	
	nuevo->next = *head;
	*head = nuevo;
	cont++;
	}
}
void listar(nodo *head){
	
	nodo *p;
	cout << "Lista: ";
	for(p=head; p!=NULL; p=p->next){
		cout << p->dato << " ->";
	}
	
	cout << "\n";
}
int buscarlista(nodo *lista, int n){
	int cont;
	cont=1;
	nodo *actual=new nodo();
	actual=lista; 
	
	while(actual != NULL){
		if(actual->dato == n){
			
			return cont;
		}else{
			actual = actual-> next;
			cont++;
		}
	}
	return -1;
	}

void promediar (nodo *head){
	float final=0,promedio=0;
	int cont;
	nodo *p;
	cont=0;
	for(p=head; p!=NULL; p=p->next){
		promedio+= p->dato;
		cont++;
		
	}
	final= promedio / cont;
	cout <<"El promedio de la lista es: "<< final;
}
*/
