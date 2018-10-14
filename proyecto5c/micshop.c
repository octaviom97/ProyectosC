#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Incluimos las listas que usaremos que contienen las funciones
//con sus respectivos nombres para manejar los datos
#include "lista2.c"
#include "compra.c"

/*Declaramos las estructuras que se van a  usar.
	Discos
	Usuario 
	Admin
*/
struct discos{
	char nombre[30];
	char artista[30];
	int precio;
}disc[50];


struct usuario{
	char nombre[30];
	char contrasenia[30];
	int numCompras;
} user[50];

struct admin{
	char nomUsuario[30];
	char contrasenia[30];
	
}admin={"admin","admin1"};

//Declaramos las variables globales que utilizaremos 
int cont=0,contcontra=3,control=0;

/* Inicializamos todas las funciones que utilizaremos 
a lo largo del programa.
*/

void comparar_usuario();
void ingresar_usuario();
void menu_admin();
void menu_usuario();
void agregar_disco();
void consultar_discos();
void eliminar_disco();
void modificar_disco();
void consultar_usuario();
void realizar_compra();

/* En esta zona se inicia sesión los usuarios
Hay dos tipos de usuarios, admin y usuario normal
Tienen una capacidad de 3 intentos de ingresar la contraseña
Si no se introduce la contraseña correcta te saca del programa */
void comparar_usuario(){
		char usuario[30];
		char contrasenia[30];
		int i;
		//El inicio del programa imprime la bienvenida y pide introducir el usuario
		system("clear");
		printf("\t-----------------------------------------\n");
		printf("\t|       Martínez Osorio Octavio 10      |\n");
		printf("\t|---------------------------------------|\n");
		printf("\t|                                       |\n");
		printf("\t|                                       |\n");
		printf("\t|       Bienvenido a la MiCShop         |\n");
		printf("\t|                                       |\n");
		printf("\t|                                       |\n");
		printf("\t|---------------------------------------|\n");
		printf("\t|   Serrano Sansón Jorge Alejandro 13   |\n");
		printf("\t-----------------------------------------\n");
		printf("\nIntroduce tu usuario: ");
		scanf(" %[^\n]s", usuario);

		/* Posteriomente de introducir el usuario se empieza a hacer la comparación con admin 
		 y después con usuario normal para aceptar al mismo*/
		if(strcmp(usuario,admin.nomUsuario)==0){
			do{
			printf("Introduce tu contraseña: ");
			scanf(" %[^\n]s", contrasenia);
				if(strcmp(contrasenia,admin.contrasenia)==0){
					control=1;
					menu_admin();
				} else { 
					printf("contraseña incorrecta\n");
					contcontra-=1;
					printf("\nIntentos: %d\n",contcontra);

				}
			} while(contcontra!=0);

		} 
		else if (cont==0){
			ingresar_usuario();
		}
		else {

			for (i = 0; i < cont; ++i)
			{
				if (strcmp(usuario, user[i].nombre) ==0 )
				{
					do{
					printf("Introduce tu contraseña: ");
					scanf(" %[^\n]s", contrasenia);
						if(strcmp(contrasenia,user[i].contrasenia)==0){
							system("clear");
							printf("\n\tBienvenido: %s :D\n", user[i].nombre);
							control=1;
							menu_usuario();
						} else { 
							printf("contraseña incorrecta\n");
							contcontra-=1;
							printf("\nIntentos: %d\n",contcontra);

						}
					} while(contcontra!=0);
					
				} 
			} 
			if (contcontra==0)
			{
				control=1;
			}
			//Si el usuario no existe te permite registrar uno nuevo
			if (control==0)
			{
				ingresar_usuario();
			}

		} 

				
}

//Si al iniciar sesión se introduce un usuario que no existe, el flujo del programa
//Te manda aquí, te permite registrar un nuevo usuario.
void ingresar_usuario(){
	int n;
	// system("clear");
	printf("\nUsuario no registrado\n");
	printf("¿Desea registrarse?\n");
	printf("1) Si\t2) No\t3) Regresar\n"); 
	do{
	scanf("%d", &n);
		if (n==1){
			printf("Introduzca el nombre de usuario: ");
			scanf(" %[^\n]s",user[cont].nombre);
			printf("Introduzca la contraseña del usuario: ");
			scanf(" %[^\n]s",user[cont].contrasenia);
			user[cont].numCompras = 0;
			cont++;
			comparar_usuario();

		} else if (n==2){
			printf("Bye :D\n");
		} else if (n==3){
			comparar_usuario();
		}
	} while(n!=1 && n!=2 && n!=3);
	
}
//Si al iniciar sesión se inicia como administrador, despliega el siguiente menu.
void menu_admin(){
	int op;
	system("clear");
	printf("\n\tBienvenido admin :D\n");
	do{
	printf("\n¿Qué deseas hacer?\n");
	printf("1) Agregar discos\n");
	printf("2) Remover discos\n");
	printf("3) Actualizar datos de discos\n");
	printf("4) Buscar usuario\n");
	printf("5) Consultar datos de los discos\n");
	printf("6) Regresar a inicio de sesión\n");
	printf("7) Salir\n");
	printf("Introduce tu opción: ");
	scanf("%d", &op);
	//Dependiendo la opción seleccionada por el usuario hace lo siguiente:
	//El administrador es el único que puede modiicar datos del disco
		switch(op){
			case 1:
			agregar_disco();
			break;
			case 2:
			eliminar_disco();
			break;
			case 3:
			modificar_disco();
			break;
			case 4:
			consultar_usuario();
			break;
			case 5:
			consultar_discos();
			break;
			case 6:
			comparar_usuario();
			break;		
			case 7:	
			printf("Adios :D\n");
			contcontra=0;
			break;
			default:
			printf("Opción incorrecta, vuelve a intentarlo\n\n");
			break;
		}
	} while (op!=7);

}

//Si al iniciar sesión se ingresa como un usuario normal despliega el siguiente menu
void menu_usuario(){
	int op;
	do{
	printf("\n¿Qué deseas hacer?\n");
	printf("1) Consultar datos de los discos\n");
	printf("2) Realizar compras\n");
	printf("3) Regresar a inicio de sesión\n");
	printf("4) Salir\n");
	printf("Introduce tu opción: ");
	scanf("%d", &op);
		switch(op){
			case 1:
			consultar_discos();
			break;
			case 2:
			realizar_compra();
			break;
			case 3:
			comparar_usuario();
			break;
			case 4:
			printf("Adios c:\n");
			contcontra=0;
			break;
			default:
			printf("Opción incorrecta, vuelve a intentarlo\n\n");
			break;
		}
	} while (op!=4);

}

//Si el admin quiere agregar un disco, muestra lo siguiente:

void agregar_disco(){
	printf("Ingresa el nombre del disco: ");
	insertarNodoS();
	printf("Ingresa el artista: ");
	insertarNodoS2();
	printf("Ingresa el precio: ");
	insertarNodo();
	printf("\n");
}

//Si se quiere consultar los valores de un disco, muestra lo siguiente:

void consultar_discos(){
	printf("Discos disponibles: \n");
	desplegarListaPUS();
	printf("Artistas: \n");
	desplegarListaPUS2();
	printf("Precio: \n");
	desplegarListaPU();
	printf("\n");
}

//Si el admin quiere eliminar un disco, muestra lo siguiente:

void eliminar_disco(){
	printf("Elimina el disco: ");
	eliminarNodoS();
	printf("Elimina el artista: ");
	eliminarNodoS2();
	printf("Elimina el precio: ");
	eliminarNodo();
}

//Si el admin quiere modificar los datos de un disco, muestra lo siguiente:

void modificar_disco(){
	printf("¿Qué disco vas a modificar?\n");
	modificarNodoS();
	printf("Modifica el artista: ");
	modificarNodoS2();
	printf("Modifica el precio: ");
	modificarNodo();
}
//Si se quiere consultar la información de usuario se muestra lo siguiente:
void consultar_usuario(){
	char consultar[30];
	int i;

	printf("Ingrese el nombre del usuario: ");
	scanf(" %[^\n]s",consultar);
	printf("\n");

	for(i=0;i<cont;i++)
	{
		if(strcmp(consultar, user[i].nombre) ==0 )
		{
			printf("Nombre del usuario: %s\n", user[i].nombre);
			printf("Número de compras: %d\n", user[cont].numCompras);
			
		} else{ //Si el usuario no existe muestra lo sig:
		printf("Usuario no encontrado\n");
		}
	} 


}

//Si el usuario quiere comprar, muestra lo siguiente:

void realizar_compra(){
	//Primero despliega la lista de los discos
	printf("Listas de discos: \n");
	consultar_discos();
	//Se le pide al usuario que seleccione un disco para comprar
	printf("Introduce el nombre, artista y precio del disco que vas a comprar\n");
	insertar_NodoS();
	insertar_NodoS2();
	insertar_Nodo();

	printf("Compra exitosa\n");
	
	user[cont].numCompras++;
}

//Inicio del flujo del programa
int main(){

	comparar_usuario();
	
	return 0;
}

