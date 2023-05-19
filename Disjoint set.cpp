#include <iostream>
using namespace std;
int f[10002];
int maxi=-1;

int get_root(int x) {
    int root = x;
    while (f[root] > 0) {
        root = f[root];
    }
    int aux;
    while (x != root) {
        aux = f[x];
        f[x] = root;
        x = aux;
    }
    return root;
}

void join(int x, int y) {
    int root_x = get_root(x);
    int root_y = get_root(y);
    if (root_x == root_y) { return; }
    
    if (f[root_x] < f[root_y]) {
        f[root_x] += f[root_y];
        f[root_y] = root_x;
        if (f[root_x] < maxi) { maxi = f[root_x]; }
    }
    else{
        f[root_y] += f[root_x];
        f[root_x] = root_y;
        if (f[root_y] < maxi) { maxi = f[root_y]; }
    }
    
}



int main()
{
    int n,m,q,a,b;
    cin >> n>> m;
    for (int i = 1;i <= n;i++) {
        f[i] = -1;
    }
    for (int i = 1;i <= m;i++) {
        cin >> q;
        switch (q){
        case 1:
            cin >> a >> b;
            join(a, b);
        break;
        case 2:
            cin >> a >> b;
            if (get_root(a) == get_root(b)) {
                cout << "DA\n";
            }
            else {
                cout << "NU\n";
            }
        break;
        case 3:
            cout << maxi * (-1) << "\n";
        break;
        }
    
    }

}

