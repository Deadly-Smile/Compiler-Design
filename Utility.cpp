//
// Created by Anik on 10/28/2022.
//

#include <bits/stdc++.h>
#include "Utility.h"
#include "Types.h"

void Utility::trimmer(std::string &s) {
    std::string t;
    bool is_ok = false;
    for(auto i : s) {
        if(!is_ok && i != ' ') {
            is_ok = true;
        }
        if (is_ok) {
            t.push_back(i);
        }
    }

    s = t;
    t.clear();
    is_ok = false;
    for(int i = (int)s.length()-1; i >= 0; i--) {
        if(!is_ok && s[i] != ' ') {
            is_ok = true;
        }
        if (is_ok) {
            t.push_back(s[i]);
        }
    }
    s = t;
    std::reverse(s.begin(), s.end());
}

void Utility::comment_remover(std::vector<std::pair<std::string, int>> &record) {
    bool is_multi_line{false};
    for(auto &i : record) {
        std::string s;
        for(int j = 0; j < i.first.size(); j++) {
            if(!is_multi_line && j+1 < i.first.size() && i.first.at(j) == '/' && i.first.at(j+1) == '/') {
                break;
            }
            if(j+1 < i.first.size() && i.first.at(j) == '/' && i.first.at(j+1) == '*') {
                is_multi_line = true;
                j++;
                continue;
            }
            if(j+1 < i.first.size() && i.first.at(j) == '*' && i.first.at(j+1) == '/') {
                is_multi_line = false;
                j++;
                continue;
            }
            if(!is_multi_line) {
                s.push_back(i.first.at(j));
            }
        }
        i.first = s;
    }
}

void Utility::code_cleaner(std::vector<std::pair<std::string, int>> &record) {
    comment_remover(record);
    std::vector<std::pair<std::string, int>> temp;
    for(auto &i : record) {
        trimmer(i.first);
        if(!i.first.empty()) {
            temp.push_back(i);
        }
    }
    record = temp;
}

bool Utility::is_number(const std::string &s) {
    bool is_fractional{false};
    for (char const &c : s) {
        if(!std::isdigit(c)) {
            if(!is_fractional && c == '.') {
                is_fractional = true;
            } else {
                return false;
            }
        }
    }
    return true;
}

//void infixToPostfix(string s) {
//
//    stack<char> st; // For stack operations, we are using
//    // C++ built in stack
//    string result;
//
//    for (int i = 0; i < s.length(); i++) {
//        char c = s[i];
//
//        // If the scanned character is
//        // an operand, add it to output string.
//        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
//            || (c >= '0' && c <= '9'))
//            result += c;
//
//            // If the scanned character is an
//            // ‘(‘, push it to the stack.
//        else if (c == '(')
//            st.push('(');
//
//            // If the scanned character is an ‘)’,
//            // pop and to output string from the stack
//            // until an ‘(‘ is encountered.
//        else if (c == ')') {
//            while (st.top() != '(') {
//                result += st.top();
//                st.pop();
//            }
//            st.pop();
//        }
//
//            // If an operator is scanned
//        else {
//            while (!st.empty()
//                   && prec(s[i]) <= prec(st.top())) {
//                result += st.top();
//                st.pop();
//            }
//            st.push(c);
//        }
//    }
//
//    // Pop all the remaining elements from the stack
//    while (!st.empty()) {
//        result += st.top();
//        st.pop();
//    }
//
//    cout << result << endl;
//}

std::vector<Token> Utility::infix_to_postfix_expression(std::vector<Token> record) {
    std::stack<Token> stack;
    std::vector<Token> result;

    for(auto &i : record) {
        if(stack.empty()) {
            stack.push(i);
        } else {
            if(Types::PRECEDENCE_TABLE.at(i.getType()) <= Types::PRECEDENCE_TABLE.at(stack.top().getType())) {
                result.push_back(stack.top());
                stack.pop();
            } else {
                stack.push(i);
            }
        }
    }
    while (!stack.empty()) {
        result.push_back(stack.top());
        stack.pop();
    }

    return result;
}


