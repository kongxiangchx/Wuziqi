#ifndef CHESSINFO_H
#define CHESSINFO_H

#include<iostream>
#include<vector>
#include "Strings.h"
#include "Point.h"
using namespace std;

class ChessInfo{
public:
    ChessInfo();
    ~ChessInfo();
    int piece[ROW+1][COL+1];
    int turn;
    Point p_cur=Point(-1,-1);
};

#endif // CHESSINFO_H
