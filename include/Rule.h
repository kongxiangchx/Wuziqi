#ifndef RULE_H
#define RULE_H

#include<bits/stdc++.h>
#include "Point.h"
#include "Strings.h"
using namespace std;

class Rule{
public:
    Rule();
    ~Rule();
    static int cnt_piece(int piece[16][16],Point p,Point dp,int color);
    static bool IsWin(int piece[16][16],Point p);
    static string GetStr(int piece[16][16],Point p,Point dp,int num);
    static bool SanSan(int piece[16][16],Point p);
    static bool SiSi(int piece[16][16],Point p);
    static bool ChangLian(int piece[16][16],Point p);
};

#endif // RULE_H
