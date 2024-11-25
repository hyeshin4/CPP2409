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
    virtual string getName();
    virtual void IncreaseHP(int inc_hp);
    virtual void DecreaseHP(int dec_hp);
    virtual int GetHP();   
    friend ostream &operator<<(ostream &os, const User &a);
    virtual int getItemCnt();
    virtual void setItemCnt();
    virtual void doAttack();
    virtual void handlePositionEffect(const vector<vector<int>>& map, int x, int y);
    static bool checkXY(int x, int y, int mapX, int mapY);
    static bool checkGoal(const vector<vector<int>>& map, int x, int y);
    virtual bool move(vector<vector<int>>& map, User &player, int &x, int &y, int dx, int dy,int mapX, int mapY);

};

class Magician : public User{
public:
    Magician() : User("M") {}
    void doAttack() override;
};

class Warrior : public User{
public:
    Warrior() : User("W") {}
    void doAttack() override;
};