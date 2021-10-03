// Sudoku _Solver.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector> 
#include<cstdlib>
#include<Windows.h>
#include"Sudoku_Solver.h"
#include"Console.h"


Sudoku::Sudoku() :dimension (9) {

    Difficulty();

    vector < vector <int> >Board(dimension, vector <int>(dimension)); (UNASSIGNED);



    for (int i = 0; i < Board.size(); i++) {
        for (int j = 0; j < Board.size(); j++) {
            cin >> Board[i][j];
                           
        }
    }
   
    
    while (Check_if_Board_Correct(Board) == true) 
    {
        cout << "\n Error board max number should be : " << MaxNumber << " Please try again\n\n";
        system("Pause");
        system("cls");
        for (int i = 0; i < Board.size(); i++) {
            for (int j = 0; j < Board.size(); j++) {
                cin >> Board[i][j];

            }
        }
    }

    if (Solve_Sudoku_Board(Board) == true) {
        cout << "\n\nBoard has been solved with result:\n";
         Printer( Board);
    }
    else {
        cout << "\n solution was not reached due to board being unsolvable\n";
        exit;
    }
}
bool Sudoku::Check_Row(const vector<vector<int>>& Board, int NewItem, int i)
{
    for (int col = 0; col < Board.size(); col++)
        if (Board[i][col] == NewItem)
            return true;

    return false;

}
bool Sudoku::Check_Col(const vector<vector<int>>& Board, int NewItem, int j)
{
    for (int row = 0; row < Board.size(); row++)
        if (Board[row][j] == NewItem)
            return true;

    return false;

}
bool Sudoku::Check_Box_for_New_Item(const vector<vector<int>>& Board, int boxStartRow, int boxStartCol, int NewItem)
{
    for (int row = 0; row < bsize_y; row++)
        for (int col = 0; col < bsize_x; col++)
            if (Board[row + boxStartRow][col + boxStartCol] == NewItem)
                return true;
    return false;
}
bool Sudoku::Search_for_Empty(const vector<vector<int>>& Board, int& i, int& j) {

    for (i = 0; i < Board.size(); i++) {
        for (j = 0; j < Board.size(); j++)
        {
            if (Board[i][j] == UNASSIGNED)
                return true;
        }
    }
    return false;
}
bool Sudoku::Check_if_fit(vector<vector<int>>& Board, int i, int j, int NewItem)
{
    return (!Check_Row(Board, NewItem, i) &&
        !Check_Col(Board, NewItem, j) &&
        !Check_Box_for_New_Item(Board, i - i % bsize_y, j - j % bsize_x, NewItem));
}
bool Sudoku::Solve_Sudoku_Board(vector<vector<int>>& Board) {
    int i, j ;
    if (!Search_for_Empty(Board, i, j))
        return true;

    for (int NewItem = 1; NewItem <= MaxNumber; NewItem++) {
        if (Check_if_fit(Board, i, j, NewItem))
        {
            Board[i][j] = NewItem;
            if (Solve_Sudoku_Board(Board))
                return true;
            Board[i][j] = UNASSIGNED;
        }
    }
    return false;
}
void Sudoku::Difficulty() 
{
    while (true) {
        int size;
        cout << "\n Enter Size of the Field(6,9,12,16)";
        cin >> size;
        if (size == 6 || size == 9 || size == 12 || size == 16) 
        { 
            set_Dimension(size);
            
            if (size == 6) {
                bsize_y = 2;
                bsize_x = 3;
                MaxNumber = 6;
            }

            else if (size == 9) {
                bsize_y = 3;
                bsize_x = 3;
                MaxNumber = 9;
            }
            else if (size ==12) {
                bsize_y = 3;
                bsize_x = 4;
                MaxNumber = 12;
            }
            else if (size == 16) {
                bsize_y = 4;
                bsize_x = 4;
                MaxNumber = 16;
            }


           
            system("cls");
            cout << "\nCtrl+V the field from txt file using this format\nUse numbers only\n";
            for (int i = 0; i < size / 2; i++)
            {
                for (int j = 0; j < size / 2; j++)
                {
                    cout << "0 ";
                }
                cout << "\n";
            }
            system("PAUSE");
            system("cls");
            break;
        }
        else {
            cout << "\n Please enter correct Size of the Field (6,9,12,16)";
            Difficulty();
        };

        break;
    }


}
bool Sudoku::Check_if_Board_Correct(vector<vector<int>>& Board)
{
    for (int i = 0; i < Board.size(); i++) {
        for (int j = 0; j < Board.size(); j++) {

            if (Board[i][j] > MaxNumber)
                return true;
        }
    }

    
   return false;

}
void Sudoku::Printer(vector<vector<int>>& Board)
{
    for (int i = 0; i < Board.size() * 2.452; i++) {
        cout << "_";
    }cout << "\n";

    for (int row = 0; row < Board.size(); row++) {
        cout << "| ";
        for (int col = 0; col < Board.size(); col++) {

            Color(Board, row, col);

            cout << Board[row][col] << " ";
            if (col + 1 % bsize_x == bsize_x || col + 1 % bsize_x == bsize_x*2 || col + 1 % bsize_x == bsize_x*3 || col + 1 % bsize_x == bsize_x*4 || col + 1 % bsize_x == bsize_x*5)
                cout << "|";
        }

        if (row + 1 % bsize_y == bsize_y || row + 1 % bsize_y == bsize_y*2 || row + 1 % bsize_y == bsize_y*3  || row + 1 % bsize_y == bsize_y *4 || row + 1 % bsize_y == bsize_y*5) {
            cout << endl;

            for (int i = 0; i < Board.size() * 2.452; i++) { cout << "_"; };
        }
        cout << endl;
    }
}




int main()
{

    console();
    Sudoku a;
    system("PAUSE");
    return 0;


}