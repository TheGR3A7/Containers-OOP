#define _CRT_SECURE_NO_WARNINGS
#define MAX_MASS 100
#include <iostream>
#include <string.h>
#include "I_Printable.h"
#include "I_Copyable.h"
#include "I_Value.h"
#include "I_Manageable.h"
#include "Text.h"
#include "Vector_2_d.h"
#include "Vector_3_d.h"
#include "Complex.h"


using namespace std;

void Sort(IManageable* mass[], int size) 
{
	if (size <= 0)
		return;

	for (int i = 0; i < size - 1; i++) 
	{
		for (int j = 0; j < size - i - 1; j++) 
		{
			if (mass[j]->GetValue() > mass[j + 1]->GetValue()) 
			{
				IManageable* temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}
	}
}

IManageable* Min(IManageable* mass[], int size) 
{
	if (size <= 0) 
		return nullptr; 

	IManageable* min = mass[0];

	for (int i = 1; i < size; i++) 
	{
		if (mass[i]->GetValue() < min->GetValue()) 
			min = mass[i];
	}
	return min;
}

IManageable* Max(IManageable* mass[], int size)
{
	if (size <= 0)
		return nullptr; 

	IManageable* max = mass[0];

	for (int i = 1; i < size; i++) 
	{
		if (mass[i]->GetValue() > max->GetValue()) 
			max = mass[i];
	}
	return max;
}

int Find(IManageable** mass, int size) 
{
	if (size <= 0)
		return -1;

	float value;

	cout << "Введите значение элемента: ";
	cin >> value;

	for (int i = 0; i < size; i++)
		if (mass[i]->GetValue() == value)
			return i;

	return INT_MIN;
}


void Print_Line(IManageable** mass, int size) 
{
	if (size <= 0)
		return;

	for (int i = 0; i < size; i++) 
		mass[i]->Print_Short();
	cout << endl;
}

void Print_Column(IManageable** mass, int size) 
{
	if (size <= 0) 
		return;

	for (int i = 0; i < size; i++) 
	{
		mass[i]->Print_Full();
		cout << endl;
	}
}

float Sum(IManageable** mass, int size) 
{
	if (size <= 0)
		return 0;

	float sum = 0;
	for (int i = 0; i < size; i++) 
		sum += mass[i]->GetValue();
	return sum;
}


int Count_In_Range(IManageable** mass, int size)
{
	if (size <= 0) 
		return 0;

	int minRange, maxRange;
	cout << "Введите начальное значение: ";
	cin >> minRange;
	cout << "Введите конечное значение: ";
	cin >> maxRange;
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (mass[i]->GetValue() >= minRange && mass[i]->GetValue() <= maxRange)
		{
			mass[i]->Print_Short();
			cout << endl;
			count++;
		}
	}

	return count;
}

void Print_Pikes(IManageable** mass, int size) 
{
	if (size <= 0 || mass == nullptr) 
		return;

	for (int i = 0; i < size; i++) 
	{
		if (i == 0) 
		{
			if (mass[i]->GetValue() > mass[i + 1]->GetValue() || mass[i]->GetValue() < mass[i + 1]->GetValue()) 
			{
				mass[i]->Print_Full();
				cout << endl;
			}
		}

		else if (i == size - 1) 
		{
			if (mass[i]->GetValue() > mass[i - 1]->GetValue() || mass[i]->GetValue() < mass[i - 1]->GetValue()) 
			{
				mass[i]->Print_Full();
				cout << endl;
			}
		}

		else 
		{
			if ((mass[i]->GetValue() > mass[i - 1]->GetValue() && mass[i]->GetValue() > mass[i + 1]->GetValue()) ||
				(mass[i]->GetValue() < mass[i - 1]->GetValue() && mass[i]->GetValue() < mass[i + 1]->GetValue())) 
			{
				mass[i]->Print_Full();
				cout << endl;
			}
		}
	}
}

IManageable** Make_Copy(IManageable** mass, int size, int& new_size)
{
	IManageable** new_mass = new IManageable * [size];
	new_size = 0;
	for (int i = 0; i < size; i++)
		new_mass[new_size++] = mass[i]->Copy();
	return new_mass;
}

void Join(IManageable**& mass, int& size, IManageable** second_mass, int second_size)
{
	IManageable** new_mass = new IManageable * [size + second_size];
	if (mass != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			new_mass[i] = mass[i];
		}
		delete[] mass;
	}
	if (second_mass != nullptr)
	{
		for (int i = 0; i < second_size; i++)
			new_mass[i+size] = second_mass[i]->Copy();
	}
	size += second_size;
	mass = new_mass;		
}

void Append(IManageable**& mass, int& size, IManageable*element)
{
	IManageable** new_mass = new IManageable * [size + 1];
	if (mass != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			new_mass[i] = mass[i];
		}
		delete[]  mass;
	}
	new_mass[size] = element;
	size++;
	mass = new_mass;
}

void Print_Unique(IManageable** mass, int size)
{
	if (size <= 0 || !mass)
	{
		cout << "Массив пуст или некорректен." << endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		bool isUnique = true;
		for (int j = 0; j < size; j++)
		{
			if (i != j && mass[i]->Is_Equal(mass[j]))
			{
				isUnique = false;
				break;
			}
		}

		if (isUnique)
		{
			mass[i]->Print_Full();
			cout << endl;
		}
	}
}


int main()
{
	system("chcp 1251");
	IManageable** mass = { nullptr };
	int count = 0, key;
	bool flag = true;

	while (flag)
	{
		do
		{
			cout << "1 - Отсортировать массив (Sort)\n"
				<< "2 - Вывести минимальный элемент (Min)\n"
				<< "3 - Вывести максимальный элемент (Max)\n"
				<< "4 - Найти элемент в списке (Find)\n"
				<< "5 - Вывести массив в короткой форме в строчку (Print_Line)\n"
				<< "6 - Вывести массив в полной форме в столбик (Print_Column)\n"
				<< "7 - Вывести сумму всех элементов (Sum)\n"
				<< "8 - Вывести количество элементов в диапазоне от а до б (Count_In_Range)\n"
				<< "9 - Вывести в полной форме только те элементы, которые либо больше, либо меньше левого и правого (Print_Pikes)\n"
				<< "10 - Сделать копию массива (Make_Copy)\n"
				<< "11 - Соединить 2 массива (Join)\n"
				<< "12 - Добавить элемент (Append)\n"
				<< "13 - Вывести уникальные элементы (Print_Unique)\n"
				<< "14 - Закончить работу\n";
			cin >> key;
		} while (key < 1 or key > 14);

		switch (key)
		{
		case 1:
			Sort(mass, count);
			break;
		case 2:
		{
			IManageable* minElement = Min(mass, count);
			if (minElement)
			{
				cout << "Минимальный элемент: ";
				minElement->Print_Full();
				cout << endl;
			}
			else
			{
				cout << "Массив пуст." << endl;
			}
		}
		break;
		case 3:
		{
			IManageable* maxElement = Max(mass, count);
			if (maxElement)
			{
				cout << "Максимальный элемент: ";
				maxElement->Print_Full();
				cout << endl;
			}
			else
			{
				cout << "Массив пуст." << endl;
			}
		}
		break;
		case 4:
		{
			int index = Find(mass, count);
			if (index != INT_MIN)
			{
				cout << "Элемент найден на позиции " << index << endl;
			}
			else
			{
				cout << "Элемент не найден." << endl;
			}
		}
		break;
		case 5:
			Print_Line(mass, count);
			break;
		case 6:
			Print_Column(mass, count);
			break;
		case 7:
			cout << "Сумма элементов: " << Sum(mass, count) << endl;
			break;
		case 8:
			cout << "Количество элементов в диапазоне: " << Count_In_Range(mass, count) << endl;
			break;
		case 9:
			Print_Pikes(mass, count);
			break;
		case 10:
		{
			int new_size = 0;
			IManageable** new_mass = Make_Copy(mass, count, new_size);
			cout << "Копия массива:" << endl;
			Print_Column(new_mass, new_size);
			delete[] new_mass; 
		}
		break;
		case 11:
		{
			int second_size = 0;
			IManageable* second_mass[MAX_MASS];

			Join(mass, count, second_mass, second_size);

			cout << "Объединенный массив:" << endl;
			Print_Column(mass, count);

			delete[] second_mass;
		}
		break;
		case 12:
		{
			IManageable* element = new Complex(10, 9);
			Append(mass, count, element);
		}
		break;
		case 13:
			Print_Unique(mass, count);
			break;
		case 14:
			flag = false;
			break;
		}
	}

	for (int i = 0; i < count; ++i)
	{
		delete mass[i];
	}

	return 0;
}
