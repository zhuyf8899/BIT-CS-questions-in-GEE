//
//  main.cpp
//  2009Exam
//
//  Created by zhuyifan on 16/3/9.
//  Copyright © 2016年 org.yifans. All rights reserved.
//
/*
 1 请输入字符串，最多输入4个字符串，要求后输入的字符串排在前面，例如
 输入：EricZ
 输出：1=EricZ
 输入：David
 输出：1=David 2=EricZ
 输入：Peter
 输出：1=Peter 2=David 3=EricZ
 输入：Alan
 输出：1=Alan 2=Peter 3=David 4=EricZ
 输入：Jane
 输出：1=Jane 2=Alan 3=Peter 4=David
 2.把上述最后结果保存到Name.txt中
 */
/*
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    string array[4] = {"","","",""};
    ofstream fout("Name.txt",ios::out);
    while(1){
        string in;
        cin>>in;
        for (int i = 3 ; i > 0; --i) {
            array[i] = array[i-1];
        }
        array[0] = in;
        for (int i =0; i<4; ++i) {
            if (array[i] != "") {
                cout<<i+1<<"="<<array[i]<<" ";
                fout<<i+1<<"="<<array[i]<<" ";
            }
            
        }
        cout<<endl;
        fout<<endl;
    }
    return 0;
}
 //*/
/*
 3. 先输入一组数，然后输入其分组，按照分组统计出现次数并输出
 例如，输入数据3,2,3,8,8,2,3
 输入对应分组  1,2,3,2,1,3,1
 输出：
 1={2=0，3=2，8=1}
 2={2=1，3=0，8=1}
 3={2=1，3=1，8=0}
 即每组中各数据出现的次数
//*/
/*
#include <iostream>
#include <string>

using namespace std;

int main(){
    int a[3][3];
    for (int p = 0; p<3; ++p) {
        for (int q =0 ; q<3; ++q) {
            a[p][q] = 0;
        }
    }
    char data[1000];
    char group[1000];
    int i = 0;
    char temp = '\0';
    while(temp != '\n'){
        temp = getchar();
        data[i] = temp;
        ++i;
    }
    //temp = getchar();
    temp = '\0';
    i = 0;
    while(temp != '\n') {
        temp = getchar();
        group[i] = temp;
        ++i;
    }
    
    for(int j=0;j<1000;++j){
        if (data[j] == '\0' || group[j] == '\0') {
            break;
        }
        if (data[j] != ',' && group[j] != ',') {
            if (data[j] == '2') {
                a[group[j]-'0'-1][0] +=1;
            }if (data[j] == '3') {
                a[group[j]-'0'-1][1] +=1;
            }if (data[j] == '8') {
                a[group[j]-'0'-1][2] +=1;
            }
        }
    }
    
    for(int j = 0;j<3;++j){
        cout<<j+1<<"={2="<<a[j][0]<<",3="<<a[j][1]<<",8="<<a[j][2]<<"}"<<endl;;
    }
    
}
 //*/
//4. 输入一个英文句子，把句子中的单词按出现次数按从多到少把单词和次数在屏幕上输出来，要求能识别英文句号和逗号，即是说暂不要求识别其他符号
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

class ValueReverse{
public:
    bool operator()(pair<string, int>l,pair<string, int>r){
        return l < r;
    }
};

int checkSpilt(string x){
    unsigned int space;
    unsigned int commant;
    unsigned int stence;
    space = x.find(' ');
    commant = x.find(',');
    stence = x.find('.');
    
    if (space < commant) {
        if (space < stence) {
            return space;
        }else{
            return stence;
        }
    }else{
        if (commant < stence) {
            return commant;
        }else{
            return stence;
        }
    }
}

bool replacePlusOne(map<string,int>&target,string x){
    for (map<string,int>::iterator i = target.begin(); i != target.end(); ++i ) {
        if (i->first == x) {
            i->second += 1;
            return true;
        }
    }
    return false;
}

void print(map<string,int>x){
    vector<pair<string,int>>y(x.begin(),x.end());
    sort(y.begin(), y.end(), ValueReverse());
    for (vector<pair<string,int>>::iterator i = y.begin();i!=y.end();++i){
        //cout<<i->first.first<<":"<<i->first.second<<endl;
        //cout<<&i<<endl;;
        cout<<i->first<<":"<<i->second<<endl;
    }
}

int main(){
    string input;
    getline(cin,input);
    transform(input.begin(), input.end(), input.begin(), ::tolower);
    map<string,int>dic;
    while (1){
        if (input.size() == 0) {
            break;
        }
        int pos = checkSpilt(input);
        if(pos == string::npos){
            if (!replacePlusOne(dic, input)) {
                dic.insert(make_pair(input, 1));
            }
            input.erase();
        }else if (pos == 0) {
            input.erase(0,1);
        }else{
            string temp = input.substr(0,pos);
            if (!replacePlusOne(dic, temp)) {
                dic.insert(make_pair(temp, 1));
            }
            input.erase(0,pos+1);
        }

    }
    print(dic);
    
    return 0;
}

