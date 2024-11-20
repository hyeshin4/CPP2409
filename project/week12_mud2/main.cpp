#include <iostream>
#include <string>
#include "user.h"
#include <vector>
using namespace std;

// 맵의 크기
const int mapX = 5;
const int mapY = 5;

void displayMap(const vector<vector<int>>& map, int magicianX, int magicianY, int warriorX, int warriorY) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            // 같은 위치에 두 플레이어가 있는 경우
            if (i == magicianY && j == magicianX && i == warriorY && j == warriorX) {
                cout << "  U   |"; // 두 플레이어가 같은 위치
            }
            // 마법사 위치
            else if (i == magicianY && j == magicianX) {
                cout << "  M   |";
            }
            // 전사 위치
            else if (i == warriorY && j == warriorX) {
                cout << "  W   |";
            }
            // 맵 기본 상태
            else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break; // 6칸 공백
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break; // 양 옆 2칸 공백
                    case 3: cout << " 포션 |"; break; // 양 옆 1칸 공백
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl << " -------------------------------- " << endl;
    }
}


// 메인 함수
int main() {
	// 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    vector<vector<int>> map = { 
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    Magician magician;
    Warrior warrior;

    vector<User*> players = {&magician, &warrior};
    // 각 플레이어의 위치를 저장
    int magicianX = 0, magicianY = 0;
    int warriorX = 0, warriorY = 0; 
    
    int turn = 0;

	// 게임 시작 
   while (true) {
        User* currentPlayer = players[turn % players.size()];
        int& currentX = (turn % players.size() == 0) ? magicianX : warriorX;
        int& currentY = (turn % players.size() == 0) ? magicianY : warriorY;

        displayMap(map, magicianX, magicianY, warriorX, warriorY);
        currentPlayer->takeTurn(map, currentX, currentY, mapX, mapY, *currentPlayer);


        if (currentPlayer->GetHP() <= 0) 
        {
            cout << currentPlayer->getName() << "의 HP가 0 이하가 되어 게임 종료.\n";
            break;
        }
        turn++;
    }

    cout << "게임이 종료되었습니다." << endl;
    return 0;
}
