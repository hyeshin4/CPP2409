#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
protected:
    int hp;
    int itemCnt; // 아이템 먹은 횟수를 저장하는 변수
    string name;
public:
    User(string name);
    string getName();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();   
    friend ostream &operator<<(ostream &os, const User &a);
    int getItemCnt();
    void setItemCnt();
    void doAttack();
    void handlePositionEffect(const vector<vector<int>>& map, int x, int y);
    static bool checkXY(int x, int y, int mapX, int mapY);
    static bool checkGoal(const vector<vector<int>>& map, int x, int y);
    bool move(vector<vector<int>>& map, User &player, int &x, int &y, int dx, int dy,int mapX, int mapY);

};

class Magician : public User{
public:
    Magician() : User("M") {}
    void doAttack();
};

class Warrior : public User{
public:
    Warrior() : User("W") {}
    void doAttack();
};