#include <iostream>
#include <cmath>
using namespace std;

double F(double x, double y)
{
    return (3*sin(2*y)+x);// Вписать уравнение
}


void Eiler(double a, double b,double h)// Метод Эйлера
{
    size_t n = (b - a) / h;
    double* X = new double[n];
    double* Y = new double[n];
    X[0] = a; Y[0] = 2;
    for (int i = 1; i < n; i++) {
        X[i] = a + i * h;
        Y[i] = Y[i - 1] + h * F(X[i - 1], Y[i - 1]);
    }
    for (int i = 1; i < n; i++) {
        cout << "X[" << i << "]=" << X[i] << " ";
        cout << "Y[" << i << "]=" << Y[i] << " ";
        cout << endl;
    }

    delete[] X;
    delete[] Y;

}

void Runge(double a, double b, double h) //Метод Рунге-Кутта
{
    size_t n = (b - a) / h;
    double*X = new double[n];
    double*Y1 = new double[n];
    double*Y2 = new double[n];
    double*Y3 = new double[n];
    double*Y4 = new double[n];
    double*Y = new double[n];
    X[0] = a; Y[0] = 2;
    for (int i = 1; i < n; i++) {
        X[i] = a + i * h;
        Y1[i] = h * F(X[i - 1], Y[i - 1]);
        Y2[i] = h * F(X[i - 1] + h / 2.0, Y[i - 1] + Y1[i] / 2.0);
        Y3[i] = h * F(X[i - 1] + h / 2, Y[i - 1] + Y2[i] / 2);
        Y4[i] = h * F(X[i - 1] + h, Y[i - 1] + Y3[i]);
        Y[i] = Y[i - 1] + (Y1[i] + 2 * Y2[i] + 2 * Y3[i] + Y4[i]) / 6;
    }

    for (int i = 1; i < n; i++) {
        cout << "X[" << i << "]=" << X[i] << " ";
        cout << "Y[" << i << "]=" << Y[i] << " ";
        cout << endl;
    }

    delete[] X;
    delete[] Y;
    delete[] Y1;
    delete[] Y2;
    delete[] Y3;
    delete[] Y4;

}

int main() 
{
    system("chcp 1251");

    double a, b, h;
    bool m;
    cout << "Введите концы отрезка A и B" << endl;
    cin >> a >> b;
    cout << "Введите шаг" << endl;
    cin >> h;
    cout << "Выберите метод решения задачи" << endl
        << "0-Метод Эйлера, 1-Метод Рунге-Кутта" << endl;
    cin >> m;

    if (m)
        Runge(a, b, h);
    else
        Eiler(a, b, h);
    return 0;
}