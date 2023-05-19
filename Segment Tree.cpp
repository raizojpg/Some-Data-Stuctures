#include <iostream>
using namespace std;

long long vec[100002];
long long tree[300002];
int n, m, op, x, y;

void add(int poz, long long val, int l = 1, int r = n, int ind = 1) {
	if (l <= poz && poz <= r) {
		tree[ind] += val;
		if (l != r) {
			int mid = (l + r) / 2;
			add(poz, val, l, mid, ind * 2);
			add(poz, val, mid + 1, r, ind * 2 + 1);
		}
	}
}

long long sum(int x, int y, int l = 1, int r = n, int ind = 1) {
	if (x <= l && r <= y) { return tree[ind]; }
	if (l > y || r < x) { return 0; }
	else {
		int mid = (l + r) / 2;
		return sum(x, y, l, mid, ind * 2) + sum(x, y, mid + 1, r, ind * 2 + 1);
	}
}

long long construct(int ind, int l, int r) {
	if (l == r) { 
		tree[ind] = vec[l];
		return tree[ind]; 
	}
	else{
		int mid = (l + r) / 2;
		tree[ind] = construct(ind * 2, l, mid) + construct(ind * 2 + 1, mid + 1, r);
		return tree[ind];
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> vec[i];
	}
	tree[1] = construct(1, 1, n);
	for (int i = 1;i <= m;i++) {
		cin >> op >> x >> y;
		if (op == 1) { 
			long long val = y - vec[x];
			vec[x] = y;
			add(x, val); 
		}
		else if (op == 2) { cout << sum(x, y) << "\n"; }
	}
}