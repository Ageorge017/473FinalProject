#ifndef FUNCTIONS_H
#define FUNCTIONS_H 
#include"playerInfo.h"
void HomeMenu();
void MainMenu();
void printChoiceErr();
void startNewGame(int saveFileNum);
void loadGame(int saveFileNum);
void startGame(saveData* playerData);
void openMenu(saveData* playerData);
void viewInventory(saveData* playerData);
void saveGame(saveData* playerData);
void openTerminal();
int bedroom(saveData* playerData);
int farm(saveData* playerData);
int town(saveData* playerData);
int processusProcuratio(saveData* playerData);
int memoriaProcuratio(saveData* playerData);
int procuratioRepono(saveData* playerData);
int wideRiver(saveData* playerData);
int lostForest(saveData* playerData);
int boronMountains(saveData* playerData);
#endif 