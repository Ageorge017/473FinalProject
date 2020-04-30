/*
 * Project: Final Game
 * Purpose Details:
 * Course: CMPSC 473
 * Author: Albert George
 * Date Developed: 04/20/2020
 * Last Date Changed: 
 * Revision: 1
 * */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include<string.h>
#include"playerInfo.h"
#include"functions.h"
#define STRLEN 1024

int saveDataOption;

const char* locations[]={
    "Farm Bedroom",
    "Outside Farm",
    "Town",
    "Processus Procuratio",
    "Memoria Procuratio",
    "Procuratio Repono",
    "Wide River",
    "Lost Forest",
    "Boron Mountains"
};

int main(){

    HomeMenu();
    return 0;
    
}
void HomeMenu(){
    int menuOption;
    printf("Welcome to the Valley\n ");
    printf("\033[1;31m"); //red
    printf("Do you want to start a New Game or Load Game File?\n");  
    printf("\033[0;34m"); //blue
    printf("1. New Game\n");
    printf("2. Load Game\n");
    printf("\033[0m;");  //default
    while(1){
        scanf("%d", &menuOption);
        if (menuOption==1){
            printf("\033[1;31m"); //red
            printf("Which save data do you want to use?\n");
            printf("\033[0;34m"); //blue
            printf("1. Save Data 1\n");
            printf("2. Save Data 2\n");
            printf("3. Save Data 3\n");
            printf("\033[0m;");  //default
            while(1){
                scanf("%d", &saveDataOption);
                if(saveDataOption==1||saveDataOption==2||saveDataOption==3){
                    startNewGame(saveDataOption);
                    loadGame(saveDataOption);
                    break;
                }
                else{
                    printf("\033[1;31m"); //red
                    printf("\nI wasn't able to recognize your choice. Please type in the NUMBER corresponding to your choice.\n ");
                    printf("\033[0;34m"); //blue
                    printf("1. Save Data 1\n");
                    printf("2. Save Data 2\n");
                    printf("3. Save Data 3\n");
                    printf("\033[0m;");  //default
                }                
            }            
            break;
        }
        else if(menuOption==2){
            printf("\033[1;31m"); //red
            printf("Which save data do you want to load?\n");
            printf("\033[0;34m"); //blue
            printf("1. Save Data 1\n");
            printf("2. Save Data 2\n");
            printf("3. Save Data 3\n");
            printf("\033[0m;");  //default
            while(1){
                scanf("%d", &saveDataOption);
                if(saveDataOption==1||saveDataOption==2||saveDataOption==3){
                    loadGame(saveDataOption);
                    break;
                }
                else{
                    printf("\033[1;31m"); //red
                    printf("\nI wasn't able to recognize your choice. Please type in the NUMBER corresponding to your choice.\n ");
                    printf("\033[0;34m"); //blue
                    printf("1. Save Data 1\n");
                    printf("2. Save Data 2\n");
                    printf("3. Save Data 3\n");
                    printf("\033[0m;");  //default
                }                
            }
            break;
        }
        else{
            printf("\033[1;31m"); //red
            printf("\nI wasn't able to recognize your choice. Please type in the NUMBER corresponding to your choice.\n ");
            printf("\033[0;34m"); //blue
            printf("1. New Game\n");
            printf("2. Load Game\n");
            printf("\033[0m;");  //default
        }
    }

}
void startNewGame(int saveFileNum){
    printf("Creating new game profile.\n"); 
    
    challenges initChallenges = {false,false,false,false,false,false,false,false,false,false};
    inventory initInventory = {false,false,false,false,false};
    locationStory initStory = {false,false,false,false,false,false,false,false,false};
    saveData initState = {0, saveFileNum, &initChallenges,&initInventory, &initStory};


    printf("Creating save data. Using save file %d\n", saveFileNum);
    if(saveFileNum==1){
        printf("saving file to File %d", saveFileNum);
        FILE* fp = fopen("saveFiles/file_1","w");
        if(fp!=NULL){
            fwrite(&initChallenges, sizeof(challenges), 1, fp);
            fwrite(&initInventory, sizeof(inventory), 1, fp);
            fwrite(&initStory, sizeof(locationStory), 1, fp);
            fwrite(&initState, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    if(saveFileNum==2){
        printf("saving file to File %d", saveFileNum);
        FILE* fp = fopen("saveFiles/file_2","w");
        if(fp!=NULL){
            fwrite(&initChallenges, sizeof(challenges), 1, fp);
            fwrite(&initInventory, sizeof(inventory), 1, fp);
            fwrite(&initStory, sizeof(locationStory), 1, fp);
            fwrite(&initState, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    if(saveFileNum==3){
        printf("saving file to File %d", saveFileNum);
        FILE* fp = fopen("saveFiles/file_3","w");
        if(fp!=NULL){
            fwrite(&initChallenges, sizeof(challenges), 1, fp);
            fwrite(&initInventory, sizeof(inventory), 1, fp);
            fwrite(&initStory, sizeof(locationStory), 1, fp);
            fwrite(&initState, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
  
}

void loadGame(int saveFileNum){
    printf("Loading game file %d\n", saveFileNum);
    
    challenges* currChallenges = (challenges*)malloc(sizeof(challenges));
    inventory* currInventory = (inventory*)malloc(sizeof(inventory));
    locationStory* currStory = (locationStory*)malloc(sizeof(locationStory));
    saveData* currData =(saveData*)malloc(sizeof(saveData));

    if(saveFileNum==1){
        FILE* fp = fopen("saveFiles/file_1","r");
        if(fp!=NULL){
            fread(currChallenges, sizeof(challenges), 1, fp);
            fread(currInventory, sizeof(inventory), 1, fp);
            fread(currStory, sizeof(locationStory), 1, fp);
            fread(currData, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    if(saveFileNum==2){
        FILE* fp = fopen("saveFiles/file_2","r");
        if(fp!=NULL){
            fread(currChallenges, sizeof(challenges), 1, fp);
            fread(currInventory, sizeof(inventory), 1, fp);
            fread(currStory, sizeof(locationStory), 1, fp);
            fread(currData, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    if(saveFileNum==3){
        FILE* fp = fopen("saveFiles/file_3","r");
        if(fp!=NULL){
            fread(currChallenges, sizeof(challenges), 1, fp);
            fread(currInventory, sizeof(inventory), 1, fp);
            fread(currStory, sizeof(locationStory), 1, fp);
            fread(currData, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    currData->completedChallenges=currChallenges;
    currData->collectedInventory=currInventory;
    currData->storyTold=currStory;
    startGame(currData);
}
// "Farm Bedroom",
//     "Outside Farm",
//     "Town",
//     "Processus Procuratio",
//     "Memoria Procuratio",
//     "Procuratio Repono",
//     "Wide River",
//     "Lost Forest",
//     "Boron Mountains"
void startGame(saveData* playerData){
    int currLocation=playerData->playerLocation;
    while(1){
        playerData->playerLocation = currLocation;
        switch(currLocation){
            case(0):
                currLocation = bedroom(playerData);
                break;
            case(1):
                currLocation = farm(playerData);
                break;
            case(2):
                currLocation = town(playerData);
                break;
            case(3):
                currLocation = processusProcuratio(playerData);
                break;   
            case(4):
                currLocation = memoriaProcuratio(playerData);
                break;   
            case(5):
                currLocation = procuratioRepono(playerData);
                break;   
            case(6):
                currLocation = wideRiver(playerData);
                break;    
            case(7):
                currLocation = lostForest(playerData);
                break;    
            case(8):
                currLocation = boronMountains(playerData);
                break;    
            
            default:
                printf("Default Case Statement\n");

        }
    }
}
void saveGame(saveData* playerData){
    printf("saving file to File %d\n", playerData->saveNum);
    if(playerData->saveNum==1){
        FILE* fp = fopen("saveFiles/file_1","w");
        if(fp!=NULL){
            fwrite(playerData->completedChallenges, sizeof(challenges), 1, fp);
            fwrite(playerData->collectedInventory, sizeof(inventory), 1, fp);
            fwrite(playerData->storyTold, sizeof(locationStory), 1, fp);
            fwrite(playerData, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    if(playerData->saveNum==2){
        FILE* fp = fopen("saveFiles/file_2","w");
        if(fp!=NULL){
            fwrite(playerData->completedChallenges, sizeof(challenges), 1, fp);
            fwrite(playerData->collectedInventory, sizeof(inventory), 1, fp);
            fwrite(playerData->storyTold, sizeof(locationStory), 1, fp);
            fwrite(playerData, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
    if(playerData->saveNum==3){
        FILE* fp = fopen("saveFiles/file_3","w");
        if(fp!=NULL){
            fwrite(playerData->completedChallenges, sizeof(challenges), 1, fp);
            fwrite(playerData->collectedInventory, sizeof(inventory), 1, fp);
            fwrite(playerData->storyTold, sizeof(locationStory), 1, fp);
            fwrite(playerData, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
            
   
}
void printChoiceErr(){
    printf("\033[1;31m");//bold red
    printf("I'm sorry, I don't understand what you wanted. Please select from the choices given to you\n");
    printf("\033[0m"); //reset
}
