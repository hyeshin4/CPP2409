#include <iostream>
using namespace std;

const int numCell = 5; // 보드판의 가로 세로 길이

// 좌표가 유효한지 확인하는 함수
int isValid(int x, int y, char board[numCell][numCell]) {
    if (x >= numCell || y >= numCell) { // 좌표 범위를 벗어날 때
        cout << x << "," << y << ": x와 y 둘 중 하나가 칸을 벗어납니다." << endl;
        return 1;
    } else if (board[x][y] != ' ') { // 이미 돌이 놓인 칸일 때
        cout << x << "," << y << ": 이미 돌이 차 있습니다." << endl;
        return 2;
    }
    return 0; // 유효한 좌표일 때
}


// 승리 여부를 체크하는 함수
bool checkWin(char board[numCell][numCell], char currentUser) {
    // 가로, 세로 검사
    for (int i = 0; i < numCell; i++) {
        bool rowWin = true, colWin = true;
        for (int j = 0; j < numCell; j++) {
            if (board[i][j] != currentUser) rowWin = false;
            if (board[j][i] != currentUser) colWin = false;
        }
        if (rowWin || colWin) return true;
    }

    // 우하향 대각선 검사
    bool diagWin1 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][i] != currentUser) {
            diagWin1 = false;
            break;
        }
    }
    if (diagWin1) return true;

    // 우상향 대각선 검사
    bool diagWin2 = true;
    for (int i = 0; i < numCell; i++) {
        if (board[i][numCell - 1 - i] != currentUser) {
            diagWin2 = false;
            break;
        }
    }
    return diagWin2;
}

int main() {
	// 게임을 진행하는 데 필요한 변수 선언
	int k = 0; // 누구 차례인지 체크하기 위한 변수
	char currentUser = 'X'; // 현재 유저의 돌을 저장하기 위한 변수
	char board[numCell][numCell]{}; // 보드판을 나타내는 2차원 배열

	// 보드판 초기화
	for (int i = 0; i < numCell; i++) {
		for (int j = 0; j < numCell; j++) {
			board[i][j] = ' ';
		}
	}

	// 게임을 무한 반복
	while (true) {
		// 1. 누구 차례인지 출력
            int k = 0; 
            int turn=0;
        char currentUser = 'X'; 
        while(true) {
            switch (k % 3) {
            case 0:
                currentUser = 'X';
                turn = 0;
                break;
            case 1:
                currentUser = 'O';
                turn = 1;
                break;
            case 2:
                currentUser = 'V';
                turn = 2;
                break;
            
        }


		// TODO 1.1: 3인용 게임으로 변경
		switch (k % 3) {
		case 0:
			currentUser = 'X';
			break;
		case 1:			
			currentUser = 'O';
			break;
        case 3:			
			currentUser = 'H';
			break;
		}
		cout << k % 3 + 1 << "번 유저("<< currentUser <<")의 차례입니다. -> ";

		// 2. 좌표 입력 받기
		cout << "(x, y) 좌표를 입력하세요: ";
		int x, y;
		cin >> x >> y;

		// 3. 입력받은 좌표의 유효성 체크
		// TODO FUNC 1: isValid 함수 생성 후 호출
        int validity = isValid(x, y, board);
        if (validity == 0) {
        } else if (validity == 1 || validity == 2) {
            continue;  
        }


		// 4. 입력받은 좌표에 현재 유저의 돌 놓기
		board[x][y] = currentUser;

		// 5. 현재 보드 판 출력
		// TODO 1.2: numCell 숫자에 맞춘 보드판 출력
		for (int i = 0; i < numCell; i++) {
            for ( int i = 0; i < numCell -1; i++ ){
			    cout << "---|" ;}
            cout << "---" << endl;
			for (int j = 0; j < numCell; j++)
			{
				cout << board[i][j];
				if (j == numCell - 1) {
					break;
				}
				cout << "  |";
			}
			cout << endl;
		}
	    for ( int i = 0; i < numCell -1; i++ ){
		    cout << "---|" ;}
        cout << "---"<<endl;



		bool isWin = false; // 승리 여부
		// TODO FUNC2: 6.1부터 6.2까지 checkWin 함수 생성 후 호출
        // 승리 조건 확인
        if (checkWin(board, currentUser)) {
            cout << "플레이어 " << currentUser << "가 승리했습니다!" << endl;
            break;
        }

		// 7. 모든 칸 다 찼는지 체크하기
		int checked = 0;
		for (int i = 0; i < numCell; i++) {
			for (int j = 0; j < numCell; j++) {
				if (board[i][j] == ' ') {
					checked++;
				}
			}
		}
		if (checked == 0) {
			cout << "모든 칸이 다 찼습니다.  종료합니다. " << endl;
			break;
		}

		k++;
	}

	return 0;
}
}