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
void imprime_lista(List L) {
   intdato;
   dato = (int)first(L);
   printf("[");
   while(dato != NULL) {
      printf("%d ",dato);
      dato = (int)next(L);
   }
   printf("]\n");

}

//Ojo que la pila se vacía al imprimir y se imprime en orden inverso
//NO MODIFICAR
void imprime_y_vacia_pila(StackP) {
   void dato;
   printf("[");
   while((dato = pop(P)) != NULL) {
      printf("%d ",(int)dato);
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

List crea_lista() {
   List* L = create_list();
   for (int i = 1; i <= 10; i++){
     int* element = (int*)malloc(sizeof(int));
     element = i;
     pushBack(L, element);
  }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y 
retorne la suma de sus elementos.
*/
int sumaLista(ListL) {
  int suma = 0;
  int* dato;

  dato = (int)first(L);
  while(dato != NULL){
    suma +=dato;
    dato = (int*)next(L);
  }

   return suma;
}
[22:03]
/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos 
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List L, int elem){
  int* dato = (int)first(L);
  while(dato != NULL) {
    if(dato == elem){
      free(popCurrent(L));
    } 
    else {
      dato = (int)next(L);
    }
  }
}

/
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
/

void copia_pila(Stack P1, Stack* P2) {
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

/* Ejercicio 5.
La función verifica si la cadena de entrada tiene sus 
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int parentesisBalanceados(charcadena) {
  Stack* stack = create_stack();
  char c;

  for (int i = 0; i < strlen(cadena); i++) {
    c = cadena[i];
    if (c == '(') {
      push(stack, (void)&c);
    } else if (c == ')') {
      if (get_size(stack) == 0 ||((char*)pop(stack)) != '(') {
        return 0;
      }
    }
  }

  if (get_size(stack) == 0) {
    return 1;
  } else {
    return 0;
  }
}

Enviar mensaje a @Rulo
