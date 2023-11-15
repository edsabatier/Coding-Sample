#ifndef TEXT_HANDLER
#define TEXT_HANDLER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class TextHandler{
  public:
    static vector<string> unpackTxtFile(const char* address);
    
};

#endif