#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;


void n1() {
    string name;
    cout << "Ваше Имя ";
    cin >> name;
    cout << "\n" + name;
}

void n2() {
    float num1, num2, sum, m, p, d;
    cout << "Введите 1 число ";
    cin >> num1;
    cout << "\nВведите 2 число ";
    cin >> num2;
    sum = num2 + num1;
    m = num1 - num2;
    p = num1 * num2;
    if (num2 != 0)
        d = num1 / num2;
    cout << "Сумма " << sum << endl;
    cout << "Разность " << m << endl;
    cout << "Произведение " << p << endl;
    if (num2 != 0) {
        cout << "Частное " << d;
    } else {
        cout << "Нельзя делить на 0";
    }
}

void funcWithTwoArguments(float b, float c) {
    if (b == 0) {
        if (c == 0)
            cout << "X любое";
        if (c != 0)
            cout << "Нет решений";
        return;
    }
    float x = (-c) / b;
    cout << "\nОтвет " << x;
}

void n3() {
    float b, c;
    cout << "Введите число b ";
    cin >> b;
    cout << "\nВведите число c ";
    cin >> c;
    funcWithTwoArguments(b, c);
}

void n4() {
    float a, b, c, x1, x2;
    cout << "Введите число a ";
    cin >> a;
    cout << "Введите число b ";
    cin >> b;
    cout << "Введите число c ";
    cin >> c;
    if (a == 0) {
        funcWithTwoArguments(b, c);
        return;
    }
    else if (b == 0) {
        float rightPath = (-c) / a;
        if (rightPath < 0) {
            cout << "Нет корней";
            return;
        }
        x1 = -sqrt(rightPath);
        x2 = sqrt(rightPath);
    } else if (c == 0) {
        x1 = 0;
        x2 = (-b) / a;
    } else {
        float D = pow(b, 2) - 4 * c * a;
        if (D < 0) {
            cout << "Нет корней";
            return;
        }
        x1 = ((-b) - sqrt(D)) / (2 * a);
        x2 = ((-b) + sqrt(D)) / (2 * a);
    }
    if (x1 == x2) {
        cout << "Есть совпадающий корень " << x1;
    } else {
        cout << "Есть два корня " << x1 << " и " << x2;
    }
}


void n5() {
    string dayAnswer, curtainsAnswer, lampAnswer;
    bool isDay, isCurtainsOpen, isLampOn;
    cout << "На улице день? ";
    cin >> dayAnswer;
    while (dayAnswer != "Да" && dayAnswer != "Нет") {
        cout << "Введите Да или Нет\n";
        cin >> dayAnswer;
    }
    cout << "Шторы открыты? ";
    cin >> curtainsAnswer;
    while (curtainsAnswer != "Да" && curtainsAnswer != "Нет") {
        cout << "Введите Да или Нет\n";
        cin >> curtainsAnswer;
    }
    cout << "Лампа включена? ";
    cin >> lampAnswer;
    while (lampAnswer != "Да" && lampAnswer != "Нет") {
        cout << "Введите Да или Нет\n";
        cin >> lampAnswer;
    }
    isDay = dayAnswer == "Да";
    isCurtainsOpen = curtainsAnswer == "Да";
    isLampOn = lampAnswer == "Да";
    if ((isDay && isCurtainsOpen) || isLampOn) {
        cout << "В комнате светло";
    } else {
        cout << "В комнате темно";
    }
}

int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");

    cout << "Введите номер задания ";
    int taskNumber;
    cin >> taskNumber;
    cout << endl;
    switch (taskNumber)
    {
        case 1:
            n1();
            break;
        case 2:
            n2();
            break;
        case 3:
            n3();
            break;
        case 4:
            n4();
            break;
        case 5:
            n5();
            break;
        default:
            break;
    }

    system("pause");

}
