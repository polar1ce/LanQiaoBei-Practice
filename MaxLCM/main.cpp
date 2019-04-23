#include <iostream>

using namespace std;

int main() {
    long long n, lcm;
    cin >> n;
    if(n <= 3) lcm = n;//小于3的情况
    else if(n%2 == 0) {//n与n-2公因子为2
        if(n%3 != 0) lcm = n * (n-1) * (n-3);//n与n-3没有公因子
        else lcm = (n-1) * (n-2)* (n-3);//n与n-3公因子为3
    }
    else lcm = n * (n-1) * (n-2);//n与n-2没有除1以外的公因子，n-1与其余两数更不可能有
    cout << lcm << endl;
    return 0;
}
