// 10 Martínez Osorio Octavio
// Compilar con "gcc -lm" por la biblioteca <math.h>

#include <stdio.h>
#include <math.h>

int i;
float arr[10];
float prom, var, desviacion_std;

float moda(float arr[], int tam)
{
	//Se declaran las variables
	int j, a;
	float m[10];

	{
			//Se ingresan los valores
	        for (i=0 ; i<tam ; i++) 
	        {
	            printf("Ingrese el elemento %d del arreglo: ",i+1);
	            scanf("%f",&arr[i]);
	            m[i]=0;
	            if (i>0) //Se compara a partir del segundo elemento
	            {
	                for (j=0 ; j<i ; j++) //Se hace el contador para el elemento que más se repita 
	                    if (arr[i]==arr[j])	m[i]=m[i]+1;
	            }
	        }
	        a=0;
	        for (i=1;i<tam;i++){
	                   if (m[i]>m[a])	a=i;
	        }
	        if (a==0) //Se hace la condición por si hubo elementos repetidos o no
	            printf("\nNo hay moda\n\n");
	        else
	            printf("\nLa moda es: %f\n\n",arr[a]);
	}        
}
float mediana(float arr[], int tam)
{
 	//Se declaran las variables para la mediana
 	int j,k,l,m;
    float aux,c,d,e,f,ma,mg,mm;
    float *a;  
    
    //Se ingresan los valores del arreglo 
	for(i = 0; i<tam;i++)
	{
	printf("Ingresa el elemento %d del arreglo: ", i+1);
	scanf("%f", &arr[i]);
    }
    printf("\n");

    //Se ordenan los números
    for(i=0;i<tam;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(arr[i]>arr[j])
            {
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
            }
        }
    }
       	//Se calcula la mediana
        printf("Los numeros ordenados son\n");
        for(i=0;i<tam;i++)
        {
            printf("%.2f\t\n",arr[i]);
        }                 
        if((tam%2)!=0)
        {
           k=((tam+1)/2)-1;
           printf("\nLa mediana es: %.2f\n\n",arr[k]);
        }
        
        else
        {
            l=(tam/2)-1;
            m=(tam/2);
            f=arr[l];
            e=arr[m];
            mm=(f+e)/2;
            printf("\nLa mediana es: %.2f\n\n",mm);
        }                                      

}

float promedio(float arr[], int tam)
{
	//Se declaran las variables para el promedio
	float suma;
	//Se utiliza el ciclo for para sumar los valores del arreglo
	for(i = 0; i<tam;i++)
	{
	printf("Ingresa el elemento %d del arreglo: ", i+1);
	scanf("%f", &arr[i]);
	suma+=arr[i];
	}
	//Se calcula el promedio con la suma de los valores entre el numero de éstos
	prom = suma/tam;
}

float varianza(float arr[], int tam)
{
	//Se declaran las variables para la varianza
	float suma2=0;
	//Se llama la función promedio
	promedio(arr,10);
	//Se utiliza el ciclo for para obtener los valores de la varianza
	for (i = 0; i < tam; i++)
		{
            suma2 = suma2 + pow((arr[i] - prom), 2);
        }
    //Se saca el valor de la varianza para posteriormente imprimirla
    var = suma2/tam;
}

float desviacion_estandar(float arr[], int tam)
{
	float suma=0, suma2=0;
	//Se llama la función varianza
	varianza(arr, 10);
    //La desviación estándar es la raiz de la varianza
    desviacion_std = sqrt(var);
}

void regresion_lineal ()
{
	int tam=10;
	float m,b,x,y2,xy,x2;
   	float y[10];
  	
  	printf("Introduce los valores de x\n");
  	//Se utiliza el ciclo for para ingresar los indices del arreglo
   	for (i=0;i<tam;i++)
  	{
   		printf("Ingresa el indice del arreglo : ",i+1);
        scanf("%f",&arr[i]);
    }
   	printf("\nIntroduce los valores de y\n");
   	//Se utiliza el ciclo for para obtener los valores del arreglo
	for ( i = 0; i < tam; ++i)
	{
    	printf("Ingresa el elemento %d del arreglo : ",i+1);
    	scanf("%f",&y[i]);
  	}
//Se hacen las sumatorias 
   x=y2=xy=x2=0;
   for (i=0;i<tam;i++)
   {
   
        xy += arr[i]*y[i];
    
     	x2 += arr[i]*arr[i];
    
        x += arr[i];
    
        y2 += y[i];
  
   }
   //Se calcula la pendiente (m) y la interseccion (b)

   m = (tam*xy - x*y2) / (tam*x2 - x*x);
   b = (y2 - m*x) / tam;

   printf("\nLa ecuación de la recta resultante es: %f + (%f)\n\n",b,m);
}


int main()
{
	int opcion=0;
	
	while(opcion<7)
	{
	printf("Elige tu opción y posteriormente introduce los 10 valores a calcular.\n");
	printf("1. Moda\n");
	printf("2. Mediana\n");
	printf("3. Promedio\n");
	printf("4. Varianza\n");
	printf("5. Desviación estándar\n");
	printf("6. Regresión lineal\n");
	printf("Mayor a 6 fin del programa\n\n");
	printf("Introduce el número de tu opción: ");
	scanf("%i", &opcion);
	printf("\n");
	switch(opcion)
		{
		case 1: 
			moda(arr, 10);
			break;
		case 2:
			mediana(arr, 10);
			break;
		case 3: 
			promedio(arr, 10);
			printf("\nEl promedio del arreglo es: %f\n\n", prom);
			break;
		case 4: 
			varianza(arr, 10);
			printf("\nLa varianza es: %f\n\n", var);
			break;
		case 5: 
			desviacion_estandar(arr, 10);
			printf("\nLa derivación estándar es: %f\n\n", desviacion_std);
			break;
		case 6: 
			regresion_lineal();
			break;

		default:
		printf("Fin del programa.\n\n");
		break;
		}


	}

	return 0;
}
