#include "user.h"

User::User()
{
    hp = 20;
    itemCnt = 0; // 아이템 먹은 횟수를 저장하는 변수
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
    os << "(현재 HP는 " << a.hp << "이고, 먹은 아이템은 총 " << a.itemCnt << "개 입니다.)" << endl;
    return os;
}