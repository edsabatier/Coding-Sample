#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <limits>

#include "Cipher.h"
#include "Letter.h"
#include "CodeBreaker.h"

using namespace std;

/*CONSTRUCTOR*/
CodeBreaker::CodeBreaker(string knownLetters, string cipherLetters, string key, string sent):
  puzzle(knownLetters, cipherLetters)
{
  keyword = key;
  sentence = sent;
}


/*ACCESSORS*/
string CodeBreaker::getSentence(){return sentence;}
string CodeBreaker::getKeyword(){return keyword;}
Cipher CodeBreaker::getPuzzle(){return puzzle;}


string CodeBreaker::solve(){
  attempt();
  solveKeyword();
  attempt();
  randomSolve();
  
  attempt();
  return sentence;
}

void CodeBreaker::attempt(){
  for(int i = 0; i < sentence.size(); i++){
    string str = string(1, puzzle.fromCipher(sentence.at(i)));
    if(str.at(0) != '?'){
      //cout << str << endl;
      sentence.replace(sentence.begin() + i, sentence.begin() + i + 1, string(1, puzzle.fromCipher(sentence.at(i))));
    }
  }
}

void CodeBreaker::randomSolve(){
  for(int i = 0; i < puzzle.getUnknownTrueLetters().size(); i++){
    cout << puzzle.getUnknownTrueLetters().at(i) << ", " << puzzle.getUnknownCipherLetters().at(i) << endl;
  }
  
  while(!puzzle.getUnknownTrueLetters().empty() && !puzzle.getUnknownCipherLetters().empty()){
    cout << puzzle.getUnknownTrueLetters().at(0) << ", " << puzzle.getUnknownCipherLetters().at(0) << endl;
    puzzle.decipherLetter(puzzle.getUnknownTrueLetters().at(0), puzzle.getUnknownCipherLetters().at(0));
  }
}

void CodeBreaker::solveKeyword(){
  istringstream iss(sentence);
  vector<string> words((istream_iterator<string>(iss)), istream_iterator<string>());
  
  int i = 0;
  while(i < words.size()){
    if(words.at(i).size() != keyword.size()){
      words.erase(words.begin() + i);
    }else{
      i++;
    }
  }
  
  cout << "a" << endl;
  if(!words.empty() && words.size() <= 1){
    cout << words.at(0) <<  ", " << keyword << endl;
    keywordSolved(words.at(0));
    return;
  }
  cout << "b" << endl;
  
  i = 0;
  while(i < words.size()){
    int startingSize = words.size();
    int size = words.at(i).size();
    
    for(int j = 0; j < size; j++){
      if(isupper(words.at(i).at(j)) && words.at(i).at(j) != keyword.at(j)){
        words.erase(words.begin() + i);
        j = numeric_limits<int>::max() - 1;
      }
    }
    
    if(startingSize == words.size()){
      i++;
    }
  }
  
  cout << words.at(0) << ", " << keyword << endl;
  keywordSolved(words.at(0));
  return;
}

void CodeBreaker::keywordSolved(string encoded){
  for(int i = 0; i < encoded.size(); i++){
    cout << keyword.at(i) << encoded.at(i) << endl;
    puzzle.decipherLetter(keyword.at(i), encoded.at(i));
  }
}












