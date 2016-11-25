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
void* PlayBackgroundMusic();

int main(int argc, char** argv) {
    
    pthread_t thread1, music;
    
    pthread_create( &thread1, NULL, Thread1, NULL);
    pthread_create( &music, NULL, PlayBackgroundMusic, NULL);
    
    while(1);

    return (EXIT_SUCCESS);
}

void* Thread1(){
    while(1){
        
    }
}
void* PlayBackgroundMusic(){
    
        const int C    = 261;
        const int Cis  = 277;
        const int D    = 293;
        const int Dis  = 311;
        const int E    = 329;
        const int F    = 349;
        const int Fis  = 369;
        const int G    = 391;
        const int Gis  = 415;
        const int A    = 440;
        const int Ais  = 466;
        const int H    = 493;
        const int Takt = 1700;
    
    while(1){
        
        Beep(E * 2, Takt / 4);
        Beep(H * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 8);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 2.5);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 4);
        Sleep(Takt / (8 / 3));
        Beep(D * 2, Takt / 3.25);
        Beep(F * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(A * 2, Takt / 8);
        Beep(G * 2, Takt / 8);
        Beep(F * 2, Takt / 8);
        Beep(E * 2, Takt / 3);
        Beep(C * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(E * 2, Takt / 8);
        Beep(D * 2, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(H * 1, Takt / 4);
        Beep(H * 1, Takt / 8);
        Beep(C * 2, Takt / 8);
        Beep(D * 2, Takt / 4);
        Beep(E * 2, Takt / 4);
        Beep(C * 2, Takt / 4);
        Beep(A * 1, Takt / 4);
        Beep(A * 1, Takt / 4);
        
    }
}