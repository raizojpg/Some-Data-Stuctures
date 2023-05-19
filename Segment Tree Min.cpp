#include <iostream>
using namespace std;

int vec[100002];
int tree[400002];
int n, m, op, x, y;

int minimum(int a, int b) {
	if (a == 0) { return b; }
	if (b == 0) { return a; }
	if (a < b) { return a; }
	else { return b; }
}

void add(int poz, int val, int l = 1, int r = n, int ind = 1) {
	if (l <= poz && poz <= r) {
		if (l == r) {
			tree[ind] = val;
		}
		else {
			int mid = (l + r) / 2;
			add(poz, val, l, mid, ind * 2);
			add(poz, val, mid + 1, r, ind * 2 + 1);
			tree[ind] = minimum(tree[ind * 2], tree[ind * 2 + 1]);
		}
	}
}

int min(int x, int y, int l = 1, int r = n, int ind = 1) {
	if (x <= l && r <= y) { return tree[ind]; }
	if (l > y || r < x) { return 0; }
	else {
		int mid = (l + r) / 2;
		return minimum(min(x, y, l, mid, ind * 2), min(x, y, mid + 1, r, ind * 2 + 1));
	}
}

long long construct(int ind, int l, int r) {
	if (l == r) {
		tree[ind] = vec[l];
		return tree[ind];
	}
	else {
		int mid = (l + r) / 2;
		tree[ind] = minimum(construct(ind * 2, l, mid), construct(ind * 2 + 1, mid + 1, r));
		return tree[ind];
	}
}

int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> vec[i];
	}
	tree[1] = construct(1, 1, n);
	cin >> m;
	for (int i = 1;i <= m;i++) {
		cin >> op >> x >> y;
		if (op == 1) { cout << min(x, y) << "\n"; }
		else if (op == 2) {
			vec[x] = y;
			add(x, y);
		}
	}
}