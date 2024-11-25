#include "user.h"
#include <iostream>
using namespace std;

ostream &operator<<(ostream &os, const User &a)
{
    os << a.name <<": (현재 HP는 " << a.hp << "이고, 먹은 아이템은 총 " << a.itemCnt << "개 입니다.)" << endl;
    return os;
}

User::User(string name) : name(name), hp(20), itemCnt(0) {}

string User::getName()
{
    return name;
}
void User::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}
void User::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}
int User::GetHP()
{
    return hp;
}
int User::getItemCnt()
{
    return itemCnt;
}
void User::setItemCnt()
{
    itemCnt ++;
}
void User::handlePositionEffect(const vector<vector<int>>& map, int x, int y) {
    switch (map[y][x]) {
        case 1:
            cout << name << "이(가) 아이템을 획득했습니다!" << endl;
            itemCnt++;
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

bool User::checkXY(int x, int y, int mapX, int mapY) {
    return x >= 0 && x < mapX && y >= 0 && y < mapY;
}

bool User::checkGoal(const vector<vector<int>>& map, int x, int y) {
    return map[y][x] == 4;
}

bool User::move(vector<vector<int>>& map, User &player, int &x, int &y, int dx, int dy, int mapX, int mapY) {
    // 이동한 위치
    int newX = x + dx;
    int newY = y + dy;
    if (checkXY(newX, newY, mapX, mapY)) {
        x = newX;
        y = newY;
        player.DecreaseHP(1);
        //hp -= 1; // 체력 -1
        handlePositionEffect(map, x, y); // 아이템-적과 만났을 때 상호작용
        return true;
    } else {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl; //맵을 벗어나는 입력을 받은 경우
        return false;
    }
}


void User::doAttack()
{
    cout << "공격합니다" << endl;
}


string Magician::getName()
{
    return name;
}
void Magician::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}
void Magician::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}
int Magician::GetHP()
{
    return hp;
}
int Magician::getItemCnt()
{
    return itemCnt;
}
void Magician::setItemCnt()
{
    itemCnt ++;
}
void Magician::handlePositionEffect(const vector<vector<int>>& map, int x, int y) {
    switch (map[y][x]) {
        case 1:
            cout << name << "이(가) 아이템을 획득했습니다!" << endl;
            itemCnt++;
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

bool Magician::checkXY(int x, int y, int mapX, int mapY) {
    return x >= 0 && x < mapX && y >= 0 && y < mapY;
}

bool Magician::checkGoal(const vector<vector<int>>& map, int x, int y) {
    return map[y][x] == 4;
}

bool Magician::move(vector<vector<int>>& map, User &player, int &x, int &y, int dx, int dy, int mapX, int mapY) {
    // 이동한 위치
    int newX = x + dx;
    int newY = y + dy;
    if (checkXY(newX, newY, mapX, mapY)) {
        x = newX;
        y = newY;
        player.DecreaseHP(1);
        //hp -= 1; // 체력 -1
        handlePositionEffect(map, x, y); // 아이템-적과 만났을 때 상호작용
        return true;
    } else {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl; //맵을 벗어나는 입력을 받은 경우
        return false;
    }
}

void Magician::doAttack() override
{
    cout << "마법 사용" << endl;

}


string Warrior::getName()
{
    return name;
}
void Warrior::IncreaseHP(int inc_hp)
{
    hp += inc_hp;
}
void Warrior::DecreaseHP(int dec_hp)
{
    hp -= dec_hp;
}
int Warrior::GetHP()
{
    return hp;
}
int Warrior::getItemCnt()
{
    return itemCnt;
}
void Warrior::setItemCnt()
{
    itemCnt ++;
}
void Warrior::handlePositionEffect(const vector<vector<int>>& map, int x, int y) {
    switch (map[y][x]) {
        case 1:
            cout << name << "이(가) 아이템을 획득했습니다!" << endl;
            itemCnt++;
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

bool Warrior::checkXY(int x, int y, int mapX, int mapY) {
    return x >= 0 && x < mapX && y >= 0 && y < mapY;
}

bool Warrior::checkGoal(const vector<vector<int>>& map, int x, int y) {
    return map[y][x] == 4;
}

bool Warrior::move(vector<vector<int>>& map, User &player, int &x, int &y, int dx, int dy, int mapX, int mapY) {
    // 이동한 위치
    int newX = x + dx;
    int newY = y + dy;
    if (checkXY(newX, newY, mapX, mapY)) {
        x = newX;
        y = newY;
        player.DecreaseHP(1);
        //hp -= 1; // 체력 -1
        handlePositionEffect(map, x, y); // 아이템-적과 만났을 때 상호작용
        return true;
    } else {
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl; //맵을 벗어나는 입력을 받은 경우
        return false;
    }
}

void Warrior::doAttack() override
{
    cout << "베기 사용" << endl;
}