
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct Nodo{
    int carnet;
    string nombre;
    Nodo *siguiente;
};

void Insertar(Nodo *&, int, string);
void Mostrar(Nodo *);
void Buscar(Nodo *, int);
void Eliminar (Nodo *&, int);


  Nodo *lista = NULL;

int main (){
  
    int elemento;
    string nombre;
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
            cout<<" Ingresae carné";
            cin>>elemento;
            cout<<" Ingresar nombre";
            cin>>nombre;
            Insertar(lista,elemento, nombre);
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
          cout<<"\nIngrese carnet a buscar";
          cin>>elemento;
          Buscar(lista, elemento);
          cout<<"\n";
          break;
      }
     
    } while (resp != 5);
    
    Mostrar(lista);
    
    return 0;
}

void Insertar(Nodo *&lista, int n, string nombre){
    Nodo *nuevo = new Nodo();
    nuevo -> carnet = n;
    nuevo ->nombre = nombre;
    Nodo *a1 = lista;
    Nodo *a2;

    while ((a1 != NULL) && (a1->carnet < n)){
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
        cout<<actual->carnet<<", "<<actual->nombre<<" --->";
        actual = actual->siguiente;
    }
}

void Buscar(Nodo *lista, int n){
    bool x = false;

    Nodo *actual = new Nodo();
    actual = lista;

    while((actual != NULL) && (actual->carnet <= n)){
        if (actual -> carnet == n){
            x= true;
            cout<<"El nombre es: "<<actual->nombre;
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
        
        while ((aux1 !=NULL)&&(aux1->carnet != n)){
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









