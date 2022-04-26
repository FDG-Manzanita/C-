#include <iostream>

using namespace std;

int main(){
	int suma,a, base, altura,suma2;
	cout<<"Ingrese la base:"<< endl;
	cin>>base;
	cout<<"Ingrese la altura:"<<endl;
	cin>>altura;
	suma= base * altura;
	suma2= 2*(base+altura);
	cout<<"El area es:"<< suma<<endl;
	cout<<"El perimetro es:" << suma2<<endl;
	a=2**5;
	cout<< a <<endl;
	return 0;
}
