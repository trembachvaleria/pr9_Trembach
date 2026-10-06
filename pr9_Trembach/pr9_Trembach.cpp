// pr9_Trembach.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <exception>

using namespace std;

double orig[10];
double mass[10];

//вывод
void printArray(double* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//уменьшить на 20%
void reduceBy20(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] * 0.8;
    }
}

//увеличить на 20%
void increaseBy20(double* data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] = data[i] * 1.2;
    }
}

//ограничить макс. время
void limitMax(double* data, int size) {
    const double maxTime = 1000.0;
    for (int i = 0; i < size; i++) {
        if (data[i] > maxTime)
            data[i] = maxTime;
    }
}

//долгие на 0
void zeroTooLong(double* data, int size) {
    const double limit = 500.0;
    for (int i = 0; i < size; i++) {
        if (data[i] > limit)
            data[i] = 0;
    }
}

//массив указателей
void (*processors[])(double*, int) = {
    reduceBy20,
    increaseBy20,
    limitMax,
    zeroTooLong
};

//функция которая вызывает нужную функцию
void applyProcessing(double* data, int size, void (*processor)(double*, int)) {
    if (processor != nullptr) {
        processor(data, size);
    }
}

//генерация
void generateData() {
    for (int i = 0; i < 10; i++) {
        orig[i] = (rand() % 1000) + 100;
        mass[i] = orig[i];
    }
    cout << "Данные сгенерированы\n";
}

//востановить
void restoreData() {
    for (int i = 0; i < 10; i++) {
        mass[i] = orig[i];
    }
    cout << "Данные восстановлены\n";
}

int main()
{
    setlocale(NULL, "Russian");
    srand(time(0));

    int otvet = 0;
    while (otvet != 5) {
        cout << "\nМеню:\n";
        cout << "1. Ввести данные (случайно)\n";
        cout << "2. Показать данные\n";
        cout << "3. Выбрать и выполнить обработку\n";
        cout << "4. Восстановить исходные данные\n";
        cout << "5. Выход\n";
        cout << "Выбор: ";
        cin >> otvet;

        if (otvet == 1) {
            generateData();
        }
        else if (otvet == 2) {
            cout << "Массив: ";
            printArray(mass, 10);
        }
        else if (otvet == 3) {
            cout << "\nВыберите операцию:\n";
            cout << "1. Уменьшить время на 20%\n";
            cout << "2. Увеличить время на 20%\n";
            cout << "3. Ограничить максимальное время (1000 мс)\n";
            cout << "4. Заменить задачи > 500 мс на 0\n";
            cout << "Номер: ";

            int otv;
            cin >> otv;

            if (otv < 1 || otv > 4) {
                cout << "Неверный номер\n";
                continue;
            }

            cout << "\nДо обработки: ";
            printArray(mass, 10);

            void (*processor)(double*, int) = processors[otv - 1];
            applyProcessing(mass, 10, processor);

            cout << "После обработки: ";
            printArray(mass, 10);
        }
        else if (otvet == 4) {
            restoreData();
        }
    }

    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
