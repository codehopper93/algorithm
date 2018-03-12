/*Backjoon 11401 ���װ�� 3
�ڿ��� �� ���� �� �־����� �� ���� ��� nCk �� 1,000,000,007�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

*/
/*
	�丣���� �������� ���� Ǯ��
	a�� ���� , p�� �Ҽ�, a��p �� ���μ��̸�,
	a^p-1 === 1 (mod p) --> p�� ���� �������� 1�� ���ٴ� ��
	a*a^p-2 === 1 (mod p)�� �ٲٰ� ������ a^p-2�� Ȱ��


	
	*/
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

#define MOD 1000000007LL
typedef long long int ll;

ll square(ll x, ll y) {
	ll sq = 1;
	while (y > 0) {
		if (y % 2) {
			sq *= x;
			sq %= MOD;
		}
		x *= x;
		x %= MOD;
		y /= 2;
	}
	return sq;
}

ll combi(ll n, ll k) {
	//nCk -> n! / k!(n-k)! �̹Ƿ� nf = k // a = n-k�� ���丮�� ���
	ll nf = 1, a = 1;
	for (ll i = n; i >= 1; i--) {
		nf *= i;
		nf %= MOD;
	}
	for (ll i = k; i >= 1; i--) {
		a *= i;
		a %= MOD;
	}
	for (ll i = n - k; i >= 1; i--) {
		a *= i;
		a %= MOD;
	}
	return (nf*square(a, MOD - 2)) % MOD;
}

int main() {
	ll n, k;

	cin >> n >> k;
	
	cout << combi(n, k);
	
	return 0;
}