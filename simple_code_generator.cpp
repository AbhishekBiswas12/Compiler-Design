#include<bits/stdc++.h>

using namespace std;

void simp_code_gen(pair<string, vector<string>> op_code){
    int reg_count = 0;
    
    pair<string, vector<string>> p = op_code;
    
    cout<<"MOV "<<"R1 "<<p.second[p.second.size() - 1]<<endl;
    
    reg_count++;
    
    for(int i = p.second.size()-2; i>=0; i-=2){
        string op;
        if(p.second[i] == "*"){
            op = "MUL";
        }
        if(p.second[i] == "+"){
            op = "ADD";
        }
        if(p.second[i] == "-"){
            op = "SUB";
        }
        
        reg_count++;
        cout<<"MOV R"<<reg_count<<" "<<p.second[i-1]<<endl;
        reg_count++;
        cout<<op<<" R"<<reg_count<<" R"<<reg_count-1<<" R"<<reg_count-2<<endl;
    }
    cout<<"MOV "<<p.first<<" R"<<reg_count;
}

int main(){
    simp_code_gen({"id1", {"id2", "-", "id3", "*", "id4"}});
}
