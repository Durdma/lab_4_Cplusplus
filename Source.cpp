#define NOMINMAX

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <climits>
#include <iomanip>

using namespace std;

// Проверка введнных значений на корректность
void f_input_check(float& a, const char* word)
{

	while (!cin.good() || cin.peek() != '\n')
	{

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cerr << "Неккоректный ввод " << word << "!!! Введите " << word << " заново!!!" << endl;
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

		cerr << ""Неккоректный ввод " << word << "!!!Введите " << word << " заново!!!" << endl;
		cout << word << " = ";

		cin >> a;
		cout << endl;

	}

}

// Ввод коэффициентов

void f_input_k(float& a, float& b, float& c)
{

	char let_A = 'A';
	char let_B = 'B';
	char let_C = 'C';

	cout << "Введите коэффициенты: " << endl;
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

// Ввод шага и границ

void f_input_x(float& out_x_min, float& out_dx, float& out_x_max)
{

	char word_min[]{ "xMin" };
	char word_dx[]{ "dx" };
	char word_max[]{ "xMax" };

	cout << "xMin = ";
	cin >> out_x_min;
	cout << endl;

	f_input_check(out_x_min, word_min);

	cout << "Введите шаг и границы интервала: " << endl;
	cout << "dx = ";
	cin >> out_dx;
	cout << endl;

	f_input_check(out_dx, word_dx);

	while (out_dx == 0)
	{

		cerr << "Шаг не может быть равен 0!!!" << endl;
		cout << "Введите шаг заново!!!" << endl;
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

// Проверка шага и границ

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


			cerr << "Некорректно заданы границы функции: xMin > xMax" << endl;
			cout << "Левая и правая граница были переставлены: " << "xMin = "
				<< x_min << " xMax = " << x_max << endl;

		}

		buff = x_max - x_min;

		if (abs(dx) > abs(buff))
		{

			cerr << "Шаг функции dx больше длины интервала функции!!! Данные некорректны!!! Проверьте их и введите заново!!!" << endl;

			f_input_x(x_min, dx, x_max);


		}

		else
		{

			break;

		}
	}

}

// Ïðîâåðêà ÎÄÇ è ðàñ÷åò ôóíêöèé

bool f_logic(float in_a, float in_b, float in_c, float& in_res, float in_x)
{

	// Ïðîâåðêà ÎÄÇ 1îé ôóíêöèè

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

	// Ïðîâåðêà ÎÄÇ 2îé ôóíêöèè
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

		// Ïðîâåðêà ÎÄÇ 3é ôóíêöèè

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

// Ïîñòðîåíèå òàáëèöû

void f_out_table(const float* a, const float* b, const float* c, const float* x_min, const float* dx, const float* x_max)
{

	float res = 0;

	cout << "Ôóíêöèÿ âûãëÿäèò ñëåäóþùèì îáðàçîì: " << endl;

	cout << "F(õ)= " << "- ((2*x - " << *c << ") / (" << *c
		<< "*x - " << *a << "))" << " ïðè õ < 0 è b != 0" << endl;

	cout << "F(x)= " << "(x - " << *a << ") / (x - " << *c << ")"
		<< " ïðè õ > 0 è b = 0" << endl;

	cout << "F(x)= " << "- (x / " << *c << ") - (" << *c
		<< " / (2*x))" << " âî âñåõ îñòàëüíûõ ñëó÷àÿõ" << endl;
	cout << endl;

	cout << "Òàáëèöà çíà÷åíèé F(x)" << endl;

	for (int i = 0; i < 66; i++)
	{

		cout << "-";

	}

	cout << endl;

	cout << "| " << setw(30) << "Çíà÷åíèå Õ " << "| " << setw(30) << "Çíà÷åíèå F(x)" << " |" << endl;

	for (int i = 0; i < 66; i++)
	{

		cout << "-";

	}

	cout << endl;

	for (float i = *x_min; i <= *x_max; i += *dx)
	{

		cout << "| " << setw(29) << i << " | ";

		// Ïðîâåðêà ÎÄÇ ôóíêöèè

		if (f_logic(*a, *b, *c, res, i) == 0)
		{

			cout << setw(30) << "Âíå ÎÄÇ" << " |" << endl;

		}

		else
		{

			cout << setw(30) << res << " |" << endl; // Âûâîä ðåçóëüòàòîâ ðàñ÷åòà ôóíêöèè

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

	// Èíèöèàëèçàöèÿ ïåðåìåííûõ

	float a{}, b{}, c{}, dx{}, x_min{}, x_max{};


	f_input_k(a, b, c);								// Ââîä êîýôôîâ

	f_input_x(x_min, dx, x_max);					// ÂÂîä ãðàíèö è øàãà

	f_check_input_x(x_min, dx, x_max);				// Ïðîâåðêà ãðàíèö è øàãà

	f_out_table(&a, &b, &c, &x_min, &dx, &x_max);	// Ðàñ÷åò ôóíêöèé è ïîñòðîåíèå òàáëèöû

	system("pause");

}
