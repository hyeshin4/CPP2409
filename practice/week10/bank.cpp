#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    double balance;           // 잔액은 외부에서 직접 수정되지 않도록 private로 설정.
    string accountHolderName;  // 계좌 소유자 이름을 저장할 변수

public:
    // 생성자
    BankAccount(string name, double initialBalance) {
        accountHolderName = name;
        balance = initialBalance;
    }

    // 현재 잔액 조회 메서드
    double getBalance() const {
        return balance;
    }

    // 입금 메서드
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << amount << " deposited. Current balance: " << balance << endl;
        }
    }

    // 출금 메서드
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << amount << " withdrawn. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
};

int main() {
    // 계좌 생성
    BankAccount myAccount("Alice", 1000);
    
    // 잔액 조회
    cout << "Initial Balance: " << myAccount.getBalance() << endl;
    
    // 입금 및 출금
    myAccount.deposit(500);
    myAccount.withdraw(200);

    // 직접 접근 시도 (불가능)
    // myAccount.balance = 5000; // 오류: private 멤버에 접근 불가
    // myAccount.accountHolderName = "Bob"; // 오류: private 멤버에 접근 불가

    return 0;
}
