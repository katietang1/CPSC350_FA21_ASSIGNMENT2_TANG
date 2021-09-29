/*
Katie Tang
2313452
htang@chapman.edu
CPSC-350-02
Assignment 2: Tutnese Translation Conitnued
Model.cpp uses switch statements to assign each english character
to it's Tutnese counter part.
*/
 
#include <iostream>
#include "Model.h"
#include "Translator.h"
using namespace std;

Model::Model(){
//default constructor
}
Model::~Model(){
//default destructor
}

/* wordParser function takes in a word and
determines how to translate each char. It returns the translated word.*/
string Model::wordParser(std::string fullWord, bool whichDirection){
    string translatedWord = "";
    string mySqua = "squa";
    string mySquat = "squat";
    string tutSyllable = "";
    string tempString = "";

    // for T2E
    if (whichDirection == true){
        for (int i = 0; i < fullWord.length(); ++i){
            char currTut = fullWord[i];
            tempString += fullWord[i];
            if (currTut == 'a' || currTut == 'A' || currTut == 'e' ||
            currTut == 'E' || currTut == 'i' || currTut == 'I' || currTut == 'O'|| 
            currTut == 'o' || currTut == 'U' || currTut == 'u'){
                if (i < fullWord.length()-1 && tempString == "Ex"){
                    translatedWord += "X";
                    tempString = "";
                }  else if (i < fullWord.length()-1 && tempString == "ex"){
                    translatedWord += "x";
                    tempString = "";
                }
                // tut check for double vowel 
                if (i - 5 >= 0){
                    if (fullWord.substr(i-5, i) == "squat"){
                        char doubleVowel = i + 5;
                        size_t pos = fullWord.find(mySquat);
                        fullWord.erase(fullWord.begin()+ i, fullWord.begin() + pos +5 ); // erase the squat indexes
                        translatedWord += this->tutTranslateDoubleVowel(doubleVowel);
                    }
                }
           
            }
            else {
                size_t pos = fullWord.find(mySqua); // find squa
                if (pos >= 0 && pos < fullWord.length()-4){
                    tutSyllable += fullWord.substr(i,pos); //store until squa
                    fullWord.erase(fullWord.begin()+ pos, fullWord.begin() + pos +4 ); // erase the squa indexes
                    translatedWord += this->tutTranslateSingleChar(tutSyllable);
                    translatedWord += currTut; // to make double letter
                    continue;
                    }

                if (tempString == "Cash" || tempString == "cash" || tempString == "Hash" || tempString == "hash" ||
                   tempString == "Kuck" || tempString == "kuck" || tempString == "Wack" || tempString == "wack" ){
                   tutSyllable = tempString;
                   translatedWord += this->tutTranslateSingleChar(tutSyllable);
                   tempString = "";
                   i+4;
               } else if (tempString == "Quack" || tempString == "quack"){
                   tutSyllable = tempString;
                   translatedWord += this->tutTranslateSingleChar(tutSyllable);
                   tempString = "";
                   i+5;
               } else {
                   tutSyllable = tempString;
                   translatedWord += this->tutTranslateSingleChar(tutSyllable);
                   tempString = "";
                   i+3;
               }


            }
        
        }
        return translatedWord;

    } else if (whichDirection == false){ //E2T
         for (int i = 0; i < fullWord.length(); ++i){
            char curr = fullWord[i];
        
         // check if vowel
             if (curr == 'a' || curr == 'A' || curr == 'e' ||
                curr == 'E' || curr == 'i' || curr == 'I' || curr == 'O'|| 
                curr == 'o' || curr == 'U' || curr == 'u'){

            //english if double translate vowel double
            if (i != fullWord.length()-1 && curr == fullWord[i+1]){
                translatedWord += this->translateDoubleVowel(curr);
                ++i;
            }
             //english if single translate vowel single
            else {
                translatedWord += this->translateSingleVowel(curr);
            }
            
            } else {
             //english if double character translate regular double
             if (i != fullWord.length()-1 && curr == fullWord[i+1]) {
                translatedWord += this->translateDoubleCharacter(curr);
                ++i;
             }
             //english if single translate regular single 
            else {
                translatedWord += this->translateSingleCharacter(curr);
            }
            
        }
      }
      return translatedWord;
    }
}

/* translateDoubleCharacter function takes in a non-vowel char that is 
repeated. It returns the translated char.*/
std::string Model::translateDoubleCharacter(char doubleChar){
    std::string translatedChar = "";
    switch (doubleChar){

        case 'B' :
        translatedChar += "Bubsqua";
        break;

        case 'b' :
        translatedChar += "bubsqua";
        break;

        case 'C' :
        translatedChar += "Cashsqua";
        break;

        case 'c' :
        translatedChar += "cashsqua";
        break;

        case 'D' :
        translatedChar += "Dudqua";
        break;

        case 'd' :
        translatedChar += "dudsqua";
        break;

        case 'F' :
        translatedChar += "Fufsqua";
        break;

        case 'f' :
        translatedChar += "fufsqua";
        break;

        case 'G' :
        translatedChar += "Gugsqua";
        break;

        case 'g' :
        translatedChar += "gugsqua";
        break;

        case 'H' :
        translatedChar += "Hashsqua";
        break;

        case 'h' :
        translatedChar += "hashsqua";
        break;

        case 'J' :
        translatedChar += "Jaysqua";
        break;

        case 'j' :
        translatedChar += "jaysqua";
        break;

        case 'K' :
        translatedChar += "Kucksqua";
        break;

        case 'k' :
        translatedChar += "kucksqua";
        break;

        case 'L' :
        translatedChar += "Lulsqua";
        break;

        case 'l' :
        translatedChar += "lulsqua";
        break;

        case 'M' :
        translatedChar += "Mumsqua";
        break;

        case 'm' :
        translatedChar += "mumsqua";
        break;

        case 'N' :
        translatedChar += "Nunsqua";
        break;

        case 'n' :
        translatedChar += "nunsqua";
        break;

        case 'P' :
        translatedChar += "Pubsqua";
        break;

        case 'p' :
        translatedChar += "pubsqua";
        break;

        case 'Q' :
        translatedChar += "Quacksqua";
        break;

        case 'q' :
        translatedChar += "quacksqua";
        break;

        case 'R' :
        translatedChar += "Rugsqua";
        break;

        case 'r' :
        translatedChar += "rugsqua";
        break;

        case 'S' :
        translatedChar += "Sussqua";
        break;

        case 's' :
        translatedChar += "sussqua";
        break;

        case 'T' :
        translatedChar += "Tutsqua";
        break;

        case 't' :
        translatedChar += "tutsqua";
        break;

        case 'V' :
        translatedChar += "Vuvsqua";
        break;

        case 'v' :
        translatedChar += "vuvsqua";
        break;

        case 'W' :
        translatedChar += "Wacksqua";
        break;

        case 'w' :
        translatedChar += "wacksqua";
        break;

        // x is special on the way back
        case 'X' :
        translatedChar += "Exsqua";
        break;

        case 'x' :
        translatedChar += "exsqua";
        break;

        case 'Y' :
        translatedChar += "Yubsqua";
        break;

        case 'y' :
        translatedChar += "yubsqua";
        break;

        case 'Z' :
        translatedChar += "Zubsqua";
        break;

        case 'z' :
        translatedChar += "zubsqua";
        break;

        default :
        cout << "Invalid character translateDoubleCharacter" << endl;

    };

    return translatedChar;

}

/* translateSingleCharacer function takes in a non-vowel char.
 It returns the translated char.*/
std::string Model::translateSingleCharacter(char singleChar){
    std::string translatedChar = "";
    switch (singleChar){
        case 'B' :
        translatedChar += "Bub";
        break;

        case 'b' :
        translatedChar += "bub";
        break;

        case 'C' :
        translatedChar += "Cash";
        break;

        case 'c' :
        translatedChar += "cash";
        break;

        case 'D' :
        translatedChar += "Dud";
        break;

        case 'd' :
        translatedChar += "dud";
        break;

        case 'F' :
        translatedChar += "Fuf";
        break;

        case 'f' :
        translatedChar += "fuf";
        break;

        case 'G' :
        translatedChar += "Gug";
        break;

        case 'g' :
        translatedChar += "gug";
        break;

        case 'H' :
        translatedChar += "Hash";
        break;

        case 'h' :
        translatedChar += "hash";
        break;

        case 'J' :
        translatedChar += "Jay";
        break;

        case 'j' :
        translatedChar += "jay";
        break;

        case 'K' :
        translatedChar += "Kuck";
        break;

        case 'k' :
        translatedChar += "kuck";
        break;

        case 'L' :
        translatedChar += "Lul";
        break;

        case 'l' :
        translatedChar += "lul";
        break;

        case 'M' :
        translatedChar += "Mum";
        break;

        case 'm' :
        translatedChar += "mum";
        break;

        case 'N' :
        translatedChar += "Nun";
        break;

        case 'n' :
        translatedChar += "nun";
        break;

        case 'P' :
        translatedChar += "Pub";
        break;

        case 'p' :
        translatedChar += "pub";
        break;

        case 'Q' :
        translatedChar += "Quack";
        break;

        case 'q' :
        translatedChar += "quack";
        break;

        case 'R' :
        translatedChar += "Rug";
        break;

        case 'r' :
        translatedChar += "rug";
        break;

        case 'S' :
        translatedChar += "Sus";
        break;

        case 's' :
        translatedChar += "sus";
        break;

        case 'T' :
        translatedChar += "Tut";
        break;

        case 't' :
        translatedChar += "tut";
        break;

        case 'V' :
        translatedChar += "Vuv";
        break;

        case 'v' :
        translatedChar += "vuv";
        break;

        case 'W' :
        translatedChar += "Wack";
        break;

        case 'w' :
        translatedChar += "wack";
        break;

        case 'X' :
        translatedChar += "Ex";
        break;

        case 'x' :
        translatedChar += "ex";
        break;

        case 'Y' :
        translatedChar += "Yub";
        break;

        case 'y' :
        translatedChar += "yub";
        break;

        case 'Z' :
        translatedChar += "Zub";
        break;

        case 'z' :
        translatedChar += "zub";
        break;

        default :
        cout << "Invalid character translateSingleCharacter" << endl;

    }

    return translatedChar;
}


/* translateDoubleVowel function takes in a repeated vowel char.
 It returns the translated char.*/
std::string Model::translateDoubleVowel(char doubleVowel){
    std::string translatedChar = "";
    switch (doubleVowel) {
        case 'A' :
        translatedChar += "Squata";
        break;

        case 'a' :
        translatedChar += "squata";
        break;

        case 'E' :
        translatedChar += "Squate";
        break;

        case 'e' :
        translatedChar += "squate";
        break;
        
        case 'I' :
        translatedChar += "Squati";
        break;

        case 'i' :
        translatedChar += "squati";
        break;

        case 'O' :
        translatedChar += "Squato";
        break;

        case 'o' :
        translatedChar += "squato";
        break;

        case 'U' :
        translatedChar += "Squatu";
        break;

        case 'u' :
        translatedChar += "squatu";
        break;

        default:

        cout << "Invalid character translateDoubleVowel" << endl;


    }

    return translatedChar;

}


// Tut starts here 
/* tutTranslateDoubleVowel function takes in a tut vowel char
    and returns the double char in english.*/
std::string Model::tutTranslateDoubleVowel(char doubleVowel){
    std::string translatedChar = "";
    switch (doubleVowel) {
        case 'A' :
        translatedChar += doubleVowel;
        break;

        case 'a' :
        translatedChar += doubleVowel;
        break;

        case 'E' :
        translatedChar += doubleVowel;
        break;

        case 'e' :
        translatedChar += doubleVowel;
        break;

        case 'I' :
        translatedChar += doubleVowel;
        break;

        case 'i' :
        translatedChar += doubleVowel;
        break;

        case 'O' :
        translatedChar += doubleVowel;
        break;

        case 'o' :
        translatedChar += doubleVowel;
        break;

        case 'U' :
        translatedChar += doubleVowel;
        break;

        case 'u' :
        translatedChar += doubleVowel;
        break;

        default:

        cout << "Invalid character tutTranslateDoubleVowel" << endl;
    }

    return translatedChar;

}
/* tutTranslateSingleChar function takes in a string representing a tut syllable.
 It returns the translated char.*/
std::string Model::tutTranslateSingleChar(string tutSyllable){
    std::string translatedChar = "";
        if("Bub"== tutSyllable) {
            translatedChar += "B";
        }

        if("bub"== tutSyllable) {
            translatedChar += "b";
        }

        if("Cash"== tutSyllable) {
            translatedChar += "C";
        }

        if("cash"== tutSyllable) {
            translatedChar += "C";
        }

        if("Dud"== tutSyllable) {
            translatedChar += "D";
        }

        if("dud"== tutSyllable) {
            translatedChar += "d";
        }

        if("Fuf"== tutSyllable) {
            translatedChar += "F";
        }

        if("fuf"== tutSyllable) {
            translatedChar += "f";
        }

        if("Gug"== tutSyllable) {
            translatedChar += "G";
        }

        if("gug"== tutSyllable) {
            translatedChar += "g";
        }

        if("Hash"== tutSyllable) {
            translatedChar += "H";
        }

        if("hash"== tutSyllable) {
            translatedChar += "h";
        }

        if("Jay"== tutSyllable) {
            translatedChar += "J";
        }

        if("jay"== tutSyllable) {
            translatedChar += "j";
        }

        if("Kuck"== tutSyllable) {
            translatedChar += "K";
        }
        if("kuck"== tutSyllable) {
            translatedChar += "k";
        }

        if("Lul"== tutSyllable) {
            translatedChar += "L";
        }

        if("lul"== tutSyllable) {
            translatedChar += "l";
        }
        if("Mum"== tutSyllable) {
            translatedChar += "M";
        }

        if("mum"== tutSyllable) {
            translatedChar += "m";
        }

        if("Nun"== tutSyllable) {
            translatedChar += "N";
        }

        if("nun"== tutSyllable) {
            translatedChar += "n";
        }

        if("Pub"== tutSyllable) {
            translatedChar += "P";
        }

        if("pub"== tutSyllable) {
            translatedChar += "p";
        }

       if("Quack"== tutSyllable) {
            translatedChar += "Q";
        }

        if("quack"== tutSyllable) {
            translatedChar += "q";
        }

        if("Rug"== tutSyllable) {
            translatedChar += "R";
        }

        if("rug"== tutSyllable) {
            translatedChar += "r";
        }

        if("Sus"== tutSyllable) {
            translatedChar += "S";
        }

        if("sus"== tutSyllable) {
            translatedChar += "s";
        }

       if("Tut"== tutSyllable) {
            translatedChar += "T";
        }

        if("tut"== tutSyllable) {
            translatedChar += "t";
        }

        if("Vuv"== tutSyllable) {
            translatedChar += "V";
        }

        if("vuv"== tutSyllable) {
            translatedChar += "v";
        }

        if("Yub"== tutSyllable) {
            translatedChar += "Y";
        }

        if("yub"== tutSyllable) {
            translatedChar += "y";
        }

       if("Zub"== tutSyllable) {
            translatedChar += "Z";
        }

        if("Zub"== tutSyllable) {
            translatedChar += "z";
        }

    return translatedChar;
}
/* translateSingleVowel function takes in a vowel char.
 It returns the translated char.*/
 std::string Model::translateSingleVowel(char singleVowel){
    std::string translatedChar = "";
    switch (singleVowel) {
         case 'A' :
         translatedChar += "A";
         break;

         case 'a' :
         translatedChar += "a";
         break;

         case 'E' :
         translatedChar += "E";
         break;

         case 'e' :
         translatedChar += "e";
         break;
        
         case 'I' :
         translatedChar += "I";
         break;

         case 'i' :
         translatedChar += "i";
         break;

         case 'o' :
         translatedChar += "o";
         break;

         case 'O' :
         translatedChar += "O";
         break;

         case 'U' :
         translatedChar += "U";
         break;

         case 'u' :
         translatedChar += "u";
         break;

         default:

         cout << "Invalid character translateSingleVowel" << endl;


     }

     return translatedChar;

 }


 
 
