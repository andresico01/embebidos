#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//#define N_est 10
typedef char string[20];
typedef struct{
    string nombre;
    string apellido;
    int edad;
    int peso;
    int numero_estudiantes;
    string estudiantes[10];
}personas;

typedef struct{
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
        while((aux != NULL) /*&& (aux->un_vale.peso < new_nodo->un_vale.peso)*/){
            aux_2 = aux;
            aux = aux->siguiente;
        }
        if(lista == aux){
            lista = new_nodo;
        }else aux_2->siguiente = new_nodo;
        new_nodo->siguiente = aux;
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
void mostrar_lista(){
    node* actual = new();
    actual = lista;
    
    while(actual != NULL){
        
        mostrar_datos(actual->un_vale);
        actual = actual->siguiente;
    }
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
/*ingresa los datos guardados en gente y los pone en mi lista*/
void insertar_texto_lista(personas nueva){
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
/*paso los datos del texto a un vector, en la mayoria de casos el vector es el string que cree arriba*/
void pasando_datos(char* datos, int posicion_0, int posicion_final,char string[]){
    int iterador_k = 0,iterador_o = 0;
    for(iterador_k=posicion_0+1; iterador_k < posicion_final ;iterador_k++){
        string[iterador_o] = *(datos+iterador_k);
         iterador_o++;
    }
}
/*como en el texto todos los datos son tipo char, aqui rescato o paso los valores que estan guardados como char a numeros enteros caso, peso y edad*/
int cargando_datos(char valor[],int iterador_j){
    int iterador_k=0;
    int auxiliar = 0;
    for(iterador_k = iterador_j-1;iterador_k >= 0;iterador_k--){
        auxiliar += ((valor[(iterador_j-1)-iterador_k]-'0')*pow(10,iterador_k));
    }
    return auxiliar;
}
/*los string al no inicializarse guardan valores basura en sus especios de memoria, aqui los "limpios" para que no me guareden resultados basura*/
void debbugeando_madres(char vector[]){
    for(int i = 0;i <= 20;i++)vector[i] = '\0';
}
/*este funcion la cree para reemplazar a free en los vectores "dinamicos" que creo en funciones que devuelven valores */
void eliminar_vector(int* vec, int cont_3){
    while((cont_3+1) != 0){
        *(vec+cont_3) = NULL;
        cont_3--;
    }
}
void eliminar_string(char* vec, size_t cont_3){
    while((cont_3+1) != 0){
        *(vec+cont_3) = NULL;
        cont_3--;
    }
}
/*con esta funcione encuentro la posicion de todos los inicio de grupos que hay en el .txt*/
void inicio_posiciones(int vec[], unsigned char* datos){
    int k = 0, i = 0;
    while(*(datos+i) != '\0'){
        if (*(datos+i) == '{'){
            vec[k] =i;                    
            k++;
            }
        i++;
    }
    

}
/*esta funcion se encarga de encontrar las datos que corresponden a cada area de mi estructura*/
personas pasando_lista(unsigned char* datos, int posicion){
    int vec[5] = {0};            
    int* vec_2 = malloc(sizeof(int));          
    int cont = 0;
    int cont_3 = 0;
    char valor[]="  ", valor_2[]="  ";
    int iterador_i = posicion, iterador_j = 0, iterador_k = 0, iterador_p=posicion,iterador_o=0;            
    personas gente;
    debbugeando_madres(gente.nombre);
    debbugeando_madres(gente.apellido);
    while (*(datos+iterador_i) != '}' ){
        if (*(datos+iterador_i) == ':'){
            vec[cont] = iterador_i+1;
            cont++;
        }
        iterador_i++;                                        
    }                                              
     while(*(datos+iterador_p) != '}'){     
         if(*(datos+iterador_p) == ','){
            *(vec_2+cont_3) = iterador_p-1;

            cont_3++;
        }
            iterador_p++;
    } 
    *(vec_2+6) = iterador_p-2;
    iterador_k=0;
    pasando_datos(datos,vec[0],*(vec_2+0),gente.nombre);
    pasando_datos(datos,vec[1],*(vec_2+1),gente.apellido);
    iterador_k = *(vec_2+2)+1;
    pasando_datos(datos,vec[2]-1,iterador_k,valor);
    iterador_k = (*(vec_2+2)+1)-vec[2];
    gente.edad = cargando_datos(valor,iterador_k);
    iterador_k = *(vec_2+3) + 1;
    pasando_datos(datos,vec[3]-1,iterador_k,valor_2);
    iterador_k = (*(vec_2+3)+1)-vec[3];
    gente.peso = cargando_datos(valor_2,iterador_k);
    iterador_k=0;
    iterador_j=0;
    iterador_i = vec[4];
    while (*(datos+iterador_i+iterador_k) != '}' ){      
        if (*(datos+iterador_i+iterador_k) == ',')iterador_j++;   
        iterador_k++;
    }
   
    for(int contando = 0;contando <=iterador_j ;contando++){
        debbugeando_madres(gente.estudiantes[contando]);
    }
    gente.numero_estudiantes = iterador_j+1;
    iterador_i=0;
    iterador_k=0;
    pasando_datos(datos,vec[4]+1,*(vec_2+4),gente.estudiantes[0]);
   for(iterador_i = 1;iterador_i <= iterador_j;iterador_i++){
       pasando_datos(datos,*(vec_2+3+iterador_i)+2,*(vec_2+4+iterador_i),gente.estudiantes[iterador_i]);
    }
   eliminar_vector(vec_2,cont_3);
   return gente;
}
