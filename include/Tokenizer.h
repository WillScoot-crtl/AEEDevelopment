#ifndef AEE_TOKENIZER_H 
#define AEE_TOKENIZER_H 
 
#include <string> 
#include <vector> 
#include "Token.h" 
 
namespace aee { 
 
/** 
* @brief Converts a raw arithmetic expression string into a token stream. 
* 
* The tokenizer performs a left-to-right scan of the input string and 
* recognizes integer numeric constants, arithmetic operators, exponentiation, 
* and parentheses. Unsupported characters cause an exception so invalid input 
* can be reported early before parsing begins. 
*/ 
class Tokenizer { 
public: 
    /** 
     * @brief Tokenize the given input expression. 
     * @param input The raw expression entered by the user. 
     * @return A vector of tokens ending with an End token. 
     * @throws std::runtime_error if an unsupported character is found. 
     */ 
    std::vector<Token> tokenize(const std::string& input) const; 
}; 
 
} // namespace aee 
 
#endif 
