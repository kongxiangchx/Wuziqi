#include "PVM.h"

PVM::PVM(){

}

PVM::~PVM(){

}

void PVM::PVM_Black_ChessShow(ChessInfo chess){
    system("CLS");
    cout<<" -------------------------------"<<endl;
    cout<<"|              PVM              |"<<endl;
    cout<<"|       P:Black   M:White       |"<<endl;
    cout<<"|    Input example: H8 or h8    |"<<endl;
    cout<<"|        Enter q to quit        |"<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<endl;
    ChessView::ChessShow(chess.piece,chess.p_cur);
    cout<<endl;
}

void PVM::PVM_White_ChessShow(ChessInfo chess){
    system("CLS");
    cout<<" -------------------------------"<<endl;
    cout<<"|              PVM              |"<<endl;
    cout<<"|       P:White   M:Black       |"<<endl;
    cout<<"|    Input example: H8 or h8    |"<<endl;
    cout<<"|        Enter q to quit        |"<<endl;
    cout<<" -------------------------------"<<endl;
    cout<<endl;
    ChessView::ChessShow(chess.piece,chess.p_cur);
    cout<<endl;
}



void PVM::AI_White(ChessInfo &chess){
    Point bestPoint=AI::getBestPoint(chess);
    chess.piece[bestPoint.x][bestPoint.y]=W_Piece;
    chess.p_cur=bestPoint;
    chess.turn=chess.turn^1;
}

void PVM::PVM_Black(){
    ChessInfo chess;
    bool IsFirst=true;
    int cnt_piece=0;
    while(true){
        PVM_Black_ChessShow(chess);
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
            chess.piece[p.x][p.y]=B_Piece;
            chess.p_cur=p;
            chess.turn=chess.turn^1;
            if(Rule::IsWin(chess.piece,p)){
                PVM_Black_ChessShow(chess);
                cout<<"Black piece win!"<<endl;
                break;
            }
            if(Rule::SanSan(chess.piece,p)){
                PVM_Black_ChessShow(chess);
                cout<<"SanSanJinShou, White piece win!"<<endl;
                break;
            }
            if(Rule::SiSi(chess.piece,p)){
                PVM_Black_ChessShow(chess);
                cout<<"SiSiJinShou, White piece win!"<<endl;
                break;
            }
            if(Rule::ChangLian(chess.piece,p)){
                PVM_Black_ChessShow(chess);
                cout<<"ChangLian, White piece win!"<<endl;
                break;
            }

            PVM_Black_ChessShow(chess);
            cout<<"Waiting AI..."<<endl;

            AI_White(chess);
            if(Rule::IsWin(chess.piece,chess.p_cur)||Rule::ChangLian(chess.piece,chess.p_cur)){
                PVM_Black_ChessShow(chess);
                cout<<"White piece win!"<<endl;
                break;
            }

            cnt_piece+=2;
            if(cnt_piece==ROW*COL){
                PVM_Black_ChessShow(chess);
                cout<<"HeQi"<<endl;
                break;
            }
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

void PVM::AI_Black(ChessInfo &chess){
    Point bestPoint=AI::getBestPoint(chess);
    chess.piece[bestPoint.x][bestPoint.y]=B_Piece;
    chess.p_cur=bestPoint;
    chess.turn=chess.turn^1;
}

void PVM::PVM_White(){
    ChessInfo chess;
    bool IsFirst=true;
    int cnt_piece=0;
    while(true){
        PVM_White_ChessShow(chess);
        if(IsFirst){
            chess.piece[8][8]=B_Piece;
            chess.p_cur=Point(8,8);
            chess.turn=chess.turn^1;
            IsFirst=false;
            Sleep(1000);
            continue;
        }
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
            chess.piece[p.x][p.y]=W_Piece;
            chess.p_cur=p;
            chess.turn=chess.turn^1;
            if(Rule::IsWin(chess.piece,p)||Rule::ChangLian(chess.piece,p)){
                PVM_White_ChessShow(chess);
                cout<<"White piece win!"<<endl;
                break;
            }

            PVM_White_ChessShow(chess);
            cout<<"Waiting AI..."<<endl;

            AI_Black(chess);
            if(Rule::IsWin(chess.piece,chess.p_cur)){
                PVM_White_ChessShow(chess);
                cout<<"Black piece win!"<<endl;
                break;
            }
            if(Rule::SanSan(chess.piece,chess.p_cur)){
                PVM_White_ChessShow(chess);
                cout<<"SanSanJinShou, White piece win!"<<endl;
                break;
            }
            if(Rule::SiSi(chess.piece,chess.p_cur)){
                PVM_White_ChessShow(chess);
                cout<<"SiSiJinShou, White piece win!"<<endl;
                break;
            }
            if(Rule::ChangLian(chess.piece,chess.p_cur)){
                PVM_White_ChessShow(chess);
                cout<<"ChangLian, White piece win!"<<endl;
                break;
            }

            cnt_piece+=2;
            if(cnt_piece==ROW*COL){
                PVM_White_ChessShow(chess);
                cout<<"HeQi"<<endl;
                break;
            }
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

void PVM::PVM_Game(){
    while(true){
        system("CLS");
        cout<<"Please choose your turn:"<<endl;
        cout<<"BLACK  :  1"<<endl;
        cout<<"WHITE  :  2"<<endl;
        cout<<"Quit  :  q"<<endl;
        cout<<endl;
        cout<<"Your choice : ";
        string turn;
        cin>>turn;
        if(turn=="1"){
            PVM_Black();
        }
        else if(turn=="2"){
            PVM_White();
        }
        else if(turn=="q"){
            break;
        }
    }
}
