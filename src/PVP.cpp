#include "PVP.h"

PVP::PVP(){

}

PVP::~PVP(){

}

void PVP::PVP_ChessShow(ChessInfo chess){
    system("CLS");
    cout<<" -------------------------------"<<endl;
    cout<<"|              PVP              |"<<endl;
    cout<<"|                               |"<<endl;
    cout<<"|    Input example: H8 or h8    |"<<endl;
    cout<<"|        Enter q to quit        |"<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<endl;
    ChessView::ChessShow(chess.piece,chess.p_cur);
    cout<<endl;
}

void PVP::PVP_Game(){
    ChessInfo chess;
    bool IsFirst=true;
    int cnt_piece=0;
    while(true){
        PVP_ChessShow(chess);
        cout<<"Please input x and y: ";
        string s;
        cin>>s;
        if(s=="q"){
            break;
        }
        char s_row=s[0];
        string s_col=s.substr(1,s.size()-1);
        Point p=Point(Tool::Num_row(s_row),Tool::Num_col(s_col));
        if(p.IsValid()&&p.IsEmpty(chess.piece)){
            if(IsFirst&&(p.x!=8||p.y!=8)){
                cout<<"\nThe first step of black piece needs to be in H8.\n";
                cout<<"Please press any key to continue...";
                getchar();
                getchar();
                continue;
            }
            else{
                IsFirst=false;
            }
            if(chess.turn==B_Turn){
                chess.piece[p.x][p.y]=B_Piece;
            }
            else{
                chess.piece[p.x][p.y]=W_Piece;
            }
            chess.p_cur=p;
            cnt_piece++;
            if(Rule::IsWin(chess.piece,p)||(chess.turn==W_Turn&&Rule::ChangLian(chess.piece,p))){
                PVP_ChessShow(chess);
                switch(chess.piece[p.x][p.y]){
                    case 1:cout<<"Black piece win!"<<endl;
                    break;
                    case 2:cout<<"White piece win!"<<endl;
                    break;
                    default:break;
                }
                break;
            }
            if(chess.turn==B_Turn){
                if(Rule::SanSan(chess.piece,p)){
                    PVP_ChessShow(chess);
                    cout<<"SanSanJinShou, White piece win!"<<endl;
                    break;
                }
                if(Rule::SiSi(chess.piece,p)){
                    PVP_ChessShow(chess);
                    cout<<"SiSiJinShou, White piece win!"<<endl;
                    break;
                }
                if(Rule::ChangLian(chess.piece,p)){
                    PVP_ChessShow(chess);
                    cout<<"ChangLian, White piece win!"<<endl;
                    break;
                }
            }
            if(cnt_piece==ROW*COL){
                PVP_ChessShow(chess);
                cout<<"HeQi"<<endl;
                break;
            }
            chess.turn=chess.turn^1;
        }
        else{
            cout<<"\nYour input is illegal.\n";
            cout<<"Please press any key to continue...";
            getchar();
            getchar();
        }
    }
    cout<<endl;
    cout<<"Please press any key to quit...";
    getchar();
    getchar();
}
