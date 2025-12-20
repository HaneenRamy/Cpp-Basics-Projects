#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int computerChoice, userChoice;

    // Display game instructions
    cout << "Rock Paper Scissors Game!\n";
    cout << "1 = Rock, 2 = Paper, 3 = Scissors\n";

    // Main game loop
    while (true) {
        // Get user input
        cout << "Enter your choice (1-3) or 0 to quit: ";
        cin >> userChoice;

        // Exit condition
        if (userChoice == 0) {
            cout << "Thanks for playing!\n";
            break;
        }

        // Validate user input
        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        // Generate random choice for the computer
        computerChoice = rand() % 3 + 1;

        // Display computer's choice
        cout << "Computer chose: ";
        if (computerChoice == 1) cout << "Rock\n";
        else if (computerChoice == 2) cout << "Paper\n";
        else cout << "Scissors\n";

        // Determine game result
        if (userChoice == computerChoice)
            cout << "It's a tie!\n";
        else if ((userChoice == 1 && computerChoice == 3) ||
            (userChoice == 2 && computerChoice == 1) ||
            (userChoice == 3 && computerChoice == 2))
            cout << "You win!\n";
        else
            cout << "You lose!\n";

        cout << "\n";
    }

    return 0;
}
