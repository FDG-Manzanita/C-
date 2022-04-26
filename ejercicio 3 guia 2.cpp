#include <iostream>

using namespace std;
void factorial(int );


int main(){
		int x,n;
	cout<<"		----Elija una opcion----"<<endl;
	cout<<"1.) Imprimir los n primeros multiplos de un numero ingresado por pantalla"<<endl;
	cout<<"2.) Factorial de n"<<endl;
	cout<<"Opcion elegida: ";
	cin>>x;
	switch(x){
		case 0:
			break;
		case 1:
			//funcion
		case 2:
			cout<<"\nDele un valor a n: ";
			cin>>n;
			factorial(n);
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
