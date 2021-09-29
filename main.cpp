/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Continued
*/
#include <iostream>
#include <fstream>
using namespace std;
#include "FileProcessor.h"

int main (int arg, char** argv){

   cout << "Welcome to the Tutnese English translator." << endl;
   //Instantiate FileProcessor
   FileProcessor *fp = new FileProcessor(argv[1]);
   fp->startTranslation(argv[2], argv[3]);
   delete fp;

   return 0;
}
