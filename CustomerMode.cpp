#define _CRT_SECURE_NO_WARNINGS
#include "CustomerMode.h"
#include "LinkedList.h"
#include "Stack.h"
#include <fstream> 

void CustomerMode::loadMenu() {
    ifstream fin("menu.txt");
    if (!fin) {
        cout << "menu.txt 파일을 찾을 수 없습니다.\n";
        return;
    }

    string line, currentCategory;
    while (getline(fin, line)) {
        if (line.empty()) continue;
        if (line[0] == '[') {
            currentCategory = line.substr(1, line.size() - 2);
        }
        else {
            menuCategories[currentCategory].push_back(line);
        }
    }
    fin.close();
}

void CustomerMode::showMenu() {
    cout << "\n=== 메뉴 목록 ===\n";
    for (auto& cat : menuCategories) {
        cout << "\n[" << cat.first << "]\n";
        for (int i = 0; i < cat.second.size(); i++) {
            cout << i + 1 << ". " << cat.second[i] << endl;
        }
    }
}

void CustomerMode::addOrder() {
    string item;
    cout << "추가할 메뉴 이름을 입력하세요: ";
    cin.ignore();
    getline(cin, item);

    orderList.add_front(item);
    cout << "--> " << item << " 주문에 추가되었습니다.\n";
}

void CustomerMode::deleteOrder() {
    string item;
    cout << "삭제할 메뉴 이름을 입력하세요: ";
    cin.ignore();
    getline(cin, item);

    Node* cursor = orderList.search(item);
    if (cursor) {
        Node* prev = NULL;
        Node* current = orderList.getHead();

        while (current && current->data() != item) {
            prev = current;
            current = current->link();
        }

        if (current) {
            if (prev == NULL) {
                orderList.remove_front();
            }
            else {
                orderList.remove_after(prev);
            }

            deletedOrders.push(item);
            cout << "--> " << item << " 주문에서 삭제되었습니다.\n";
        }
    }
    else {
        cout << "해당 메뉴가 주문 목록에 없습니다.\n";
    }
}

void CustomerMode::undoDelete() {
    if (!deletedOrders.empty()) {
        string restored = deletedOrders.top();
        deletedOrders.pop();                   
        orderList.add_front(restored);      
        cout << "--> " << restored << " 주문이 복구되었습니다.\n";
    }
    else {
        cout << "되돌릴 항목이 없습니다.\n";
    }
}

void CustomerMode::showOrderList() {
    cout << "\n 현재 주문 목록:\n";
    orderList.print();
}

void CustomerMode::run() {
    loadMenu();
    int choice;
    do {
        cout << "\n=== 손님용 모드 ===\n"
            << "1. 메뉴 보기\n"
            << "2. 주문 추가\n"
            << "3. 주문 삭제\n"
            << "4. 되돌리기\n"
            << "5. 주문 목록 보기\n"
            << "0. 종료\n"
            << "선택: ";
        cin >> choice;

        switch (choice) {
        case 1: showMenu(); break;
        case 2: addOrder(); break;
        case 3: deleteOrder(); break;
        case 4: undoDelete(); break;
        case 5: showOrderList(); break;
        }
    } while (choice != 0);
}
