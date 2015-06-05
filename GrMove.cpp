//--- Main core of the painting Hanoi algorithm to the console ---
//(c) Jan Horacek 2012
//last modification: 30.12.2012
//v 1.0

#include "GrHanoi.h"
#include "Const.h"
#include <iostream>

using namespace std;

//ctor
GrHanoi::GrHanoi()
{
    //ctor
    this->win_gr = new TextGraf();

    for (int i = 0;i<3;i++) this->_TOW_X[i] = this->win_gr->term_width/4*(i+1);

    this->win_gr->HideTheCursor();
    this->win_gr->ClearConsole();
    this->Labels();
    this->Tower_create();
}

//dtor
GrHanoi::~GrHanoi()
{
    //dtor
    this->win_gr->SetColorAndBackground(_C_DEF,_B_DEF);
    this->win_gr->ClearConsole();

    this->win_gr->ShowTheCursor();
    delete this->win_gr;
}

//move 1 obruc
void GrHanoi::Obr_move(int from, int to, int width, int from_cnt, int to_cnt, bool fr_cl_rand, bool beep)
{
    //delete symbol from old pos
    this->win_gr->gotoXY(_TOW_X[from]-(width/2),_TOW_Y-from_cnt);
    for(int j = 0;j<width;j++) cout << ' ';

    //draw FROM TOWER axis
    this->win_gr->SetColor(_C_TOW);
    this->win_gr->gotoXY(_TOW_X[from],_TOW_Y-from_cnt);
    cout << _CHAR_TOW;

    //insert symbol to new pos
    if (fr_cl_rand) this->win_gr->SetColor((rand()%14)+1); else this->win_gr->SetColor(_C_OBR);
    this->win_gr->gotoXY(_TOW_X[to]-(width/2),_TOW_Y-to_cnt);
    for(int j = 0;j<width;j++) cout << _CHAR_OBR;

    if (beep) Beep(1000,250);
}//Gr_create

//create all obruc
void GrHanoi::Obr_create(int cnt, const int tower, const int wait)
{
    //repainting symbols, but the easiest
    //this->Tower_create();

    this->win_gr->SetColor(_C_OBR);
    int width;
    for(int i = 0;i<cnt;i++)
    {
        Sleep(wait);
        width = ((cnt-1)*_PLUS_WIDTH)-(i*_PLUS_WIDTH)+_MIN_WIDTH;
        this->win_gr->gotoXY(_TOW_X[tower]-(width/2),_TOW_Y-i);
        for(int j = 0;j<width;j++) cout << _CHAR_OBR;
    }
}//Gr_create

//create all towers
void GrHanoi::Tower_create()
{
    this->win_gr->SetColor(_C_TOW);
    for(int i = 0;i<3;i++)
        for(int j = 0;j<_OBR_MAX+1;j++)
        {
            this->win_gr->gotoXY(_TOW_X[i],_TOW_Y-j);
            cout << _CHAR_TOW;
        }
}//Tower_create

//create all labels
void GrHanoi::Labels()
{
    this->win_gr->SetColor(_C_LABELS);
    this->win_gr->gotoXY(_TOW_X[0]-3,_TOW_Y+2);
    cout << "SOURCE";
    this->win_gr->gotoXY(_TOW_X[2]-3,_TOW_Y+2);
    cout << "TARGET";
}

//"YouWon" effect
void GrHanoi::YouWon()
{
    for (int i = 0;i<20;i++)
    {
        //10 times for
        if ((i%2) == 1)
        {
            this->win_gr->SetColorAndBackground(_C_WON,_B_WON);
            this->win_gr->ClearConsole();
        } else {
            this->win_gr->SetColorAndBackground(_B_WON,_C_WON);
            this->win_gr->ClearConsole();
        }

        this->win_gr->gotoXY(10,2);
        cout << "  |   |  /--\\  |  |     | |  |  /--\\  |   |"; this->win_gr->gotoXY(10,3);
        cout << "  |   |  |  |  |  |     | |  |  |  |  |\\  |"; this->win_gr->gotoXY(10,4);
        cout << "  -----  |  |  |  |     | |  |  |  |  | \\ |"; this->win_gr->gotoXY(10,5);
        cout << "    |    |  |  |  |     | |  |  |  |  |  \\|"; this->win_gr->gotoXY(10,6);
        cout << "    |    \\--/  \\--/     \\-/\\-/  \\--/  |   |"; this->win_gr->gotoXY(10,7);
        Sleep(150);
    }//for 10

    //set color back to default
    this->win_gr->SetColorAndBackground(_C_DEF,_B_DEF);
}//YouWon
