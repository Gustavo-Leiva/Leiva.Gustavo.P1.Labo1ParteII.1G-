#include <stdio.h>
#include <stdlib.h>



#include "tipo.h"
#include <string.h>

int cargarDescripcionTipos (eTipo tipos[], int tamT, int id, char desc[])
{
    int todoOk = 0;

    if(tipos != NULL && tamT > 0 && desc != NULL)
    {

        for(int i = 0; i < tamT ; i++)
        {

            if(tipos[i].id == id)//repasar que hace esto.
            {
                strcpy(desc, tipos[i].descripcion);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}




int listarTipos(eTipo tipos[], int tamT)
{
    int todoOk = 0;

    if(tipos != NULL && tamT > 0)
    {
        printf("         ***Listado de tipos***           \n");
        printf("        id                   Descripcion   \n");
        printf("-------------------------------------------\n");


        for(int i = 0 ; i < tamT; i++)
        {

            printf("        %4d         %20s    \n", tipos[i].id, tipos[i].descripcion);

        }


        todoOk = 1;

    }


    return todoOk;
}



int buscarTipos(eTipo tipos[], int tamT, int id, int* pIndex)
{
    int todoOk = 0;

    if(tipos != NULL && tamT > 0 && pIndex != NULL)
    {
        *pIndex = -1;

        for(int i = 0;  i < tamT; i++)
        {

            if(tipos[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarTipos(eTipo tipos[], int tamT, int id)
{
    int esValido = 0;
    int indice;

    if(buscarTipos(tipos, tamT, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;
}
