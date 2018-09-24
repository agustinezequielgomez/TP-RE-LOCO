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
    int acumulacion[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(i=1; i<ALobras->size; i++)
    {
        auxObras=al_get(ALobras,i);
        if(auxObras!=NULL)
        {
            for(j=1; j<=50; j++)
            {
                auxTareas=al_get(ALtareas,j);
                if(auxTareas!=NULL && auxObras->codigoDeTarea==auxTareas->codigoDeTarea)
                {
                    acumulacion[j]+=(auxTareas->costoDiario)*auxObras->cantidadDeDias;
                }
            }
        }
    }
    ordenarCostos(acumulacion);
}

void costoTotalPlanta(ArrayList* ALtareas, ArrayList* ALobras)
{
    eTareas* auxTareas;
    eObra* auxObras;
    int total = 0;
    int i;
    int j;
    for(i=1; i<ALobras->size; i++)
    {
        auxObras=al_get(ALobras,i);
        if(auxObras!=NULL)
        {
            for(j=1; j<=50; j++)
            {
                auxTareas=al_get(ALtareas,j);
                if(auxTareas!=NULL && auxObras->codigoDeTarea==auxTareas->codigoDeTarea)
                {
                    total+=((auxTareas->costoDiario)*auxObras->cantidadDeDias);
                }
            }
        }
    }
    printf("\nEl costo total del montaje de la planta es $%d",total);
}

void ordenarCostos(int costos[])
{
    int i;
    int j;
    int aux;
    int auxIndice = 0;
    int indices[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
    for(i=1;i<50;i++)
    {
        for(j=i+1;j<=50;j++)
        {
            if(costos[i]<costos[j])
            {
                aux = costos[i];
                costos[i] = costos[j];
                costos[j] = aux;
                auxIndice = indices[i];
                indices[i] = indices[j];
                indices[j] = auxIndice;
            }
        }
    }

    for(i=1; i<50; i++)
    {
        for(j=i+1; j<=50; j++)
        {
            if(costos[i] == costos[j])
            {
                if(indices[i]>indices[j])
                {
                    aux = costos[i];
                    costos[i] = costos[j];
                    costos[j] = aux;
                    auxIndice = indices[i];
                    indices[i] = indices[j];
                    indices[j] = auxIndice;
                }
            }
        }
    }
    for(i=1;i<=50;i++)
    {
        printf("\nNumero de tarea: %d\tCosto total de la tarea: $%d",indices[i],costos[i]);
    }
}
