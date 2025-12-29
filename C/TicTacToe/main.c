#include "head.h"

void menu()
{
    printf("Welcome to play chess game!\n");
    printf("**********************\n");
    printf("*** 1.start 0.exit ***\n");
    printf("**********************\n");
}

void game()
{
    char ret = 0;
    printf("< GAME START >\n");
    char board[ROW][COL] = {0};
    InitBoard(board, ROW, COL);
    PrintBoard(board, ROW, COL);

    while (1)
    {
        PlayerMove(board, ROW, COL);
        ret = GameOver(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        system("clear");
        printf("< Player Round >\n");
        PrintBoard(board, ROW, COL);
        
        ComputerMove(board, ROW, COL);
        ret = GameOver(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        PrintBoard(board, ROW, COL);
    }
    
    if (ret == 'X')
    {
        system("clear");
        printf("< You win! >\n");
    }
    else if (ret == 'O')
    {
        system("clear");
        printf("< You lose! >\n");
    }
    else
    {
        system("clear");
        printf("< Draw! >\n");
    }
    PrintBoard(board, ROW, COL);
    printf("\n");
    printf("< GAME OVER >\n");
}

int main()
{
    srand((unsigned int)time(NULL));
    int input;
    do
    {
        menu();
        printf("< Please input your choice: >");
        scanf("%d", &input);
        system("clear");
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("< EXIT > \n");
            break;
        default:
            printf("< ERROR >\n");
            break;
        }
    } while (input);
    return 0;
}
