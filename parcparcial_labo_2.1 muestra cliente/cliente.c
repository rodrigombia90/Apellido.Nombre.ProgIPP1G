#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "mascotas.h"

void mostrarCliente(eCliente unCliente)
{
    printf(" %-4d   %-12s    %-8c  \n",unCliente.id,unCliente.nombre,unCliente.sexo);
}

int mostrarClientes(eCliente clientes[], int tam_cli)
{
    int error = 1;

    if(clientes!= NULL && tam_cli > 0)
    {
        system("cls");
        printf(" ID     Nombre         Sexo\n");
        printf("---------------------------------\n\n");
        for(int i=0; i<tam_cli; i++)
        {
            if(clientes[i].id!=0)
            {
                mostrarCliente(clientes[i]);
            }
        }
        printf("\n");

        error = 0;
    }
    return error;
}


int obtenerNombreCliente(eCliente clientes[], int tam_cli, int idCliente, char nombreCliente[])
{
    int error = 1;
    if(clientes != NULL && tam_cli > 0 && nombreCliente != NULL)
    {
        for (int i = 0; i<tam_cli ; i++)
        {
            if(clientes[i].id == idCliente)
            {
                strcpy(nombreCliente,clientes[i].nombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}

int obtenerNombreClienteTrabajo(eCliente clientes[], int tam_cli, int idMascotas, char nombreCliente[],eMascota mascotas[],int tam_m)
{
    int error = 1;
    char nombre[10];
    if(clientes != NULL && tam_cli > 0 && nombreCliente != NULL)
    {
        for (int i = 0; i<tam_m ; i++)
        {
            obtenerNombreCliente(clientes,tam_cli,mascotas[i].idCliente,nombre);
            if(mascotas[i].id == idMascotas)
            {
                strcpy(nombreCliente,nombre);
                error = 0;
                break;
            }
        }
    }
    return error;
}

