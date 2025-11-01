#include "LinkedList.h"
#include <iostream>
#include <cassert>
using namespace std;


Node::Node(const value_type& init_data, Node* init_link) {
    data_field = init_data;
    link_field = init_link;
}

void Node::set_data(const value_type& new_data) { data_field = new_data; }
void Node::set_link(Node* new_link) { link_field = new_link; }

Node::value_type Node::data() const { return data_field; }
Node* Node::link() { return link_field; }
const Node* Node::link() const { return link_field; }


LinkedList::LinkedList() : head_ptr(nullptr) {}
LinkedList::~LinkedList() { clear(); }

void LinkedList::add_front(const Node::value_type& entry) {
    head_ptr = new Node(entry, head_ptr);
}

void LinkedList::remove_front() {
    assert(head_ptr != nullptr);

    Node* temp = head_ptr;
    head_ptr = head_ptr->link();
    delete temp;
}

void LinkedList::remove_after(Node* previous_ptr) {
    if (previous_ptr && previous_ptr->link()) {
        Node* temp = previous_ptr->link();
        previous_ptr->set_link(temp->link());
        delete temp;
    }
}

Node* LinkedList::getHead() const { return head_ptr; }

size_t LinkedList::length() const {
    size_t count = 0;
    Node* cursor = head_ptr;
    for (; cursor != NULL; cursor = cursor->link()) {
        ++count;
    }
    return count;
}

Node* LinkedList::search(const Node::value_type& target) {
    Node* cursor = head_ptr;
    while (cursor != NULL) {
        if (cursor->data() == target) return cursor;
        cursor = cursor->link();
    }
    return nullptr;
}

void LinkedList::clear() {
    while (head_ptr != NULL) remove_front();
}

void LinkedList::print() const {
    if (!head_ptr) {
        cout << "주문이 없습니다.\n";
        return;
    }
    Node* cursor = head_ptr;
    cout << "\n현재 주문 목록:\n";
    while (cursor != NULL) {
        cout << "- " << cursor->data() << "\n";
        cursor = cursor->link();
    }
}
