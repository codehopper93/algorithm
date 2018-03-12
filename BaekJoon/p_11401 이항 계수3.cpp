/*Backjoon 11401 이항계수 3
자연수 과 정수 가 주어졌을 때 이항 계수 nCk 를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

*/
/*
	페르마의 소정리에 의한 풀이
	a가 정수 , p가 소수, a와p 가 서로소이면,
	a^p-1 === 1 (mod p) --> p로 나눈 나머지가 1로 같다는 뜻
	a*a^p-2 === 1 (mod p)로 바꾸고 역원은 a^p-2를 활용


	
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
	//nCk -> n! / k!(n-k)! 이므로 nf = k // a = n-k로 팩토리얼 계산
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