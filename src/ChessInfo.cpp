#include "ChessInfo.h"

ChessInfo::ChessInfo(){
    for(int i=1;i<=ROW;i++){
        for(int j=1;j<=COL;j++){
            piece[i][j]=0;
        }
    }
    turn=B_Turn;
}
ChessInfo::~ChessInfo(){

}
