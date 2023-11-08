#include<stdio.h>
#include<math.h>
#include<string.h>
#define MAX_COMMAND_TOKEN_LENGTH 6
#define WHITE 1
#define BLACK -1
typedef enum {
    EMPTY,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
}square;

typedef enum {
    NONE = 0,
    WHITE_SHORT = 1,
    WHITE_LONG = 2,
    BLACK_SHORT = 4,
    BLACK_LONG = 8
}castle;
extern square board[8][8];
extern int turn;
char getCommandWord(char command[], int maxLength);
extern int d, o, g;
handleShow(char* name1, char* name2, int d, int o, int g);
handleCapture();
handleMove();
handleAMove(char singleMove[]);
char* name1[100];//why???? i dont know, it works
char* name2[100];
//int p;
//char getFirstPlayersLastName(char name[],int k);
//char getSecondPlayersLastName(char name[],int k);
//char firstLastNameArray[500];
//char secondLastNameArray[500];
//char rowArray[1000];