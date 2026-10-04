#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>
using namespace std;

// this program will ask user to play guessing game
int main () {

    // initialize ask user to play game
    string userName;
    char ans;
    int gamesPlayed = 0;
    cout << "What is your name?\n\n> ";
    cin >> userName;
    userName.at(0) = toupper(userName.at(0));
    cout << "\nHello, " << userName << ". Do you want to play a game? (y/n)\n\n> ";
    cin >> ans;

    // error checking y/n
    while (tolower(ans) != 'y' && tolower(ans) != 'n') {

        cout << "\nInvalid response. Please enter 'y' for yes or 'n' for no.\n\n> ";
        cin >> ans;
    }

    // user entered yes; start game
    while (tolower(ans) == 'y') {
        
        // initialize and calculate random number
        int randNum, userInput;
        int counter = 0;
        srand(static_cast <unsigned int>(time(0)));
        randNum = (rand() % 20) + 1;

        // describe game and prompt for guess
        cout << "\nAwesome! I have a number in mind from 1 to 20.\nTry to guess.\n\n> ";
        cin >> userInput;

        // user guessed wrong
        while (userInput != randNum) {
            
            // out of range
            while (userInput < 1 || 20 < userInput) {

                cout << "\nYour guess is out of range. Please enter a number from 1 to 20\n\n> ";
                cin >> userInput;
            }
            // guess too low
            if (userInput < randNum) {

                counter ++;
                cout << "\nYour guess is too LOW. Guess again!\n\n> ";
                cin >> userInput;
            }
            // guess too high
            else if (userInput > randNum) {

                counter ++;
                cout << "\nYour guess is too HIGH. Guess again!\n\n> ";
                cin >> userInput;
            }
        }
            
        // correct guess
        counter ++;
        gamesPlayed ++;

        if (counter == 1) {
            cout << "\nYou have guessed " << randNum << " correctly in 1 try! Amazing work!\n";
        }
        else {
            cout << "\nYou have guessed " << randNum << " correctly in " << counter << " tries! Nice!\n";
        }

        // ask user to play again (error checking y/n)
        cout << "Would you like to play again? (y/n)\n\n> ";
        cin >> ans;

        while (tolower(ans) != 'y' && tolower(ans) != 'n') {

            cout << "\nInvalid response. Please enter 'y' for yes or 'n' for no.\n\n> ";
            cin >> ans;
        }
    }

    // goodbye
    if (gamesPlayed == 0) {

        cout << "\nNo worries. Have a great day, " << userName << "!\n\n\n";
    }
    else {

        cout << "\nThanks for playing, " << userName << ". Have a great day!\n\n\n";
    }

    return 0;
}