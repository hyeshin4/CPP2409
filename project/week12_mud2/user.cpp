#include "user.h"
#include <iostream>
using namespace std;

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
ostream &operator<<(ostream &os, const User &a)
{
    os << a.name <<": (현재 HP는 " << a.hp << "이고, 먹은 아이템은 총 " << a.itemCnt << "개 입니다.)" << endl;
    return os;
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

void User::takeTurn(vector<vector<int>>& map, int& x, int& y, int mapX, int mapY, const User &player) {
    cout <<"현재 HP: "<< player.hp << " 명령어를 입력하세요 (상, 하, 좌, 우, 종료, 정보): ";
    string user_input;
    cin >> user_input;

    int dx = 0, dy = 0;
    if (user_input == "상") dy = -1;
    else if (user_input == "하") dy = 1;
    else if (user_input == "좌") dx = -1;
    else if (user_input == "우") dx = 1;
    else if (user_input == "종료") {
        cout << name << "이(가) 게임을 종료합니다." << endl;
        hp = 0; // 게임 종료 조건
        return;
    } 
    else if (user_input == "정보"){
        cout << player << endl;
        return;
    }

    else {
        cout << "잘못된 입력입니다." << endl;
        return;
    }

    int newX = x + dx;
    int newY = y + dy;

    if (checkXY(newX, newY, mapX, mapY)) {
        x = newX;
        y = newY;
        DecreaseHP(1); // 이동 시 HP 감소
        handlePositionEffect(map, x, y);

        if (checkGoal(map, x, y)) {
            cout << name << "이(가) 목적지에 도달했습니다!" << endl;
            hp = 0; // 게임 종료 조건
        }
    } else {
        cout << "맵을 벗어났습니다!" << endl;
    }
}

void User::doAttack()
{
    cout << "공격합니다" << endl;
}

void Magician::doAttack()
{
    cout << "마법 사용" << endl;

}

void Warrior::doAttack()
{
    cout << "베기 사용" << endl;
}