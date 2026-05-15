#ifndef AEE_PARSER_H 
#define AEE_PARSER_H 
 
#include <memory> 
#include <vector> 
#include "Token.h" 
 
namespace aee { 
 
/** 
* @brief Node type used for the internal expression tree. 
* 
* A node may represent either a numeric constant or an operator with left and 
* right child expressions. 
*/ 
struct ExprNode { 
    TokenType op; 
    long long value; 
    std::unique_ptr<ExprNode> left; 
    std::unique_ptr<ExprNode> right; 
 
    explicit ExprNode(long long number); 
    ExprNode(TokenType opType, std::unique_ptr<ExprNode> lhs, std::unique_ptr<ExprNode> rhs); 
}; 
 
/** 
* @brief Builds an expression tree from a token stream. 
* 
* The parser uses recursive descent to enforce precedence, associativity, 
* unary operator handling, and parenthesized subexpressions. 
*/ 
class Parser { 
public: 
    /** 
     * @brief Parse the provided tokens into an expression tree. 
     * @param tokens Token stream produced by the tokenizer. 
     * @return Root node of the parsed expression tree. 
     * @throws std::runtime_error if the expression is malformed. 
     */ 
    std::unique_ptr<ExprNode> parse(const std::vector<Token>& tokens) const; 
 
private: 
    class ParserImpl; 
}; 
 
} // namespace aee 
 
#endif 
