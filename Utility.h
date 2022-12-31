//
// Created by Anik on 10/28/2022.
//

#ifndef COMPILER_DESIGN_UTILITY_H
#define COMPILER_DESIGN_UTILITY_H


#include <string>
#include "Token.h"

class Utility {
    static void comment_remover(std::vector<std::pair<std::string, int>> &record);
public:
    static void trimmer(std::string& s);
    static void code_cleaner(std::vector<std::pair<std::string, int>> &record);
    static bool is_number(const std::string& s);
    static std::vector<Token> infix_to_postfix_expression(std::vector<Token> record);
    template<typename T>
    static void append(T new_container, const T &old_container) {
        for(const auto &it : old_container) {
            new_container.insert(it);
        }
    }
};


#endif //COMPILER_DESIGN_UTILITY_H
