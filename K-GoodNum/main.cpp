#include<iostream>

using namespace std;

int main()
{
	int k;	//������
	int l;  //λ��
	cin >> k;
	cin >> l;
	/*�ӵ͵�����λ����K������Ŀ����λΪa����λΪb
	�����±�Ϊ��λ��ȡֵ������ֵΪaλ��bλ����K������������ϵĸ���*/
	long long *ka = new long long[k];   //aλ
	long long *kb = new long long[k];   //bλ
	long long res = 0;  //������
	//������0��ͷ������0��βʱ������a��b��ͬ
	ka[0] = 0;
	kb[0] = 0;
	for(int i = 1; i < k; i++)
	{
	    //a��b��ͬ�����
		ka[i] = 1;
		kb[i] = 1;
	}
	for(int i = 2; i <= l; i++) //��lλ��ѭ��l-1��
	{
		for(int j = 0; j < k; j++)
		{
			for(int m = 0; m < k; m++)
			{
				if(m < j-1 || m > j+1)  //����������
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
