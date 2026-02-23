# AEEDevelopment
A Qt C++ application for parsing and evaluating arithmetic expressions with advanced visualization features

**Team Members**
  - Ritwik Goyal - Product Manager
  - Jacob Spry - Software Developer
  - Andrew Wendling - Software Architect
  - Mahanthi Sai - DevOps Engineer
  - Ayesha Akbar - Quality Assurance
  - William Webb - UI/UX Designer

**Project Overview**
This project implements an arithemtic expression evaluator that supports:
  - Basic Operators: +, -, *, /, %
  - Exponentiation: **
  - Unary Operators: +, -
  - PEMDAS Operator precedence
  - Proper left_to_right and right-to-left associativity

  **Features**
  Core Features:
    - Expression parsing and evaluation
    - Comprehensive error handling
    - Support for real numbers and algebraic variables

  GUI Features:
    - Parse tree visualization
    - Step-by-step evaluation display
    - Token stream display
    - Dark mode toggle
    - Expression history
    - Interactive tabbed interface

  Environment
    - C++ Compiler: Clang 14+
    - Qt Framework: Qt 6.10
    - CMake: Version 3.16 or later
    - Git: Version Control

  **Installation**
  1. Install Qt 6
       Windows: Download https://www.qt.io/development/download
       macOS: bash
           brew install qt@6
       Linux(Ubuntu/Debian):
           sudo apt update
           sudo apt install qt6-base-dev qt6-tools-dev cmake build-essential

  2. Clone the Repository
       [git clone https://github.com/WillScoot-crtl/AEEDevelopment.git]
       [cd aeedevelopment]

  3. Build the Project
           Bash
       mkdir build
       cd build
       
       cmake . .
       came --build
     on linux/macOS you can also use:
     make -j$(nproc)
**Running the Application**
          bash
cd build
./aeedevelopment #linuc/macos
aeedevelopment.exe #windows

From Qt creator
1. Open CMakeLists.txt in Qt Creator
2. configure the project
3. click "run"

**Documentation**
  - Programming Guidelines
  - Requirements Document
  - Design Document
  - User Manual

**Status**: Under Development
**Current Version**: 0.1.0 (Initial Setup)

             
      
