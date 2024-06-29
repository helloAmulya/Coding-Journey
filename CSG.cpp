#include <iostream>
#include <limits>
#include <ctime>   // random number generation with current time
#include <cstdlib> // for rand() and srand()
using namespace std;

// Casino Number Guessing Game

void CgN()
{
    cout << "\n\t\t\tWelcome to the Casino Number Guessing Game!" << endl;
    cout << "\n\t\t\tI have choosen a number between 1-100." << endl;
    cout << "\n\t\t\tCan you guess what is it?" << endl;

    srand(static_cast<unsigned int>(time(0))); // random number generator with current time
    int numberTOguess = rand() % 100 + 1;      // generates random number between [1-100]

    int numberOfguess = 0; // guesses made
    int maxGuess = 10;     // guesses allowed
    int guess;             // guess to be made

    while (numberOfguess < maxGuess)
    { // loop till max number of guesses are reached
        cout << "Enter your guess: ";
        cin >> guess;
        if (cin.fail())
        {                                                        // checks for non integer value
            cin.clear();                                         // clears if found non interger value  to prevent infinite loop
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // will ignore the characters till correct input
            cout << "Invalid input. Please Enter an integer." << endl;
            continue;
        }
        numberOfguess++;

        // guessing the number
        if (guess < numberTOguess)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > numberTOguess)
        {
            cout << "Too High! Try again." << endl;
        }

        else
        {
            cout << "Congratulations! You've guessed the number right " << numberTOguess << " in " << numberOfguess << " attempts." << endl;
            break;
        }
    }

    if (numberOfguess == maxGuess && guess != numberTOguess)
    {
        cout << "Sorry you are out of guesses, The numnber was " << numberTOguess << ", Better luck next time!"
             << endl;
    }
}

int main()
{
    CgN();
    return 0;
}