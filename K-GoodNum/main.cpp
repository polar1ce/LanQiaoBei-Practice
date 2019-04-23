#include<iostream>

using namespace std;

int main()
{
	int k;	//进制数
	int l;  //位数
	cin >> k;
	cin >> l;
	/*从低到高逐位计算K好数数目，高位为a，低位为b
	数组下标为该位的取值，数组值为a位与b位满足K好数条件的组合的个数*/
	long long *ka = new long long[k];   //a位
	long long *kb = new long long[k];   //b位
	long long res = 0;  //输出结果
	//不能以0开头，且以0结尾时不存在a、b相同
	ka[0] = 0;
	kb[0] = 0;
	for(int i = 1; i < k; i++)
	{
	    //a、b相同的情况
		ka[i] = 1;
		kb[i] = 1;
	}
	for(int i = 2; i <= l; i++) //有l位，循环l-1次
	{
		for(int j = 0; j < k; j++)
		{
			for(int m = 0; m < k; m++)
			{
				if(m < j-1 || m > j+1)  //不相邻条件
					kb[j] += ka[m];
			}
		}
		for(int j = 0; j < k; j++)
		{
		    kb[j] %= 1000000007;
			ka[j] = kb[j];
		}
		for(int i = 0; i < k; i++) {
            cout << ka[i] << " ";
		}
		cout << endl;
	}
	while(k--)
	{
		res += ka[k];
		res %= 1000000007;
	}
	cout << res << endl;
	delete[] ka;
	delete[] kb;
	return 0;
}
