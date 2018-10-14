/*Este programa es una lista doblemente enlazada que utiliza 
los tipos de datos char e int para manejar los datos que se 
usen a lo largo del programa.

Aquí se dividen tres estrucutras con un tipo de dato cada una y sus 
correspondientes funciones para el manejo de datos.

Cada estructura es un nodo que manejara los tipos de datos incluidos en la estructura original disco.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nomDisco{
	char dato[30];
	struct nomDisco* next;
	struct nomDisco* back;
	
}nomDisco;

nomDisco* primero = NULL;
nomDisco* ultimo = NULL;

void insertarNodoS();
void desplegarListaPUS();
void modificarNodoS();
void eliminarNodoS();

void insertarNodoS(){
	nomDisco* nuevo = malloc(sizeof(nomDisco));
	
	// printf("Ingresa la cadena que tendrá el nuevo nodo: ");
	scanf(" %[^\n]s", nuevo->dato);

	if(primero==NULL){
		primero=nuevo;
		primero->next=NULL;
		primero->back=NULL;
		ultimo=primero;
	} else{
		ultimo->next=nuevo;
		nuevo->next=NULL;
		nuevo->back=ultimo;
		ultimo=nuevo;
	}

	printf("Datos ingresados con éxito\n\n");
}

void desplegarListaPUS(){
	nomDisco* actual = malloc(sizeof(nomDisco));
	actual = primero;
	if(primero!=NULL){
		while(actual!=NULL){
			printf("%s",actual->dato);
			printf(",  ");
			actual=actual->next;

		} printf("\n");
	} else{
		printf("La lista está vacía\n");
	}
}


void modificarNodoS(){
	nomDisco* actual = malloc(sizeof(nomDisco));
	actual = primero;
	char nodoBuscado[30];
	int encontrado=0;
	// printf("Ingresa la cadena de nodo a buscar para modificarla: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				printf("El disco (%s) fue encontrado\n", nodoBuscado);
				printf("Ingrese el nuevo nombre: ");
				scanf(" %[^\n]s",actual->dato);
				printf("Modificación exitosa\n");
				encontrado=1;
			}
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Nodo no encontrado\n");
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}

void eliminarNodoS(){
	nomDisco* actual = malloc(sizeof(nomDisco));
	actual = primero;
	nomDisco* anterior = malloc(sizeof(nomDisco));
	anterior=NULL;
	char nodoBuscado[30];
	int encontrado=0;
	// printf("Ingresa la cadena de nodo a eliminar: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				if (actual==primero)
				{
					primero=primero->next;
					primero->back=NULL;

				} else if (actual==ultimo)
					{
						anterior->next=NULL;
						ultimo=anterior;
					} else
						{
							anterior->next=actual->next;
							actual->next->back=anterior;
						}
				printf("Disco eliminado\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Disco no encontrado\n");
		} else{
			free(anterior);
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



typedef struct artista{
	char dato[30];
	struct artista* next;
	struct artista* back;
	
}artista;

artista* primero2 = NULL;
artista* ultimo2 = NULL;

void insertarNodoS2();
void desplegarListaPUS2();
void modificarNodoS2();
void eliminarNodoS2();

void insertarNodoS2(){
	artista* nuevo = malloc(sizeof(artista));
	
	// printf("Ingresa la cadena que tendrá el nuevo nodo: ");
	scanf(" %[^\n]s", nuevo->dato);

	if(primero2==NULL){
		primero2=nuevo;
		primero2->next=NULL;
		primero2->back=NULL;
		ultimo2=primero2;
	} else{
		ultimo2->next=nuevo;
		nuevo->next=NULL;
		nuevo->back=ultimo2;
		ultimo2=nuevo;
	}

	printf("Datos ingresados con éxito\n\n");
}

void desplegarListaPUS2(){
	artista* actual = malloc(sizeof(artista));
	actual = primero2;
	if(primero2!=NULL){
		while(actual!=NULL){
			printf("%s",actual->dato);
			printf(",  ");
			actual=actual->next;

		} printf("\n");
	} else{
		printf("La lista está vacía\n");
	}
}


void modificarNodoS2(){
	artista* actual = malloc(sizeof(artista));
	actual = primero2;
	char nodoBuscado[30];
	int encontrado=0;
	// printf("Ingresa la cadena de nodo a buscar para modificarla: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero2!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				printf("El artista (%s) fue encontrado\n", nodoBuscado);
				printf("Ingrese el nuevo artista: ");
				scanf(" %[^\n]s",actual->dato);
				printf("Modificación exitosa\n");
				encontrado=1;
			}
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Artista no encontrado\n");
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}

void eliminarNodoS2(){
	artista* actual = malloc(sizeof(artista));
	actual = primero2;
	artista* anterior = malloc(sizeof(artista));
	anterior=NULL;
	char nodoBuscado[30];
	int encontrado=0;
	// printf("Ingresa la cadena de nodo a eliminar: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero2!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				if (actual==primero2)
				{
					primero2=primero2->next;
					primero2->back=NULL;

				} else if (actual==ultimo2)
					{
						anterior->next=NULL;
						ultimo2=anterior;
					} else
						{
							anterior->next=actual->next;
							actual->next->back=anterior;
						}
				printf("Artista eliminado\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Artista no encontrado\n");
		} else{
			free(anterior);
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct precio{
	int dato;
	struct precio* next;
	struct precio* back;
	
}precio;

precio* primero3 = NULL;
precio* ultimo3 = NULL;

void insertarNodo();
void desplegarListaPU();
void modificarNodo();
void eliminarNodo();

void insertarNodo(){
	precio* nuevo = malloc(sizeof(precio));
	
	// printf("Ingresa el nuevo dato númerico: ");
	scanf("%d",&nuevo->dato);

	if(primero3==NULL){
		primero3=nuevo;
		primero3->next=NULL;
		primero3->back=NULL;
		ultimo3=primero3;
	} else{
		ultimo3->next=nuevo;
		nuevo->next=NULL;
		nuevo->back=ultimo3;
		ultimo3=nuevo;
	}

	printf("Dato ingresado con éxito\n\n");
}

void desplegarListaPU(){
	precio* actual = malloc(sizeof(precio));
	actual = primero3;
	if(primero3!=NULL){
		while(actual!=NULL){
			printf("%d",actual->dato);
			printf(",  ");
			actual=actual->next;

		} printf("\n");
	} else{
		printf("La lista está vacía\n");
	}
}


void modificarNodo(){
	precio* actual = malloc(sizeof(precio));
	actual = primero3;
	int nodoBuscado=0, encontrado=0;
	// printf("Ingresa el dato númerico a buscar para modificarlo: ");
	scanf("%d",&nodoBuscado);
	if(primero3!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (actual->dato==nodoBuscado)
			{
				printf("El precio (%d) fue encontrado\n", nodoBuscado);
				printf("Ingrese el nuevo precio: ");
				scanf("%d", &actual->dato);
				printf("El dato fue modificado exitosamente\n");
				encontrado=1;
			}
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Precio no encontrado\n");
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}

void eliminarNodo(){
	precio* actual = malloc(sizeof(precio));
	actual = primero3;
	precio* anterior = malloc(sizeof(precio));
	anterior=NULL;
	int nodoBuscado=0, encontrado=0;
	// printf("Ingresa el dato númerico a eliminar: ");
	scanf("%d",&nodoBuscado);
	if(primero3!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (actual->dato==nodoBuscado)
			{
				if (actual==primero3)
				{
					primero3=primero3->next;
					primero3->back=NULL;

				} else if (actual==ultimo3)
					{
						anterior->next=NULL;
						ultimo3=anterior;
					} else
						{
							anterior->next=actual->next;
							actual->next->back=anterior;
						}
				printf("Precio eliminado con éxito\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Precio no encontrado\n");
		} else{
			free(anterior);
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}

