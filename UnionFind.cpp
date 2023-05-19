#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(50000, -1);
int maxi = 0;

int find(int val) {
	int root = val;
	while (vec[root] > 0) {
		root = vec[root];
		vec[val] = root;
	}
	return root;
}

void add(int x, int y) {
	int root_x = find(x);
	int root_y = find(y);
	if (root_x != root_y) {
		vec[root_x] += vec[root_y];
		if (vec[root_x] < maxi) { maxi = vec[root_x]; }
		vec[root_y] = root_x;
		vec[y] = root_x;
	}
}



int main()
{
	int n, m, op, a, b;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> a >> b;
			add(a, b);

		break;
		case 2:
			cin >> a >> b;
			if (find(a) == find(b)) {
				cout << "DA" << "\n";
			}
			else { cout << "NU" << "\n"; }
		break;
		case 3:
			cout << maxi * (-1) << "\n";
		break;

		default:
			break;
		}


	}


}

