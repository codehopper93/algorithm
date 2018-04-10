#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	int B, C;
	long long  ans=0;

	cin >> N;


	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] < 0) {
			A[i] = 0;
		}
		ans++;
	}
	
	for (int i = 0; i < N; i++) {
		ans += A[i] / C;
		if (A[i] % C > 0) {
			ans++;
		}
	}

	cout << ans;

	return 0;
}