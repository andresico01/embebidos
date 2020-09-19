#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"libreria.h"
#include"texto_lista.h"

//node* lista = NULL;
void insertar_lista_2(personas nueva);
int main(){
    FILE* archivo = fopen("pal profe.txt","rt");
    size_t tamano;
    personas grupo;
    unsigned char* contenido;
    int i = 0;
    fseek(archivo,0,SEEK_END);
    tamano = ftell(archivo);
    fseek(archivo,0,SEEK_SET);
    contenido = malloc(tamano* sizeof(char));
    fread(contenido, sizeof(char),tamano,archivo);
    int j[10] = {0};
    printf("%s\n",contenido);
    inicio_posiciones(j,contenido);
    while(i<2){
    printf("\naaa%da\n",j[i]);
        grupo = pasando_lista(contenido,j[i]);
        insertar_lista_2(grupo);
        i++;
    }
    menu();


    
    free(contenido);
    fclose(archivo);

    return EXIT_SUCCESS;
}

void insertar_lista_2(personas nueva){
        node* new_nodo = new();
        new_nodo->un_vale = nueva;
        node* aux = lista;
        node* aux_2;
        while((aux != NULL) /*&& (aux->un_vale.peso < new_nodo->un_vale.peso*/){
            aux_2 = aux;
            aux = aux->siguiente;
        }
        if(lista == aux){
            lista = new_nodo;
        }else aux_2->siguiente = new_nodo;
        new_nodo->siguiente = aux;
}