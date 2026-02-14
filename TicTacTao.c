
#include <stdio.h>
void system();
char board[] = {'0','1','2','3','4','5','6','7','8','9'};

void printbord();
int checkwinner();

int main()
{
    int player = 1, input, status = -1;
    char marks;

    while (status == -1)
    {
        marks = (player == 1) ? 'x' : 'o';

        printf("Please enter number for player %d: ", player);
        scanf("%d", &input);

        if (input < 1 || input > 9)
        {
            printf("Invalid input! Try again.\n");
            continue;
        }

        if (board[input] == 'x' || board[input] == 'o')
        {
            printf("Position already filled. Try again.\n");
            continue;
        }

        board[input] = marks;

        printbord();

        status = checkwinner();

        if (status == 1)
        {
            printf("Player %d is the winner!\n", player);
            break;
        }
        else if (status == 0)
        {
            printf("Game Draw!\n");
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    return 0;
}

void printbord()
{
    system("cls");
    printf("\n=== TIC TAC TOE ===\n\n");
    printf("   %c | %c | %c \n", board[1], board[2], board[3]);
    printf("  ---|---|---\n");
    printf("   %c | %c | %c \n", board[4], board[5], board[6]);
    printf("  ---|---|---\n");
    printf("   %c | %c | %c \n", board[7], board[8], board[9]);
    printf("\n");
}

int checkwinner()
{
    if (board[1]==board[2] && board[2]==board[3]) return 1;
    if (board[4]==board[5] && board[5]==board[6]) return 1;
    if (board[7]==board[8] && board[8]==board[9]) return 1;

    if (board[1]==board[4] && board[4]==board[7]) return 1;
    if (board[2]==board[5] && board[5]==board[8]) return 1;
    if (board[3]==board[6] && board[6]==board[9]) return 1;

    if (board[1]==board[5] && board[5]==board[9]) return 1;
    if (board[3]==board[5] && board[5]==board[7]) return 1;

    
    int count = 0;
    for (int i = 1; i <= 9; i++)
    {
        if (board[i] == 'x' || board[i] == 'o')
            count++;
    }
    if (count == 9)
        return 0;

    return -1;
}
