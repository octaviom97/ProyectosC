 //10 Martínez Osorio Octavio

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct agenda {
	char nombre[30], apellidop[15], apellidom[15];
	int edad;
	char dir[50];
	long int telefono;
} persona[100];

int cont=0;

void ingresar_contacto()
{
	system ("clear");
	int n;
	printf("¿Cuantos contactos desea agregar?\n");
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
	printf("%d.Nombre de contacto: ", (cont+1));
	scanf(" %[^\n]s",persona[cont].nombre);
	printf("Apellido paterno: ");
	scanf(" %[^\n]s",persona[cont].apellidop);
	printf("Apellido materno: ");
	scanf(" %[^\n]s",persona[cont].apellidom);
	printf("Edad: ");
	scanf("%d", &persona[cont].edad);
	printf("Dirección: ");
	scanf(" %[^\n]s",persona[cont].dir);
	printf("Teléfono: ");
	scanf("%ld", &persona[cont].telefono);
	printf("\n");
	cont++;
	}
}

void consultar_contacto()
{
	system ("clear");
	char consultar[30];
	int i;

	printf("Ingrese el nombre del contacto: ");
	scanf(" %[^\n]s",consultar);
	printf("\n");

	for(i=0;i<cont;i++)
	{
		if(strcmp(consultar, persona[i].nombre) ==0 )
		{
			printf("Nombre: %s\n", persona[i].nombre);
			printf("Apellido paterno: %s\n", persona[i].apellidop);
			printf("Apellido materno: %s\n", persona[i].apellidom);
			printf("Edad: %d\n", persona[i].edad);
			printf("Dirección: %s\n", persona[i].dir);
			printf("Telefono: %ld\n", persona[i].telefono);
			
		}
	}

}

void mostar_contacto()
{
	system ("clear");
	int aux, i, j;
	char auxc[50];

	for(i=0;i<cont-1;i++){
		for(j=0;j<cont-1-i;j++){
			if(strcmp(persona[j].nombre,persona[j+1].nombre)>0){
				
				strcpy(auxc,persona[j].nombre);
				strcpy(persona[j].nombre,persona[j+1].nombre);
				strcpy(persona[j+1].nombre,auxc);

				strcpy(auxc,persona[j].apellidop);
				strcpy(persona[j].apellidop,persona[j+1].apellidop);
				strcpy(persona[j+1].apellidop,auxc);

				strcpy(auxc,persona[j].apellidom);
				strcpy(persona[j].apellidom,persona[j+1].apellidom);
				strcpy(persona[j+1].apellidom,auxc);

				aux = persona[j].edad;
				persona[j].edad = persona[j+1].edad;
				persona[j+1].edad = aux;

				strcpy(auxc,persona[j].dir);
				strcpy(persona[j].dir,persona[j+1].dir);
				strcpy(persona[j+1].dir,auxc);

				aux = persona[j].telefono;
				persona[j].telefono = persona[j+1].telefono;
				persona[j+1].telefono = aux;

				
			}
		}
	}

	printf("\n\tContactos\n\n");

	for(i=0;i<cont;i++){
		printf("%d.Nombre: %s\n",(i+1), persona[i].nombre);
		printf("Apellido paterno: %s\n", persona[i].apellidop);
		printf("Apellido materno: %s\n", persona[i].apellidom);
		printf("Edad: %d\n", persona[i].edad);
		printf("Dirección: %s\n", persona[i].dir);
		printf("Telefono: %ld\n", persona[i].telefono);
		printf("\n");
		
	}

}



int main(){
	int opcion=0;


	while(opcion<5)
	{
		printf("\n\tMENU\n");
		printf("1.Ingresar contactos\n");
		printf("2.Consultar contacto\n");
		printf("3.Modificar contacto\n");
		printf("4.Mostrar todos los contactos\n");
		printf("5.Salir\n");
		printf("Introduce tu opción: ");
		scanf("%d", &opcion);

		switch(opcion)
		{

		case 1:
			ingresar_contacto();
			break;
		case 2:
			consultar_contacto();
			break;
		case 3:
			printf("\nNo supe hacer esta parte, lo siento :(\n");
			break;
		case 4:
			mostar_contacto();
			break;
		default:
			printf("Fin del programa\n");
			break;
		}
	}

	return 0;
}