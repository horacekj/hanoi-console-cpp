//--- Text graphic for windows console ---
//(c) Jan Horacek 2012
//last modification: 30.12.2012
//v 1.0

#ifndef TEXTGRAF_H
#define TEXTGRAF_H
#include <windows.h>

class TextGraf{

    public:
        int term_width,term_height;

        TextGraf();
        ~TextGraf();

        void ClearConsole();
        void ClearConsoleToColors(int ForgC, int BackC);
        void gotoXY(short x, short y);
        void SetColor(int ForgC);
        void SetColorAndBackground( int ForgC, int BackC);
        void ConPrint(char *CharBuffer, int len);
        void HideTheCursor();
        void ShowTheCursor();

    private:
        HANDLE hStdOut;
        CONSOLE_SCREEN_BUFFER_INFO csbi;

    protected:

};
#endif // TETXGRAF_H
