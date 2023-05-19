#include <iostream>
#include <vector>
using namespace std;
int mat[102][102];
int f[102];
int n, k, sum;
struct muchie {
	int a, b, c;
};
vector<muchie> vec;



void pop() {
	int ind = 1;
	int son = 2;
	int size = vec.size() - 1;
	swap(vec[1],vec[size]);
	vec.erase(vec.begin()+size);
	if (son < vec.size()) {
		if (son + 1 < vec.size()) {
			if (vec[son].c > vec[son + 1].c) {
				son = son + 1;
			}
		}
		while (vec[ind].c > vec[son].c) {
			swap(vec[ind], vec[son]);
			ind = son;
			son = ind * 2;
			if (son>=vec.size()) { break; }
			if (son + 1 < vec.size()) {
				if (vec[son].c > vec[son + 1].c) {
					son = son + 1;
				}
			}
		}
	}
}
void add(muchie x) {
	int ind = vec.size();
	vec.push_back(x);
	while (vec[ind].c < vec[ind / 2].c && ind>1) {
		swap(vec[ind], vec[ind / 2]);
		ind = ind / 2;
	}
}



int main()
{
	muchie m;
	m.a = 0;m.b = 0;m.c = 0;
	vec.push_back(m);
	int a, b, c;
	cin >> n >> k;
	for (int i = 1;i <= k;i++) {
		cin >> a >> b >> c;
		mat[a][b] = c;
		mat[b][a] = c;
	}
	for (int i = 1;i <= n;i++) {
		if (mat[1][i] > 0) {
			m.a = 1;
			m.b = i;
			m.c = mat[1][i];
			add(m);
		}
	}
	mat[1][0] = 1;
	while (vec.size() > 1) {
		m = vec[1];
		pop();
		b = m.b;
		if (mat[b][0] == 0) {
			mat[b][0] = 1;
			f[b] = m.a;
			sum += m.c;
			for (int i = 1;i <= n;i++) {
				if (mat[b][i] > 0) {
					m.a = b;
					m.b = i;
					m.c = mat[b][i];
					add(m);
				}
			}
		}
	}
	cout << sum << "\n";
	for (int i = 1;i <= n;i++) {
		cout << f[i] << " ";
	}
}

