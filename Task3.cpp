#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Seed for random number generation

    int attempt = 10;
    int randomNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;

    cout << "Enter your guess: ";
    cin >> guess;

    while (attempt > 0 && guess != randomNumber) {
        attempt--;
        if (guess < randomNumber) {
            cout << "Your guess is too low. Try again. ";
        } else {
            cout << "Your guess is too high. Try again. ";
        }
        cout << "Remaining attempts: " << attempt << endl;
        cin >> guess;
    }

    if (guess == randomNumber) {
        cout << "Congratulations! You guessed the correct number." << endl;
    } else {
        cout << "Sorry, you have run out of attempts. The correct number was " << randomNumber << "." << endl;
    }

    return 0;
}
