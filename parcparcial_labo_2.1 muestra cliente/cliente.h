#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct //tipo
{
    int id;
    char nombre[20];
    char sexo;
} eCliente;


#endif // CLIENTE_H_INCLUDED

int obtenerNombreCliente(eCliente clientes[], int tam_cli, int idCliente, char nombreCliente[]);
int getIdCliente(eCliente clientes[],int tam_cli);
int mostrarClientes(eCliente clientes[], int tam_cli);
void mostrarCliente(eCliente unCliente);

