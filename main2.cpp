#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;

class Dz2{

public:
    void ChooseTasks(){
        int taskNumber = TakeTaskNumber();

        while (taskNumber != 0){
            StartChosenTask(taskNumber);
            taskNumber = TakeTaskNumber();
        }
    }

private:
    void ConeTask1(){
        float V, S, R, r, h, l;

        cout << "Введите R" << endl;
        cin >> R;
        cout << "Введите r" << endl;
        cin >> r;
        cout << "Введите h" << endl;
        cin >> h;
//        cout << "Введите l" << endl;
//        cin >> l;

        l = sqrt(pow(R-r, 2) + pow(h, 2));

        if (l <= 0 || h <= 0 || r <= 0 || R <= 0 || (h >= l)){
            cout << "Усеченного конуса при данных значениях не существует" << endl;
            ConeTask1();
            return;
        }

        V = 1.0f/3*M_PI*h*(pow(R, 2) + R*r + pow(r, 2));
        S = M_PI*(pow(R, 2) + (R + r) * l + pow(r, 2));

        cout << "Объем V = " << V << endl;
        cout << "Полная поверхность S = " << S << endl;
        cout << "Образующая l = " << l << endl;
    }

private:
    void BranchingTask2(){
        float w, x, a;

        cout << "Введите x" << endl;
        cin >> x;
        cout << "Введите a" << endl;
        cin >> a;

        x = abs(x);

        if (x < 1){
            w = a * log(x);
            if (x <= 0){
                cout << "Нет корней"<< endl;
                return;
            }
            cout << "w = " << w << endl;
        }else{
            float f = a - pow(x, 2);
            if (f >= 0){
                w = sqrt(f);
                cout << "w = " << w << endl;
            }else{
                cout << "Корней нет" << endl;
            }
        }
    }

private:
    void FunctionTask3(){
        float z, x, y, b;

        cout << "Введите x" << endl;
        cin >> x;
        cout << "Введите y" << endl;
        cin >> y;
        cout << "Введите b" << endl;
        cin >> b;

        float f1 = b - y;
        float f2 = b - x;
        if (f1 <= 0 or f2 < 0){
            cout << "Корней нет" << endl;
        } else {
            z = log(f1) * sqrt(f2);
            cout << "z = " << z << endl;
        }
    }

private:
    void OrderTask4(){
        int N, count;

        cout << "Введите N" << endl;
        cin >> N;

        if (N <= 0){
            cout << "Не натуральное число" << endl;
            OrderTask4();
            return;
        }

        count = 9;

        for (int i = N; i <= N + count; i++){
            cout << i << endl;
        }
    }

private:
    void TabulationTask5(){
        float y, x;
        COORD cPos;
        HANDLE hCon;
        CONSOLE_SCREEN_BUFFER_INFO consoleCursorPos;

        hCon = GetStdHandle(STD_OUTPUT_HANDLE);
        x = -4;

        cout << "y" << endl;
        cout << "x";


        while (x <= 4) {
            GetConsoleScreenBufferInfo(hCon, &consoleCursorPos);
            cPos.X = consoleCursorPos.dwCursorPosition.X;
            cPos.Y = consoleCursorPos.dwCursorPosition.Y;
            cPos.Y -= 1;
            y = (float)(pow(x, 2) - 2*x + 2) / (x - 1);
            cPos.X += 7;
            SetConsoleCursorPosition(hCon, cPos);
            if (x == 1){
                cout << "|Div by 0";
            } else {
                cout << "|" << y;
            }
            cPos.Y += 1;
            SetConsoleCursorPosition(hCon, cPos);
            cout << "|" << x;
            x += 0.5;
        }
        cout << endl;
    }

private:
    void TabulationTask5Easy(){
        float y, x;
        x = -4;

        cout << "y x" << endl;

        while (x <= 4){
            y = (float)(pow(x, 2) - 2*x + 2) / (x - 1);
            if (x == 1){
                cout << "Div by 0";
            } else {
                cout << y;
            }
            cout << " | " << x << endl;
            x += 0.5;
        }
    }

private:
    int TakeTaskNumber(){
        cout << "Введите номер задания. Для завершения программы введите \"0\"." << endl;

        int taskNumber;
        cin >> taskNumber;

        return taskNumber;
    }

private:
    void StartChosenTask(int taskNumber){

        switch (taskNumber)
        {
            case 1:
                ConeTask1();
                break;
            case 2:
                BranchingTask2();
                break;
            case 3:
                FunctionTask3();
                break;
            case 4:
                OrderTask4();
                break;
            case 5:
                TabulationTask5();
                break;
            case 50:
                TabulationTask5Easy();
                break;
            default:
                break;
        }
    }


};



int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Dz2 Program = Dz2();
    Program.ChooseTasks();

    system("pause");
}
