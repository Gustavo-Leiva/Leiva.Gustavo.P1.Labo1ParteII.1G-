#include <stdio.h>
#include <stdlib.h>



#include "destino.h"
#include <string.h>

int cargarDescripcionDestino (eDestino destinos[], int tamD, int id, char desc[])
{
    int todoOk = 0;

    if(destinos != NULL && tamD > 0 && desc != NULL)
    {

        for(int i = 0; i < tamD ; i++)
        {

            if(destinos[i].id == id)//repasar que hace esto.
            {
                strcpy(desc, destinos[i].descripcion);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}




int listarDestinos(eDestino destinos[], int tamD)
{
    int todoOk = 0;

    if(destinos != NULL && tamD > 0)
    {
        printf("                 ***Listado de Destino***                    \n");
        printf("        id                           Descripcion       Precio \n");
        printf("--------------------------------------------------------------\n");


        for(int i = 0 ; i < tamD; i++)
        {

            printf("        %4d         %20s         %10.2f \n", destinos[i].id, destinos[i].descripcion, destinos[i].precio);

        }


        todoOk = 1;

    }


    return todoOk;
}



int buscarDestinos(eDestino destinos[], int tamD, int id, int* pIndex)
{
    int todoOk = 0;

    if(destinos != NULL && tamD > 0 && pIndex != NULL)
    {
        *pIndex = -1;

        for(int i = 0;  i < tamD; i++)
        {

            if(destinos[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarDestinos(eDestino destinos[], int tamD, int id)
{
    int esValido = 0;
    int indice;

    if(buscarDestinos(destinos, tamD, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;
}
