/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Continued
*/
 
#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>

class Model{
    public:
    Model(); 
   ~Model(); 

    std::string translateSingleCharacter( char );
    std::string translateDoubleCharacter( char );

    std::string wordParser( std::string fullWord, bool whichDirection);
    std::string translateSingleVowel( char );
    std::string translateDoubleVowel( char );

    std::string tutTranslateDoubleVowel( char );
    std::string tutTranslateSingleChar( std::string );

    
   
};

#endif
