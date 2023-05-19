#include <fstream>
#include <vector>
using namespace std;
ifstream cin("a.in");
ofstream cout("a.out");
int mat[102][102];
int f[102], d[102];
int n,s,p,a,b,c;
struct muchie {
    int a, b, c;
};
vector<muchie> vec;

void pop() {
    int ind = 1;
    int son = 2;
    swap(vec[1], vec[vec.size() - 1]);
    vec.erase(vec.begin() + vec.size() - 1);
    if (son < vec.size()) {
        if (son + 1 < vec.size() && vec[son].c > vec[son + 1].c) {
            son++;
        }
        while (vec[son].c < vec[ind].c) {
            swap(vec[son], vec[ind]);
            ind = son;
            son = ind * 2;
            if (son >= vec.size()) { break; }
            if (son + 1 < vec.size() && vec[son].c > vec[son + 1].c) {
                son++;
            }   
        }
    }
}

void add(muchie x) {
    int ind = vec.size();
    vec.push_back(x);
    while (vec[ind].c < vec[ind / 2].c && ind > 1) {
        swap(vec[ind], vec[ind / 2]);
        ind /= 2;
    }
}


void dijkstra(int p) {
    muchie x;
    mat[p][0] = 1;
    for (int i = 1;i <= n;i++) {
        if (mat[p][i] > 0) {
            x.a = p;
            x.b = i;
            x.c = mat[p][i];
            add(x);
        }
    }
    while (vec.size()>1) {
        int node;
        x = vec[1];
        node = x.b;
        pop();
        if (d[node] > d[x.a] + x.c) {
            mat[node][0] = 1;
            d[node] = d[x.a] + x.c;
            f[node] = x.a;
            for (int i = 1;i <= n;i++) {
                if (mat[node][i] > 0) {
                    x.a = node;
                    x.b = i;
                    x.c = mat[node][i];
                    add(x);
                }
            }

        }
        /*
        else if (d[node] > d[x.a] + x.c) {
            cout << "Da " << d[node] << " " << node << "\n";
            d[node] = d[x.a] + x.c;
            f[node] = x.a;
        }
        */
    }
}

int main()
{
    muchie x;
    x.a = 0;x.b = 0;x.c = 0;
    vec.push_back(x);
    cin >> n >> p;
    while (cin >> a >> b >> c) {
        mat[a][b] = c;
    }
    for (int i = 1;i <= n;i++) {
        d[i] = 10000;
    }
    d[p] = 0;
    dijkstra(p);
    for (int i = 1;i <= n;i++) {
        if (d[i] != 10000) { cout << d[i] << " "; }
        else { cout << "-1 "; }
    }
}
