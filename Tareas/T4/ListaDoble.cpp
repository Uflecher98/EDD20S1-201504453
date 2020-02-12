

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

struct Nodo{
    int carnet;
    string nombre;
    Nodo *siguiente;
    Nodo *anterior;
} ;

void Insertar(int, string);
void Mostrar(Nodo *);
void Buscar(Nodo *, int);
void Eliminar (Nodo *&, int);


  Nodo *primero = NULL;
  Nodo *ultimo = NULL;



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
            Insertar(elemento, nombre);
            cout<<"\n";  
          break;

          case 2: 
          cout<<"Ingrese elemento a eliminar: ";
          cin>>elemento;
          Eliminar(primero, elemento);
          cout<<"\n";
          break;

          case 3:
          cout<<"\nIngrese carnet a buscar";
          cin>>elemento;
          Buscar(primero, elemento);
          cout<<"\n";
          break;

          case 4:
             Mostrar(primero);
             cout<<"\n";
             break;
     
      }
     
    } while (resp != 5);
    
    Mostrar(primero);
    
    return 0;
}

void Insertar(int n, string nombre){
    Nodo *nuevo = new Nodo();
    nuevo -> carnet = n;
    nuevo ->nombre = nombre;


    if (primero==NULL){
        primero = nuevo;
        ultimo = nuevo;
        primero ->anterior = NULL;
        ultimo -> siguiente = NULL;
    } else
    {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            nuevo->siguiente = NULL;
            ultimo = nuevo;
    }
    
}


void Mostrar(Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual != NULL){
        cout<<"["<<actual->carnet<<", "<<actual->nombre<<"] <--->";
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
            lista ->anterior = NULL;
            delete aux1;

        } else {
            ante ->siguiente= aux1->siguiente;
            aux1->siguiente->anterior = ante;
            delete aux1;
        }
    }
}





