#include <iostream> 
#include <string> 
#include "Evaluator.h" 
 
int main() { 
    aee::Evaluator evaluator; 
 
    std::cout << "Arithmetic Expression Evaluator in C++\n"; 
    std::cout << "Enter an expression, or type quit to exit.\n"; 
 
    std::string line; 
    while (true) { 
        std::cout << "> "; 
        if (!std::getline(std::cin, line)) { 
            break; 
        } 
 
        if (line == "quit" || line == "exit") { 
            break; 
        } 
 
        try { 
            long long result = evaluator.evaluateExpression(line); 
            std::cout << "Result: " << result << "\n"; 
        } catch (const std::exception& ex) { 
            std::cout << "Error: " << ex.what() << "\n"; 
        } 
    } 
 
    return 0; 
} 
