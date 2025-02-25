#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

// Card structure
struct Card {
    string rank;
    string suit;
    int value;
};

// Function to create a deck of cards
vector<Card> createDeck() {
    vector<Card> deck;
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};

    for (int s = 0; s < 4; s++) {
        for (int r = 0; r < 13; r++) {
            deck.push_back({ranks[r], suits[s], values[r]});
        }
    }
    return deck;
}

// Function to shuffle the deck
void shuffleDeck(vector<Card>& deck) {
    random_device rd;   // Get a random seed from the hardware
    mt19937 g(rd());    // Mersenne Twister PRNG (better randomness)
    shuffle(deck.begin(), deck.end(), g); // Use modern shuffle
}

// Function to calculate the total hand value
int calculateHandValue(vector<Card>& hand) {
    int total = 0;
    int aceCount = 0;

    for (Card card : hand) {
        total += card.value;
        if (card.rank == "A") {
            aceCount++;
        }
    }

    // Adjust for Aces (11 -> 1 if needed)
    while (total > 21 && aceCount > 0) {
        total -= 10;
        aceCount--;
    }

    return total;
}

// Function to display a hand
void displayHand(string name, vector<Card>& hand) {
    cout << name << "'s Hand: ";
    for (Card card : hand) {
        cout << "[" << card.rank << " of " << card.suit << "] ";
    }
    cout << " (Total: " << calculateHandValue(hand) << ")" << endl;
}

// Main game function
void playBlackjack() {
    vector<Card> deck = createDeck();
    shuffleDeck(deck);

    vector<Card> playerHand, dealerHand;

    // Initial deal (2 cards each)
    playerHand.push_back(deck.back()); deck.pop_back();
    dealerHand.push_back(deck.back()); deck.pop_back();
    playerHand.push_back(deck.back()); deck.pop_back();
    dealerHand.push_back(deck.back()); deck.pop_back();

    cout << "==================== BLACKJACK ====================\n";
    displayHand("Player", playerHand);
    cout << "Dealer's Hand: [" << dealerHand[0].rank << " of " << dealerHand[0].suit << "] [Hidden Card]" << endl;

    // Player turn
    char choice;
    while (calculateHandValue(playerHand) < 21) {
        cout << "\nDo you want to (h)it or (s)tand? ";
        cin >> choice;

        if (choice == 'h' || choice == 'H') {
            playerHand.push_back(deck.back());
            deck.pop_back();
            displayHand("Player", playerHand);
            if (calculateHandValue(playerHand) > 21) {
                cout << "Bust! You lose.\n";
                return;
            }
        } else if (choice == 's' || choice == 'S') {
            break;
        } else {
            cout << "Invalid choice. Enter 'h' to hit or 's' to stand.\n";
        }
    }

    // Dealer's turn (reveals hidden card)
    cout << "\nDealer reveals second card: ";
    displayHand("Dealer", dealerHand);

    while (calculateHandValue(dealerHand) < 17) {
        cout << "Dealer hits...\n";
        dealerHand.push_back(deck.back());
        deck.pop_back();
        displayHand("Dealer", dealerHand);
    }

    int playerScore = calculateHandValue(playerHand);
    int dealerScore = calculateHandValue(dealerHand);

    // Determine winner
    if (dealerScore > 21 || playerScore > dealerScore) {
        cout << "Congratulations! You win!\n";
    } else if (playerScore == dealerScore) {
        cout << "It's a tie!\n";
    } else {
        cout << "Dealer wins! Better luck next time.\n";
    }
}

// Main function
int main() {
    char playAgain;
    do {
        playBlackjack();
        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Blackjack!\n";
    return 0;
}
