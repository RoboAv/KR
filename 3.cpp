#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

string dec(int n){
    string alph = "01";
    string result = "";
    for (int i = 0; n > 0; i ++){
        result += alph[n % 2];
        n /= 2;
    }
    return result;
}

int sum(string str){
    int result = 0;
    for (int i = 0; i < str.size(); i ++){
        if (str[i] == '1'){
            result ++;
        }
    }
    return result;
}

bool sravPol(int a, int b){
    return a < b;
}

bool sravOtr(int a, int b){
    return a > b;
}

int main()
{
    string str;
    ifstream finn ("input.txt");
    getline(finn, str);
    char ch = str[0], resCh = str[0], curCh = str[0];
    int result = 0, curMax = 0;
    for (int i = 0; i < str.size(); i ++){
        ch = str[i];
        if (ch == curCh){
            curMax ++;
        }
        if (curMax > result){
            result = curMax;
            resCh = curCh;
        }
        if (ch != curCh){
            curMax = 1;
            curCh = ch;
        }
    }
    cout << resCh << " " << result;
    return 0;
}
