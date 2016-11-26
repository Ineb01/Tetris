/* 
 * File:   main.c
 * Author: Benjamin Bachmayr
 *
 * Created on 25. November 2016, 21:57
 */

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define XSIZE 5
#define YSIZE 5
#define XSIZEFORM 3
#define YSIZEFORM 3
#define FORMCOUNT 1

void* PrintThread();
void* PlayBackgroundMusic();
void SpawnForm(int xpos, int ypos, int form);
void ClearForm(int xpos, int ypos, int form);
int Sum();

int rgForm[XSIZEFORM][YSIZEFORM] = {2, 2, 2,
                                    -1, 2, -1,
                                    0, -1, 0};

int rgMain[XSIZE][YSIZE] = {0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 0, 0,
                            0, 0, 0, 2, 0,
                            0, 0, 0, 0, 0};

int main(int argc, char** argv) {

    pthread_t thread1, music;

    pthread_create(&thread1, NULL, PrintThread, NULL);
    pthread_create(&music, NULL, PlayBackgroundMusic, NULL);

    printf("\e[?25l");

    int x = 0, y = 1, sum, sum1, i = 1;

    SpawnForm(x, y, 1);
    sum = Sum();
    sum1 = Sum();
    while (1) {
        sleep(1);
        sum = Sum();
        if (sum != sum1) {
            i = 0;
        }
        ClearForm(x, y, 1);
        if (i) {
            x++;
        }
        SpawnForm(x, y, 1);
    }

    return (EXIT_SUCCESS);
}

void* PrintThread() {

    int x, y;

    while (1) {

        printf("\033[%d;%dH", 0, 0);

        for (x = 0; x < XSIZE; x++) {
            for (y = 0; y < YSIZE; y++) {
                if (rgMain[x][y] > 0)printf("#", rgMain[x][y]);
                else printf(" ");
            }
            printf("\n");
        }

        for (x = 0; x < XSIZE; x++) {
            printf("-");
        }
        printf("\n");

        for (x = 0; x < XSIZE; x++) {
            for (y = 0; y < YSIZE; y++) {
                if (rgMain[x][y] >= 0)
                    printf(" %d", rgMain[x][y]);
                if (rgMain[x][y] < 0)
                    printf("%d", rgMain[x][y]);
            }
            printf("  \n");
        }
    }
}

void SpawnForm(int xpos, int ypos, int form) {

    int x, y;
    for (x = 0; x < XSIZEFORM; x++) {
        for (y = 0; y < YSIZEFORM; y++) {

            rgMain[x + xpos][y + ypos] = rgMain[x + xpos][y + ypos] + rgForm[x][y];

        }
    }
}

void ClearForm(int xpos, int ypos, int form) {
    int x, y;
    for (x = 0; x < XSIZEFORM; x++) {
        for (y = 0; y < YSIZEFORM; y++) {
            rgMain[x + xpos][y + ypos] = rgMain[x + xpos][y + ypos] - rgForm[x][y];
        }
    }
}

int Sum() {
    int x, y, sum = 0;
    for (x = 0; x < XSIZE; x++) {
        for (y = 0; y < YSIZE; y++) {
            if (rgMain[x][y] > 0)
                sum = sum + rgMain[x][y];
            if (rgMain[x][y] < 0)
                sum = sum - rgMain[x][y];
        }
    }
    return sum;
}

void* PlayBackgroundMusic() {

    int takt = 220; //takt in ms = 1/8 Ton
    float c2 = 523.251; //c''
    float d2 = 587.330; //d''
    float e2 = 622.254; //e'' um Halbton niedriger
    float f2 = 698.456; //f''
    float g2 = 783.991; //g''
    float a2 = 830.609; //a'' um Halbton niedriger
    float h2 = 932.328; //h'' um Halbton niedriger
    float c3 = 1046.50; //c'''

    while (1) {

        Beep(g2, takt * 2); //g'' 1. Zeile
        Beep(d2, takt * 1); //d''
        Beep(e2, takt * 1); //e''

        Beep(f2, takt * 2); //f''
        Beep(e2, takt * 1); //e''
        Beep(d2, takt * 1); //d''

        Beep(c2, takt * 2); //c''
        Beep(c2, takt * 1); //c''
        Beep(e2, takt * 1); //e''

        Beep(g2, takt * 2); //g''
        Beep(f2, takt * 1); //f''
        Beep(e2, takt * 1); //e''

        Beep(d2, takt * 3); //d'' (2 Toene)
        Beep(e2, takt * 1); //e''

        Beep(f2, takt * 2); //f''
        Beep(g2, takt * 2); //g''

        Beep(e2, takt * 2); //e''
        Beep(c2, takt * 2); //c''

        Beep(c2, takt * 2); //c''
        Sleep(takt * 2); //Pause

        Sleep(takt * 1); //Pause 2. Zeile
        Beep(f2, takt * 2); //f'' (2 Toene)
        Beep(a2, takt * 1); //a''

        Beep(c3, takt * 2); //c'''
        Beep(h2, takt * 1); //h''
        Beep(a2, takt * 1); //a''

        Beep(g2, takt * 3); //g'' (2 Toene)
        Beep(e2, takt * 1); //e''

        Beep(g2, takt * 2); //g''
        Beep(f2, takt * 1); //f''
        Beep(e2, takt * 1); //e''

        Beep(d2, takt * 2); //d''
        Beep(d2, takt * 1); //d''
        Beep(e2, takt * 1); //e''

        Beep(f2, takt * 2); //f''
        Beep(g2, takt * 2); //g''

        Beep(e2, takt * 2); //e''
        Beep(c2, takt * 2); //c''

        Beep(c2, takt * 2); //c''
        Sleep(takt * 2); //Pause

    }
}