#include "Tokenizer.h" 
#include <cctype> 
#include <stdexcept> 
 
namespace aee { 
 
std::string tokenTypeToString(TokenType type) { 
    switch (type) { 
        case TokenType::Number: return "Number"; 
        case TokenType::Plus: return "Plus"; 
        case TokenType::Minus: return "Minus"; 
        case TokenType::Multiply: return "Multiply"; 
        case TokenType::Divide: return "Divide"; 
        case TokenType::Modulo: return "Modulo"; 
        case TokenType::Power: return "Power"; 
        case TokenType::LeftParen: return "LeftParen"; 
        case TokenType::RightParen: return "RightParen"; 
        case TokenType::End: return "End"; 
    } 
    return "Unknown"; 
} 
 
std::vector<Token> Tokenizer::tokenize(const std::string& input) const { 
    std::vector<Token> tokens; 
 
    for (std::size_t i = 0; i < input.size();) { 
        char ch = input[i]; 
 
        if (std::isspace(static_cast<unsigned char>(ch))) { 
            ++i; 
            continue; 
        } 
 
        if (std::isdigit(static_cast<unsigned char>(ch))) { 
            std::size_t start = i; 
            long long value = 0; 
            while (i < input.size() && std::isdigit(static_cast<unsigned char>(input[i]))) { 
                value = value * 10 + (input[i] - '0'); 
                ++i; 
            } 
            tokens.push_back({TokenType::Number, input.substr(start, i - start), value}); 
            continue; 
        } 
 
        if (ch == '+') { 
            tokens.push_back({TokenType::Plus, "+", 0}); 
        } else if (ch == '-') { 
            tokens.push_back({TokenType::Minus, "-", 0}); 
        } else if (ch == '/') { 
            tokens.push_back({TokenType::Divide, "/", 0}); 
        } else if (ch == '%') { 
            tokens.push_back({TokenType::Modulo, "%", 0}); 
        } else if (ch == '(') { 
            tokens.push_back({TokenType::LeftParen, "(", 0}); 
        } else if (ch == ')') { 
            tokens.push_back({TokenType::RightParen, ")", 0}); 
        } else if (ch == '*') { 
            if (i + 1 < input.size() && input[i + 1] == '*') { 
                tokens.push_back({TokenType::Power, "**", 0}); 
                i += 2; 
                continue; 
            } 
            tokens.push_back({TokenType::Multiply, "*", 0}); 
        } else { 
            throw std::runtime_error(std::string("Unsupported character: ") + ch); 
        } 
 
        ++i; 
    } 
 
    tokens.push_back({TokenType::End, "", 0}); 
    return tokens; 
} 
 
} // namespace aee 
 