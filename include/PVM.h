#ifndef PVM_H
#define PVM_H

#include<iostream>
#include <windows.h>
#include "ChessInfo.h"
#include "ChessView.h"
#include "Rule.h"
#include "Tool.h"
#include "AI.h"
using namespace std;

class PVM{
public:
    PVM();
    ~PVM();
    static void PVM_Black_ChessShow(ChessInfo chess);
    static void PVM_White_ChessShow(ChessInfo chess);
    static void AI_Black(ChessInfo &chess);
    static void AI_White(ChessInfo &chess);
    static void PVM_Black();
    static void PVM_White();
    static void PVM_Game();
};


#endif // PVM_H
