#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcionesExtra.h"
#include "validaciones.h"
#include "movies.h"


int menu()
{
    int opcion;
    system("cls");
    printf("MENU DE OPCIONES:\n");
    printf("1. Cargar los datos de los pasajeros desde un archivo .csv (modo texto).\n");
    printf("2. Imprimir lista\n");
    printf("3. Asignar rating\n");
    printf("4. Asignar genero\n");
    printf("5. Filtrar por genero\n");
    printf("6. Ordenar peliculas por genero y rating descendente\n");
    printf("7. Guardar peliculas en archivo .csv\n");
    printf("8. Salir\n");
    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error. Opcion invalida. ", 1, 8);
    return opcion;
}

int mostrarPelicula(eMovie* m)
{
    int todoOk = 0;
    int id;
    char titulo[50];
    char genero[50];
    float rating;

    if( Movie_getId(m, &id) &&
    	Movie_getTitulo(m, titulo) &&
		Movie_getGenero(m, genero) &&
		Movie_getRating(m, &rating) )
    {
        printf("%4d %30s %15s %5.2f \n", id, titulo, genero, rating);
        todoOk = 1;
    }
    return todoOk;
}

int mostrarPeliculas(LinkedList* lista)
{
    int todoOk = 0;
    eMovie* auxMovie=NULL;
    int tam;
    if(lista != NULL)
    {
    	tam=ll_len(lista);
        printf("  id                       titulo       genero      rating\n");
        for(int i=0; i<tam; i++)
        {
        	auxMovie=(eMovie*)ll_get(lista, i);
        	if(!mostrarPelicula(auxMovie))
        	{
        		return todoOk;
        	}
        }
        printf("\n\n");
        todoOk = 1;
    }
    return todoOk;
}

int menuFilter()
{
    int opcion;
    printf("ELIJA OPCION:\n");
    printf("1- Filtrar lista por genero drama y crear archivo CSV\n");
    printf("2- Filtrar lista por genero comedia y crear archivo CSV\n");
    printf("3- Filtrar lista por genero accion y crear archivo CSV\n");
    printf("4- Filtrar lista por genero terror y crear archivo CSV\n");
    printf("5- Salir\n");
    utn_getNumeroInt(&opcion, "Ingrese opcion: ", "Error. Opcion invalida. ", 1, 5);
    return opcion;
}
