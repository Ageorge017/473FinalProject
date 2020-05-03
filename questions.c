#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

bool ProcessusFortress(){
    FILE* fp;
    char s;
    int response;
    printf("\033[0;36m"); //cyan
    printf("Welcome to the Fortress Gaunlet. In order to free your animals you have to answer all questions relating to processes correctly.\nTo quit anytime, enter 0.\n");
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
        printf("INCORRECT! Exiting gaunlet.\n");
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
        printf("INCORRECT! Exiting gaunlet.\n");        
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
        printf("INCORRECT! Exiting gaunlet.\n");
        return false;
    }

    return true;

}
bool lostForestQuestions(){
    int response;
    printf("\033[0;36m"); //cyan
    printf("Welcome to the Forest Gaunlet. In order to open the tunnels you have to answer all questions relating to processes correctly.\nTo quit anytime, enter 0.\n");
    printf("\033[1;31m");//bold red
    printf("Question 1: True or False? In a one-to-one threading model, a user-space library schedules a new thread when one is blocked.\n");
    printf("\033[0;34m"); //blue
    printf("1. True\n2. False\n");
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
    printf("Question 2: True or False? Multithreaded processes reduce their memory utilization by sharing their code, heap, and OS resources.\n");
    printf("\033[0;34m"); //blue
    printf("1. True\n2. False\n");
    scanf("%d",&response);

    if(response==1){
        printf("\033[0;32m");//GREEN
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the forest\n");
        return false;
    }
    return true;
}
bool boronMountainsQuestions(){
    int response;
    printf("\033[0;36m"); //cyan
    printf("Welcome to the Mountain Gaunlet. In order to open the tunnels you have to answer all questions relating to memory correctly.\nTo quit anytime, enter 0.\n");
    printf("\033[1;31m");//bold red
    printf("Question 1: True or False? The TLB caches address translations.\n");
    printf("\033[0;34m"); //blue
    printf("1. True\n2. False\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);
    if(response==1){
        printf("\033[0;32m");
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the mountains.\n");
        return false;
    }
    printf("\033[1;31m");//bold red
    printf("Question 2: True or False? When the first function in the library is invoked, the dynamic linker will load in the Dynamically Linked Library (DLL).\n");
    printf("\033[0;34m"); //blue
    printf("1. True\n2. False\n");
    scanf("%d",&response);

    if(response==1){
        printf("\033[0;32m");//GREEN
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the mountain\n");
        return false;
    }
    return true;
}

bool MemoriaCastle(){
    FILE* fp;
    char s;
    int response;
    printf("\033[0;36m"); //cyan
    printf("Welcome to the Castle Gaunlet. In order to free your animals you have to answer all questions relating to memory correctly.\nTo quit anytime, enter 0.\n");
    printf("\033[1;31m");//bold red
    fp=fopen("Questions/q4.txt","r");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);            
    }
    fclose(fp);
    printf("\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);

    if(response==3){
        printf("\033[0;32m");//GREEN
        printf("CORRECT!\n");
    }
    else{
        printf("INCORRECT! Exiting gaunlet.\n");        
        return false;
    }
    printf("\033[1;31m");//bold red
    fp=fopen("Questions/q5.txt","r");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);            
    }
    fclose(fp);
    printf("\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);

    if(response==4){
        printf("\033[0;32m");//Green
        printf("CORRECT!\n");
    }
    else{
        printf("INCORRECT! Exiting gaunlet.\n");
        return false;
    }
    printf("\033[1;31m");//bold red
    fp=fopen("Questions/q6.txt","r");
    while((s=fgetc(fp))!=EOF) {
        printf("%c",s);            
    }
    fclose(fp);
    printf("\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);

    if(response==2){
        printf("\033[0;32m");//Green
        printf("CORRECT!\n");
    }
    else{
        printf("INCORRECT! Exiting gaunlet.\n");
        return false;
    }

    return true;
}
bool riverQuestions(){
    int response;
    printf("\033[0;36m"); //cyan
    printf("Welcome to the River Gaunlet. In order to unlock the boat you have to answer all questions relating to memory correctly.\nTo quit anytime, enter 0.\n");
    printf("\033[1;31m");//bold red
    printf("Question 1: True or False? The TLB caches address translations.\n");
    printf("\033[0;34m"); //blue
    printf("1. True\n2. False\n");
    printf("\033[0m"); //reset
    scanf("%d",&response);
    if(response==1){
        printf("\033[0;32m");
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the mountains.\n");
        return false;
    }
    printf("\033[1;31m");//bold red
    printf("Question 2: True or False? When the first function in the library is invoked, the dynamic linker will load in the Dynamically Linked Library (DLL).\n");
    printf("\033[0;34m"); //blue
    printf("1. True\n2. False\n");
    scanf("%d",&response);

    if(response==1){
        printf("\033[0;32m");//GREEN
        printf("CORRECT!\n");
    }
    else{
        printf("Going back to the mountain\n");
        return false;
    }
    return true;
}
bool ReponoDungeon(){
    return false;
}