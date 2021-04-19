#include <stdio.h>
#include <stdlib.h>

#define MAX 4 //Tamaño inicial de las listas de prueba

typedef int item;
typedef struct Node
{
    item number;
    struct Node *next;
} * Node;

Node createList();                             // apartado a
int isItAnEmptyList(Node L_Header);            // apartado b
Node showList(Node L_Header);                  // apartado c
item firstElement(Node L_Header);              //apartado d
Node addInHeader(Node L_Header, item value);   // apartado e
Node deleteFirstNode(Node L_Header);           // apartado f
int listLength(Node L_Header);                 // apartado g
int belongToTheList(Node L_Header, int value); // apartado h
void belongToTheList_ExtendedVersion(Node L_Header, int value);
int equalLists(Node L_Header, Node L_Header_2); // punto 3
void equalLists_ExtendedVersion(Node L_Header, Node L_header_2);
Node createNewList(Node L_header);
Node createTestList(Node L_Header);
Node addInTail(Node L_Header, item value);
Node deleteTheTail(Node L_Header);
Node controlarPositivos(Node L_Header); // Quiz (checkPositive)

int main()
{
    int number;
    // crear listas vacias
    Node L_Header_1 = createList();
    Node L_Header_2 = createList();
    Node L_Header_3 = createList();
    Node L_Header_4 = createList();

    //Verificar si la lista esta vacia
    printf("Al crear la primera lista se tiene que:");
    if (isItAnEmptyList(L_Header_1))
    {
        printf("\nEs una lista vacia");
    }
    else
    {
        printf("\nLa lista no esta vacia");
    }

    //Mostrar el primer elemento de la lista 1
    firstElement(L_Header_1);

    // Crear dos listas de MAX=4 elementos cada una
    printf("\n*** Primera lista ***");
    L_Header_1 = createNewList(L_Header_1);
    printf("\n*** Segunda lista ***");
    L_Header_2 = createNewList(L_Header_2);

    // Mostrar ambas listas creadas
    printf("\n*** Elementos de la primera lista ***\n");
    showList(L_Header_1);

    // QUIZTP1: Controlo si todos los elementos de la lista '1' son positivos
    if (controlarPositivos(L_Header_1))
    {
        printf("\nTodos los elementos de la lista 'L_Header_1' son positivos");
    }
    else
    {
        printf("\nLa lista dada no contiene elementos positivos o no todos los elementos de la lista son positivos");
    }

    printf("\n*** Elementos de la segunda lista ***\n");
    showList(L_Header_2);

    // Mostrar el primer elemento de ambas listas
    firstElement(L_Header_1);
    firstElement(L_Header_2);

    // Verificar igualdad entre las listas 1 y 2
    printf("\n*** Verifico si las listas 1 y 2 son iguales ***");
    equalLists_ExtendedVersion(L_Header_1, L_Header_2);

    // Crear dos listas iguales y usar la función de comparacion de listas para verificar esta igualdad
    L_Header_3 = createTestList(L_Header_3);
    L_Header_4 = createTestList(L_Header_4);

    // Verifico si las siguientes listas (3 y 4) son iguales
    printf("\n*** Comparando las listas 3 y 4 ***");
    printf("\nLista 3: ");
    showList(L_Header_3);
    printf("\nLista 4: ");
    showList(L_Header_4);
    equalLists_ExtendedVersion(L_Header_3, L_Header_4);

    // Agregar un nuevo nodo a la cabecera de la lista 3
    printf("\nIngrese un numero entero para agregar a la lista 3: ");
    scanf("%d", &number);
    L_Header_3 = addInHeader(L_Header_3, number);
    printf("\n*** Lista 3 modificada ***\n");
    showList(L_Header_3);

    // Compara la lista 3 con la lista 4
    printf("\n*** Verifico si las listas 3 y 4 son iguales ***");
    equalLists_ExtendedVersion(L_Header_3, L_Header_4);

    // Verificar si un elemento pertenece a la lista
    printf("\n*** Verifico si el numero %d pertenece a la lista 3 ***", number);
    belongToTheList_ExtendedVersion(L_Header_3, number);

    // Eliminar el primer elemento de la lista
    printf("\n*** Eliminando el primer nodo de la lista 3 ***\n");
    L_Header_3 = deleteFirstNode(L_Header_3);

    // Muestro la lista 3 modificada
    showList(L_Header_3);

    //Verifico si el numero ingresado anteriormente pertenece a la lista 3 (no debería ya que fue eliminado)
    printf("\n*** Verifico si el numero %d pertenece a la lista 3 ***", number);
    belongToTheList_ExtendedVersion(L_Header_3, number);

    getchar();
    return 0;
}

Node createList()
{
    return NULL;
}

int isItAnEmptyList(Node L_Header)
{
    return L_Header == NULL;
}

Node showList(Node L_Header)
{
    if (L_Header)
    {
        printf("%d ", L_Header->number);
        showList(L_Header->next);
    }
}

item firstElement(Node L_Header)
{
    if (!isItAnEmptyList(L_Header))
    {
        printf("\n*** Primer elemento de la lista: %d***", L_Header->number);
    }
    else
    {
        printf("\nLa lista ingresada no contiene elementos. Es una lista vacia.");
    }
}

Node addInHeader(Node L_Header, item value)
{
    /*Función que agrega un nodo al comienzo de la lista*/
    Node new_Node = (Node)malloc(sizeof(Node));
    new_Node->number = value;
    new_Node->next = L_Header;
    L_Header = new_Node;
    return L_Header;
}

Node deleteFirstNode(Node L_Header)
{
    Node aux_pointer;
    if (L_Header != NULL)
    {
        aux_pointer = L_Header->next; // L_Header->next es un puntero que vive dentro del primer nodo y apunta al segundo nodo
        free(L_Header);               // Elimino el primer nodo
        L_Header = aux_pointer;       // Ahora el primer nodo es el que antes de este proceso era el segundo nodo
    }
    return L_Header;
}

int listLength(Node L_Header)
{
    int length = 0;
    while (L_Header != NULL)
    {
        length++;
        L_Header = L_Header->next;
    }
    return length;
}

int belongToTheList(Node L_Header, int value)
{
    //Si el elemento indicado por parametro pertenece a la lista, la función devolverá un entero mayor a 0
    Node aux_pointer;
    for (aux_pointer = L_Header; aux_pointer != NULL; aux_pointer = aux_pointer->next)
    {
        if (aux_pointer->number == value)
        {
            return 1;
        }
    }
    return 0;
}

int equalLists(Node L_Header, Node L_Header_2)
{
    int aux = 1; //variable auxilar que si se retorna con un valor de 0, implicará que las listas NO son iguales
    if (listLength(L_Header) != listLength(L_Header_2))
    {
        return 0;
    }
    else
    {
        Node aux_pointer_1 = L_Header;
        Node aux_pointer_2 = L_Header_2;
        while (aux_pointer_1 != NULL)
        {
            if (aux_pointer_1->number != aux_pointer_2->number)
            {
                aux = 0;
                //break;
            }
            aux_pointer_1 = aux_pointer_1->next;
            aux_pointer_2 = aux_pointer_2->next;
        }
        free(aux_pointer_1);
        free(aux_pointer_2);

        return aux;
    }
}

Node createNewList(Node L_Header)
{
    int number;
    for (int i = 0; i < MAX; i++)
    {
        printf("\nIngrese un numero entero para la correspondiente lista: ");
        scanf("%d", &number);
        L_Header = addInHeader(L_Header, number);
    }
    return L_Header;
}

Node createTestList(Node L_Header)
{
    for (int i = 1; i <= MAX; i++)
    {
        L_Header = addInHeader(L_Header, i);
    }
    return L_Header;
}

void equalLists_ExtendedVersion(Node L_Header, Node L_header_2)
{
    if (equalLists(L_Header, L_header_2))
    {
        printf("\nLas listas ingresadas son iguales");
    }
    else
    {
        printf("\nLas listas ingresadas no son iguales");
    }
}

void belongToTheList_ExtendedVersion(Node L_Header, int value)
{
    if (belongToTheList(L_Header, value))
    {
        printf("\nPertenece a la lista");
    }
    else
    {
        printf("\nNo pertenece a la lista");
    }
}

Node addInTail(Node L_Header, item value)
{
    // Funcion para agregar un elemento por la cola o final de la lista enlazada
    Node aux_pointer, new_Node;
    new_Node = (Node)malloc(sizeof(Node));
    new_Node->number = value;
    new_Node->next = NULL;
    if (L_Header == NULL)
    {
        L_Header = new_Node;
    }
    else
    {
        for (aux_pointer = L_Header; aux_pointer->next != NULL; aux_pointer = aux_pointer->next)
            ;
        aux_pointer->next = new_Node;
    }
    return L_Header;
}

Node deleteTheTail(Node L_Header)
{
    // Funcion para eliminar el ultimo elemento de la lista o la cola de la lista enlazada
    Node aux_pointer, behind;
    if (L_Header != NULL)
    {
        for (behind = NULL, aux_pointer = L_Header; aux_pointer != NULL; behind = aux_pointer, aux_pointer = aux_pointer->next)
            ;
        free(aux_pointer);
        if (behind == NULL)
        {
            L_Header = NULL;
        }
        else
        {
            behind->next = NULL;
        }
    }
    return L_Header;
}

Node controlarPositivos(Node L_Header)
{
    Node aux_pointer;
    if (L_Header == NULL)
    {
        return 0;
    }
    else
    {
        for (aux_pointer = L_Header; aux_pointer != NULL; aux_pointer = aux_pointer->next)
        {
            if (aux_pointer->number < 0)
            {
                return 0;
            }
        }
        return 1;
    }
}