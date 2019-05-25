#include <iostream>
#include <string>
#include <sstream>
#include "node.h"

// Operators overloading.

std::ostream& operator<< (std::ostream& stream, Node& node)
{
    std::stringstream ss;
    ss << node.getFrequency();

    std::string text = "(";
    text += node.getSymbol();
    text += ",";
    text += ss.str();
    text += ")";

    return stream << text;
}

// Constructors.

Node::Node()
{
    this->symbol = '\0';
    this->frequency = 0;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char symbol, int frequency)
{
    this->symbol = symbol;
    this->frequency = frequency;
    this->prev = NULL;
    this->next = NULL;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(char symbol, int frequency, Node* prev, Node* next)
{
    this->symbol = symbol;
    this->frequency = frequency;
    this->prev = prev;
    this->next = next;
    this->left = NULL;
    this->right = NULL;
}

Node::Node(int frequency, Node* left, Node* right)
{
    this->symbol = '\0';
    this->frequency = frequency;
    this->prev = NULL;
    this->next = NULL;
    this->left = left;
    this->right = right;
}

Node::Node(char symbol, int frequency, Node* prev, Node* next, Node* left, Node* right)
{
    this->symbol = symbol;
    this->frequency = frequency;
    this->prev = prev;
    this->next = next;
    this->left = left;
    this->right = right;
}

// Methods.

void Node::setSymbol(char symbol)
{
    this->symbol = symbol;
}

char Node::getSymbol()
{
    return this->symbol;
}

void Node::setFrequency(int frequency)
{
    this->frequency = frequency;
}

int Node::getFrequency()
{
    return this->frequency;
}

void Node::setLeft(Node* left)
{
    this->left = left;
}

Node* Node::getLeft()
{
    return this->left;
}

void Node::setRight(Node* right)
{
    this->right = right;
}

Node* Node::getRight()
{
    return this->right;
}

void Node::setPrev(Node* prev)
{
    this->prev = prev;
}

Node* Node::getPrev()
{
    return this->prev;
}

void Node::setNext(Node* next)
{
    this->next = next;
}

Node* Node::getNext()
{
    return this->next;
}

void Node::print()
{
    std::cout << *this;
}

bool Node::isLeaf()
{
    return this->left == NULL && this->right == NULL;
}
