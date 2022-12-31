//
// Created by Anik on 10/28/2022.
//
#include <bits/stdc++.h>
#include "Utility.h"
#include "Tokenizer.h"
#include "Token.h"

using namespace std;

vector<std::pair<string, int>> get_lines() {
    vector<std::pair<string, int>> record;
    string s;
    int line_number{0};
    while (getline(cin, s)) {
        line_number++;
        record.emplace_back(s, line_number);
    }
    Utility::code_cleaner(record);
    return record;
}

vector<Token> tokenization(vector<std::pair<string, int>> &record) {
    return Tokenizer::tokenize(record);
}

int main() {
    freopen("../test.c", "r", stdin);
    string s;
    vector<std::pair<string, int>> each_line = get_lines();
    for(const auto& i : each_line) {
        cout << i.first << " " << endl;
    }



    for(const auto& i : tokenization(each_line)) {
        cout << i.getContains() << " as a - " << i.getType() << " in line - " << i.getLineNumber() << endl;
    }
    for(auto i : Utility::infix_to_postfix_expression(tokenization(each_line))) {
        cout << i.getContains() << " ";
    }   cout << endl;
    return 0;
}

/*
output :
#include                <stdio.h  >
#  define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)
#   define Ignore cin.ignore()
int main() {
int m = 0;
int a, b;
int n = 51;
m += gh;
a = 10;
b = 20;
int c = a + b;
printf("%d", c);
return 0;
}
line - 1 "#include                <stdio.h  >" is correct
line - 2 "#  define FastIO ios_base::sync_with_stdio(false);    cin.tie(NULL)" is correct
line - 3 "#   define Ignore cin.ignore()" is correct
int KEY_WORD
main Identifiers
( PARENTHESIS
) PARENTHESIS
{ PARENTHESIS
int KEY_WORD
m Identifiers
= BINARY_OPERATOR
0 Identifiers
; Identifiers
int KEY_WORD
a Identifiers
, Identifiers
b Identifiers
; Identifiers
int KEY_WORD
n Identifiers
= BINARY_OPERATOR
51 Identifiers
; Identifiers
m Identifiers
+ BINARY_OPERATOR
= BINARY_OPERATOR
gh Identifiers
; Identifiers
a Identifiers
= BINARY_OPERATOR
10 Identifiers
; Identifiers
b Identifiers
= BINARY_OPERATOR
20 Identifiers
; Identifiers
int KEY_WORD
c Identifiers
= BINARY_OPERATOR
a Identifiers
+ BINARY_OPERATOR
b Identifiers
; Identifiers
printf Identifiers
( PARENTHESIS
%d CONSTANTS
, Identifiers
c Identifiers
) PARENTHESIS
; Identifiers
return KEY_WORD
0 Identifiers
; Identifiers
} PARENTHESIS
 */
