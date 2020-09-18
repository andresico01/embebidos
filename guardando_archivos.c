#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef char string[20];
typedef struct{
    string nombre;
    string apellido;
    int edad;
    int peso;
    int numero_estudiantes;
    string estudiantes[10];
}personas;
void pasando_datos(char* datos, int posicion_0, int posicion_final,char string[]);
personas pasando_lista(unsigned char* datos,int posicion);           //con esto paso los datos de texto plano a los valores que guarda mi estructura persona 
int cargando_datos(char valor[],int iterador_j);                       // una cochinada que hice por salir del paso por que ya tenia sueño, cambialo mas tardesito.
void debbugeando_madres(char vector[]);     
void eliminar_vector(int* vec,int cont_3);            //con esta funcion lleno de \0 o valor null los vectores y matrices pertenecientes a mi estructura personas 
int main (){
    FILE* archivo = fopen("pal profe.txt","rt");
    size_t tamano;
    personas* unidad = malloc(sizeof(personas));        //creo un vector dinamico de mi estructura personas, esto no lo implementare al final, solo queria saber si 
    int i=0;                                            //funcionaba
    int j[10]= {0};
    unsigned char* contenido;
    unsigned char k = 0;
    
    fseek(archivo,0, SEEK_END);
    tamano = ftell(archivo);
    fseek(archivo,0, SEEK_SET);                     //le digo al cursor que vaya al inicio del texto

    contenido = malloc(tamano* sizeof(char));
    fread(contenido, sizeof(char), tamano, archivo);        //ingreso en un vector dinamico tipo char todos los  datos del texto plano

    printf("contenido : \n%s\n",contenido);
    while(*(contenido+i) != '\0'){
        if (*(contenido+i) == '{'){
            j[k] =i;                    //vector que registra la terminacion de cada grupo o bloque ne mi texto plano
            k++;
            }
        i++;
    }
    //printf("\n%d\n",k);
   // for(int contar = 0;contar < k;contar++ ){
    *(unidad+0) = pasando_lista(contenido,j[0]);
    printf("\n%s\t%s\t%s\n",(unidad+0)->estudiantes[0],(unidad+0)->estudiantes[1],(unidad+0)->estudiantes[2]);                    // para asi asiganarl los valores mas rapido a mi lista en mi funcion principal, esto es un borrador. por asi
   
   printf("\n%d\t%d\n",(unidad+0)->edad,(unidad+0)->peso);
                                                             // esto posiblemente no lo use, solo tenia la idea de pasar un vector dinamico de mi tipo de datos persona
                                                            //decirlo la idea es hacer una libreria que me contenga las funciones que hecho aqui, asi como hice una 
    printf("%d\t%d\n",j[0],j[1]);                         //libreria para trabajar con listas. 
    
    free(contenido);
    fclose(archivo);                
    return EXIT_SUCCESS;
}
personas pasando_lista(unsigned char* datos, int posicion){
    int vec[5] = {0};             // este vector guarda posiciones de mi vector que contiene el texto entero, estas posiciones las uso para sacar los valores
    int* vec_2 = malloc(sizeof(int));           // mismo que lo de arriba, pero aja. 
    int cont = 0;
    int cont_3 = 0;
    char valor[]="  ", valor_2[]="  ";
    int iterador_i = posicion, iterador_j = 0, iterador_k = 0, iterador_p=posicion,iterador_o=0;            
    personas gente;
    debbugeando_madres(gente.nombre);
    debbugeando_madres(gente.apellido);
//    contando_ando contador;
    while (*(datos+iterador_i) != '}' ){
        if (*(datos+iterador_i) == ':'){
    
            vec[cont] = iterador_i+1;
           // printf(": %d\t",vec[cont]);
            cont++;
        }
        iterador_i++;                                        //posicion final del contenido de texto.
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
    while (*(datos+iterador_i+iterador_k) != '}' ){      /// con esto saco las filas de la matriz que contendran los nombres de mis estudientes. la inilializo ahi para que sea
        if (*(datos+iterador_i+iterador_k) == ',')iterador_j++;   /// mas "rapido"
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
void pasando_datos(char* datos, int posicion_0, int posicion_final,char string[]){
    int iterador_k = 0,iterador_o = 0;
    for(iterador_k=posicion_0+1; iterador_k < posicion_final ;iterador_k++){
        string[iterador_o] = *(datos+iterador_k);
         iterador_o++;
    }
}
int cargando_datos(char valor[],int iterador_j){
    int iterador_k=0;
    int auxiliar = 0;
    for(iterador_k = iterador_j-1;iterador_k >= 0;iterador_k--){
        auxiliar += ((valor[(iterador_j-1)-iterador_k]-'0')*pow(10,iterador_k));
    }
    return auxiliar;
}
void debbugeando_madres(char vector[]){
    for(int i = 0;i <= 20;i++)vector[i] = '\0';
}
void eliminar_vector(int* vec, int cont_3){
    while((cont_3+1) != 0){
        *(vec+cont_3) = NULL;
        cont_3--;
    }
}
