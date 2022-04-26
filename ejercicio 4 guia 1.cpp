#include <iostream>
#include <math.h>

using namespace std;

int main(){
	float radio,longitud,pi,area,volumen,a,v;
	cout<<"Introduzca el radio:"<<endl;
	cin>>radio;
	pi=3.14;
	longitud= 2*pi*radio;
	a=pow(radio,2);
	area= pi*a;
	v=pow(radio,3);
	volumen=(4/3)*pi*v;
	cout<<"La longitud de la circunferencia es:"<<longitud<<endl;
	cout<<"El area de la circunferencia es:"<<area<<endl;
	cout<<"El volumen de la circunferencia es:"<<volumen<<endl;
	return 0;
}
