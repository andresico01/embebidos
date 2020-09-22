#include<stdio.h>
#include<stdlib.h>

 

/*typedef struct{
    char *nombre;
    int edad;
}empleado;*/

 


typedef struct{
    char dato;
    struct Nodo* ptrNext;
} Nodo;

 

Nodo *header = NULL;
Nodo *footer = NULL;

 Nodo *new(char dat);
 void insertar(Nodo *nodo);
 void run();
void free_memory();
void pop(unsigned char index);
void insertar_dato(char dato, int posicion);

 

int main(){
    Nodo *nodo1 = new(3);
    Nodo *nodo2 = new(5);
    Nodo *nodo3 = new(8);
    Nodo *nodo4 = new(10);
    insertar(nodo1);
    insertar(nodo2);
    insertar(nodo3);
    insertar(nodo4);
    run();
    insertar_dato(6, 3);  //agregar valor nuevo en posicion de lista, si existe ya un valor en esa posicion desplazar pal otro lado 
    run();
    pop(0);
    run();
   free_memory();
   run();
   return EXIT_SUCCESS;
}
Nodo *new(char dat){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->dato = dat;
    nuevo->ptrNext = NULL;
    return(nuevo);
}
void insertar(Nodo *nodo){
    if(header == NULL){
        header = nodo;
        footer = nodo;
    }
    else{
        footer->ptrNext = nodo;
        footer = nodo;
    }
}
void run(){
    Nodo *i = header;
    if(i==NULL){
        printf("lista vacía\r\n");
        return;
    }
    else{
        while(i != NULL){
            printf("%d->", i->dato);
            i = i->ptrNext;
        }
        printf("\r\n");
    }
}
void free_memory(){
    Nodo *i = header;
    if(i==NULL){
        printf("lista vacia\r\n");
        return;
    }
    else{
        while(i != NULL){
            header = i->ptrNext;
            free(i);
            i = header;
        }
        header = NULL;
        footer = NULL;
        printf("Memoria Liberada\r\n");
    }
}
void pop(unsigned char index){
    unsigned char cont = 0;
    Nodo *i = header;
    Nodo *ant = NULL;
    //index--;
    if( i == NULL){
        printf("lista vacía\r\n");
        return;
    }
    else{
       while( i != NULL && cont != index){
           ant = i;
           i = i->ptrNext;
           cont++;
       }
       if (i == NULL){
           printf("\nla lista no es tan extensa\n");
       }
       else if (ant == NULL){
           header = header->ptrNext;
           free (i);
       }
       else{
           ant->ptrNext = i->ptrNext;
           free(i);
       }
    }
}
void insertar_dato(char dato, int posicion){
    Nodo *new_node = new(dato);                    
    unsigned char cont = 0;                                           

    Nodo *aux=header;                               
    Nodo *aux2;                                     
    while((aux != NULL) && ( cont < posicion)){         
        aux2 = aux;                                 
        aux = aux->ptrNext;     
        cont++;                  
    }                                               
    
    if(header == aux){
        header = new_node;
    }else if(aux == NULL){
        printf("\nla lista es muy pequena para la posicion solicitada\n");
        return;
    }else aux2->ptrNext = new_node;
    new_node->ptrNext = aux;

}
