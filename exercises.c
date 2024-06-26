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
   for (int i = 1; i <= 10; i++){
      int* elementos = (int*)malloc(sizeof(int));
      *elementos = i;
      pushBack(L, elementos);
   }
   return L;
}
/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(List *L) {
  int suma = 0;
  int* datos;

  datos = (int*)first(L);
  while(datos != NULL){
    suma += *datos;
    datos = (int*)next(L);
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

void eliminaElementos(List* L, int elem){
  int* datos = (int*)first(L);
  while(datos != NULL) {
    if(*datos == elem){
      free(popCurrent(L));
    } 
    else {
      datos = (int*)next(L);
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
  Stack* auxStack = create_stack();

  while (get_size(P1) > 0) {
    void* data = pop(P1);
    push(auxStack, data);
  }

  while (get_size(auxStack) > 0) {
    void* data = pop(auxStack);
    push(P1, data);
    push(P2, data);
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
  char *pila = malloc(strlen(cadena)); 

  while (*cadena != '\0') {
      if (*cadena == '(' || *cadena == '[' || *cadena == '{') {
          pila[balance] = *cadena;
          balance++;
      } else if (*cadena == ')' || *cadena == ']' || *cadena == '}') {

          if (balance == 0) {
              free(pila);
              return 0;
          }
          char ultimo = pila[balance - 1];
          if ((*cadena == ')' && ultimo == '(') || (*cadena == ']' && ultimo == '[') || (*cadena == '}' && ultimo == '{')) {
              balance--;
          } else {
              free(pila);
              return 0; 
          }
      }
      cadena++; // Avanzamos al siguiente carácter
  }

  free(pila);
  return balance == 0 ? 1 : 0;
  }
