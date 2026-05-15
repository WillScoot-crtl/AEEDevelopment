#ifndef AEE_TOKEN_H 
#define AEE_TOKEN_H 
 
#include <string> 
 
namespace aee { 
 
enum class TokenType { 
    Number, 
    Plus, 
    Minus, 
    Multiply, 
    Divide, 
    Modulo, 
    Power, 
    LeftParen, 
    RightParen, 
    End 
}; 
 
struct Token { 
    TokenType type; 
    std::string lexeme; 
    long long value; 
}; 
 
std::string tokenTypeToString(TokenType type); 
 
} // namespace aee 
 
#endif 

