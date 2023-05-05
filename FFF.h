//
// Created by Вадим Герасимович on 4/21/23.
//

#ifndef S2LABA6_FFF_H
#define S2LABA6_FFF_H

#endif //S2LABA6_FFF_H
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct FIFO {
    char data;
    struct FIFO* next;
} queue;
struct Deck {
    char data;
    struct Deck *next;
    struct Deck *prev;
};
int input(int min, int max);
int task1();
int task2();