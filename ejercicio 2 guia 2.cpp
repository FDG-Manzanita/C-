#include <iostream>

using namespace std;

int main(){
	int suma,n1,contador;
	cout<<"Ingrese el numero: ";
	cin >>  n1;
	contador=1;
	while (contador <= n1){
		suma+=contador;
		contador++;
	}
	cout<<"La suma es: "<<suma<<endl;
	
}
