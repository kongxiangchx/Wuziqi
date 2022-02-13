#include "ChessView.h"

ChessView::ChessView() {

}

ChessView::~ChessView() {

}

void ChessView::ChessShow(int piece[16][16],Point p_cur) {
    for(int j=COL;j>=1;j--){
        printf("%2d",j);
        for(int i=1;i<=ROW;i++){
            if(piece[i][j]==0){
                cout<<getBoard(i,j);
            }
            else if(piece[i][j]==W_Piece){
                if(p_cur.x==i&&p_cur.y==j){
                    cout<<"¡ø";
                }
                else{
                    cout<<"¡ñ";
                }
            }
            else if(piece[i][j]==B_Piece){
                if(p_cur.x==i&&p_cur.y==j){
                    cout<<"¡÷";
                }
                else{
                    cout<<"¡ð";
                }
            }
        }
        cout<<endl;
    }
    cout<<"  ";
    for(int i=1;i<=ROW;i++){
        printf("%2c",(char)('A'+i-1));
    }
    cout<<endl;
}
string ChessView::getBoard(int i,int j) {
    if(i==1&&j==1) {
        return "©» ";
    }
    else if(i==1&&j==15) {
        return "©³ ";
    }
    else if(i==15&&j==1) {
        return "©¿";
    }
    else if(i==15&&j==15) {
        return "©·";
    }
    else if(i==1) {
        return "©Ä ";
    }
    else if(i==15) {
        return "©Ì";
    }
    else if(j==1) {
        return "©Û ";
    }
    else if(j==15) {
        return "©Ó ";
    }
    else {
        return "©à ";
    }
}
