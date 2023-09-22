#include <iostream>
#include <Windows.h>
#include <cmath>
#include <fstream>

using namespace std;

class Console{

public:
    bool isCorrectInput;

    template <typename T>
    T whileInput(){
        T input;

        do{
            input = Input<T>();
            if (!isCorrectInput)
                cout << "Некорректный ввод, повторите еще раз: " << endl;
        } while (!isCorrectInput);
        return input;
    }

public:
    template <typename T>
    T Input(){
        string stringInput;
        cin >> stringInput;

        T input;

        if (stringInput.empty()){
            isCorrectInput = false;
            return input;
        }

        try{
            if (typeid(T).operator==(typeid(int))){

                for(char c : stringInput){
                    if (isdigit(c) == 0){
                        isCorrectInput = false;
                        return input;
                    }
                }

                input = stoi(stringInput);
            } else if (typeid(T).operator==(typeid(float))){

                bool hasOnePoint = false;
                for(char c : stringInput){
                    if (c == '.'){
                        if (hasOnePoint){
                            isCorrectInput = false;
                            return input;
                        } else {
                            hasOnePoint = true;
                            continue;
                        }
                    }
                    if (isdigit(c) == 0){
                        isCorrectInput = false;
                        return input;
                    }
                }

                input = stof(stringInput);
            }
        } catch(...) {
            isCorrectInput = false;
            return input;
        }

        isCorrectInput = true;
        return input;
    }
};

class Dz3{

public:
    Dz3(){
        console = Console();
    }

    Console console;

public:
    void ChooseTasks(){
        int taskNumber = TakeTaskNumber();

        while (taskNumber != 0){
            StartChosenTask(taskNumber);
            taskNumber = TakeTaskNumber();
        }
    }

private:
    void LoanTask1(){
        int n;
        float m, S, p;

        cout << "Введите S" << endl;
        S = console.whileInput<float>();
        cout << "Введите p" << endl;
        p = console.whileInput<float>();
        cout << "Введите n" << endl;
        n = console.whileInput<int>();

        float r = p / 100;
        float numerator = S * r * pow((1 + r), n);
        float denominator = 12 * (pow((1+r), n) - 1);

        m = numerator / denominator;

        cout << "Месячная выплата m = " << m << endl;
    }

private:
    void LoanTask2(){
        int n;
        float m, iterableM, S, r, eps, numerator, denominator;

        cout << "Введите S" << endl;
        cin >> S;
        cout << "Введите m" << endl;
        cin >> m;
        cout << "Введите n" << endl;
        cin >> n;

        eps = 0.01;

        for (int p = 0; p < 100; ++p) {
            r = (float)p / 100;
            numerator = S * r * pow((1 + r), n);
            denominator = 12 * (pow((1+r), n) - 1);

            iterableM = numerator / denominator;
            if (abs(iterableM-m) < eps){
                cout << "Процент p = " << p << endl;
                break;
            }
        }
    }


private:
    void CopyingFilesTask3(){
        ofstream fout("cppstudio.txt");
        fout << "Работа с файлами в с++";
        fout.close();

        char buff[40];
        ifstream fin("cppstudio.txt");
        fin.getline(buff, 40);
        fin.close();
        cout << buff << endl;
    }

private:
    void FilterTask4(){
        string path;
        int buffSize = 50;
        char buff[buffSize];

        cout << "Введите путь до файла: " << endl;
        cin >> path;

        ifstream fin(path);
        if (!fin.is_open()){
            cout << "Некорректный файл" << endl;
        } else {
            fin.read(buff, buffSize);
            for(char c : buff){
                if (isdigit(c) != 0){
                    cout << c << " ";
                }
            }
        }
        cout << endl;
        fin.close();
    }

private:
    void LetterSortingTask5(){

        char line[30];

        cout << "Введите строку(лишние символы обрежутся): " << endl;
        cin.read(line, 30);

        for(int i=1; i<sizeof(line); i++)
            for(int j=i; j>0 && line[j-1]>line[j]; j--)
                swap(line[j-1],line[j]);

        cout << "Отсортированная строка: " << line << endl;
    }

private:
    int TakeTaskNumber(){
        cout << "Введите номер задания. Для завершения программы введите \"0\"." << endl;

        int taskNumber = console.whileInput<int>();

        return taskNumber;
    }

private:
    void StartChosenTask(int taskNumber){

        switch (taskNumber)
        {
            case 1:
                LoanTask1();
                break;
            case 2:
                LoanTask2();
                break;
            case 3:
                CopyingFilesTask3();
                break;
            case 4:
                FilterTask4();
                break;
            case 5:
                LetterSortingTask5();
                break;
            default:
                break;
        }
    }


};



int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    Dz3 Program = Dz3();
    Program.ChooseTasks();


    system("pause");
}

