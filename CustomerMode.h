#ifndef CUSTOMER_MODE_H
#define CUSTOMER_MODE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

class CustomerMode {
private:
    map<string, vector<string>> menuCategories;
    LinkedList orderList;
    Stack deletedOrders;

public:
    void loadMenu();         
    void showMenu();      
    void addOrder();       
    void deleteOrder();   
    void undoDelete();   
    void showOrderList(); 
    void run();           
};

#endif
