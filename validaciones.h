
#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief permite al usuario ingresar un numero entero, valida que sea un numero y que se encuentre entre el maximo y el minimo
 *
 * \param pResultado int* es donde se guarda el numero ingresado
 * \param mensaje char* es el mensaje que pide el ingreso del numero
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \param minimo int es el valor minimo que se le deja ingresar al usuario
 * \param maximo int es el valor maximo que se le deja ingresar al usuario
 * \return int devuelve 1 si no hubo problemas con los punteros y 0 si si los hubo
 *
 */
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief permite al usuario ingresar un numero con decimales, valida que sea un numero y que se encuentre entre el maximo y el minimo
 *
 * \param pResultado float* es donde se guarda el numero ingresado
 * \param mensaje char* es el mensaje que pide el ingreso del numero
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \param minimo int es el valor minimo que se le deja ingresar al usuario
 * \param maximo int es el valor maximo que se le deja ingresar al usuario
 * \return int devuelve 1 si no hubo problemas con los punteros y 0 si si los hubo
 *
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo);

/** \brief permite al usuario ingresar una cadena de caracteres, y valida que se encuentre entre el maximo y el minimo de longitud
 *
 * \param pResultado char* es donde se guarda la cadena de caracteres ingresada
 * \param mensaje char* es el mensaje que pide el ingreso del dato
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \param minimo int es el valor minimo de longitud de cadena que se le deja ingresar al usuario
 * \param maximo int es el valor maximo de longitud de cadena que se le deja ingresar al usuario
 * \return int devuelve 1 si no hubo problemas con los punteros y 0 si si los hubo
 *
 */
int utn_getCadenaChar(char pResultado[], char* mensaje, char* mensajeError, int minimo, int maximo);


/** \brief permite al usuario ingresar una respuesta de si(s) o no(n) y la valida
 *
 * \param pResultado char* es donde se guarda la respuesta validada
 * \param mensaje char* es el mensaje que pide el ingreso del dato
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \return int devuelve 1 si no hubo problemas con los punteros y 0 si si los hubo
 *
 */
int utn_getRespuesta(char* pResultado, char* mensaje, char* mensajeError);

/** \brief permite al usuario ingresar una cadena de caracteres, y valida que se encuentre entre el maximo y el minimo de longitud y que sean solo letras
 *
 * \param pResultado char* es donde se guarda la cadena de caracteres ingresada
 * \param mensaje char* es el mensaje que pide el ingreso del dato
 * \param mensajeError char* es el mensaje que indica al usuario que hubo un error al ingresar el dato
 * \param minimo int es el valor minimo de longitud de cadena que se le deja ingresar al usuario
 * \param maximo int es el valor maximo de longitud de cadena que se le deja ingresar al usuario
 * \return int devuelve 1 si no hubo problemas con los punteros y 0 si si los hubo
 *
 */
int utn_getCadenaCharLetras(char pResultado[], char* mensaje, char* mensajeError, int minimo, int maximo);
