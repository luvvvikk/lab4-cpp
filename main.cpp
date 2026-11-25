#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

string checkOnlyOneOdd(long long a, long long b) {
    bool isOddA = (a % 2 != 0);
    bool isOddB = (b % 2 != 0);
    bool result = (isOddA != isOddB);
    return result ? "True" : "False";
}

void printSquaresRange(long long a, long long b) {
    cout << "\n--- Завдання 2: Квадрати чисел від " << a << " до " << b << " ---\n";
    cout << left << setw(12) << "Число (x)" << setw(16) << "Квадрат (x^2)" << "\n";
    cout << string(28, '-') << "\n";

    if (a <= b) {
        for (long long x = a; x <= b; ++x) {
            long long sq = x * x;
            cout << left << setw(12) << x << setw(16) << sq << "\n";
        }
    } else {
        for (long long x = a; x >= b; --x) {
            long long sq = x * x;
            cout << left << setw(12) << x << setw(16) << sq << "\n";
        }
    }
}

void printFunctionTable(double a, double b, double h) {
    cout << "\n--- Завдання 3: Таблиця значень Y = ln(x^2) + x^2 + 2 ---\n";
    if (h <= 0.0) {
        cout << "Помилка: крок h повинен бути додатним (h > 0).\n";
        return;
    }
    if (a > b) {
        cout << "Помилка: нижня межа a не повинна перевищувати верхню межу b.\n";
        return;
    }

    cout << left << setw(14) << "x" << setw(18) << "Y(x)" << "\n";
    cout << string(32, '-') << "\n";

    const double eps = 1e-9;
    int steps = static_cast<int>(floor((b - a) / h + eps));

    for (int i = 0; i <= steps; ++i) {
        double x = a + i * h;
        if (fabs(x - b) <= eps && x > b) {
            x = b;
        }
        if (x > b + eps) {
            break;
        }

        cout << left << setw(14) << fixed << setprecision(4) << x;
        if (fabs(x) <= eps) {
            cout << left << setw(18) << "не визначено (x=0)" << "\n";
        } else {
            double y = log(x * x) + (x * x) + 2.0;
            cout << left << setw(18) << fixed << setprecision(6) << y << "\n";
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "============================================================\n";
    cout << "        ЛАБОРАТОРНА РОБОТА №4: УМОВИ ТА ЦИКЛИ В C++\n";
    cout << "============================================================\n\n";

    long long a1, b1;
    cout << "[Завдання 1] Введіть два цілих числа A та B: ";
    cin >> a1 >> b1;
    cout << "Результат перевірки (\"Тільки одне з чисел A і B непарне\"): "
         << checkOnlyOneOdd(a1, b1) << "\n\n";

    long long a2, b2;
    cout << "[Завдання 2] Введіть межі діапазону A та B: ";
    cin >> a2 >> b2;
    printSquaresRange(a2, b2);
    cout << "\n";

    double a3, b3, h3;
    cout << "[Завдання 3] Введіть початок проміжку a, кінець b та крок h: ";
    cin >> a3 >> b3 >> h3;
    printFunctionTable(a3, b3, h3);

    return 0;
}
