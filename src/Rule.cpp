#include "Rule.h"

Rule::Rule(){

}
Rule::~Rule(){

}

int Rule::cnt_piece(int piece[16][16],Point p,Point dp,int color){
    p.add(dp);
    int cnt=0;
    while(p.IsValid()){
        if(piece[p.x][p.y]==color){
            cnt++;
        }
        else{
            break;
        }
        p.add(dp);
    }
    return cnt;
}

bool Rule::IsWin(int piece[16][16],Point p){
    int color=piece[p.x][p.y];
    if(cnt_piece(piece,p,Point(-1,0),color)+cnt_piece(piece,p,Point(1,0),color)+1==5){
        return true;
    }
    else if(cnt_piece(piece,p,Point(0,-1),color)+cnt_piece(piece,p,Point(0,1),color)+1==5){
        return true;
    }
    else if(cnt_piece(piece,p,Point(-1,-1),color)+cnt_piece(piece,p,Point(1,1),color)+1==5){
        return true;
    }
    else if(cnt_piece(piece,p,Point(-1,1),color)+cnt_piece(piece,p,Point(1,-1),color)+1==5){
        return true;
    }
    return false;
}

string Rule::GetStr(int piece[16][16],Point p,Point dp,int num){
    string s="";
    for(int i=0;i<num;i++){
        p.add(dp);
        if(p.IsValid()==false){
            return "N";
        }
        s+='0'+piece[p.x][p.y];
    }
    return s;
}



bool Rule::SanSan(int piece[16][16],Point p){
    vector<string> san={
        "01110",
        "010110",
        "011010"
    };

    int dx[]={-1,0,-1,-1};
    int dy[]={0,-1,-1,1};

    int cnt=0;
    for(int d=0;d<4;d++){
        bool flag=false;
        for(int i=0;i<san.size();i++){
            for(int j=0;j<san[i].size();j++){
                if(san[i][j]=='1'){
                    string before=GetStr(piece,p,Point(dx[d],dy[d]),j);
                    reverse(before.begin(),before.end());
                    string after=GetStr(piece,p,Point(-dx[d],-dy[d]),san[i].size()-j-1);
                    if(before!="N"&&after!="N"&&before+"1"+after==san[i]){
                        cnt++;
                        flag=true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
    }
    if(cnt>=2){
        return true;
    }
    else{
        return false;
    }
}
bool Rule::SiSi(int piece[16][16],Point p){
    vector<string> si={
        "011110",
        "11110",
        "01111",
        "11011",
        "10111",
        "11101"
    };

    int dx[]={-1,0,-1,-1};
    int dy[]={0,-1,-1,1};

    int cnt=0;
    for(int d=0;d<4;d++){
        bool flag=false;
        for(int i=0;i<si.size();i++){
            for(int j=0;j<si[i].size();j++){
                if(si[i][j]=='1'){
                    string before=GetStr(piece,p,Point(dx[d],dy[d]),j);
                    reverse(before.begin(),before.end());
                    string after=GetStr(piece,p,Point(-dx[d],-dy[d]),si[i].size()-j-1);
                    if(before!="N"&&after!="N"&&before+"1"+after==si[i]){
                        cnt++;
                        flag=true;
                        break;
                    }
                }
            }
            if(flag){
                break;
            }
        }
    }
    if(cnt>=2){
        return true;
    }
    else{
        return false;
    }
}

bool Rule::ChangLian(int piece[16][16],Point p){
    int color=piece[p.x][p.y];
    if(cnt_piece(piece,p,Point(-1,0),color)+cnt_piece(piece,p,Point(1,0),color)+1>5){
        return true;
    }
    else if(cnt_piece(piece,p,Point(0,-1),color)+cnt_piece(piece,p,Point(0,1),color)+1>5){
        return true;
    }
    else if(cnt_piece(piece,p,Point(-1,-1),color)+cnt_piece(piece,p,Point(1,1),color)+1>5){
        return true;
    }
    else if(cnt_piece(piece,p,Point(-1,1),color)+cnt_piece(piece,p,Point(1,-1),color)+1>5){
        return true;
    }
    return false;
}
