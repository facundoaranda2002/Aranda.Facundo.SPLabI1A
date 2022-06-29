#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct
{
	int id_peli;
	char titulo[50];
	char genero[50];
	float rating;
}eMovie;

/** \brief Reserva el espacio en memoria dinamica para una nueva pelicula
 *
 * \return eMovie* retorna la nueva pelicula o NULL en caso de error
 *
 */
eMovie* Movie_new();

/** \brief Utiliza los setters para cargar la informacion recibida en una nueva pelicula
 *
 * \param id_peli int
 * \param titulo char*
 * \param genero char*
 * \param rating float
 * \return eMovie* retorna la nueva pelicula o NULL en caso de error
 *
 */
eMovie* Movie_newParametros(int id_peli,char* titulo,char* genero,float rating);

/** \brief Utiliza los setters para cargar la informacion recibida en cadena de caracteres en una nueva pelicula
 *
 * \param id_peliStr char*
 * \param tituloStr char*
 * \param generoStr char*
 * \param ratingStr char*
 * \return eMovie* retorna la nueva pelicula o NULL en caso de error
 *
 */
eMovie* Movie_newParametrosString(char* id_peliStr,char* tituloStr,char* generoStr,char* ratingStr);

/** \brief Libera el espacio de memoria asignado a una pelicula
 *
 * \param m eMovie* pelicula a eliminar
 * \return void
 *
 */
void Movie_delete(eMovie* m);

/** \brief Asigna un valor de id a la pelicula en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param id_peli int
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_setId(eMovie* m,int id_peli);

/** \brief Asigna un valor de id_peli de una pelicula a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param id_peli int*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_getId(eMovie* m, int *id_peli);

/** \brief Asigna un valor de titulo a la pelicula en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param titulo char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_setTitulo(eMovie* m,char* titulo);

/** \brief Asigna un valor de titulo de una pelicula a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param titulo char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_getTitulo(eMovie* m,char* titulo);

/** \brief Asigna un valor de genero a la pelicula en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param genero char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_setGenero(eMovie* m,char* genero);
/** \brief Asigna un valor de genero de una pelicula a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param genero char*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_getGenero(eMovie* m,char* genero);

/** \brief Asigna un valor de rating a la pelicula en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param rating float
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_setRating(eMovie* m,float rating);

/** \brief Asigna un valor de rating de una pelicula a una variable en caso de que se cumplan las validaciones requeridas
 *
 * \param m eMovie* pelicula
 * \param rating float*
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int Movie_getRating(eMovie* m,float* rating);


/** \brief Compara a 2 peliculas por genero y rating
 *
 * \param a void* pelicula A
 * \param b void* pelicula B
 * \return int 1 si el genero de la pelicula A es mayor al del pelicula B o si son del mismo genero y el rating de A es mayor al de B, -1 en caso contrario y 0 si son iguales o hubo algun error
 *
 */
int movieSortGeneroYRating(void* a, void* b);

/** \brief Asigna un rating aleatorio entre 1 y 10(decimal) en el elemento recibido
 *
 * \param a void* elemento recibido
 * \return void* retorna el elemento con el campo rating modificado
 *
 */
void* asignarRating(void* a);

/** \brief Asigna un genero aleatorio segun el numero que se genera aleatoriamente(entre 1 y 4) en el elemento recibido
 *
 * \param a void* elemento recibido
 * \return void* retorna el elemento con el campo genero modificado
 *
 */
void* asignarGenero(void* a);

/** \brief Retorna si el elemento recibido tiene como genero drama o no
 *
 * \param a void* elemento recibido
 * \return int retorna 1 si su genero coincide con drama y 0 si no lo hace
 *
 */
int filtrarGeneroDrama(void* a);

/** \brief Retorna si el elemento recibido tiene como genero comedia o no
 *
 * \param a void* elemento recibido
 * \return int retorna 1 si su genero coincide con comedia y 0 si no lo hace
 *
 */
int filtrarGeneroComedia(void* a);

/** \brief Retorna si el elemento recibido tiene como genero accion o no
 *
 * \param a void* elemento recibido
 * \return int retorna 1 si su genero coincide con comedia y 0 si no lo hace
 *
 */
int filtrarGeneroAccion(void* a);

/** \brief Retorna si el elemento recibido tiene como genero terror o no
 *
 * \param a void* elemento recibido
 * \return int retorna 1 si su genero coincide con terror y 0 si no lo hace
 *
 */
int filtrarGeneroTerror(void* a);

#endif // MOVIES_H_INCLUDED
