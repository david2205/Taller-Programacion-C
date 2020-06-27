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
            case '6' : 
            getchar();
            break;
            
            case '7' : 
            getchar();
            break;
            
            
            
            
        }
    }while( toupper(option) != 'S' );
}


int main() {

    mainMenu();
    
    return (EXIT_SUCCESS);
}

