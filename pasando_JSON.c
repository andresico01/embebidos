#include<stdio.h>
#include<stdlib.h>
#include"Libreria.h"

int main (){
    //personas g = ingreso_datos();
    FILE* archivo = fopen("archivo.json","r+t");
    size_t tamano;
    personas grupo;
    
    Nodo* datos = NULL;
    unsigned char* contenido;
    int i = 0;
    int contador = 0;
    int contador_2 = 0;
    fseek(archivo,0,SEEK_END);
    tamano = ftell(archivo);
    fseek(archivo,0,SEEK_SET);
    contenido = (char*)malloc(tamano* sizeof(char));
    fread(contenido, sizeof(char),tamano,archivo);
    int j[10] = {0};
    printf("%s\n",contenido);
    inicio_posiciones(j,contenido);
    while( *(contenido+contador) != '\0'){
        if (*(contenido+contador) == '{'){
            contador_2++;
        }
        contador++;
    }
    while(i<contador_2){
        pasando_lista(&grupo,contenido,j[i]);
    //printf("\naaa%da\n",j[i]);
        datos = new(grupo);
   printf("\n un ser de love\n");
        insertar(datos);
        datos = datos->ptrNext;
        i++;
    }
    //free(contenido);
   // printf("%s\n",contenido);
    printf("\nlos datos del archivo.json fueron pasados con exito a la lista, digame que proceso necesita hacer ahora\n");
    menu();
    free_memory();
    return EXIT_SUCCESS;
}
