#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "TextHandler.h"

using namespace std;


vector<string> TextHandler::unpackTxtFile(const char* address){
  string temp;
  vector<string> unpackedFile;
  
  ifstream file(address);
  if(file.is_open()){
    while(std::getline(file, temp)){
      unpackedFile.push_back(temp);
    }
    file.close();
  }else{
    cout << "opening failed" << endl;
  }
  
  return unpackedFile;
}