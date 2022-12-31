//
// Created by Anik on 12/29/2022.
//

#ifndef COMPILER_DESIGN_PARSETREE_H
#define COMPILER_DESIGN_PARSETREE_H

#include <vector>
#include "Token.h"

class Node {
public:
    Node* left;
    Node* right;
    Node* under;
    Node* parent;
};
class ParseTree {
public:
    explicit ParseTree(std::vector<Token> &record, std::string type);
    bool is_ok();
private:
    int is_correct;
    std::string type;
    Node* root;
    void add_node(Token token);
    bool evaluate_parse_tree();
    ~ParseTree();
};


#endif //COMPILER_DESIGN_PARSETREE_H
