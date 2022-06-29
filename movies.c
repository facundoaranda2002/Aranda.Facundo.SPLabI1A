#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "movies.h"
#include "funcionesExtra.h"


eMovie* Movie_new()
{
	eMovie* nuevaPelicula = (eMovie*) calloc(1,sizeof(eMovie));
    return nuevaPelicula;
}

eMovie* Movie_newParametros(int id_peli,char* titulo,char* genero,float rating)
{
	eMovie* nuevaPelicula = Movie_new();
	if(nuevaPelicula != NULL)
	{
		if(!(Movie_setId(nuevaPelicula, id_peli) &&
				Movie_setTitulo(nuevaPelicula, titulo) &&
				Movie_setGenero(nuevaPelicula, genero) &&
				Movie_setRating(nuevaPelicula, rating) ))
		{
			Movie_delete(nuevaPelicula);
			nuevaPelicula = NULL;
		}
	}
	return nuevaPelicula;
}

eMovie* Movie_newParametrosString(char* id_peliStr,char* tituloStr,char* generoStr,char* ratingStr)
{
	eMovie* nuevaPelicula = Movie_new();
	if(nuevaPelicula != NULL)
	{
		if(!(Movie_setId(nuevaPelicula, atoi(id_peliStr)) &&
				Movie_setTitulo(nuevaPelicula, tituloStr) &&
				Movie_setGenero(nuevaPelicula, generoStr) &&
				Movie_setRating(nuevaPelicula, atof(ratingStr)) ))
		{
			Movie_delete(nuevaPelicula);
			nuevaPelicula = NULL;
		}
	}
	return nuevaPelicula;
}

void Movie_delete(eMovie* m)
{
	free(m);
}

int Movie_setId(eMovie* m,int id_peli)
{
    int todoOk = 0;
    if(m != NULL && id_peli>0)
    {
        m->id_peli = id_peli;
        todoOk = 1;

    }
    return todoOk;
}
int Movie_getId(eMovie* m, int *id_peli)
{
    int todoOk = 0;
    if(m != NULL && id_peli!=NULL)
    {
        *id_peli = m->id_peli;
        todoOk = 1;
    }
    return todoOk;
}


int Movie_setTitulo(eMovie* m,char* titulo)
{
    int todoOk = 0;
    if(m != NULL && titulo != NULL && strlen(titulo) < 51 && strlen(titulo) > 1)
    {
        strcpy(m->titulo, titulo);
        strlwr(m->titulo);
        (m->titulo)[0] = toupper((m->titulo)[0]);

        todoOk = 1;
    }
    return todoOk;
}
int Movie_getTitulo(eMovie* m,char* titulo)
{
    int todoOk = 0;
    if(m != NULL && titulo != NULL)
    {
        strcpy(titulo, m->titulo);
        todoOk = 1;
    }
    return todoOk;
}

int Movie_setGenero(eMovie* m,char* genero)
{
    int todoOk = 0;
    if(m != NULL && genero != NULL && strlen(genero) < 51 && strlen(genero) > 1)
    {
        strcpy(m->genero, genero);
        strlwr(m->genero);
        (m->genero)[0] = toupper((m->genero[0]));

        todoOk = 1;
    }
    return todoOk;
}
int Movie_getGenero(eMovie* m,char* genero)
{
    int todoOk = 0;
    if(m != NULL && genero != NULL)
    {
        strcpy(genero, m->genero);
        todoOk = 1;
    }
    return todoOk;
}

int Movie_setRating(eMovie* m,float rating)
{
    int todoOk = 0;
    if(m != NULL && rating >= 0 && rating <= 10)
    {
        m->rating = rating;
        todoOk = 1;

    }
    return todoOk;
}
int Movie_getRating(eMovie* m,float* rating)
{
    int todoOk = 0;
    if(m != NULL && rating !=NULL)
    {
        *rating = m->rating;
        todoOk = 1;
    }
    return todoOk;
}

int movieSortGeneroYRating(void* a, void* b)
{
    int retorno=0;
    eMovie* movA;
    eMovie* movB;

    if(a!=NULL && b!=NULL)
    {
        movA=(eMovie*) a;
        movB=(eMovie*) b;

        if( ( (stricmp(movA->genero, movB->genero) == 0) && (movA->rating > movB->rating) )
           || (stricmp(movA->genero, movB->genero) > 0)  )
        {
            retorno=1;
        }
        else if(( (stricmp(movA->genero, movB->genero) == 0) && (movA->rating < movB->rating) )
           || (stricmp(movA->genero, movB->genero) < 0)  )
        {
            retorno=-1;
        }
    }

    return retorno;
}


void* asignarRating(void* a)
{
    eMovie* pMovie=NULL;
    if(a!=NULL)
    {
        int min=10;
        int max=100;
        float valor;
        valor=(float)((rand()% (max-min+1))+min)/10;

        pMovie=(eMovie*)a;
        pMovie->rating=valor;


    }
    return pMovie;
}

void* asignarGenero(void* a)
{
    eMovie* pMovie=NULL;
    if(a!=NULL)
    {
        int min=1;
        int max=4;
        int valor;

        valor=(rand()% (max-min+1))+min;

        pMovie=(eMovie*)a;
        switch(valor)
        {
        case 1:
            strcpy(pMovie->genero, "drama");
            break;
        case 2:
            strcpy(pMovie->genero, "comedia");
            break;
        case 3:
            strcpy(pMovie->genero, "accion");
            break;
        case 4:
            strcpy(pMovie->genero, "terror");
            break;
        }

    }
    return pMovie;
}

int filtrarGeneroDrama(void* a)
{
    int rta=0;
    eMovie* pMovie=NULL;
    if(a!=NULL)
    {
        pMovie=(eMovie*)a;
        if(stricmp(pMovie->genero, "drama")==0)
        {
            rta=1;
        }
    }
    return rta;
}

int filtrarGeneroComedia(void* a)
{
    int rta=0;
    eMovie* pMovie=NULL;
    if(a!=NULL)
    {
        pMovie=(eMovie*)a;
        if(stricmp(pMovie->genero, "comedia")==0)
        {
            rta=1;
        }
    }
    return rta;
}

int filtrarGeneroAccion(void* a)
{
    int rta=0;
    eMovie* pMovie=NULL;
    if(a!=NULL)
    {
        pMovie=(eMovie*)a;
        if(stricmp(pMovie->genero, "accion")==0)
        {
            rta=1;
        }
    }
    return rta;
}

int filtrarGeneroTerror(void* a)
{
    int rta=0;
    eMovie* pMovie=NULL;
    if(a!=NULL)
    {
        pMovie=(eMovie*)a;
        if(stricmp(pMovie->genero, "terror")==0)
        {
            rta=1;
        }
    }
    return rta;
}
