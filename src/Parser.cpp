#include "Parser.h" 
#include <stdexcept> 
 
namespace aee { 
 
ExprNode::ExprNode(long long number) 
    : op(TokenType::Number), value(number) {} 
 
ExprNode::ExprNode(TokenType opType, std::unique_ptr<ExprNode> lhs, std::unique_ptr<ExprNode> rhs) 
    : op(opType), value(0), left(std::move(lhs)), right(std::move(rhs)) {} 
 
class Parser::ParserImpl { 
public: 
    explicit ParserImpl(const std::vector<Token>& tokenStream) 
        : tokens(tokenStream) {} 
 
    std::unique_ptr<ExprNode> parseExpression() { 
        auto node = parseTerm(); 
        while (match(TokenType::Plus) || match(TokenType::Minus)) { 
            TokenType op = previous().type; 
            auto rhs = parseTerm(); 
            node = std::make_unique<ExprNode>(op, std::move(node), std::move(rhs)); 
        } 
        return node; 
    } 
 
    void ensureEnd() const { 
        if (peek().type != TokenType::End) { 
            throw std::runtime_error("Unexpected token after end of expression"); 
        } 
    } 
 
private: 
    const std::vector<Token>& tokens; 
    std::size_t current = 0; 
 
    std::unique_ptr<ExprNode> parseTerm() { 
        auto node = parsePower(); 
        while (match(TokenType::Multiply) || match(TokenType::Divide) || match(TokenType::Modulo)) { 
            TokenType op = previous().type; 
            auto rhs = parsePower(); 
            node = std::make_unique<ExprNode>(op, std::move(node), std::move(rhs)); 
        } 
        return node; 
    } 
 
    std::unique_ptr<ExprNode> parsePower() { 
        auto node = parseUnary(); 
        if (match(TokenType::Power)) { 
            TokenType op = previous().type; 
            auto rhs = parsePower(); 
            node = std::make_unique<ExprNode>(op, std::move(node), std::move(rhs)); 
        } 
        return node; 
    } 
 
    std::unique_ptr<ExprNode> parseUnary() { 
        if (match(TokenType::Plus)) { 
            return parseUnary(); 
        } 
        if (match(TokenType::Minus)) { 
            auto zero = std::make_unique<ExprNode>(0); 
            auto rhs = parseUnary(); 
            return std::make_unique<ExprNode>(TokenType::Minus, std::move(zero), std::move(rhs)); 
        } 
        return parsePrimary(); 
    } 
 
    std::unique_ptr<ExprNode> parsePrimary() { 
        if (match(TokenType::Number)) { 
            return std::make_unique<ExprNode>(previous().value); 
        } 
        if (match(TokenType::LeftParen)) { 
            auto node = parseExpression(); 
            if (!match(TokenType::RightParen)) { 
                throw std::runtime_error("Missing closing parenthesis"); 
            } 
            return node; 
        } 
        throw std::runtime_error("Expected number or parenthesized expression"); 
    } 
 
    bool match(TokenType type) { 
        if (peek().type == type) { 
            ++current; 
            return true; 
        } 
        return false; 
    } 
 
    const Token& peek() const { 
        return tokens[current]; 
    } 
 
    const Token& previous() const { 
        return tokens[current - 1]; 
    } 
}; 
 
std::unique_ptr<ExprNode> Parser::parse(const std::vector<Token>& tokens) const { 
    ParserImpl impl(tokens); 
    auto root = impl.parseExpression(); 
    impl.ensureEnd(); 
    return root; 
} 
 
} // namespace aee 
 