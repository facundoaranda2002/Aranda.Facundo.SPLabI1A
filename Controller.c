#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "movies.h"
#include "parser.h"
#include "funcionesExtra.h"
#include "validaciones.h"
#include "Controller.h"



int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int todoOk=0;
	char respuesta;
	FILE* f=fopen(path, "r");
	if(f!=NULL && pArrayList!=NULL)
	{
		if(ll_len(pArrayList)>0)
		{
			utn_getRespuesta(&respuesta, "Esto eliminara la lista actual del linked list y cargara una nueva desde el archivo seleccionado, asegurese de guardar los datos que ya tiene antes. Seguro que quiere continuar?(s(si), n(no))", "Opcion Invalida. Reingrese respuesta. ");
			if(respuesta=='s')
			{
				if(ll_clear(pArrayList)==0)
				{
					if(parser_MovieFromText(f, pArrayList))
					{
						todoOk=1;
					}
				}
			}
			else
			{
				printf("Carga de archivo cancelada\n");
			}
		}
		else
		{
			if(parser_MovieFromText(f, pArrayList))
			{
				todoOk=1;
			}
		}
		fclose(f);
	}
    return todoOk;
}

int controller_List(LinkedList* pArrayList)
{
	int todoOk=0;
	if(pArrayList!=NULL)
	{
		int x=ll_len(pArrayList);
		if(x>0)
		{
			if(mostrarPeliculas(pArrayList))
			{
				todoOk=1;
			}
		}
		else
		{
			printf("No hay datos cargados en la lista\n");
		}
	}
    return todoOk;
}

int controller_AsignarRating(LinkedList* pArrayList)
{
	int todoOk=0;
	if(pArrayList!=NULL)
	{
		if(!ll_isEmpty(pArrayList))
		{
		    pArrayList=ll_map(pArrayList, asignarRating);

			if(controller_List(pArrayList))
			{
				todoOk=1;
			}

		}
		else
		{
			printf("No hay datos cargados en la lista\n");
		}
	}
    return todoOk;
}

int controller_AsignarGenero(LinkedList* pArrayList)
{
	int todoOk=0;
	if(pArrayList!=NULL)
	{
		if(!ll_isEmpty(pArrayList))
		{
		    pArrayList=ll_map(pArrayList, asignarGenero);
		    if(controller_List(pArrayList))
            {
               todoOk=1;
            }
		}
		else
		{
			printf("No hay datos cargados en la lista\n");
		}
	}
    return todoOk;
}

int controller_FiltrarPorGenero(LinkedList* pArrayList)
{
	int todoOk=0;
	int salir=0;
	LinkedList* filterList=NULL;
	if(pArrayList!=NULL)
	{
		if(!ll_isEmpty(pArrayList))
		{
		    do
			{
				system("cls");
				switch(menuFilter())
				{
				case 1:
					filterList=ll_filter(pArrayList, filtrarGeneroDrama);
					if(ll_isEmpty(filterList))
                    {
                        printf("No existen peliculas con ese genero en la lista, por lo tanto no se ha creado el archivo\n");
                    }
                    else
                    {
                        if(controller_saveAsText("movies_drama.csv", filterList))
                        {
                            printf("El archivo movies_drama.csv se ha creado correctamente\n");
                        }
                        else
                        {
                            printf("Error al cargar el archivo\n");
                        }
                    }
                    system("pause");
					break;
				case 2:
					filterList=ll_filter(pArrayList, filtrarGeneroComedia);
					if(ll_isEmpty(filterList))
                    {
                        printf("No existen peliculas con ese genero en la lista, por lo tanto no se ha creado el archivo\n");
                    }
                    else
                    {
                        if(controller_saveAsText("movies_comedia.csv", filterList))
                        {
                            printf("El archivo movies_comedia.csv se ha creado correctamente\n");
                        }
                        else
                        {
                            printf("Error al cargar el archivo\n");
                        }
                    }
                    system("pause");
					break;
				case 3:
					filterList=ll_filter(pArrayList, filtrarGeneroAccion);
					if(ll_isEmpty(filterList))
                    {
                        printf("No existen peliculas con ese genero en la lista, por lo tanto no se ha creado el archivo\n");
                    }
                    else
                    {
                        if(controller_saveAsText("movies_accion.csv", filterList))
                        {
                            printf("El archivo movies_accion.csv se ha creado correctamente\n");
                        }
                        else
                        {
                            printf("Error al cargar el archivo\n");
                        }
                    }
                    system("pause");
					break;
				case 4:
					filterList=ll_filter(pArrayList, filtrarGeneroTerror);
					if(ll_isEmpty(filterList))
                    {
                        printf("No existen peliculas con ese genero en la lista, por lo tanto no se ha creado el archivo\n");
                    }
                    else
                    {
                        if(controller_saveAsText("movies_terror.csv", filterList))
                        {
                            printf("El archivo movies_terror.csv se ha creado correctamente\n");
                        }
                        else
                        {
                            printf("Error al cargar el archivo\n");
                        }
                    }
                    system("pause");
					break;
				case 5:
					{
						salir=1;
						break;
					}
				}
			}
			while(salir!=1);
			todoOk=1;
		}
		else
		{
			printf("No hay datos cargados en la lista\n");
		}
	}
    return todoOk;
}

int controller_sort(LinkedList* pArrayList)
{
    int todoOk=0;
    if(pArrayList!=NULL && ll_len(pArrayList)>1)
    {
        ll_sort(pArrayList, movieSortGeneroYRating, 0);
    	todoOk=1;
    }

    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int todoOk=0;
	int tamLista;
	eMovie* aux;
	FILE* f=NULL;
	char encabezados[100]="id,titulo,genero,rating\n";

	if(pArrayList!=NULL)
	{
		tamLista=ll_len(pArrayList);
		if(tamLista>0)
		{
			f=fopen(path, "w");
			if(f!=NULL)
			{
				fprintf(f, encabezados);
				for(int i=0; i<tamLista; i++)
				{
					aux=(eMovie*)ll_get(pArrayList, i);
					if(aux!=NULL)
					{
						if(fprintf(f, "%d,%s,%s,%.2f\n", aux->id_peli, aux->titulo, aux->genero, aux->rating)==-1)
						{
							fclose(f);
							return todoOk;
						}
					}
					else
					{
						fclose(f);
						return todoOk;
					}
				}
				todoOk=1;
			}
			fclose(f);
		}
	}
	return todoOk;
}
