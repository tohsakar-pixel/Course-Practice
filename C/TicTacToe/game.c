#include "head.h"

// Initialize the board with empty spaces
void InitBoard(char board[ROW][COL], int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            board[i][j] = ' ';
        }
    }
}

// Print the board
void PrintBoard(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++) 
    {
       for (int j = 0; j < col; j++)
       {
            printf(" %c ", board[i][j]);
            if (j < col - 1)
                printf("|");
       }
       printf("\n");

       if (i < row - 1)
       {
            for (int j = 0; j < col; j++)
            {
                printf("---");
                if (j < col - 1)
                    printf("+");
            }
            printf("\n");
       }
    }
}

// Player's turn
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("< Player Round >\n");
    printf("< Enter your move: >\n");

    while (1)
    {
        scanf("%d %d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (board[x - 1][y - 1] == ' ')
            {
                board[x - 1][y - 1] = 'X';
                break;
            }
            else
            {
                printf("< Invalid move, try again. >\n");
            }
        }
        else
        {
            printf("< Invalid move, try again. >\n");
        }
    }
}

// Computer's turn
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int step = 0;
    printf("< Computer is thinking... >\n");
    sleep(ComputerThinking);
    system("clear");
    printf("< Computer Round >\n");
    // smart computer
    // row
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == 'O' && board[i][2] == ' ')
        {
            board[i][2] = 'O';
            step++;
            return;
        }
        if (board[i][0] == board[i][2] && board[i][2] == 'O' && board[i][1] == ' ')
        {
            board[i][1] = 'O';
            step++;
            return;
        }
        if (board[i][1] == board[i][2] && board[i][2] == 'O' && board[i][0] == ' ')
        {
            board[i][0] = 'O';
            step++;
            return;
        }
    }

    //col
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == 'O' && board[2][i] == ' ')
        {
            board[2][i] = 'O';
            step++;
            return;
        }
        if (board[0][i] == board[2][i] && board[2][i] == 'O' && board[1][i] == ' ')
        {
            board[1][i] = 'O';
            step++;
            return;
        }
        if (board[1][i] == board[2][i] && board[2][i] == 'O' && board[0][i] == ' ')
        {
            board[0][i] = 'O';
            step++;
            return;
        }
    }

    //diagonal
    if (board[0][0] == board[1][1] && board[1][1] == 'O' && board[2][2] == ' ')
    {
        board[2][2] = 'O';
        step++;
        return;
    }
    if (board[0][0] == board[2][2] && board[2][2] == 'O' && board[1][1] == ' ')
    {
        board[1][1] = 'O';
        step++;
        return;
    }
    if (board[1][1] == board[2][2] && board[2][2] == 'O' && board[0][0] == ' ')
    {
        board[0][0] = 'O';
        step++;
        return;
    }

    // anti player
    // row
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == 'X' && board[i][2] == ' ')
        {
            board[i][2] = 'O';
            step++;
            return;
        }
        if (board[i][0] == board[i][2] && board[i][2] == 'X' && board[i][1] == ' ')
        {
            board[i][1] = 'O';
            step++;
            return;
        }
        if (board[i][1] == board[i][2] && board[i][2] == 'X' && board[i][0] == ' ')
        {
            board[i][0] = 'O';
            step++;
            return;
        }
    }
    

    // col
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == 'X' && board[2][i] == ' ')
        {
            board[2][i] = 'O';
            step++;
            return;
        }
        if (board[0][i] == board[2][i] && board[2][i] == 'X' && board[1][i] == ' ')
        {
            board[1][i] = 'O';
            step++;
            return;
        }
        if (board[1][i] == board[2][i] && board[2][i] == 'X' && board[0][i] == ' ')
        {
            board[0][i] = 'O';
            step++;
            return;
        }
    }

    // diagonal
    if (board[0][0] == board[1][1] && board[1][1] == 'X' && board[2][2] == ' ')
    {
        board[2][2] = 'O';
        step++;
        return;
    }
    if (board[0][0] == board[2][2] && board[2][2] == 'X' && board[1][1] == ' ')
    {
        board[1][1] = 'O';
        step++;
        return;
    }
    if (board[1][1] == board[2][2] && board[2][2] == 'X' && board[0][0] == ' ') 
    {
        board[0][0] = 'O';
        step++;
        return;
    }

    // Random move
    if (step == 0)
    {
        int x, y;
        while (1)
        {
            x = rand()%row;
            y = rand()%col;

            if (board[x][y] == ' ')
            {
                board[x][y] = 'O';
                break;
            }
        }
    }
}

// Check if the game is over
// Player win - X
// Computer win - O
// Draw - Q
// Continue - C
char GameOver(char board[ROW][COL], int row, int col)
{
    //row
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][1];
        }
    }
    
    //col
    for (int i = 0; i < col; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[1][i];
        }
    }
    
    //diagonal
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[1][1];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return board[1][1];
    }
    
    //draw
    int count = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 'O' || board[i][j] == 'X')
            {
                count++;
            }
        }
    }
    if (count == ROW * COL)
    {
        return 'Q';
    }

    // continue
    return 'C';
}


