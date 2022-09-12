#pragma once
#include <iostream>
#include <stack>
#include "Node.h"


/*****************************************
Class: Binary tree
******************************************/
template <class T>
class BinaryTree
{
private:
    Node<T>* root;
public:
    BinaryTree(T);
    Node<T>* add_node(T, Node<T>* = nullptr);
    void show_tree(Node<T>* = nullptr);
    void show_no_rec(Node<T>* = nullptr);
    Node<T>* find_node(T, Node<T>* = nullptr);
    Node<T>* operator<<(T);
};
/*****************************************/

template <class T>
Node<T>* BinaryTree<T>::operator<<(T val)
{
    return add_node(val);
}


// Constructors definitions
template <class T>
BinaryTree<T>::BinaryTree(T root_value)
{
    root = new Node<T>(root_value);
}

// Add node to the tree
template <class T>
Node<T>* BinaryTree<T>::add_node(T val, Node<T>* start)
{
    // Node * added = nullptr;
    if (start == nullptr) start = this->root;
    Node<T>* parent = start; // ???
    Node<T>* next = (val < start->value) ? start->left : start->right;
    if (next == nullptr) {
        next = new Node<T>(val, start);
        *start += next;
        //start->connect_child(next);
    }
    else {
        next = add_node(val, next);
    }
    return next;
}



// Show tree as sorted vector
template <class T>
void BinaryTree<T>::show_tree(Node<T>* start)
{
    if (start == nullptr) start = root;
    if (start->left) show_tree(start->left);
    std::cout << start->value << ", ";
    if (start->right) show_tree(start->right);
}




// Find node by value
template <class T>
Node<T>* BinaryTree<T>::find_node(T x, Node<T>* start)
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
template <class T>
void BinaryTree<T>::show_no_rec(Node<T>* start)
{
    if (!start) start = root;      // По-умолчанию - с корневого узла
    std::stack<Node<T>*> st;          // Наш стек
    Node<T>* current = start;         // Текущий узел
    bool parent_is_ok = false;
    // Старт цикла обхода дерева
    do {
        Node<T>* st_top = (st.empty()) ? nullptr : st.top();
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
