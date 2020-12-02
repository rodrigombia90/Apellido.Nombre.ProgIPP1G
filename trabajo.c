#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "trabajo.h"
#include "servicio.h"
#include "input.h"

int inicializarTrabajos(eTrabajo trabajos[], int tam_t)
{
    int error = 1;
    if (trabajos!=NULL && tam_t > 0)
    {
        for(int i=0; i<tam_t; i++)
        {
            trabajos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam_t)
{
    int indice = -1;
    for(int i = 0; i < tam_t; i++)
    {
        if(trabajos[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarTrabajo(eTrabajo trabajos[], int tam_t)
{
    int error = 1;
    for(int i = 0; i < tam_t; i++)
    {
        if(trabajos[i].isEmpty == 0)
        {
            error = 0;
            break;
        }
    }
    return error;
}

int altaTrabajo(eMascota mascotas[],int tam_m,int idTrabajo,eTipo tipos[],int tam_t,eColor color[],int tam_c, eServicio servicios[],int tam_s, eTrabajo trabajos[],int tam_tra,eCliente clientes[],int tam_cli)
{
    int error=-1;
    int indiceTrabajo;
    eTrabajo nuevoTrabajo;

    if(trabajos != NULL && tam_t>0)
    {
        system("cls");
        indiceTrabajo=buscarLibreTrabajo(trabajos,tam_t);
        if(indiceTrabajo==-1)
        {
            printf("No hay lugar para trabajos");
        }
        else
        {
            nuevoTrabajo.idMascota=getIdMascota(mascotas,tam_m,color,tam_c,tipos,tam_t,clientes,tam_cli);
            nuevoTrabajo.idServicio=getIdServicio(servicios,tam_s);
            system("cls");
            printf("ingrese la fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d/",&nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);
            while(validarFecha(nuevoTrabajo.fecha.dia,nuevoTrabajo.fecha.mes,nuevoTrabajo.fecha.anio)!=0)
            {
                printf("Error, ingrese la fecha valida: dd/mm/aaaa");
                scanf("%d/%d/%d/",&nuevoTrabajo.fecha.dia,&nuevoTrabajo.fecha.mes,&nuevoTrabajo.fecha.anio);
            }
            nuevoTrabajo.isEmpty=0;
            nuevoTrabajo.id=idTrabajo;
            trabajos[indiceTrabajo]=nuevoTrabajo;
        }
        error=0;
    }
    return error;
}



int mostrarTrabajos(eTrabajo trabajos[], int tam_t, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m,eCliente cliente[],int tam_cli)
{
    int error = 0;

    if( trabajos != NULL && tam_t > 0)
    {

        if(buscarTrabajo(trabajos,tam_m)==1)
        {
            system("cls");
            printf("\n\n  ACTUALMENTE, NO HAY trabajos\n\n");
        }
        else
        {
            system("cls");
            printf("     ID       NOMBRE         SERVICIO                FECHA   \n");
            printf("-----------------------------------------------------------\n\n");

            for(int i=0; i<tam_t; i++)
            {
                if(trabajos[i].isEmpty == 0)
                {
                    mostrarTrabajo(trabajos[i], servicios, tam_s,mascotas,tam_m,cliente,tam_cli);
                }
            }
        }
        printf("\n\n\n\n\n\n");

        error = 0;

    }

    return error;
}

void mostrarTrabajo(eTrabajo trabajo, eServicio servicios[], int tam_s,eMascota mascotas[], int tam_m,eCliente cliente[],int tam_cli)
{
    char descripcionServ[20];
    char nombreMascota[20];
    char nombreCliente[20];

    if(obtenerDescripcionServicio(servicios,tam_s,trabajo.idServicio,descripcionServ)==0 &&
            obtenerNombreMascota(mascotas,tam_m,trabajo.idMascota,nombreMascota)==0 &&
       obtenerNombreClienteTrabajo(cliente,tam_cli,trabajo.idMascota,nombreCliente,mascotas,tam_m)==0)
    {
        printf("    %2d         %4s        %8s      %s      %10d/%d/%d\n",
               trabajo.id,
               nombreMascota,
               descripcionServ,
               nombreCliente,
               trabajo.fecha.dia,
               trabajo.fecha.mes,
               trabajo.fecha.anio);
    }
    else
    {
        printf("problema para obtener descripciones");
    }

}



int listarTrabajosParaCadaMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli)
{
    int error=0;
    int auxId;
    int flagTrabajo=0;
    if(mascotas!=NULL&&trabajos!=NULL&&tam_t>0&&tam_c>0)
    {
        printf("***Trabajos que se le realizaron a una mascota***\n\n");
        auxId=getIdMascota(mascotas,tam_m,colores,tam_c,tipos,tam_t,clientes,tam_cli);
        for(int i=0; i<tam_m; i++)
        {
            if(trabajos[i].idMascota==auxId && trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_s,mascotas,tam_m,clientes,tam_cli);
                flagTrabajo=1;
            }
            if(!flagTrabajo)
            {
                printf("No se le realizaron trabajos a esa mascota\n");
                break;
            }
        }
    }
    return error;
}

//void mostrarMascotax(eMascota mascota, eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli);
//int mostrarMascotasx(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli);

int listarDineroInvertidoPorMascota (eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s, eCliente clientes[], int tam_cli)
{
    int error=0;
    float precioTotal=0;
    int auxId;
    char auxNombre[10];
    if(mascotas!=NULL&&trabajos!=NULL&&tam_t>0&&tam_c>0)
    {
        system("cls");
        printf("***Dinero invertido en una mascota***\n\n");
        mostrarMascotas(mascotas,tam_m,tipos,tam_t,colores,tam_c, clientes,tam_cli);
        printf("Ingrese ID de mascota: ");
        scanf("%d",&auxId);
        for(int i=0; i<tam_t; i++)
        {
            if(trabajos[i].isEmpty==0 && trabajos[i].idMascota==auxId)
            {
                for(int s=0; s<tam_s; s++)
                {
                    if(servicios[s].id==trabajos[s].idServicio)
                    {
                        precioTotal+=servicios[s].precio;
                        error=1;
                    }
                }
            }
        }
        obtenerNombreMascota(mascotas,tam_m,auxId,auxNombre);
        printf("El dinero invertido en %s es:$ %.2f\n",auxNombre,precioTotal);

    }
    return error;
}


int listarTrabajosRealizadosEnUnaFecha(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c, eTrabajo trabajos[], int tam_tra,eServicio servicios[], int tam_s,eCliente clientes[],int tam_cli)
{
    int error=0;
    eTrabajo auxTrabajo;
    int flagTrabajo=0;
    if(mascotas!=NULL&&trabajos!=NULL&&tam_t>0&&tam_c>0)
    {
        system("cls");
        printf("ingrese la fecha dd/mm/aaaa");
        scanf("%d/%d/%d/",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
        while(validarFecha(auxTrabajo.fecha.dia,auxTrabajo.fecha.mes,auxTrabajo.fecha.anio)!=0)
        {
            printf("Error, ingrese la fecha valida: dd/mm/aaaa");
            scanf("%d/%d/%d/",&auxTrabajo.fecha.dia,&auxTrabajo.fecha.mes,&auxTrabajo.fecha.anio);
        }
        printf("     ID       NOMBRE         SERVICIO          FECHA   \n");
        printf("---------------------------------------------------------\n\n");

        for(int i=0;i<tam_tra;i++)
        {
            if(trabajos[i].fecha.anio==auxTrabajo.fecha.anio && trabajos[i].fecha.dia==auxTrabajo.fecha.dia && trabajos[i].fecha.mes==auxTrabajo.fecha.mes)
            {
                mostrarTrabajo(trabajos[i],servicios,tam_s,mascotas,tam_m,clientes,tam_cli);
                flagTrabajo=1;
            }
            if(!flagTrabajo)
            {
                printf("No se le realizaron trabajos en esa fecha\n");
                break;
            }
        }

    }

    return error;
}

