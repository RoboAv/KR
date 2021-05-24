#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
    int a, b;
    cin >> a >> b;
    bool flag = 0;
    string str;
    vector<int> result;
    if (a < 0 && b < 0){
        flag = 1;
        a = abs(a);
        b = abs(b);
    }
    if (a <= b){
        for (int i = a; i <= b; i ++){
            str = dec(i);
            if (str[0] == '0' && sum(str) == 5 && i % 10 != 0){
                result.push_back(i);
            }
        }
    } else {
        for (int i = b; i <= a; i ++){
            str = dec(i);
            if (str[0] == '0' && sum(str) == 5 && i % 10 != 0){
                result.push_back(i);
            }
        }
    }
    if (result.size() == 0){
        cout << "0 0";
    } else if (!flag){
        cout << result.size() << " " << result[distance(result.begin(), max_element(result.begin(), result.end(), sravPol))];
    } else {
        cout << result.size() << " " << -result[distance(result.begin(), max_element(result.begin(), result.end(), sravOtr))];
    }
    return 0;
}
