#include <iostream>

using namespace std;

bool esPrimo(int numero);
int main(){
	int n1,n2;
	cout<<"Ingrese el numero:"<<endl;
	cin >>  n1;
	bool hola=esPrimo(n1);
	cout<<hola;
}
bool esPrimo(int numero) {
  if (numero == 0 || numero == 1){
  	return false;
  }
  if (numero == 4){
   return false;
	}
  for (int x = 2; x < numero / 2; x++) {

    if (numero % x == 0){ 
		return false;
	}
  }
  return true ;
}
