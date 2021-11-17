#include <stdio.h>
#include <stdlib.h>
#include "src/inventory.c"
#include "src/map.c"
#include "src/itemMap.c"
//les items utilisable dans l'inventaire

/* il faut pas oublié de faire une copie de la première valeur pour pouvoir reparcourire la liste */


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
void newTour(int** array, char dir, int* y, int* x) {
    if(dir == 'z') {
        if(*y-1 > -1) {
            array[*y][*x] = 0;
            array[*y - 1][*x] = 1;
            *y -= 1;
        }
    }
    else if(dir == 'q') {
        if(*x-1 > -1) {
            array[*y][*x] = 0;
            array[*y][*x - 1] = 1;
            *x -= 1;
        }
    }
    else if(dir == 's') {
        if(*y+1 < 10) {
            array[*y][*x] = 0;
            array[*y + 1][*x] = 1;
            *y += 1;
        }
    }
    else if(dir == 'd') {
        if(*x+1 < 10) {
            array[*y][*x] = 0;
            array[*y][*x + 1] = 1;
            *x += 1;
        }
    }
}

typedef struct item {
    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
    char* nom; // Epee, pioche , ...
    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
    int nombre; //dois être inferieur ou egual à 20 pour les ressources et = à 1 ou à 0 pour les outils
    int durabilite; //uniquement pour les outils / armes
} item;

typedef struct itemInventaire itemInventaire;

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

    enum ItemMap d = Joueur;


    player* p = malloc(sizeof (player));
    p->y = 2;
    p->x = 3;


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
    array[p->y][p->x] = 1;
    displayMatrix(array, 10,10);
    char c = 'e';
    while (c != 'a') {

        printf("\n Commande: ");
        int res = scanf("%c", &c);
        if(res == 1) {
            if(c == 'e') {
                displayInventory(p->inventaire);
            }
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


