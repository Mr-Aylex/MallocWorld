#include <stdio.h>
#include <stdlib.h>
//
// Created by Alexandre on 04/11/2021.
//

enum ObjectMap {
    PortailZ2To3 = -3, // -3 Portail vers la zone 3
    PortailZ1To2, // -2 Portail vers la zone 2
    CassInfran, //-1
    ZoneLibre,//0
    Joueur,//1
    PNJ,//2
    PlanteZ1,//3
    RocherZ1, //4
    BoisZ1,//   5
    PlanteZ2,//6
    RocherZ2,//7
    BoisZ2,//8
    PlanteZ3,//9
    RocherZ3,//10
    BoisZ3,//11
    Monstes,
    BossDeFin
};

enum ItemInventaire {
    EpeeEnBois = 1,//1
    Pioche,//2
    SerpeEnBois,//3
    HacheEnBois,//4
    Sapin,//    5
    Pierre,//    6
    Herpe,//    7
    EpeeEnPierre,// 8
    LanceEnPierre,// 9
    MarteauEnPierre,
    PlastronEnPierre,
    PiocheEnPierre,
    SerpeEnPierre,
    HacheEnPierre,
    PotionDeVie1,
    Hetre,
    Fer,
    Lavande,
    EpeeEnFer,
    LanceEnFer,
    MarteauEnFer,
    PlastronEnFer,
    PiocheEnFer,
    SerpeEnFer,
    HacheEnFer,
    PotionDeVie2,
    Chene,
    Diamant,
    Chanvre,
    EpeeEnDiamant,
    LanceEnDiamant,
    MarteauEnDiament,
    PlastronEnDiament,
    PotionDeVie3
};
