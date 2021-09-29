/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Continued
*/
 
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <iostream>
#include "Model.h"

class Translator{
    private:
    Model *model;
    public:
    Translator(); 
    Translator(std::string);
    ~Translator(); 

    std::string stringParser(std::string, bool);
    std::string translateEnglishWord( std::string, bool );
    std::string translateEnglishSentence( std::string, bool );

};

#endif
