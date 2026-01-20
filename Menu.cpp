#include <iostream>
#include "menu.h"
#include <windows.h>

using namespace std;
void Menu1()
{
	cout << "1. Сгенерировать лабиринт" << endl << "2. Вывести лабиринт на экран" << endl << "3. Сохранить лабиринт в файл " << endl << "4. Загрузить свой лабиринт"<<endl << "5. Следущий шаг" << endl;
}
void Menu2()
{
	cout << "1. Вывести кратчайший путь" << endl << "2. Вывести кратчайший путь в файл" << endl << "3. Закончить работу программы" << endl;
}
void SetColor(int colorCode) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, colorCode);
}
void ResetColor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(
		hConsole, 7);  // делает белый цвет по дефолту, что другое не было цветным
}