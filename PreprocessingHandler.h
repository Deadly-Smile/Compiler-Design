//
// Created by Anik on 10/28/2022.
//

#ifndef COMPILER_DESIGN_PREPROCESSINGHANDLER_H
#define COMPILER_DESIGN_PREPROCESSINGHANDLER_H


#include <string>

class PreprocessingHandler {
private:
    static bool check_file_loader(const std::string& s);
    static bool check_macro(const std::string& s);
    static bool is_header_file_correct(const std::string &basicString);
public:
    static bool check_preprocessor(const std::string &s);
};


#endif //COMPILER_DESIGN_PREPROCESSINGHANDLER_H
