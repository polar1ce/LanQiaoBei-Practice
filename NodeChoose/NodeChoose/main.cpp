#include <iostream>
#include <algorithm>
#define MAX 200002

using namespace std;

class Node {//结点
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
		int dp[2];//该结点的值，0为未选取时的值，1为选取时的值
		int head;//该结点的边
};

class Edge {//边
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
		int to;//该边指向的结点
		int next;//该边起始结点的下一条边
};

Node *node = new Node[MAX];
Edge *edge = new Edge[MAX];
int num = 0;//边的总数目

void add(int f, int t) {
	edge[num].setTo(t);//设置该边指向的结点
	edge[num].setNext(node[f].getHead());//将该边的下一条边设置为其起始结点所指向的边
	node[f].setHead(num);//将该边设置为其起始结点所指向的边
	num++;
}

int DFS(int now, int parent) {//now为当前搜索到的结点，parent为now的父结点
	for(int i = node[now].getHead(); i != -1; i = edge[i].getNext()) {//遍历当前结点的各条边
        if(edge[i].getTo()== parent) continue;//不重复计算now的父结点
        int next = edge[i].getTo();//获得当前边指向的结点

        DFS(next, now);//深搜，先找到并计算孩子节点的值

        node[now].setDp(node[now].getDp(0) + max(node[next].getDp(0), node[next].getDp(1)), 0);//当前结点未选中的情况下，对于每个子结点选择其选中或未选中情况中值较大的情况，累积统计
        node[now].setDp(node[now].getDp(1) + node[next].getDp(0), 1);//当前结点选中的情况下，对于每个子结点都选择未选中的情况，累积统计
	}
	return 0;
}

int main(int argc, char *argv[]) {
	int n = 0;//结点数
	cin >> n;

	int v;
    for(int i = 1; i <= n; i++) {
    	cin >> v;
        node[i].setDp(v,1);//输入各结点的值
    }

    int from, to;
    for(int i = 0; i < n-1; i++) {
    	cin >> from >> to;
    	add(from, to);//输入各条边
    	add(to, from);//双向边
    }

    DFS(1,0);//深度搜索构造的树，从结点0开始，令结点0的父结点为0

    cout << max(node[1].getDp(0), node[1].getDp(1)) << endl;//最后选取根节点选中或未选中情况中值较大的情况

    delete[] node;
    delete[] edge;
	return 0;
}
