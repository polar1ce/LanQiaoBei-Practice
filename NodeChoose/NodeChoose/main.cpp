#include <iostream>
#include <algorithm>
#define MAX 200002

using namespace std;

class Node {//���
	public:
		Node() {
			dp[0] = dp[1] = 0;
			head = -1;
		}
		int getDp(int i) {
			return dp[i];
		}
		int getHead() {
			return head;
		}
		void setDp(int v, int i) {
			dp[i] = v;
		}
		void setHead(int v) {
			head = v;
		}
	private:
		int dp[2];//�ý���ֵ��0Ϊδѡȡʱ��ֵ��1Ϊѡȡʱ��ֵ
		int head;//�ý��ı�
};

class Edge {//��
	public:
		Edge() {
			to = -1;
			next = -1;
		}
		int getTo() {
			return to;
		}
		int getNext() {
			return next;
		}
		void setTo(int v) {
			to = v;
		}
		void setNext(int v) {
			next = v;
		}
	private:
		int to;//�ñ�ָ��Ľ��
		int next;//�ñ���ʼ������һ����
};

Node *node = new Node[MAX];
Edge *edge = new Edge[MAX];
int num = 0;//�ߵ�����Ŀ

void add(int f, int t) {
	edge[num].setTo(t);//���øñ�ָ��Ľ��
	edge[num].setNext(node[f].getHead());//���ñߵ���һ��������Ϊ����ʼ�����ָ��ı�
	node[f].setHead(num);//���ñ�����Ϊ����ʼ�����ָ��ı�
	num++;
}

int DFS(int now, int parent) {//nowΪ��ǰ�������Ľ�㣬parentΪnow�ĸ����
	for(int i = node[now].getHead(); i != -1; i = edge[i].getNext()) {//������ǰ���ĸ�����
        if(edge[i].getTo()== parent) continue;//���ظ�����now�ĸ����
        int next = edge[i].getTo();//��õ�ǰ��ָ��Ľ��

        DFS(next, now);//���ѣ����ҵ������㺢�ӽڵ��ֵ

        node[now].setDp(node[now].getDp(0) + max(node[next].getDp(0), node[next].getDp(1)), 0);//��ǰ���δѡ�е�����£�����ÿ���ӽ��ѡ����ѡ�л�δѡ�������ֵ�ϴ��������ۻ�ͳ��
        node[now].setDp(node[now].getDp(1) + node[next].getDp(0), 1);//��ǰ���ѡ�е�����£�����ÿ���ӽ�㶼ѡ��δѡ�е�������ۻ�ͳ��
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int n = 0;//�����
	cin >> n;

	int v;
    for(int i = 1; i <= n; i++) {
    	cin >> v;
        node[i].setDp(v,1);//���������ֵ
    }

    int from, to;
    for(int i = 0; i < n-1; i++) {
    	cin >> from >> to;
    	add(from, to);//���������
    	add(to, from);//˫���
    }

    DFS(1,0);//�����������������ӽ��0��ʼ������0�ĸ����Ϊ0

    cout << max(node[1].getDp(0), node[1].getDp(1)) << endl;//���ѡȡ���ڵ�ѡ�л�δѡ�������ֵ�ϴ�����

    delete[] node;
    delete[] edge;
	return 0;
}
