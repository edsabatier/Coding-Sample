#ifndef LETTER
#define LETTER

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Letter{
  private:
    /*INSTANCE VARIABLES*/
    char trueValue;
    char cipheredValue;
  public:
    /*CONTRUCTORS*/
    //value is true value, cipher is encrypted value
    Letter(char value, char cipher);
  
    /*SIMPLE ACCESSORS*/
    char getTrueValue();
    char getCipheredValue();
    void print();
};

#endif