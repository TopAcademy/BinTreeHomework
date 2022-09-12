#pragma once

enum LoR { LEFT_CHILD, RIGHT_CHILD };

/*****************************************
Template class: Node of binary tree
******************************************/
template <class T>
class Node
{
public:
    T value;
    Node * parent, * left, * right;
public:
    Node(const T&, Node* = nullptr);
    bool connect_child(Node*);
    Node* disconnect_child(LoR);
    bool operator+=(Node*);
};
/*****************************************/


template <class T>
bool Node<T>::operator+=(Node* child)
{
    if (child->value < this->value) {
        if (this->left) return false;
        this->left = child;
    }
    else {
        if (this->right) return false;
        this->right = child;
    }
    return true;
}



/*
 Constructor
 -> value of the node and pointer to parent
*/
template <class T>
Node<T>::Node(const T& val, Node* parent)
{
    this->value = val;
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
}



/*
 Connect child node to this node
 -> new child node pointer
 <- true if success, false if subtree already exists
*/
template <class T>
bool Node<T>::connect_child(Node* child)
{
    if (child->value < this->value) {
        if (this->left) return false;
        this->left = child;
    }
    else {
        if (this->right) return false;
        this->right = child;
    }
    return true;
}


/*
 Disconnect child node from this node
 -> what of 2 childs (LEFT_CHILD or RIGHT_CHILD)
 <- pointer to the disconnected child node
*/
template <class T>
Node<T>* Node<T>::disconnect_child(LoR left_or_right)
{
    Node* disconnected = nullptr; 
    if (left_or_right == LEFT_CHILD) {
        disconnected = this->left;
        this->left = nullptr;
    }
    else {
        disconnected = this->right;
        this->right = nullptr;
    }
    return disconnected;
}

