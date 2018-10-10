#include <stdio.h>
#include <stdlib.h>
#include "Pila.c"

//crear variable con numero de elementos del arreglo
int num_arr = 10;

//Crear función que pida la memoria del arreglo
int* hacer_arr(int* aparr,int n){
 aparr = calloc(n,sizeof(int));
  if(aparr == NULL){
  	return NULL;
  }
  return aparr;
};

//Función que lee el número de elementos del arreglo
void pedir_arr(int* aparr){
  for (int i = 0; i < num_arr; i++) {
    printf("Elemento %i del arreglo: ",i+1);
    scanf("%i",aparr + i);
  }
};

//Función para invertir los elementos del arreglo
void inv_arr(int* aparr){
   Pila* stack = crearPila();
  for (int i = 0; i < num_arr; i++) {
    push(stack, aparr[i]);
  }
  for (int i = 0; i < num_arr; i++) {
    aparr[i] = pop(stack);
  }
};

// Función para imprimir los elementos del arreglo
void imp_arr(int* aparr){
  printf("El arreglo invertido es: ");
  for (int i = 0; i < num_arr; i++) {
    printf("%i ",aparr[i]);
  }
};

//Función principal para correr el programa
int main() {

  int* arr = NULL;
  printf("\n\tIntroduce 10 elementos de un arreglo para invertirlos\n\n");
  arr = hacer_arr(arr,num_arr);
  pedir_arr(arr);
  printf("\n");
  inv_arr(arr);
  imp_arr(arr);
  printf("\n\n");
  return 0;
}
