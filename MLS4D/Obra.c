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
    eObra* aux;
    do
    {
        aux=constructorObras();
        if(aux!=NULL)
        {
            do
            {
                getInt("\nIngrese el numero de obra (entre 1 y 5) ",&numeroDeObra,"\nIngrese un codigo de tarea valido ");
            }
            while(!(numeroDeObra >=0 && numeroDeObra <= 5));
            if(numeroDeObra != 0)
            {
                getInt("\nIngrese el codigo de tarea (entre 1 y 50) ",&codigoDeTarea,"\nIngrese un codigo de tarea valido ");
                getInt("\nIngrese la cantidad de dias que va a demorar la tarea ",&cantidadDeDias,"\nIngrese una cantidad de dias valida ");
                getInt("\nIngrese el codigo de contratista ",&codigoDeContratista,"\nIngrese un codigo de contratista valido ");
                aux->numeroDeObra = numeroDeObra;
                aux->codigoDeTarea = codigoDeTarea;
                aux->cantidadDeDias = cantidadDeDias;
                aux->codigoDeContratista = codigoDeContratista;
                this->add(this,aux);
            }
            else
            {
                printf("\nAbortando carga de datos..");
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
    float acumulacion[6];
    for(i=1;i<=50;i++)
    {
        auxTareas=al_get(ALtareas,i);
        for(j=1;j<=ALobras->len();j++)
        {
           auxObras=al_get(ALobras,j);
           if(auxObras->codigoDeTarea==auxTareas->codigoDeTarea)
           {
               acumulacion[auxObras->numeroDeObra]+=(auxTareas->costoDiario)*auxObras->cantidadDeDias;
           }
        }
    }

}

void MINIMO(float costos[])
{
    float minimo;
    int menor;
    int i;
    int flag = 0;
    for(i=1;i<6;i++)
    {
        if(flag = 0)
        {
            minimo = costos[i];
            menor = i;
        }
        else if(costos[i] < minimo)
        {
            minimo = costos[i];
            menor = i;
        }
    }
    printf("\nLa obra de menor costo fue la obra Nº%d, y su costo fue de %f",menor,minimo);
}
