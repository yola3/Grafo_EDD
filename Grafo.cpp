#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//se declara los tipos de variables a utilizar
int opc;
int volver;
int valor;

//vamos a agegrar funciones para administra el grafo



struct nodo{ // se crea una estructura de tipo nodo y tendra dos punteros
	int numero;//nombre del vertice o nodo
	struct nodo *sgte; // creamos una estructura para la adyacente 
	struct arista *ady;//estructura de la primera arista del nodo
	
	
};


typedef struct nodo *Tnodo; // definimos el tipo de datos de las variables
Tnodo puntero;//instanciamos el nodo declardo anteriormente al puntero base


struct arista { // creamos la estructura arista
	struct nodo *destino; // creamos la estructura destino
	struct arista *sgte; 
	
};

typedef struct arista *Tarista; // distanciar la tarista para que apunte ala arista, para verficar cuantas aristas tiene el grafo


void insertar_nodo (){// funcion para insertar nodo
	//instanciamos el nuevo nodo
	Tnodo t,nuevo=new struct nodo;
	cout<<"ingrese un numero para el nodo: "<<endl;// ingresamos el numero en el nodo

	cin>>nuevo->numero;	//captura el nuevo numero ingresado en el nodo
	nuevo->sgte=NULL; // aasignamosel puntero en NULL
	nuevo->ady=NULL;
	
	if(puntero==NULL){//si el puntero esta vacio lo llevamos puntero 
		puntero=nuevo;
		cout<<"Nodo ingresado."<<endl; // mensaje indicando que ya se ingreso un numero
	}else{//si no debe recorrer este puntero para preguntar
		
		//por la variable siguiente que este vacia por la variable siguiente que este vacia 
		t=puntero;
		while (t->sgte!=NULL){// recorremos el ciclo while la variable siguiente para checar si esta vacia
		    t = t->sgte; // se pregunta con el siguiente hastaque encontremos nulo
		}
		t->sgte=nuevo; // se ingresa un nuevo nodo
		cout<<"Nodo ingresado."<<endl;    
	}	
}

void agregar_arista (Tnodo &aux, Tnodo &aux2, Tarista &nuevo){//funcion  para agregar aristas, esta funcion recibe prametros a utlizar para almacenar grafo
	
	Tarista q;//con el puntero de la arista inicializamos otro puntero que se utilizara internamente

	if (aux->ady==NULL){//preguntamos si esta vacio pra ingresar un nuevo nodo
		aux->ady=nuevo; // si el puntero esta vacio agregamos un nuevo nodo a la adyacente
		nuevo->destino=aux2;// aqui asignamos ala adyacente al puntero auxiliar
	}else{//si no  debemos recorrerlo por que ya insertamos una arista en esa posicion 
		
		q=aux->ady; // utilizamos otra arista para asignar
		//recorremos la arista 
		while (q->sgte!=NULL){//recorremos la arista la arista con un ciclo while
			q=q->sgte;
		}
	
		nuevo->destino=aux2,	//cuando encontramos la que esta  libre la asignamos y agregamos en el nuevo destino lo llevamos en el auxiliar dos
		q->sgte=nuevo;// aqui organimos las variables y al distancia que ingresa la arista
		cout<<"Arista ingresado"<<endl;	
	}
	
}


void insertar_arista(){//funcion para insertar la arista
	
	int ini,fin;// se declara la variable de tipo entero para capturar el vertice inicio y final.
	
	Tarista nuevo=new struct arista;// instanciamos una arista que es la que vamos a ingresar
	
	Tnodo aux, aux2;// instanciamos lo dos nodos auxiliar para poner el nodo inicial y el nodo final
	
	
	if (puntero==NULL){//si el puntero esta vacio es por que no se ha inseratdo ningun nodo 
		cout<<"No hay grafo"<<endl;// aqui se manda un mensaje diciendo que no hay ningun valor en el grafo.
		return;
	}
	
	nuevo->sgte=NULL;//de lo contrario instancia el nodo siguiente null
	
	cout<<"Ingrese el nodo del inicio: "<<endl; 
	cin>>ini;// se captura el nodo incial 
	cout<<"Ingrese el nodo del final: "<<endl;
	cin>>fin;// capturamos el nodo final
	
	aux=puntero;// este nodo auxiliar lo llevamos al puntero
	aux2=puntero;// se verifica si el auxliar dos esta vacio
	
	while (aux2!=NULL){// con un ciclo while verificamos si el auxiliar dos tiene algo
		
		if (aux2->numero==fin){//verificamos si ese algo es el puntero finaly si es entonces se sale
		
			break;
		}
	
		aux2=aux2->sgte;	//de lo contrario le llevamos el valor de siguiente
	}

	while (aux!=NULL){	//aqui ingresamos la arista al primer puntero
		
		if (aux->numero==ini){//si la variable auxiliar es igual a la arista del puntero 1 entonces agrega la arista
			
			agregar_arista(aux,aux2,nuevo);// aqui le mandamos los dos punteros auxiliar y el nuevo 
			return;
		}
	
		aux=aux->sgte;	//de lo contrario va con el siguiente
	}	
}

void mostrargrafo() {// funcion para mostrar el grafo en forma adyacente
	Tnodo ptr;// se instancia el puntero nodo
	Tarista ar;// se instancia el puntero arista y la asignamos
	
	ptr=puntero;//al puntero del nodo lo llevamos al que tenemos inicialmente
	cout<<"Nodo:Arista"<<endl;
	//si esta vacia
	while (ptr!=NULL){//si el puntero esta vacio muestra el dato puntero
		
		cout<<"  "<<ptr->numero<<"|";// aqui se imprime el grafo
		if(ptr->ady!=NULL){
			ar=ptr->ady;
		
			while(ar!=NULL){// recorremos con el ciclo para ver que cantidad de arista tiene el grafo
				cout<<"  "<<ar->destino->numero;
				ar=ar->sgte;
			}
		}
	
		ptr=ptr->sgte;//despues pasa el siguiente puntero y repite el proceso a ver si tiene aristas
		cout<<endl;
	}	 
}

//esta funcion mustra las aristas de un nodo en especifico
void mostrar_aristas(){
	
	Tnodo aux;//inicializamos nodo y la asignamos
	Tarista ar;// inicializamos arista y la asigamos
	int var;
	cout <<"Mostrar arista del nodo"<<endl; // mandamos a imprimir las aristas del nodo
	cout<<"Ingrese el nodo"<<endl; // solicitamos el nodo desde el teclado un valor que queremos ver 
	cin>>var;// se manda imprimir la variable que se solicito
	
	aux=puntero;//capturamos el puntero 
	while(aux!=NULL){// con ciclo while recorremos la auxiliar
		
		if (aux->numero==var){//preguntamos si es un puntero ya definido
			if(aux->ady==NULL){// y si esta vacio esta nos manda un mensaje
			cout<<"El nodo no tiene Aristas"<<endl;
			return;
		    }else{//por el contario si el puntero tiene arista la imprime 
			
		     	 
			    cout<<"Nodo:Arista"<<endl;
			    cout<<"  "<<aux->numero<<"|";
		    	ar=aux->ady;// aqui imprime los valore
			    
			    while(ar!=NULL){//se recorre con un ciclo while para saber cuantas aristas tiene el nodo
			 	    cout<<ar->destino->numero<<" ";
			 	    ar=ar->sgte;
			    }
			    cout<<endl;// finaliza 
			    return; 
		    }
	    }else{
		   aux=aux->sgte; //de lo contarrio, si no es nodo que encontramos esto nos mandara al siguiente
        }
	}
}		
	

// creamos una funcion para crear un menu de opciones
int crear_menu(){
	cout<<"introduzca el numero de la opcion que desea realizar"<<endl;
	cout<<"1. Insertar nodo"<<endl;
	cout<<"2. Insertar Arista"<<endl;
	cout<<"3. Mostrar Grafo"<<endl;
	cout<<"4. Ver Arista de la posicion requerida"<<endl;
	cout<<"5. Salir"<<endl;
} 

int main(){

	puntero=NULL;	//instanciamos el puntero principal en nulo
	
	//ciclo para ejecutar opciones del menu
	volver= 1;// esta se declara para que al insertar un valor entonces para continuar insertando tenemos que introducir el numero 1
	while(volver==1){// hace un ciclo repetitivo
		//se inicializa el menu
		 crear_menu();//se inicializa el menu
		 cin>>opc;// se lee la opcion
		
		switch(opc){// utilizamos switch para las opciones
		case 1:
		    	insertar_nodo();//opcion de la funcion insertar nodo en el grafo
				break;
		case 2:
			    
				insertar_arista();//opcion de la funcion insertar arista en el grafo
				break;
		case 3:
			   
				mostrargrafo(); //opcion de la funcion para mostra el grafo
				break;
		case 4:
			    //mostrar un nodo y sus aristas adyacentes
				mostrar_aristas();//opcion de le funciom mostrar un nodo requerida  y sus aristas 
				break;
		case 5:
			    
			   cout<<"salir"<<endl;// opcion para salir 
			   return 0;
			   break;
				
		default:
		   cout<<"opcion invalida"<<endl;// captura el error		
		}
		cout<<"para volver al menu principal, presione el numero 1\n";// para que nos vuelve aprecer el menu despues de insertar un valor tenemos que presionar el numero 1
		cin>>volver; 
	}
return 0;
}



