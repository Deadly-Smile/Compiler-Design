//
// Created by Anik on 12/29/2022.
//

#include "ParseTree.h"
#include <utility>

void ParseTree::add_node(Token token) {

}

bool ParseTree::evaluate_parse_tree() {
    return false;
}

ParseTree::~ParseTree() {

}

ParseTree::ParseTree(std::vector<Token> &record, std::string type) {
    this->root = nullptr;
    this->type = std::move(type);
    this->is_correct = -1;
    
}

bool ParseTree::is_ok() {
    if(this->is_correct < 0) {
        is_correct = evaluate_parse_tree();
    }
    return this->is_correct;
}