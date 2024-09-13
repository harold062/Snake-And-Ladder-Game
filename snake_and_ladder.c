#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<unistd.h>
#define clear() printf("\033[2J\033[3J\033[H");

int dice;
int checkposition(int position,char player[10],char face[],int dice);
char choice[2];
char g;
int count;
void rules();
void display(int newposition,char face[]);                    
void legend();
int player_1vs(int player2,int player3,int player4,int playerComp);
int player_2vs(int player1,int player3,int player4,int playerComp);
int player_3vs(int player1,int player2,int player4,int playerComp);
int player_4vs(int player1,int player2,int player3,int playerComp);
int playerVs_Comp(int player1,int player2,int player3,int player4);


int main(){
    
    char choice[2];
    int count=0,player1=0,player2=0,player3=0,player4=0,playerComp=0;
    srand(time(NULL));
    do{               
    clear();                       
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t┏------------------------┓\n");
    printf("\t\t\t\t\t\t\t|        MAIN MENU       |\n"
           "\t\t\t\t\t\t\t|                        |\n");   
    printf("\t\t\t\t\t\t\t|    [1]Play the Games   |\n"
           "\t\t\t\t\t\t\t|    [2] How to Play     |\n"
           "\t\t\t\t\t\t\t|    [0]    Exit         |\n ");
    printf("\t\t\t\t\t\t\t┗------------------------┛\n\n\n");   
    printf("\t\t\t\t\t\tEnter your choice: ");
    scanf("%s", choice);
    
    if(strcasecmp(choice,"0")==0){
         
         clear();
         printf("\t\t\t\t\t\t      Successfully Exited\n");        
         exit(1);
    }    
    
    if(strcasecmp(choice,"2")==0){
        clear();
        rules();
    }
 
    if(strcasecmp(choice,"1")==0){
    clear();
    do{
        printf("\n\n\n");
        printf("\t\t\t\t\t\t\t┏---------------------------┓\n");
        printf("\t\t\t\t\t\t\t|  How do you want to play? |\n"
               "\t\t\t\t\t\t\t|                           |\n"
               "\t\t\t\t\t\t\t|  [1] Player vs. Player    |\n"
               "\t\t\t\t\t\t\t|  [2] Player vs. Computer  |\n"
               "\t\t\t\t\t\t\t|  [3] Go back to Main Menu |\n"
               "\t\t\t\t\t\t\t|  [0]       Exit           |\n"
               "\t\t\t\t\t\t\t┗---------------------------┛\n");
               
               
               
        printf("\t\t\t\t\t\t\t Enter Choice: ");
        scanf("%s", choice);
        
        if(strcasecmp(choice,"1")==0){
            clear();
            printf("\n\n\n");
            printf("\t\t\t\t\t\t\t    PLAYER VS. PLAYER\n\n");
            printf("\t\t\t\t\t\t The Players should not exceed 4 players\n\n");
            printf("\t\t\t\t\t\t\tHow many players: ");
            scanf("%s",choice);
            if(strcasecmp(choice,"1")==0)
            {
                   clear();
                   player_1vs(player2,player3,player4,playerComp);                   
            }
            else if(strcasecmp(choice,"2")==0)
            {   
                    clear();
                    player_2vs(player1,player3,player4,playerComp);               
            }
            else if(strcasecmp(choice,"3")==0)
            {
                    clear();
                    player_3vs(player1,player2,player4,playerComp);               
            }
            else if(strcasecmp(choice,"4")==0)
            {
                    clear();
                    player_4vs(player1,player2,player3,playerComp);               
            }
            
        }
         else if(strcasecmp(choice,"2")==0)
        {
            clear();
            printf("\n\n\n");
            printf("\t\t\t\t\t\t      PLAYER VS. ALICE\n\n");
            playerVs_Comp(player1,player2,player3,player4);       
        }

         else if(strcasecmp(choice,"3")==0)
        {
            clear();
            break;      
        }
        
        else if(strcasecmp(choice,"0")==0){
         
         printf("\n\n\n");
         clear();
         printf("\t\t\t\t\t\t      Successfully Exited\n");        
         exit(1);
        }        
        else{
        printf("\t\t\t\t\t\t      Not in the choice\n"
               "\t\t\t\t\t\t           Try again\n");
           continue;        
        }
     }while(strcasecmp(choice,"0")!=0);
    }

        if(strcasecmp(choice,"0")!=0) {
        clear();
        printf("\t\t\t\t\t\t      Not in the choice\n"
               "\t\t\t\t\t\t           Try again\n");
           continue;        
        }
}while(strcasecmp(choice,"0")!=0);
}
void rules(){
        
        printf("\n\n\n\n\n");
        printf("\t\t       ┏-----------------------------------------------------------------------------------------┓\n");
        printf("\t\t       |   To Play:                                                                              |\n"
               "\t\t       |       In playing snake and ladder there are some options that a player can choose.      |\n"
               "\t\t       |        Choices that indicates Player vs Player and Player vs. Computer. First the       |\n"
               "\t\t       |      player vs player this features of the program will ask the player on how many      |\n"
               "\t\t       |     will play the game but these features have a limited number of players the number   |\n"
               "\t\t       |     of players must not exceed  to 4 players.Second one is player vs. computer,wherein  |\n"
               "\t\t       |                         your playing with computer named ALICE                          |\n"
               "\t\t       |       Before playing the game it will ask the player to enter the name of each player   |\n");
        printf("\t\t       ┗-----------------------------------------------------------------------------------------┛\n");
               
    while(1){
      char ent[5];
      printf("\n\n\t\t\t\t\t\t\tGo back[1]/Exit[0]: ");
      scanf("%s",ent);
       
       if(strcasecmp(ent,"1")==0)
       {
       break;
       }
       else if(strcasecmp(ent,"0")==0){
                            clear();
       printf("\n\n\n\t\t\t\t\t\t\t   SUCCESSFULLY EXITED\n\n\n");
         
            exit(1);
       }
       else{
       clear();
        printf("\n\n\n\t\t\t\t\t\t\t    Not in the choice\n"
               "\t\t\t\t\t\t\t        Try Again\n    ");
            continue;  
     }
    }
}
void legend()
{   
    printf("\t\t\t\t==================================LEGEND================================\n");
    printf("\t\t\t\t┏----------------------------------------------------------------------┓\n");
    printf("\t\t\t\t|               0-START                            100-END             |\n"
           "\t\t\t\t|   4=LADDER TO 35  70=LADDER TO 91    21=SNAKE TO  3  63=SNAKE TO  2  |\n"
           "\t\t\t\t|   7=LADDER TO 23  40=LADDER TO 80    17=SNAKE TO 13  26=SNAKE TO  5  |\n"
           "\t\t\t\t|  14=LADDER TO 43  10=LADDER TO 65    34=SNAKE TO 20  95=SNAKE TO 81  |\n"
           "\t\t\t\t|  24=LADDER TO 58  35=LADDER TO 75    42=SNAKE TO 22  47=SNAKE TO 30  |\n");        
    printf("\t\t\t\t┗----------------------------------------------------------------------┛\n");
             
}

void display(int newposition,char face[])
{

            printf("\t\t\t\t\t\t┏---------------------------------------┓\n");
            printf("\t\t\t\t\t\t");
            for(int y=91;y<=100;y++)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=90;y>80;y--)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }           
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=71;y<=80;y++)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=70;y>60;y--)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=51;y<=60;y++)
            {if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=50;y>40;y--)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=31;y<=40;y++)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=30;y>20;y--)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=11;y<=20;y++)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t|---+---+---+---+---+---+---+---+---+---|\n");
            printf("\t\t\t\t\t\t");
            for(int y=10;y>0;y--)
            {
            if(y==newposition)
            {
            printf("|%3s",face);
            }
            else{
            printf("|%3d",y);}
            }
            printf("|\n");
            printf("\t\t\t\t\t\t┗---------------------------------------┛\n");
            
            legend();
            
            
}
int playerVs_Comp(int player1,int player2,int player3,int player4){
  
    int playerComp=0,flag=0,presentposition,latestposition,a=0,z=0;
    char player_1[10],player_comp[10]={"Alice"},ch[2];
    clear();
    srand((unsigned)time(NULL));
    printf("\n");   
    printf("\t\t\t\t\t\t    Player 1:");
    scanf("%s", player_1);
    printf("\t\t\t\t\t\t    Player 2: %s\n\n",player_comp);
    clear();
    while(player1<100 && playerComp<100)
    {
     dice=(rand()%6+1);
     if(flag==0)
     {  
     printf("\t\t\t\t\t  %s's Turn\n",player_1);
     scanf("%c", &g);
     if(g=='\n'){
     a++;
     player1=player1+dice;
     flag=1;
     char face[]={" 🦊️"};
     presentposition=checkposition(player1,player_1,face,dice);
     player1=presentposition;
     sleep(1);
     }
     }
     else if(flag==1)
     {
     char face[]={" 🐨️"};
     printf("\t\t\t\t\t %s Turn\n",player_comp);
     sleep(3);
     z++;
     playerComp=playerComp+dice;
     flag=0;
     latestposition=checkposition(playerComp,player_comp,face,dice);     
     playerComp=latestposition;
     }
    }
     if(flag==0)
    {
    printf("\t\t\t\t\t  %s Win with %d Dice Rolls\n",player_comp,z);
    }
    else
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_1,a);
    }
}

int player_4vs(int player1,int player2,int player3,int playerComp){
    int player4=0,flag=0,a=0,b=0,c=0,d=0;
    int latest_position,new_position,present_position,today_position;
    char player_1[10],player_2[10],player_3[10],player_4[10],ch[2];
    clear();
    srand((unsigned)time(NULL));
    printf("\n");
    printf("\t\t\t\t\t\t    Player 1:");
    scanf("%s", player_1);
    printf("\t\t\t\t\t\t    Player 2:");
    scanf("%s", player_2);
    printf("\t\t\t\t\t\t    Player 3:");
    scanf("%s", player_3);
    printf("\t\t\t\t\t\t    Player 4:");
    scanf("%s", player_4);
    
    while(player1<100 && player2<100 && player3<100 && player4<100)
    {
     dice=(rand()%6+1);
     if(flag==0)
     {
     printf("\n");
     printf("\t\t\t\t\t  %s's Turn\n",player_1);
     scanf("%c", &g);
     printf("\t\t\t\t\t  %s roll the dice\n",player_1);
     printf("\t\t\t\t\t  The result is %d\n", dice);
     if(g=='\n'){
     a++;
     char face[]={" 🐒️"};
     player1=player1+dice;
     flag=1;
     latest_position=checkposition(player1,player_1,face,dice);
     player1=latest_position;
     }
     }
     else if(flag==1)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_2);
     scanf("%c", &g);
     if(g=='\n'){
     b++;
     char face[]={" 🐌️"};     
     player2=player2+dice;
     flag=2;
     new_position=checkposition(player2,player_2,face,dice);
     player2=new_position;
     }     
     }
     else if (flag==2)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_3);
     scanf("%c", &g);
     if(g=='\n'){
     c++;
     char face[]={" 🦝️"};     
     player3=player3+dice;
     flag=3;
     present_position=checkposition(player3,player_3,face,dice);
     player3=present_position;
     }          
     }
     else if (flag==3)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_4);
     scanf("%c", &g);
     if(g=='\n'){
     d++;
     char face[]={" 🐕️"};     
     player4=player4+dice;
     flag=0;
     today_position=checkposition(player4,player_4,face,dice);
     player4=today_position;
     }          
     }
    }
     if(flag==2)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_2,b);
    }
    else if(flag==0)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_4,d);
    }
    else if(flag==3)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_3,c);
    }
    else if(flag==1)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_1,a);
    }
}

int player_3vs(int player1,int player2,int player4,int playerComp){
    int player3=0,flag=0;
    int latest_position,new_position,present_position,a=0,b=0,c=0;
    char player_1[10],player_2[10],player_3[10],ch[2];
    clear();
    srand((unsigned)time(NULL));
    
    printf("\t\t\t\t\t\t    Player 1:");
    scanf("%s", player_1);
    printf("\t\t\t\t\t\t    Player 2:");
    scanf("%s", player_2);
    printf("\t\t\t\t\t\t    Player 3:");
    scanf("%s", player_3);
    
    while(player1<100 && player2<100 && player3<100)
    {
     dice=(rand()%6+1);
     if(flag==0)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_1);
     scanf("%c", &g);
     printf("\t\t\t\t\t  %s roll the dice\n",player_1);
     printf("\t\t\t\t\t  The result is %d\n", dice);
     if(g=='\n'){
     a++;
     char face[]={" 🐩️"};     
     player1=player1+dice;
     flag=1;
     latest_position=checkposition(player1,player_1,face,dice);
     player1=latest_position;
     }
     }
     else if(flag==1)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_2);
     scanf("%c", &g);
     printf("\t\t\t\t\t  %s roll the dice\n",player_2);
     printf("\t\t\t\t\t  The result is %d\n", dice);
     if(g=='\n'){
     b++;
     char face[]={" 🦌️"};     
     player2=player2+dice;
     flag=2;
     new_position=checkposition(player2,player_2,face,dice);
     player2=new_position;
     }     
     }
     else if (flag==2)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_3);
     scanf("%c", &g);
     printf("\t\t\t\t\t  %s roll the dice\n",player_3);
     printf("\t\t\t\t\t  The result is %d\n", dice);
     if(g=='\n'){
     c++;
     char face[]={" 🐖️"};     
     player3=player3+dice;
     flag=0;
     present_position=checkposition(player3,player_3,face,dice);
     player3=present_position;
     }          
    }
   }
     if(flag==2)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_2,b);
    }
    else if(flag==0)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_3,c);
    }
    else if(flag==1)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_1,a);
    }
}
int player_1vs(int player2,int player3,int player4,int playerComp){
        
        int player=0,latest_position,coun=0;
        char pla_yer[10];
        clear();     
        srand((unsigned)time(NULL));
        printf("\n");
        printf("\t\t\t\t\t\t    Player: ");
        scanf("%s", pla_yer);
        
        while(player<100){
        
        dice=(rand()%6+1);
        scanf("%c", &g);
        printf("\t\t\t\t\t  %s roll the dice\n",pla_yer);
        printf("\t\t\t\t\t  The result is %d\n", dice);
        if(g=='\n'){
        count++;
        char face[]={" 🐀️"};        
        player=player+dice;
        latest_position=checkposition(player,pla_yer,face,dice);
        player=latest_position;
        }
      }
        if(player>=100){
        printf("\t\t\t\t\t  %s win with %d Dice Rolls\n",pla_yer, count);
        }
}
int player_2vs(int player1,int player3,int player4,int playerComp){
    
    int player2=0,flag=0,a,b;
    int latest_position,new_position;
    char player_1[10],player_2[10],ch[2];
    clear();
    srand((unsigned)time(NULL));
    
    printf("\n");
    printf("\t\t\t\t\t\t    Player 1:");
    scanf("%s", player_1);
    printf("\t\t\t\t\t\t    Player 2:");
    scanf("%s", player_2);
    
    while(player1<100 && player2<100)
    {
     
     dice=(rand()%6+1);
    
        if(flag==0)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_1);
     scanf("%c", &g);
     printf("\t\t\t\t\t  %s roll the dice\n",player_1);
     printf("\t\t\t\t\t  The result is %d\n", dice);
     if(g=='\n'){
     a++;
     char face[]={" 🐈️"};     
     player1=player1+dice;
     flag=1;
     latest_position=checkposition(player1,player_1,face,dice);
     player1=latest_position;      
     }
     }
     else if(flag==1)
     {
     printf("\t\t\t\t\t  %s's Turn\n",player_2);
     scanf("%c", &g);
     printf("\t\t\t\t\t  %s roll the dice\n",player_2);
     printf("\t\t\t\t\t  The result is %d\n", dice);
     if(g=='\n'){
     b++;
     char face[]={" 🐇️"};     
     player2=player2+dice;
     flag=0;
     new_position=checkposition(player2,player_2,face,dice);
     player2=new_position;
     }     
     }
    }
     if(flag==0)
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_2,b);
    }
    else
    {
    printf("\t\t\t\t\t  %s Wins with %d Dice Rolls\n",player_1,a);
    }
}
int checkposition(int position,char player[],char face[],int dice){
    
    int newposition;
    int buff;
    clear();
    if(position>100)
    {
    buff=position-100;
    printf("\n\n\t\t\t\tThe position is greater than the target no. you moved %d spaces to the left\n",buff);
    position=100-buff;
    }

    switch(position){
        
       case 4:newposition=35;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                     display(newposition,face);                    
                     return newposition;
                    
              break;
       case 7:newposition=23;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                     display(newposition,face);                    
                      return newposition;
                      
              break;                 
       case 14:newposition=43;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                     display(newposition,face);                    
                      return newposition;
                      
              break;       
       case 24:newposition=58;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                    display(newposition,face);                    
                      return newposition;
                      
              break;       
       case 70:newposition=91;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);
                      return newposition;
                      
              break;       
       case 9:newposition=31;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                    
                      return newposition;
                      
              break;       
       case 40:newposition=80;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                   
                      return newposition;
                      
              break;       
       case 46:newposition=65;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                    
                      return newposition;
                      
              break;       
       case 35:newposition=75;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Ladder in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                    
                      return newposition;
                      
              break;       
       case 21:newposition=3;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                     display(newposition,face);                    
                      return newposition;
                      
                      
              break;      
       case 17:newposition=13;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                     display(newposition,face);                    
                      return newposition;
                      
              break;             
       case 34:newposition=20;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                       display(newposition,face);                    
                      return newposition;
                      
              break;         
       case 42:newposition=22;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                   
                      return newposition;
                      
              break;  
       case 10:newposition=65;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                   
                      return newposition;

                      
              break;                           
       case 63:newposition=2;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                       display(newposition,face);                    
                      return newposition;
                      
              break;             
       case 90:newposition=32;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                    
                      return newposition;
                      
              break;             
       case 26:newposition=5;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                      display(newposition,face);                    
                      return newposition;
                      
              break;             
       case 47:newposition=30;   
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                       display(newposition,face);                    
                      return newposition;
                      
              break; 
              
        case 95:newposition=81;   
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t   %10s Landed on the Snake in the space %d\n"
                     "\t\t\t\t\t\t    %10s is in the space %d\n",player,position,player,newposition); 
                       display(newposition,face);                    
                      return newposition;
                      
              break;               
              
       default:newposition=position;
              printf("\t\t\t\t\t\t         %10s's Turn\n",player);
              printf("\t\t\t\t\t\t      %10s roll the dice\n",player);
              printf("\t\t\t\t\t\t             The result is %d\n", dice);      
              printf("\t\t\t\t\t\t     %10s in the position %d\n",player,newposition);
                      display(newposition,face);                    
                      return newposition;
               
              break;
    }
}
