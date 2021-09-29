/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Continued
Translator.cpp breaks down the full english string into sentences
and words 
*/

#include <iostream>
#include "Translator.h"
#include "Model.h"
using namespace std;
Model *model;

/* Translator class takes in the full string Input and 
translates english sentences. */
Translator::Translator() {
//constructor
    //this->model = new Model();
}

Translator::Translator(std::string fullString) {
//overload constructor
    this->model = new Model();
    
}
Translator::~Translator(){
//destructor
    delete this->model;
}

/* stringParser function takes in the full string input and 
    determines sentences based on puncuation. It returns the 
    fully translated Tutnese string.*/
std::string Translator::stringParser(std::string fullText, bool whichDirection){

    std::string translatedString = "";
    std::string currSentence = "";
    // for char in fullText 
    for (int i = 0; i < fullText.length(); ++i){
        char currChar = fullText[i];
        currSentence += currChar;
        //check if sentence
        if (currChar == '.'){
    
            translatedString += this->translateEnglishSentence(currSentence.substr(0,(currSentence.length()-1)), whichDirection)+ '.';
        }   
        else if (currChar == '!'){

            translatedString += this->translateEnglishSentence(currSentence.substr(0,(currSentence.length()-1)), whichDirection)+ '!';
        }

        else if (currChar == '?'){
            translatedString += this->translateEnglishSentence(currSentence.substr(0,(currSentence.length()-1)), whichDirection)+ '?';
             
        }

        else if (currChar == ','){
            translatedString += this->translateEnglishSentence(currSentence.substr(0,(currSentence.length()-1)), whichDirection)+ ',';
             
        }

        else if (currChar == ':'){
            translatedString += this->translateEnglishSentence(currSentence.substr(0,(currSentence.length()-1)), whichDirection) + ':';
             
        }

        else if (currChar == ';'){
            translatedString += this->translateEnglishSentence(currSentence.substr(0,(currSentence.length()-1)), whichDirection)+ ';';
             
        }

    }
    return translatedString;

}

/* translateEnglishSentence function takes in an english sentence and
breaks it down words based on spaces. It returns the translated sentence.*/
std::string Translator::translateEnglishSentence( std::string EngSentence, bool whichDirection ){
    std::string translatedSentence = "";
    std::string currWord = "";
    for (int i = 0; i < EngSentence.length(); ++i){
        char currChar = EngSentence[i];

        if (currChar != ' ' && !ispunct(currChar)){
            currWord += currChar;
        }

        else if(ispunct(currChar) || currChar == ' ') {
            translatedSentence += this->translateEnglishWord(currWord, whichDirection);
            translatedSentence += currChar;
            currWord = "";
        }
        if(i == EngSentence.length()-1) {
            translatedSentence += this->translateEnglishWord(currWord, whichDirection);
        }
      
    }
    return translatedSentence;
}
/* translateEnglishWord function takes in an english word and
calls wordParser, then returns the translated word. */
std::string Translator::translateEnglishWord( std::string EngWord, bool whichDirection){

    std::string translatedWord = "";
    translatedWord = model->wordParser(EngWord, whichDirection);

    return translatedWord;
}
