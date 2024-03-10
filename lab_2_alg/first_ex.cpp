#include <iostream>
#include <stack>
#include <conio.h> // Для функции _getche()

// Функция для добавления символа в стек
int PUSH(std::stack<char>& stk, char c) {
    stk.push(c);
    return 0; // Всегда успешно, так как стек не ограничен
}

// Функция для извлечения символа из стека
int POP(std::stack<char>& stk, char& c) {
    if (stk.empty()) {
        return 1; // Стек пуст
    }
    c = stk.top();
    stk.pop();
    return 0; // Успешно
}

// Функция для анализа строки на правильность расстановки скобок
bool checkBrackets(const std::stack<char>& stk) {
    return stk.empty(); // Стек должен быть пустым, если все скобки правильно закрыты
}

int main() {
    std::stack<char> stk;

    std::cout << "Введите строку (для завершения введите пробел): ";

    while (true) {
        char c = _getche(); // Получаем символ с клавиатуры и отображаем его в консоли
        if (c == ' ') {
            break; // Если введен пробел, завершаем цикл
        }
        if (c == '(') {
            PUSH(stk, c);
        }
        else if (c == ')') {
            char top;
            int status = POP(stk, top);
            if (status == 1 || top != '(') {
                std::cout << "\nОшибка в расстановке скобок." << std::endl;
            }
        }
    }

    if (checkBrackets(stk)) {
        std::cout << "\nСкобки расставлены правильно." << std::endl;
    }
    else {
        std::cout << "\nОшибка в расстановке скобок." << std::endl;
    }

    return 0;
}
