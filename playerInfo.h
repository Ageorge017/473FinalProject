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
    bool challenge2;
    bool challenge3;
    bool challenge4;
    bool challenge5;
    bool challenge6;
    bool challenge7;
    bool challenge8;
    bool challenge9;
    bool challenge10;
}challenges;

typedef struct Inventory{
    bool Note_Terminal;
    bool item2;
    bool item3;
    bool item4;
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