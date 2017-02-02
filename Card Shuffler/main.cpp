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
#include <assert.h>
#include <stdio.h>
#include <fstream>

using namespace std;


class card{  // instance of card
public:
    int suit;
    int number;
};


void deck_shuffle(vector<card>* pdeck){    // shuffles the deck
    int iterations = 10000; // number of iterations
    for(int n = 0; n<iterations; n++){
    int s1 = rand() % pdeck->size();
    int s2 = rand() % pdeck->size();
    
    card hand;
        hand = pdeck->at(s1);
        pdeck->at(s1) = pdeck->at(s2);
        pdeck->at(s2) = hand;
    }
}


void showdeck(vector<card>* pdeck){   // function for outputting deck to console
    //int num_suits = 52;
    //int num_numbers = 1;
    for(int i=0; i<pdeck->size(); i++){
        //for(int j=0; j<num_numbers; j++){
            cout << "Index: " << i << " Suit: "<< pdeck->at(i).suit << " Num: "<< pdeck->at(i).number << endl;
        //}
    }
}

void testA(vector<card>* pdeck){
    if(pdeck->size()>53){
        cout << "Test A Will Fail with More than one deck, skipping test A" << endl;
    }
    else {
    card A;
    card B;
    for(int j=0; j<pdeck->size(); j++){
    A.suit = pdeck->at(j).suit;
        A.number = pdeck->at(j).number;
    for(int i= j+1; i<pdeck->size(); i++){
        B.suit = pdeck->at(i).suit;
        B.number = pdeck->at(i).number;
    bool suitissame = false;
    bool numissame = false;
    bool isidenticle = false;
    
    if(A.suit == B.suit){
        suitissame = true;
    }
    if( A.number == B.number){
        numissame =true;
    }
    if(suitissame && numissame){
        isidenticle = true;
    }
    
    if( isidenticle == true){
        // cout << "Is Identicle" << endl;
        
    }
    else{
        // cout << "not identicle" << endl;
    }
    assert (isidenticle == false);

    }
    }
    cout << "Test A Passed" << endl;
    }
}

void testB(vector<card>* pdeck){
    if(pdeck->size()<53){
        cout << "Test B Will Fail only one deck, skipping test B" << endl;
    }
    else {
        card A;
        card B;
        int count = 0;
            A.suit = pdeck->at(0).suit;
            A.number = pdeck->at(0).number;
            for(int i= 1; i<pdeck->size(); i++){
                B.suit = pdeck->at(i).suit;
                B.number = pdeck->at(i).number;
                
                bool suitissame = false;
                bool numissame = false;
                bool isidenticle = false;
                
                if(A.suit == B.suit){
                    suitissame = true;
                }
                if(A.number == B.number){
                    numissame = true;
                }
                if( numissame&&suitissame){
                    count++;
                }
                else{
                    //cout << "No identical cards" << endl;
                }
            
            }
        int n = pdeck->size() / 52;
        assert(count = n);
        cout << "There are " << n << " multiples of " << pdeck->at(0).suit << "\t" << pdeck->at(0).number << " in the shuffled deck" << endl;
    }
}

int main() {
    srand(time(NULL));
    vector<card> deck;
    cout << "Main Start" << endl;
    int num_decks = 1;          // Number of Decks
    int num_suits = 4;
    int num_numbers = 13;
    for( int N=0; N<num_decks; N++){
    for(int i=0; i<num_suits; i++){     // creating deck
        for(int j=0; j<num_numbers; j++){
            card temp_c;
            temp_c.suit=i;
            temp_c.number=j+1;
            deck.push_back(temp_c);
        }
    }
    }
    cout << "Initial Deck Created" << "\n" << "Total Cards: \t" << deck.size() << endl;
    
    vector<card>* pdeck = &deck;
    
    
    
    deck_shuffle(pdeck);
    cout << "Deck shuffled" << endl;
    testA(pdeck);
    testB(pdeck);
    
    
    ofstream outputFile;  //Creating Output text file and copying the shuffled deck to it
    outputFile.open("deckout.txt");
    if(outputFile.is_open()){
    outputFile << "test" << endl;
    for(int i=0; i<pdeck->size(); i++){
    outputFile << "Index: " << i << " Suit: "<< pdeck->at(i).suit << " Num: "<< pdeck->at(i).number << endl;
        }
    }
    else{
        cout << "Output File Error" << endl;
    }
    outputFile.close();
}
