#include "Evaluator.h" 
#include "Tokenizer.h" 
#include <cmath> 
#include <stdexcept> 
 
namespace aee { 
 
long long Evaluator::evaluate(const std::unique_ptr<ExprNode>& root) const { 
    if (!root) { 
        throw std::runtime_error("Cannot evaluate empty expression tree"); 
    } 
 
    if (root->op == TokenType::Number) { 
        return root->value; 
    } 
 
    long long lhs = evaluate(root->left); 
    long long rhs = evaluate(root->right); 
 
    switch (root->op) { 
        case TokenType::Plus: 
            return lhs + rhs; 
        case TokenType::Minus: 
            return lhs - rhs; 
        case TokenType::Multiply: 
            return lhs * rhs; 
        case TokenType::Divide: 
            if (rhs == 0) { 
                throw std::runtime_error("Division by zero"); 
            } 
            return lhs / rhs; 
        case TokenType::Modulo: 
            if (rhs == 0) { 
                throw std::runtime_error("Modulo by zero"); 
            } 
            return lhs % rhs; 
        case TokenType::Power: 
            if (rhs < 0) { 
                throw std::runtime_error("Negative exponents are not supported for integer evaluation"); 
            } 
            return static_cast<long long>(std::pow(lhs, rhs)); 
        default: 
            throw std::runtime_error("Unsupported operation during evaluation"); 
    } 
} 
 
long long Evaluator::evaluateExpression(const std::string& expression) const { 
    Tokenizer tokenizer; 
    Parser parser; 
    auto tokens = tokenizer.tokenize(expression); 
    auto tree = parser.parse(tokens); 
    return evaluate(tree); 
} 
 
} // namespace aee 
 