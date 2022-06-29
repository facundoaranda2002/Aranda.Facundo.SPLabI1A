/** \brief Carga los datos desde el archivo .csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayList LinkedList* lista de peliculas
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList);

/** \brief Listar peliculas
 *
 * \param pArrayList LinkedList* lista de peliculas
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_List(LinkedList* pArrayList);

/** \brief Asigna un numero con decimales aleatorio entre 1 y 10 en el campo rating de las peliculas y lo muestra por pantalla
 *
 * \param pArrayList LinkedList* lista de peliculas
 * \return int int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_AsignarRating(LinkedList* pArrayList);

/** \brief Asigna un genero de pelicula en el campo genero de las peliculas segun un numero entero aleatorio entre 1 y 4 y lo muestra por pantalla
 *
 * \param pArrayList LinkedList* lista de peliculas
 * \return int int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_AsignarGenero(LinkedList* pArrayList);

/** \brief Crea una lista nueva filtrada por el genero seleccionado y la guarda en un archivo .csv
 *
 * \param pArrayList LinkedList* lista de peliculas
 * \return int int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_FiltrarPorGenero(LinkedList* pArrayList);

/** \brief Ordenar peliculas
 *
 * \param pArrayList LinkedList* lista de peliculas
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_sort(LinkedList* pArrayList);

/** \brief Guarda los datos de las peliculas en el archivo .csv (modo texto).
 *
 * \param path char* nombre del archivo
 * \param pArrayList LinkedList* lista de peliculas
 * \return int 1 si todo OK, 0 si hubo algun error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList);




