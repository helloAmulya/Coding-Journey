#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// rock paper scissor game

char getcomputerMove()
{
    int move;
    srand(time(NULL));
    move = rand() % 3;

    if (move == 0)
    {
        return 'p';
    }
    else if (move == 1)
    {
        return 's';
    }
    return 'r';
}

int getResult(char playerMove, char computerMove)
{
    if (playerMove == computerMove)
    {
        cout << "Both Morons do another move, TIE!";
        return 0;
    }

    if (playerMove == 's' && computerMove == 'p')
    {
        return 0;
    }
    if (playerMove == 's' && computerMove == 'r')
    {
        return -1;
    }
    if (playerMove == 'p' && computerMove == 'r')
    {
        return 0;
    }
    if (playerMove == 'p' && computerMove == 's')
    {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 's')
    {
        return 0;
    }
    if (playerMove == 'r' && computerMove == 'p')
    {
        return -1;
    }

    return 0;
}

int main()
{
    char playerMove;

    cout << "\n\n\n\t\t\tWelcome to Rock Papern Scissor "
            "Game\n";
    cout << "\n\t\tEnter r for ROCK, p for PAPER,and s "
            "for Scissor \n\t\t\t\t\t";
    "Game\n";

    while (1)
    {
        cin >> playerMove;
        if (playerMove == 'p' || playerMove == 'r' || playerMove == 's')
        {
            break;
        }
        else
        {
            cout << "\t\t\tInvalid Player Move !!!   Please Try Again." << endl;
        }
    }

    char computerMove = getcomputerMove();
    int result = getResult(playerMove, computerMove);

    if (result == 0)
    {
        cout << "\n\t\t\tCongratulations! Player won the "
                "game\n";
    }
    else
    {
        cout << "\n\t\t\tComputer Won the game!, You LOSER\n";
    }

    cout << "\t\t\tYour Move: " << playerMove << endl;
    cout << "\t\t\tComputer's Move: " << computerMove << endl;

    return 0;
}