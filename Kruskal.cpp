#include <iostream>
#include <vector>
using namespace std;
int f[102];
int n,m,sum;

struct muchie {
	int a, b, c;
};
vector<muchie> vec;

int root(int x) {
	int root_x = x;
	while (f[root_x] > 0) {
		root_x = f[root_x];
	}
	int aux;
	while (x != root_x) {
		aux = f[x];
		f[x] = root_x;
		x = aux;
	}
	return root_x;
}

bool query(int x, int y) {
	return root(x) == root(y);
}

void join(int x, int y) {
	int root_x = root(x), root_y = root(y);
	if (root_x == root_y) { return; }
	int size = f[root_x] + f[root_y];
	int root;
	if (root_x < root_y) { 
		root = root_x;
		f[root_y] = root_x;
		f[root_x] = size;
	}
	else {
		root = root_y;
		f[root_x] = root_y;
		f[root_y] = size;
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		f[i] = -1;
	}
	for (int i = 1;i <= m;i++) {
		muchie x;
		cin >> x.a >> x.b >> x.c;
		vec.push_back(x);
	}
	for(int i=0;i<vec.size();i++){
		for (int j = i + 1;j < vec.size();j++) {
			if (vec[i].c > vec[j].c) {
				muchie aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}
	}
	for (int i = 0;i < vec.size();i++) {
		if (!query(vec[i].a, vec[i].b)) {
			join(vec[i].a, vec[i].b);
			sum += vec[i].c;
		}
		else {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
	cout << sum << "\n";
	for (int i = 0;i < vec.size();i++) {
		cout << vec[i].a << " " << vec[i].b << "\n";
	}
}

