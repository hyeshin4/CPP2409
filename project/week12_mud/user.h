#include <iostream>
using namespace std;

class User {
private:
    int hp;
    int itemCnt; // 아이템 먹은 횟수를 저장하는 변수
public:
    User();
    void IncreaseHP(int inc_hp);
    void DecreaseHP(int dec_hp);
    int GetHP();   
    friend ostream &operator<<(ostream &os, const User &a);
    int getItemCnt();
    void setItemCnt();
};