/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Propietario
 *
 * Created on 26 de junio de 2020, 06:19 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
    "6. Secuencia de palabras Fibonacci\n"
    "7. Resultado de prueba\n"
    "8. Salir\n"
    "\nDigite una opcion\n";
    do{
        printf(mainMenu);
        scanf("%d",&option);
        fflush(stdin);
        switch(option){
            
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
