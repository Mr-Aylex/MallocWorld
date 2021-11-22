#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/inventory.c"
#include "src/map.c"
#include "src/itemMap.c"



// structure d'un item de l'inventaire
typedef struct item {
    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
    char nom[20]; // Epee, pioche , ...
    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
    int nombre; //doit être inferieur ou egale à 20 pour les ressources et = à 1 ou à 0 pour les outils
    int durabilite; //uniquement pour les outils / armes

    int typeOutils; //1 = epee, 2 = pioche, 3 = hache, 4 Serpe
    int materiaux; //enum bois = 1, pierre = 2, fer = 3, diamant = 4  ...
} item;

// structure ressource (plante, pierre, ...)  pouvant être placée sur la carte
typedef struct ressourceInMap {
    char nom[20];
    int id;
    int ressource;
    int difficulte;
} ressourceInMap;

// fonction qui permet de créer une ressource
ressourceInMap makeObectMap(enum ObjectMap id, char nom[20], int ressource, int difficulte) {
    ressourceInMap obj;
    obj.id = id;
    obj.ressource = ressource;
    obj.difficulte = difficulte;
    return obj;
}
// fonction qui permet de créer un outil
item makeOutils(enum ItemInventaire id, char nom[20], int type, int durabilite, int materiaux) {
    item out;
    strcpy(out.nom, nom);
    out.idItem = id;
    out.type = type;
    out.durabilite = durabilite;
    out.materiaux = materiaux;
    return out;
}


//fonction qui ajoute un item dans la map à une position aléatoire
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

void displayMatrix(int **tab, int rows, int columns) {
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j<columns;j++) {
            printf("%d  ", tab[i][j]);
        }
        printf("\n");


    }
}



//this function is used to display element near the player
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

typedef struct itemInventaire itemInventaire;
//Fonction à terminer---------------------------------------------------------------------------------------------------------------------
int checkIfPlayerCanCollect(itemInventaire* inventaire, int ressource) {

}

//fonction qui fait passer un tour de jeu
void newTour(int** array, char dir, int* y, int* x) {
    printf(" \n direction : %c", dir);
    if(dir == 'z') {
        if(*y - 1 > -1) {
            if(array[*y - 1][*x] != 0) {
                int value = array[*y - 1][*x];
                if(value >= 3 && value <=11) {

                }
            }
            array[*y][*x] = 0;
            array[*y - 1][*x] = 1;
            *y -= 1;
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




struct itemInventaire {
    //int id;
    item item;
    itemInventaire* next;
};


typedef struct player {
    /* localisation sur la map */
    int y;
    int x;

    int map; // id de la map ou le joueur est present
    itemInventaire* inventaire; //maximum 20 items

} player;


/* il faut pas oublié de faire une copie de la première valeur pour pouvoir reparcourire la liste */

void appendElement(itemInventaire* head, itemInventaire* last) {
//    printf("ajout de :");
    while(head->next != NULL) {
        //printf("%c", head->item.type);
        head = head->next;
    }
    head->next = last;
}
itemInventaire makeItemInventaire(item item1) {
    itemInventaire* inventaire = malloc(sizeof(itemInventaire));
    inventaire->item = item1;
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
void displayInventory(itemInventaire *inventory) {
    printf("inventaire \n");
    while (inventory->next != NULL) {
        printf("type: %c \n", inventory->item.type);
        printf("id: %d \n", inventory->item.idItem);
        inventory = inventory->next;
    }
    printf("<<-------------->>");
}


int main() {
    enum ObjectMap BoisZ1 = BoisZ1;
    ressourceInMap Sapin = makeObectMap(BoisZ1, "Sapin", 5, 1);

    player* p = malloc(sizeof (player));

    /*
     * Start Test Creation item & deleteItem & updateItem
     */
    item* testItem = malloc(sizeof (item));
    testItem->idItem = 3;
    testItem->nom = "Pioche";
    testItem->durabilite = 5;
    testItem->nombre = 0;
    testItem->type = 'o';
    itemInventaire inventaire2 = makeItemInventaire(*testItem);

    itemInventaire inventaire = makeItemInventaire(*testItem);

    //printf("%c",inventaire2->item.type);
    //newItem(); //--> à tester après appendElement();
    p->inventaire = &inventaire;

    appendElement(p->inventaire,&inventaire2);//--> Tester chaque pointeurs dans la fonction appendElement();


    /*
     *  End Test Creation Item .....
     */

    int** array = getMap();

    putObjectToMap(3, array);
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
            newTour(array, c, &(p->y), &(p->x));
            printf("----------------------------------\n");
            displayMatrix(array, 10, 10);
            if(c == 'e') {
                itemInventaire *inventaireCopy = p->inventaire;// étape nécessaire, il faut faire une copie du pointeur pour que lors de l'affichage,
                // le pointeur initial reste à la première valeur.
                displayInventory(inventaireCopy);
            }
        }
        //system("cls");
    }
    return 0;
}


