#include<stdio.h>
#include"Tarea.h"

eTareas* constructorTareas()
{
    eTareas* aux;
    aux=(eTareas*)malloc(sizeof(eTareas));
    return aux;
}

void inicializarTareas(ArrayList* ALtareas)
{
    eTareas* aux;
    int i;
    for(i=1; i<=50;i++)
    {
        aux=constructorTareas();
        if(aux!=NULL)
        {
            aux->codigoDeTarea=i;
            aux->costoDiario=i;
            ALtareas->add(ALtareas,aux);
        }
    }
}

void calcularCostoTotal(ArrayList* ALtareas, ArrayList* ALobras)
{
    eTareas* auxTareas;
    eObra* auxObras;
    int i;
    int j;
    int acumulacion[50];
    for(i=1;i<=ALobras->len();i++)
    {
        auxObras=al_get(ALobras,i);
        for(j=1;j<=50;j++)
        {
           auxTareas=al_get(ALtareas,i);
           if(auxObras->codigoDeTarea==auxTareas->codigoDeTarea)
           {
               acumulacion[j]+=(auxTareas->costoDiario)*auxObras->cantidadDeDias;
           }
        }
    }
    ordenarCostos(acumulacion);
}

void costoTotalPlanta(ArrayList* ALtareas, ArrayList* ALobras)
{
    eTareas* auxTareas;
    eObra* auxObras;
    int total;
    int i;
    int j;
    int acumulacion[51];
    for(i=1;i<=ALobras->len();i++)
    {
        auxObras=al_get(ALobras,i);
        for(j=1;j<=50;j++)
        {
           auxTareas=al_get(ALtareas,i);
           if(auxObras->codigoDeTarea==auxTareas->codigoDeTarea)
           {
               acumulacion[j]+=(auxTareas->costoDiario)*auxObras->cantidadDeDias;
           }
        }
    }
    for(j=1;j<=50;j++)
    {
        total += acumulacion[j];
    }
    printf("\nEl costo total del montaje de la planta es %d",total);
}

void ordenarCostos(int costos[])
{
    int i;
    int j;
    int aux;
    for(i=0;i<50;i++)
    {
        for(j=i+1;j<=50;j++)
        {
            if(costos[i]<costos[j])
            {
                aux = costos[i];
                costos[i] = costos[j];
                costos[j] = aux;
            }
        }
    }
    for(i=0;i<50;i++)
    {
        printf("\nNumero de tarea: %d\tCosto total de la tarea: $%d",i,costos[i]);
    }
}
