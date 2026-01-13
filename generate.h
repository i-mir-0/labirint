#ifndef generate
#define generate
#include <iostream>
#include <vector>
using namespace std;

void generateMaze(vector<vector<char>>& maze, int size_of_maze);
void printMaze(vector<vector<char>> maze, int size_of_maze);
void printFileMaze(vector<vector<char>> maze, int size_of_maze);
void printFileShortMaze(vector<vector<char>> maze, int size_of_maze);
void InputFileMaze(vector<vector<char>>& maze, int& size_of_maze);


#endif 
