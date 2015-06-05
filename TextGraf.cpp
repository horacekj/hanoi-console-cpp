//--- Text graphic for windows console ---
//(c) Jan Horacek 2012
//last modification: 30.12.2012
//v 1.0

#include "TextGraf.h"
#include <windows.h>

//ctor
TextGraf::TextGraf()
{
    this->hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    if (GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi))
    {
        this->term_width  = csbi.dwSize.X;
        this->term_height = csbi.dwSize.Y;
    }
}

//dtor
TextGraf::~TextGraf() {}

void TextGraf::ClearConsole()
{
    const int _CLEAR_X = 0;
    const int _CLEAR_Y = 0;

    DWORD count;
    COORD coord = {_CLEAR_X, _CLEAR_Y};

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    { //Vyplní obrazovku mezerami.
        FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
        //Kurzor nastaví na zadanou pozici.
        SetConsoleCursorPosition(hStdOut, coord);
    }
}//ClearConsole

void TextGraf::ClearConsoleToColors(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(this->hStdOut, wColor);
}

void TextGraf::gotoXY(short x, short y)
{
    COORD coord = {x,y};
    SetConsoleCursorPosition(hStdOut, coord);
}

void TextGraf::SetColor(int ForgC)
{
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        //WORD wColor = (ForgC & 0x0F);
        WORD wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
}

void TextGraf::SetColorAndBackground(int ForgC, int BackC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(hStdOut, wColor);
}

void TextGraf::ConPrint(char *CharBuffer, int len)
{
//    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), CharBuffer, len, &count, NULL);
}

void TextGraf::HideTheCursor()
{
    CONSOLE_CURSOR_INFO cciCursor;
    if (GetConsoleCursorInfo(hStdOut, &cciCursor))
    {
        cciCursor.bVisible=FALSE;
        SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &cciCursor);
    }
}

void TextGraf::ShowTheCursor()
{
    CONSOLE_CURSOR_INFO cciCursor;
    if (GetConsoleCursorInfo(hStdOut, &cciCursor))
    {
        cciCursor.bVisible=TRUE;
        SetConsoleCursorInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &cciCursor);
    }
}
