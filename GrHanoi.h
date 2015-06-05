//--- Main core of the painting Hanoi algorithm to the console ---
//(c) Jan Horacek 2012
//last modification: 30.12.2012
//v 1.0

#ifndef GRHANOI_H_INCLUDED
#define GRHANOI_H_INCLUDED

#include "TextGraf.h"

class GrHanoi {
    public:
        GrHanoi();
        ~GrHanoi();

        void Obr_move(int from, int to, int width, int from_cnt, int to_cnt, bool fr_cl_rand, bool beep);
        void Obr_create(int cnt, const int tower, const int wait);
        void YouWon();

    private:
        int _TOW_X[3];
        TextGraf* win_gr;

        void Tower_create();
        void Labels();

    protected:

};

#endif // GRHANOI_H_INCLUDED
