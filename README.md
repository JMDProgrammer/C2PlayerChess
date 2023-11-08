# C2PlayerChess
A two player chess game in C (programming language)

(--->) Command-Line Arguments and Options (<---)


(->) -w name: gets the string name as the given name of the player playing with white
pieces. This name will be displayed close to rank 1 of the board when the board gets
printed on the screen during the program.

(->) -b name: gets the string name as the given name of the player playing with black
pieces. This name will be displayed close to rank 8 of the board when the board gets
printed on the screen during the program.

(->) -r: changes the default orientation of the chess board when being printed on the screen
during the program. Without this option, when the program displays the board on
the screen, the ranks of the board are displayed in the order 8, 7, 6, . . . , 1 and the files
are displayed in the order a, b, c, . . . , h. However, using ‘-r’ option, the ranks (files)
are displayed in the reverse order: 1, 2, . . . , 8 (h, g, f, . . . , a).

(->) -i game: imports a game where game is a string made of a sequence of moves/captures
separated by comma.

(->) -t time: gets the time limit for both players (w/o increment) where time is an inte-
ger specifying the limit in minutes. Enforcing time limit is the optional part of the
assignment.

(--->)Program Commands(<---)


(->) mv α0β0 α1β1: moves the piece in cell with label α0β0 to cell with label α1β1 where α0
and α1 can be letters from a to h; while β0 and β1 can be integers from 1 to 8.
 cp α0β0 α1β1: captures the piece in cell with label α1β1 with the piece in cell α0β0
where α0 and α1 can be letters from a to h; while β0 and β1 can be integers from 1 to
8.

(->) show: prints out the content of the 2D array on the screen in the form of a table like
this (the ranks 1,2,..., 8 and files a, b, ..., h must be printed as well )

(--->)how to run(<---)

(->) make the file with make

make

(->) then run the chess.c file by typing something like:

./chess -w firstPlayer -b secondPlayer

#then more prompts will pop up with instructions

(->) if the game is still not working gcc it:

gcc ./chess (#with options)

---> any questions, ask <---

