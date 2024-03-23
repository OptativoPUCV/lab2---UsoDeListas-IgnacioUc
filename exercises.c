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

List* ejercicio1() {
  List* lista = create_list();

  // Agregar punteros a elementos del 1 al 10
  for (int i = 1; i <= 10; i++) {
    int* elemento = (int*)malloc(sizeof(int)); 
    *elemento = i; 
    pushBack(lista, elemento); 
  }

  return lista;
}
/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int suma = 0;
  int* dato;

  dato = (int*)first(L);
  while(dato != NULL){
    suma += *dato;
    dato = (int*)next(L);
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

void eliminaElementos(List L, int elem) {
    int dato;
    dato = (int)first(L); // Obtienes el primer elemento de la lista
    while(dato != NULL) { // Mientras no llegues al final de la lista
        if(dato == elem) {
            popCurrent(L); // Eliminas el elemento actual
            // No avanzas al siguiente inmediatamente porque popCurrent te deja en el elemento anterior
        } else {
            dato = (int*)next(L); 
        }
    }
}
/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
  // Crear una lista auxiliar para mantener temporalmente los elementos de P1
    List* auxiliar = create_list();

    // Copiar los elementos de P1 en la lista auxiliar en orden inverso
    void* elemento = popBack(P1);
    while (elemento != NULL) {
      pushFront(auxiliar, elemento);
      elemento = popBack(P1);
    }

    // Copiar los elementos de la lista auxiliar a P2
    elemento = popFront(auxiliar);
    while (elemento != NULL) {
      pushBack(P2, elemento);
      elemento = popFront(auxiliar);
    }

    // Liberar memoria de la lista auxiliar
    free(auxiliar);
  }
}

/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(char *cadena) {
    int balance = 0;
    char c ;
    stack = create_stack();
    for (int i = 0; i < strlen(cadena); i++){
      c
    }
/*
    while (*cadena != '\0') {
        if (*cadena == '(') {
            balance++;
        } else if (*cadena == ')') {
            balance--;
        }

        if (balance < 0) {
            return 0; // Paréntesis desbalanceados
        }

        cadena++;
    }

    return (balance == 0) ? 1 : 0;
}
*/