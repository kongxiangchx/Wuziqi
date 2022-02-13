#ifndef POINT_H
#define POINT_H

#include<iostream>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int x,int y);
    ~Point();
    void add(Point dp);
    void FuZhi(Point p1);
    bool IsValid();
    bool IsEmpty(int piece[16][16]);
    bool IsBlack(int piece[16][16]);
    bool IsWhite(int piece[16][16]);
    bool operator<( const Point p ) const{
        if((this->x)==p.x){
            return (this->y)<p.y;
        }
        return (this->x)<p.x;
    }
};

#endif // POINT_H
