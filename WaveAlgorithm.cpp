#include <iostream>
#include <vector>
#include <math.h>
#include "generate.h"
#include <thread>
using namespace std;
void waveAlgorithm(vector<vector<char>> maze, int size_of_maze,int user_number) {
	vector<vector<int>> wave(size_of_maze, vector<int>(size_of_maze));
	int start_x, start_y, finish_x, finish_y;
    for (int i = 1; i < size_of_maze - 1; i++) {
        if (maze[i][size_of_maze - 2] == '/') {
            finish_y = i;
            finish_x = size_of_maze - 2;
        }
        if (maze[1][i] == '/') {
            finish_y = 1;
            finish_x = i;
        }
        if (maze[size_of_maze - 2][i] == '/') {
            start_x = i;
            start_y = size_of_maze - 2;
        }
        if (maze[i][1] == '/') {
            start_y = i;
            start_x = 1;
        }

    }
    for (int i = 0; i < size_of_maze; i++) {
        for (int j = 0; j < size_of_maze; j++) {
            if (i == 0 || j == 0 || j == size_of_maze - 1 || i == size_of_maze - 1 || maze[i][j] == '#') {
                wave[i][j] = 11111;
            }
            else if (maze[i][j] == '.') {
                wave[i][j] = -1;
            }
            else
                wave[i][j] = 0;
        }
    }
    wave[finish_y][finish_x] = 7777;
    vector<vector<int>>oldWave = wave;
    int step = 0;
    bool flag = 1;
    while (flag) {
        for (int i = 1; i < size_of_maze - 1; i++) {
            for (int j = 1; j < size_of_maze - 1; j++) {
                if (wave[i][j] == step) {
                    if (wave[i][j + 1] == 7777 || wave[i][j - 1] == 7777 ||wave[i - 1][j] == 7777 || wave[i + 1][j] == 7777) {
                        flag = 0;
                    }
                    if (wave[i][j + 1] != 11111 && wave[i][j + 1] != 0 &&wave[i][j + 1] < 0) {
                        wave[i][j + 1] = step + 1;
                    }
                    if (wave[i][j - 1] != 11111 && wave[i][j - 1] != 0 &&wave[i][j - 1] < 0) {
                        wave[i][j - 1] = step + 1;
                    }
                    if (wave[i + 1][j] != 11111 && wave[i + 1][j] != 0 &&wave[i + 1][j] < 0) {
                        wave[i + 1][j] = step + 1;
                    }
                    if (wave[i - 1][j] != 11111 && wave[i - 1][j] != 0 &&wave[i - 1][j] < 0) {
                        wave[i - 1][j] = step + 1;
                    }
                }
            }
        }
        step++;
        if (oldWave == wave && flag){
            cout << "выхооооода нееет,ключ поверни и полетели" << endl;
            flag = 0;
            return;
        }
   
        
    }
    vector<vector<int>> way;
    int number1, number2, number3, number4,min_number;
    while (true) { 
        number1 = 11110;
        number2 = 11110;
        number3 = 11110;
        number4 = 11110;
        if (wave[finish_y + 1][finish_x] != 11111 && wave[finish_y + 1][finish_x] != -1)
            number1 = wave[finish_y + 1][finish_x];
        if (wave[finish_y][finish_x + 1] != 11111 && wave[finish_y][finish_x + 1] != -1)
            number2 = wave[finish_y][finish_x + 1];
        if (wave[finish_y][finish_x - 1] != 11111 && wave[finish_y][finish_x - 1] != -1)
            number3 = wave[finish_y][finish_x - 1];
        if (wave[finish_y - 1][finish_x] != 11111 && wave[finish_y - 1][finish_x] != -1)
            number4 = wave[finish_y - 1][finish_x];
        min_number = 1000000;
        min_number = min(min_number, number1);
        min_number = min(min_number, number2);
        min_number = min(min_number, number3);
        min_number = min(min_number, number4);
        way.push_back(vector<int>(2));
        if (min_number == 0) break;
        if (min_number == number1) {
            way.back()[0] = finish_y + 1;
            way.back()[1] = finish_x;
            finish_y++;
            continue;
        }
        if (min_number == number2) {
            way.back()[0] = finish_y;
            way.back()[1] = finish_x + 1;
            finish_x++;
            continue;

        }
        if (min_number == number3) {
            way.back()[0] = finish_y;
            way.back()[1] = finish_x - 1;
            finish_x--;
            continue;
        }
        if (min_number == number4) {
            way.back()[0] = finish_y - 1;
            way.back()[1] = finish_x;
            finish_y--;
            continue;
        }

    }
    if (user_number == 1) {
        for (int i = 0; i < way.size(); i++) {
            int x = way[i][1];
            int y = way[i][0];
            maze[y][x] = '*';
            maze[0][0] = '#';
        }
        printMaze(maze, size_of_maze);
    }
    if (user_number == 2) {
        
        for (int i = 0; i < way.size(); i++) {
            int x = way[i][1];
            int y = way[i][0];
            maze[y][x] = '*';
            maze[0][0] = '#';
        }
        printFileShortMaze(maze, size_of_maze);
    }
   
}
