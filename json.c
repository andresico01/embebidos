#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define N_est 10

typedef struct{
    char nombre[20];
    char apellido[20];
    int edad;
    int peso;
    int numero_estudiantes;
   
    char estudiantes[N_est][20];
}personas;

typedef struct {
    personas un_vale;
    struct node* siguiente; 
}node;
node* new();
void eliminar_dato(char docente[20]);
void insertar_lista();
void mostrar_lista();
void eliminar(node* lista);  // este aun no fuanciona.
personas ingreso_datos();
void mostrar_datos(personas datos);
bool comprobando(node* aux,char docente[20]);
int tamano(char letra[20]);
bool val = false;
node* lista = NULL;
int main(){
    //personas docentes = ingreso_datos();
    int opcion = 0;
    char nombre[20];
    printf("\ndame nombre teacher\n");
    scanf("%s",nombre);
    do{
        fflush(stdin);
        printf("\nque opcion desea ?\n");
        scanf("%d",&opcion);
        switch (opcion){
            case 1 : 
                insertar_lista();
                system("pause");
                break;
            case 2 :
                mostrar_lista();
                system("pause");
                break;
            case 3 : 
                if (!comprobando(lista,nombre)){
                    printf("es falso\n");
                }else printf("es verdadero\n");
                
                system("pause");
                break;
        }
   // printf("\n%s",lista->un_vale.edad);
    system("cls");
    }while(opcion < 4);
   //printf("si sera ?%d",lista->un_vale.edad);
  /*  node* people = malloc(sizeof(node));
    people->un_vale->nombre= "pedro";*/

    return EXIT_SUCCESS;
}
node* new(){                                //si teacher esto es de su codigo.
    node* nuevo = malloc(sizeof(node));
    nuevo->siguiente =  NULL;
    return (nuevo);
}
personas ingreso_datos(){
    personas referencia;
    int N_estu = 0, i = 0;
    
    // fflush(stdin);
    printf("ingrese los datos de referencia del asesino\n");
    printf("\n ingrese el nombre del docente\n");
    scanf("%s",referencia.nombre);
    printf("\n ingrese el apellido del docente\n");
    scanf("%s",referencia.apellido);
    printf("\n ingrese su edad\n");
    scanf("%d",&referencia.edad);
    printf("\n ingrese peso \n");
    scanf("%d",&referencia.peso);
    fflush(stdin);
    printf("\n ingrese numero de estudiantes\n");
    scanf("%d",&referencia.numero_estudiantes);
   
    do{
    fflush(stdin);
        printf("\ningrese el nombre del estudiante\n");
        scanf("%s",referencia.estudiantes[i]);
        i++;
   }while(i < referencia.numero_estudiantes);
    return (referencia);
}

void insertar_lista(){
        node* new_nodo = new();
        new_nodo->un_vale = ingreso_datos();
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
void mostrar_lista(){
    node* actual = new();
    actual = lista;
    printf("melo\n");
    while(actual != NULL){
        printf("melo?");
        mostrar_datos(actual->un_vale);
        actual = actual->siguiente;
    }
}
void mostrar_datos(personas datos){
    int i=0;
    printf("\nnombre del docente: %s\n", datos.nombre);
    printf("\n apellido: %s \n",datos.apellido);
    printf("\nedad: %d \n",datos.edad);
    printf("\n peso: %d \n",datos.peso);
    printf("\n sus estudientes son: \n");
    while(i < datos.numero_estudiantes){
        printf("%s\t",datos.estudiantes[i]);
        i++;
    }
    printf("\n");
}

int tamano(char letra[20]){
    int tam = 0; 
    while(letra[tam] != 0)tam++;

    return tam;
}

bool comprobando(node* aux,char docente[20]){
    int valor_1 = 0, valor_2 = 0, i = 0;
    valor_1 = tamano(docente);
    valor_2 = tamano(aux->un_vale.nombre);
    while(i < valor_1){
        if (docente[i] == aux->un_vale.nombre[i])valor_2--;
        i++;   
    }
    return (valor_2 != 0);
}

void eliminar_dato(char docente[20]){
    int cont = 0;
    if (lista != NULL){
        node* aux_borrar = new();
        node* anterior = NULL;
        aux_borrar = lista;
        while(aux_borrar != NULL && !comprobando(aux_borrar,docente)){
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
            printf("%d\t",cont++);
        }
        if (aux_borrar == NULL){
            printf("\n el nombre del docente ingresado no existe\n");
        }else if(anterior == NULL){
            lista = aux_borrar;
        }else{
            anterior->siguiente = aux_borrar->siguiente;
        }
    }else{
        printf("\n no existen datos en la lista aun\n");
    }
}