#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tipo.h"

void mostrarTipo(eTipo unTipo)
{
    printf("   %d   %s \n",unTipo.id,unTipo.descripcion);
}

int mostrarTipos(eTipo tipos[], int tam_t)
{
    int error = 1;

    if(tipos!= NULL && tam_t > 0)
    {
        system("cls");
        printf("--------------------\n");
        printf("-- ID     Especie  --\n");
        printf("--------------------\n");
        for(int i=0; i<tam_t; i++)
        {
                mostrarTipo(tipos[i]);

        }
        printf("\n");

        error = 0;
    }
    return error;
}

int mostrarTiposModificar(eTipo tipos[], int tam_t)
{
    int error = 1;

    if(tipos!= NULL && tam_t > 0)
    {
        printf(" ID     Especie     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam_t; i++)
        {
                mostrarTipo(tipos[i]);

        }
        printf("\n");

        error = 0;
    }
    return error;
}

int obtenerDescripcionTipo(eTipo tipos[], int tam_t, int idTipo, char descripcionTipo[])
{
    int error = 1;
    if(tipos != NULL && tam_t > 0 && descripcionTipo != NULL)
    {
        for (int i = 0; i<tam_t ; i++)
        {
            if(tipos[i].id == idTipo)
            {
                strcpy(descripcionTipo,tipos[i].descripcion);
                error = 0;
                break;
            }
        }
    }
    return error;
}
