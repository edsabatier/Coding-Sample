#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Cipher.h"
#include "Letter.h"

using namespace std;

/*CONSTRUCTOR*/
Cipher::Cipher(string values, string ciphers){
  
  //first constructs knownLetters
  for(int i = 0; i < values.size(); i++){
    knownLetters.push_back(Letter(values.at(i), ciphers.at(i)));
    //testing code, prints letter pairs as it makes them
    //cout << knownLetters.at(i).getTrueValue() << ", " << knownLetters.at(i).getCipheredValue() << endl;
  }
  
  //next constructs true values of unknownTrueLetters, keeping track of individual indexes for values and the alphabet, 
  //as values will have letters missing
  string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int j = 0;
  for(int i = 0; i < alphabet.size(); i++){
    //cout << i << ", " << j << endl;
    if(j < values.size() && alphabet.at(i) == values.at(j)){
      //cout << values.at(j) << endl;
      j++;
    }else{
      unknownTrueLetters.push_back(alphabet.at(i));
      //testing code, prints unknown letters as they are discovered
      //cout << alphabet.at(i) << endl;
    }
  }
  
  alphabet = "abcdefghijklmonpqrstuvwxyz";
  for(int i = 0; i < alphabet.size(); i++){
    bool isKnown = false;
    for(int j = 0; j < ciphers.size(); j++){
      if(alphabet.at(i) == ciphers.at(j)){
        isKnown = true;
      }
    }
    if(!isKnown){
      unknownCipherLetters.push_back(alphabet.at(i));
    }
  }
}


/*SIMPLE ACCESSORS*/
vector<char> Cipher::getUnknownTrueLetters(){return unknownTrueLetters;}
vector<char> Cipher::getUnknownCipherLetters(){return unknownCipherLetters;}
vector<Letter> Cipher::getKnownLetters(){return knownLetters;}

void Cipher::print(){
  for(int i = 0; i < knownLetters.size(); i++){
    knownLetters.at(i).print();
  }
  
  for(int i = 0; i < unknownTrueLetters.size(); i++){
    cout << unknownTrueLetters.at(i) << endl;
  }
  
  for(int i = 0; i < unknownCipherLetters.size(); i++){
    cout << unknownCipherLetters.at(i) << endl;
  }
}


/*COMPLEX ACCESSORS*/
char Cipher::toCipher(char cha){
  for(int i = 0; i < knownLetters.size(); i++){
    if(knownLetters.at(i).getTrueValue() == cha){
      return knownLetters.at(i).getCipheredValue();
    }
  }
  
  //cout << "letter not known" << endl;
  return '?';
}

char Cipher::fromCipher(char cha){
  for(int i = 0; i < knownLetters.size(); i++){
    if(knownLetters.at(i).getCipheredValue() == cha){
      return knownLetters.at(i).getTrueValue();
    }
  }
  
  //cout << "letter not known" << endl;
  return '?';
}


/*MUTATORS*/
bool Cipher::decipherLetter(char value, char cipher){
  Letter let(value, cipher);
  
  //cout << "in" << endl;
  for(int i = 0; i < unknownTrueLetters.size(); i++){
    //cout << "unknownTrueLetters iterator: " << i << endl;
    if(unknownTrueLetters.at(i) == let.getTrueValue()){
      for(int j = 0; j < knownLetters.size()-1; j++){
        //cout << "knownLetters iterator: " << j << endl;
        if(let.getTrueValue() > knownLetters.at(j).getTrueValue() &&
          let.getTrueValue() < knownLetters.at(j + 1).getTrueValue()){
          knownLetters.insert(knownLetters.begin() + j + 1, let);
          unknownTrueLetters.erase(unknownTrueLetters.begin() + i);
          
          for(int t = 0; t < unknownCipherLetters.size(); t++){
            if(unknownCipherLetters.at(t) == let.getCipheredValue()){
              //cout << unknownCipherLetters.at(t) << endl;
              unknownCipherLetters.erase(unknownCipherLetters.begin() + t);
              t+=300;
            }
          }
          return true;
        }
      }
      knownLetters.push_back(let);
      unknownTrueLetters.erase(unknownTrueLetters.begin() + i);
      for(int t = 0; t < unknownCipherLetters.size(); t++){
        if(unknownCipherLetters.at(t) == let.getCipheredValue()){
           //cout << unknownCipherLetters.at(t) << endl;
           unknownCipherLetters.erase(unknownCipherLetters.begin() + t);
           t+=300;
        }
      }
      return true;
    }
  }
  
  return false;
}



















