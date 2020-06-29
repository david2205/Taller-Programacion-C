#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

    void NumPrimos(){
     int i,j,cont,n;
     printf( "\n   Introduzca un numero entero: ");
     if(scanf( "%d", &n )==1){
        for(i=n;i>=2;i--){
            cont=1;
            for(j=2;j<i;j++)
                if(i%j==0)
                    cont=0;
                if(cont)
                    printf("%d-",i);          
     }
     printf("\nEnter para continuar");
     getchar();
     }else{
         printf( "\n ERROR!!! introduzca un entero \n");
         getchar();
     }
    }
    
    void numEgolatra(){
        int n,tam,tot=0,resultado=0;
        printf( "\n Introduzca el TAMAÑO del entero: ");
        if(scanf( "%d", &tam )==1){
        int num[tam];
        for(int i=0;i<tam;i++){
            printf( "\n   Introduzca el DIGITO del numero en la posicion %d ------->",i+1);
            if(scanf( "%d", &num[i]) !=1 ){
                printf( "\n ERROR!!!!.....SOLO VALORES ENTEROS!!!! \n\n");
                break;
            }
        }
        for(int i=0;i<tam;i++){
            tot+=pow(num[i],tam);
             }
        unsigned char i;
        for(i=0;i<tam;i++){
            resultado=resultado*10+num[i];
            }
            if(resultado==tot){
                printf("\n ******Si es un numero Egolatra***** \n");
            }else{
                printf("\n *********Lo siento No es un numero Egolatra******** \n");
            }
        printf("\nEnter para continuar");
        getchar();
        }else{
             printf( "\n ERROR!!!!.....Introduzca un valor entero");
             getchar();
        }
    }
    
    void numMagico(){
        int n,tam,mayor=0,menor=0,original=0;
        unsigned char i;
        printf( "\n Introduzca el TAMAÑO del entero: ");
        if(scanf( "%d", &tam )==1){
        int num[tam];
            for(int i=0;i<tam;i++){
                printf( "\n   Introduzca el DIGITO del numero en la posicion %d ------->",i+1);
               if(scanf( "%d", &num[i]) !=1 ){
                printf( "\n ERROR!!!!.....SOLO VALORES ENTEROS!!!! \n\n");
                break;
            }
            }
            for(i=0;i<tam;i++){
                original=original*10+num[i];
            }
       int aux=0;
        for(int j=0;j<tam;j++){
            for(int i=0;i<tam-1;i++){
                if(num[i]>num[i+1]){
                    aux=num[i];
                    num[i]=num[i+1];
                    num[i+1]=aux;
                }
            }
        }
            for(i=0;i<tam;i++){
                menor=menor*10+num[i];
            }
       int temp,cont;
       cont=0;
        while(cont<tam/2){
            temp=num[cont];
            num[cont]=num[tam-1-cont];
            num[tam-1-cont]=temp;
            cont++;
                  }
            for(i=0;i<tam;i++){
                mayor=mayor*10+num[i];
            }
        if((mayor-menor)==original){
            printf("\n *******SI ES UN NUMERO MAGICO********* \n");
          }else{
            printf("\n *******NO ES UN NUMERO MAGICO********* \n");
          }
       printf("\nEnter para continuar");
       getchar();
        }else{
             printf( "\n ERROR!!!!.....Introduzca un valor entero");
            getchar();
        }
    }

char* calculateSerie(int n,char *chain){
    if ( n==0 || n==1 ){
        if ( n==1 ){
            strcat(chain, "1");
        }else{
            strcat(chain, "0");
        }
    }else{
        *calculateSerie( n-1, chain ) + *calculateSerie( n-2, chain);
    }
    return chain;
}

void calSecuenciaFib(){
    long n;
    int cont1=0,cont2=0,cont3=0,lenSer=0,lenPat=0;
    char chain[80]="",chain2[80]="",chain4[80]="",numberSerie[80]="", *aux, pattern[80]="",var4[80]="";
    printf("Digite el numero n para la serie :");
    getchar();
    if (fgets(numberSerie, sizeof(numberSerie), stdin)){
        n = strtol(numberSerie, &aux, 10);
        if (aux == numberSerie || *aux != '\n'){
            printf("\nLas cadenas y los decimales no son validos, debe digitar un numero entero positivo");
        }else{
            if ( n >= 0 ){
                printf("\nDigite el patron de bits (0,1) a buscar: ");
                scanf("%s", pattern);
                
                char var1[80]="",var2[80]="",var3[80]="";

                for (int i = 0; i < strlen(pattern); i++) {
                    cont1 += strcmp(strncpy(var1, &pattern[i], 1), "0") == 0 || strcmp(strncpy(var1, &pattern[i], 1), "1") == 0 ? 1 : 0;
                    cont2 += (i + 2 <= strlen(pattern) && strcmp(strncpy(var2, &pattern[i], 2), "00") == 0) || (i + 3 <= strlen(pattern) && strcmp(strncpy(var3, &pattern[i], 3), "111") == 0) ? 1 : 0;
                }
                if ( cont1 == strlen(pattern) && cont2 == 0){
                    lenSer = strlen(calculateSerie(n,chain));
                    lenPat = strlen(pattern);
                    if ( lenSer >= lenPat ){
                        char *chain3 = calculateSerie(n,chain4);
                        for (int i=0 ; i<lenSer ; i++){
                            if (strcmp(strncpy(var4,&chain3[i * lenPat],lenPat),pattern)==0){
                                cont3++;
                            }
                        }
                        printf("\nEl patrón de bits %s se encuentra %d veces en f(%ld) = %s", pattern,cont3,n,calculateSerie(n,chain2));
                    }else{
                        printf("El patron de bits %s es demasiado largo para la serie f(n) con n = %ld",pattern, n);
                    }
                }else{
                    printf(cont2 != 0 ? "\nEl patrón de bits %s se encuentra 0 veces en f(n) para n = %ld" : "\nEl patron digitado no corresponde a un patron de bits (0,1)", pattern, n);
                }
            }else {
                printf("\nEl numero n debe ser positivo\n");
            }      
        }
    }
    printf("\nEnter para continuar");
    getchar();
}

int calculateResultado(char* res){
    int cont = 0,resTot = 0;
    for (int i=0 ; i<strlen(res) ; i++){
        if (res[i]=='O'){
            cont++;
            resTot += cont;
        }else{
            cont = 0;
        }
    }
    return resTot;
}

int validarCadena (char* cad){
    int bool = 0;
    for (int i=0 ; i<strlen(cad) ; i++){
        if (cad[i]=='O' || cad[i]=='X'){
            bool = 0;
        }else{
            bool = 1;
            return bool;
        }
    }
    return bool;
}

void calResultadoPrueba(){
    char resultado[50];
    printf("Digite la cadena de caracteres resultado de la prueba. Ejp: XXXOOXO; donde las O represantan una respuesta correcta y las X una incorrecta:  ");
    scanf("%s", resultado);
    for (int i=0 ; i<strlen(resultado) ; i++){
        resultado[i] = toupper(resultado[i]);
    }
    if (validarCadena(resultado)==0){
        printf("La cadena ingresada es [%s] y el resultado fue %d",resultado,calculateResultado(resultado));
    }else{
        printf("La cadena ingresada es incorrecta");
    }
    printf("\nEnter para continuar");
    getchar();
}


void mainMenu(){
    int option;
    
    char *mainMenu = "<<<<<MENU PRINCIPAL>>>>>\n\n"
    "1. Calcular numeros primos\n"
    "2. Calcular Numero Egolatra\n"
    "3. Calcular Numero Magico\n"
    "6. Secuencia de palabras Fibonacci\n"
    "7. Resultado de prueba\n"
    "8. Salir\n"
    "\nDigite una opcion\n";
    do{
        printf(mainMenu);
        scanf("%d",&option);
        fflush(stdin);
        switch(option){
            case 1: NumPrimos();
            getchar();
            break;

            case 2: numEgolatra();
            getchar();
            break;

            case 3: numMagico();
            getchar();
            break;
            
            case 6 : calSecuenciaFib();
            getchar();
            break;
            
            case 7 : calResultadoPrueba();
            getchar();
            break;
            
            default:
            printf(option == 8 ? "EL PROGRAMA FINALIZO\n" : "OPCION NO VALIDA\n\n");
            getchar();
            break;
            
        }
    }while( option != 8 );
}


int main() {

    mainMenu();
    
    return (EXIT_SUCCESS);
}
