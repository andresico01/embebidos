//#include<stdio.h>
//#include<stdlib.h>
//#define N_est 10
typedef struct{
    char nombre[20];
    char apellido[20];
    int edad;
    int peso;
    int numero_estudiantes;
    char estudiantes[10][20];
}personas;

typedef struct {
    personas un_vale;
    struct node* siguiente; 
}node;

node* lista = NULL;
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
        while((aux != NULL) && (aux->un_vale.peso < new_nodo->un_vale.peso)){
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

void menu(){
    //personas docentes = ingreso_datos();
    int opcion = 0;
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
        }
  
    system("cls");
    }while(opcion < 3);  
}