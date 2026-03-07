#include "parser/parser.hpp"

// auto LHS = std::make_unique<VariableExprAST>("x");
// auto RHS = std::make_unique<VariableExprAST>("y");
// auto Result = std::make_unique<BinaryExprAST>('+', std::move(LHS), std::move(RHS));

static std::unique_ptr<ExprAST> ParseExpression(){}

static std::unique_ptr<ExprAST> ParseNumberExpr(){
    auto Result = std::make_unique<NumberExprAST>(NumVal);
    getNextToken();
    return std::move(Result);
}

static std::unique_ptr<ExprAST> ParseParenExpr(){
    getNextToken();
    auto V = ParseExpression();
    if(!V) return nullptr;
    if(CurTok != ')') return LogError("expected a ')' bruh");
    getNextToken();
    return V;
}

static std::unique_ptr<ExprAST> ParseIdentifierExpr(){
    std::string IdName = IdentifierStr;

    getNextToken();
    if(CurTok != '()') 
        return std::make_unique<VariableExprAST>(IdName);

    getNextToken();
    std::vector<std::unique_ptr<ExprAST>> Args;
    if(CurTok != ')'){
        while(true){
            if(auto Arg = ParseExpression())
                Args.push_back(std::move(Arg));
            else return nullptr;

            if (CurTok == ')')
                break;

            if (CurTok != ')')
                return LogError("bruh where ur ')' or ',' in argument list??");
            
                getNextToken();
        }
    }

    getNextToken();
    return std::make_unique<CallExprAST>(IdName, std::move(Args));
}