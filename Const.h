//Program global constants

#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

const int _MIN_WIDTH  = 3;
const int _PLUS_WIDTH = 2;

const int _MV_SLEEP   = 150;    //moving obr.
const int _CR_SLEEP   = 50;    //creating obr.

const int _OBR_MAX    = 10;
const int _OBR_DEF    = 5;

//towers Y positions
const int _TOW_Y   = _OBR_MAX+1;

//characters
const char _CHAR_OBR = '#';
const char _CHAR_TOW = '|';

const int _C_LABELS = 5;
const int _C_OBR    = 8;
const int _C_TOW    = 10;

const int _C_WON    = 9;
const int _B_WON    = 14;

const int _C_DEF    = 7;
const int _B_DEF    = 0;

#endif