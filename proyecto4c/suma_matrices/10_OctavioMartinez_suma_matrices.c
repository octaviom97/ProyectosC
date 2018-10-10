#include <stdio.h>
#include <string.h>
     
    int main(){

    //Declaración de variables y arreglos que se usarán en el programa
    FILE* archivo;
    int i,j,filas=3,columnas=3;
    int ma1[10][10],ma2[10][10],suma_ma[10][10];

    //Instrucciones y comentarios del programa
    printf("\n\tSuma de matrices 3x3\n\n"); 
    printf("Programa que suma una matriz A con una matriz B\n\n");   
    printf("Instrucciones:\n");
    printf("Debe de tener dos archivos de texto llamados 'matriz1' y 'matriz2', con \n9 números enteros cada uno para que el programa sume esos elementos.\n\n");
    
    //Usamos un ciclo for para leer los elementos del archivo matriz1 
    archivo = fopen("matriz1", "r"); 
    for(i=0;i<filas;i++){                               
        for(j=0;j<columnas;j++){
            fscanf(archivo, "%i", &ma1[i][j]);    
        }
    }
    fclose(archivo); 
    
    //Con este ciclo for imprimimos los valores del archivo matriz1
    printf("Matriz 1:\n");
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%i ",ma1[i][j]);
        }
        printf("\n");
    }

    //Usamos un ciclo for para leer los elementos del archivo matriz2 
    archivo = fopen("matriz2", "r"); 
    for(i=0;i<filas;i++){            
        for(j=0;j<columnas;j++){
            fscanf(archivo, "%i", &ma2[i][j]);      
        }
    }        
    fclose(archivo);  

    //Con este ciclo for imprimimos los valores del archivo matriz2
    printf("Matriz 2:\n");
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%i ",ma2[i][j]);
        }
        printf("\n");
    }

    //Ahora se suman los elementos de matriz1 y matriz2 y los almacenamos en un arreglo llamado suma_ma
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            suma_ma[i][j] = ma1[i][j] + ma2[i][j]; 
        }
    }

    //Abrimos el archivo matriz3 con 'w' para poder modificar su contenido e introducir los elementos de suma_ma
    archivo = fopen("matriz3", "w");  
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            fprintf(archivo, "%i \n", suma_ma[i][j]);
        }
    }
    fclose(archivo);  

    //Con este ciclo for imprimimos los valores del archivo matriz3
    printf("Matriz 3:\n");
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%i ",suma_ma[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}