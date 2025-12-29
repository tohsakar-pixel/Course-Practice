#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#define ROW 3
#define COL 3
#define ComputerThinking 3

// Initialize the board with empty spaces
void InitBoard(char board[ROW][COL], int row, int col);

// Print the board
void PrintBoard(char board[ROW][COL], int row, int col);

// Player's turn
void PlayerMove(char board[ROW][COL], int row, int col);

// Computer's turn
void ComputerMove(char board[ROW][COL], int row, int col);

// Check if the game is over
char GameOver(char board[ROW][COL], int row, int col);