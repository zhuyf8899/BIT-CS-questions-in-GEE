//
//  main.cpp
//  2010Exam
//
//  Created by zhuyifan on 16/3/9.
//  Copyright © 2016年 org.yifans. All rights reserved.
//2010年：
//第一题：输入一串整数，输入命令排序！
//输入a t   在这串整数后面添加整数t，
//输入c\m\n 有n替换m，
//输入d t 删除t，
//输入 s  排序，
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void print(vector<int>n){
    for (vector<int>::iterator x = n.begin(); x!= n.end(); ++x) {
        cout<<"|"<<*x;
    }
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    vector<int>numbers;
    string command;
    while (1) {
        getline(cin,command);
        switch (command[0]) {
            case 'a':{
                string test = command.substr(2);
                //sst<<(command.substr(0,2));
                stringstream sst;
                int adder;
                sst<<test;
                sst>>adder;
                numbers.push_back(adder);
                print(numbers);
                break;
            }
            case 'c':
            {
                stringstream sst1,sst2;
                int source,replacer;
                command.erase(0,2);
                int pos = command.find('\\');
                sst1<<command.substr(0,pos);
                sst1>>source;
                command.erase(0,pos+1);
                sst2<<command;
                sst2>>replacer;
                for (vector<int>::iterator x = numbers.begin(); x!=numbers.end(); ++x) {
                    if (*x == source) {
                        *x = replacer;
                    }
                }
                print(numbers);
                break;
            }
            case 'd':
            {
                stringstream sst3;
                sst3<<command.substr(2);
                int deler;
                sst3>>deler;
                //for (vector<int>::iterator x = numbers.begin(); x!=numbers.end(); ++x) {
                //    if (*x == deler) {
                //        numbers.erase(x);
                //    }
                //}
                for (int i = 0;i<numbers.size();++i){
                    if(numbers[i] == deler)
                        numbers.erase(numbers.begin()+i);
                }
                print(numbers);
                break;
            }
            case 's':
            {
                sort(numbers.begin(),numbers.end());
                print(numbers);
            }
            case 'e':
                exit(2);
            default:
                break;
        }
    }
    return 0;
}
 //*/

//2.输入表达式，输出值，思路先将中缀表达式转换成后缀表达式，然后扫描后缀表达式


