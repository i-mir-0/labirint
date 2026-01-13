#include <iostream>
#include <vector>
#include <stack>
#include <cstdlib>
#include <ctime>
#include"generate.h"
#include <fstream>
#include "menu.h"
using namespace std;

void generateMaze(vector<vector<char>>& maze, int size_of_maze) 
{
	srand(time(0));
    for (int i = 0; i < size_of_maze; i++) {
        for (int j = 0; j < size_of_maze; j++) {
            if (i == 0 || j == 0 || j == size_of_maze - 1 || i == size_of_maze - 1) {
                maze[i][j] = '#';
            }
            else {
                maze[i][j] = '.';
            }

        }
    }
    for (int i = 1; i < size_of_maze - 1; i++) {
        for (int j = 1; j < size_of_maze - 1; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                int random_direction = rand() % 4 + 1;
                int shall_we_stop = 1;
                if (random_direction == 1) { //вверх
                    for (int up = i; up > 0 && maze[up][j] != '#'; up--) {
                        if (up % 2 == 0 && up != i) {
                            shall_we_stop = rand() % 4;

                        }
                        if (shall_we_stop)
                            maze[up][j] = '#';
                        else
                            break;

                    }
                }
                if (random_direction == 2) {  // вправо
                    for (int right = j; right < size_of_maze - 1 && maze[i][right] != '#'; right++) {
                        if (right % 2 == 0 && right != j) {
                            shall_we_stop = rand() % 4;

                        }
                        if (shall_we_stop)
                            maze[i][right] = '#';
                        else
                            break;
                    }
                }
                if (random_direction == 3) {  // вниз
                    for (int down = i; down < size_of_maze - 1 && maze[down][j] != '#'; down++) {
                        if (down % 2 == 0 && down != i) {
                            shall_we_stop = rand() % 4;

                        }
                        if (shall_we_stop)
                            maze[down][j] = '#';
                        else
                            break;
                    }
                }
                if (random_direction == 4) {  // влево
                    for (int left = j; left != 0 && maze[i][left] != '#'; left--) {
                        if (left % 2 == 0 && left != j) {
                            shall_we_stop = rand() % 4;

                        }
                        if (shall_we_stop)
                            maze[i][left] = '#';
                        else
                            break;
                    }
                }
            }
        }
    }
    int enter = 0;
    while (enter % 2 == 0 || enter == size_of_maze - 1) {
        enter = rand() % (size_of_maze - 1);

    }

    int which_side_enter = (rand() % 2); //0 слева, 1 снизу
    if (!which_side_enter) {
        maze[size_of_maze - 2][enter] = '/';
    }
    else {
        maze[enter][1] = '/';

    }
    int exit = 0;
    int which_size_exit;
    while (exit % 2 == 0 || exit == size_of_maze - 1) {
        exit = rand() % (size_of_maze);
    }
    if (which_side_enter) {
        which_size_exit = 2; // 2 справа
    }
    else
        which_size_exit = 3;
    if (which_size_exit == 2) {
        maze[exit][size_of_maze - 2] = '/';
    }
    else {
        maze[1][exit] = '/'; //  слева
    }
}
void printMaze(vector<vector<char>> maze,int size_of_maze)
{
    for (int i = 0; i < size_of_maze; i++) {
        cout << "   ";
        for (int j = 0; j < size_of_maze; j++) {
            cout<<maze[i][j];
            cout << " ";
        }
        cout << endl;
    }
}
void printFileMaze(vector<vector<char>> maze, int size_of_maze)
{
    ofstream f1("maze.txt");
    if (!f1.is_open()) {
        cout << "Файл не открылся!!!" << endl;
    }
    for (int i = 0; i < size_of_maze; i++) {
        f1 << "   ";
        for (int j = 0; j < size_of_maze; j++) {
            f1 << maze[i][j];
            f1 << " ";
        }
        f1 << endl;
    }
    cout << endl << endl;
}
void printFileShortMaze(vector<vector<char>> maze, int size_of_maze)
{
    ofstream f2("shortWay.txt");
    if (!f2.is_open()) {
        cout << "Файл не открылся!!!" << endl;
    }
    for (int i = 0; i < size_of_maze; i++) {
        f2 << "   ";
        for (int j = 0; j < size_of_maze; j++) {
            f2 << maze[i][j];
            f2 << " ";
        }
        f2 << endl;
    }
    cout << endl << endl;
}
void InputFileMaze(vector<vector<char>>& maze, int& size_of_maze) {
    ifstream inputMaze("inputMaze.txt");
    if (!inputMaze.is_open()) {
        SetColor(4);
        cout << "Ошибка открытия файла для записи////" << endl << endl;
        ResetColor();
        return;
    }
    size_of_maze = 0;
    char part_of_maze;
    float copy_size;
    while (inputMaze >> part_of_maze) {
        size_of_maze++;
    }
    int count_doors = 0;
    inputMaze.clear();
    inputMaze.seekg(0, inputMaze.beg);
    copy_size = size_of_maze;
    if (sqrt(size_of_maze) == sqrt(copy_size)) {

        int size = sqrt(size_of_maze);
        size_of_maze = size;
        maze.resize(size, vector<char>(size));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                inputMaze >> part_of_maze;
                maze[i][j] = part_of_maze;
                if (maze[i][j] == '/') {
                    count_doors++;
                }
                if (count_doors > 2 || count_doors < 0) {
                    size_of_maze = 0;
                    return;
                }
            }
        }
    }
    else {

        size_of_maze = 0;
    }
    if (count_doors == 1) size_of_maze = 0;
    inputMaze.close();
}
