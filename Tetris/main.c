/* 
 * File:   main.c
 * Author: Benjamin Bachmayr
 *
 * Created on 25. November 2016, 21:57
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
void* Thread1();
void* Thread2();

int main(int argc, char** argv) {
    
    pthread_t thread1, thread2;
    
    pthread_create( &thread1, NULL, Thread1, NULL);
    pthread_create( &thread2, NULL, Thread2, NULL);
    
    

    return (EXIT_SUCCESS);
}

void* Thread1(){
    while(1){
        
    }
}
void* Thread2(){
    while(1){
        
    }
}