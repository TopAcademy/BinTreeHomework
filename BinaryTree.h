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
    void show_tree(Node*);
    void show_no_rec(Node*);
    Node* find_node(int, Node*);
};
/*****************************************/


// Constructors definitions

BinaryTree::BinaryTree(int root_value)
{
    root = new Node(root_value);
}

// Add node to the tree
Node* BinaryTree::add_node(int val, Node* start = nullptr)
{
    // Node * added = nullptr;
    if (start == nullptr) start = this->root;
    Node* parent = start; // ???
    Node* next = (val < start->value) ? start->left : start->right;
    if (next == nullptr) {
        next = new Node(val, start);
        start->connect_child(next);
    }
    else {
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
    if (!start) start = root;      // По-умолчанию - с корневого узла
    std::stack<Node*> st;          // Наш стек
    Node* current = start;         // Текущий узел
    bool parent_is_ok = false;
    // Старт цикла обхода дерева
    do {
        Node* st_top = (st.empty()) ? nullptr : st.top();
        // Мы попали в узел из правого потомка?
        if (parent_is_ok) {
            // возвращаемся наверх
            if (current->parent != nullptr) {
                if (current == current->parent->right) parent_is_ok = true;
                else parent_is_ok = false;
                current = current->parent;
            }
            st.pop();
            continue;
        }
        // Иначе работаем с узлом
        // Текущий узел в стеке? 
        if (st.empty() || (current != st.top())) {
            // Если нет, мы только начали работу с узлом
            st.push(current);
            if (current->left) {
                // Спускаемся влево, если там есть узел
                current = current->left;
            }
        }
        else {
            // Мы между левым и правым
            std::cout << current->value << ", ";
            if (current->right) {
                // Спускаемся вправо, если там есть куда
                current = current->right;
            }
            else {
                // Остаемся в узле, и говорим что родитель обслужен
                parent_is_ok = true;
            }
        }
    } while (!st.empty());

}
