/*Este programa es una lista doblemente enlazada que utiliza 
los tipos de datos char e int para manejar los datos que se 
usen a lo largo del programa.

Aquí existe una estructura con 3 datos y una función para cada 
tipo de dato correspondiente que tendra uso en las compras del usuario.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct compra{
	char dato[30];
	char dato2[30];
	int dato3;
	struct compra* next;
	struct compra* back;
	
}compra;

compra* primero4 = NULL;
compra* ultimo4 = NULL;

void insertar_NodoS();
void insertar_NodoS2();
void insertar_Nodo();

void desplegar_ListaPUS();
void desplegar_ListaPUS2();
void desplegar_ListaPU();

void buscar_NodoS();
void buscar_NodoS2();
void buscar_Nodo();

void modificar_NodoS();
void modificar_NodoS2();
void modificar_Nodo();

void eliminar_NodoS();
void eliminar_NodoS2();
void eliminar_Nodo();

void insertar_NodoS(){
	compra* nuevo = malloc(sizeof(compra));
	
	// printf("Ingresa la cadena que tendrá el nuevo nodo: ");
	scanf(" %[^\n]s", nuevo->dato);

	if(primero4==NULL){
		primero4=nuevo;
		primero4->next=NULL;
		primero4->back=NULL;
		ultimo4=primero4;
	} else{
		ultimo4->next=nuevo;
		nuevo->next=NULL;
		nuevo->back=ultimo4;
		ultimo4=nuevo;
	}

	printf("Datos ingresados con éxito\n\n");
}

void desplegar_ListaPUS(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	if(primero4!=NULL){
		while(actual!=NULL){
			printf("%s",actual->dato);
			printf(",  ");
			actual=actual->next;

		} printf("\n");
	} else{
		printf("La lista está vacía\n");
	}
}


void buscar_NodoS(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	char nodoBuscado[30];
	int encontrado=0;
	printf("Ingresa la cadena de nodo a buscar: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				printf("El nodo con la cadena (%s) fue encontrada\n", nodoBuscado);
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

void modificar_NodoS(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	char nodoBuscado[30];
	int encontrado=0;
	printf("Ingresa la cadena de nodo a buscar para modificarla: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				printf("El nodo con la cadena (%s) fue encontrada\n", nodoBuscado);
				printf("Ingrese la nueva cadena de nodo: ");
				scanf(" %[^\n]s",actual->dato);
				printf("La cadena fue modificada exitosamente\n");
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

void eliminar_NodoS(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	compra* anterior = malloc(sizeof(compra));
	anterior=NULL;
	char nodoBuscado[30];
	int encontrado=0;
	printf("Ingresa la cadena de nodo a eliminar: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato,nodoBuscado)==0);
			{
				if (actual==primero4)
				{
					primero4=primero4->next;
					primero4->back=NULL;

				} else if (actual==ultimo4)
					{
						anterior->next=NULL;
						ultimo4=anterior;
					} else
						{
							anterior->next=actual->next;
							actual->next->back=anterior;
						}
				printf("Cadena eliminada con éxito\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Nodo no encontrado\n");
		} else{
			free(anterior);
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}


void insertar_NodoS2(){
	compra* nuevo = malloc(sizeof(compra));
	
	// printf("Ingresa la cadena que tendrá el nuevo nodo: ");
	scanf(" %[^\n]s", nuevo->dato2);

	if(primero4==NULL){
		primero4=nuevo;
		primero4->next=NULL;
		primero4->back=NULL;
		ultimo4=primero4;
	} else{
		ultimo4->next=nuevo;
		nuevo->next=NULL;
		nuevo->back=ultimo4;
		ultimo4=nuevo;
	}

	printf("Datos ingresados con éxito\n\n");
}

void desplegar_ListaPUS2(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	if(primero4!=NULL){
		while(actual!=NULL){
			printf("%s",actual->dato2);
			printf(",  ");
			actual=actual->next;

		} printf("\n");
	} else{
		printf("La lista está vacía\n");
	}
}


void buscar_NodoS2(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	char nodoBuscado[30];
	int encontrado=0;
	printf("Ingresa la cadena de nodo a buscar: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato2,nodoBuscado)==0);
			{
				printf("El nodo con la cadena (%s) fue encontrada\n", nodoBuscado);
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

void modificar_NodoS2(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	char nodoBuscado[30];
	int encontrado=0;
	printf("Ingresa la cadena de nodo a buscar para modificarla: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato2,nodoBuscado)==0);
			{
				printf("El nodo con la cadena (%s) fue encontrada\n", nodoBuscado);
				printf("Ingrese la nueva cadena de nodo: ");
				scanf(" %[^\n]s",actual->dato2);
				printf("La cadena fue modificada exitosamente\n");
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

void eliminar_NodoS2(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	compra* anterior = malloc(sizeof(compra));
	anterior=NULL;
	char nodoBuscado[30];
	int encontrado=0;
	printf("Ingresa la cadena de nodo a eliminar: ");
	scanf(" %[^\n]s",nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (strcmp(actual->dato2,nodoBuscado)==0);
			{
				if (actual==primero4)
				{
					primero4=primero4->next;
					primero4->back=NULL;

				} else if (actual==ultimo4)
					{
						anterior->next=NULL;
						ultimo4=anterior;
					} else
						{
							anterior->next=actual->next;
							actual->next->back=anterior;
						}
				printf("Cadena eliminada con éxito\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Nodo no encontrado\n");
		} else{
			free(anterior);
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}



void insertar_Nodo(){
	compra* nuevo = malloc(sizeof(compra));
	
	// printf("Ingresa el nuevo dato númerico: ");
	scanf("%d",&nuevo->dato3);

	if(primero4==NULL){
		primero4=nuevo;
		primero4->next=NULL;
		primero4->back=NULL;
		ultimo4=primero4;
	} else{
		ultimo4->next=nuevo;
		nuevo->next=NULL;
		nuevo->back=ultimo4;
		ultimo4=nuevo;
	}

	printf("Dato ingresado con éxito\n\n");
}

void desplegar_ListaPU(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	if(primero4!=NULL){
		while(actual!=NULL){
			printf("%d",actual->dato3);
			printf(",  ");
			actual=actual->next;

		} printf("\n");
	} else{
		printf("La lista está vacía\n");
	}
}


void buscar_Nodo(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	int nodoBuscado=0, encontrado=0;
	printf("Ingresa el dato númerico a buscar: ");
	scanf("%d",&nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (actual->dato3==nodoBuscado)
			{
				printf("El nodo con el dato (%d) fue encontrado\n", nodoBuscado);
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

void modificar_Nodo(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	int nodoBuscado=0, encontrado=0;
	printf("Ingresa el dato númerico a buscar para modificarlo: ");
	scanf("%d",&nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (actual->dato3==nodoBuscado)
			{
				printf("El nodo con el dato (%d) fue encontrado\n", nodoBuscado);
				printf("Ingrese el nuevo dato númerico: ");
				scanf("%d", &actual->dato3);
				printf("El dato fue modificado exitosamente\n");
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

void eliminar_Nodo(){
	compra* actual = malloc(sizeof(compra));
	actual = primero4;
	compra* anterior = malloc(sizeof(compra));
	anterior=NULL;
	int nodoBuscado=0, encontrado=0;
	printf("Ingresa el dato númerico a eliminar: ");
	scanf("%d",&nodoBuscado);
	if(primero4!=NULL){
		while(actual!=NULL && encontrado != 1){
			if (actual->dato3==nodoBuscado)
			{
				if (actual==primero4)
				{
					primero4=primero4->next;
					primero4->back=NULL;

				} else if (actual==ultimo4)
					{
						anterior->next=NULL;
						ultimo4=anterior;
					} else
						{
							anterior->next=actual->next;
							actual->next->back=anterior;
						}
				printf("Dato eliminado con éxito\n");
				encontrado=1;
			}
			anterior=actual;
			actual=actual->next;
		} 
		if (encontrado==0)
		{
			printf("Nodo no encontrado\n");
		} else{
			free(anterior);
		}
		printf("\n");
	} else{
		printf("La lista está vacía\n");
	}	
}

