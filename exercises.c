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
   List* L = create_list();
   return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
   return 0;
}

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(void* L, int elem) {
    void* current = ((void**)L)[0]; // Comienza desde el primer nodo
    void* prev = NULL; // Para almacenar el nodo anterior

    while (current != NULL) {
        void* nextNode = ((void**)current)[1]; // Guarda el siguiente nodo antes de eliminar el actual

        // Verifica si el elemento actual es igual a 'elem'
        if (current != NULL && *((int*)((void**)current)[0]) == elem) {
            // Elimina el nodo actual de la lista
            if (prev == NULL) {
                // Si el nodo a eliminar es el primero
                ((void**)L)[0] = ((void**)current)[1];
            } else {
                // Si el nodo a eliminar no es el primero
                ((void**)prev)[1] = ((void**)current)[1];
            }

            // Si el nodo a eliminar es el último
            if (((void**)current)[1] == NULL) {
                ((void**)L)[1] = prev;
            }

            free(((void**)current)[0]); // Libera la memoria del nodo
            free(current); // Libera la memoria del nodo (previo)
            free(prev); // Libera la memoria del nodo (actual)
            ((int*)L)[2]--; // Reduce el tamaño de la lista
        } else {
            prev = current; // Actualiza el nodo anterior solo si no se elimina el actual
        }

        current = nextNode; // Avanza al siguiente nodo
    }
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

void copia_pila(Stack* P1, Stack* P2) {
    Stack* auxStack = create_stack(); // Pila auxiliar para mantener el orden

    // Vacía la pila P1 en la pila auxiliar, manteniendo el orden
    while (!is_empty_stack(P1)) {
        void* dato = pop(P1); // Extrae el elemento de P1
        push(auxStack, dato); // Agrega el elemento a la pila auxiliar
    }

    // Vacía la pila auxiliar en la pila P2, manteniendo el orden original
    while (!is_empty_stack(auxStack)) {
        void* dato = pop(auxStack); // Extrae el elemento de la pila auxiliar
        push(P2, dato); // Agrega el elemento a P2
    }

    // Libera la memoria de la pila auxiliar
    destroy_stack(auxStack);
}