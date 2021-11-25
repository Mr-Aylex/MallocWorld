typedef struct ressourceInMap ressourceInMap;

typedef struct itemInventaire itemInventaire;

typedef struct item item;

typedef struct ressourceGetInMap ressourceGetInMap;

int** getMap(void);
ressourceInMap makeObectMap(enum ObjectMap id, char* nom, int ressource, int difficulte);
ressourceGetInMap makeRessourceGetInMap(int id, char* nom);


itemInventaire makeItemInventaire(item item1);
void putObjectToMap(int object, int** map);
void addPlayerOnTheMap(int** map, int* x, int* y);
void displayMatrix(int **tab, int rows, int columns);
void displayMapNearPlayer(int** map, int x, int y);
void displayInventory(itemInventaire *inventory);
void appendElement(itemInventaire* head, itemInventaire* last);
newTour(int** array, char dir, int* y, int* x, itemInventaire* inventaire,ressourceInMap* arrayRessourceInMap, ressourceGetInMap* arrayRessource);
int checkIfPlayerCanCollect(itemInventaire* inventaire, ressourceInMap ressource);
ressourceInMap getRessourceInMap(int value, ressourceInMap* arrayRessourceInMap);
item makeOutils(enum ItemInventaire id, char* nom, int type, int durabilite, int materiaux);


