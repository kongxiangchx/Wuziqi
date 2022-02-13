#include "Tool.h"

Tool::Tool(){

}

Tool::~Tool(){

}

int Tool::Num_row(char c){
    if(sizeof(c)==0){
        return -1;
    }
    if(c>='A'&&c<='Z'){
        return c-'A'+1;
    }
    else if(c>='a'&&c<='z'){
        return c-'a'+1;
    }
    else{
        return -1;
    }
}

int Tool::Num_col(string s){
    int len=s.length();
    if(len==0){
        return -1;
    }
    int num=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            num=num*10+(s[i]-'0');
        }
        else{
            return -1;
        }
    }
    return (num>=1&&num<=15)?num:-1;
}
