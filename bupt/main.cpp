//
//  main.cpp
//  bupt
//
//  Created by zhuyifan on 16/3/18.
//  Copyright © 2016年 org.yifans. All rights reserved.
//
/*
#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    int num;
    while(cin>>num){
        map<int,int>dic;
        int input[100];
        for(int i=0;i<num;++i){
            cin>>input[i];
        }
        
        
        //int j = 0;
        
        
        //map<int,int>::iterator x = dic.begin();
        for(int j = 0;j<num;++j){
            //while(true){
            for(map<int,int>::iterator x = dic.begin();;++x){
                if(x->first == input[j]){
                    x->second += 1;
                    break;
                }else if (x == dic.end()){
                    dic.insert(make_pair(input[j], 1));
                    break;
                }else{
                    //++x;
                }
            }
            
        }
        
        for(map<int,int>::iterator x = dic.begin();x!=dic.end();++x){
            if(x->second == 1){
                cout<<x->first<<endl;
            }
        }
        
    }
    return 0;
}
 //*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    string a = "111110111110111110111110111110";
    //cout<<a.size();
    for(int i = 0;i<a.size();++i){
        if(a[i] == '1')
            cout<<a[i];
        else
            ;
    }
    //system("pause");
}

