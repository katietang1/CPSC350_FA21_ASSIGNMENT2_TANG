/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Continued
FileProcessor takes a text file with English text and produces 
an output file containing Tutnese translation.
*/

#include <fstream>
using std::ifstream;
#include "FileProcessor.h"
#include "Translator.h"
using namespace std;

std::string inputName;
std::string stringInput;
ifstream indata;

/* FileProcessor class takes the name of the english file 
and produces an output file with Tutnese translation*/
FileProcessor::FileProcessor() {
//default constructor
}
FileProcessor::FileProcessor(std::string inputName){
// overload constructor
    indata.open(inputName);
    this->translator = new Translator();
}
FileProcessor::~FileProcessor(){
// destructor
    delete this->translator;
}

/* startTranslation function reads the file and stores the 
content in a string, it then calls processFile to write into file*/
void FileProcessor::startTranslation(std:: string outputName, std:: string whichDirection){
    std::string line;
    while (getline(indata,line)) {
        stringInput += line;

    }
    if (whichDirection == "E2T"){
        this->processFile(stringInput, outputName, false);
    } else if (whichDirection == "T2E"){
        this->processFile(stringInput, outputName, true);
    }
    indata.close();
}


/* processFile takes two arguments, a string representing text input
and a string representing translated output. It calls stringParser
then writes the translated data.*/
void FileProcessor::processFile(std::string stringInput, std::string stringOutput, bool whichDirection){
    stringInput = translator->stringParser(stringInput, whichDirection);
    ofstream outdata;
    outdata.open(stringOutput);
    for (int i = 0; i < stringInput.length(); i++){
         outdata << stringInput[i];
    }
    outdata.close();
}
