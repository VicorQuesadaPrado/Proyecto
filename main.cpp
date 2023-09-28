#include <iostream>
#include <algorithm> // Necessary for std::shuffle
#include <random>    // Necessary for the random number generator
using namespace std;

// Game 1
class Card {
private:
    string color;
    string shape;
    bool wild;

public:

    // Set functions for color, shape, and wild

    void setColor(const string& newColor) {
        color = newColor;
    }

    void setShape(const string& newShape) {
        shape = newShape;
    }

    void setWild(bool newWild) {
        wild = newWild;
    }

    // Get functions for color, shape, and wild
    string getColor()  {
        return color;
    }

    string getShape()  {
        return shape;
    }

    bool isWild() {
        return wild;
    }

    Card(){

    };
    
    // Function that prints the cards, prints a single card according to its color and shape
    // Wild cards like +4 and color change will be black in color and +4/4 in shape
    void printCard(string color, string shape){
        if(color == "Black"){
            if(shape == "C"){
                // Print the color change card
            }
            else if(shape == "4"){
                // Print the +4 card
            }
        }
        else if(color == "Red"){
            if(shape == "0"){

            }
            else if(shape == "1"){

            }
            else if(shape == "2"){

            }
            else if(shape == "3"){

            }
            else if(shape == "4"){

            }
            else if(shape == "5"){

            }
            else if(shape == "6"){

            }
            else if(shape == "7"){

            }
            else if(shape == "8"){

            }
            else if(shape == "9"){

            }
            else if(shape == "S"){ // Skip turn

            }
            else if(shape == "R"){ // Reverse direction

            }
            else if(shape == "+2"){ // +2

            }

        }
        else if(color == "Yellow"){
            if(shape == "0"){

            }
            else if(shape == "1"){

            }
            else if(shape == "2"){

            }
            else if(shape == "3"){

            }
            else if(shape == "4"){

            }
            else if(shape == "5"){

            }
            else if(shape == "6"){

            }
            else if(shape == "7"){

            }
            else if(shape == "8"){

            }
            else if(shape == "9"){

            }
            else if(shape == "S"){ // Skip turn

            }
            else if(shape == "R"){ // Reverse direction

            }
            else if(shape == "+2"){ // +2

            }
        }
        else if(color == "Green"){
            if(shape == "0"){

            }
            else if(shape == "1"){

            }
            else if(shape == "2"){

            }
            else if(shape == "3"){

            }
            else if(shape == "4"){

            }
            else if(shape == "5"){

            }
            else if(shape == "6"){

            }
            else if(shape == "7"){

            }
            else if(shape == "8"){

            }
            else if(shape == "9"){

            }
            else if(shape == "S"){ // Skip turn

            }
            else if(shape == "R"){ // Reverse direction

            }
            else if(shape == "+2"){ // +2

            }
        }
        else if(color == "Blue"){
            if(shape == "0"){

            }
            else if(shape == "1"){

            }
            else if(shape == "2"){

            }
            else if(shape == "3"){

            }
            else if(shape == "4"){

            }
            else if(shape == "5"){

            }
            else if(shape == "6"){

            }
            else if(shape == "7"){

            }
            else if(shape == "8"){

            }
            else if(shape == "9"){

            }
            else if(shape == "S"){ // Skip turn

            }
            else if(shape == "R"){ // Reverse direction

            }
            else if(shape == "+2"){ // +2

            }
        }
    }
};

void fillMainDeck(Card deck[]){
    int index = 0;
    // Number cards from 0 to 9 (one of each color)
    for (int number = 0; number <= 9; ++number) {
        for (const string& color : {"Red", "Green", "Blue", "Yellow"}) {
            if (number == 0) {  // Only one "0" of each color
                deck[index].setColor(color);
                deck[index].setShape(to_string(number));
                index++;
            } else {  // Two copies of the other numbers
                for (int i = 0; i < 2; ++i) {
                    deck[index].setColor(color);
                    deck[index].setShape(to_string(number));
                    index++;
                }
            }
        }
    }
    // "+2" cards (wild)
    for (const string& color : {"Red", "Green", "Blue", "Yellow"}) {
        for (int i = 0; i < 2; ++i) {
            deck[index].setColor(color);
            deck[index].setShape("+2");
            deck[index].setWild(true);
            index++;
        }
    }
    // "S" cards (wild) - Skip turn
    for (const string& color : {"Red", "Green", "Blue", "Yellow"}) {
        for (int i = 0; i < 2; ++i) {
            deck[index].setColor(color);
            deck[index].setShape("S");
            deck[index].setWild(true);
            index++;
        }
    }
    // "R" cards (wild) - Reverse direction
    for (const string& color : {"Red", "Green", "Blue", "Yellow"}) {
        for (int i = 0; i < 2; ++i) {
            deck[index].setColor(color);
            deck[index].setShape("R");
            deck[index].setWild(true);
            index++;
        }
    }
    // "+4" cards (wild)
    for (int i = 0; i < 4; ++i) {
        deck[index].setColor("Black");
        deck[index].setShape("+4");
        deck[index].setWild(true);
        index++;
    }
    // "C" cards (wild) - Color change
    for (int i = 0; i < 4; ++i) {
        deck[index].setColor("Black");
        deck[index].setShape("C");
        deck[index].setWild(true);
        index++;
    }
}

void shuffleMainDeck(Card deck[]){
    // Get a random number generator
    random_device rd;
    mt19937 gen(rd());

    // Shuffle the cards randomly
    int numCards = 108;
    shuffle(deck, deck + numCards, gen);
}

void swap(Card *a, Card *b){
    Card x;
    x = *a;
    *a = *b;
    *b = x;
}

void dealCards(Card player1Hand[], Card player2Hand[], Card deck[]){
    int x = 107;
    int j = 107 - 8;
    for(int i = 0; i < 8; i++){
        swap(&player1Hand[i], &deck[x]);
        x--;
    }
    for(int i = 0; i < 8; i++){
        swap(&player2Hand[i], &deck[j]);
        j--;
    }
}

void sortHand(Card playerHand[]){
    int numCards = 108;
    int index = 0;
    // Move valid cards to the beginning of the vector
    for (int i = 0; i < numCards; ++i) {
        if (playerHand[i].getColor() != "") {
            // If the card has a valid color, move it to the beginning of the vector
            swap(playerHand[i], playerHand[index]);
            index++;
        }
    }
}

void addCardToHand(Card playerHand[], Card deck[]){
    int x = 0;
    int n1 = 0;
    if(deck[0].getColor() == ""){
        cout << "No more cards available" << endl;
    }
    for(int i = 0; i < 108; i++){
        if(playerHand[i].getColor() == ""){
            break;
        }
        n1++;
    }
    while(deck[x + 1].getColor() != "" && x < 107){
        x++;
        if(deck[x + 1].getColor() == "" && x < 107){
            swap(&playerHand[n1], &deck[x]);
        }
    }
}

void placeFirstCardOnTable(Card deck[], Card table){
    int x = 108 - 16;
    Card provisional;
    provisional = deck[x];
    deck[x] = table;
    table = provisional;
}

Card nextCardInDeck(Card deck[]){
    int numCards = 108;
    for(int i = 0; i < numCards; ++i){
        if(deck[i + 1].getColor() == ""){
            return deck[i];
        }
    }
}

void printPlayerCards(Card playerHand[]){
    int numCards = 108;
    for(int i = 0; i < numCards; ++i){
        if(playerHand[i + 1].getColor() == ""){
            break;
        }
        cout << "Card #" << i << ": ";
        cout << playerHand[i].getColor() << endl;
        cout << playerHand[i].getShape() << endl;
    }
}

int lastCardIndex(Card playerHand[]){
    int numCards = 108;
    for(int i = 0; i < numCards; ++i){
        if(playerHand[i + 1].getColor() == ""){
            return i + 1;
        }
    }
}

void playOrDrawCard(Card playerHand[], Card deck[], Card table, int n){
    if(table.isWild()){
        if(table.getShape() == "+4" && playerHand[n].getShape() != "+2" || playerHand[n].getShape() != "+4"){
            for(int i = 0; i < 4; i++){
                playerHand[lastCardIndex(playerHand)] = nextCardInDeck(deck);
            }
        }
    }
    else if(!table.isWild()){
        if(table.getColor() == playerHand[n].getColor() || table.getShape() == playerHand[n].getShape() || playerHand[n].getColor() == "Black"){
            Card emptyCard; // Null values
            table = playerHand[n];
            playerHand[n] = emptyCard;
        }
        else if(table.getColor() != playerHand[n].getColor() || table.getShape() != playerHand[n].getShape() || playerHand[n].getColor() != "Black" ){
            cout << "Enter a valid card" << endl;
        }
    }
}

void playerTurn(Card player1Hand[], Card player2Hand[], Card deck[], Card table, bool turn){
    int n;
    if(turn == true){ // If true, Player 1's turn
        printPlayerCards(player1Hand);
        cin >> n;
        playOrDrawCard(player1Hand, deck, table, n);
        turn = false;
    }
    else if(turn == false){ // If false, Player 2's turn
        printPlayerCards(player2Hand);
        cin >> n;
        playOrDrawCard(player2Hand, deck, table, n);
        turn = true;
    }
}

void game(Card player1Hand[], Card player2Hand[], Card deck[], Card table ){
    bool gameStatus = true;
    bool turn = true;
    fillMainDeck(deck);
    shuffleMainDeck(deck);
    dealCards(player1Hand, player2Hand, deck);
    placeFirstCardOnTable(deck, table);

    while(gameStatus){
        // Check if someone won (empty player1Hand or player2Hand)
        if (player1Hand[0].getColor() == "") {
            cout << "Player #1 has won" << endl;
            gameStatus = false;
        } else if (player2Hand[0].getColor() == "") {
            cout << "Player #2 has won" << endl;
            gameStatus = false;
        }
        
        int n = 0; // The player's card choice
        playerTurn(player1Hand, player2Hand, deck, table, turn);
        
    }
}

int main (int argc, char *argv[]) {
    Card deck[108];
    Card player1Hand[108];
    Card player2Hand[108];
    Card table;
    game(player1Hand, player2Hand, deck, table);
    return 0;
}
