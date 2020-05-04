#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include<string.h>
#include"playerInfo.h"
#include"functions.h"
#define MAXCOM 1000 
#define MAXLIST 100 

void openMenu(saveData* playerData){
    int response;
    while(1){
        printf("--Main Menu--\n");
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. View Inventory \n");
        printf("2. Save Game\n");
        printf("3. Exit Menu\n");
        scanf("%d",&response);
        switch(response){
            case(1):
                viewInventory(playerData);
                break;
            case(2):
                saveGame(playerData);
                break;
            case(3):
                return;
            default:
                printChoiceErr();

        }
    }

}
void viewInventory(saveData* playerData){
    int response;
    FILE* fp;
    char s;
    while(1){
        printf("--Inventory--\n");
        printf("\033[1;31m");//bold red
        printf("What do you want to access?\n");
        printf("\033[0;34m"); //blue
        if(playerData->collectedInventory->Note_Terminal){
            printf("1. View Bedroom Note\n");            
        }
        if(playerData->collectedInventory->Postcard){
            printf("2. View Postcard\n");
        }
        if(playerData->collectedInventory->Barflyer){
            printf("3. View Bar Flyer\n");
        }
        printf("4. Exit\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                if(playerData->collectedInventory->Note_Terminal){
                    fp=fopen("messages/bedroom_message.txt","r");
                    while((s=fgetc(fp))!=EOF) {
                        printf("%c",s);            
                    }
                    fclose(fp);
                    printf("\n");
                }
                break;
            case(2):
                if(playerData->collectedInventory->Postcard){
                    fp=fopen("messages/postcard.txt","r");
                    while((s=fgetc(fp))!=EOF) {
                        printf("%c",s);            
                    }
                    fclose(fp);
                    printf("\n");
                }
                break;
            case(3):
                if(playerData->collectedInventory->Barflyer){
                    fp=fopen("messages/barflyer.txt","r");
                    while((s=fgetc(fp))!=EOF) {
                        printf("%c",s);            
                    }
                    fclose(fp);
                    printf("\n");
                }
                break;
            default:
                return;
        }
    } 
}


