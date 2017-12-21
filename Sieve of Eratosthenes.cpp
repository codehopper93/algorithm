/*
�����佺�׳׽��� ü�� Ư�� ������ ������ �Ҽ�(Prime)���� �ƴ����� �Ǻ��ϴ� �˰����Դϴ�.

*/

#include<iostream>
#include<cmath>

#define MAXN 1000001

using namespace std;

bool isReal[MAXN];			//�Ҽ� �Ǻ����� true = �Ҽ�, false = �Ҽ�X
int idx[MAXN], cnt, num, T, testcase;

void SO_Eratosthenes(int N) {
	for (int i = 2; i <= N; i++) {
		isReal[i] = true;			//true�� �ʱ�ȭ
	}
	
	for (int i = 2; i <= sqrt(N); i++) {		//������ �Ҽ��� ����� Ȧ���̹Ƿ� �� �ݱ����� ����ϸ� ��.
		if (!isReal[i]) {
			continue;
		}
		for (int j = i * 2; j <= N; j += i) {	//�� ������ ����� �� false
			isReal[j] = false;
		}
	}
}
int main() {
	SO_Eratosthenes(MAXN-1);			//�����佺�׳׽�
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