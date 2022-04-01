#include <iostream> // добавляем функции для ввода и вывода на экран
#include <math.h>// добавляем математические функции
#include <windows.h>// русификация
#include <iomanip>
#include <cmath>
using namespace std;

double Integral = 0.0; // значение интеграла 
double a, b; //  отрезок интегрирования
double h;//  шаг интегрирования
double n;// число разбиений 


double f(double x)
{
	return (cos(x) / (x * x + 1));// интеграл
}

void I1()//вычисление по формуле прямоугольников
{
	Integral = 0.0;
	for (int i = 1; i <= n; i++)
		Integral = Integral + h * f(a + h * (i - 0.5));
	cout << "Интеграл по формуле центральных прямоугольников = " << setprecision(5) << Integral  << endl;
	cout << endl;
}

void I2()// вычисление по формуле трапеций
{
	Integral = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++)
		Integral = Integral + h * f(a + h * i);
	cout << "интеграл по формуле трапеций = " << setprecision(5) << Integral  << endl;
	cout << endl;
}


void I3()//вычисление по формуле Симпсона
{
	Integral = h * (f(a) + f(b)) / 6.0;
	for (int i = 1; i <= n; i++)
		Integral = Integral + 4.0 / 6.0 * h * f(a + h * (i - 0.5));
	for (int i = 1; i <= n - 1; i++)
		Integral = Integral + 2.0 / 6.0 * h * f(a + h * i);
	cout << "интеграл по формуле Симпсона = " << setprecision(5) << Integral  << endl;
	cout << endl;

}

enum Menu
{
	charac,
	Intergal_1,
	Intergal_2,
	Intergal_3,
	exit_programm
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::fixed);
	cout << "Введите отрезок интегрирования :" << endl;
	cout << "A:"; cin >> a; 
	cout << "B:"; cin >> b;
	h = pow(0.001,0.25);/// при точности e=0.001
	n = (b - a) / h;
	while (((int)(n) < n) || ((int)(n) % 4 != 0))
	{
		n=(int)n+1;
	}

	h = (b - a) / n;
	cout <<"Число разбиений n: "  << (int) n << endl ;

	int ans;

	do
	{
		cout << "Выберите пункт меню: " << endl;
		cout << charac << " - Изменение характеристик " << endl
			<< Intergal_1 << " - Вычисление интеграла по формуле центральных прямоугольников" << endl
			<< Intergal_2 << " - Вычисление интеграла по формуле трапеций " << endl
			<< Intergal_3 << " - Вычисление интеграла по формуле Симпсона" << endl
			<< exit_programm << " - выход" << endl;
		cin >> ans;

		switch (ans)
		{
		case charac:
		{
			cout << "Введите отрезок интегрирования :" << endl;
			cout << "A:"; cin >> a;
			cout << "B:"; cin >> b;
			cout << "Введите шаг интегрирования :" << endl;
			cin >> h;
			n = (b - a) / h; 
			break;
		}
		case Intergal_1:
		{
			I1();
			break;
		}
		case Intergal_2:
		{
			I2();
			break;
		}
		case Intergal_3:
		{
			I3();
			break;
		}
		case exit_programm:
			break;
		}
	} while (ans != exit_programm);

	return 0;

}