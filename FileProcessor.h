/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Continued
*/
 
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <fstream>
#include "Translator.h"


class FileProcessor{
    public:

    Translator *translator;
    std::string stringInput;

    FileProcessor();
    FileProcessor(std::string inputName);
    ~FileProcessor();

    void startTranslation(std:: string outputName, std:: string whichDirection);
    void processFile( std::string, std::string, bool );



};

#endif