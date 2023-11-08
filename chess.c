#include "chess.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
square board[8][8];
int turn;
//char firstLastNameArray[5000];//for getting the first players name
//char secondLastNameArray[5000];//for getting the second players name
//int moveArray[100000][100000];// for getting a list of pre-recorded moves.
//int nameArray[10000];
//int n=0;//for fetching the total number of chars in the first array
//int b=0;//for fetching the total number of chars in the second array
//int p = 1;

//add arguments for board reset just pass a value through
//passing 1 for normal start
//passing 2 for odd start
static void resetBoard() {
    turn = WHITE;//WHITE moves first
    int i, j;
    for (i = 2; i < 6;i++)
        for (j = 0;j < 8;j++)
            board[i][j] = EMPTY;
    for (j = 0;j < 8;j++) {
        board[1][j] = BLACK * PAWN;
        board[6][j] = WHITE * PAWN;
    }
    board[0][0] = board[0][7] = BLACK * ROOK;
    board[7][0] = board[7][7] = WHITE * ROOK;
    board[0][1] = board[0][6] = BLACK * KNIGHT;
    board[7][1] = board[7][6] = WHITE * KNIGHT;
    board[0][2] = board[0][5] = BLACK * BISHOP;
    board[7][2] = board[7][5] = WHITE * BISHOP;
    board[0][3] = BLACK * QUEEN;
    board[7][3] = WHITE * QUEEN;
    board[0][4] = BLACK * KING;
    board[7][4] = WHITE * KING;
}

//for user input
char getCommandWord(char command[], int maxLength) {
    char lastCharacter;//either space or new line
    int i;
    for (i = 0; (lastCharacter = getchar()) == ' '; i++);//skip leading white spaces
    if (lastCharacter == '\n') {
        command[0] = '\0';
        return lastCharacter;
    }
    command[0] = lastCharacter;
    for (i = 1; i < maxLength - 1 && (command[i] = getchar()) != ' ' && command[i] != '\n'; i++);
    lastCharacter = command[i];
    command[i] = '\0';
    return lastCharacter;
}

handleAMove(char* singleMove){
  int capture = 0;
  int i = 0;
  //char source[1000];
  //char target[1000];
  //char * temp;
  //strcpy(temp, singleMove);
  //char temp = *singleMove;
  //temp = singleMove[];
  
  //strncpy(source,temp,2);
  //strncp(target,temp +2, 2);
  //temp = isUpper(*temp)?(temp++)):temp;
  if(isupper(*singleMove)){
    singleMove++;
  }
  if(singleMove[2] == 'x'){
    capture =1;
  }
  //strncpy(source, temp , 2);
  //strncpy(target, temp + 2 , 2);
  //temp = 
  //isupper(*temp)?(temp++):temp;
  //if(*singleMove =='x')
    //capture = 1;
  char sourceFile = singleMove[0];
  char targetFile = singleMove[capture + 2];
  char sourceRank = singleMove[1] - '0';
  char targetRank = singleMove[3 + capture] - '0';
  char sourceI = 8 - sourceRank;
  char sourceJ = sourceFile - 'a';
  char targetI = 8 - targetRank;
  char targetJ = targetFile - 'a';

  //char *delim = strtok(singleMove,",");
  //printf("%c", delim[i]);

    //checking the turn first
    /*
    if ((int)(board[sourceI][sourceJ] * turn) < 0) {
        printf("Turn violation, it's %s to move\n", turn == WHITE ? "white" : "black");
        //return;
    }
    if (board[sourceI][sourceJ] == EMPTY || board[targetI][targetJ] != EMPTY) {
        printf("Invalid move: either source square is empty or target square is not empty\n");
        //return;
    }
    if (!isLegalMove(sourceI, sourceJ, targetI, targetJ)) {
        printf("Illegal chess move\n");
        //return;
    }*/
    //end of error checking....


  
  //for(int f= 0; f < strlen(singleMove);f++){
  board[targetI][targetJ] = board[sourceI][sourceJ];
  //prinf(board[sourceI][sourceJ];);
  board[sourceI][sourceJ] = 0;
  
    turn *= -1;
  //}
  //for(int f= 0; f < strlen(singleMove);f++){
  //printf("%c \n", singleMove[f]);
  
  //big piece is entered
  /*if (singleMove[f] == 'R' || singleMove[f] == 'K' || singleMove[i] =='Q' || singleMove[i] == 'B' || singleMove[i + 4] == 'R' || singleMove[i + 4] == 'K' || singleMove[i + 4] =='Q' || singleMove[i + 4] == 'B' || singleMove[i+5] == 'R' || singleMove[i + 5] == 'K' || singleMove[i + 5] =='Q' || singleMove[i + 5] == 'B' || singleMove[i + 6] == 'R' || singleMove[i + 6] == 'K' || singleMove[i + 6] =='Q' || singleMove[i + 6] == 'B'){
  }else{//pawn is entered

  }*/
  //}

  /*
  if(isupper(singleMove)){//skip the first capital letter
  printf("weeeeeeeeeeeeeee");
  singleMove++;
  }
  if(*singleMove == ',')
  singleMove++;
  */

}

main(int argc, char** argv) {
    /*
    * You can access all the command-line arguments here
    * argv[1], argv[2], ...
    * mv d2 d4
    * mv d7 d5
    * mv e2 e4
    * cp d5 e4
    * mv g1 h3
    * mv e8 d7
    * mv d1 d3
    */
    //Example of import option: -i d2d4,d7d5,e2e4,d5xe4,Ng1h3,Ke8d7,Qd1d3
    //which is equivalent to a new game started this way:
    //int counter = 1;
    //char* name1[100]; 
    //char* name2[100];
    char command[MAX_COMMAND_TOKEN_LENGTH];
    //char command2[10000];//max characters you can use in this array
    //char playerLastCharacter = 0; 
    char lastCharacter;
   
    //int columnArray[1000]; 
    //char* pointer;
   
    int d, o, g;
    d=0;
    o=0;
    g=0; 
    
    resetBoard();
    //-w first playername -b second player name
    //-i imports a player game 
    //-r flips game
      //printf("please pick an option: \n");
      //printf("-w(space)first playername -b(space)2ndPlayerName: \n");
      //printf("-r flips the board -i(space)moves imports moves \n");
      //playerLastCharacter =  getCommandWord(command2, 10000);
      //printf(">>");
   //AH = argv[counter];
	//for(int i = 0; i<10; i++)
      	//printf("%s \n", argv[i]);
      for(int i = 1; i < argc; i++){
        char* AH = argv[i];
        //if(*AH == '-'){

        //}
        
      //if(strcmp(argv[counter], "-")==0){
              //counter++;
              //}   
      switch(AH[1]) {
        case 'w':
          //add to get rid of space
          strcpy(name1, argv[++i]);
          o++;
          printf("we got inside of the w argument %d \n",o);
          //name1[counter++];
          //handleShow(name1,name2,p);
          break; 
        case 'b':
          //counter++;
          strcpy(name2, argv[++i]);
          //counter++;
          //argv[name2[counter]] = command2;
          g++;
          printf("we got inside of the b argument %d \n", g);
          //handleShow(name1,name2,++p);
          
          break;
        case 'r'://flip board
          //counter++;
          printf("we got inside of the r argument \n");
          d++;
          //counter++; 
          break;
        case 'i': //import a game
          //argv[counter] = command2;
          
          printf("we got inside of the i argument \n");
          //handleAMove(argv[++i]);
          char* move = argv[++i]; //new char move is pointing at user imput array
          //sense there is no container for move to prevent memory dump
          char* rowArray = (char*) malloc((strlen(move) + 1) * sizeof(char));
          rowArray = strtok(argv[i], ",");//take out the ,
          //strcpy(rowArray, argv[++i]);
          while(rowArray != 0){
          handleAMove(rowArray);
          rowArray = strtok(0, ",");//using delimiter to break up string

          //isupper(rowArray);
          }
          //handleAMove(argv[++i]);
          //strcpy(rowArray, handleAMove(argv));
          break;
          }
        }
    
    //int i = 0; //reset
    printf("Start the game using a mv command! Valid commands are quit, show, mv and cp.\n");
    while (1) {//infinite while loop...
    //since i is used, we are using int o and p
    //if(resetBoard(){};
    //int o =0;
        printf(">>");
        lastCharacter = getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH);
        if (strcmp(command, "quit") == 0)//if command === "quit"
            break;
        else if (!strcmp(command, "mv"))//if command == "mv"
        {
            if (lastCharacter == '\n')//mv\n reaches the end of the line
                printf("Too few arguments for mv command! It must be in the form of mv ai bj.\n");
            else
                handleMove();
        }
        else if (!strcmp(command, "cp"))//if command == "cp"
        {
            if (lastCharacter == '\n')//cp\n
                printf("Too few arguments for cp command! It must be in the form of cp ai bj.\n");
            else
                handleCapture();
        }
        else if (!strcmp(command, "show"))//if command == "show"
        {
            if (lastCharacter != '\n') {//show x\n
                printf("Too many arguments for show command! It must be in the form of show.\n");
                while (getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH) != '\n');//skip the ramainder of the invalid show command...	
            }
            else
                handleShow(name1, name2, d, o, g);;
        }
        else {
            printf("invalid command! Your command must start either with quit, show, mv or cp.\n");
            while (lastCharacter != '\n')//skip the remainder of my invalid command...
                lastCharacter = getCommandWord(command, MAX_COMMAND_TOKEN_LENGTH);
        }
    }
  }
/*
    //pointer = &command2[i];
    printf("Before starting the game, please enter the information in the following order, in lowercase: \n");
    printf("-w(first player's last name)*pressSpaceBar*-b(2nd player's last name) ");
    printf("-i(imports a game where game is a sequence of moves/captures seporated by commas(,)");

    printf("*pressSpaceBar*-r(changes the default board to black on bottom, white on top).\n");
    //maybe if i get to time, ill do time.
    printf(">>");
    //if command2 does not equal -n
    while(1){//infinite while loop
    playerLastCharacter = getCommandWord(command2, 1000);

  //---------------------_-w-FIRSTPLAYER----------------------------------------
    if(command2[0] == '-' && command2[1] == 'w'){
    //if(pointer[0] == '-' && pointer[1] == 'w'){
      if(playerLastCharacter == '\n'){//the argument is not right
      printf("Too few arguments for command! (you pressed enter) It must give user name.\n");
      while (playerLastCharacter != '\n')//skip the remainder of my invalid command...
                playerLastCharacter = getCommandWord(command2, 1000);
      }//end inner if statement
        //in the outer if statement
      //need to get the number of spaces that first player last name occupies.
      while(command2[2 + i] != ' '){ 
      //while(pointer[2+i] != ' '){//testing pointers
      //coppying chars to the first player's last name
      firstLastNameArray[i] = command2[2+i];
      //getFirstPlayersLastName(firstLastNameArray[], command2[5 + i]);
      //firstLastNameArray = getFirstPlayersLastName(pointer[6+i],i);
      ++n;//max number of integers inside the first while loop
      ++b;//max number of integers inside this and next while loop
      ++i;
      }
      }else if(command2[2 + i] == EOF){//end outer if statement and while loop
      //continue;//maybe use it?
      printf("you got to the end of the file");
      break;
      }else{//end outer if statement and start else statment if a player skipped command 5 and 6 indicies
        printf("You don't want to enter a name for the first player?\n");
        //break;//break from loop
    }//end else statement of inner while loop finish first name
//------------------------------------------------------------------------------
    //getFirstPlayersLastName(firstLastNameArray, sizeof(command2[1-5]));
//------------_-b-SECOND-PLAYER----------------------------------------
    //skip (4 + 1 + i)th character in the char array string for space
    //4 stands for the 6th character in this string, 
    //1 stands for the spacebar, 
    //i is the counted ammount characters in the last name,
    //which was taken from the first inner while loop
    //if(pointer[4 + i] == '-' && pointer[5 + i] == 'b'){
    if(command2[4 + i] == '-' && command2[5 + i] == 'b'){
      if(playerLastCharacter == '\n'){//the argument is not right
      printf("Too few arguments for command! (you pressed enter) It must give user name.\n");
            while (playerLastCharacter != '\n')//skip the remainder of my invalid command...
                playerLastCharacter = getCommandWord(command2, 1000);
      }//end inner if statement
      //while(pointer[6+1] != ' ')//testing pointers
      while(command[6+i] != ' '){
      //dont know about the &nds
      //getSecondPlayersLastName(strcpy(secondLastNameArray[i], command2[6 + i]));
      //strcpy(secondLastNameArray[i], &pointer[7 + i]);//coppying chars to the //2nd player's last name
      secondLastNameArray[i] = command2[6+n];
      b++;//this is for the max number of integers inside of both while loops
      ++i;//max incrementation and process
      }//end outer if statement and while loop
      }else if(command[6 + i] == EOF){
        printf("you got to the end of the file");
        break;
      }else{
         printf("You don't want to enter a name for the 2nd player?\n");
         //break;//break from loop
      }//end else statement for the second name
    
    //if user imput at unit 0 equals -i(spacebar)
    //then start the while loop for the splitter, and //continue till spacebar is entered
    
    //-----------_-r--BOARD ROTATION---------------------------------------------
        //now for board rotation
    //skip (7 + 1 + i)th character in the char string for space
    if((command2[8 + i] == '-' && command2[9 + i] == 'r')||(command2[0] == '-' && command2[1] == 'r')){
    //if(pointer[8 + i] == '-' && pointer[9 + i] == 'r'){
    resetBoard(2);//flipped board start
    break;
    }else if(playerLastCharacter == '\n'){//the argument is not right
      printf("Too few arguments for command! (you pressed enter) It must give user name.\n");
      break;//last of the loop
    }else{
      resetBoard(1);//normal start
    }
//-------------_-i-IMPORTING A GAME----------------------------------------------
    if((command2[0] == '-' && command2[1] == 'i')||(command2[9 + i] == '-' && command2[10 + i] == 'i')||(command2[12 +i] == '-' && command2[13 + i] == 'i')){ 
    //testing pointers
    //if(pointer[0] == '-' && pointer[1] == 'i'){
      //going to use a delimmiter here ',' with a while loop
      //Example of import option: -i d2d4,d7d5,e2e4,d5xe4,Ng1h3,Ke8d7,Qd1d3
      //first letter is 5 points in, second letter is 7 points in then 9 then 11

      //for pawns
      while(command2[3 + i] != ' '){
      int f = 0;//for the other counter
        if(command2[3 + i] != ','){
          if(command2[3 + i] == 'x'){
            i++; //increment one to skip the x
          }

          if(command2[3+i] == 'R'){
            i = i + 3;
            if(command2[3 + i] == 'x'){
              i++; //increment one to skip the x
            }
            //R is equal to 2
            if(command2[3+i] == 'a'){//increment the i on every one of these
                columnArray[i] = 0;
                i++;//OMG
            }else if(command2[3+i] == 'b'){
                columnArray[i] = 1;
                i++;
            }else if(command2[3+i] == 'c'){
                columnArray[i] = 2;
                i++;
            }else if(command2[3+i] == 'd'){
                columnArray[i] = 3;
                i++;
            }else if(command2[3+i] == 'e'){
                columnArray[i] = 4;
                i++;
            }else if(command2[3+i] == 'f'){
                columnArray[i] = 5;
                i++;
            }else if(command2[3+i] == 'g'){
                columnArray[i] = 6;
                i++;
            }else if(command2[3+i] == 'h'){
                columnArray[i] = 7;
                i++;
            }if(command2[3+i] == 0 || (command2[3+i] == 1) ||
          command2[3+i] == 2 ||command2[3+i] == 3 ||
          command2[3+i] == 4 || command2[3+i] == 5 ||
          command2[3+i] == 6 || command2[3+i] == 7){
            rowArray[i] = command2[3+i];
          //a-h down equal the columns
          //turns them into numbers
          //and then shove into an array
          //increment by i before looping back again
          nameArray[f] = 4;
            i++;
            f++;
              }
          }else if(command2[3+i] == 'N'){
            i = i + 3;
            //knight is equal to 3
              if(command2[3 + i] == 'x'){
              i++; //increment one to skip the x
            }
            if(command2[3+i] == 'a'){
                columnArray[i] = 0;
                i++;
            }else if(command2[3+i] == 'b'){
                columnArray[i] = 1;
                i++;
            }else if(command2[3+i] == 'c'){
                columnArray[i] = 2;
                i++;
            }else if(command2[3+i] == 'd'){
                columnArray[i] = 3;
                i++;
            }else if(command2[3+i] == 'e'){
                columnArray[i] = 4;
                i++;
            }else if(command2[3+i] == 'f'){
                columnArray[i] = 5;
                i++;
            }else if(command2[3+i] == 'g'){
                columnArray[i] = 6;
                i++;
            }else if(command2[3+i] == 'h'){
                columnArray[i] = 7;
                i++;
            }if(command2[3+i] == 0 || (command2[3+i] == 1) ||
          command2[3+i] == 2 ||command2[3+i] == 3 ||
          command2[3+i] == 4 || command2[3+i] == 5 ||
          command2[3+i] == 6 || command2[3+i] == 7){
            rowArray[i] = command2[3+i];
          //a-h down equal the columns
          //turns them into numbers
          //and then shove into an array
          //increment by i before looping back again
          nameArray[f] = 2; 
            i++;
            f++;
              }
          }else if(command2[3+i] == 'B'){
            i = i + 3;
            if(command2[3 + i] == 'x'){
            i++; //increment one to skip the x
            }
            //biship is equal to 4
            if(command2[3+i] == 'a'){
                columnArray[i] = 0;
                i++;
            }else if(command2[3+i] == 'b'){
                columnArray[i] = 1;
                i++;
            }else if(command2[3+i] == 'c'){
                columnArray[i] = 2;
                i++;
            }else if(command2[3+i] == 'd'){
                columnArray[i] = 3;
                i++;
            }else if(command2[3+i] == 'e'){
                columnArray[i] = 4;
                i++;
            }else if(command2[3+i] == 'f'){
                columnArray[i] = 5;
                i++;
            }else if(command2[3+i] == 'g'){
                columnArray[i] = 6;
                i++;
            }else if(command2[3+i] == 'h'){
                columnArray[i] = 7;
                i++;
            }if(command2[3+i] == 0 || (command2[3+i] == 1) ||
          command2[3+i] == 2 ||command2[3+i] == 3 ||
          command2[3+i] == 4 || command2[3+i] == 5 ||
          command2[3+i] == 6 || command2[3+i] == 7){
            rowArray[i] = command2[3+i];
          //a-h down equal the columns
          //turns them into numbers
          //and then shove into an array
          //increment by i before looping back again
          nameArray[f] = 3; 
            i++;
            f++;
              }
          }else if(command2[3+i] == 'Q'){
            i = i + 3;
            //queen is equal to 5  
            if(command2[3 + i] == 'x'){
            i++; //increment one to skip the x
            }            
            if(command2[3+i] == 'a'){
                columnArray[i] = 0;
                i++;
            }else if(command2[3+i] == 'b'){
                columnArray[i] = 1;
                i++;
            }else if(command2[3+i] == 'c'){
                columnArray[i] = 2;
                i++;
            }else if(command2[3+i] == 'd'){
                columnArray[i] = 3;
                i++;
            }else if(command2[3+i] == 'e'){
                columnArray[i] = 4;
                i++;
            }else if(command2[3+i] == 'f'){
                columnArray[i] = 5;
                i++;
            }else if(command2[3+i] == 'g'){
                columnArray[i] = 6;
                i++;
            }else if(command2[3+i] == 'h'){
                columnArray[i] = 7;
                i++;
            }if(command2[3+i] == 0 || (command2[3+i] == 1) ||
          command2[3+i] == 2 ||command2[3+i] == 3 ||
          command2[3+i] == 4 || command2[3+i] == 5 ||
          command2[3+i] == 6 || command2[3+i] == 7){
            rowArray[i] = command2[3+i];
          //a-h down equal the columns
          //turns them into numbers
          //and then shove into an array
          //increment by i before looping back again
          nameArray[f] = 5; 
            i++;
            f++;
              }
          }else if(command2[3+i] == 'K'){
            i = i + 3;
            //king is equal to 6
            if(command2[3 + i] == 'x'){
            i++; //increment one to skip the x
            }
            if(command2[3+i] == 'a'){
                columnArray[i] = 0;
                i++;
            }else if(command2[3+i] == 'b'){
                columnArray[i] = 1;
                i++;
            }else if(command2[3+i] == 'c'){
                columnArray[i] = 2;
                i++;
            }else if(command2[3+i] == 'd'){
                columnArray[i] = 3;
                i++;
            }else if(command2[3+i] == 'e'){
                columnArray[i] = 4;
                i++;
            }else if(command2[3+i] == 'f'){
                columnArray[i] = 5;
                i++;
            }else if(command2[3+i] == 'g'){
                columnArray[i] = 6;
                i++;
            }else if(command2[3+i] == 'h'){
                columnArray[i] = 7;
                i++;
            }if(command2[3+i] == 0 || (command2[3+i] == 1) ||
          command2[3+i] == 2 ||command2[3+i] == 3 ||
          command2[3+i] == 4 || command2[3+i] == 5 ||
          command2[3+i] == 6 || command2[3+i] == 7){
            rowArray[i] = command2[3+i];
          //a-h down equal the columns
          //turns them into numbers
          //and then shove into an array
          //increment by i before looping back again
          nameArray[f] = 6; 
            i++;
            f++;
              }
          }else{
            //pawn is equal to one
            i = i + 2;
            if(command2[3 + i] == 'x'){
            i++; //increment one to skip the x
            }
            if(command2[3+i] == 'a'){
                columnArray[i] = 0;
                i++;
            }else if(command2[3+i] == 'b'){
                columnArray[i] = 1;
                i++;
            }else if(command2[3+i] == 'c'){
                columnArray[i] = 2;
                i++;
            }else if(command2[3+i] == 'd'){
                columnArray[i] = 3;
                i++;
            }else if(command2[3+i] == 'e'){
                columnArray[i] = 4;
                i++;
            }else if(command2[3+i] == 'f'){
                columnArray[i] = 5;
                i++;
            }else if(command2[3+i] == 'g'){
                columnArray[i] = 6;
                i++;
            }else if(command2[3+i] == 'h'){
                columnArray[i] = 7;
                i++;
            }if(command2[3+i] == 0 || (command2[3+i] == 1) ||
          command2[3+i] == 2 ||command2[3+i] == 3 ||
          command2[3+i] == 4 || command2[3+i] == 5 ||
          command2[3+i] == 6 || command2[3+i] == 7){
            rowArray[i] = command2[3+i];
          //a-h down equal the columns
          //turns them into numbers
          //and then shove into an array
          //increment by i before looping back again
          nameArray[f] = 1; 
            i++;
            f++;
              }
          }
        }
      }
      //i++;//increment 1//end of the inner while loop
      //now that everything is in a neat every 4 matrixes
    //still inside of the if statement
    //rowArray;
    //columnArray;
    for(int p = 0; p < 8; p++){
      for(int f = 0; f < 8; f++){
        if(nameArray[f] == 1 || nameArray[f] == 2 || 
        nameArray[f] == 3 || nameArray[f] == 4 || 
        nameArray[f] == 5 || nameArray[f] == 6 ||
        nameArray[i] == 7){
        board[rowArray[p]][columnArray[f]] = nameArray[f];
        printf("%d",nameArray[f]);  
        }else{
          board[p][f] = 0;
          printf("%d",0);
        }
      }printf("\n");
    }

    }else if (playerLastCharacter == '\n'){
            printf("Too few arguments for command! (you pressed enter) It must give a pre-game set up\n");
      while (lastCharacter != '\n')//skip the remainder of my invalid command...
                playerLastCharacter = getCommandWord(command2, 1000);
    }else if(playerLastCharacter == EOF){
      printf("You have entered the end of the file");
    }else{
      printf("you entered something wrong.");
    }//end this if section
}//end first while loop
      //make b equal to the amount of integers inside of the second array
      //b = b-n;   //moving this function to be placed before the 2nd while loop
    //getFirstPlayersLastName(secondLastNameArray, sizeof(command2[i-9]));
  //maybe put an eof here to start the next part of the program?
    b = b-n;
    //start game here
    //resetBoard(1);//normal start reset board moved up
    printf("Start the game using a mv command! Valid commands are quit, show, mv and cp.\n");
    
static void resetBoard(int number) {
    turn = WHITE;//WHITE moves first
    int i, j;
//-------------Original code----------------------
    for (i = 2; i < 6;i++)
       for (j = 0;j < 8;j++)
            board[i][j] = EMPTY;
//-----------------------------------------            
    //1 makes the board stay the same
    //if(number == 1){
    for (j = 0;j < 8;j++) {
        board[1][j] = BLACK * PAWN;
        board[6][j] = WHITE * PAWN;
      }
    board[0][0] = board[0][7] = BLACK * ROOK;
    board[7][0] = board[7][7] = WHITE * ROOK;
    board[0][1] = board[0][6] = BLACK * KNIGHT;
    board[7][1] = board[7][6] = WHITE * KNIGHT;
    board[0][2] = board[0][5] = BLACK * BISHOP;
    board[7][2] = board[7][5] = WHITE * BISHOP;
    board[0][3] = BLACK * QUEEN;
    board[7][3] = WHITE * QUEEN;
    board[0][4] = BLACK * KING;
    board[7][4] = WHITE * KING;
    //if number equils two then mirror board   
    }else if(number == 2){//flip board
    for (j = 0; j < 8; j++) {
        board[1][j] = WHITE * PAWN;
        board[6][j] = BLACK * PAWN;
    }  
    //inverse color of all pieces while keeping all numbers the same
    board[0][0] = board[0][7] = WHITE * ROOK;
    board[7][0] = board[7][7] = BLACK * ROOK;
    board[0][1] = board[0][6] = WHITE * KNIGHT;
    board[7][1] = board[7][6] = BLACK * KNIGHT;
    board[0][2] = board[0][5] = WHITE * BISHOP;
    board[7][2] = board[7][5] = BLACK * BISHOP;
    board[0][3] = WHITE * QUEEN;
    board[7][3] = BLACK * QUEEN;
    board[0][4] = WHITE * KING;
    board[7][4] = BLACK * KING;
  }
  else if(number ==3){//placing pieces all over the board

  }*/
