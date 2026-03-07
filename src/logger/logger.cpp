#include "logger/logger.hpp"

std::unique_ptr<ExprAST> LogError(const char *Str){
    fprintf(stderr, "Error hai bro:  %s\n", Str);
    return nullptr;
}

std::unique_ptr<PrototypeAST> LogErrorProto(const char *Str){
    LogError(Str);
    return nullptr;
}