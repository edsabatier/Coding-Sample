#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Letter.h"

using namespace std;


/*CONSTRUCTORS*/
//value is true value, cipher is encrypted value
//IMPORTANT: UPPERCASE IS TRUE VALUE, LOWERCASE IS CIPHERED VALUE
Letter::Letter(char value, char cipher){
  trueValue = toupper(value);
  cipheredValue = tolower(cipher);
}

/*ACCESSORS*/
char Letter::getTrueValue(){return trueValue;}
char Letter::getCipheredValue(){return cipheredValue;}
void Letter::print(){
  cout << trueValue << ", " << cipheredValue << endl;
}