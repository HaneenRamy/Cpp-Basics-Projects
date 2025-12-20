#include <iostream>
#include <string>   // to treat numbers as strings
using namespace std;

int main() {
    string HostNum, GuestNum;

    cout << "Please enter a number: ";
    cin >> HostNum;
    system("cls"); //clears the screen 

    do {
        cout << "Please enter your guess number: ";
        cin >> GuestNum;

        // Ensure both numbers have the same length
        if (GuestNum.length() != HostNum.length()) {
            cout << "Your guess must have " << HostNum.length() << " digits!\n";
            continue;
        }

        int correctPlace = 0;
        int correctNumber = 0;
        bool countedHost[10] = { false }; // to prevent double counting

        // Check for correct positions first
        for (int i = 0; i < HostNum.length(); i++) {
            if (GuestNum[i] == HostNum[i]) {
                correctPlace++;
                countedHost[i] = true;
            }
        }

        // Check for correct but misplaced digits
        for (int i = 0; i < GuestNum.length(); i++) {
            if (GuestNum[i] != HostNum[i]) {
                for (int j = 0; j < HostNum.length(); j++) {
                    if (!countedHost[j] && GuestNum[i] == HostNum[j]) {
                        correctNumber++;
                        countedHost[j] = true;
                        break;
                    }
                }
            }
        }

        if (GuestNum == HostNum) {
            cout << "Correct! You guessed it!\n";
        }
        else {
            cout << correctPlace << " number(s) correct and in the right place, "
                << correctNumber << " number(s) correct but misplaced.\n\n";
        }

    } while (GuestNum != HostNum);

    return 0;
}
