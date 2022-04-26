#include <iostream>
using namespace std;

void f(int,int,int,int);

int main(){
	int n1,n2,num,contador;
	cout<<"Ingrese un numero: ";
	cin>>num;
	n1=1;
	n2=1;
	contador=3;
	if (num ==2){
		cout<<n1<<endl;
		cout<<n2<<endl;
	}else{ 
		if(num==1){
			cout<<n1;		
		}else{
			if (num>2){
				cout<<n1<<endl;
				cout<<n2<<endl;
				f(n1,n2,num,contador);
			}
		}
	}
}
void f(int n1,int n2,int num,int contador){
	if (contador<=num){
	n1=n1+n2;
	cout<<n1<<endl;
	contador++;
	f(n2,n1,num,contador);
	}
}
