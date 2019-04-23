#include <iostream>
#include <algorithm>

using namespace std;

struct Edge {
    int s;
    int e;
    int l;
};

int n, p;
int *node;
Edge *edge;
int *path;

int cmp(Edge e1, Edge e2) {
    return e1.l < e2.l;
}

int find(int x) {
    return path[x] == x ? x : path[x] = find(path[x]);
}

int Kruscal() {
    int res = 0;
    sort(edge, edge+p, cmp);
    for(int i = 0; i < p; i++) {
        int ss = find(edge[i].s);
        int ee = find(edge[i].e);
        if(ss != ee) {
            path[ss] = ee;
            res += edge[i].l;
        }
    }
    return res;
}

int main()
{
    cin >> n >> p;

    node = new int[n+1];
    edge = new Edge[p];
    path = new int[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> node[i];
        path[i] = i;
    }
    for(int i = 0; i < p; i++) {
        cin >> edge[i].s >> edge[i].e >> edge[i].l;
        edge[i].l = node[edge[i].s] + node[edge[i].e] + edge[i].l * 2;
    }

    int root = distance(node, min_element(node+1, node+n+1));

    cout << node[root] + Kruscal() << endl;
    return 0;
}
