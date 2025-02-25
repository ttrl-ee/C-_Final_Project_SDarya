# C-_Final_Project_SDarya
This mini-game allows you to play Blackjack directly in the terminal without using third-party libraries. It includes the basic rules of the game:

A deck of 52 cards, randomly shuffled before the game.
The player and the dealer are each dealt 2 cards.
The player can take a card (‘Hit’) or stop (‘Stand’).
Dealer plays according to standard rules (takes cards until he has < 17 points).
Automatic determination of the winner according to standard Blackjack rules.

What might this mini-game be used for?
✅ Entertainment - You can just play a card game and test your luck!
✅ Educational purposes - The game will help beginner C++ developers to learn how to work with:

Vectors (std::vector), structure (struct) and loops.
Random number generation (std::shuffle, std::mt19937).
Functions and processing of user input (cin / cout).
✅ AI development - You can add a dealer strategy or create a player bot.
✅ Gambling Fundamentals - A great option for learning the logic of gambling without the risk of losing money.

How to start the game?
1. Compile the code (G++)
g++ -std=c++17 blackjack.cpp -o blackjack

2. Run the game
./blackjack
