/*
에라토스테네스의 체는 특정 범위의 수들이 소수(Prime)인지 아닌지를 판별하는 알고리즘입니다.

*/

#include<iostream>
#include<cmath>

#define MAXN 1000001

using namespace std;

bool isReal[MAXN];			//소수 판별위해 true = 소수, false = 소수X
int idx[MAXN], cnt, num, T, testcase;

void SO_Eratosthenes(int N) {
	for (int i = 2; i <= N; i++) {
		isReal[i] = true;			//true로 초기화
	}
	
	for (int i = 2; i <= sqrt(N); i++) {		//어차피 소수는 약수가 홀수이므로 그 반까지만 계산하면 됨.
		if (!isReal[i]) {
			continue;
		}
		for (int j = i * 2; j <= N; j += i) {	//그 숫자의 배수를 다 false
			isReal[j] = false;
		}
	}
}
int main() {
	SO_Eratosthenes(MAXN-1);			//에라토스테네스
	cin >> testcase;

	while (testcase != T) {
		T++;
		cin >> num;
		cout << "test#"  << T << endl;
		if (isReal[num]) {
			cout << "sosu" << endl;
		}
		else {
			cout << "sosu anim" << endl;
		}
	}
	return 0;
}