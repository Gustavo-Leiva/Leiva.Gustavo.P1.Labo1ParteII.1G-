#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eTipo;


#endif // TIPOS_H_INCLUDED


int cargarDescripcionTipos (eTipo tipos[], int tamT, int id, char desc[]);
int listarTipos(eTipo tipos[], int tamT);
int buscarTipos(eTipo tipos[], int tamT, int id, int* pIndex);
int validarTipos(eTipo tipos[], int tamT, int id);
