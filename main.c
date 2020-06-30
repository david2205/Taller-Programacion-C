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

void imc() {

    float height, weight, gender, imc, m;

    printf("Digite su genero 1 si es masculino , 2 si es femenino: ");
    scanf("%f", &gender);

    if (gender == 1 || gender == 2) {
        
    printf("Digite su estatura en centimetros : ");
    scanf("%f", &height);

    printf("Digite su peso en kg: ");
    scanf("%f", &weight);


    m = height / 100;

    imc = weight / (m * m);

    printf("\nSu IMC es: %.1f", imc);

    if (gender == 1) {
        if (imc < 17) {
            printf("\nSu estado es: Desnutricion\n");
        } else {
            if (imc > 17 && imc < 20) {
                printf("\nSu estado es: Bajo peso\n");
            } else {
                if (imc > 20 && imc < 25) {
                    printf("\nSu estado es: Nomal\n");
                } else {
                    if (imc > 25 && imc < 30) {
                        printf("\nSu estado es: Sobre peso\n");
                    } else {
                        if (imc > 30 && imc < 35) {
                            printf("\nSu estado es: Obesidad\n");
                        } else {
                            if (imc > 35 && imc < 40) {
                                printf("\nSu estado es: Obesidad marcada\n");
                            } else {
                                if (imc > 40) {
                                    printf("\nSu estado es: Obesidad Morbida\n");
                                }
                            }
                        }
                    }
                }

            }
        }
    } else {
        if (imc < 16) {
            printf("\nSu estado es: Desnutricion\n");
        } else {
            if (imc > 16 && imc < 20) {
                printf("\nSu estado es: Bajo peso\n");
            } else {
                if (imc > 20 && imc < 24) {
                    printf("\nSu estado es: Normal\n");
                } else {
                    if (imc > 24 && imc < 29) {
                        printf("\nSu estado es: Sobre peso\n");
                    } else {
                        if (imc > 29 && imc < 34) {
                            printf("\nSu estado es: Obesidad\n");
                        } else {
                            if (imc > 34 && imc < 39) {
                                printf("\nSu estado es: Obesidad marcada\n");
                            } else {
                                if (imc > 39) {
                                    printf("\nSu estado es: Obesidad Morbida\n");
                                }

                            }

                        }
                    }
                }
            }
        }

    }
    }else{
        printf("Error... Opcion invalida");
    }

    printf("\nEnter para continuar");
    getchar();
}

void sumaDigitos() {
    int less = 0, higher = 0, exclude = 0, sumExclude = 0, sumInclude = 0, dig = 0, num = 0, contExc = 0, suma = 0;

    printf("Digite el valor menor del rango: ");
    scanf("%d", &less);
    getchar();
    printf("Digite el valor mayor del rango: ");
    scanf("%d", &higher);
    getchar();
    printf("Digite el valor que desea excluir del intervalo: ");
    scanf("%d", &exclude);
    getchar();

    for (int i = less; i <= higher; i++) {
        num = i;
        while (num != 0) {
            dig = num % 10;
            num = num / 10;

            if (dig == exclude) {
                contExc++;
            } else {
                suma += dig;
            }
        }
    }
    sumExclude = contExc;
    sumInclude = suma;
    printf("Los excluidos fueron %d y la suma del resto es %d", sumExclude, sumInclude);
    printf("\nEnter para continuar");
    getchar();
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
            "4. Indice de masa corporal\n"
            "5. Sumatoria de digitos\n"
            "6. Secuencia de bits Fibonacci\n"
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
            
            case 4: imc();
            getchar();
            break;
            
            case 5: sumaDigitos();
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
