#include <fstream>
#include <vector>
using namespace std;
ifstream cin("dijkstra2.in");
ofstream cout("dijkstra2.out");

//list[i] would be the node
//list[i].first would be the adiacent one
//list[i].second would be the lenght
vector<pair<int, int>> l;
vector<vector<pair<int, int>>> list;
long long dist[100001];
//int father[100001];
//in vec we store the indices with the smallest distance
vector<int> vec;
int n, m;

//priority queue
void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

int pop() {
    int node = vec[1];
    swap(vec[1], vec[vec.size() - 1]);
    vec.erase(vec.begin() + vec.size() - 1);
    int poz = 1;
    int son1 = poz * 2;
    int son2 = poz * 2 + 1;
    while (son2 < vec.size()) {
        int son;
        if (dist[vec[son1]] < dist[vec[son2]]) { son = son1; }
        else { son = son2; }
        if (dist[vec[poz]] > dist[vec[son]]) {
            swap(vec[poz], vec[son]);
            poz = son;
            son1 = poz * 2;
            son2 = poz * 2 + 1;
        }
        else { break; }
    }
    if (son1 < vec.size()) {
        if (dist[vec[poz]] > dist[vec[son1]]) {
            swap(vec[poz], vec[son1]);
        }
    }
    return node;
}

void update(int val) {
    int poz;
    for (int i = 1;i < vec.size();i++) {
        if (vec[i] == val) { poz = i; }
    }
    while (poz / 2 != 0 && dist[vec[poz / 2]] > dist[vec[poz]]) {
        swap(vec[poz], vec[poz / 2]);
        poz = poz / 2;
    }
}

void add(int val) {
    int poz = vec.size();
    vec.push_back(val);
    while (poz / 2 != 0 && dist[vec[poz / 2]] > dist[vec[poz]]) {
        swap(vec[poz], vec[poz / 2]);
        poz = poz / 2;
    }
}

// dijkstra
void dijkstra(int start) {
    dist[start] = 0;
    //list[start][0].first = -1; // this mean visited
    for (int i = 1;i < list[start].size();i++) {
        int next_node = list[start][i].first;
        int lenght = list[start][i].second;
        dist[next_node] = dist[start] + lenght;
        add(next_node);
    }
    while (vec.size() > 1) {
        int node = pop();
        //list[node][0].first = -1; //this mean visited
        for (int i = 1;i < list[node].size();i++) {
            int next_node = list[node][i].first;
            int lenght = list[node][i].second;
            if (dist[next_node] == -1) {
                dist[next_node] = dist[node] + lenght;
                add(next_node);
            }
            else if (dist[next_node] > dist[node] + lenght) {
                dist[next_node] = dist[node] + lenght;
                update(next_node);
            }
        }
    }
}

int main()
{
    vec.push_back(0);
    l.push_back(make_pair(0, 0));
    list.push_back(l);
    int a, b, c, start;
    cin >> n >> m >> start;
    for (int i = 1;i <= n;i++) {
        dist[i] = -1;
        list.push_back(l);
    }
    for (int i = 1;i <= m;i++) {
        cin >> a >> b >> c;
        list[a].push_back(make_pair(b, c));
        list[b].push_back(make_pair(a, c));
    }

    dijkstra(start);

    for (int i = 1;i <= n;i++) {
        cout << dist[i] << " ";
    }
}

