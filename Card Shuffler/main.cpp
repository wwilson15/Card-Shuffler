//
//  main.cpp
//  Card Shuffler
//
//  Created by Wade Wilson on 1/31/17.
//  Copyright © 2017 Wade Wilson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


class card{  // instance of card
public:
    int suit;
    int number;
};


void deck_shuffle(vector<card>* pdeck){    // shuffles the deck
    int iterations = 5000; // number of iterations
    for(int n = 0; n<iterations; n++){
    int s1 = rand() % 4;
    int s2 = rand() % 4;
    int c1 = rand() % 13;
    int c2 = rand() % 13;
    
    card hand;
    hand.suit = pdeck->at(s1).suit;             //suit of random card 1 to hand
    hand.number = pdeck->at(c1).number;       //number of random card one into hand
    pdeck->at(s1).suit = pdeck->at(s2).suit; //replaces suit of random card 1 with suit of random card 2
    pdeck->at(c1).number = pdeck->at(c2).number; // replace number of random card 1 with random card 2
    pdeck->at(s2).suit = hand.suit;          // suit of random card 2 replaced with suit of card in hand
    pdeck->at(c2).number = hand.number;     // number of random card 2 repalce with number of card in hand
    
    }
}

void printdeck(vector<card>* pdeck){  // will print the deck to a text file
}

void showdeck(vector<card>* pdeck){   // function for outputting deck to console
    int num_suits = 4;
    int num_numbers = 13;
    for(int i=0; i<num_suits; i++){
        for(int j=0; j<num_numbers; j++){
            cout << pdeck->at(i).suit << "\t"<< pdeck->at(j).number << endl;
        }
    }
}

int main() {
    srand(time(NULL));
    vector<card> deck;
    
    int num_suits = 4;
    int num_numbers = 13;
    for(int i=0; i<num_suits; i++){     // creating deck
        for(int j=0; j<num_numbers; j++){
            card temp_c;
            temp_c.suit=i;
            temp_c.number=j;
            deck.push_back(temp_c);
            cout << temp_c.suit << endl;
        }
    }
    cout << deck.size() << endl;
    
    vector<card>* pdeck = &deck;
    
    showdeck(pdeck);
    
    deck_shuffle(pdeck);

    
}
