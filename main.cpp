#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CustomerMode.h"
#include "ManagerMode.h"
#include "LinkedList.h"
#include "Stack.h"
using namespace std;

int main() {
    int mode;
    cout << "모드 선택 (1. 손님용 / 2. 매장용): ";
    cin >> mode;

    if (mode == 1) {
        CustomerMode customer;
        customer.run();
    }
    else if (mode == 2) {
        ManagerMode manager;
        manager.run();
    }
    else {
        cout << "잘못된 선택입니다.\n";
    }

    return 0;
}
