cmake_minimum_required(VERSION 3.16) 
project(AEEDevelopment VERSION 0.1.0 LANGUAGES CXX) 
 
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS OFF) 
 
include(CTest) 
enable_testing() 
 
add_library(aee_core 
    src/Tokenizer.cpp 
    src/Parser.cpp 
    src/Evaluator.cpp 
) 
 
target_include_directories(aee_core PUBLIC include) 
 
add_executable(aeedevelopment src/main.cpp) 
target_link_libraries(aeedevelopment PRIVATE aee_core) 
 
add_executable(test_evaluator tests/test_evaluator.cpp) 
target_link_libraries(test_evaluator PRIVATE aee_core) 
add_test(NAME evaluator_tests COMMAND test_evaluator) 
 