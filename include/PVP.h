#ifndef PVP_H
#define PVP_H

#include <iostream>
#include "ChessInfo.h"
#include "ChessView.h"
#include "Rule.h"
#include "Tool.h"
using namespace std;

class PVP{
public:
    PVP();
    ~PVP();
    static void PVP_ChessShow(ChessInfo chess);
    static void PVP_Game();
};

#endif // PVP_H
