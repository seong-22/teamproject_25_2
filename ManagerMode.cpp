#define _CRT_SECURE_NO_WARNINGS
#include "ManagerMode.h"
#include "LinkedList.h"
#include "Stack.h"
#include <fstream>

void ManagerMode::loadMenu() {
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

void ManagerMode::showMenu() {
    cout << "\n=== 현재 메뉴 ===\n";
    for (auto& cat : menuCategories) {
        cout << "\n[" << cat.first << "]\n";
        for (auto& item : cat.second) {
            cout << "- " << item << endl;
        }
    }
}

void ManagerMode::addMenu() {
    string category, item;
    cout << "추가할 카테고리 입력 (커피/논커피/티/에이드/스무디): ";
    cin >> category;
    cin.ignore();

    cout << "추가할 메뉴 이름 입력: ";
    getline(cin, item);

    menuCategories[category].push_back(item);
    cout << "--> " << item << " 이(가) 추가되었습니다.\n";
}

void ManagerMode::deleteMenu() {
    string category, item;
    cout << "삭제할 카테고리 입력: ";
    cin >> category;
    cin.ignore();

    cout << "삭제할 메뉴 이름 입력: ";
    getline(cin, item);

    auto& list = menuCategories[category];
    for (auto it = list.begin(); it != list.end(); ++it) {
        if (*it == item) {
            list.erase(it);
            cout << "--> " << item << " 이(가) 삭제되었습니다.\n";
            return;
        }
    }
    cout << "해당 메뉴를 찾을 수 없습니다.\n";
}

void ManagerMode::saveMenu() {
    ofstream fout("menu.txt");
    for (auto& cat : menuCategories) {
        fout << "[" << cat.first << "]\n";
        for (auto& item : cat.second) {
            fout << item << "\n";
        }
        fout << "\n";
    }
    fout.close();
    cout << "메뉴가 menu.txt에 저장되었습니다.\n";
}

void ManagerMode::run() {
    loadMenu();
    int choice;
    do {
        cout << "\n=== 매장용 모드 ===\n"
            << "1. 메뉴 보기\n"
            << "2. 메뉴 추가\n"
            << "3. 메뉴 삭제\n"
            << "4. 메뉴 저장\n"
            << "0. 종료\n"
            << "선택: ";
        cin >> choice;

        switch (choice) {
        case 1: showMenu(); break;
        case 2: addMenu(); break;
        case 3: deleteMenu(); break;
        case 4: saveMenu(); break;
        }
    } while (choice != 0);
}
