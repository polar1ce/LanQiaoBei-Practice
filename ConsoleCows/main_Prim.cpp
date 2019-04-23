#include <iostream>
#include <algorithm>
#define INF 9999

using namespace std;

int *cow;
int *consoled;
int *pathNum;
int **path;
int **shortpath;


void addPath(int n) {
    int minPathS = 0, minPathE = 0;
    for(int i = 1; i <= n; i++) {
        if(consoled[i] == 1) {
            for(int j = 1; j <= n; j++) {
                if(consoled[j] == 0 && shortpath[i][j] == 0 && path[i][j] * 2 + cow[i] < path[minPathS][minPathE] * 2 + cow[minPathS]) {
                    minPathS = i;
                    minPathE = j;
                }
            }
        }
    }
    if(minPathS != 0 && minPathE != 0) {
        shortpath[minPathS][minPathE] = 1;
        consoled[minPathE] = 1;
        pathNum[minPathS]++;
        pathNum[minPathE]++;
    }
}

int main()
{
    int n, p;
    cin >> n >> p;

    cow = new int[n+1];
    consoled = new int[n+1];
    pathNum = new int[n+1];
    path = new int*[n+1];
    shortpath = new int*[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> cow[i];
        consoled[i] = 0;
        pathNum[i] = 0;
        path[i] = new int[n+1];
        shortpath[i] = new int[n+1];
        for(int j = 1; j <= n; j++) {
            path[i][j] = INF;
            shortpath[i][j] = 0;
        }
    }
    cow[0] = INF;
    path[0][0] = INF;

    int s, e, l;
    while(p--) {
        cin >> s >> e >> l;
        path[s][e] = path[e][s] = l;
    }

    int root = distance(cow, min_element(cow, cow+n));
    consoled[root] = 1;

    int flag = n-1;
    while(flag--) {
        addPath(n);
    }

    int res = cow[root];
    for(int i = 1; i <= n; i++){
        res += cow[i] * pathNum[i];
        for(int j = 1; j <= n; j++) {
            if(shortpath[i][j] == 1) {
                res += path[i][j] * 2;
            }
        }
    }
    cout << res << endl;
    return 0;
}
