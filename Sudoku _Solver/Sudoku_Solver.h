#pragma once
#include <iostream>
#include<cstdlib>
#include<vector>
#include<Windows.h>
using namespace std;
constexpr auto UNASSIGNED = 0;
HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

class Sudoku
{
private:
    int bsize_y, bsize_x, dimension, MaxNumber;
    bool Check_Col(const vector<vector<int>>& Board, int NewItem, int j);
    bool Check_Row(const vector<vector<int>>& Board, int NewItem, int i);
    bool Check_Box_for_New_Item(const vector<vector<int>>& Board, int boxStartRow, int boxStartCol, int NewItem);
    bool Search_for_Empty(const vector<vector<int>>& Board, int& i, int& j);
    bool Check_if_fit(vector<vector<int>>& Board, int i, int j, int NewItem);
    bool Solve_Sudoku_Board(vector<vector<int>>& Board);
    void Difficulty();
    bool Check_if_Board_Correct(vector<vector<int>>& Board);
    void Printer(vector<vector<int>>& Board);



public:
    
    void set_Dimension(int Dimension) { dimension = Dimension; }

    Sudoku();
    ~Sudoku() {}
  
};
