//
// Created by Anik on 10/28/2022.
//

#include "PreprocessingHandler.h"
#include <string>
#include <vector>
#include <regex>
#include "Utility.h"
const std::vector<std::string> HEADER_FILE_LIST{"stdio.h", "string.h", "conio.h", "stdlib.h", "math.h", "ctype.h", "time.h", "assert.h", "locale.h", "signal.h", "setjmp.h", "stdarg.h", "errno.h", "complex.h", "fenv.h", "float.h", "inttypes.h", "iso646.h", "limits.h", "setjmp.h", "signal.h", "stdalign.h", "uchar.h", "wchar.h", "wctype.h"};

bool PreprocessingHandler::check_preprocessor(const std::string &s) {
    std::regex file_loader_format(" *# *include.*");
    std::regex macro_format(" *# *define +.*");
    if(std::regex_match(s, file_loader_format)) {
        return check_file_loader(s);
    }
    if(std::regex_match(s, macro_format)) {
        return check_macro(s);
    }
    return false;
}

bool PreprocessingHandler::check_file_loader(const std::string &s) {
    std::regex r(" *# *include *<[!-~]+ *> *");
    if(std::regex_match(s, r)) {
        return is_header_file_correct(s);
    }
    return false;
}

bool PreprocessingHandler::check_macro(const std::string &s) {
    std::regex correct_macro_format(" *# *define +[!-~]+ +[!-~]+[ -~]+");
    if(std::regex_match(s, correct_macro_format)) {
        return true;
    }
    return false;
}

bool PreprocessingHandler::is_header_file_correct(const std::string &s) {
    bool hasStarted{false};
    std::string t;
    for (char i : s) {
        if(i == '<' && !hasStarted) {
            t.clear();
            hasStarted = true;
            continue;
        } else if(i == '>' && hasStarted) {
            break;
        }
        if(hasStarted) {
            t.push_back(i);
        }
    }
    Utility::trimmer(t);
    auto it = std::find(HEADER_FILE_LIST.begin(), HEADER_FILE_LIST.end(), t);
    return it != HEADER_FILE_LIST.end();
}
