#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "src/header.h"
#include "src/itemMap.c"

typedef struct ressourceInMap ressourceInMap;

typedef struct itemInventaire itemInventaire;

typedef struct item item;

typedef struct ressourceGetInMap ressourceGetInMap;

typedef struct player player;

struct item {
    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
    char* nom; // Epee, pioche , ...
    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
    int nombre; //doit être inferieur ou egale à 20 pour les ressources et = à 1 ou à 0 pour les outils
    int durabilite; //uniquement pour les outils / armes

    int typeOutils; //1 = epee, 2 = pioche, 3 = hache, 4 Serpe
    int materiaux; //enum bois = 1, pierre = 2, fer = 3, diamant = 4  ...
} ;

// structure ressource (plante, pierre, ...)  pouvant être placée sur la carte


struct itemInventaire {
    //int id;
    item item;
    struct itemInventaire* next;
};

struct ressourceInMap {
    char* nom;
    int id;
    int ressource;
    int difficulte;
} ;

struct ressourceGetInMap {
    int idOutil;
    int idRessource;
    char* nom;
} ;

struct player {
    /* localisation sur la map */
    int y;
    int x;

    int map; // id de la map ou le joueur est present
    itemInventaire* inventaire; //maximum 20 items

} ;

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

void appendElement(itemInventaire* head, itemInventaire* last) {
//    printf("ajout de :");
    while(head->next != NULL) {
        //printf("%c", head->item.type);
        head = head->next;
    }
    head->next = last;
    printf("nom : %s \n", head->next->item.nom);
}
itemInventaire makeItemInventaire(item* item1) {
    itemInventaire* inventaire = malloc(sizeof(itemInventaire));
    inventaire->item = *item1;
    inventaire->next = NULL;
    return *inventaire;
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
void displayInventory(itemInventaire* inventory) {
    printf("<<----------------------->>\n");
    printf("inventaire \n");
    while (inventory != NULL) {
        printf("%s \n",inventory->item.nom);
        if (inventory->item.type == 'r') {
            printf("quantite : %d \n", inventory->item.nombre);
        }
        else if(inventory->item.type == 'o') {
            printf("materiaux : %d \n",inventory->item.materiaux);
            printf("durabilite : %d \n",inventory->item.durabilite);
        }
        printf("\n");
        inventory = inventory->next;

    }
    printf("<<----------------------->>\n");
}

int checkIfPlayerCanCollect(itemInventaire* inventaire, ressourceInMap* ressource) {
    itemInventaire* itemInventaire1 = inventaire;
//    printf("nom ressource: %s, id : %d, difficulte : %d \n", ressource->ressource, ressource->id, ressource->difficulte);
    while (itemInventaire1 != NULL) {
        printf(" type outile : %d , %d \n", itemInventaire1->item.typeOutils,ressource->ressource );
        if(itemInventaire1->item.typeOutils == 2 && itemInventaire1->item.materiaux >= ressource->difficulte) {
            return 1;
        }
        itemInventaire1 = itemInventaire1->next;
    }
    return 0;
}


item makeOutils(int id, char* nom, int type, int durabilite, int materiaux) {
    item* out = malloc(sizeof(item));
    strcpy(out->nom, nom);
    out->idItem = id;
    out->type = type;
    out->durabilite = durabilite;
    out->materiaux = materiaux;
    return *out;
}

void newTour(int** array, char dir, int* y, int* x, itemInventaire* inventaire, ressourceInMap* arrayRessourceInMap, ressourceGetInMap* arrayRessource) {
    printf(" \n direction : %c \n", dir);
    if(dir == 'z') {
        if(*y - 1 > -1) {
            if(array[*y - 1][*x] != 0) {
                int value = array[*y - 1][*x];
                ressourceInMap* ressource = malloc(sizeof(ressourceInMap));
                for (int i = 0; i<9; i++) {
                    if(value == arrayRessourceInMap[i].id) {
                        ressource = &(arrayRessourceInMap[i]);
                        break;
                    }
                }


                if(value >= 3 && value <=11) {
                    if (checkIfPlayerCanCollect(inventaire, ressource)) {
                        printf("ressource disponible: %d\n", ressource->id);
                        array[*y - 1][*x] = 0;
                        item* newItem = malloc(sizeof (item));
                        newItem->nom = "pierre";
                        newItem->idItem = 6;
                        newItem->nombre = 1;
                        newItem->type = 'r';
                        itemInventaire *itemInventaire1 = malloc(sizeof (itemInventaire));
                        *itemInventaire1 = makeItemInventaire(newItem);

                        appendElement(inventaire, itemInventaire1);
                    }
                }
            }
            else {
                array[*y][*x] = 0;
                array[*y - 1][*x] = 1;
                *y -= 1;
            }

        }
    }
    else if(dir == 'q') {
        if(*x - 1 > -1) {
            if(array[*y][*x - 1] != 0) {
                int value = array[*y][*x - 1];
                if(value >= 3 && value <=11) {

                }
            }
            array[*y][*x] = 0;
            array[*y][*x - 1] = 1;
            *x -= 1;
        }
    }
    else if(dir == 's') {
        if(*y + 1 < 10) {
            if(array[*y + 1][*x] != 0) {
                int value = array[*y + 1][*x];
                if(value >= 3 && value <=11) {

                }
            }
            array[*y][*x] = 0;
            array[*y + 1][*x] = 1;
            *y += 1;
        }
    }
    else if(dir == 'd') {
        if(*x+1 < 10) {
            if(array[*y][*x + 1] != 0) {
                int value = array[*y][*x + 1];
                if(value >= 3 && value <=11) {

                }
            }
            array[*y][*x] = 0;
            array[*y][*x + 1] = 1;

            *x += 1;
        }
    }
}
ressourceGetInMap makeRessourceGetInMap(int id, char* nom) {
    ressourceGetInMap* ressourceGetInMap1 = malloc(sizeof(ressourceGetInMap));
    ressourceGetInMap1->idRessource = id;
    ressourceGetInMap1->nom = nom;
    return *ressourceGetInMap1;
}
ressourceInMap makeObectMap(int id, char nom[20], int ressource, int difficulte) {
    ressourceInMap* ressourceInMap1 = malloc(sizeof(ressourceInMap));
    ressourceInMap1->id = id;
    ressourceInMap1->nom = nom;
    ressourceInMap1->ressource = ressource;
    ressourceInMap1->difficulte = difficulte;
    return *ressourceInMap1;
}
// structure d'un item de l'inventaire



void putObjectToMap(int object, int** map){
    int x,y;
    do {
        x = rand()%(9);
        y = rand()%(9);
    } while(map[x][y] != 0);
    map[x][y] = object;

}

void addPlayerOnTheMap(int** map, int* x, int* y){
    do {
        *x = rand()%(9);
        *y = rand()%(9);
    } while(map[*x][*y] != 0);
    map[*x][*y] = 1;
}

void displayMatrix(int **tab, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j<columns;j++) {
            printf("%d  ", tab[i][j]);
        }
        printf("\n");


    }
}


void displayMapNearPlayer(int** map, int x, int y){
    if(y - 1 > -1) {
        int ZObject = map[y -1][x];
        enum ObjectMap itZ = ZObject;
        if (itZ >= -3 && itZ <= 99) {
            printf("En Z se trouve : %d \n", itZ);
        }
    }
    else {
        printf("En Z le joueur est au bord \n");
    }

    if(x - 1 > -1) {
        int QObject = map[y][x - 1];
        enum ObjectMap itQ = QObject;
        if (itQ >= -3 && itQ <= 99){
            printf("En Q se trouve : %d \n", itQ);
        }
    }
    else{
        printf("En Q le joueur est au bord \n");
    }

    if(y + 1 < 10) {
        int SObject = map[y + 1][x];
        enum ObjectMap itS = SObject;
        if (itS >= -3 && itS <= 99){
            printf("En S se trouve : %d \n", itS);
        }
    }
    else{
        printf("En S le joueur est au bord \n");
    }


    if(x+1 < 10) {
        int DObject = map[y][x + 1];
        enum ObjectMap itD = DObject;
        if (itD >= -3 && itD <= 99){
            printf("En D se trouve : %d \n", itD);
        }
    }
    else{
        printf("En D le joueur est au bord \n");
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


