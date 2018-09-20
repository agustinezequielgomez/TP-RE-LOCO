#include <stdio.h>
#include <stdlib.h>
#include"ArrayList.h"
#include"Tarea.h"
#include"Obra.h"
#include"Contratista.h"

int main()
{
    ArrayList* listaObra;
    listaObra = al_newArrayList();
    ArrayList* listaTareas;
    listaTareas = al_newArrayList();
    inicializarTareas(listaTareas);
    int opcion;
    do
    {
        printf("\n1- Cargar datos");
        printf("\n2- Costo total del montaje de la planta");
        printf("\n3- Costo total de cada Tarea");
        printf("\n4- Obra con menor costo");
        printf("\n5- Contratistas que superaron el plazo establecido (150 dias)");
        printf("\n6- Salir");
        getInt("\nIngrese la opcion que desea realizar ",&opcion,"\nOpcion invalida ");
        switch(opcion)
        {
        case 1:
            altaObra(listaObra);
            break;
        case 2:
            costoTotalPlanta(listaTareas,listaObra);
            break;
        case 3:
            calcularCostoTotal(listaTareas,listaObra);
            break;
        case 4:
            calcularCostoMinimo(listaTareas,listaObra);
            break;
        case 5:
            break;
        case 6:
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }while(opcion!=6);
    return 0;
}
