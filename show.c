#include"chess.h"
/*
char getFirstPlayersLastName(char token[],int k){ //will be passing string argument here
int i;
//char temp[MAX_COMMAND_TOKEN_LENGTH];
char firstPlayerString[10000];
//temp[i++] = atoi(token[]);
while(sizeof(token[i]) < k){
//for(int i = 0; i < token; i++){//save string to array
firstPlayerString[i]= token[i];
//token[i] = (char*)malloc(strlen(temp) * sizeof(char));
printf("%c",firstPlayerString[i]);
i++;
}
return 0;
}

//will be passing string argument h
char getSecondPlayersLastName(char name[], int k){
int i;
char secondPlayerString[10000];

while(sizeof(name[i]) < k+1){
//for(int i = 0; i < token; i++){//save string to array
//strcpy(&secondPlayerString[i], token[i]);
secondPlayerString[i] = name[i];
printf("%c",secondPlayerString[i]);
i++;
//token[i] = (char*)malloc(strlen(temp) * sizeof(char));
}
return 0;
}
*/

handleShow(char* name1, char* name2, int d, int o, int g) {
    int i, j;
    char temquip;//something like this
    //print out board
    //while(name[i] != '\0' || name[i] != '\n'){

   
    //printf("board \t");
    //this will print an original board
        if(d==0){
      if(g>0){
        printf("%s \n", name2);
      }else{
        printf("Player 2 \n");//defult name
      }
    printf("bd \t");
    for (i = 0; i < 8; i++)//file labels...
        printf("%c%c", 'a' + i, i == 7 ? '\n' : '\t');
    for (i = 0; i < 8; i++)//table itself
        for (j = 0; j < 9; j++)
            printf("%d%c", j == 0 ? 8 - i : board[i][j - 1], j == 8 ? '\n' : '\t');
    if(o>0){
      printf("%s \n", name1);
    }else{
      printf("Player 1 \n");
      }
    } else{//print mirrored board if -r is given in arg[]
      if(g > 0){
         printf("%s \n", name1);
      }else{
        printf("Player 1 \n");//defult name
      }
    printf("bd \t");
    for (i = 0; i < 8; i++)//print labels...
        //printf("%c%c", 'h' - i, i == 7 ? '\n' : '\t');
        printf("%c%c", 'h' - i, i == 7 ? '\n' : '\t');
    for (i = 7; i >= 0; i--)//table itself
    //for (i = 0; i < 8; i++)//table itself
        for (j = 8; j >= 0; j--)
            printf("%d%c", j == 8 ? 8 -i : board[i][j], j == 0 ? '\n' : '\t');
      if(o > 0){
        printf("%s \n", name2);
      }else{
        printf("Player 2 \n");
      }
    }
    //this will print a reversed board

    //while(name[i] != '\0' || name[i] !='\n'){
}







/*
#include"chess.h"
handleShow() {
    int i, j;
    printf("board\t");
    for (i = 0; i < 8; i++)//file labels...
        printf("%c%c", 'a' + i, i == 7 ? '\n' : '\t');
    for (i = 0; i < 8; i++)//table itself
        for (j = 0; j < 9; j++)
            printf("%d%c", j == 0 ? 8 - i : board[i][j - 1], j == 8 ? '\n' : '\t');
}
*/