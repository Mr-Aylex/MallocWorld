//typedef struct ressourceInMap ressourceInMap;
//
//typedef struct itemInventaire itemInventaire;
//
//typedef struct item item;
//
//typedef struct ressourceGetInMap ressourceGetInMap;
//
//typedef struct player player;
//
//struct item {
//    int idItem; //la valeur de l'objet Eppée en bois = 1 | pioche en bois = 2 ...
//    char* nom; // Epee, pioche , ...
//    char type; //il faut choisir arbitrairement une valeur pour chaque type a = Arme , o = Outil, r = Ressource, s = Soin
//    int nombre; //doit être inferieur ou egale à 20 pour les ressources et = à 1 ou à 0 pour les outils
//    int durabilite; //uniquement pour les outils / armes
//
//    int typeOutils; //1 = epee, 2 = pioche, 3 = hache, 4 Serpe
//    int materiaux; //enum bois = 1, pierre = 2, fer = 3, diamant = 4  ...
//} ;
//
//// structure ressource (plante, pierre, ...)  pouvant être placée sur la carte
//
//
//struct itemInventaire {
//    //int id;
//    item item;
//    struct itemInventaire* next;
//};
//
//struct ressourceInMap {
//    char* nom;
//    int id;
//    int ressource;
//    int difficulte;
//} ;
//
//struct ressourceGetInMap {
//    int idRessource;
//    char* nom;
//} ;
//
//struct player {
//    /* localisation sur la map */
//    int y;
//    int x;
//
//    int map; // id de la map ou le joueur est present
//    itemInventaire* inventaire; //maximum 20 items
//
//} ;
//
//
//
//int** getMap(void);
//ressourceInMap makeObectMap(int id, char* nom, int ressource, int difficulte);
//ressourceGetInMap makeRessourceGetInMap(int id, char* nom);
//
//
//itemInventaire makeItemInventaire(item* item1);
//void putObjectToMap(int object, int** map);
//void addPlayerOnTheMap(int** map, int* x, int* y);
//void displayMatrix(int **tab, int rows, int columns);
//void displayMapNearPlayer(int** map, int x, int y);
//void displayInventory(itemInventaire *inventory);
//void appendElement(itemInventaire* head, itemInventaire* last);
//void newTour(int** array, char dir, int* y, int* x, itemInventaire* inventaire,ressourceInMap* arrayRessourceInMap, ressourceGetInMap* arrayRessource);
//int checkIfPlayerCanCollect(itemInventaire* inventaire, ressourceInMap* ressource);
//ressourceInMap getRessourceInMap(int value, ressourceInMap* arrayRessourceInMap);
//item makeOutils(enum ItemInventaire id, char* nom, int type, int durabilite, int materiaux);

