#pragma once


#include "Sudoku_Solver.h"



void console()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions
    MoveWindow(console, r.left, r.top, 500, 500, 1);
    PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX();
    lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);
    lpConsoleCurrentFontEx->dwFontSize.X = 27;
    lpConsoleCurrentFontEx->dwFontSize.Y = 27;
    SetCurrentConsoleFontEx(out, 0, lpConsoleCurrentFontEx);


    cout << "\n\n\n\t\t Hi! Welcome to Sudoku Solver\n\n\n\n\n";    
    system("PAUSE");
    system("cls");
    
}

void Color(vector<vector<int>>& Board, int& i, int& j)
{

    SetConsoleTextAttribute(out, Board[i][j]);

}


