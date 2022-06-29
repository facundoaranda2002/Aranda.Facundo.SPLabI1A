#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "movies.h"
#include "funcionesExtra.h"
#include "validaciones.h"

int main()
{
    int salir=0;
    int flagGenero=0;
    int flagRating=0;
    int flagOrden=0;
    int flagListado=0;
    int flagFiltrado=0;
    int flagGuardado=0;
    char archivo[20];
    srand(time(NULL));

    LinkedList* listaPeliculas = ll_newLinkedList();
    if(listaPeliculas==NULL)
    {
    	printf("No se consiguio memoria\n");
    	system("pause");
    	exit(1);
    }
    else
    {
		do{
			switch(menu())
			{
				case 1:
				    utn_getCadenaChar(archivo, "Ingrese nombre del archivo(sin extension csv): ", "Error. Nombre demasiado largo. ", 1, 20);
				    strcat(archivo, ".csv");
					if(!controller_loadFromText(archivo, listaPeliculas))
					{
						printf("Error al cargar desde archivo csv\n");
					}
					else
					{
						printf("Archivo cargado con exito\n");
						flagGenero=0;
                        flagRating=0;
                        flagOrden=0;
                        flagListado=0;
                        flagFiltrado=0;
                        flagGuardado=0;
					}
					break;
				case 2:
					if(!controller_List(listaPeliculas))
					{
						printf("Error al leer lista\n");
					}
					else
                    {
                        flagListado=1;
                    }
					break;
				case 3:
				    if(!flagListado)
                    {
                        printf("Primero debe mostrarse la lista cargada\n");
                    }
                    else
                    {
                       if(!controller_AsignarRating(listaPeliculas))
                        {
                            printf("Error al asignar rating\n");
                        }
                        else
                        {
                            printf("Rating asignado correctamente\n");
                            flagRating=1;
                        }
                    }
					break;
				case 4:
				    if(!flagRating)
                    {
                        printf("Primero se debe de asignar ratings a las peliculas\n");
                    }
                    else
                    {
                       if(!controller_AsignarGenero(listaPeliculas))
                        {
                            printf("Error al asignar genero\n");
                        }
                        else
                        {
                            printf("Genero asignado correctamente\n");
                            flagGenero=1;
                        }
                    }
					break;
				case 5:
				    if(!flagGenero || !flagRating)
                    {
                        printf("No se han cargado generos o ratings a las peliculas\n");
                    }
                    else
                    {
                       if(!controller_FiltrarPorGenero(listaPeliculas))
                        {
                            printf("Error al filtrar por genero\n");
                        }
                        else
                        {
                            flagFiltrado=1;
                        }
                    }
					break;
				case 6:
					if(flagFiltrado)
					{
						if(!controller_sort(listaPeliculas))
						{
							printf("Error al ordenar peliculas\n");
						}
						else
						{
							printf("Peliculas ordenadas con exito\n");
							flagOrden=1;
						}
					}
					else
					{
						printf("Primero se deben cargar peliculas y filtrarlas\n");
					}
					break;
				case 7:
				    if(!flagOrden)
                    {
                        printf("Primero se deben ordenar las peliculas\n");
                    }
                    else
                    {
                        utn_getCadenaChar(archivo, "Ingrese nombre del archivo(sin extension csv): ", "Error. Nombre demasiado largo. ", 1, 20);
                        strcat(archivo, ".csv");
                        if(!controller_saveAsText(archivo,listaPeliculas))
                        {
                            printf("Error al guardar archivo csv\n");
                        }
                        else
                        {
                            printf("Archivo guardado con exito\n");
                            flagGuardado=1;
                        }
                    }
					break;
				case 8:
				    if(!flagGuardado)
                    {
                        printf("No se puede salir sin antes guardar un archivo\n");
                    }
                    else
                    {
                        salir=1;
                    }
					break;
			}
			system("pause");
		  }while(salir != 1);
    }
    ll_deleteLinkedList(listaPeliculas);
    return 0;
}

