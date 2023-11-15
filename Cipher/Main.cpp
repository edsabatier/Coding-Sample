#include <iostream>
#include <string>
#include <algorithm>

#include "TextHandler.h"
#include "CodeBreaker.h"
#include "Cipher.h"
#include "Letter.h"

using namespace std;

int main(int argc, char **argv){
  vector<string> cipher = TextHandler::unpackTxtFile(argv[1]);
  vector<string> sentence = TextHandler::unpackTxtFile(argv[2]);
  string keyword(argv[3]);
  
  
  transform(sentence.at(0).begin(), sentence.at(0).end(), sentence.at(0).begin(), ::tolower);
  transform(cipher.at(1).begin(), cipher.at(1).end(), cipher.at(1).begin(), ::tolower);

  CodeBreaker c(cipher.at(0), cipher.at(1), keyword, sentence.at(0));
  
  string s = c.solve();
  cout << s << endl;
  
  return 0;
}