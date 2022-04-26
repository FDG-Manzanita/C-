#include <iostream>

using namespace std;

int main(){
	int b,k,m,g;
	cout<<"Ingrese los Gigabytes a convertir:"<<endl;
	cin>>g;
	m= g * 1024;
	k= m * 1024;
	b=k*1024;
	cout<<"Los megasbytes son:"<<m<<endl;
	cout<<"Los kilobytes son:"<<k<<endl;
	cout<<"Los bytes son:"<<b<<endl;
	return 0;
}
