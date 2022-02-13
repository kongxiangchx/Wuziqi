#ifndef CHESSVIEW_H
#define CHESSVIEW_H

#include<iostream>
#include<cstdio>
#include "Strings.h"
#include "Point.h"
using namespace std;

class ChessView {
public:
    ChessView();
    ~ChessView();
    static void ChessShow(int piece[16][16],Point p_cur);
    static string getBoard(int i,int j);
};

#endif // CHESSVIEW_H
