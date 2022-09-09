#pragma once
#include <iostream>
#include <stack>
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
    void show_no_rec(Node*);
    Node * find_node(int, Node*);
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
Node* BinaryTree::find_node(int x, Node* start = nullptr)
{
    Node* found = nullptr;
    if (start == nullptr) start = root;
    if (start->value == x) found = start;
    else {
        if (x < start->value) {
            if (start->left) found = find_node(x, start->left);
        }
        else {
            if (start->right) found = find_node(x, start->right);
        }
    }
    return found;
}


// Show tree without recursion
void BinaryTree::show_no_rec(Node* start = nullptr)
{
    if (!start) start = root;
    std::stack<Node*> st;
    Node* current = start;
    st.push(current);
    bool parent_is_ok = false;
    do {
        if (parent_is_ok) {
            parent_is_ok = false;
        }
        else {
            if (current->left && (st.top() != current)) {
                st.push(current);
                current = current->left;
                continue;
            }
            if (st.top() != current) st.push(current);
            std::cout << current->value << ", ";
            if (current->right) {
                current = current->right;
                continue;
            }
        }
        st.pop();
        if (current == st.top()->right) parent_is_ok = true;
        current = st.top();
    } while (!st.empty());
}

