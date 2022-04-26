#include <iostream>
#include <conio.h>
struct nodo{
     int nro;
     struct nodo *sgte;
            struct nodo *ant;
    };
typedef struct nodo *lisdo;
void insertain(lisdo &,int);
void insertafi(lisdo &,int);
int busca(lisdo,int,int &);
void elimini(lisdo &);
void elimlista(lisdo &);
void elimelem(lisdo &,int);
void verlis(lisdo);
void invertir(lisdo);
void media(lisdo);
void sure(lisdo);
void asen(lisdo &);
void insertain(lisdo &lista,int elem)
{
 lisdo l;
 l=new(struct nodo);
 l->nro=elem;
 if(lista==NULL)
   {
    lista=l;
    lista->sgte=NULL;
    lista->ant=NULL;
   }
 else
   {
    l->sgte=lista;
    l->ant=NULL;
    lista->ant=l;
    lista=l;
   }
}
void insertafi(lisdo &lista,int elem)
{
 lisdo l,aux;
 l=new(struct nodo);
 l->nro=elem;
 aux=lista;
 if(lista==NULL)
   {
    lista=l;
    lista->sgte=NULL;
    lista->ant=NULL;
   }
 else
   {
    while(aux->sgte!=NULL)
    {
     aux=aux->sgte;
    }
    l->sgte=NULL;
    aux->sgte=l;
    l->ant=aux;
   }
}
int busca(lisdo lista,int elem,int &pos)
{
 //int b;
 pos=0;
 lisdo aux;
 aux=lista;
 while(aux->sgte!=NULL)
 {
  if(aux->nro==elem)
    {
     return 1;
    }
  aux=aux->sgte;
  pos++;
 }
 return 0;
}
void elimini(lisdo &lista)
{
 if(lista!=NULL)
   {
    lista=lista->sgte;
    cout<<"!! primer elemento eliminado ¡¡";
   }
 else
   cout<<"¡¡¡ lista sin elementos !!!";
}
void elimlista(lisdo &lista)
{
 if(lista!=NULL)
   {
    lista=NULL;
    cout<<"!! lista bacia ¡¡";
   }
 else
   cout<<"!! lista sin elementos ¡¡"; 
}
void elimelem(lisdo &lista,int elem)
{
 lisdo aux;
 aux=lista;
 if(lista!=NULL)
   {
    while(aux!=NULL)
    {
     if(aux->nro==elem)
       {
 if(aux->sgte==NULL&&aux->ant==NULL)
   {
    aux=NULL;
           lista=aux;
   }
 else
   {
    if(aux->ant==NULL)
      {
              //lista->sgte->ant=NULL;
       lista=lista->sgte;
      }
    else
      if(aux->sgte==NULL)
        {
  aux->ant->sgte=NULL;
                aux=aux->ant;
        }
    else
      {
       aux->ant->sgte=aux->sgte;
       aux->sgte->ant=aux->ant;
              aux=aux->ant;
      }
   }
       }
    aux=aux->sgte;
    }
    cout<<"!! elemento eliminado ¡¡";
   }
 else
   cout<<"!! lista sin elementos ¡¡";
}
void verlis(lisdo lista)
{
 lisdo aux;
 aux=lista;
 if(lista!=NULL)
   {
    while(aux!=NULL)
    {
     cout<nro<<" - ";
     aux=aux->sgte;
    }
   }
 else
   cout<<"!! lista sin elementos ¡¡";
}
void invertir(lisdo lista)
{
 lisdo aux;
 aux=lista;
 if(lista!=NULL)
   {
    while(aux->sgte!=NULL)
    {
     aux=aux->sgte;
    }
    while(aux!=NULL)
    {
     cout<nro<<" - ";
     aux=aux->ant;
    }
   }
 else
   cout<<"!! sin elementos ¡¡";
}
void media(lisdo lista)
{
 int m,n=0,i=0,v;
 lisdo aux;
 aux=lista;
 while(aux->sgte!=NULL)
 {
  aux=aux->sgte;
  n++;
 }
 while(aux->ant!=NULL)
 {
  aux=aux->ant;
  i++;
  if(i==n/2)
    v=aux->nro;
 }
  cout<<v;
}
void sure(lisdo lista)
{
 lisdo aux1,aux2;
 aux1=lista;
 aux2=aux1->sgte;
 while(aux1!=NULL)
 {
  aux1->nro=((aux1->nro)+2);
  aux1=aux2->sgte;
  aux2->nro=((aux2->nro)-2);
  aux2=aux1->sgte;
 }
}
 void asen(lisdo &lista)
 {
  int may;
  lisdo aux1,aux2;
  if(lista!=NULL)
    {
     aux1=lista;
     aux2=lista->sgte;
     while(aux1!=NULL)
     {
      aux2=aux1->sgte;
      while(aux2!=NULL)
      {
       if(aux1->nro>aux2->nro)
  {
   may=aux1->nro;
   aux1->nro=aux2->nro;
          aux2->nro=may;
  }
       aux2=aux2->sgte;
      }
      aux1=aux1->sgte;
     }
    }
 }

void main()
{
 lisdo lista=NULL;
 int elem,pos,x,y,i;
 char opc;
 do
 {
  clrscr();
  cout<<"**********MENU********\n";
  cout<<"1.-INSERTAR ELEMENTO AL INICIO\n";
  cout<<"2.-INSETAR ELEMENTO AL FINAL\n";
  cout<<"3.-BUSCAR ELEMENTO\n";
  cout<<"4.-ELIMINAR PRIMER ELEMENTO\n";
  cout<<"5.-ELIMINAR ELEMENTO\n";
  cout<<"6.-ELIMINAR LISTA\n";
  cout<<"7.-VER ELEMENTOS DE LA LISTA\n";
  cout<<"8.-LISTA ORDENADA ASENDENTEMENTE\n";
  cout<<"9.-SALIR\n";
  cout<<"INGRESE SU OPCION: ";opc=getche();
  switch(opc)
 {
  case '1':clrscr();
     cout<<"numeros de elementos: ";cin>>x;
    for(i=0;i<x;i++)
      {
       cout<<i+1<<".-elemento: ";cin>>y;
                     insertain(lista,y);
      }
    break;
  case '2':clrscr();
    cout<<"numero de elementos: ";cin>>x;
    for(i=0;i<x;i++)
      {
       cout<<i+1<<".-elemento: ";cin>>y;
                     insertafi(lista,y);
      }
    break;
  case '3':clrscr();
    cout<<"Ingrese elemento a buscar: ";cin>>x;
    y=busca(lista,x,pos);
    if(y==1)
      {
                     cout<<"Elemento en la posicion "<<pos;
      }
    else
      cout<<"Elemento no existe ";
    break;
  case '4':clrscr();
    elimini(lista);
    break;
  case '5':clrscr();
    cout<<"Elementos a buscar";cin>>x;
    elimelem(lista,x);
    break;
  case '6':clrscr();
    elimlista(lista);
    break;
 case '7':clrscr();
   cout<<"******LISTA INVERTIDA********\n";
   verlis(lista);
   cout<<"nn*******LISTA DE ELEMENTOS********\n";
   invertir(lista);
   cout<<"n********LA MEDIA ES **********\n";
   media(lista);
   sure(lista);
   cout<<"n******LISTA DE ELEMENTOS********\n";
   verlis(lista);
   break;
  case '8':clrscr();
    cout<<"******LISTA DE ELEMENTOS********\n";
    verlis(lista);
                  cout<<endl<<endl;
    cout<<"******LISTA DE ELEMENTOS ORDENADOS********\n";
    asen(lista);
    verlis(lista);
    break;                                
 }
  getch();
 }while(opc!='9');
}

