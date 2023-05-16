#include<bits/stdc++.h>

using namespace std;

vector<string> vec;

int oper(char c){
    if(c == '+' || c == '-'|| c == '/'|| c == '*'|| c == '=')
        return 1;
    return 0;
}

void three_add_code(string str){
    
    int l = str.length();
    int c = count(str.begin(), str.end(), ' ');
    remove(str.begin(), str.end(), ' ');
    str.resize(l-c);
    
    string s1 = "", s2 = "";
    
    int f1 = 1, f2 = 0;
    
    c = 0;
    string op;
    
    for(int i = str.length() - 1; i>=0; i--){
        if(f1 == 1 && oper(str[i]) == 1){
            f1 = 0;
            f2 = 0;
            op = str[i];
            if(i!=0 && oper(str[i-1])){
                break;
            }
            else{
                f2 = 1;
            }
        }
        else if(f1 == 1){
            s1 = str[i] + s1;
        }
        else if(f2 == 1){
            if(oper(str[i]) == 1)
                break;
            s2 = str[i] + s2;
        }
    }
    if(f1 == 1){
        return;
    }
    vec.push_back(s2+op+s1);
    int t = s2.size()+1+s1.size();
    str = str.substr(0, str.length() - t);
    str = str + "t" + to_string(vec.size());
    three_add_code(str);
}
int main(){
    string s;
    cout<<"Enter the exp:"<<endl;
    getline(cin, s);
    three_add_code(s);
    cout<<"Intermediate Code:"<<endl;
    for(int i = 0; i<vec.size()-1; i++){
        cout<<"t"<<i+1<<"="<<vec[i]<<endl;
    }
    cout<<vec[vec.size()-1];
}
