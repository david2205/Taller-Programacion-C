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

char* calculateSerie(int n){
    if (n==0){
        return "0";
    }else if(n==1){
        return "1";
    }else{
        return "10";
    }
}

void calSecuensiaFib(){
    printf("En construccion--->%s\nEnter para continuar",calculateSerie(1));
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
    char option;
    
    char *mainMenu = "<<<<<MENU PRINCIPAL>>>>>\n\n"
    "6. Secuencia de palabras Fibonacci\n"
    "7. Resultado de prueba\n"
    "\nDigite una opcion ([s/S]-Salir)\n";
    do{
        printf(mainMenu);
        scanf("%c",&option);
        fflush(stdin);
        switch(option){
            
            case '6' : calSecuensiaFib();
            getchar();
            break;
            
            case '7' : calResultadoPrueba();
            getchar();
            break;
            
            default:
            printf("OPCION NO VALIDA\n");
            getchar();
                break;
            
        }
    }while( toupper(option) != 'S' );
}


int main() {

    mainMenu();
    
    return (EXIT_SUCCESS);
}
