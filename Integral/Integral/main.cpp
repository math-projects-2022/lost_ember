#include <iostream> // ��������� ������� ��� ����� � ������ �� �����
#include <math.h>// ��������� �������������� �������
#include <windows.h>// �����������
#include <iomanip>
#include <cmath>
using namespace std;

double Integral = 0.0; // �������� ��������� 
double a, b; //  ������� ��������������
double h;//  ��� ��������������
double n;// ����� ��������� 


double f(double x)
{
	return (cos(x) / (x * x + 1));// ��������
}

void I1()//���������� �� ������� ���������������
{
	Integral = 0.0;
	for (int i = 1; i <= n; i++)
		Integral = Integral + h * f(a + h * (i - 0.5));
	cout << "�������� �� ������� ����������� ��������������� = " << setprecision(5) << Integral  << endl;
	cout << endl;
}

void I2()// ���������� �� ������� ��������
{
	Integral = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++)
		Integral = Integral + h * f(a + h * i);
	cout << "�������� �� ������� �������� = " << setprecision(5) << Integral  << endl;
	cout << endl;
}


void I3()//���������� �� ������� ��������
{
	Integral = h * (f(a) + f(b)) / 6.0;
	for (int i = 1; i <= n; i++)
		Integral = Integral + 4.0 / 6.0 * h * f(a + h * (i - 0.5));
	for (int i = 1; i <= n - 1; i++)
		Integral = Integral + 2.0 / 6.0 * h * f(a + h * i);
	cout << "�������� �� ������� �������� = " << setprecision(5) << Integral  << endl;
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
	cout << "������� ������� �������������� :" << endl;
	cout << "A:"; cin >> a; 
	cout << "B:"; cin >> b;
	h = pow(0.001,0.25);/// ��� �������� e=0.001
	n = (b - a) / h;
	while (((int)(n) < n) || ((int)(n) % 4 != 0))
	{
		n=(int)n+1;
	}

	h = (b - a) / n;
	cout <<"����� ��������� n: "  << (int) n << endl ;

	int ans;

	do
	{
		cout << "�������� ����� ����: " << endl;
		cout << charac << " - ��������� ������������� " << endl
			<< Intergal_1 << " - ���������� ��������� �� ������� ����������� ���������������" << endl
			<< Intergal_2 << " - ���������� ��������� �� ������� �������� " << endl
			<< Intergal_3 << " - ���������� ��������� �� ������� ��������" << endl
			<< exit_programm << " - �����" << endl;
		cin >> ans;

		switch (ans)
		{
		case charac:
		{
			cout << "������� ������� �������������� :" << endl;
			cout << "A:"; cin >> a;
			cout << "B:"; cin >> b;
			cout << "������� ��� �������������� :" << endl;
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