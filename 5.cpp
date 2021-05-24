#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stdlib.h>

using namespace std;

int prior (char simb){
    switch (simb){
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        default:
            return -1;
    }

}

string remov (string str){
    while (str[0] == '(' && str[str.size() - 1] == ')'){
        int brack = 1;
        for (int i = 1; i < str.size () - 1; i ++){
            char simb = str[i];
            if (simb == '('){
                brack ++;
            } else if (simb == ')'){
                brack --;
                if (brack == 0){
                    return str;
                }
            }
        }
        str = str.substr(1, str.size() - 2);
    }
    return str;
}

int solvim (string str){
    str = remov(str);
    int brack = 0;
    int minPriorOper = -1;
    for (int i = 0; i < str.size(); i ++){
        char simb = str[i];
        int p = prior(simb);
        if (p != -1 && brack == 0 && (minPriorOper == -1 || p < prior(str[minPriorOper]))){
            minPriorOper = i;
        } else if (simb == '('){
            brack ++;
        } else if (simb == ')'){
            brack --;
        }
    }
    if (minPriorOper != -1){
        int a = solvim(str.substr(0, minPriorOper));
        int b = solvim(str.substr(minPriorOper + 1, str.size()));
        switch (str[minPriorOper]){
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }
    }
    return atoi(str.c_str());
}

int main()
{
    string str;
    getline(cin, str);
    cout << solvim(str);
    return 0;
}
