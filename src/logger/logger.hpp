#include "ast/ast.hpp"

std::unique_ptr<ExprAST> LogError(const char *Str);
std::unique_ptr<PrototypeAST> LogErrorProto(const char *Str);
