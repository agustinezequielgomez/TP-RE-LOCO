#include"Funciones.h"
#include"Obra.h"
#include"ArrayList.h"
#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED

typedef struct
{
    int codigoDeTarea;
    int costoDiario;
}eTareas;

#endif // TAREA_H_INCLUDED
/** \brief Funcion que reserva espaacio en memoria para una tarea
 *
 * \return eTareas* Retorna un puntero a un dato del tipo eTarea
 *
 */
eTareas* constructorTareas();

/** \brief Funcion que inicializa las tareas con sus numeros y valores
 *
 * \param ALtareas ArrayList* Lista que contendra las tareas a inicializar
 * \return void
 *
 */
void inicializarTareas(ArrayList* ALtareas);

/** \brief Funcion que calcula el costo total de cada tarea en cada obra
 *
 * \param ALtareas ArrayList* Lista que contendra los datos sobre las tareas
 * \param ALobras ArrayList* Lista que contendra los datos sobre las obras realizadas y las tareas realizadas en cada obra
 * \return void
 *
 */
void calcularCostoTotal(ArrayList* ALtareas, ArrayList* ALobras);

/** \brief Funcion que ordena los costos de cada tarea de manera descendente (Si dos tareas tienen el mismo valor las ordena de manera descendente por numero de tarea)
 *
 * \param costos[] int Arreglo de enteros que contiene los valores por cada tarea
 * \return void
 *
 */
void ordenarCostos(int costos[]);

/** \brief Funcion que calcula el costo total de la planta teniendo en cuenta la suma de todas sus tareas
 *
 * \param ALtareas ArrayList* Lista que contiene los datos sobre las tareas
 * \param ALobras ArrayList* Lista que contiene los datos sobre las obras realizadas
 * \return void
 *
 */
void costoTotalPlanta(ArrayList* ALtareas, ArrayList* ALobras);

