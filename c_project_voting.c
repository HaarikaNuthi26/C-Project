/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX_votes 15
    int c1=0,c2=0,c3=0,c4=0,c5=0;
int eligibility(int age,char id);
void casting_vote(char v);
int counting(int c1,int c2,int c3,int c4,int c5);
int main()
{
    int age,e;
    char id[10], name[40],votes;
    char cand1[30]="Aravind Kejriwal";
    char cand2[30]="Parvesh Singh";
    char cand3[30]="Ramesh Bidhuri";
    char cand4[30]="Alka Lamba";
    char cand5[30]="Sandeep Dikshit";
    printf(".........          ONLINE VOTING SYSTEM     .........\n");
    
    while(1)  
    {
    printf("Enter age:\n");
    scanf("%d",&age);
    printf("Enter VoterId:\n");
    //for(int i =0;i<10;i++){
        scanf("%[^\f]s",id);
    //}
    
    //printf("%s",id);
    e=eligibility(age,id);
    if(e==0){
        printf("You are not eligible\n");
        break;
    }
    else{
        printf("CANDIDATE LIST:\n");
        printf("Enter 1 for %s\nEnter 2 for %s\nEnter 3 for %s\nEnter 4 for %s\nEnter 5 for %s\n",cand1,cand2,cand3,cand4,cand5);
        printf("Enter your vote:\n");
        scanf("%c",&votes);
        casting_vote(votes);
        printf("YOUR VOTE CASTED SUCCESSFULLY..!!!");
        int result=counting(c1,c2,c3,c4,c5);
        printf("Maximum votes : %d\n",result);
    
    }
    }
    
    return 0;

}
int eligibility(int age,char id){
    char Alpha[4],Digit[8];
    int flag=0;
    if(age>=18)
    {
        if(strlen(id)==10)
        {
            strncpy(Alpha,id,3);
            strncpy(Digit,id+3,7);
            Alpha[3]='\0';
            Digit[7]='\0';
        for(int i=0;Alpha[i]!='\0';i++)    
        {
             if(!isalpha(Alpha[i]))
             {
                flag=1;
                 break;
             }
         }
         for(int j=0;Digit[j]!='\0';j++)    
        {
             if(!isdigit(Digit[j]))
             {
                 flag=1;
                 break;
             }
        }
        //if(flag==0)
        //printf("You are eligible to vote\n");
     }
    }
     else
     {
         flag=1;
       //  printf("You are not eligible\n");
     }
     return flag;
}
void casting_vote(char v){
    
    switch(v){
        case '1': c1+=1;
                    break;
        case '2': c2+=1;
                    break;
        case '3' : c3+=1;
                    break;
        case '4' : c4+=1;
                    break;
        case '5' : c5+=1;
                    break;
        default : printf("Invalid Candidate\n");
                 exit(0);
    }
  
}
int counting(int c1,int c2,int c3,int c4,int c5){
    int arr[5] ={c1,c2,c3,c4,c5};
    int MAX=arr[0];
    for(int i=0;i<5;i++)
    {
        
        if(MAX<arr[i])
        {
            MAX=arr[i];
        }
    }
    return MAX;
}


    

    
