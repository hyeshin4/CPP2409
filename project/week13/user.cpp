#include "user.h"

bool User::checkXY(int x, int y, int mapX, int mapY) {
    return x >= 0 && x < mapX && y >= 0 && y < mapY;
}

bool User::checkGoal(const vector<vector<int>>& map, int x, int y) {
    return map[y][x] == 4;
}

ostream &operator<<(ostream &os, const User &a) {
    os << a.getName() << ": (현재 HP는 " << a.GetHP() 
       << "이고, 먹은 아이템은 총 " << a.getItemCnt() << "개 입니다.)" << endl;
    return os;
}

Magician::Magician() : hp(20), itemCnt(0), name("마법사") {}

string Magician::getName() const { return name; }
void Magician::IncreaseHP(int inc_hp) { hp += inc_hp; }
void Magician::DecreaseHP(int dec_hp) { hp -= dec_hp; }
int Magician::GetHP() const { return hp; }
int Magician::getItemCnt() const { return itemCnt; }
void Magician::setItemCnt() { itemCnt++; }
void Magician::doAttack() const { cout << name << "마법 사용" << endl; }
void Magician::handlePositionEffect(const vector<vector<int>>& map, int x, int y) {
    switch (map[y][x]) {
        case 1:
            cout << name << "이(가) 아이템을 획득했습니다!" << endl;
            setItemCnt();
            break;
        case 2:
            cout << name << "이(가) 적을 만났습니다. HP가 2 감소합니다." << endl;
            DecreaseHP(2);
            break;
        case 3:
            cout << name << "이(가) 포션을 획득했습니다. HP가 2 증가합니다." << endl;
            IncreaseHP(2);
            break;
        default:
            break;
    }
}

bool Magician::move(vector<vector<int>>& map, int &x, int &y, int dx, int dy, int mapX, int mapY) {
    int newX = x + dx;
    int newY = y + dy;
    if (checkXY(newX, newY, mapX, mapY)) {
        x = newX;
        y = newY;
        DecreaseHP(1); // 체력 -1
        handlePositionEffect(map, x, y);
        return true;
    } else {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return false;
    }
}

// Warrior methods (similar to Magician)
Warrior::Warrior() : hp(20), itemCnt(0), name("전사") {}

string Warrior::getName() const { return name; }
void Warrior::IncreaseHP(int inc_hp) { hp += inc_hp; }
void Warrior::DecreaseHP(int dec_hp) { hp -= dec_hp; }
int Warrior::GetHP() const { return hp; }
int Warrior::getItemCnt() const { return itemCnt; }
void Warrior::setItemCnt() { itemCnt++; }
void Warrior::doAttack() const { cout << name << "베기 사용" << endl; }
void Warrior::handlePositionEffect(const vector<vector<int>>& map, int x, int y) {
    switch (map[y][x]) {
        case 1:
            cout << name << "이(가) 아이템을 획득했습니다!" << endl;
            setItemCnt();
            break;
        case 2:
            cout << name << "이(가) 적을 만났습니다. HP가 2 감소합니다." << endl;
            DecreaseHP(2);
            break;
        case 3:
            cout << name << "이(가) 포션을 획득했습니다. HP가 2 증가합니다." << endl;
            IncreaseHP(2);
            break;
        default:
            break;
    }
}

bool Warrior::move(vector<vector<int>>& map, int &x, int &y, int dx, int dy, int mapX, int mapY) {
    int newX = x + dx;
    int newY = y + dy;
    if (checkXY(newX, newY, mapX, mapY)) {
        x = newX;
        y = newY;
        DecreaseHP(1); // 체력 -1
        handlePositionEffect(map, x, y);
        return true;
    } else {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
        return false;
    }
}
