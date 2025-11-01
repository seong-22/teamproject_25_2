#include "Stack.h"

Stack::Stack() : top_ptr(nullptr) {}

Stack::~Stack() {
    while (!empty()) pop();
}

void Stack::push(const Node::value_type& entry) {
    top_ptr = new Node(entry, top_ptr);
}

void Stack::pop() {
    assert(!empty());
    Node* temp = top_ptr;
    top_ptr = top_ptr->link();
    delete temp;
}

Node::value_type Stack::top() const {
    assert(!empty());
    return top_ptr->data();
}

bool Stack::empty() const {
    return top_ptr == nullptr;
}

void Stack::print() const {
    Node* cursor = top_ptr;
    cout << "Stack ³»¿ë:\n";
    while (cursor) {
        cout << "- " << cursor->data() << "\n";
        cursor = cursor->link();
    }
}
