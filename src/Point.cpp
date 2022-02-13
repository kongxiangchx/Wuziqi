#include "Point.h"

Point::Point(int x,int y){
    this->x=x;
    this->y=y;
}

Point::~Point(){

}

void Point::add(Point dp){
    this->x+=dp.x;
    this->y+=dp.y;
}
bool Point::IsValid(){
    if(this->x>=1&&this->x<=15&&this->y>=1&&this->y<=15){
        return true;
    }
    return false;
}
bool Point::IsEmpty(int piece[16][16]){
    if(piece[this->x][this->y]==0){
        return true;
    }
    return false;
}
bool Point::IsBlack(int piece[16][16]){
    if(piece[this->x][this->y]==1){
        return true;
    }
    return false;
}
bool Point::IsWhite(int piece[16][16]){
    if(piece[this->x][this->y]==2){
        return true;
    }
    return false;
}
