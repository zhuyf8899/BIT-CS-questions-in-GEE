//
//  main.cpp
//  2011BITExam
//
//  Created by zhuyifan on 16/3/7.
//  Copyright © 2016年 org.yifans. All rights reserved.
//2011年上机及答案1
//1.输入一组单词（区分大小写），统计首字母相同的单词个数，相同的单词不累加，输出格式“字母，以该字母为首的单词个数。

//*
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<string>in;
    vector<string>repeatCheck;
    map<char,int>dictionary;
    string tempIn;
    while(cin>>tempIn && tempIn[0] != 27) {
        bool flag = false;
        for(int i = 0;i<repeatCheck.size();i++){
            if (repeatCheck[i] == tempIn) {
                flag = true;
            }
        }
        if (flag == false) {
            repeatCheck.push_back(tempIn);
            //int position = dictionary.find(dictionary.begin(),dictionary.end(),tempIn[0]);
            map<char,int>::iterator pos = dictionary.find(tempIn[0]);
            if (pos != dictionary.end()) {
                dictionary[tempIn[0]] = (pos->second) + 1;
                
            }else{
                dictionary.insert(make_pair(tempIn[0], 1));
            }
        }
    }
    
    for (map<char,int>::iterator x = dictionary.begin(); x!=dictionary.end(); ++x) {
        cout<<""<<x->first<<","<<x->second<<endl;
    }
    return 0;
}
//*/
//2.输入一组单词（区分大小写），输出这些单词的字典排序
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    string in;
    vector<string>dic;
    while(cin>>in && in != "EXIT"){
        dic.push_back(in);
        in.erase();
    }
    sort(dic.begin(),dic.end());
    for (vector<string>::iterator x = dic.begin(); x!=dic.end(); ++x) {
        cout<<*x<<",";
    }
}

//*/
//3.给一个字符串（aaaa（bbb（cccc，dddd），eeee（ffff）））
//该字符串表明的是各个人的层次关系。
//如aaaa是bbb和eeee的领导，bbb是cccc和dddd的领导
//等等 现要求你输入一个名称如ffff要求你输出其的领导关系
// 那么就应输出aaaa>eeee>ffff
//不会




