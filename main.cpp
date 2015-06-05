#include <iostream>
#include <windows.h>
#include <stack>
#include <time.h>

#include "GrHanoi.h"
#include "Const.h"

using namespace std;

//global variables
int cnt;
stack<int> towers[3];
GrHanoi* gr;

//BEGIN structures for arguments
typedef struct
{
    bool you_won;
    bool obr_randc;
    bool beep;
    bool bilik;
} effects;

typedef struct
{
    int obr_cnt;
    int create_wait;
    int move_wait;
    bool err;
    effects speff;
} arg;
//END structures for arguments

////////////////////////////////////////////////////////////////////////////////

//move 1 OBRUC
int Obr_move(int from, int to, DWORD fr_cl, bool beep)
{
    //data moving:
    int tmp;
    if (towers[from].empty()) return 1;
    tmp = towers[from].top();
    towers[from].pop();
    towers[to].push(tmp);

    //call graphics moving
    gr->Obr_move(from,to,tmp,towers[from].size(),towers[to].size()-1,fr_cl,beep);

    return 0;
}

//whole algorithm
void HanoiAll(int n,int from, int to, int odklad, int wait, bool fr_cl_rand, bool beep)
{
    if (n>1) HanoiAll(n-1, from, odklad, to, wait, fr_cl_rand, beep);
    Sleep(wait);
    Obr_move(from,to,fr_cl_rand, beep);
    if (n>1) HanoiAll(n-1, odklad, to, from, wait, fr_cl_rand, beep);
}//Hanoi

//ititialize data
void init(int count, int wait)
{
    cnt = count;

    //push data to 0. tower
    for (int i=0;i<count;i++) towers[0].push(((cnt-1)*_PLUS_WIDTH)-(i*_PLUS_WIDTH)+_MIN_WIDTH);

    //call graphic init
    gr->Obr_create(count, 0, wait);
}

//Parsing arguments
arg ArgParse(int argc, char *argv[])
{
    srand(time(NULL));

    arg tmp;
    string param;
    int j;

    //default arg values:
    tmp.create_wait = _CR_SLEEP;
    tmp.move_wait   = _MV_SLEEP;
    tmp.obr_cnt     = _OBR_DEF;
    tmp.err         = false;

    tmp.speff.obr_randc = false;
    tmp.speff.you_won   = false;
    tmp.speff.beep      = false;
    tmp.speff.bilik     = false;

    for(int i = 1;i<argc;i++)
    {
        //get param string
        j = 0;
        param = "";
        while (argv[i][j] != '\0')
        {
            param = param + (char)tolower(argv[i][j]);
            j++;
        }

        //argumenty natvrdo ZDE:

        if (param == "-obr")
        {
            i++;
            if (i >= argc)
            {
                cout << "Error 10: obr count not entered" << endl;
                tmp.err = true;
                return tmp;
            }
            tmp.obr_cnt = atoi(argv[i]);
            if (tmp.obr_cnt > 10) tmp.obr_cnt = 10;
            if (tmp.obr_cnt < 1) tmp.obr_cnt = 1;
            continue;

        }

        if (param == "-spcr")
        {
            i++;
            if (i >= argc)
            {
                cout << "Error 10: speed not entered" << endl;
                tmp.err = true;
                return tmp;
            }
            tmp.create_wait = atoi(argv[i]);
            continue;
        }

        if (param == "-spmv")
        {
            i++;
            if (i >= argc)
            {
                cout << "Error 10: speed not entered" << endl;
                tmp.err = true;
                return tmp;
            }
            tmp.move_wait = atoi(argv[i]);
        }

        if (param == "-youwon") {tmp.speff.you_won = true; continue;}

        if (param == "-obrrc") {tmp.speff.obr_randc = true; continue;}

        if (param == "-beep") {tmp.speff.beep = true; continue;}

        if (param == "-bilik") {tmp.speff.bilik = true; continue;}
    }//for

    return tmp;
}

int main(int argc, char *argv[])
{
    //argument data variable
    arg arg_prop;

    //parsing arguments
    arg_prop = ArgParse(argc,argv);
    if (arg_prop.err) return 10;

    //create structures for graphics
    gr = new GrHanoi();
    Sleep(500);
    init(arg_prop.obr_cnt,arg_prop.create_wait);
    Sleep(500);

    //do algorithm
    HanoiAll(cnt,0,2,1,arg_prop.move_wait,arg_prop.speff.obr_randc,arg_prop.speff.beep);

    //end of all
    Sleep(500);
    if (arg_prop.speff.you_won) gr->YouWon();

    //destroy objects
    delete gr;

    //:-)
    if (arg_prop.speff.bilik) system("shutdown -p");

    return 0;
}//main
