#include"chess.h"

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
