/*Backjoon 1676
N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

input
10

output
2
*/
#include<iostream>

using namespace std;

int factorial(int n) {
	//��͸� �̿��� ���μ� ����
	//5�� ����� �����ϸ� �ȴ�.

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