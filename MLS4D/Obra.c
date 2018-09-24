#include<stdio.h>
#include"Obra.h"
#include"Tarea.h"

eObra* constructorObras()
{
    eObra* aux;
    aux=(eObra*)malloc(sizeof(eObra));
    return aux;
}

void altaObra(ArrayList* this)
{
    int numeroDeObra;
    int codigoDeTarea;
    int cantidadDeDias;
    int codigoDeContratista;
    int retorno;
    int indice = this->size;
    eObra* aux;
    do
    {
        aux=constructorObras();
        if(aux!=NULL)
        {
            do
            {
                getInt("\nIngrese el numero de obra (entre 1 y 5. Ingresar 0 para abortar la carga de datos) ",&numeroDeObra,"\nIngrese un numero de obra valido ");
            }
            while(!(numeroDeObra >=0 && numeroDeObra <= 5));
            if(numeroDeObra != 0)
            {
                do
                {
                    getInt("\nIngrese el codigo de tarea (entre 1 y 50) ",&codigoDeTarea,"\nIngrese un codigo de tarea valido ");
                }while(!(codigoDeTarea <= 50 && codigoDeTarea >= 1));

                getInt("\nIngrese la cantidad de dias que va a demorar la tarea ",&cantidadDeDias,"\nIngrese una cantidad de dias valida ");
                getInt("\nIngrese el codigo de contratista ",&codigoDeContratista,"\nIngrese un codigo de contratista valido ");
                aux->numeroDeObra = numeroDeObra;
                aux->codigoDeTarea = codigoDeTarea;
                aux->cantidadDeDias = cantidadDeDias;
                aux->codigoDeContratista = codigoDeContratista;
                retorno = this->add(this,aux);
            }
            else
            {
                printf("\nAbortando carga de datos..");
                free(aux);
            }
        }
    }
    while(numeroDeObra!=0);
}

void calcularCostoMinimo(ArrayList* ALtareas, ArrayList* ALobras)
{
    eTareas* auxTareas;
    eObra* auxObras;
    int i;
    int j;
    float acumulacion[] = {0,0,0,0,0,0};
    for(i=1; i<=50; i++)
    {
        auxTareas=al_get(ALtareas,i);
        if(auxTareas!=NULL)
        {
            for(j=1; j<ALobras->size; j++)
            {
                auxObras=al_get(ALobras,j);
                if(auxObras!=NULL && auxObras->codigoDeTarea==auxTareas->codigoDeTarea)
                {
                    acumulacion[auxObras->numeroDeObra]+=(auxTareas->costoDiario)*auxObras->cantidadDeDias;
                }
            }
        }
    }
    MINIMO(acumulacion);
}

void MINIMO(float costos[])
{
    float minimo;
    int menor;
    int i;
    int flag = 0;
    for(i=1;i<6;i++)
    {
        if(flag == 0)
        {
            minimo = costos[i];
            menor = i;
            flag = 1;
        }
        else if(costos[i] < minimo&&costos[i]!=0)
        {
            minimo = costos[i];
            menor = i;
        }
    }
    printf("\nLa obra de menor costo fue la obra Numero %d, y su costo fue de %.2f",menor,minimo);
}

void contratistasMayorPlazo(ArrayList* ALObras)
{
    eObra* auxObra;
    int i;
    printf("\nContratistas que superaron el plazo establecido (150 dias): ");
    for(i=1;i<ALObras->size;i++)
    {
        auxObra = al_get(ALObras,i);
        if(auxObra!=NULL && auxObra->cantidadDeDias>150)
        {
            printf("\nEl contratista %d se supero del plazo establecido en %d dias (%d dias totales)",auxObra->codigoDeContratista,auxObra->cantidadDeDias-150,auxObra->cantidadDeDias);
        }
    }
}
