#include <stdio.h>
#include <stdlib.h>
#include "src/inventory.c"
#include "src/map.c"
#include "src/itemMap.c"
//les items utilisable dans l'inventaire

/* il faut pas oublié de faire une copie de la première valeur pour pouvoir reparcourire la liste */


//fonction qui ajoute un item dans la map à une posistion aléatoire
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
        *x = rand()%(10-1);
        *y = rand()%(10-1);
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
}//fonction qui fais passer un tour de jeu
void newTour(int** array, char dir, int* y, int* x) {
    if(dir == 'z') {
        if(*y-1 > -1) {
            if(array[*y][*x + 1] != 0) {
                int value = array[*y][*x + 1];
                if(value >= 3 && value <=11) {

                }
            }
            array[*y][*x] = 0;
            array[*y - 1][*x] = 1;
            *y -= 1;
        }
    }
    else if(dir == 'q') {
        if(*x-1 > -1) {
            if(array[*y][*x + 1] != 0) {
                int value = array[*y][*x + 1];
                if(value >= 3 && value <=11) {

                }
            }
            array[*y][*x] = 0;
            array[*y][*x - 1] = 1;
            *x -= 1;
        }
    }
    else if(dir == 's') {
        if(*y+1 < 10) {
            if(array[*y][*x + 1] != 0) {
                int value = array[*y][*x + 1];
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

    //enum ObjectMap d = Joueur;


    player* p = malloc(sizeof (player));
//    p->y ;
//    p->x = ;


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

        printf("\n Commande: ");
        int res = scanf("%c", &c);
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


