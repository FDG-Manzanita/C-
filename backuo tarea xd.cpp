int main(){
	int a;
	a=1;
	while (a>0){int x,num,dato;
	nodo*lista=NULL;
	cout<<"			Elija una opcion:"<<endl;
	cout<<"1.) Agregar un número al inicio de la lista"<<endl;
	cout<<"2.) Agregar un número al final de la lista"<<endl;
	cout<<"3.) Eliminar primer elemento de la lista "<<endl;  ///EN CASO DE QUE NO HAYAN ELEMENTOS PARA ELIMINAR MANDAR MENSAJE
	cout<<"4.) Borrar toda la lista"<<endl;
	cout<<"5.) Mostrar la cantidad de elementos que tiene la lista"<<endl;
	cout<<"6.) Imprimir la lista por pantalla"<<endl;
	cout<<"7.) Invertir la lista e imprimirla"<<endl;
	cout<<"8.) Invertir la lista mediante un subproceso recursivo"<<endl;
	cout<<"9.) Salir\n\n";
	cout<<"Coloque el numero del comando:";
	cin>>x;
	if (x>9 or x<1){
		cout<<"Comando invalido.";
	}
	switch(x){
		case 1:
			
			break;
		case 2:
			cout<<"¿Que numero desea ingresar al inicio de la lista?"<<endl;
			cin>>num;
			agregar(&lista,num);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			listar(lista);
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			a=0;
			break;
	}
	}
}
