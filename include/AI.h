#ifndef AI_H
#define AI_H

#include<bits/stdc++.h>
#include "Point.h"
#include "ChessInfo.h"
#include "Rule.h"
#include "Pattern.h"
using namespace std;

#define INF 0x3f3f3f3f

class AI{
public:
    AI();
    ~AI();
    static int evaluate(int piece[16][16],Point p,bool IsBlack);
    static vector<Point> AllPossiblePoint(int piece[16][16],Point p);
    static int PVS(ChessInfo chess,Point prev,int depth,int alpha,int beta);
    static Point FirstStep(ChessInfo chess,int depth);
    static set<int> AroundPoint(int piece[16][16]);
    static Point getBestPoint(ChessInfo chess);
};

#endif // AI_H
