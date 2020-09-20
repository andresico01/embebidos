#include<stdio.h>
#include<stdlib.h>
#include"libreria.h"



//node* lista = NULL;
//void insertar_texto_lista(personas nueva);
int main(){
    FILE* archivo = fopen("pal profe.txt","rt");
    size_t tamano;
    personas grupo;
    unsigned char* contenido;
    int i = 0;
    int contador = 0;
    int contador_2 = 0;
    fseek(archivo,0,SEEK_END);
    tamano = ftell(archivo);
    fseek(archivo,0,SEEK_SET);
    contenido = malloc(tamano* sizeof(char));
    fread(contenido, sizeof(char),tamano,archivo);
    int j[10] = {0};
    printf("%s\n",contenido);
    inicio_posiciones(j,contenido);
   // printf("\n hijo de la remil putas\n");
    while( *(contenido+contador) != '\0'){
        if (*(contenido+contador) == '{'){
            contador_2++;
        }
        contador++;
    }
    while(i<contador_2){
    //printf("\naaa%da\n",j[i]);
        grupo = pasando_lista(contenido,j[i]);
        insertar_texto_lista(grupo);
        i++;
    }
    eliminar_string(contenido,tamano);
    //free(contenido);
    printf("%s\n",contenido);
    printf("\nlos datos del archivo.txt fueron pasados con exito a la lista, digame que proceso necesita hacer ahora\n");
    printf("\n1)ingresar datos a la lista \n2)mostrar los grupos de la lista  \n3)eliminar algun grupo perteneciente a la lista \n");
    menu();


    
    fclose(archivo);

    return EXIT_SUCCESS;
}

