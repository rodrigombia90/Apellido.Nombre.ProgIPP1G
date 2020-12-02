#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "servicio.h"


void mostrarServicio(eServicio unServicio)
{
    printf(" %d   %-13s   %-15d\n",unServicio.id,unServicio.descripcion,unServicio.precio);
}

int mostrarServicios(eServicio servicios[], int tam_s)
{
    int error = 1;

    if(servicios!= NULL && tam_s > 0)
    {
        system("cls");
        printf(" ID      Servicio      Precio \n");
        printf("-------------------------------\n\n");
        for(int i=0; i<tam_s; i++)
        {
                mostrarServicio(servicios[i]);

        }
        printf("\n");

        error = 0;
    }
    return error;
}

int buscarServicios(eServicio servicios[],int tam_s,int idServicio)
{
    int indice=-1;

    for(int i=0;i<tam_s;i++)
    {
        if(servicios[i].id==idServicio)
        {
            indice=i;
            break;
        }
    }
        return indice;
}

int obtenerDescripcionServicio(eServicio servicios[], int tam_s, int idServicio, char nombreServicio[])
{
    int error = 1;
    if(servicios != NULL && tam_s > 0 && nombreServicio != NULL)
    {

        for (int i = 0; i<tam_s ; i++)
        {
            if(servicios[i].id == idServicio)
            {
                strcpy(nombreServicio,servicios[i].descripcion);
                error = 0;
                break;
            }
        }
    }

    return error;

}


int obtenerPrecioServicio(eServicio servicios[], int tam_s, int idServicio, char precio)
{
    int error = 1;
    if(servicios != NULL && tam_s > 0 && precio >0)
    {

        for (int i = 0; i<tam_s ; i++)
        {
            if(servicios[i].id == idServicio)
            {
                precio=servicios[i].precio;
                error = 0;
                break;
            }
        }
    }

    return error;

}

int getIdServicio(eServicio servicios[],int tam_s)
{
    int auxId;
    mostrarServicios(servicios,tam_s);
    auxId=getIntNew("Ingrese id","Error, ingrese id valido");
    while(buscarServicios(servicios,tam_s,auxId)==-1)
    {
        auxId=getIntNew("Ingrese id valido","Error, ingrese id valido");
    }

    return auxId;
}
