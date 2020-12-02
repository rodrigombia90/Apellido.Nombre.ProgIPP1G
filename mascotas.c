#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "mascotas.h"
#include "input.h"
#include "tipo.h"
#include "color.h"
#include "dataAnimales.h"
#include "servicio.h"
#include "trabajo.h"

int inicializarMascotas(eMascota mascotas[], int tam_m)
{
    int error = 1;
    if (mascotas!=NULL && tam_m > 0)
    {
        for(int i=5; i<tam_m; i++)
        {
            mascotas[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}



int harcodearMascotas(eMascota mascotas[],int tam_m,int cantidad)
{
    int error=-1;
    if(mascotas!= NULL && tam_m>0 && cantidad >= 0 && cantidad <= tam_m)
    {
        error=0;
        for(int i=0; i<cantidad; i++)
        {
            mascotas[i].id= idMascotas[i];
            strcpy(mascotas[i].nombre,nombresAnimales[i]);
            mascotas[i].idTipo= idTipoMascotas[i];
            mascotas[i].idColor=idColorMascotas[i];
            mascotas[i].edad=edadAnimales[i];
            mascotas[i].isEmpty=0;
            mascotas[i].idCliente=idClientes[i];
            error++;
        }
    }
    return error;//esto retorna a partir del ultimo dato harcodeado
}

int buscarMascota(eMascota mascotas[],int tam_m,int idMascotas)
{
    int indice=-1;

    for(int i=0; i<tam_m; i++)
    {
        if(mascotas[i].id==idMascotas &&mascotas[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


int buscarCliente(eCliente clientes[],int tam_cli,int idCliente)
{
    int indice=-1;

    for(int i=0; i<tam_cli; i++)
    {
        if(clientes[i].id==idCliente)
        {
            indice=i;
            break;
        }
    }
    return indice;
}


int altaMascota(eMascota mascotas[],int tam_m,int idMascota,eTipo tipos[],int tam_t,eColor color[],int tam_c, eCliente clientes[], int tam_cli)
{
    int error=-1;
    int indice;
    eMascota nuevaMascota;

    if(mascotas != NULL && tam_m>0)
    {
        system("cls");
        indice=buscarLibre(mascotas,tam_m);

        if(indice==-1)
        {
            printf("No hay lugar");
        }
        else
        {
            nuevaMascota.isEmpty=0;
            nuevaMascota.id=idMascota;
            fflush(stdin);
            system("cls");
            printf("\n***Alta de mascota***\n");
            fflush(stdin);
            getString(nuevaMascota.nombre,sizeof(nuevaMascota.nombre),"\nINGRESE nombre de mascota:","Error,ingrese nombre valido");
            //system("cls");
            mostrarTipos(tipos,tam_t);
            utn_getNumeroInt(&nuevaMascota.idTipo,"\n\n    Ingrese tipo de mascota: ","Error, ingrese numero valido",1000,1004,5);
            //system("cls");
            mostrarColores(color,tam_c);
            utn_getNumeroInt(&nuevaMascota.idColor,"\n\n    Ingrese color de mascota: ","Error, ingrese numero valido",5000,5004,5);
            //system("cls");
            utn_getNumeroInt(&nuevaMascota.edad,"\n\n    Ingrese edad de mascota: ","Error, ingrese numero valido",1,25,5);
            nuevaMascota.idCliente=getIdCliente(clientes,tam_cli);
            mascotas[indice]=nuevaMascota;
            error=0;
        }
    }

    return error;
}

int buscarLibre(eMascota mascotas[], int tam_m)
{
    int indice = -1;
    for(int i = 0; i < tam_m; i++)
    {
        if(mascotas[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}





int mostrarMascotas(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli)
{
    int error=1;
    int flag=0;
    if(mascotas!=NULL &&tam_m>0)
    {

        printf("\n                    Listado de mascotas                     \n");
        printf("\n    ID       nombre           tipo           color       edad       Cliente\n\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i<tam_m; i++)
        {
            if(mascotas[i].isEmpty==0)
            {
                mostrarMascota(mascotas[i],tipos,tam_t,colores,tam_c,clientes,tam_cli);
                flag=1;
            }

        }
        if(flag==0)
        {
            printf("no hay mascotas\n\n");
        }

        error=0;
    }
    printf("\n\n");

    return error;
}




void mostrarMascota(eMascota mascota, eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli)
{
    char nombreColor[20];
    char descripcionTipo[20];
    char nombreCliente[20];

    if(obtenerDescripcionTipo(tipos,tam_t,mascota.idTipo,descripcionTipo)==0 &&
            obtenerDescripcionColor(colores,tam_c,mascota.idColor,nombreColor)==0 &&
       obtenerNombreCliente(clientes,tam_cli,mascota.idCliente,nombreCliente)==0 )
    {
        printf("    %-2d       %-10s       %-8s       %-5s        %-5d     %-8s\n",
               mascota.id,
               mascota.nombre,
               descripcionTipo,
               nombreColor,
               mascota.edad,
               nombreCliente);
    }

}


int modificarMascota(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t, eColor colores[], int tam_c,eCliente clientes[], int tam_cli)
{
    int error = 1;
    int idModificar;
    int indice;
    char seguir = 's';

    if(mascotas != NULL && tam_t > 0)
    {
        system("cls");
        mostrarMascotas(mascotas,tam_m,tipos,tam_t,colores,tam_c,clientes,tam_cli);
        printf("Ingrese el ID de la mascota a modificar: ");
        scanf("%d",&idModificar);

        indice=buscarMascota(mascotas,tam_m,idModificar);

        if( indice == -1)
        {
            printf("\n\n\n Error-ID inexistente.\n\n\n");
        }
        else
        {
            system("cls");
            printf("\n\n");
        printf("\n    ID       nombre           tipo           color       edad       Cliente\n\n");
        printf("--------------------------------------------------------------------------------\n");
            mostrarMascota(mascotas[indice],tipos,tam_t,colores,tam_c,clientes,tam_cli);
            printf("\n\n");

            do
            {
                switch(menuModificar())
                {
                case 'A':
                    modificarTipo(mascotas, tam_m,indice,tipos,tam_t);
                    seguir = 'n';
                    error = 0;
                    system("cls");
                    break;
                case 'B':
                    modificarEdad(mascotas,tam_m,indice);
                    seguir = 'n';
                    error = 0;
                    system("cls");
                    break;
                case 'C':
                    modificarCliente(mascotas,tam_m,indice,clientes,tam_cli);
                    seguir = 'n';
                    error = 0;
                    system("cls");
                    break;
                default:
                    system("cls");
                    printf("\n\n\nOpcion no valida\n\n\n");
                    break;
                }

            }
            while( seguir == 's');
        }
    }

    return error;

}



int menuModificar()
{
    char opcion;

    printf("*** Modificar mascota ***\n\n");
    printf("A tipo\n");
    printf("B edad \n");
    printf("C cliente \n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = toupper(getchar());

    return opcion;

}




int modificarTipo(eMascota mascotas[], int tam_m, int indice,eTipo tipos[],int tam_t)
{

    int error = 1;
    int confirma;
    int nuevoTipo;

    printf("\n\n");
    mostrarTiposModificar(tipos,tam_t);
    printf("Ingrese nuevo tipo: ");
    scanf("%d", &nuevoTipo);
    system("cls");
    printf("\nConfirma modificacion de tipo?\n\n");
    printf("1-SI\n");
    printf("2-NO\n\n");
    utn_getNumeroInt(&confirma,"Respuesta: ","Error, ingrese opcion valida\n",1,2,5);
    if(confirma==1)
    {
        mascotas[indice].idTipo = nuevoTipo;
        error = 0;
    }
    else
    {
        error = 2;
    }

    if(error==0)
    {
        system("cls");
        printf("\n\nModificacion de tipo exitosa\n\n\n\n");
        system("pause");
    }
    else if(error==2)
    {
        system("cls");
        printf("\n\nModificacion de tipo candelada por el ususario\n\n\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la modificacion del tipo\n\n\n\n");
        system("pause");
    }

    return error;
}



int modificarEdad(eMascota mascotas[],int tam_m,int indice)
{
    int error = 1;
    int confirma;
    int auxEdad;
    printf("\n\n");
    printf("\nIngrese la nueva edad: ");
    scanf("%d",&auxEdad);
    printf("\nConfirma modificacion de edad?\n\n");
    printf("1-SI\n");
    printf("2-NO\n\n");
    utn_getNumeroInt(&confirma,"Respuesta: ","Error, ingrese opcion valida\n",1,2,5);
    if(confirma==1)
    {
        mascotas[indice].edad = auxEdad;
        error = 0;
    }
    else
    {
        error = 2;
    }

    if(error==0)
    {
        system("cls");
        printf("\n\nModificacion de edad exitosa\n\n\n\n");
        system("pause");
    }
    else if(error==2)
    {
        system("cls");
        printf("\n\nModificacion cancelada por el usuario\n\n\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la modificacion\n\n\n\n");
        system("pause");
    }

    return error;
}



int modificarCliente(eMascota mascotas[],int tam_m,int indice,eCliente clientes[],int tam_cli)
{
    int error = 1;
    int confirma;
    int auxCliente;

    printf("\n\n");
    system("cls");
    mostrarClientes(clientes,tam_cli);
    printf("\nIngrese la nueva edad: ");
    scanf("%d", &auxCliente);
    printf("\nConfirma modificacion de Cliente?\n\n");
    printf("1-SI\n");
    printf("2-NO\n\n");
    utn_getNumeroInt(&confirma,"Respuesta: ","Error, ingrese opcion valida\n",1,2,5);
    if(confirma==1)
    {
        mascotas[indice].idCliente = auxCliente;
        error = 0;
    }
    else
    {
        error = 2;
    }

    if(error==0)
    {
        system("cls");
        printf("\n\nModificacion de cliente exitosa\n\n\n\n");
        system("pause");
    }
    else if(error==2)
    {
        system("cls");
        printf("\n\nModificacion cancelada por el usuario\n\n\n\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la modificacion\n\n\n\n");
        system("pause");
    }

    return error;
}




int bajaMascota(eMascota mascotas[],int tam_m,eTipo tipos[],int tam_t,eColor color[],int tam_c, eCliente clientes[],int tam_cli)
{
   int error=1;
   int idBaja;
   int indice;
   int confirma;
   if(mascotas!=NULL &&tam_m>0)
   {
       system("cls");
       printf(" *** Baja Mascotas ***");
       mostrarMascotas(mascotas,tam_m,tipos,tam_t,color,tam_c,clientes,tam_cli);
       printf("Ingrese id para dar de baja: ");
       scanf("%d",&idBaja);
       indice=buscarMascota(mascotas,tam_m,idBaja);
       if(indice==-1)
       {
           printf("No existe el id");

       }
       else
        {
            system("cls");
            printf("\n    ID       nombre           tipo           color        edad\n\n");
            printf("-----------------------------------------------------------------------\n");
            mostrarMascota(mascotas[indice],tipos,tam_t,color,tam_c,clientes,tam_cli);
            printf("\n\nConfirma baja de mascota?\n\n");
            printf("1-SI\n");
            printf("2-NO\n\n");
            printf("Respuesta: ");
            scanf("%d", &confirma);
            if(confirma == 1)
            {
                mascotas[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
       }
   }
   if(error==0)
    {
        system("cls");
        printf("\n\nBaja exitosa\n\n\n\n");
    }else if(error==2)
    {
        system("cls");
        printf("\n\nBaja cancelada por el usuario\n\n\n\n");
    }
    else
    {
        system("cls");
        printf("\n\nHa ocurrido un error en la baja\n\n\n\n");
    }

    return error;
}




int ordenarMascotas(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t)
{
    int error = 1;
    eMascota auxMascota;
    char tipoI[20];
    char tipoJ[20];

    if(mascotas!=NULL && tam_m>0)
    {
        for(int i=0; i<tam_m -1 ; i++)
        {
            for(int j=i+1; j<tam_m; j++)
            {
                obtenerDescripcionTipo(tipos, tam_t,mascotas[i].idTipo, tipoI);
                obtenerDescripcionTipo(tipos, tam_t,mascotas[j].idTipo, tipoJ);
                if(strcmp(tipoI,tipoJ)>0)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }else if(strcmp(tipoI,tipoJ)==0 && strcmp(mascotas[i].nombre,mascotas[j].nombre)==1)
                {
                    auxMascota = mascotas[i];
                    mascotas[i] = mascotas[j];
                    mascotas[j] = auxMascota;
                }
            }
        }
        error = 0;
    }

    return error;

}


int obtenerNombreMascota(eMascota mascotas[], int tam_m, int idMascotas, char nombreMascota[])
{
    int error = 1;
    if(mascotas != NULL && tam_m > 0 && nombreMascota != NULL)
    {
        for (int i = 0; i<tam_m ; i++)
        {
            if(mascotas[i].id == idMascotas)
            {   strcpy(nombreMascota,mascotas[i].nombre);
                error = 0;
                break;
            }
        }
    }

    return error;

}

int getIdMascota(eMascota mascotas[],int tam_m,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli)
{
    int auxId;
    mostrarMascotas(mascotas,tam_m,tipos,tam_t,colores,tam_c,clientes,tam_cli);
    auxId=getIntNew("Ingrese id","Error, ingrese id valido");
    while(buscarMascota(mascotas,tam_m,auxId)==-1)
    {
        auxId=getIntNew("Ingrese id valido","Error, ingrese id valido");
    }

    return auxId;
}




int getIdCliente(eCliente clientes[],int tam_cli)
{
    int auxId;
    mostrarClientes(clientes,tam_cli);
    auxId=getIntNew("Ingrese id","Error, ingrese id valido");
    while(buscarCliente(clientes,tam_cli,auxId)==-1)
    {
        auxId=getIntNew("Ingrese id valido","Error, ingrese id valido");
    }

    return auxId;
}


int listarMascotasXColor(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli)
{
    int error=1;
    int idColorMascotas;
    char descripcionColor[20];
    int bandera=0;
    if(colores!=NULL&&colores!=NULL&&tam_m>0&&tam_c>0)
    {
        system("cls");
        mostrarColores(colores,tam_c);
        fflush(stdin);
        utn_getNumeroInt(&idColorMascotas,"Ingrese el ID del Color: ","\nError, ingrese numero valido\n",5000,5001,5);
        obtenerDescripcionColor(colores,tam_c,idColorMascotas,descripcionColor);
        printf("Mascotas de color %s son\n",descripcionColor);
            printf("\n    ID       nombre           tipo           color        edad\n\n");
            printf("--------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tam_m; i++)
        {
            if(mascotas[i].isEmpty==0&&mascotas[i].idColor==idColorMascotas)
            {
                mostrarMascota(mascotas[i],tipos,tam_t,colores,tam_c,clientes,tam_cli);
                bandera=1;
            }
        }
        if(bandera==0)
        {
            printf("No hay mascotas del color %s\n",descripcionColor);
        }
        printf("\n\n");
        error=0;
    }
    return error;
}


int listarMascotasXTipo(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli)
{
    int error=1;
    int idTipoMascota;
    char descripcionTipo[20];
    int bandera=0;
    if(colores!=NULL&&colores!=NULL&&tam_m>0&&tam_c>0)
    {
        system("cls");
        mostrarTipos(tipos,tam_t);
        fflush(stdin);
        utn_getNumeroInt(&idTipoMascota,"Ingrese el ID del Tipo: ","\nError, ingrese numero valido\n",1000,1004,5);
        obtenerDescripcionTipo(tipos,tam_t,idTipoMascota,descripcionTipo);
        printf("Mascotas de tipo %s son\n",descripcionTipo);
            printf("\n    ID       nombre           tipo           color        edad\n\n");
            printf("--------------------------------------------------------------------------------\n\n");
        for(int i=0; i<tam_m; i++)
        {
            if(mascotas[i].isEmpty==0&&mascotas[i].idTipo==idTipoMascota)
            {
                mostrarMascota(mascotas[i],tipos,tam_t,colores,tam_c,clientes,tam_cli);
                bandera=1;
            }

        }
        if(bandera==0)
        {
            printf("No hay mascotas del tipo %s\n",descripcionTipo);
        }
        printf("\n\n");
        error=0;
    }
    return error;
}


int listarMascotaMasJoven(eMascota mascotas[], int tam_m, eColor colores[], int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tam_cli)
{
    int error=1;
    int primerMascota;
    int flag=0;

    if(mascotas !=NULL && tam_m >0 && colores !=NULL && tam_c >0 && tipos !=NULL && tam_t >0)
    {
        printf("\n                    Listado de mascotas                     \n");
            printf("\n    ID       nombre           tipo           color        edad\n\n");
            printf("--------------------------------------------------------------------------------\n\n");
        for(int i=0 ;i<tam_m-1;i++)
        {
            if(flag==0)
            {
                primerMascota=mascotas[i].edad;
                flag=1;
            }
            else
            {
                if(primerMascota>mascotas[i].edad)
                {
                    primerMascota=mascotas[i].edad;
                    mostrarMascota(mascotas[i],tipos,tam_t,colores,tam_c,clientes,tam_cli);
                }
                else{
                    if(primerMascota==mascotas[i].edad)
                    {
                        primerMascota=mascotas[i].edad;
                        mostrarMascota(mascotas[i],tipos,tam_t,colores,tam_c,clientes,tam_cli);
                    }
                }
            }
        }
        printf("\n\n");
        error=0;
    }
    return error;
}


int listarTodasLasMascotasXtipo(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tam_cli)
{
    int error=1;
    //int idTipoNuevo;
    char descripcionTipo[20];
    int bandera=0;
    if(mascotas!=NULL && tam_m>0 && tipos!=NULL && tam_t>0)
    {
        system("cls");
        printf("***Listado de mascotas de cada tipo***\n");
            printf("\n    ID       nombre           tipo           color        edad\n\n");
            printf("--------------------------------------------------------------------------------\n\n");
        for(int t=0; t<tam_t; t++)
        {
            bandera=0;
            obtenerDescripcionTipo(tipos,tam_t,tipos[t].id,descripcionTipo);
            printf("Tipo: %s\n",descripcionTipo);
            for(int i=0; i<tam_m; i++)
            {
                if(mascotas[i].isEmpty==0&&mascotas[i].idTipo==tipos[t].id)
                {
                    mostrarMascota(mascotas[i],tipos,tam_t,colores,tam_c,clientes,tam_cli);
                    bandera=1;
                }
            }
            if(bandera==0)
            {
                printf("No hay mascotas %s\n",descripcionTipo);
            }
            printf("\n\n");
        }
        error=0;
    }
    return error;
}

int contarMascotasXTipoYColor(eMascota mascotas[], int tam_m, eTipo tipos[], int tam_t,eColor colores[],int tam_c)
{
    int error=1;
    int idTipoNuevo;
    int idColorNuevo;
    char nombreTipo[20];
    char nombreColor[20];
    int contador=0;
    if(tipos!=NULL&&tipos!=NULL&&tam_m>0&&tam_t>0)
    {
        system("cls");
        printf("***Cantidad de mascotas por tipo y color***\n");
        mostrarTipos(tipos,tam_t);
        fflush(stdin);
        utn_getNumeroInt(&idTipoNuevo,"Ingrese el ID del Tipo: ","\nError, ingrese numero valido\n",1000,1004,5);
        mostrarColores(colores,tam_c);
        fflush(stdin);
        utn_getNumeroInt(&idColorNuevo,"\nIngrese el ID del Color: ","\nError, ingrese numero valido\n",5000,5001,5);
        obtenerDescripcionColor(colores,tam_c,idColorNuevo,nombreColor);
        obtenerDescripcionTipo(tipos,tam_t,idTipoNuevo,nombreTipo);
        printf("\nMascotas del tipo %s y del color %s :",nombreTipo,nombreColor);
        for(int i=0; i<tam_m; i++)
        {
            if(mascotas[i].isEmpty==0&&mascotas[i].idTipo==idTipoNuevo && mascotas[i].idColor==idColorNuevo)
            {
                contador++;
            }
        }
        printf(" %d\n\n",contador);
        system("pause");
        error=0;
    }
    return error;
}


int coloresConMasMascotas(eMascota mascotas[], int tam_m, eColor color[], int tam_c)
{
    int error=1;
    int mayor;
    int contadores[tam_c];
    int flag=0;
    for(int i=0; i<tam_m; i++)
    {
        contadores[i]=0;
    }
    if(mascotas!=NULL&&color!=NULL&&tam_m>0&&tam_c>0)
    {
        system("cls");
        printf("*** Colores con mas mascotas ***\n");
        for(int c=0; c<tam_c; c++)
        {

            for(int m=0; m<tam_m; m++)
            {
                if(mascotas[m].isEmpty==0&&mascotas[m].idColor==color[c].id)
                {
                   contadores[c]++;
                }
            }
        }

        for(int i=0;i<tam_c;i++)
        {
            if(contadores[i]>mayor || flag==0)

            {
                mayor=contadores[i];
                flag=1;
            }
        }
        printf("El o los colores con mas mascotas son: \n\n");
        for(int i=0;i<tam_c;i++)
        {
            if(contadores[i] == mayor)
            {
                printf("%s\n",color[i].nombreColor);
            }
        }

        printf("\n\n");
        error=0;
    }
    return error;
}
