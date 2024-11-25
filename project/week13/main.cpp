#include "user.h"
#include <iostream>
#include <vector>
using namespace std;

const int mapX = 5;
const int mapY = 5;

void displayMap(const vector<vector<int>>& map,int choice, int playerX, int playerY) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == playerY && j == playerX) {
                if( choice == 1){
                    cout << "  M   |";
                }
                else{
                    cout << "  W   |";
                }
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << "\n--------------------------------\n";
    }
}

int main() {
    vector<vector<int>> map = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    User* player;
    cout << "직업을 선택하세요 (1: 마법사, 2: 전사): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        player = new Magician();
    } else if (choice == 2) {
        player = new Warrior();
    } else {
        cout << "잘못된 입력입니다. 게임을 종료합니다.\n";
        return 0;
    }

    int playerX = 0, playerY = 0;
    while (true) {
        cout << "\n" << player->getName() << "의 차례입니다. 명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료): ";
        string command;
        cin >> command;

        if (command == "상") {
            player->move(map, playerX, playerY, 0, -1, mapX, mapY);
        } else if (command == "하") {
            player->move(map, playerX, playerY, 0, 1, mapX, mapY);
        } else if (command == "좌") {
            player->move(map, playerX, playerY, -1, 0, mapX, mapY);
        } else if (command == "우") {
            player->move(map, playerX, playerY, 1, 0, mapX, mapY);
        } else if (command == "지도") {
            displayMap(map, choice, playerX, playerY);
        } else if (command == "정보") {
            cout << *player;
        } else if (command == "종료") {
            cout << "게임을 종료합니다.\n";
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력하세요.\n";
        }

        if (player->checkGoal(map, playerX, playerY)) {
            cout << "목적지에 도착했습니다! 축하합니다!\n게임을 종료합니다.\n";
            break;
        }
    }

    delete player;
    return 0;
}
