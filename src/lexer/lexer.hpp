#include<cctype>
#include<cstdio>
#include<string>

extern double NumVal;
extern std::string IdentifierStr;
extern int CurTok;

enum Token {
    tok_eof = -1,
    
    tok_def = -2,
    tok_extern = -3,

    tok_identifier = -4,
    tok_number = -5,
};

int gettok();
static int getNextToken();