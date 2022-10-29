#include <stdio.h>
#include <stdlib.h>

#include "micro.h"
#include "empresa.h"
#include "tipo.h"


#include "validaciones.h"

#include <string.h>
#include <ctype.h>
#include <string.h>




/*
---------------------------------------------------------------------------------------
                                  Inicializar Arrays
---------------------------------------------------------------------------------------
*/

int inicializarMicros(eMicro vec[], int tam)
{
    int todoOk = 0;

    if(vec!= NULL && tam > 0)
    {

        for( int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}


/*
---------------------------------------------------------------------------------------
                                 HARCODEO DE FUNCIONES
---------------------------------------------------------------------------------------
*/


int harcodearMicros(eMicro vec[], int tamM, int cantM, int* pNextId)
{
    int todoOk = 0;

    eMicro micros [15]=
    {
        {0, 1000, 5000, 30,0},
        {0, 1001, 5003, 40,0},
        {0, 1002, 5001, 20,0},
        {0, 1003, 5002, 50,0},
        {0, 1004, 5001, 40,0},
        {0, 1004, 5000, 34,0},
        {0, 1002, 5003, 48,0},
        {0, 1001, 5002, 40,0},
        {0, 1003, 5001, 35,0},
        {0, 1000, 5000, 29,0},
        {0, 1004, 5003, 30,0},
        {0, 1002, 5002, 40,0},
        {0, 1000, 5000, 35,0},
        {0, 1003, 5001, 45,0},
        {0, 1004, 5002, 30,0}

    };

    if(vec != NULL && pNextId != NULL && tamM> 0 && tamM <=15 && cantM <= tamM)
    {
        for (int i = 0; i<cantM; i++)
        {
            vec[i]= micros[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


/*
---------------------------------------------------------------------------------------
                                  ALTA  DE DATOS
---------------------------------------------------------------------------------------
*/

int menuMicro()
{
    int opcion;

    system("cls");
    printf("********** ABM MICRO*******\n\n");
    printf("1. Alta Micro\n");
    printf("2. Modificar Micro\n");
    printf("3. Baja Micro\n");
    printf("4. Listar Micro\n");
    printf("5. Listar Empresas\n");
    printf("6. Listar Tipos\n");
    printf("7. Listar Destinos\n");
    printf("8. Alta de Viaje\n");
    printf("9. Listar Viajes\n");
    printf("30. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}





int buscarLibreMicros(eMicro vec[], int tam, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
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







int altaMicro(eMicro vec[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pNextId)
{

    int todoOk = 0;
    int indice;
    int idEmpresa;
    int idTipo;
    int auxCapPas;
    eMicro nuevoMicro;


    if(vec != NULL  && empresas != NULL  && tipos != NULL  && tamM > 0 && tamE > 0 && tamT > 0 && pNextId != NULL)

    {
        system("cls");
        printf("***************Alta Micro********\n");
        printf("----------------------------------\n");
        buscarLibreMicros(vec, tamM, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoMicro.id = *pNextId;




            //listar empresas
            listarEmpresas(empresas, tamE);
            printf("Ingrese  Id Empresa: ");
            fflush(stdin);
            scanf("%d", &idEmpresa);
            while(validarEmpresas(empresas,tamE, idEmpresa)==0)
            {
                printf("Reingrese  Id Empresa: ");
                fflush(stdin);
                scanf("%d", &idEmpresa);
            }

            nuevoMicro.idEmpresa = idEmpresa;

            //listar tipos.
            listarTipos(tipos, tamT);
            printf("Ingrese  Id tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
            while(validarTipos(tipos,tamT, idTipo)==0)
            {
                printf("Reingrese  Id tipos: ");
                fflush(stdin);
                scanf("%d", &idTipo);
            }

            nuevoMicro.idTipo = idTipo;


            pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");
            while(auxCapPas <1 || auxCapPas > 50)
            {
                printf("Error, maximo permitido 50 pasajeros\n");
                pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");

            }


            nuevoMicro.capacidad = auxCapPas;


            nuevoMicro.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoMicro;
            //aca lo inyecto en la lista de micros

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1


            todoOk = 1;

        }




    }

    return todoOk;
}



/*
---------------------------------------------------------------------------------------
                                 MODIFICAR DATOS
---------------------------------------------------------------------------------------
*/

int modificarMicro(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    int idTipo;
    int auxCapPas;
    char confirma;
    char opcion [] = {"1,2,"};



    if(micros != NULL && tamM > 0 && empresas != NULL && tipos != NULL && tamT >0)
    {
        listarMicros(micros, tamM, empresas, tamE, tipos, tamT); //tiene listar y lista fila.
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos del Micros a Modificar*******\n");

        if(buscarMicro(micros, tamM, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un micro con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarMicro(micros[indice], tamM, empresas, tamE, tipos, tamT);

                switch(menuModificarMicro())
                {
                case 1:

                    listarTipos(tipos, tamT);
                    printf("Ingrese el id del Tipo: \n");
                    fflush(stdin);
                    scanf("%d", &idTipo);
                    while(validarTipos(tipos, tamT, idTipo)==0)
                    {
                        printf("Error!! Reingrese el id del Tipo: \n");
                        fflush(stdin);
                        scanf("%d", &idTipo);

                    }


                    micros[indice].idTipo = idTipo;
                    if(confirmarCarga(&confirma))
                    {

                        micros[indice].idTipo = idTipo;
                    }
                    break;



                case 2:
                    pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");
                    while(auxCapPas <1 || auxCapPas > 50)
                    {
                        printf("Error, debe ingresar entre 1 y 50\n");
                        pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");

                    }



                    if(confirmarCarga(&confirma))
                    {

                        micros[indice].capacidad = auxCapPas;
                    }

                    break;


                default:
                    validarOpcion(opcion);
                    break;



                }

            }

            todoOk = 1;

        }

    }

    return todoOk;
}





int listarMicros(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if(micros != NULL  && empresas!= NULL  && tipos != NULL && tamM > 0 && tamE > 0 && tamT > 0)
    {
        //system("cls");
        printf("****** Listado  De Micros ****************\n");
        printf("   ID       EMPRESA      TIPO      CAPACIDAD  \n");
        printf("------------------------------------------ \n");

        for(int i = 0; i< tamM; i++)
        {
            if(!micros[i].isEmpty)//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarMicroFila(micros[i], tamM, empresas, tamE, tipos, tamT);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("     no hay micros en el sistema\n");
        }
    }


    return todoOk;
}


void mostrarMicroFila(eMicro micros, int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{

    char descripcionEmpresa [20];
    char descripcionTipo [20];

    cargarDescripcionEmpresa(empresas, tamE, micros.idEmpresa, descripcionEmpresa);
    cargarDescripcionTipos(tipos, tamT, micros.idTipo, descripcionTipo);


    printf("%4d     %10s     %10s    %d\n",
           micros.id,
           descripcionEmpresa,
           descripcionTipo,
           micros.capacidad
          );

}




int buscarMicro(eMicro micros[], int tamM, int id, int* pIndex)
{
    int todoOk = 0;

    if(micros != NULL && tamM > 0  && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < tamM; i++)
        {

            //aca busco que la estructura no este vacia y que el id que busco coincida con ese lugar.
            if(!micros[i].isEmpty && micros[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}




int validarMicro (eMicro micros[], int tamM, int id)
{
    int esValido = 0;
    int indice;

    if(buscarMicro(micros, tamM, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}



void mostrarMicro(eMicro micros, int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    char descripcionEmpresa [20];
    char descripcionTipo [20];

    cargarDescripcionEmpresa(empresas, tamE, micros.idEmpresa, descripcionEmpresa);
    cargarDescripcionTipos(tipos, tamT, micros.idTipo, descripcionTipo);


    printf("Id: %d\n", micros.id);
    printf("Empresa: %s\n", descripcionEmpresa);
    printf("Tipo: %s\n", descripcionTipo);
    printf("Capacidad: %d\n", micros.capacidad);


}




int menuModificarMicro()
{
    int opcion;
    printf("******************************\n\n");
    printf("   *** Campo a modificar ***  \n");
    printf("-----------------------------*\n\n");
    printf("1. Tipo\n");
    printf("2. Capacidad\n");
    printf("3. Salir:\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}








/*
---------------------------------------------------------------------------------------
                                  BAJA DE AUTO
---------------------------------------------------------------------------------------
*/


int bajaMicro (eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(micros != NULL && tamM > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT >0)
    {
        listarMicros(micros, tamM, empresas, tamE, tipos, tamT);

        printf("Ingrese Id:");
        scanf("%d", &id);
        if(buscarMicro(micros,tamM, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe ese Micro con ese Id %d en el sistema\n", id);
            }

            else
            {
                mostrarMicro(micros[indice], tamM, empresas,tamE, tipos, tamT);
                printf("confirma baja?\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                    micros[indice].isEmpty = 1;
                    printf("Baja exitosa\n");
                }

                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;

        }



    }


    return todoOk;

}




int ordenarMicroXEmpresaCapacidad(eMicro vec[], int tam)
{
    int todoOk = 0;
    eMicro auxMicro;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i +1; j < tam; j++)
            {
                if(((vec[i].idEmpresa == vec[j].idEmpresa) && (vec[i].capacidad > vec[j].capacidad))

                        ||((vec[i].idEmpresa != vec[j].idEmpresa) && (vec[i].idEmpresa > vec[j].idEmpresa)))
                {

                    auxMicro = vec[i];
                    vec[i]= vec[j];
                    vec[j]= auxMicro;

                }
            }
        }

        todoOk = 1;
    }


    return todoOk;
}
