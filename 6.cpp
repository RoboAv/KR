#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdlib.h>
#include <stack>

using namespace std;

stack <string> split (string str, char simb){
    stack <string> result;
    string help = "";
    for (int i = 0; i < str.size(); i ++){
        if (str[i] != simb){
            help += str[i];
        } else {
            result.push(help);
            help = "";
        }
    }
    result.push(help);
    help = "";
    return result;
}

int main()
{
    ifstream finn ("input.txt");
    ofstream fout ("output.txt");
    string str, alph = "+-*/";
    stack <int> result;
    int help;
    while (finn >> str){
        if (result.size() < 2 && alph.find(str) != -1){
            fout << "ERROR";
            return 0;
        }
        if (str == "+"){
            help = result.top();
            result.pop();
            help += result.top();
            result.pop();
            result.push(help);
        } else if (str == "-"){
            int hell = result.top();
            result.pop();
            help = result.top();
            result.pop();
            result.push(help - hell);
        } else if (str == "*"){
            help = result.top();
            result.pop();
            help *= result.top();
            result.pop();
            result.push(help);
        } else if (str == "/"){
            int hell = result.top();
            result.pop();
            help = result.top();
            result.pop();
            if (hell > 0 && help < 0){
                result.push(help / hell - 1);
            } else {
                result.push(help / hell);
            }
        } else {
            result.push(atoi(str.c_str()));
        }
    }
    int n = result.size();
    if (n > 1){
        fout << "ERROR";
        return 0;
    }
    for (int i = 0; i < n; i ++){
        fout << result.top() << " ";
        result.pop();
    }
    finn.close();
    fout.close();
    return 0;
}
