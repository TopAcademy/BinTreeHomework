#pragma once
#include <iostream>
#include "Node.h"


/*****************************************
Class: Binary tree
******************************************/
class BinaryTree
{
private:
    Node* root;
public:
    BinaryTree(int);
    Node* add_node(int, Node*);
    void show_tree(Node *);
    Node * find_node(Node*);
};
/*****************************************/


// Constructors definitions

BinaryTree::BinaryTree(int root_value)
{
    root = new Node(root_value);
}

// Add node to the tree
Node* BinaryTree::add_node(int val, Node * start = nullptr)
{
    // Node * added = nullptr;
    if (start == nullptr) start = this->root;
    Node* parent = start; // ???
    Node* next = (val < start->value) ? start->left : start->right;
    if (next == nullptr) {
        // ниже пусто
        next = new Node(val, start);
        start->connect_child(next);
    }
    else {
        // дочерний элемент уже есть
        next = add_node(val, next);
    }
    return next;
}



// Show tree as sorted vector
void BinaryTree::show_tree(Node* start = nullptr)
{
    if (start == nullptr) start = root;
    if (start->left) show_tree(start->left);
    std::cout << start->value << ", ";
    if (start->right) show_tree(start->right);
}


// Find node by value
Node* BinaryTree::find_node(Node* start = nullptr)
{
    Node* found = nullptr;
    // ДОМАШНЕЕ ЗАДАНИЕ
    return found;
}
