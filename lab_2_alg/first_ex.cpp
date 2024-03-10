#include <iostream>
#include <stack>
#include <conio.h> // ��� ������� _getche()

// ������� ��� ���������� ������� � ����
int PUSH(std::stack<char>& stk, char c) {
    stk.push(c);
    return 0; // ������ �������, ��� ��� ���� �� ���������
}

// ������� ��� ���������� ������� �� �����
int POP(std::stack<char>& stk, char& c) {
    if (stk.empty()) {
        return 1; // ���� ����
    }
    c = stk.top();
    stk.pop();
    return 0; // �������
}

// ������� ��� ������� ������ �� ������������ ����������� ������
bool checkBrackets(const std::stack<char>& stk) {
    return stk.empty(); // ���� ������ ���� ������, ���� ��� ������ ��������� �������
}

int main() {
    std::stack<char> stk;

    std::cout << "������� ������ (��� ���������� ������� ������): ";

    while (true) {
        char c = _getche(); // �������� ������ � ���������� � ���������� ��� � �������
        if (c == ' ') {
            break; // ���� ������ ������, ��������� ����
        }
        if (c == '(') {
            PUSH(stk, c);
        }
        else if (c == ')') {
            char top;
            int status = POP(stk, top);
            if (status == 1 || top != '(') {
                std::cout << "\n������ � ����������� ������." << std::endl;
            }
        }
    }

    if (checkBrackets(stk)) {
        std::cout << "\n������ ����������� ���������." << std::endl;
    }
    else {
        std::cout << "\n������ � ����������� ������." << std::endl;
    }

    return 0;
}
