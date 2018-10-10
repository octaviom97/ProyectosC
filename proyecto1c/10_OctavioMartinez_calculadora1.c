#include <stdio.h>

int potencia(int z,int y)
	{
	int acum=1;
	for(int j=1;j<=y;j++)
    	acum*=z;
	return(acum);
	}

long int factorial (int x) 
{ 
int i; 
long int fac = 1; 
for (i=2; i<=x; i=i+1) fac=fac*i; 
return 
(fac); 
 }  

int main(){
int opcion=1;
float a, b;
int c, d, e, f, g;

while(opcion<7){
printf("¿Que deseas hacer?\n");
printf("1. Sumar    ");
printf("2. Restar    ");
printf("3. Multiplicar    ");
printf("4. Dividir    ");
printf("5. Potencia    ");
printf("6. Factorial    \n");
printf("Introduce el número de tu opción: ");
scanf("%i", &opcion);
switch(opcion){
	case 1: 
		printf("Introduce los dos valores a sumar: ");	
		scanf("%f%f", &a, &b);
		printf("La suma es:%f\n\n", a+b);
		break;
	case 2: 
		printf("Introduce los dos valores a restar: ");
		scanf("%f%f", &a, &b);
		printf("La resta es:%f\n\n", a-b);
		break;
	case 3: 
		printf("Introduce los dos valores a multiplicar: ");
		scanf("%f%f", &a, &b);
		printf("La multiplicación es:%f\n\n", a*b);
		break;
	case 4: 
		printf("Introduce los dos valores a dividir: ");
		scanf("%f", &a);
		scanf("%f", &b);
		if (b==0)
		{
			printf("Error, vuelve a intentarlo.\n\n");
			break;
		} 
		else
		{
			printf("La división es:%f\n\n", a/b);
			break;
		}
	case 5: 
		printf ("Introduce el número y su potencia: "); 
		scanf ("%d%d", &d,&e); 
		printf ("potencia es %d\n\n", potencia (d, e)); 
		break;
	case 6: 
		printf ("Introduce el valor factorial: "); 
		scanf ("%d", &c); 
		if (c > 0)  
		printf ("El factorial es %ld\n\n", factorial (c)); 
        break;

	default:
	printf("Fin del programa.\n");
	break;
		}


	}
return 0;
}
