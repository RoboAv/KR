#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

vector<int> arr;
vector<string> result;

void razl(int a, int b, int i){
    if (a < 0){
        return;
    }
    if (a == 0){
        string str = "";
        for (int j = 0; j < i; j ++){
            int help = arr[j];
            switch (help){
                case 0:
                    str += "0 ";
                    break;
                case 1:
                    str += "1 ";
                    break;
                case 2:
                    str += "2 ";
                    break;
                case 3:
                    str += "3 ";
                    break;
                case 4:
                    str += "4 ";
                    break;
                case 5:
                    str += "5 ";
                    break;
                case 6:
                    str += "6 ";
                    break;
                case 7:
                    str += "7 ";
                    break;
                case 8:
                    str += "8 ";
                    break;
                case 9:
                    str += "9 ";
                    break;
            }
        }
        result.push_back(str);
        str = "";
    } else {
        if (a - b >= 0){
            arr[i] = b;
            razl(a - b, b, i + 1);
        }
        if (b - 1 > 0){
            razl(a, b - 1, i);
        }
    }
}

int main()
{
    int num;
    cin >> num;
    for (int i = 0; i <= num; i ++){
        arr.push_back(0);
    }
    razl(num, num, 0);
    for (int i = result.size() - 1; i >= 0; i --){
        cout << result[i] << endl;
    }
    return 0;
}
