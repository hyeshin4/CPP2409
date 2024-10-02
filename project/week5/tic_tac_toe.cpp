#include <iostream>
using namespace std;

const int numCell = 3;
char board[numCell][numCell]{};

    // 승리 조건 체크
    bool checkWin() {
        for (int i = 0; i < numCell; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') // x축이 빙고인 경우
                return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') // y축이 빙고인 경우 
                return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') //우하강 대각선 빙고
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') //우상향 대각선 빙고
            return true;
        
        return false;
    }

    // 무승부 검사
    bool checkDraw() {
        for (int i = 0; i < numCell; i++) {
            for (int j = 0; j < numCell; j++) {
                if (board[i][j] == ' ') return false; // 빈 칸이 있으면 아직 게임이 끝나지 않음
            }
        }
        return true;
    }


int main() {
    char players[2] = {'X', 'O'}; // 두 플레이어
    int x, y; 
    int turn = 0; // 현재 차례 (0번 플레이어부터 시작)


    for (x = 0; x < numCell; x++){
        for (y = 0; y < numCell; y++){
            board[x][y] = ' ';
        }
    }
    int k = 0; 
    char currentUser = 'X'; 
    while(true) {
        switch (k % 2) {
        case 0:
            cout << "첫번째 유저(X)의 차례입니다 -> ";
            currentUser = 'X';
            break;
        case 1:
            cout << "두번째 유저(O)의 차례입니다 -> ";
            currentUser = 'O';
            break;
        }

        cout << "(x, y) 좌표를 입력하세요: ";
        cin >> y >> x; // x, y 좌표를 입력받은대로 반영하기 위하여 이 코드를 수정했습니다.

        if (x >= numCell || y >= numCell) {
            cout << x << ", " << y << ": ";
            cout << "x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
            continue;
        }
        if (board[x][y] !=' ') {
            cout << x << ", " << y << ": 이미 돌이 차있습니다." << endl;
            continue;
        }

        board[x][y] = currentUser;

        for (int i = 0; i < numCell; i++){
            cout << "---|---|---" << endl;
            for (int j = 0; j < numCell; j++){
                cout << board[i][j];
                if (j == numCell - 1){
                    break;
                }
                cout << "  |";
            }
            cout << endl;
        }
        cout << "---|---|---" << endl;

    // 승리 체크
        if (checkWin()) {
            cout << "Player " << players[turn] << "가 이겼습니다!" << endl;
            break;
        }

        // 무승부 체크
        if (checkDraw()) {
            cout << "무승부 입니다!" << endl;
            break;
        }

        k++;
    }
    return 0;
}

