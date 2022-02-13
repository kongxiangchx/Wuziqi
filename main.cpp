#include <iostream>
#include "PVP.h"
#include "PVM.h"
using namespace std;

int main(){
    cout<<" ---------------------------------------"<<endl;
    cout<<"|             Wuziqi Game               |"<<endl;
    cout<<"|                                       |"<<endl;
    cout<<"|         Welcome to the game!          |"<<endl;
    cout<<"|  The game has two modes: PVP and PVM  |"<<endl;
    cout<<" ---------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Please press any key to continue...";
    getchar();
    while(true){
        system("CLS");
        cout<<"Please choose the game mode:"<<endl;
        cout<<"PVP  :  1"<<endl;
        cout<<"PVM  :  2"<<endl;
        cout<<"Quit :  q"<<endl;
        cout<<endl;
        cout<<"Your choice : ";
        string mode;
        cin>>mode;
        if(mode=="1"){
            PVP::PVP_Game();
        }
        else if(mode=="2"){
            PVM::PVM_Game();
        }
        else if(mode=="q"){
            break;
        }
    }
    return 0;
}
