#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
public:
    virtual ~User() {}
    virtual string getName() const = 0;
    virtual void IncreaseHP(int inc_hp) = 0;
    virtual void DecreaseHP(int dec_hp) = 0;
    virtual int GetHP() const = 0;
    virtual int getItemCnt() const = 0;
    virtual void setItemCnt() = 0;
    virtual void doAttack() const = 0;
    virtual void handlePositionEffect(const vector<vector<int>>& map, int x, int y) = 0;
    virtual bool move(vector<vector<int>>& map, int &x, int &y, int dx, int dy, int mapX, int mapY) = 0;

    static bool checkXY(int x, int y, int mapX, int mapY);
    static bool checkGoal(const vector<vector<int>>& map, int x, int y);

    friend ostream &operator<<(ostream &os, const User &a);
};

class Magician : public User {
private:
    int hp;
    int itemCnt;
    string name;
public:
    Magician();
    string getName() const override;
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() const override;
    int getItemCnt() const override;
    void setItemCnt() override;
    void doAttack() const override;
    void handlePositionEffect(const vector<vector<int>>& map, int x, int y) override;
    bool move(vector<vector<int>>& map, int &x, int &y, int dx, int dy, int mapX, int mapY) override;
};

class Warrior : public User {
private:
    int hp;
    int itemCnt;
    string name;
public:
    Warrior();
    string getName() const override;
    void IncreaseHP(int inc_hp) override;
    void DecreaseHP(int dec_hp) override;
    int GetHP() const override;
    int getItemCnt() const override;
    void setItemCnt() override;
    void doAttack() const override;
    void handlePositionEffect(const vector<vector<int>>& map, int x, int y) override;
    bool move(vector<vector<int>>& map, int &x, int &y, int dx, int dy, int mapX, int mapY) override;
};