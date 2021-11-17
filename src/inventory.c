#include <stdio.h>
#include <stdlib.h>
//
// Created by Alexandre on 04/11/2021.
//
//les items utilisable dans l'inventaire
//typedef struct item {
//    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
//    char* nom; // Epee, pioche , ...
//    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
//    int nombre; //dois être inferieur ou egual à 20 pour les ressources et = à 1 ou à 0 pour les outils
//    int durabilite; //uniquement pour les outils / armes
//} item;
//
//typedef struct itemInventaire itemInventaire;
//
//struct itemInventaire {
//    //int id;
//    item item;
//    itemInventaire* next;
//};
//
//
//typedef struct player {
//    /* localisation sur la map */
//    int y;
//    int x;
//
//    int map; // id de la map ou le joueur est present
//    itemInventaire* inventaire; //maximum 20 items
//
//} player;
//
//
///* il faut pas oublié de faire une copie de la première valeur pour pouvoir reparcourire la liste */
//
//void appendElement(itemInventaire* head, itemInventaire* last) {
////    printf("ajout de :");
//    while(head->next != NULL) {
//        //printf("%c", head->item.type);
//        head = head->next;
//    }
//    head->next = last;
//}
//itemInventaire makeItemInventaire(item item1) {
//    itemInventaire* inventaire = malloc(sizeof(itemInventaire));
//    inventaire->item = item1;
//    inventaire->next = NULL;
//    return *inventaire;
//}
//
//void deleteItem(itemInventaire* inventaire, int id) {
//    itemInventaire* itemInventaire1 = inventaire;
//    while (inventaire->next != NULL) {
//        if(id == inventaire->item.idItem) {
//            itemInventaire1->next = inventaire->next;
//            free(inventaire);
//        }
//        itemInventaire1 = inventaire;
//        inventaire = inventaire->next;
//    }
//}
//void updateItemInInventory(itemInventaire* inventaire, int id, item* item1) {
//    while (inventaire != NULL) {
//        if(id == inventaire->item.idItem) {
//            inventaire->item = *item1;
//        }
//
//        inventaire = inventaire->next;
//    }
//}
//void displayInventory(itemInventaire *inventory) {
//    printf("inventaire \n");
//    while (inventory->next != NULL) {
//        printf("type: %c \n", inventory->item.type);
//        printf("id: %d \n", inventory->item.idItem);
//        inventory = inventory->next;
//    }
//    printf("<<-------------->>");
//}
