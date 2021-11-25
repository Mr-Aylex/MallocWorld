#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/header.h"
#include "src/itemMap.c"


// structure d'un item de l'inventaire
typedef struct item {
    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
    char* nom; // Epee, pioche , ...
    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
    int nombre; //doit être inferieur ou egale à 20 pour les ressources et = à 1 ou à 0 pour les outils
    int durabilite; //uniquement pour les outils / armes

    int typeOutils; //1 = epee, 2 = pioche, 3 = hache, 4 Serpe
    int materiaux; //enum bois = 1, pierre = 2, fer = 3, diamant = 4  ...
} item;

// structure ressource (plante, pierre, ...)  pouvant être placée sur la carte


typedef struct itemInventaire {
    //int id;
    item item;
    struct itemInventaire* next;
} itemInventaire;

typedef struct ressourceInMap {
    char* nom;
    int id;
    int ressource;
    int difficulte;
} ressourceInMap;

typedef struct ressourceGetInMap {
    int idRessource;
    char* nom;
} ressourceGetInMap;

//int checkIfPlayerCanCollect(itemInventaire* inventaire, ressourceInMap ressource) {
//    itemInventaire* itemInventaire1 = inventaire;
//    while (itemInventaire1->next != NULL) {
//        printf("%s\n", itemInventaire1->item.nom);
//        if(itemInventaire1->item.typeOutils == ressource.ressource && itemInventaire1->item.materiaux >= ressource.difficulte) {
//            return 1;
//        }
//        itemInventaire1 = itemInventaire1->next;
//    }
//    return 0;
//}


typedef struct player {
    /* localisation sur la map */
    int y;
    int x;

    int map; // id de la map ou le joueur est present
    itemInventaire* inventaire; //maximum 20 items

} player;


// fonction qui permet de créer une ressource
//ressourceInMap makeObectMap(enum ObjectMap id, char* nom, int ressource, int difficulte) {
//    ressourceInMap obj;
//    obj.id = id;
//    obj.ressource = ressource;
//    obj.difficulte = difficulte;
//    return obj;
//}
// fonction qui permet de créer un outil
//item makeOutils(enum ItemInventaire id, char* nom, int type, int durabilite, int materiaux) {
//    item* out = malloc(sizeof(item));
//    strcpy(out->nom, nom);
//    out->idItem = id;
//    out->type = type;
//    out->durabilite = durabilite;
//    out->materiaux = materiaux;
//    return *out;
//}


//fonction qui ajoute un item dans la map à une position aléatoire
//void putObjectToMap(int object, int** map){
//    int x,y;
//    do {
//        x = rand()%(9);
//        y = rand()%(9);
//    } while(map[x][y] != 0);
//    map[x][y] = object;

//}
//void addPlayerOnTheMap(int** map, int* x, int* y){
//    do {
//        *x = rand()%(9);
//        *y = rand()%(9);
//    } while(map[*x][*y] != 0);
//    map[*x][*y] = 1;
//}

//fonction qui permet de créer une map

int** getMap() {
    int** array = malloc(sizeof (int*) * 10);
    for (int i = 0; i < 10; ++i) {
        int* subArray = malloc(sizeof (int) * 10);
        for (int j = 0; j < 10; ++j) {
            subArray[j] = 0;
        }
        array[i] = subArray;
    }
    return array;
}

void deleteItem(itemInventaire* inventaire, int id) {
    itemInventaire* itemInventaire1 = inventaire;
    while (inventaire->next != NULL) {
        if(id == inventaire->item.idItem) {
            itemInventaire1->next = inventaire->next;
            free(inventaire);
        }
        itemInventaire1 = inventaire;
        inventaire = inventaire->next;
    }
}
void updateItemInInventory(itemInventaire* inventaire, int id, item* item1) {
    while (inventaire != NULL) {
        if(id == inventaire->item.idItem) {
            inventaire->item = *item1;
        }

        inventaire = inventaire->next;
    }
}



int main() {

    ressourceInMap* tabRessource = malloc(sizeof(ressourceInMap) * 9);
    tabRessource[0] = makeObectMap(3, "PlanteZ1", 7, 1);
    tabRessource[1] = makeObectMap(4, "RocherZ1", 6, 1);
    tabRessource[2] = makeObectMap(5, "BoisZ1", 5, 1);
    tabRessource[3] = makeObectMap(6, "PlanteZ2", 18, 2);
    tabRessource[4] = makeObectMap(7, "RocherZ2", 17, 2);
    tabRessource[5] = makeObectMap(8, "BoisZ2", 16, 2);
    tabRessource[6] = makeObectMap(9, "PlanteZ3", 29, 3);
    tabRessource[7] = makeObectMap(10, "RocherZ3", 28, 3);
    tabRessource[8] = makeObectMap(11, "BoisZ3", 27, 3);

    ressourceGetInMap* tabRessourceGetInMap = malloc(sizeof(ressourceGetInMap) * 9);
    tabRessourceGetInMap[0] = makeRessourceGetInMap(7,"herbe");
    tabRessourceGetInMap[1] = makeRessourceGetInMap(6,"pierre");
    tabRessourceGetInMap[2] = makeRessourceGetInMap(5,"sapin");
    tabRessourceGetInMap[3] = makeRessourceGetInMap(18,"lavande");
    tabRessourceGetInMap[4] = makeRessourceGetInMap(17,"fer");
    tabRessourceGetInMap[5] = makeRessourceGetInMap(16,"hetre");
    tabRessourceGetInMap[6] = makeRessourceGetInMap(29,"chanvre");
    tabRessourceGetInMap[7] = makeRessourceGetInMap(28,"diament");
    tabRessourceGetInMap[8] = makeRessourceGetInMap(27,"chene");


    enum ObjectMap obm = BoisZ1;
    ressourceInMap Sapin = makeObectMap(obm, "Sapin", 5, 1);

    player* p = malloc(sizeof (player));

    /*
     * Start Test Creation item & deleteItem & updateItem
     */
    item* testItem = malloc(sizeof (item));
    testItem->idItem = 2;
    testItem->nom = "Pioche en Bois";
    testItem->typeOutils = 2;
    testItem->durabilite = 5;
    testItem->nombre = 1;
    testItem->type = 'o';
    testItem->materiaux = 1;
    itemInventaire inventaire = makeItemInventaire(testItem);

    //printf("%c",inventaire2->item.type);
    //newItem(); //--> à tester après appendElement();
    p->inventaire = &inventaire;

//    appendElement(p->inventaire,&inventaire);//--> Tester chaque pointeurs dans la fonction appendElement();


    /*
     *  End Test Creation Item .....
     */

    int** array = getMap();

    putObjectToMap(4, array);
    addPlayerOnTheMap(array, &(p->y), &(p->x));

    displayMatrix(array, 10,10);
    char c = 'e';
    while (c != 'a') {
        displayMapNearPlayer(array, p->x, p->y);
        printf("\n Commande: ");
        int res = scanf("%c", &c);
        printf("\n direction1 : %c", c);
        if(res == 1) {
            if(c == 'e') {
                displayInventory(p->inventaire);
            }
            printf("location: y: %d x: %d", (p->y), (p->x));
            itemInventaire *inventaireCopy = p->inventaire;// étape nécessaire, il faut faire une copie du pointeur pour que lors de l'affichage,
            newTour(array, c, &(p->y), &(p->x), inventaireCopy, tabRessource, tabRessourceGetInMap);
            printf("----------------------------------\n");
            displayMatrix(array, 10, 10);
            if(c == 'e') {
                // le pointeur initial reste à la première valeur.
                displayInventory(inventaireCopy);
            }
        }
        //system("cls");
    }
    return 0;
}


