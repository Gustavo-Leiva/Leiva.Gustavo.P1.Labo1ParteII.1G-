#include <stdio.h>
#include <stdlib.h>


#include "empresa.h"
#include "viaje.h"


int inicializarViaje(eViaje vec[], int tamV)
{
    int todoOk = 0;

    if(vec!= NULL && tamV > 0)
    {

        for( int i = 0; i < tamV; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}







int altaViaje(eViaje vec[], int tamV, eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD,  int* pNextId)
{

    int todoOk = 0;
    int indice;
    int idMicro;
    int idDestino;
    eFecha fecha;
    eViaje nuevoViaje;


    if(vec != NULL  && micros != NULL && empresas != NULL && tipos != NULL  && destinos != NULL && tamV > 0 && tamM > 0 && tamE > 0 && tamT > 0 && tamD > 0 && pNextId != NULL)

    {
        system("cls");
        printf("         ********Alta Viaje********\n");
        printf("-----------------------------------------\n");
        buscarLibreViaje(vec, tamV, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoViaje.id = *pNextId;



             //listar micros
            listarMicros(micros,tamM,empresas, tamE,tipos,tamT);
            printf("Ingrese  Id Micro: ");
            fflush(stdin);
            scanf("%d", &idMicro);
            while(validarMicro(micros,tamM, idMicro)==0)
            {
                printf("Reingrese  Id Micro: ");
                fflush(stdin);
                scanf("%d", &idMicro);
            }

            nuevoViaje.idMicro = idMicro;

            //listar destinos.
            listarDestinos(destinos, tamD);
            printf("Ingrese  Id Destino: ");
            fflush(stdin);
            scanf("%d", &idDestino);
            while(validarDestinos(destinos,tamD, idDestino)==0)
            {
                printf("Reingrese  Id Destino: ");
                fflush(stdin);
                scanf("%d", &idDestino);
            }

            nuevoViaje.idDestino = idDestino;


            while(pidoValidoFecha(&fecha)== 0)
            {
                printf("ingrese fecha de Ingreso dd/mm/aaaa:");
                scanf("%d/%d/%d",
                      &fecha.dia,
                      &fecha.mes,
                      &fecha.anio);

            }

            nuevoViaje.fecha = fecha;


            nuevoViaje.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoViaje;
            //aca lo inyecto en la lista de motos

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1



            todoOk = 1;

        }




    }

    return todoOk;
}


int buscarLibreViaje(eViaje vec[], int tamV, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tamV > 0)
    {
        for(int i = 0; i < tamV ; i++)
        {
            *pIndex = -1;

            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }

        }

        todoOk = 1;

    }

    return todoOk;

}



int listarViajes(eViaje viajes[],  int tamV, eDestino destinos[], int tamD)
{
    int todoOk = 0;
    int flag = 1;

    if(viajes != NULL && destinos != NULL && tamV > 0 && tamD > 0)
    {

        printf("                ***Listado de Viajes***       \n");
        printf(" Id Viaje       Id Micros     Id Destino          Fecha\n");
        printf("---------------------------------------------------------- \n");

        for(int i = 0; i < tamV; i++)
        {

            if( !viajes[i].isEmpty)
            {
                mostrarViajeFila(viajes[i], destinos, tamD);
                flag = 0;
            }

        }
        todoOk = 1;
    }

    if(flag)
    {

        printf("     no hay viajes en el sistema\n");
    }


    return todoOk;
}


void mostrarViajeFila (eViaje viajes, eDestino destinos[], int tamD)
{

    char descripcionDestino [20];


    cargarDescripcionDestino(destinos, tamD, viajes.idDestino, descripcionDestino);




    printf("    %4d            %4d      %10s        %2d/%2d/%2d\n",
           viajes.id,
           viajes.idMicro,
           descripcionDestino,
           viajes.fecha.dia,
           viajes.fecha.mes,
           viajes.fecha.anio
          );

}


int harcodearViajes(eViaje vec[], int tamV, int cantV, int* pNextId)
{
    int todoOk = 0;

    eViaje viajes [15]=
    {
        {0, 1000, 20001 ,{10,7,2019},0},
        {0, 1001, 20001 ,{10,10,2019},0},
        {0, 1002, 20002 ,{9,9,2022},0},
        {0, 1003, 20003 ,{29,9,2021},0},
        {0, 1004, 20002 ,{11,8,2022},0},
        {0, 1005, 20001 ,{12,7,2022},0},
        {0, 1006, 20003 ,{14,6,2022},0},
        {0, 1007, 20002 ,{23,5,2022},0},
        {0, 1008, 20002 ,{19,4,2022},0},
        {0, 1009, 20000 ,{12,3,2022},0},
        {0, 1010, 20002 ,{26,2,2022},0},
        {0, 1011, 20002 ,{22,2,2020},0},
        {0, 1012, 20003 ,{12,1,2021},0},
        {0, 1013, 20003 ,{30,10,2022},0},
        {0, 1014, 20000 ,{17,8,2022},0}



    };

    if(vec != NULL && pNextId != NULL && tamV > 0 && tamV <=15 && cantV <= tamV)
    {
        for (int i = 0; i<cantV; i++)
        {
            vec[i]= viajes[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}
