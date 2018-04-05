/*Backjoon 6591
n개의 원소 중에서 k개를 순서 없이 선택하는 방법의 수는 몇 가지 일까?

input
4 2
10 5
49 6
0 0

output
6
252
13983816

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

typedef long long int ll;

int main() {

	int n, m;
	int div = 1;
	ll ans=1;
	vector<ll> vec;
	vector<ll>::iterator it;
	while (1) {
		cin >> n >> m;

		if (n == 0 && m == 0) {
			break;
		}
		if (n - m < m) {		//nCm = nCn-m
			m = n - m;
		}
		while (m-- > 0) {
			ans *= n--;
			ans /= div++;		//항상 10*8*7 = 3으로 나눠진다
		}
		vec.push_back(ans);
		ans = 1;
		div = 1;
	}
	for (it = vec.begin(); it != vec.end(); it++) {
		cout << *it << "\n";
	}
	return 0;
}
