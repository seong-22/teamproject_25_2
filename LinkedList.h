#pragma once
#include <string>
using namespace std;

class Node {
public:
    typedef string value_type;
private:
    value_type data_field;
    Node* link_field;
public:
    Node(const value_type& init_data = value_type(), Node* init_link = NULL);

    void set_data(const value_type& new_data);
    void set_link(Node* new_link);

    value_type data() const;
    Node* link();
    const Node* link() const;
};

class LinkedList {
private:
    Node* head_ptr;
public:
    LinkedList();
    ~LinkedList();

    void add_front(const Node::value_type& entry); 
    void remove_front();                       
    void remove_after(Node* previous_ptr);

    Node* getHead() const;
    size_t length() const;

    Node* search(const Node::value_type& target);
    void clear();
    void print() const;                           
};