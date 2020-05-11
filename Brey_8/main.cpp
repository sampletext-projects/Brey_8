#include <ctime>
#include <iostream>

using namespace std;

void read_mas(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "[" << i + 1 << "] = ";
		cin >> mas[i];
	}
}

void randomize(double* mas, int size)
{
	for (int i = 0; i < size; i++)
	{
		//1000 / 20. даст рандомные градусы с точностью 0.02
		mas[i] = rand() % 1000 / 20. - 25;
	}
}

int find_day_index(double* d_temps, double* n_temps, int days)
{
	for (int i = 2; i < days; i++)
	{
		double d1sum = (d_temps[i - 2] + n_temps[i - 2]) / 2;
		double d2sum = (d_temps[i - 1] + n_temps[i - 1]) / 2;
		double d3sum = (d_temps[i - 0] + n_temps[i - 0]) / 2;
		if (d1sum < 8 && d2sum < 8 && d3sum < 8)
		{
			return i - 2;
		}
	}
	return -1;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "russian");

	cout << "Программу сделала Белевцева Дарья Юрьевна студент группы УМЛ-112\n";
	cout << "Программа для расчёта ряда чисел\n";

	int days = 30;
	double* d_temps = new double[days];
	double* n_temps = new double[days];

	int k;
	cout << "Использовать случайные значения(0) или ввести с клавиатуры(1)? ";
	cin >> k;
	if (k == 0)
	{
		randomize(d_temps, days);
		randomize(n_temps, days);
	}
	else
	{
		cout << "Введите дневные температуры: \n";
		read_mas(d_temps, days);
		cout << "Введите ночные температуры: \n";
		read_mas(n_temps, days);
	}

	int day_index = find_day_index(d_temps, n_temps, days);
	if (day_index == -1)
	{
		cout << "Отопительный сезон не начнётся\n";
	}
	else
	{
		cout << "Отопительный сезон начнётся на " << day_index + 1 << " день\n";
	}

	system("pause");

	return 0;
}
