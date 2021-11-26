////
//// Created by Carmo on 26/11/2021.
////
//
//#include <stdio.h>
//#include <stdlib.h>
//#include "header.h"
//
//void newTour(int** array, char dir, int* y, int* x, itemInventaire* inventaire, ressourceInMap* arrayRessourceInMap, ressourceGetInMap* arrayRessource) {
//    printf(" \n direction : %c", dir);
//    if(dir == 'z') {
//        if(*y - 1 > -1) {
//            if(array[*y - 1][*x] != 0) {
//                int value = array[*y - 1][*x];
//
////                for (int i = 0; i<9; i++) {
////                    arrayRessourceInMap[i]
////                    if(value == arrayRessourceInMap[i])
////                        arrayRessourceInMap
////                }
//                ressourceInMap a = arrayRessourceInMap[1];
//
//                if(value >= 3 && value <=11) {
//                    if (checkIfPlayerCanCollect(inventaire, &a)) {
//                        array[*y - 1][*x] = 0;
//                        item* newItem = malloc(sizeof (item));
//                        newItem->nom = "pierre";
//                        newItem->idItem = 6;
//                        newItem->nombre = 1;
//                        newItem->type = 'r';
//                        itemInventaire *itemInventaire1 = malloc(sizeof (itemInventaire));
//                        *itemInventaire1 = makeItemInventaire(newItem);
//
//                        appendElement(inventaire, itemInventaire1);
//                    }
//                }
//            }
//            else {
//                array[*y][*x] = 0;
//                array[*y - 1][*x] = 1;
//                *y -= 1;
//            }
//
//        }
//    }
//    else if(dir == 'q') {
//        if(*x - 1 > -1) {
//            if(array[*y][*x - 1] != 0) {
//                int value = array[*y][*x - 1];
//                if(value >= 3 && value <=11) {
//
//                }
//            }
//            array[*y][*x] = 0;
//            array[*y][*x - 1] = 1;
//            *x -= 1;
//        }
//    }
//    else if(dir == 's') {
//        if(*y + 1 < 10) {
//            if(array[*y + 1][*x] != 0) {
//                int value = array[*y + 1][*x];
//                if(value >= 3 && value <=11) {
//
//                }
//            }
//            array[*y][*x] = 0;
//            array[*y + 1][*x] = 1;
//            *y += 1;
//        }
//    }
//    else if(dir == 'd') {
//        if(*x+1 < 10) {
//            if(array[*y][*x + 1] != 0) {
//                int value = array[*y][*x + 1];
//                if(value >= 3 && value <=11) {
//
//                }
//            }
//            array[*y][*x] = 0;
//            array[*y][*x + 1] = 1;
//
//            *x += 1;
//        }
//    }
//}