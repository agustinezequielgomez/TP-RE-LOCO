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
eTareas* constructorTareas();

void inicializarTareas(ArrayList* ALtareas);

void calcularCostoTotal(ArrayList* ALtareas, ArrayList* ALobras);

void ordenarCostos(int costos[]);

void costoTotalPlanta(ArrayList* ALtareas, ArrayList* ALobras);

