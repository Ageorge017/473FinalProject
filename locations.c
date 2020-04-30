#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include<string.h>
#include"playerInfo.h"
#include"functions.h"
#define STRLEN 1024

int bedroom(saveData* playerData){
    int response,inputPasword;
    FILE* fp;
    char s;
    int password = 57694;
    bool doorChallenge = playerData->completedChallenges->lockedDoor;
    bool note_terminal = playerData->collectedInventory->Note_Terminal;
    printf("\033[0;36m"); //cyan
    printf("You are in your bedroom on the farm.\n");
    if(!playerData->storyTold->farmBedroom){
        printf("You wake up from a long night's sleep. You sit up in your bed.\n");
        playerData->storyTold->farmBedroom=true;
    }
    printf("To your right, is your nightstand with a drawer. To your left is a bookshelf. Behind you is a window, and in front of you is the door.\n");
    printf("\033[1;31m");//bold red
    printf("What do you want to do?\n");
    while(1){
        printf("\033[0;34m"); //blue
        printf("1. Open Door \n");
        printf("2. Open Nightstand Drawer\n");
        printf("3. Examine Bookshelf\n");
        printf("4. Look Outside Window\n");
        printf("5. Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                
                if(!doorChallenge){
                    printf("\033[0;36m"); //cyan
                    printf("The door is locked with a 5-digit key.\n");
                    printf("\033[1;31m");//bold red
                    printf("Enter Key\n");
                    printf("\033[0m"); //reset
                    scanf("%d", &inputPasword);
                    if(inputPasword==password){
                        printf("\033[0;36m"); //cyan
                        printf("The door unlocked!\n");
                        printf("\033[0m"); //reset
                        playerData->completedChallenges->lockedDoor=true;
                        printf("Autosaving progress\n");
                        //saveGame();
                    }
                    else{
                        printf("\033[0;36m"); //cyan
                        printf("Wrong key! Door remains locked.\n");
                        break;
                    }
                }
                
                printf("\033[0;36m"); //cyan
                printf("You left the room\n");
                printf("\033[0m"); //reset
                playerData->playerLocation=1;
                printf("Autosaving progress\n");
                saveGame(playerData);
                return 1;
                
            case(2):
                printf("\033[0;36m"); //cyan
                if(!note_terminal){
                    printf("Inside the drawer is a note and a portable linux terminal. Placed both in inventory.\nInventory can be accessed in the main menu.\n");
                    playerData->collectedInventory->Note_Terminal=true;
                    note_terminal=true;
                    printf("\033[0m"); //reset
                    printf("Autosaving progress\n");
                    saveGame(playerData);
                }
                else{
                    printf("The drawer is empty.\n");
                    printf("\033[0m"); //reset
                }
                break;
            case(3):
                printf("\033[0;36m"); //cyan
                printf("In the bookshelf there are two books titled: Basic Linux Commands and Reading Binary and ASCII\n");
                while(1){
                    printf("\033[1;31m");//bold red
                    printf("Will you read one?\n");
                    printf("\033[0;34m"); //blue
                    printf("1. Basic Linux Commands\n2.Reading Binary\n3.I don't feel like reading\n");
                    printf("\033[0m"); //reset
                    scanf("%d",&response);
                    if(response==1){
                        fp=fopen("books/linux.txt","r");
                        while((s=fgetc(fp))!=EOF) {
                            printf("%c",s);            
                        }
                        fclose(fp);
                        printf("\n");
                        break;
                    }
                    else if(response==2){
                        fp=fopen("books/binary.txt","r");
                        while((s=fgetc(fp))!=EOF) {
                            printf("%c",s);
                        }
                        fclose(fp);
                        printf("\n");
                        break;
                    }
                    else if(response==3){
                        break;
                    }
                    else{
                        printChoiceErr();
                    }
                    
                }
                
                break;
            case(4):
                printf("\033[0;36m"); //cyan
                printf("Looking out the window first notice the open barn door. (You were sure you closed it). You also see the town down the road.\n");
                printf("\033[0m"); //reset
                break;   
            case(5):
                openMenu(playerData);
                break;

            default:
                printChoiceErr();
        }
    }
  
    return 0;
}
int farm(saveData* playerData){
    int response;
    while(1){
        printf("\033[0;36m"); //cyan
        printf("You are outside your farm. Behind you is the door leading to the inside of your house. In front of you is a path leading to town.\n");
        if(!playerData->storyTold->outsideFarm){
            printf("You look around and noticed that indeed all your animals are missing.\n");
            playerData->storyTold->outsideFarm=true;
            printf("\033[0m"); //reset
            printf("Autosaving progress\n");
            saveGame(playerData);
        }
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Go back in the house\n2. Go into town\n3.Open Main Menu\n");
        scanf("%d",&response);
        if (response==1){
            printf("You open the door to your house, walk inside and to your bedroom.\n");
            return 0;
        }   
        else if(response==2){
            printf("You walk down the dirt driveway and onto the road heading to town.\n");
            return 2;
        }
        else if(response==3){
            openMenu(playerData);
        }   
        else{
            printChoiceErr();
        }
    }
   

    return 0;
}
int town(saveData* playerData){
    printf("In town");
    return 0;
}
int processusProcuratio(saveData* playerData){
     printf("In processus");
    return 0;
}
int memoriaProcuratio(saveData* playerData){
     printf("In memoria");
    return 0;
}
int procuratioRepono(saveData* playerData){
     printf("In repono");
    return 0;
}
int wideRiver(saveData* playerData){
     printf("In river");
    return 0;
}
int lostForest(saveData* playerData){
     printf("In forest");
    return 0;
}
int boronMountains(saveData* playerData){
    printf("In mountains");
    return 0;
}
