#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>
#include <string>


using namespace std;

class Console {

public:
    bool isCorrectInput;

    template <typename T>
    T whileInput() {
        T input;

        do {
            input = Input<T>();
            if (!isCorrectInput)
                cout << "Некорректный ввод, повторите еще раз: " << endl;
        } while (!isCorrectInput);
        return input;
    }

public:
    template <typename T>
    T Input() {
        string stringInput;
        cin >> stringInput;

        T input{};

        if (stringInput.empty()) {
            isCorrectInput = false;
            return input;
        }

        try {
            bool firstMinus = false;

            if (stringInput[0] == '-')
                firstMinus = true;
            if (typeid(T).operator==(typeid(int)) || typeid(T).operator==(typeid(long))) {
                for (char c : stringInput) {
                    if (c == '-' && firstMinus) {
                        firstMinus = false;
                        continue;
                    }
                    if (isdigit(c) == 0) {
                        isCorrectInput = false;
                        return input;
                    }
                }
                if (typeid(T).operator==(typeid(int))) {
                    input = stoi(stringInput);
                }
                else {
                    input = stol(stringInput);
                }
            }
            else if (typeid(T).operator==(typeid(float)) || typeid(T).operator==(typeid(double))) {

                bool hasOnePoint = false;
                for (char c : stringInput) {
                    if (c == '-' && firstMinus) {
                        firstMinus = false;
                        continue;
                    }
                    if (c == '.') {
                        if (hasOnePoint) {
                            isCorrectInput = false;
                            return input;
                        }
                        else {
                            hasOnePoint = true;
                            continue;
                        }
                    }
                    if (isdigit(c) == 0) {
                        isCorrectInput = false;
                        return input;
                    }
                }
                if (typeid(T).operator==(typeid(float))) {
                    input = stof(stringInput);
                }
                else {
                    input = stod(stringInput);
                }
            }
        }
        catch (...) {
            isCorrectInput = false;
            return input;
        }

        isCorrectInput = true;
        return input;
    }
};

class Dz3 {

private:
    Console console = Console();

public:
    void ChooseTasks() {
        int taskNumber = TakeTaskNumber();

        while (taskNumber != 0) {
            StartChosenTask(taskNumber);
            taskNumber = TakeTaskNumber();
        }
    }

private:
    void LoanTask1() {
        long n;
        double m, S, p;

        cout << "Введите S" << endl;
        S = console.whileInput<double>();
        cout << "Введите p" << endl;
        p = console.whileInput<double>();
        cout << "Введите n" << endl;
        n = console.whileInput<long>();

        double r = p / 100;
        double numerator = S * r * pow((1 + r), n);
        double denominator = 12 * (pow((1 + r), n) - 1);

        if (p == 0) {
            m = S / 12 / n;
        }
        else {
            m = numerator / denominator;
        }

        if (m <= 0 || isnan(m) || isinf(m)) {
            cout << "Некорректные данные" << endl;
            LoanTask1();
            return;
        }

        cout << "Месячная выплата m = " << m << endl;
    }

private:
    void LoanTask2() {
        long n;
        double m, iterableM, S, r, eps, numerator, denominator;

        cout << "Введите S" << endl;
        S = console.whileInput<double>();
        cout << "Введите m" << endl;
        m = console.whileInput<double>();
        cout << "Введите n" << endl;
        n = console.whileInput<long>();

        eps = 0.0001;
        double step = 10;
        double p = 1.0;
        while (p < 100) {
            r = (double)p / 100;
            numerator = S * r * pow((1 + r), n);
            denominator = 12 * (pow((1 + r), n) - 1);

            iterableM = numerator / denominator;
            if (abs(iterableM - m) < eps) {
                cout << "Процент p = " << p << endl;
                return;
            }
            if (iterableM > m) {
                p -= step;
                step = step / 10;
            }
            p += step;

        }

        cout << "Некорректные данные" << endl;
        LoanTask2();
    }


private:
    void CopyingFilesTask3() {
        char choice;
        cout << "Записать дефолтный текст (d) или записать из консоли(w)?" << endl;
        cin >> choice;

        string res;
        string input;

        if (choice == 'd') {
            res = "Работа с файлами \nв с++";
        }
        else if (choice == 'w') {
            cout << "Чтобы завершить ввод в отдельной строке напишите \"AIWPRTON\"" << endl;
            getline(cin, input);
            while (input != "AIWPRTON") {
                res += input + "\n";
                getline(cin, input);
            }
        }
        else {
            cout << "Некорректная команда" << endl;
            CopyingFilesTask3();
            return;
        }

        ofstream fout("cppstudio.txt");
        if (fout.is_open()) {
            fout << res;
        }
        else {
            cout << "Ошибка создания файла";
            CopyingFilesTask3();
            return;
        }
        fout.close();

        cout << "Прочитать фиксированный объем (40 символов в первой строке) (F) или весь текст (A)?" << endl;
        cin >> choice;

        ifstream fin("cppstudio.txt");
        if (!fin.is_open()) {
            cout << "Ошибка чтения файла" << endl;
            CopyingFilesTask3();
            return;
        }
        if (choice == 'A') {
            string result;
            string buff;
            while (getline(fin, buff)) {
                result += buff + "\n";
            }
            cout << result;
        }
        else if (choice == 'F') {
            char buff[40];
            fin.getline(buff, 40);
            cout << buff << endl;
        }
        else {
            cout << "Некорректная команда" << endl;
            fin.close();
            CopyingFilesTask3();
            return;
        }

        fin.close();
    }

private:
    void FilterTask4() {
        string path;
        const int buffSize = 50;
        char buff[buffSize];
        bool lastCharIsDigit{};

        cout << "Введите путь до файла: " << endl;
        cin >> path;

        ifstream fin(path);
        if (!fin.is_open()) {
            cout << "Некорректный файл";
        }
        else {
            fin.read(buff, buffSize);
            int intChar;
            for (char c : buff) {
                intChar = static_cast<int>(c);
                if (48 <= intChar && intChar <= 57) {
                    cout << c;
                    lastCharIsDigit = true;
                }
                else {
                    if (lastCharIsDigit) {
                        cout << " ";
                        lastCharIsDigit = false;
                    }
                    else {
                        continue;
                    }
                }
            }
        }
        cout << endl;
        fin.close();
    }

private:
    void LetterSortingTask5() {
        string choose, path;
        const int buffsize = 30;
        char buff[buffsize];

        cout << "Считать значения из консоли(c) или файла(f)?" << endl;
        cin >> choose;

        if (choose == "f") {
            cout << "Введите путь до файла:" << endl;
            cin >> path;

            ifstream fin(path);
            if (!fin.is_open()) {
                cout << "Некорректный файл" << endl;
                fin.close();
                LetterSortingTask5();
                return;
            }
            else {
                fin.read(buff, buffsize);
                fin.close();
            }
        }
        else if (choose == "c") {
            cout << "Введите строку(лишние символы обрежутся): " << endl;
            string input;
            cin >> input;
            if (input.length() < buffsize) {
                cout << "Должно быть не менее " << buffsize << " символов" << endl;
                LetterSortingTask5();
                return;
            }
            int i = 0;
            for (char c : input) {
                buff[i] = c;
                i++;
                if (i == buffsize)
                    break;
            }
        }
        else {
            LetterSortingTask5();
            return;
        }

        for (int i = 1; i < buffsize; i++)
            for (int j = i; j > 0; j--) {
                if (65 <= buff[j - 1] && buff[j - 1] <= 90) {
                    if (65 <= buff[j] && buff[j] <= 90) {
                        if (buff[j-1] > buff[j])
                            swap(buff[j - 1], buff[j]);
                    }
                    else {
                        if (buff[j-1] > buff[j]-32)
                            swap(buff[j - 1], buff[j]);
                    }
                }
                else {
                    if (65 <= buff[j] && buff[j] <= 90) {
                        if (buff[j - 1]-32 >= buff[j])
                            swap(buff[j - 1], buff[j]);
                    }
                    else {
                        if (buff[j - 1] > buff[j])
                            swap(buff[j - 1], buff[j]);
                    }
                }
            }
        for (char c : buff)
            cout << c;
        cout << endl;
    }

private:
    int TakeTaskNumber() {
        cout << "Введите номер задания. Для завершения программы введите \"0\"." << endl;

        int taskNumber = console.whileInput<int>();

        return taskNumber;
    }

private:
    void StartChosenTask(int taskNumber) {

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
            cout << "Задание под номером " << taskNumber << " не найдено" << endl;
            break;
        }
    }


};



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Dz3 Program = Dz3();
    Program.ChooseTasks();


    system("pause");
}

