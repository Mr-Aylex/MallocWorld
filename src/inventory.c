//#include <stdio.h>
//#include <stdlib.h>
//#include "header.h"
//#include <string.h>
////
//// Created by Alexandre on 04/11/2021.
////
////les items utilisable dans l'inventaire
////typedef struct item {
////    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
////    char* nom; // Epee, pioche , ...
////    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
////    int nombre; //doit être inferieur ou egale à 20 pour les ressources et = à 1 ou à 0 pour les outils
////    int durabilite; //uniquement pour les outils / armes
////
////    int typeOutils; //1 = epee, 2 = pioche, 3 = hache, 4 Serpe
////    int materiaux; //enum bois = 1, pierre = 2, fer = 3, diamant = 4  ...
////} item;
////
////// structure ressource (plante, pierre, ...)  pouvant être placée sur la carte
////
////
////
////typedef struct itemInventaire {
////    //int id;
////    item item;
////    struct itemInventaire* next;
////} itemInventaire;
////
////typedef struct player {
////    /* localisation sur la map */
////    int y;
////    int x;
////
////    int map; // id de la map ou le joueur est present
////    itemInventaire* inventaire; //maximum 20 items
////
////} player;
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
//    printf("nom : %s \n", head->next->item.nom);
//}
//itemInventaire makeItemInventaire(item* item1) {
//    itemInventaire* inventaire = malloc(sizeof(itemInventaire));
//    inventaire->item = *item1;
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
//void displayInventory(itemInventaire* inventory) {
//    printf("<<----------------------->>\n");
//    printf("inventaire \n");
//    while (inventory != NULL) {
//        printf("%s \n",inventory->item.nom);
//        if (inventory->item.type == 'r') {
//            printf("quantite : %d \n", inventory->item.nombre);
//        }
//        else if(inventory->item.type == 'o') {
//            printf("materiaux : %d \n",inventory->item.materiaux);
//            printf("durabilite : %d \n",inventory->item.durabilite);
//        }
//        printf("\n");
//        inventory = inventory->next;
//
//    }
//    printf("<<----------------------->>\n");
//}
//
//int checkIfPlayerCanCollect(itemInventaire* inventaire, ressourceInMap* ressource) {
//    itemInventaire* itemInventaire1 = inventaire;
//    ressourceInMap* ressource1 = ressource;
//    while (itemInventaire1 != NULL) {
//        printf("%s\n", itemInventaire1->item.nom);
//        if(itemInventaire1->item.typeOutils == ressource->ressource && itemInventaire1->item.materiaux >= ressource1->difficulte) {
//            return 1;
//        }
//        itemInventaire1 = itemInventaire1->next;
//    }
//    return 0;
//}
//
//
//item makeOutils(int id, char* nom, int type, int durabilite, int materiaux) {
//    item* out = malloc(sizeof(item));
//    strcpy(out->nom, nom);
//    out->idItem = id;
//    out->type = type;
//    out->durabilite = durabilite;
//    out->materiaux = materiaux;
//    return *out;
//}
