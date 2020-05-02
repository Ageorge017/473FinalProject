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
                printf("In the bookshelf there are a couple books you can read.\n");
                printf("\033[1;31m");//bold red
                printf("Will you read one?\n");
                printf("\033[0;34m"); //blue
                printf("1. Basic Linux Commands\n2.Reading Binary\n3.Crash Course on Processes\n4.Memory\n5.I don't feel like reading\n");
                printf("\033[0m"); //reset
                scanf("%d",&response);
                switch(response){
                    case(1):
                        fp=fopen("books/linux.txt","r");
                        while((s=fgetc(fp))!=EOF) {
                            printf("%c",s);            
                        }
                        fclose(fp);
                        printf("\n");
                        break;
                    case(2):
                        fp=fopen("books/binary.txt","r");
                        while((s=fgetc(fp))!=EOF) {
                            printf("%c",s);
                        }
                        fclose(fp);
                        printf("\n");
                        break;
                    case(3):
                        fp=fopen("books/process.txt","r");
                        while((s=fgetc(fp))!=EOF) {
                            printf("%c",s);
                        }
                        fclose(fp);
                        printf("\n");
                        break;
                    case(4):
                        fp=fopen("books/memory.txt","r");
                        while((s=fgetc(fp))!=EOF) {
                            printf("%c",s);
                        }
                        fclose(fp);
                        printf("\n");
                        break;
                    case(5):
                        break;
                    default:
                        printChoiceErr();

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
    int response;
    while(1){
        printf("\033[0;36m"); //cyan
        printf("You are now in town.\n");
        if(!playerData->storyTold->town){
            printf("As you walk into town you notice the bustle of the townsfolk and various rumors in the air.\n");
            playerData->storyTold->town=true;
        }
        printf("In front of you is a newspaper stand. Right in front of you is a newspaper stand. Towards the west of town is the Bar and the West Town Exit.\nTowards the east of town is the Post Office and the East Town Exit.\nThe center of town has a Water Fountain.\nTo the north of town is the North Town Exit\n");
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Check the Newspaper Stand\n2. Go North\n3.Go East\n4.Go West\n5.Go South\n6. Go Back to Farm\n7. Check Water Fountain\n8. Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                printf("\033[0;36m"); //cyan
                printf("BREAKING NEWS\nLast night a shadowy figure was seen in town coming from the farm road headed east.\nReports of animal sounds were also heard but no animals were reported to be seen.\n");
                printf("\033[0m"); //reset
                break;
            case(2):
                return 11;
            case(3):
                return 9;
            case(4):
                return 10;
            case(5):
                return 12;
            case(6):
                return 1;
            case(7):
                printf("In water fountain\n");  
                break;
            case(8):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }
    

    return 0;
}
int processusProcuratio(saveData* playerData){ //east
    bool challenge_passed=false;
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in front of the Processus Procuratio Fortress.\n");
    if(!playerData->storyTold->processus){
        printf("You hear animal sounds coming from inside the fortress.\n");
        playerData->storyTold->processus=true;
        printf("\033[0m"); //reset
        printf("Autosaving.\n");
        saveGame(playerData);
    }
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Storm the fortress\n2. Retreat to the forest\n3.Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                if(!playerData->completedChallenges->processus_puzzle){
                    challenge_passed = ProcessusFortress();
                    if(challenge_passed){
                        playerData->completedChallenges->processus_puzzle=true;
                        printf("\033[0;36m"); //cyan
                        printf("Congratulations! You've found and freed some of your animals. They have returned to the farm.\n");
                        printf("\033[0m"); //reset
                        printf("Autosaving.\n");
                        saveGame(playerData);
                    }   
                }  
                else{
                    printf("\033[0;36m"); //cyan
                    printf("There's nothing to do here. Returning to the forest\n");               
                }
                return 7;
            case(2):
                return 7;
            case(3):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }
}
int memoriaProcuratio(saveData* playerData){ //west
    bool challenge_passed=false;
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in front of the Memoria Procuratio Castle.\n");
    if(!playerData->storyTold->memoria){
        printf("You hear animal sounds coming from inside the castle.\n");
        playerData->storyTold->memoria=true;
        printf("\033[0m"); //reset
        printf("Autosaving.\n");
        saveGame(playerData);
    }
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Storm the castle!\n2. Retreat to the mountains\n3.Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                if(!playerData->completedChallenges->memoria_puzzle){
                    challenge_passed = MemoriaCastle();
                    if(challenge_passed){
                        playerData->completedChallenges->memoria_puzzle=true;
                        printf("\033[0;36m"); //cyan
                        printf("Congratulations! You've found and freed some of your animals. They have returned to the farm.\n");
                        printf("\033[0m"); //reset
                        printf("Autosaving.\n");
                        saveGame(playerData);
                    }   
                }  
                else{
                    printf("\033[0;36m"); //cyan
                    printf("There's nothing to do here. Returning to the mountains\n");               
                }
                return 8;
            case(2):
                return 8;
            case(3):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }

}
int procuratioRepono(saveData* playerData){ //north
    bool challenge_passed=false;
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in front of the Procuratio Repono Dungeon.\n");
    if(!playerData->storyTold->repono){
        printf("You hear animal sounds coming from inside the dungeon.\n");
        playerData->storyTold->repono=true;
        printf("\033[0m"); //reset
        printf("Autosaving.\n");
        saveGame(playerData);
    }
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Storm the dungeon!\n2. Retreat to the river\n3.Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                if(!playerData->completedChallenges->repono_puzzle){
                    challenge_passed = ReponoDungeon();
                    if(challenge_passed){
                        playerData->completedChallenges->repono_puzzle=true;
                        printf("\033[0;36m"); //cyan
                        printf("Congratulations on beating the game! You've found and freed the rest of your animals. They have returned to the farm.\n");
                        printf("\033[0m"); //reset
                        printf("Autosaving.\n");
                        saveGame(playerData);
                        return 0;
                    }   
                }  
                else{
                    printf("\033[0;36m"); //cyan
                    printf("There's nothing to do here. Returning to the river\n");               
                }
                return 6;
            case(2):
                return 8;
            case(3):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }
}
int wideRiver(saveData* playerData){ //south
    bool challenge_passed=false;
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in front of the Wide River. There is a boat that could possibly take you across the river to Procuratio Repono.\n");
    if(!playerData->storyTold->river){
        printf("Tell river story\n");
        playerData->storyTold->river=true;
        printf("\033[0m"); //reset
        printf("Autosaving.\n");
        saveGame(playerData);
    }
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Avast matey! Let's cross!\n2. I'm afraid of water, let's go back to town\n3.Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                if(!playerData->completedChallenges->river_puzzle){
                    printf("\033[0;36m"); //cyan
                    printf("You notice the boat is locked. To unlock it you must answer some operating system questions regarding storage. The information can be found back in the farm bedroom bookshelf.\n");
                    printf("\033[1;31m");//bold red
                    printf("Would you like to proceed?\n");
                    printf("\033[0;34m"); //blue
                    printf("1. Yes\n2. No\n");
                    printf("\033[0m"); //reset
                    scanf("%d",&response);
                    if(response==1){
                        challenge_passed = riverQuestions();
                    }
                    else if(response==2){
                        break;
                    }
                    if(challenge_passed){
                        playerData->completedChallenges->river_puzzle=true;
                        printf("\033[0m"); //reset
                        printf("Autosaving.\n");
                        saveGame(playerData);
                    }   
                }  
                else{
                    return 5;
                }
                break;
            case(2):
                return 11;
            case(3):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }

}
int lostForest(saveData* playerData){ //east
    bool challenge_passed=false;
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in the Lost Forest. There is a bridge leading the way to Processus Procuratio.\n");
    if(!playerData->storyTold->forest){
        printf("Tell forest story\n");
        playerData->storyTold->forest=true;
        printf("\033[0m"); //reset
        printf("Autosaving.\n");
        saveGame(playerData);
    }
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. I have to go forward\n2. I'm scared and want to go back to town\n3.Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
            if(!playerData->completedChallenges->lostforest){
                printf("\033[0;36m"); //cyan
                printf("You notice there is a raised bridge. To lower it you must answer some operating system questions regarding processes. The information can be found back in the farm bedroom bookshelf.\n");
                printf("\033[1;31m");//bold red
                printf("Would you like to proceed?\n");
                printf("\033[0;34m"); //blue
                printf("1. Yes\n2. No\n");
                printf("\033[0m"); //reset
                scanf("%d",&response);
                if(response==1){
                    challenge_passed = lostForestQuestions();
                }
                else if(response==2){
                    break;
                }
                if(challenge_passed){
                    playerData->completedChallenges->lostforest=true;
                    printf("\033[0m"); //reset
                    printf("Autosaving.\n");
                    saveGame(playerData);
                }   
            }  
            else{
                return 3;
            }
            break;
            case(2):
            return 9;
            case(3):
            openMenu(playerData);
            break;
            default:
            printChoiceErr();
        }
    }
}
int boronMountains(saveData* playerData){ //west
    bool challenge_passed=false;
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in the Boron Mountains. There is a series of tunnels leading the way to Memoria Procuratio.\n");
    if(!playerData->storyTold->mountains){
        printf("Tell mountain story\n");
        playerData->storyTold->mountains=true;
        printf("\033[0m"); //reset
        printf("Autosaving.\n");
        saveGame(playerData);
    }
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. I have to go forward\n2. I'm scared and want to go back to town\n3.Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                if(!playerData->completedChallenges->boronmountains){
                    printf("\033[0;36m"); //cyan
                    printf("You notice tunnels are sealed. To open them you must answer some operating system questions regarding memory. The information can be found back in the farm bedroom bookshelf.\n");
                    printf("\033[1;31m");//bold red
                    printf("Would you like to proceed?\n");
                    printf("\033[0;34m"); //blue
                    printf("1. Yes\n2. No\n");
                    printf("\033[0m"); //reset
                    scanf("%d",&response);
                    if(response==1){
                        challenge_passed = boronMountainsQuestions();
                    }
                    else if(response==2){
                        break;
                    }
                    if(challenge_passed){
                        playerData->completedChallenges->boronmountains=true;
                        printf("\033[0m"); //reset
                        printf("Autosaving.\n");
                        saveGame(playerData);
                    }   
                }  
                else{
                    return 4;
                }
                break;
            case(2):
                return 10;
            case(3):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }

}
int townEast(saveData* playerData){
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in Town East. Town East is home to the local Post Office.\n");
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Go inside Post Office\n 2. Leave Town East\n3. Go back to Town Center\n4. Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                printf("\033[0;36m"); //cyan
                printf("The only person inside the post office is the postwoman.\n");
                printf("\033[1;31m");//bold red
                printf("Do you wanna talk to her?\n");
                printf("\033[0;34m"); //blue
                printf("1. Yes\n2. I don't feel like talking to anyone today.\n");
                printf("\033[0m"); //reset
                scanf("%d",&response);
                switch(response){
                    case(1):
                        printf("\033[0;36m"); //cyan
                        printf("Post lady says something.\n");
                        if(!playerData->collectedInventory->Postcard){
                            printf("Here, a postcard came for you. Take it.\n Recieved Postcard. Placed it in inventory.\n");
                            playerData->collectedInventory->Postcard=true;
                            printf("\033[0m"); //reset
                            printf("Autosaving.\n");
                            saveGame(playerData);
                        }
                        break;

                    case(2):
                        break;
                    default:
                        printChoiceErr();
                }
                break;
            case(2):
                return 7;
            case(3):
                return 2;
            case(4):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }
}
int townNorth(saveData* playerData){
    return 2;
}
int townWest(saveData* playerData){
    int response;
    printf("\033[0;36m"); //cyan
    printf("You are now in Town West. Town West is home to the Valley Bar\n");
    while(1){
        printf("\033[1;31m");//bold red
        printf("What do you want to do?\n");
        printf("\033[0;34m"); //blue
        printf("1. Go inside bar\n 2. Leave Town West\n3. Go back to Town Center\n4. Open Main Menu\n");
        printf("\033[0m"); //reset
        scanf("%d",&response);
        switch(response){
            case(1):
                printf("\033[0;36m"); //cyan
                printf("Inside the bar is the bartender and a couple of locals.\n");
                printf("\033[1;31m");//bold red
                printf("What do you want to do?\n");
                printf("\033[0;34m"); //blue
                printf("1. Talk to bartender\n2. Talk to the locals\n3. I don't feel like talking to anyone today.\n");
                printf("\033[0m"); //reset
                scanf("%d",&response);
                switch(response){
                    case(1):
                        printf("\033[0;36m"); //cyan
                        printf("Bartender says something.\n");
                        if(!playerData->collectedInventory->Barflyer){
                            printf("Here's a flyer.\n Recieved Bar Flyer. Placed it in inventory.\n");
                            playerData->collectedInventory->Barflyer=true;
                            printf("\033[0m"); //reset
                            printf("Autosaving.\n");
                            saveGame(playerData);
                        }
                        break;
                    case(2):
                        printf("\033[0;36m"); //cyan
                        printf("Locals say something\n");
                        break;
                    case(3):
                        break;
                    default:
                        printChoiceErr();
                }
                break;
            case(2):
                return 8;
            case(3):
                return 2;
            case(4):
                openMenu(playerData);
                break;
            default:
                printChoiceErr();
        }
    }
}
int townSouth(saveData* playerData){
    return 2;
}