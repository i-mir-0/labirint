#include <iostream>
#include <windows.h>
#include "menu.h"
#include <iomanip>
#include <fstream>
#include <thread>
#include <vector>
#include <string>
#include"generate.h"
#include <stack>
#include <cstdlib>
#include <ctime>
#include "wave.h"
#include "check.h"




using namespace std;
int main() 
{
	int size_of_maze=0;
	vector<vector<char>> maze;
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	SetColor(10);
	cout << "Добро пожаловать в меню лабиринта:" << endl << endl;
	ResetColor();
	SetColor(9);
	cout << "------------------------------------------------------------------" << endl;
	ResetColor();
	bool flag = 1;
	bool flag1 = 0;
	while (flag) {
		SetColor(6);
		Menu1();
		ResetColor();
		SetColor(9);
		cout << "------------------------------------------------------------------" << endl;
		ResetColor();
		int number = getNumber() ;
		if (number>=1&&number<=5) {
			switch (number)
			{
			case 1:
				SetColor(10);
				cout << "Введите размер лабиринта(число должно быть нечётным)(5-101) " << endl;
				ResetColor();
				SetColor(9);
				cout << "------------------------------------------------------------------" << endl;
				ResetColor();
				
				size_of_maze = getNumber();
				if (size_of_maze <= 99 && size_of_maze >= 5 && size_of_maze % 2 == 1) {
					maze.resize(size_of_maze, vector<char>(size_of_maze));
					generateMaze(maze, size_of_maze);
					flag1 = 1;
				}
				else {
					SetColor(4);
					cout << "Вы заходите в гущие заросли... 'подумай ещё раз'" << endl;
					ResetColor();
					SetColor(9);
					cout << "------------------------------------------------------------------" << endl;
					ResetColor();
				}
				break;
			case 2:
				if (flag1 == 1) {
					printMaze(maze, size_of_maze);
					SetColor(9);
					cout << "------------------------------------------------------------------" << endl;
					ResetColor();
				}
				else {
					SetColor(4);
					cout << "Для этого понадобиться камень,камень я не ДАМ!" << endl;
					ResetColor();
					SetColor(9);
					cout << "------------------------------------------------------------------" << endl;
					ResetColor();
				}
				break;
			case 3:
				if (flag1 == 1) {
					printFileMaze( maze,size_of_maze);
				}
				else {
					SetColor(4);
					cout <<"Для этого понадобиться камень,камень я не ДАМ!" << endl;
					ResetColor();
					SetColor(9);
					cout << "------------------------------------------------------------------" << endl;
					ResetColor();
				}
				break;
			case 4:
				flag1 = 0;
				InputFileMaze(maze, size_of_maze);
				if (!size_of_maze) {
					SetColor(4);
					cout << "    Данный лабиринт не подходит под описание, возврат к выбору задачи" << endl << endl;;
					ResetColor();
				}
				else {
					flag1 = 1;
				}
				break;
			case 5:
				if (flag1 == 1) {
					flag = 0;
				
					SetColor(9);
					cout << "------------------------------------------------------------------" << endl;
					ResetColor();
				}
				else {
					SetColor(4);
					cout << "Без моста дальше не сдвинуться!!" << endl;
					ResetColor();
					SetColor(9);
					cout << "------------------------------------------------------------------" << endl;
					ResetColor();
				}
				break;
			default:
				SetColor(4);
				cout << "Подумайте ещё раз" << endl;
				ResetColor();
				SetColor(9);
				cout << "------------------------------------------------------------------" << endl;
				ResetColor();
			}
		}
		else
		{
			SetColor(4);
			cout << "Подумайте ещё раз" << endl << endl;
			ResetColor();
			SetColor(9);
			cout << "------------------------------------------------------------------" << endl;
			ResetColor();
		
		}
	}
	flag = 1;
	while (flag)
	{
		SetColor(6);
		Menu2();
		ResetColor();
		SetColor(9);
		cout << "------------------------------------------------------------------" << endl;
		ResetColor();
		int user_number = getNumber();
		switch (user_number)
		{
		case 1:
			waveAlgorithm(maze, size_of_maze,user_number);
			SetColor(9);
			cout << "------------------------------------------------------------------" << endl;
			ResetColor();
			break;
		case 2:
			waveAlgorithm(maze, size_of_maze, user_number);
			SetColor(9);
			cout << "------------------------------------------------------------------" << endl;
			ResetColor();
			break;
		case 3:
			SetColor(10);
			cout << "Спасибо, что выбрали нас!!" << endl;
			ResetColor();
			SetColor(9);
			cout << "------------------------------------------------------------------" << endl;
			ResetColor();
			flag = 0;
			break;
		default:
			SetColor(4);
			cout << "Старательно подумайте ещё разок" << endl;
			ResetColor();
			SetColor(9);
			cout << "------------------------------------------------------------------" << endl;
			ResetColor();
		}
		


	}
}
