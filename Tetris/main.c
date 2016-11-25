/* 
 * File:   main.c
 * Author: Benjamin Bachmayr
 *
 * Created on 25. November 2016, 21:57
 */

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

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
    
    int takt=220; //takt in ms = 1/8 Ton
    float c2=523.251; //c''
    float d2=587.330; //d''
    float e2=622.254; //e'' um Halbton niedriger
    float f2=698.456; //f''
    float g2=783.991; //g''
    float a2=830.609; //a'' um Halbton niedriger
    float h2=932.328; //h'' um Halbton niedriger
    float c3=1046.50; //c'''
    
    while(1){
        
    Beep(g2,takt*2); //g'' 1. Zeile
    Beep(d2,takt*1); //d''
    Beep(e2,takt*1); //e''

    Beep(f2,takt*2); //f''
    Beep(e2,takt*1); //e''
    Beep(d2,takt*1); //d''

    Beep(c2,takt*2); //c''
    Beep(c2,takt*1); //c''
    Beep(e2,takt*1); //e''

    Beep(g2,takt*2); //g''
    Beep(f2,takt*1); //f''
    Beep(e2,takt*1); //e''

    Beep(d2,takt*3); //d'' (2 Toene)
    Beep(e2,takt*1); //e''

    Beep(f2,takt*2); //f''
    Beep(g2,takt*2); //g''

    Beep(e2,takt*2); //e''
    Beep(c2,takt*2); //c''

    Beep(c2,takt*2); //c''
    Sleep(takt*2); //Pause

    Sleep(takt*1); //Pause 2. Zeile
    Beep(f2,takt*2); //f'' (2 Toene)
    Beep(a2,takt*1); //a''

    Beep(c3,takt*2); //c'''
    Beep(h2,takt*1); //h''
    Beep(a2,takt*1); //a''

    Beep(g2,takt*3); //g'' (2 Toene)
    Beep(e2,takt*1); //e''

    Beep(g2,takt*2); //g''
    Beep(f2,takt*1); //f''
    Beep(e2,takt*1); //e''

    Beep(d2,takt*2); //d''
    Beep(d2,takt*1); //d''
    Beep(e2,takt*1); //e''

    Beep(f2,takt*2); //f''
    Beep(g2,takt*2); //g''

    Beep(e2,takt*2); //e''
    Beep(c2,takt*2); //c''

    Beep(c2,takt*2); //c''
    Sleep(takt*2); //Pause
        
    }
}