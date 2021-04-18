#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int info;
    struct Nodo *sig;
};
typedef struct Nodo Lista;

int main()
{
    Lista *lista = NULL, *puntero_auxiliar, *nuevo; //Creación de lista vacía y declaración de un puntero auxiliar para poder agrgar más de un nodo a la lista
    lista = (Lista *)malloc(sizeof(Lista));         //Creación de un nuevo nodo (el cual aun está vacío de información)
    lista->info = 7;                                //Le asigno un valor de prueba al campo info de la lista enlazada "lista"
    lista->sig = NULL;                              //Le indico que debe apuntar a NULL
    // Adición de un nuevo nodo a la lista enlazada "lista", por cabecera
    puntero_auxiliar = lista; //Le asigno la direccion del nodo que contiene el valor '7'
    lista = (Lista *)malloc(sizeof(Lista));
    lista->info = 3;               // Le agrego un nuevo valor de prueba al campo info del nuevo nodo
    lista->sig = puntero_auxiliar; // Le asigno la direccion del puntero auxilar para enlazar la lista
    //Adición de un nodo, por cola (es decir, que apunte a NULL)
    //puntero_auxiliar = lista;
    while (puntero_auxiliar->sig != NULL)
    {
        puntero_auxiliar = puntero_auxiliar->sig;
    }
    //Las sentencias anteriores, desde "puntero_auxiliar = lista;" hasta el "while" pueden reemplazarse por la siguiente sentencia más compacta
    //for (puntero_auxiliar = lista; puntero_auxiliar->!= NULL; puntero_auxiliar = puntero_auxiliar->sig);
    //Lo que hace este for, es simplemente desplazar el puntero hasta la dirección NULL
    nuevo = (Lista *)malloc(sizeof(Lista));
    nuevo->info = 2;
    nuevo->sig = NULL;
    puntero_auxiliar->sig = nuevo;

    // Mostrar los elementos de la lista
    while (lista != NULL)
    {
        printf("%d", lista->info);
        lista = lista->sig;
    }

    //Eliminar el primer elemento de la lista
    puntero_auxiliar = lista->sig;
    free(lista);
    lista = puntero_auxiliar;
    // Mostrar los elementos de la lista
    printf("\nMuestro la lista nuevamente:\n");
    while (lista != NULL)
    {
        printf("%d", lista->info);
        lista = lista->sig;
    }
    return 0;
}
