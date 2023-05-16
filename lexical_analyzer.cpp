#include<iostream>
#include<string.h>
#include<conio.h>
#include<ctype.h>

using namespace std;

int keyword(string buf){
    string key[18] = {"char", "int", "main","float", "double", "for", "while", "do", "if", "else", "enum", "switch", "case", "void", "goto", "static", "struct", "class"};

    for(int i = 0; i<17; i++){
        if(buf == key[i]){
            return 1;
        }
    }
    return 0;
}

int op(char c){
    string oper = "+-/*=%";
    for(int i = 0; i<oper.size(); i++){
        if(c == oper[i]){
            return 1;
        }
    }
    return 0;
}

int lex(const char* filename){
    string buf;
    int j = 0;
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        cout<<"Empty file";
        return 0;
    }
    char c;
    while((c = fgetc(f)) != EOF){
        
        
        if(feof(f)){
            break;
        }
        
        
        if(op(c) == 1){
            cout<<c<<" -> operator"<<endl;
            continue;
        }
        
        if(isalnum(c)){
            buf.push_back(c);
            j+=1;
        }
        else if((c == ' ' || c == '\n')){
            if(keyword(buf) == 1){
                cout<<buf<<" -> keyword"<<endl;
            }
            else if(buf == ""){
                continue;
            }
            else{
                cout<<buf<<" -> identifier"<<endl;
            }
            buf = "";
            j = 0;
        }
    }
    fclose(f);
    return 1;
}

int main(){
    string s;
    cout<<"Enter the filename = ";
    cin>>s;
    
    
    return lex(s.c_str());
}
