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

eObra* constructorObras();

void altaObra(ArrayList* this);

void calcularCostoMinimo(ArrayList* ALTareas, ArrayList* ALObras);

void MINIMO(float costos[]);
