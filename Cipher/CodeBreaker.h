#ifndef CODE_BREAKER
#define CODE_BREAKER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <limits>

#include "Cipher.h"
#include "TextHandler.h"
#include "Letter.h"

using namespace std;

class CodeBreaker{
  private:
    Cipher puzzle;
    string keyword;
    string sentence;
  public:
    CodeBreaker(string knownLetters, string cipherLetters, string key, string sent);
    
    /*ACCESSORS*/
    string getSentence();
    string getKeyword();
    Cipher getPuzzle();
  
  
    //returns unencrypted puzzle
    string solve();
  
    //solves with known information
    void attempt();
  
    //identifies keyword, then uses keyword to solve letters
    void solveKeyword();
    
    //if keyword did not solve everything, randomly assigns remaining unknown true values to 
    //unknown encrypted values
    void randomSolve();
  
    //takes match for keyword and uses it to decipher letters
    void keywordSolved(string encoded);
};



















#endif