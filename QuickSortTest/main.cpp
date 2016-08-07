/*
 第二题
 要求：
 学生有（学号，姓名，性别，年龄），初始化三个学生的信息
 （10,wes,f,23）(20,ert,f,45)(30,str,t,89),然后对学生信息进行插入和删除处理
 例如
 I12,rt,f,67表示插入12,rt,f,67
 D10 表示删除学号为10的学生的信息
 每次操作完成以后输出所有学生的信息按学号从大到小排序
 输入：
 I12,rt,f,67
 输出
 （10,wes,f,23）,(12,rt,f,67),(20,ert,f,45),(30,str,t,89)
 输入：
 D10
 输出
 (12,rt,f,67),(20,ert,f,45),(30,str,t,89)
*/
///*
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
//#include <cmath>
#include <sstream>
using namespace std;

struct student{
    int id;
    string name;
    char sex;
    int age;
    
    bool operator< (const student &a){
        return (id < a.id);
    }
    
    bool operator> (const student &a){
        return (id > a.id);
    }
    
    bool operator==(const student &a){
        return (id==a.id);
    }
    
};
vector<student>stu;

void print(vector<student>example){
    vector<student>::iterator it = example.begin();
    vector<student>::iterator ite = example.end();
    //sort(it, ite);
    vector<student>::iterator iti = example.begin();
    for(;iti != example.end();++iti){
        cout<<"("<<iti->id<<","<<iti->name<<","<<iti->sex<<","<<iti->age<<"),";
    }
    //cout<<"("<<iti->id<<","<<iti->name<<","<<iti->sex<<","<<iti->age<<")";
}


void insert(int i, string n, char s, int a){
    student temp;
    temp.id = i;
    temp.name = n;
    temp.sex = s;
    temp.age = a;
    stu.push_back(temp);
    //print(stu);
    //return 1;
}

void del(int i){
    for(int j = 0;j < stu.size();++j){
        cout<<stu[j].id<<" "<<i<<endl;
        if(stu[j].id == i)
            stu.erase(stu.begin()+j);
    }
    //print(stu);
}

int main(int argc, const char * argv[]) {
    insert(10, "wef", 'f', 23);
    insert(20, "ert", 'f', 45);
    insert(30, "str", 't', 39);
    while(1){
        string command;
        cin>>command;
        if(command[0] == 'E' || command[0] == 'e')
            exit(8);
        if(command[0] == 'I'){
            int i;
            string n;
            char s;
            int a;
            int pos = command.find(',');
            stringstream sst,sst2;
            sst<<command.substr(1,pos);
            sst>>i;
            command.erase(0, pos+1);
            
            pos = command.find(',');
            n = command.substr(0,pos);
            command.erase(0,pos+1);
            
            s = command[0];
            command.erase(0,2);
            
            sst2<<command;
            sst2>>a;
            
            insert(i, n, s, a);
            print(stu);
            
        }
        if (command[0] == 'D') {
            command.erase(0,1);
            int i;
            stringstream sst;
            sst<<command;
            sst>>i;
            del(i);
            print(stu);
        }
    }
    
    return 0;
}//*/

//第三题
/*
 利用后序和中序确定前序遍历的结果
 输入（按后序，中序）
 CHBEDA
 CBHADE
 输出
 ABCHDE
 */
/*
#include <iostream>
#include <string>
using namespace std;

struct node{
    char data;
    node *lchild = NULL;
    node *rchild = NULL;
};

node* Contruction(string houxu,string zhongxu,node *root){
    if(houxu.empty()){
        return NULL;
    }
    
    root = (node*)malloc(sizeof(node));
    root->data = *(houxu.end()-1);
    string zl,zr,hl,hr;
    unsigned long int pos = zhongxu.find(*(houxu.end()-1));
    zl = zhongxu.substr(0,pos);
    zr = zhongxu.substr(pos+1);
    hl = houxu.substr(0,pos);
    hr = houxu.substr(pos);
    hr.erase(hr.end()-1);
    root->lchild = Contruction(hl, zl, root->lchild);
    root->rchild = Contruction(hr, zr, root->rchild);
    return root;
}

void preorder(node *root){
    if (root == NULL) {
        return;
    }
    cout<<root->data;
    preorder(root->lchild);
    preorder(root->rchild);
}

int main(){
    string houxu;
    string zhongxu;
    node *tree = NULL;
    //cin>>houxu>>zhongxu;
    houxu = "DGFEBFCA";
    zhongxu = "DBFGEACF";
    node * target = Contruction(houxu, zhongxu, tree);
    preorder(target);
    //int posi = zhongxu.find('A');
    //cout<<houxu.size()<<"--"<<houxu.size()-1<<endl;
    //cout<<posi<<"--"<<houxu.substr(0,posi)<<"---"<<houxu.substr(posi)<<endl;
    
    
    return 0;
}
 */

