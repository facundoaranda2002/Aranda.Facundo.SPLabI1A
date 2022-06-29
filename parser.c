#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "movies.h"
#include "parser.h"


int parser_MovieFromText(FILE* pFile , LinkedList* pArrayList)
{
	int todoOk=0;
	int cant;
	char buffer[4][50];
	eMovie* pelicula=NULL;

	if(pFile!=NULL && pArrayList!=NULL)
	{
		cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
		while(!feof(pFile))
		{
			cant=fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
			if(cant==4)
			{
				pelicula=Movie_newParametrosString(buffer[0], buffer[1], buffer[2], buffer[3]);
				if(pelicula!=NULL)
				{
					if(ll_add(pArrayList, pelicula)==0)
					{
						todoOk=1;
					}
					else
					{
						todoOk=0;
						break;
					}
				}
				else
				{
					todoOk=0;
					break;
				}
			}
		}

	}
    return todoOk;
}
