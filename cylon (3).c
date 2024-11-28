#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 4

enum t_humano {INOFENSIVO,COMUN,PELIGROSO};
struct humano{
  char *nombre;
  enum t_humano tipo;
  float pb_capt;
};

int cuantos(struct humano *array, int size, enum t_humano kind, float pb_minima){

  int numero = 0; // importante la inicialización en C
  // si no se inicializa el valor interno puede ser cualquiera

  for (int i=0; i< size; i++){
    if ((array[i].tipo == kind) && (array[i].pb_capt >=pb_minima)){
      numero++;
    }
  }

  return numero;
}

int main(int argc, char **argv){
  struct humano array[TAM];
  
  array[0].nombre = strdup ("Kara Thrace");
  if (array[0].nombre == NULL){ // importante al pedir memoria
    printf("Error al pedir memoria\n");
    return 1;
  }
  array[0].tipo = PELIGROSO;
  array[0].pb_capt = 0.1;
  
  array[1].nombre = strdup ("Gaius Baltar");
  if (array[1].nombre == NULL){
    printf("Error al pedir memoria\n");
    free(array[0].nombre); //importante: hay que devolver la memoria pedida
    return 1;
  }
  array[1].tipo = COMUN;
  array[1].pb_capt = 0.5;

    
  array[2].nombre = strdup ("Lee Adama");
  if (array[2].nombre == NULL){
    printf("Error al pedir memoria\n");
    free(array[0].nombre); //importante: hay que devolver la memoria pedida
    free(array[1].nombre); 
    return 1;
  }
  array[2].tipo = PELIGROSO;
  array[2].pb_capt = 0.7;

    
  array[3].nombre = strdup ("Laura Roslin");
  if (array[3].nombre == NULL){
    printf("Error al pedir memoria\n");
    free(array[0].nombre); //importante: hay que devolver la memoria pedida
    free(array[1].nombre);
    free(array[2].nombre); 
    return 1;
  }
  array[3].tipo = PELIGROSO;
  array[3].pb_capt = 0.3;


  float pb = 0.3;
  int resultado;
  resultado = cuantos(array, TAM, PELIGROSO, pb);
  printf("%i humanos de tipo PELIGROSO pueden ser captados con pb igual o superior a: %f\n", resultado,pb);
  
  for (int i =0; i< TAM; i++){
    free(array[i].nombre); 
  }
  return 0;
}
