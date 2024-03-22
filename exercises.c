#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

//#include "exercises.h"

//Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
//NO MODIFICAR
void imprime_lista(List *L) {
   int *dato;
   dato = (int*)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ", *dato);
      dato = (int*)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
   void *dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ", *(int*)dato);
   }
   printf("]\n");
}

/* 
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List* crea_lista() {
    // Declaración e inicialización de la cabeza de la lista
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo cabeza.\n");
        exit(EXIT_FAILURE);
    }
    head->data = 1;         // Establece el dato del primer nodo
    head->next = NULL;      // Inicializa el siguiente nodo como NULL

    // Declaración de un puntero para el nodo actual
    ListNode* current = head;

    // Agregar nodos adicionales con datos del 2 al 10
    int i;
    for (i = 2; i <= 10; i++) {
        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));  // Crea un nuevo nodo
        if (newNode == NULL) {
            printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
            exit(EXIT_FAILURE);
        }
        newNode->data = i;        // Establece el dato del nuevo nodo
        newNode->next = NULL;     // Inicializa el siguiente nodo como NULL
        current->next = newNode;  // Enlaza el nuevo nodo al final de la lista
        current = newNode;        // Establece el nuevo nodo como el nodo actual
    }

    // Retorno de la cabeza de la lista
    return (List*)head;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int suma = 0;

    int largo = get_size(L);
    List *actual = first(L);
    for (int i = 0; i < largo; i++) {

      suma += *(int*)actual;

      actual = next(L);

    }
    return suma;
  }

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){

}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
   return 0;
}

