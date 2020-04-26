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
#define STRLEN 30

void HomeMenu();
void MainMenu();

void startNewGame(int saveFileNum);
void loadGame(int saveFileNum);

int saveDataOption;

typedef struct SaveData{
    int playerLocation;
    struct Challenges* completedChallenges;
    struct Inventory* collectedInventory;
} saveData;

typedef struct Challenges{
    bool challenge1;
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
    bool item1;
    bool item2;
    bool item3;
    bool item4;
    bool item5;
}inventory;

const char* loccations[]={
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
    printf("Welcome to the Valley\n Do you want to start a New Game or Load Game File?\n");
    printf("1. New Game\n");
    printf("2. Load Game\n");
    while(1){
        scanf("%d", &menuOption);
        if (menuOption==1){
            printf("Which save data do you want to use?\n");
            printf("1. Save Data 1\n");
            printf("2. Save Data 2\n");
            printf("3. Save Data 3\n");
            while(1){
                scanf("%d", &saveDataOption);
                if(saveDataOption==1||saveDataOption==2||saveDataOption==3){
                    startNewGame(saveDataOption);
                    break;
                }
                else{
                    printf("\nI wasn't able to recognize your choice. Please type in the NUMBER corresponding to your choice.\n ");
                    printf("1. Save Data 1\n");
                    printf("2. Save Data 2\n");
                    printf("3. Save Data 3\n");
                }                
            }            
            break;
        }
        else if(menuOption==2){
            printf("Which save data do you want to load?\n");
            printf("1. Save Data 1\n");
            printf("2. Save Data 2\n");
            printf("3. Save Data 3\n");
            while(1){
                scanf("%d", &saveDataOption);
                if(saveDataOption==1||saveDataOption==2||saveDataOption==3){
                    loadGame(saveDataOption);
                    break;
                }
                else{
                    printf("\nI wasn't able to recognize your choice. Please type in the NUMBER corresponding to your choice.\n ");
                    printf("1. Save Data 1\n");
                    printf("2. Save Data 2\n");
                    printf("3. Save Data 3\n");
                }                
            }
            break;
        }
        else{
            printf("\nI wasn't able to recognize your choice. Please type in the NUMBER corresponding to your choice.\n ");
            printf("1. New Game\n");
            printf("2. Load Game\n");
        }
    }

}
void startNewGame(int saveFileNum){
    printf("Creating new game profile.\n"); 
    
    challenges initChallenges = {false,false,false,false,false,false,false,false,false,false};
    inventory initInventory = {false,false,false,false,false};
    saveData initState = {0, &initChallenges,&initInventory};


    printf("Creating save data. Using save file %d\n", saveFileNum);
    if(saveFileNum==1){
        printf("saving file to File %d", saveFileNum);
        FILE* fp = fopen("saveFiles/file_1","w");
        if(fp!=NULL){
            fwrite(&initChallenges, sizeof(challenges), 1, fp);
            fwrite(&initInventory, sizeof(inventory), 1, fp);
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
            fwrite(&initState, sizeof(saveData), 1, fp);
        }
        fclose(fp);
    }
  
}

void loadGame(int saveFileNum){
    printf("In load Game\n Using load file %d\n", saveFileNum);
  
}
