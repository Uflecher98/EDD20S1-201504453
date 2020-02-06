
#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void Insertar(Nodo *&, int);
void Mostrar(Nodo *);
void Buscar(Nodo *, int);
void Eliminar (Nodo *&, int);


  Nodo *lista = NULL;

int main (){
  
    int elemento;
    int resp;
    do{
      

      std::cout<< "\t MENU \n";

      cout<<"1. Ingresar elemento\n";
      cout<<"2. Eliminar elemento\n";
      cout<<"3. Buscar elemento\n";
      cout<<"4. Mostrar\n";
      cout<<"5. Salir\n";
      cout<<"Respuesta: ";
      cin>>resp;
      
      
      switch(resp){
          case 1:
            cout<<" Ingresae elemento";
            cin>>elemento;
            Insertar(lista,elemento);
            cout<<"\n";
             
          break;

          case 2: 
          cout<<"Ingrese elemento a eliminar: ";
          cin>>elemento;
          Eliminar(lista, elemento);
          cout<<"\n";
          break;
          case 4:
             Mostrar(lista);
             cout<<"\n";
             
             break;
          case 3:
          cout<<"\nIngrese numero a buscar";
          cin>>elemento;
          Buscar(lista, elemento);
          cout<<"\n";
          break;
      }
     
    } while (resp != 5);
    
    Mostrar(lista);
    
    return 0;
}

void Insertar(Nodo *&lista, int n ){
    Nodo *nuevo = new Nodo();
    nuevo -> dato = n;

    Nodo *a1 = lista;
    Nodo *a2;

    while ((a1 != NULL) && (a1->dato < n)){
        a2 =  a1;
        a1 = a1->siguiente;
    }

    if (lista== a1){
        lista = nuevo;
    }
    else {
        a2->siguiente=nuevo;
    }

       nuevo -> siguiente = a1;
}


void Mostrar(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout<<actual->dato<<" -> ";
        actual = actual->siguiente;
    }
}

void Buscar(Nodo *lista, int n){
    bool x = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual->dato <= n)){
        if (actual -> dato == n){
            x= true;
        }
        actual = actual ->siguiente;
    }

    if (x==true){
        cout<<"Elemento "<<n<<" Se encontró";

    } else {
        cout<<"Elemento no Se encontró";
    }
}

void Eliminar(Nodo *&lista, int n){
    if (lista != NULL ){
        Nodo *aux1;
        Nodo *ante = NULL;
        aux1 = lista;
        
        while ((aux1 !=NULL)&&(aux1->dato != n)){
            ante = aux1;
            aux1 = aux1->siguiente;
        }

        if (aux1 == NULL){
            cout<<"El elemento no existe";

        }else if (ante == NULL){
            lista = lista -> siguiente;
            delete aux1;

        } else {
            ante ->siguiente= aux1->siguiente;
            delete aux1;
        }
    }
}









