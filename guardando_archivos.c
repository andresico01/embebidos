
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct{
    char nombre[20];
    char apellido[20];
    int edad;
    int peso;
    int numero_estudiantes;
    char estudiantes[10][20];
}personas;
/*typedef struct {
    int nombre;
    int apellido;
    int edad;
    int peso;
    int N_estudiente[10];
}contando_ando;*/

personas pasando_lista(unsigned char* datos);           //con esto paso los datos de texto plano a los valores que guarda mi estructura persona 
int cargando_datos(char valor[],int iterador_j);                       // una cochinada que hice por salir del paso por que ya tenia sueño, cambialo mas tardesito.
void debbugeando_madres(char vector[]);                 //con esta funcion lleno de \0 o valor null los vectores y matrices pertenecientes a mi estructura personas 
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
        if (*(contenido+i) == '}'){
            j[k] =i;                    //vector que registra la terminacion de cada grupo o bloque ne mi texto plano
            k++;
            }
        i++;
    }
    *(unidad+0) = pasando_lista(contenido);                 // esto posiblemente no lo use, solo tenia la idea de pasar un vector dinamico de mi tipo de datos persona
    printf("\n%s\n",(unidad+0)->estudiantes[2]);                    // para asi asiganarl los valores mas rapido a mi lista en mi funcion principal, esto es un borrador. por asi
    //printf("\n%d\n",fseek(archivo,11,SEEK_SET));          //decirlo la idea es hacer una libreria que me contenga las funciones que hecho aqui, asi como hice una 
   // printf("%d\t%d\n",j[0],j[1]);                         //libreria para trabajar con listas. 
    
    free(contenido);
    fclose(archivo);                
    return EXIT_SUCCESS;
}
personas pasando_lista(unsigned char* datos){
    int* vec = malloc(sizeof(int));             // este vector guarda posiciones de mi vector que contiene el texto entero, estas posiciones las uso para sacar los valores
    int* vec_2 = malloc(sizeof(int));           // mismo que lo de arriba, pero aja. 
    int cont = 0;
    int cont_3 = 0;
    char valor[]="   ", valor_2[]="   ";
    int iterador_i = 0, iterador_j = 0, iterador_k = 0, iterador_p=0,iterador_o=0;            
    personas gente;
    debbugeando_madres(gente.nombre);
    debbugeando_madres(gente.apellido);

//    contando_ando contador;
    while (*(datos+iterador_i) != '}' ){
        if (*(datos+iterador_i) == ':'){
    
            *(vec+cont) = iterador_i+1;
           // printf(": %d\t",*(vec+cont));
            cont++;
        }/*else if(*(datos+i) == '}'){ // esto debo cambiarlo esta deberia ser la condicioen del while, recuerdalo pa mas tarde 
            //printf("\nfinalizo con una persona\n");
            break;
        }*/else if(*(datos+iterador_i) == ','){
            *(vec_2+cont_3) = iterador_i-1;
            //printf(", %d\t",*(vec_2+cont_3));
            cont_3++;
        }
        iterador_p++;
        iterador_i++;                                        //posicion final del contenido de texto.
    }   
    *(vec_2+0) = 18;
    *(vec_2+6) = iterador_p-2;
    *(vec+4) = 73;
    //fflush(stdin);
   /* printf("\n");
    for(k=0;k<=cont_3;k++)printf("%d\t",*(vec_2+k));
    printf("\n");
    for(k=0;k<cont;k++)printf("%d\t",*(vec+k));
    */
    iterador_k=0;
    for (iterador_j = *(vec+0)+1 ;iterador_j < *(vec_2+0);iterador_j++ ){
        gente.nombre[iterador_k] = *(datos+(*(vec+0)+1)+iterador_k);      //aqui uso los vectores dinamicos que guardan posiciones para sacar la info que requiero.
        iterador_k++;
    }
    iterador_k = 0;
    for (iterador_j = *(vec+1 )+1; iterador_j < *(vec_2+1);iterador_j++ ){
        gente.apellido[iterador_k]= *(datos+(*(vec+1)+1)+iterador_k);
       // printf("%c",*(datos+(32+k)));
        iterador_k++;
    }
    iterador_k=0;
    for (iterador_j = *(vec + 2 ) ;iterador_j <= *(vec_2 + 2);iterador_j++ ){
        valor[iterador_k] = *(datos+(*(vec+2))+iterador_k);
        iterador_k++;
    }
    gente.edad = cargando_datos(valor,iterador_k);
    iterador_k=0;
    for (iterador_j = *(vec + 3 ) ;iterador_j <= *(vec_2 + 3);iterador_j++ ){
        valor_2[iterador_k] = *(datos+(*(vec+3))+iterador_k);
        iterador_k++;
    }
    gente.peso = cargando_datos(valor_2,iterador_k);
    //printf("\n%d\n",k);
  //printf("\nbello %d\t %d\n",*(vec_2+0),*(vec+1));
   // printf("\n%s\n",gente.nombre);
   // printf("\n%s\n",gente.apellido);
  //  printf("\n%s\n",valor);
    //printf("\n%d\n",gente.edad);
  //  printf("\n%s\n",valor_2);
    //printf("\n%d\n",gente.peso);
    iterador_k=0;
    iterador_j=0;
    iterador_i = *(vec+4);
   // printf("\n%c\n",(datos+*(vec+4)+1));
    while (*(datos+iterador_i+iterador_k) != '}' ){      /// con esto saco las filas de la matriz que contendran los nombres de mis estudientes. la inilializo ahi para que sea
        if (*(datos+iterador_i+iterador_k) == ',')iterador_j++;   /// mas "rapido"
        iterador_k++;
    }
   // printf("\n%d\n",j);
    for(int contando = 0;contando <=iterador_j ;contando++){
        debbugeando_madres(gente.estudiantes[contando]);
    }
    gente.numero_estudiantes = iterador_j+1;
    iterador_i=0;
    iterador_k=0;
    for(iterador_k=*(vec+4); iterador_k < *(vec_2+4)-2;iterador_k++){
        gente.estudiantes[0][iterador_o] = *(datos+*(vec+4)+iterador_o);
         iterador_o++;
    }
    iterador_o=0;
    //printf("\n%d\n",j);
   for(iterador_i = 1;iterador_i <= iterador_j;iterador_i++){
        for(iterador_k=*(vec_2+3+iterador_i)+1; iterador_k <*(vec_2+4+iterador_i)-2;iterador_k++){
            gente.estudiantes[iterador_i][iterador_o] = *(datos+*(vec_2+3+iterador_i)+3+iterador_o);
            iterador_o++;
            //printf("%d\t",k);
        }
        iterador_o=0;
    }
    
    //for(i=0;i<j;i++)printf("\n%s\n",gente.estudiantes[i]);
   //printf("\n%s\n",gente.estudiantes[0]);
   return gente;

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
