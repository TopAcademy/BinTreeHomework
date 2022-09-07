#pragma once

enum { LEFT_CHILD, RIGHT_CHILD };

/*****************************************
Class: Node of binary tree
******************************************/
class Node
{
public:
    int value;
    Node * parent, * left, * right;
public:
    Node(int, Node*);
    Node* get_child(int);
    bool connect_child(Node*);
    Node* disconnect_child(int);
};
/*****************************************/


/*
 Constructor
 -> value of the node and pointer to parent
*/
Node::Node(int val, Node* parent = nullptr)
{
    this->value = val;
    this->parent = parent;
    this->left = nullptr;
    this->right = nullptr;
}


/*
 Get pointer to child node (left or right)
 -> what childe (LEFT_CHILD or RIGHT_CHILD)
 <- pointer to the child
*/
Node* Node::get_child(int left_or_right)
{
    if (left_or_right == LEFT_CHILD) return this->left;
    else return this->right;
}


/*
 Connect child node to this node
 -> new child node pointer
 <- true if success, false if subtree already exists
*/
bool Node::connect_child(Node* child)
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
Node* Node::disconnect_child(int left_or_right)
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

