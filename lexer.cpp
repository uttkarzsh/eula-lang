#include<cctype>
#include<cstudio>

int gettok(){
    static int LastChar = ' ';

    while(isspace(LastChar)){
        LastChar = getchar();
    }
}