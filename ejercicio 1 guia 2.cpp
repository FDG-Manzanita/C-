#include <iostream>

using namespace std;

int main(){
	int n1,n2;
	cout<<"Ingrese el primer numero"<<endl;
	cin >>  n1;
	cout<<"Ingrese el segundo numero"<<endl;
	cin >>  n2;
	if(n1>n2){
		cout<<"El numero mayor es: "<< n1<<endl;
	}else{
		if (n1<n2){
			cout<< "El numero mayor es: "<<n2<<endl;
		}else{
			if (n1==n2){
				cout<< "Los numeros "<< n1<<" y "<<n2<<" son iguales"<<endl;
			}
		}
	
	}
}
