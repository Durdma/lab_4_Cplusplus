#define NOMINMAX

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <climits>
#include <iomanip>

using namespace std;

// �������� �������� �������� �� ������������

void f_input_check(float& a, const char* word)
{

	while (!cin.good() || cin.peek() != '\n')
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "������������ ���� " << word << "!!! ������� " << word << " ������!!!" << endl;
		cout << word << " = ";

		cin >> a;
		cout << endl;

	}

}

void f_input_check(float& a, const char& word)
{

	while (!cin.good() || cin.peek() != '\n')
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "������������ ���� " << word << "!!! ������� " << word << " ������!!!" << endl;
		cout << word << " = ";

		cin >> a;
		cout << endl;

	}

}

// ���� �������

void f_input_k(float& a, float& b, float& c)
{

	char let_A = 'A';
	char let_B = 'B';
	char let_C = 'C';

	cout << "������� ������������: " << endl;
	cout << "A = ";
	cin >> a;
	cout << endl;

	f_input_check(a, let_A);

	cout << "B = ";
	cin >> b;
	cout << endl;

	f_input_check(b, let_B);

	cout << "C = ";
	cin >> c;
	cout << endl;

	f_input_check(c, let_C);

}

// ���� ���� � ������

void f_input_x(float& out_x_min, float& out_dx, float& out_x_max)
{

	char word_min[]{ "xMin" };
	char word_dx[]{ "dx" };
	char word_max[]{ "xMax" };

	cout << "xMin = ";
	cin >> out_x_min;
	cout << endl;

	f_input_check(out_x_min, word_min);

	cout << "������� ��� � ������� ���������: " << endl;
	cout << "dx = ";
	cin >> out_dx;
	cout << endl;

	f_input_check(out_dx, word_dx);

	while (out_dx == 0)
	{

		cerr << "��� �� ����� ���� ����� 0!!!" << endl;
		cout << "������� ��� ������!!!" << endl;
		cout << "dx = ";
		cin >> out_dx;
		cout << endl;

		f_input_check(out_dx, word_dx);

	}

	cout << "Xmax = ";
	cin >> out_x_max;
	cout << endl;

	f_input_check(out_x_max, word_max);

}

// �������� ���� � ������

void f_check_input_x(float& x_min, float& dx, float& x_max)
{

	float buff;
	dx = abs(dx);

	while (true)
	{

		if (x_min > x_max)
		{

			buff = x_min;
			x_min = x_max;
			x_max = buff;


			cerr << "����������� ������ ������� �������: xMin > xMax" << endl;
			cout << "����� � ������ ������� ���� ������������: " << "xMin = "
				<< x_min << " xMax = " << x_max << endl;

		}

		buff = x_max - x_min;

		if (abs(dx) > abs(buff))
		{

			cerr << "��� ������� dx ������ ����� ��������� �������!!! ������ �����������!!! ��������� �� � ������� ������!!!" << endl;

			f_input_x(x_min, dx, x_max);


		}

		else
		{

			break;

		}
	}

}

// �������� ��� � ������ �������

bool f_logic(float in_a, float in_b, float in_c, float& in_res, float in_x)
{

	// �������� ��� 1�� �������

	if ((in_x < 0) && (in_b != 0))
	{

		if (in_c * in_x - in_a == 0)
		{

			return 0;

		}

		else
		{

			in_res = (2 * in_x - in_c) / (in_c * in_x - in_a);
			-in_res;

		}

	}

	// �������� ��� 2�� �������
	else
	{
		if ((in_x > 0) && (in_b == 0))
		{


			if (in_x - in_c == 0)
			{

				return 0;

			}

			else
			{

				in_res = in_x - in_a / (in_x - in_c);

			}

		}

		// �������� ��� 3� �������

		else
		{

			if (in_x == 0 || in_c == 0)
			{

				return 0;

			}

			else 
			{

				in_res = -(in_x / in_c) - (in_c / (2 * in_x));

			}

		}

	}

	return 1;

}

// ���������� �������

void f_out_table(const float* a, const float* b, const float* c, const float* x_min, const float* dx, const float* x_max)
{

	float res = 0;

	cout << "������� �������� ��������� �������: " << endl;

	cout << "F(�)= " << "- ((2*x - " << *c << ") / (" << *c
		<< "*x - " << *a << "))" << " ��� � < 0 � b != 0" << endl;

	cout << "F(x)= " << "(x - " << *a << ") / (x - " << *c << ")"
		<< " ��� � > 0 � b = 0" << endl;

	cout << "F(x)= " << "- (x / " << *c << ") - (" << *c
		<< " / (2*x))" << " �� ���� ��������� �������" << endl;
	cout << endl;

	cout << "������� �������� F(x)" << endl;

	for (int i = 0; i < 66; i++)
	{

		cout << "-";

	}

	cout << endl;

	cout << "| " << setw(30) << "�������� � " << "| " << setw(30) << "�������� F(x)" << " |" << endl;

	for (int i = 0; i < 66; i++)
	{

		cout << "-";

	}

	cout << endl;

	for (float i = *x_min; i <= *x_max; i += *dx)
	{

		cout << "| " << setw(29) << i << " | ";

		// �������� ��� �������

		if (f_logic(*a, *b, *c, res, i) == 0)
		{

			cout << setw(30) << "��� ���" << " |" << endl;

		}

		else
		{

			cout << setw(30) << res << " |" << endl; // ����� ����������� ������� �������

		}

		for (int i = 0; i < 66; i++)
		{

			cout << "-";

		}

		cout << endl;

	}

}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������������� ����������

	float a{}, b{}, c{}, dx{}, x_min{}, x_max{};


	f_input_k(a, b, c);								// ���� �������

	f_input_x(x_min, dx, x_max);					// ���� ������ � ����

	f_check_input_x(x_min, dx, x_max);				// �������� ������ � ����

	f_out_table(&a, &b, &c, &x_min, &dx, &x_max);	// ������ ������� � ���������� �������

	system("pause");

}
