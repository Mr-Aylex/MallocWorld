#include <stdio.h>
#include <stdlib.h>
//
// Created by Alexandre on 04/11/2021.
//

//int** getMap() {
//    int* array = malloc(sizeof (int*) * 10);
//    for (int i = 0; i < 10; ++i) {
//        int* subArray = malloc(sizeof (int) * 10);
//        for (int j = 0; j < 10; ++j) {
//            subArray[j] = 0;
//        }
//        array[i] = subArray;
//    }
//    return array;
//}
//
//void displayMatrix(int **tab, int rows, int columns) {
//    for(int i = 0; i < rows; i++) {
//        for (int j = 0; j<columns;j++) {
//            printf("%d  ", tab[i][j]);
//        }
//        printf("\n");
//
//
//    }
//}
//void newTour(int** array, char dir, int* y, int* x) {
//    if(dir == 'z') {
//        if(*y-1 > -1) {
//            array[*y][*x] = 0;
//            array[*y - 1][*x] = 1;
//            *y -= 1;
//        }
//    }
//    else if(dir == 'q') {
//        if(*x-1 > -1) {
//            array[*y][*x] = 0;
//            array[*y][*x - 1] = 1;
//            *x -= 1;
//        }
//    }
//    else if(dir == 's') {
//        if(*y+1 < 10) {
//            array[*y][*x] = 0;
//            array[*y + 1][*x] = 1;
//            *y += 1;
//        }
//    }
//    else if(dir == 'd') {
//        if(*x+1 < 10) {
//            array[*y][*x] = 0;
//            array[*y][*x + 1] = 1;
//            *x += 1;
//        }
//    }
//}