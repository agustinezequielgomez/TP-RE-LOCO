#include"Funciones.h"
#include"ArrayList.h"

#ifndef OBRA_H_INCLUDED
#define OBRA_H_INCLUDED

typedef struct
{
    int numeroDeObra;
    int codigoDeTarea;
    int cantidadDeDias;
    int codigoDeContratista;
}eObra;

#endif // OBRA_H_INCLUDED

/** \brief Funcion que reserva espaacio en memoria para una obra
 *
 * \return eObra* Puntero a un dato de tipo eObra
 *
 */
eObra* constructorObras();

/** \brief Funcion mediante la cual se ingresan datos sobre las obras realizdas
 *
 * \param this ArrayList* Lista que en la que se guardaran las obras
 * \return void
 *
 */
void altaObra(ArrayList* this);

/** \brief Funcion que calcula el costo por cada obra
 *
 * \param ALTareas ArrayList* Lista que contiene los datos sobre las tareas
 * \param ALObras ArrayList* Lista que contiene los datos sobre las obras realizadas y las tareas realizadas en cada obra
 * \return void
 *
 */
void calcularCostoMinimo(ArrayList* ALTareas, ArrayList* ALObras);

/** \brief Funcion que calcula el costo minimo de cada obra
 *
 * \param costos[] float Arreglo de enteros conteniendo el valor de cada obra
 * \return void
 *
 */
void MINIMO(float costos[]);

/** \brief Funcion que calcula que contratistas superaron el plazo establecido de 150 dias y los muestra por pantalla
 *
 * \param ALObras ArrayList* Lista que contiene los datos sobre las obras realizadas y las tareas realizadas en cada obra
 * \return void
 *
 */
void contratistasMayorPlazo(ArrayList* ALObras);
