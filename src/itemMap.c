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
    Monstes = 12,//12
    BossDeFin = 99
};

enum ItemInventaire {
    EpeeEnBois = 1,//1
    Pioche,//2
    SerpeEnBois,//3
    HacheEnBois,//4
    Sapin,//5
    Pierre,// 6
    Herpe,// 7
    EpeeEnPierre,// 8
    LanceEnPierre,// 9
    MarteauEnPierre, // 10
    PlastronEnPierre,// 11
    PiocheEnPierre,// 12
    SerpeEnPierre,// 13
    HacheEnPierre,// 14
    PotionDeVie1,// 15
    Hetre,// 16
    Fer,//17
    Lavande, //18
    EpeeEnFer,//19
    LanceEnFer,//20
    MarteauEnFer,//21
    PlastronEnFer,//22
    PiocheEnFer,//23
    SerpeEnFer,//24
    HacheEnFer, //25
    PotionDeVie2, //26
    Chene, //27
    Diamant, //28
    Chanvre, //29
    EpeeEnDiamant, //30
    LanceEnDiamant, //31
    MarteauEnDiament, //32
    PlastronEnDiament, //33
    PotionDeVie3 //34
};
