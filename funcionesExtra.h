#include "movies.h"
#include "LinkedList.h"

#ifndef FUNCIONESEXTRA_H_
#define FUNCIONESEXTRA_H_



#endif /* FUNCIONESEXTRA_H_ */

/** \brief Despliega el menu principal
 *
 * \return int retona la opcion elegida por el usuario(previamente validada)
 *
 */
int menu();

/** \brief Recibe una pelicula y la muestra por pantalla
 *
 * \param m eMovie* pelicula
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int mostrarPelicula(eMovie* m);

/** \brief Recibe una lista de peliculas y la muestra por pantalla
 *
 * \param lista LinkedList* lista de peliculas
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int mostrarPeliculas(LinkedList* lista);

/** \brief Despliega el menu de filtrado de peliculas
 *
 * \return int retorna la opcion elegida
 *
 */
int menuFilter();
