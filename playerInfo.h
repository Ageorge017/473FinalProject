#ifndef PLAYERINFO_H
#define PLAYERINFO_H 
typedef struct SaveData{
    int playerLocation;
    int saveNum;
    struct Challenges* completedChallenges;
    struct Inventory* collectedInventory;
    struct LocationStory* storyTold;
} saveData;

typedef struct Challenges{
    bool lockedDoor;
    bool lostforest;
    bool boronmountains;
    bool processus_puzzle;
    bool river_puzzle;
    bool fountain_puzzle;
    bool memoria_puzzle;
    bool repono_puzzle;
    bool challenge9;
    bool challenge10;
}challenges;

typedef struct Inventory{
    bool Note_Terminal;
    bool Postcard;
    bool Barflyer;
    bool Fountainkey;
    bool item5;
}inventory;

typedef struct LocationStory{
    bool farmBedroom;
    bool outsideFarm;
    bool town;
    bool processus;
    bool memoria;
    bool repono;
    bool river;
    bool forest;
    bool mountains;
}locationStory;
#endif 