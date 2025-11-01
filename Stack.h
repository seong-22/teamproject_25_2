#pragma once
#include <iostream>
#include <cassert>
#include "LinkedList.h"
using namespace std;

class Stack {
private:
    Node* top_ptr;
public:
    Stack();
    ~Stack();

    void push(const Node::value_type& entry);
    void pop();

    Node::value_type top() const;
    bool empty() const;
    void print() const;
};
