#ifndef CIPHER
#define CIPHER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "TextHandler.h"
#include "Letter.h"

using namespace std;

class Cipher{
  private:
    /*INSTANCE VARIABLES*/
    //contains the true values of all letters unaccounted for
    vector<char> unknownTrueLetters;
    vector<char> unknownCipherLetters;
    //contains the true and ciphered values of all known letters
    vector<Letter> knownLetters;
    
  public:
    /*CONSTRUCTORS*/
    Cipher(string values, string ciphers);
  
  
    /*SIMPLE ACCESSORS*/
    vector<char> getUnknownTrueLetters();
    vector<char> getUnknownCipherLetters();
    vector<Letter> getKnownLetters();
    void print();
  
    /*COMPLEX ACCESSORS*/
    //given true value, puts out encrypted value
    char toCipher(char cha);
    //given encrypted value, puts out true value
    char fromCipher(char cha);
    
  
    /*MUTATORS*/
    //if value is not already known, creates new letter and attempts to put it into knownLetters
    //in alphabetical order, if knownLetters is already alphabetized. Also removes from unknownLetters
    //if value is already known, returns false
    bool decipherLetter(char value, char cipher);
};

#endif