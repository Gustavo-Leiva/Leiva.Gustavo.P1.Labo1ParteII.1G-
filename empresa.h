#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eEmpresa;

#endif // EMPRESA_H_INCLUDED
int cargarDescripcionEmpresa (eEmpresa empresas[], int tamE, int id, char desc[]);
int listarEmpresas(eEmpresa empresas[], int tamE);
int buscarEmpresas(eEmpresa empresas[], int tamE, int id, int* pIndex);
int validarEmpresas(eEmpresa empresas[], int tamE, int id);


