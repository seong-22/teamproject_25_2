#ifndef MANAGER_MODE_H
#define MANAGER_MODE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class ManagerMode {
private:
    map<string, vector<string>> menuCategories; // 카테고리별 메뉴

public:
    void loadMenu();
    void showMenu();
    void addMenu();
    void deleteMenu();
    void saveMenu();
    void run();
};

#endif
