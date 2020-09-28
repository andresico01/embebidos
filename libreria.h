#include<stdio.h>
#include<stdlib.h>
//#include"texto_lista.h"
typedef char texto[20];
typedef struct{
    texto nombre;
    texto apellido;
    int edad;
    int peso;
    int numero_estudiantes;
    texto estudiantes[10];
}personas;
typedef struct{
    personas datos;
    struct Nodo* ptrNext;
} Nodo;
Nodo *header = NULL;
Nodo *footer = NULL;
void limpiar(void){
    while (getchar()!='\n');
}
int potencia(int base, int exp){
    int res;
    if (exp == 0){
        res=1.0;
    }else if (exp > 0){
        res=base * potencia(base,exp - 1);
    }
    else if (exp < 0){
        res= 1.0 / base *potencia(base,exp + 1);
    }
    return res;
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
Nodo *new(personas gente){
    Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo));
    nuevo->datos = gente;
    nuevo->ptrNext = NULL;
    return(nuevo);
}
personas ingreso_datos(){
    int i = 0;
    personas referencia;

    fflush(stdin);
    printf("ingrese los datos de referencia del  docente\n");
    printf("\n ingrese el nombre del docente\n");
    scanf("%s",referencia.nombre);
   
    fflush(stdin);
    printf("\n ingrese el apellido del docente\n");
    scanf("%s",referencia.apellido);
  
    printf("\n ingrese su edad\n");
    scanf("%d",&referencia.edad);
    fflush(stdin);
    printf("\n ingrese peso \n");
    scanf("%d",&referencia.peso);
    printf("\n ingrese numero de estudiantes\n");
    scanf("%d",&referencia.numero_estudiantes);
    
    do{
        printf("\ningrese el nombre del estudiante\n");
        scanf("%s",referencia.estudiantes[i]);
        i++;
   }while(i < referencia.numero_estudiantes);
  // limpiar();
   return referencia;
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
            mostrar_datos(i->datos);
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
           printf("\nla lista no es tan extensa, vaya a la opcion 1 a insertar datos\n");
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
void insertar_grupo(personas grupo, int posicion){
    Nodo *new_node = new(grupo);                    
    unsigned char cont = 0;                                           

    Nodo *aux = header;                               
    Nodo *aux2 = NULL;                                     
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
void menu(){
    //personas docentes = ingreso_datos();
    personas gente;
    Nodo* nuevo_nodo = NULL;
    
    unsigned int opcion = 0, cont = 0, posicion;
    //personas gente;
    do{
        printf("\n1)ingresar datos a la lista \n2)mostrar los grupos de la lista  \n3)agregar algun grupo a la lista \n4)eliminar un grupo en especial\n5)salir");
        printf("\nque opcion desea?\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch (opcion){
            
            case 1 : 
                gente = ingreso_datos();
                nuevo_nodo = new(gente);
                insertar(nuevo_nodo);
                free(nuevo_nodo);
                nuevo_nodo = nuevo_nodo->ptrNext;
                cont++;
                
                system("pause");
                break;
            case 2 :
                run();
               // fflush(stdin);
                system("pause");
                break;
            case 3 :
                //fflush(stdin);
                
                printf("\ningrese la posicion en la que desea agregar el nuevo valor.\nsi esta es mayor al tamaño de la lista habra error\n");
                scanf("%d",&posicion);
                gente = ingreso_datos();    
                insertar_grupo(gente,posicion);
                system("pause");
                 break;
            case 4 : 
              //  fflush(stdin);
                printf("\ningrese la posicion en la que desea elimnar.\nsi esta es mayor a el tamaño de la lista habra error\n");
                scanf("%d",&posicion);
                pop(posicion);
                system("pause");
                break;    
        }
  
    system("cls");
    }while(opcion < 5);  
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
   //printf("\n%d\n",iterador_j-2);
    for(iterador_k = iterador_j-2;iterador_k >= 0;iterador_k--){
        auxiliar += ((valor[(iterador_j-2)-iterador_k]-'0')*potencia(10,iterador_k));
       // printf("%d\t",auxiliar);
    }
   // printf("\n");
    return auxiliar;
}
/*los string al no inicializarse guardan valores basura en sus especios de memoria, aqui los "limpios" para que no me guareden resultados basura*/
void debbugeando_madres(char vector[]){
    int i = 0;
    for( i = 0;i <= 20;i++)vector[i] = '\0';
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
void pasando_lista(personas* gente,unsigned char* datos, int posicion){
    int vec[5] = {0};            
    int* vec_2 = (int*)malloc(sizeof(int));          
    int cont = 0;
    int cont_3 = 0;
    char valor[]="  ", valor_2[]="  ";
    int iterador_i = posicion, iterador_j = 0, iterador_k = 0, iterador_p=posicion,iterador_o=0;            
    debbugeando_madres(gente->nombre);
    debbugeando_madres(gente->apellido);
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
    *(vec_2+6) = iterador_p-3;
    iterador_k=0;
    
    pasando_datos(datos,vec[0]+1,*(vec_2+0),gente->nombre);
    
    pasando_datos(datos,vec[1]+1,*(vec_2+1),gente->apellido);
    
    iterador_k = *(vec_2+2)+1;
    pasando_datos(datos,vec[2],iterador_k,valor);
    iterador_k = (*(vec_2+2)+1)-vec[2];
    gente->edad = cargando_datos(valor,iterador_k);
    iterador_k = 0;
    iterador_k = *(vec_2+3) + 1;
    pasando_datos(datos,vec[3],iterador_k,valor_2);
    iterador_k = (*(vec_2+3)+1)-vec[3];
    gente->peso = cargando_datos(valor_2,iterador_k);
    iterador_k=0;
    iterador_j=0;
    iterador_i = vec[4];
    while (*(datos+iterador_i+iterador_k) != '}' ){      
        if (*(datos+iterador_i+iterador_k) == ',')iterador_j++;   
        iterador_k++;
    }
    int contando = 0;
    for(contando = 0;contando <=iterador_j ;contando++){
        debbugeando_madres(gente->estudiantes[contando]);
    }
    gente->numero_estudiantes = iterador_j+1;
    iterador_i=0;
    iterador_k=0;
    pasando_datos(datos,vec[4]+2,*(vec_2+4),gente->estudiantes[0]);
    
   for(iterador_i = 1;iterador_i <= iterador_j;iterador_i++){
       pasando_datos(datos,*(vec_2+3+iterador_i)+3,*(vec_2+4+iterador_i),gente->estudiantes[iterador_i]);
       
    }
   eliminar_vector(vec_2,cont_3);
}
