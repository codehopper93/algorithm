/*Backjoon 1676
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

input
10

output
2
*/
#include<iostream>

using namespace std;

int factorial(int n) {
	//재귀를 이용한 소인수 분해
	//5의 배수만 생각하면 된다.

	int ans = 0;

	if (n == 1) {
		return 0;
	}
	else if (n == 0) {
		return 0;
	}
	else {
		ans = n / 5;
	}
	return ans+factorial(n/5);
}

int main() {
	int n, ans=0;

	cin >> n;

	cout << factorial(n) << endl;

	return 0;
}