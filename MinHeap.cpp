#include <fstream>
#include <vector>
using namespace std;
vector<int> vec;
ifstream cin("heap.in");
ofstream cout("heap.out");


void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void push(int val) {
    vec.push_back(val);
    int ind = vec.size() - 1;
    int father = ind / 2;
    while (father > 0 && vec[ind] < vec[father]) {
        swap(vec[father], vec[ind]);
        ind = father;
        father = ind / 2;
    }
}

void pop(int val) {
    int ind = 0;
    for (int i = 1;i < vec.size();i++) {
        if (vec[i] == val) {
            ind = i;
            break;
        }
    }
    if (ind == 0) { return; }
    else {
        swap(vec[ind], vec[vec.size() - 1]);
        vec.erase(vec.begin() + vec.size() - 1);
    }
    ind = 1;
    int son1 = 2;
    int son2 = 3;
    while (son2 < vec.size()) {
        int son;
        if (vec[son1] < vec[son2]) { son = son1; }
        else { son = son2; }
        if (vec[ind] > vec[son]) {
            swap(vec[ind], vec[son]);
            ind = son;
            son1 = ind * 2;
            son2 = ind * 2 + 1;
        }
        else { break; }
    }
    if (son1<vec.size() && vec[ind]>vec[son1]) {
        swap(vec[ind], vec[son1]);
    }

}

int peek() {
    return vec[1];
}

int main()
{
    vec.push_back(0);
    int k,op;
    cin >> k;
    for (int i = 1;i <= k;i++) {
        cin >> op;
        if (op == 1) {
            int val;
            cin >> val;
            push(val * (-1));
        }
        else if (op == 2) {
            cout << peek() * (-1) << "\n";
            pop(peek());
        }
    }


}

