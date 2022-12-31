//
// Created by Anik on 12/28/2022.
//

#ifndef COMPILER_DESIGN_TYPES_H
#define COMPILER_DESIGN_TYPES_H


#include <string>

class Types {
public:
    inline static const std::string GLOBAL = "GLOBAL";
    inline static const std::string LOCAL = "LOCAL";
    inline static const std::string PARENTHESIS_BLOCK = "PARENTHESIS_BLOCK";
    inline static const std::string PARAMETER_BLOCK = "PARAMETER_BLOCK";
    inline static const std::string LOCAL_BLOCK = "PARAMETER_BLOCK";
    inline static const std::string SQUARE_BLOCK = "SQUARE_BLOCK";

    inline static const std::string EXPRESSION = "EXPRESSION";
    inline static const std::string CONSTANTS = "CONSTANTS";
    inline static const std::string KEY_WORD = "KEY_WORD";
    inline static const std::string BINARY_OPERATOR = "BINARY_OPERATOR";
    inline static const std::string UNARY_OPERATOR = "UNARY_OPERATOR";
    inline static const std::string IDENTIFIER = "IDENTIFIER";
    inline static const std::string PARENTHESIS = "PARENTHESIS";

    inline static const std::set<std::string> KEY_WORD_LIST{"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long", "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
    inline static const std::set<std::string> BINARY_OPERATOR_LIST{"!=", "%", "%=", "&", "&&", "&=", "*", "*=", "+", "+=", "-", "-=", "->", "/", "/=", "<", "<<", "<=", "=", "==", ">", ">=", ">>", "?:", "^", "^=", "|", "|=", "||"};
    inline static const std::set<std::string> UNARY_OPERATOR_LIST{"!", "++", "--", "~"};
    inline static const std::set<std::string> DOUBLE_CHAR_OPERATOR_LIST{"++", "--", "&&", "||", "<<", ">>", "==", "->", "!=", "<=", ">=", "?:", "+=", "-=", "*=", "/=", "%=", "&=", "^=", "|="};
    inline static const std::set<char> PARENTHESIS_LIST{'(', ')', '{', '}', '[', ']'};
    inline static const std::set<std::string> PRIMITIVE_DATA_TYPE_LIST{"int", "long int", "signed int", "short int", "signed short int", "unsigned short int", "signed long int", "unsigned long int", "unsigned int", "long long int", "unsigned long long int", "char", "signed char", "unsigned char", "void", "bool", "double", "float", "long double"};
    inline static const std::set<std::string> SEPARATOR{"!", "%", "^", "&", "*", "(", ")", "{", "}", ",", ".", "/", "<", ">", "?", ":", ";", "-", "=", "+", "[", "]", "~", "\"","\""};    inline static const std::set<char> IGNORABLE{'\n', ' ', '\t'};
    inline static const std::set<std::string> MEMORY_OPERATOR_LIST{"*", "&"};
    inline static const std::set<std::string> END_OF_EXPRESSION{";", "{", "}", "(", ","};
    inline static const std::set<std::string> SELF_INCREMENTAL_DECREMENTAL_OPERATOR_LIST{"++", "--"};
    inline static const std::map<std::string, int> PRECEDENCE_TABLE{
            {Types::EXPRESSION, 0}, {Types::IDENTIFIER, 0},
            {"++", 1}, {"--", 1}, {"(", 1}, {")", 1}, {"[", 1}, {"]", 1}, {".", 1}, {"->", 1},
            {"!", 2}, {"~", 2}, {"*", 2}, {"&", 2},
            {"*", 3}, {"/", 3}, {"%", 3},
            {"+", 4}, {"-", 4},
            {"<<", 5}, {">>", 5},
            {"<", 6}, {"<=", 6}, {">", 6}, {">=", 6},
            {"==", 7}, {"!=", 7},
            {"&", 8}, {"^", 9}, {"|", 10}, {"&&", 11}, {"||", 12}, {"?:", 13},
            {"=", 14}, {"+=", 14}, {"-=", 14}, {"*=", 14}, {"/=", 14}, {"%=", 14}, {"<<=", 14}, {">>=", 14}, {"&=", 14}, {"^=", 14}, {"|=", 14},
            {",", 15}
    };

};


#endif //COMPILER_DESIGN_TYPES_H
