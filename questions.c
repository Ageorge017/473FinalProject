#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

bool lostForestQuestions(){
    FILE* fp;
    char s;
    int response;
    printf("\033[0;36m"); //cyan
    printf("Welcome to the Forest Gaunlet. In order to lower the bridge you have to answer all questions relating to processes correctly.\nTo quit anytime, enter 0.\n");
    printf("\033[1;31m");//bold red
    printf("Question 1: Which scheduler schedules a process as soon as it becomes ready?\n");
    printf("\033[0;34m"); //blue
    printf("1. Round Robin\n2. SJF preemptive\n3. SJF nonpreemptive\n4. FCFS\n5. Priority\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);
    if(response==2){
        printf("\033[0;32m");
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the forest\n");
        return false;
    }
    printf("\033[1;31m");//bold red
    fp=fopen("Questions/q2.txt","r");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);            
    }
    fclose(fp);
    printf("\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);

    if(response==2){
        printf("\033[0;32m");//GREEN
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the forest\n");
        return false;
    }
    printf("\033[1;31m");//bold red
    fp=fopen("Questions/q3.txt","r");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);            
    }
    fclose(fp);
    printf("\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);

    if(response==1){
        printf("\033[0;32m");//Green
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the forest\n");
        return false;
    }

    return true;

}
bool boronMountainsQuestions(){
    return false;
}
bool riverQuestions(){
    return false;
}
bool ProcessusFortress(){
    return false;
}
bool MemoriaCastle(){
    return false;
}
bool ReponoDungeon(){
    return false;
}