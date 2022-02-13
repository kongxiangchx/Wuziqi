#include "AI.h"

AI::AI(){

}

AI::~AI(){

}

bool IsAIBlack;
vector<int> v_piece;

vector<Pattern> ScoreTable_B = {
        { "11111",  50000 },
        { "011110", 4320 },
        { "011100", 720 },
        { "001110", 720 },
        { "011010", 720 },
        { "010110", 720 },
        { "11110",  720 },
        { "01111",  720 },
        { "11011",  720 },
        { "10111",  720 },
        { "11101",  720 },
        { "001100", 120 },
        { "001010", 120 },
        { "010100", 120 },
        { "000100", 20 },
        { "001000", 20 },
    };

vector<Pattern> ScoreTable_W = {
        { "22222",  50000 },
        { "022220", 4320 },
        { "022200", 720 },
        { "002220", 720 },
        { "022020", 720 },
        { "020220", 720 },
        { "22220",  720 },
        { "02222",  720 },
        { "22022",  720 },
        { "20222",  720 },
        { "22202",  720 },
        { "002200", 120 },
        { "002020", 120 },
        { "020200", 120 },
        { "000200", 20 },
        { "002000", 20 },
    };

vector<Point> AI::AllPossiblePoint(int piece[16][16],Point p){
    vector<Point> AllPoint;

    int dx[]={-1,1,0,0,-1,1,-1,1};
    int dy[]={0,0,-1,1,-1,1,1,-1};
    for(int i=0;i<8;i++){
        Point p1=Point(p.x,p.y);
        int cnt=4;
        p1.add(Point(dx[i],dy[i]));
        while(cnt--&&p1.IsValid()){
            if(piece[p1.x][p1.y]==0){
                AllPoint.push_back(p1);
            }
            p1.add(Point(dx[i],dy[i]));
        }
    }
    return AllPoint;
}

int AI::evaluate(int piece[16][16],Point p,bool IsBlack){
    int score=0;

    int dx[]={-1,0,-1,-1};
    int dy[]={0,-1,-1,1};

    if(IsBlack){
        for(int d=0;d<4;d++){
            bool flag=false;
            for(int i=0;i<ScoreTable_B.size();i++){
                string s=ScoreTable_B[i].s;
                for(int j=0;j<s.size();j++){
                    if(s[j]=='1'){
                        string before=Rule::GetStr(piece,p,Point(dx[d],dy[d]),j);
                        reverse(before.begin(),before.end());
                        string after=Rule::GetStr(piece,p,Point(-dx[d],-dy[d]),s.size()-j-1);
                        if(before!="N"&&after!="N"&&before+"1"+after==s){
                            score+=ScoreTable_B[i].score;
                            flag=true;
                            break;
                        }
                    }
                }
            }
        }
    }
    else{
        for(int d=0;d<4;d++){
            bool flag=false;
            for(int i=0;i<ScoreTable_W.size();i++){
                string s=ScoreTable_W[i].s;
                for(int j=0;j<s.size();j++){
                    if(s[j]=='2'){
                        string before=Rule::GetStr(piece,p,Point(dx[d],dy[d]),j);
                        reverse(before.begin(),before.end());
                        string after=Rule::GetStr(piece,p,Point(-dx[d],-dy[d]),s.size()-j-1);
                        if(before!="N"&&after!="N"&&before+"2"+after==s){
                            score+=ScoreTable_W[i].score;
                            flag=true;
                            break;
                        }
                    }
                }
            }
        }
    }
    return score;
}

int AI::PVS(ChessInfo chess,Point prev,int depth,int alpha,int beta){
    /*if(chess.turn==W_Turn){
        if(Rule::IsWin(chess.piece,prev)){
            if(IsAIBlack){
                return -50000;
            }
            else{
                return 50000;
            }
        }
        if(Rule::SanSan(chess.piece,prev)||Rule::SiSi(chess.piece,prev)||Rule::ChangLian(chess.piece,prev)){
            if(IsAIBlack){
                return 50000;
            }
            else{
                return -50000;
            }
        }
    }
    else{
        if(Rule::IsWin(chess.piece,prev)||Rule::ChangLian(chess.piece,prev)){
            if(IsAIBlack){
                return 50000;
            }
            else{
                return -50000;
            }
        }
    }*/

    if(depth<=0){
        return -evaluate(chess.piece,prev,(chess.turn==B_Turn)?false:true);
    }

    int value=-INF;
    bool FoundPv=false;

    set<int> set_point=AroundPoint(chess.piece);

    for(auto it=set_point.begin();it!=set_point.end();it++){
        Point p=Point((*it)/100,(*it)%100);
        if(chess.piece[p.x][p.y]==0){
            if(chess.turn==W_Turn){
                chess.piece[p.x][p.y]=W_Piece;
            }
            else{
                chess.piece[p.x][p.y]=B_Piece;
            }
            chess.turn=chess.turn^1;
            v_piece.push_back(p.x*100+p.y);

            if(FoundPv){
                value=-PVS(chess,p,depth-1,-alpha-1,-alpha);
                if(value>alpha&&value<beta) {
                    value=-PVS(chess,p,depth-1,-beta,-alpha);
                }
            }
            else{
               value=-PVS(chess,p,depth-1,-beta,-alpha);
            }

            chess.piece[p.x][p.y]=0;
            chess.turn=chess.turn^1;
            v_piece.pop_back();
            if(value>=beta){
                return beta;
            }
            if(value>alpha){
                alpha=value;
            }
        }
    }
    return alpha;
}

Point AI::FirstStep(ChessInfo chess,int depth){

    int value=-INF;
    int alpha=-INF,beta=INF;

    Point BestPoint=Point(-1,-1);
    bool FoundPv=false;
    vector<Point> vec_BestPoint;

    set<int> set_point=AroundPoint(chess.piece);

    for(auto it=set_point.begin();it!=set_point.end();it++){
        Point p=Point((*it)/100,(*it)%100);
        if(chess.piece[p.x][p.y]==0){
            if(chess.turn==W_Turn){
                chess.piece[p.x][p.y]=W_Piece;
            }
            else{
                chess.piece[p.x][p.y]=B_Piece;
            }
            if(chess.turn==B_Turn){
                if(Rule::IsWin(chess.piece,p)){
                    return p;
                }
            }
            else{
                if(Rule::IsWin(chess.piece,p)||Rule::ChangLian(chess.piece,p)){
                    return p;
                }
            }
            chess.turn=chess.turn^1;
            v_piece.push_back(p.x*100+p.y);

            if(FoundPv){
                value=-PVS(chess,p,depth-1,-alpha-1,-alpha);
                if(value>alpha&&value<beta) {
                    value=-PVS(chess,p,depth-1,-beta,-alpha);
                }
            }
            else{
               value=-PVS(chess,p,depth-1,-beta,-alpha);
            }
            chess.piece[p.x][p.y]=0;
            chess.turn=chess.turn^1;
            v_piece.pop_back();
            if(value>alpha){
                alpha=value;
                FoundPv=true;
                BestPoint=p;
                vec_BestPoint.clear();
                vec_BestPoint.push_back(p);
            }
            else if(value==alpha){
                vec_BestPoint.push_back(p);
            }
        }
    }
    int score=0;
    for(int i=0;i<vec_BestPoint.size();i++){
        int eva=evaluate(chess.piece,vec_BestPoint[i],(chess.turn==B_Turn)?true:false);
        if(eva>=50000){
            BestPoint=vec_BestPoint[i];
            break;
        }
        if(eva>score){
            if(chess.turn==B_Turn){
                if(Rule::SanSan(chess.piece,vec_BestPoint[i])||Rule::SiSi(chess.piece,vec_BestPoint[i])||Rule::ChangLian(chess.piece,vec_BestPoint[i])){
                    continue;
                }
            }
            score=eva;
            BestPoint=vec_BestPoint[i];
        }
    }
    //system("PAUSE");
    return BestPoint;
}

set<int> AI::AroundPoint(int piece[16][16]){
    set<int> set_point;

    for(auto it=v_piece.begin();it!=v_piece.end();it++){
        int i=(*it)/100;
        int j=(*it)%100;
        Point p_start=Point(max(i-2,1),max(j-2,1));
        Point p_finish=Point(min(i+2,15),min(j+2,15));
        for(int x=p_start.x;x<=p_finish.x;x++){
            for(int y=p_start.y;y<=p_finish.y;y++){
                if(piece[x][y]==0&&set_point.find(100*x+y)==set_point.end()){
                    set_point.insert(100*x+y);
                }
            }
        }
    }

    /*for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            if(piece[i][j]!=0){
                Point p_start=Point(max(i-2,1),max(j-2,1));
                Point p_finish=Point(min(i+2,15),min(j+2,15));
                for(int x=p_start.x;x<=p_finish.x;x++){
                    for(int y=p_start.y;y<=p_finish.y;y++){
                        if(piece[x][y]==0&&set_point.find(100*x+y)==set_point.end()){
                            set_point.insert(100*x+y);
                        }
                    }
                }
            }
        }
    }*/
    return set_point;
}

Point AI::getBestPoint(ChessInfo chess){
    int depth=2;
    IsAIBlack=(chess.turn==B_Turn)?true:false;
    for(int i=1;i<=15;i++){
        for(int j=1;j<=15;j++){
            if(chess.piece[i][j]!=0){
                v_piece.push_back(100*i+j);
            }
        }
    }
    return FirstStep(chess,depth);
}
