#include <cstdlib> 
#include <iostream> 
#include <string> 
#include "Evaluator.h" 
 
static void expectEqual(const std::string& expr, long long expected) { 
    aee::Evaluator evaluator; 
    long long actual = evaluator.evaluateExpression(expr); 
    if (actual != expected) { 
        std::cerr << "FAILED: " << expr << " expected " << expected << " but got " << actual << "\n"; 
        std::exit(1); 
    } 
} 
 
static void expectThrows(const std::string& expr) { 
    aee::Evaluator evaluator; 
    try { 
        (void)evaluator.evaluateExpression(expr); 
        std::cerr << "FAILED: expected exception for expression: " << expr << "\n"; 
        std::exit(1); 
    } catch (...) { 
    } 
} 
 
int main() { 
    expectEqual("3 + 4", 7); 
    expectEqual("8 - (5 - 2)", 5); 
    expectEqual("10 * 2 / 5", 4); 
    expectEqual("2 ** 3", 8); 
    expectEqual("2 ** 3 ** 2", 512); 
    expectEqual("4 * (3 + 2) % 7 - 1", 5); 
    expectEqual("(((2 + 3))) + (((1 + 2)))", 8); 
    expectEqual("((5 * 2) - ((3 / 1) + ((4 % 3))))", 6); 
    expectEqual("-(+1) + (+2)", 1); 
    expectEqual("-(-(-3)) + (-4) + (+5)", -2); 
 
    expectThrows("4 / 0"); 
    expectThrows("10 % 0"); 
    expectThrows("5 (2 + 3)"); 
    expectThrows("7 & 3"); 
    expectThrows("2 * (4 + 3 - 1"); 
    expectThrows("* 5 + 2"); 
    expectThrows("2 ** -3"); 
    expectThrows(""); 
 
    std::cout << "All evaluator tests passed.\n"; 
    return 0; 
} 
