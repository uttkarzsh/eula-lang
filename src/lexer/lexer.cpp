#include "lexer/lexer.hpp"

int gettok(){
    static int LastChar = ' ';

    while(isspace(LastChar)){
        LastChar = getchar();
    }
}