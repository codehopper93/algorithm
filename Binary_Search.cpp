/* ����Ž��_BInary_Search
���� Ž��(Binary Search)�� ���ĵ� �迭���� ���ϴ� ���� �ð����⵵ O(log N) ���� ã�Ƴ��� Ž���ϴ� ����Դϴ�.

������������ ���ĵ� ����� N�� �迭 D���� ���ϴ� �� k�� ã�� ����� ������ �����ϴ�.

���� Ž���� �������� ������ �� ���� �ε���(����, ������)�� �����ϰ� 
�̸� L, R�̶�� �ϰڽ��ϴ�. ���ĵǾ��ֱ� ������ D[L]�� �ּڰ�, D[R]�� �ִ밪�� �˴ϴ�.

�翬�� ó�� Ž�� �ÿ��� ��ü�����̹Ƿ� L = 0, R = N - 1 �Դϴ�.
���� �߾Ӱ�(Median)�� ã�� ã������ �� k�� ���մϴ�. �߾Ӱ� M�� (L+R)/2 �� ���� �� �ֽ��ϴ�.

*/

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 5005
using namespace std;

int Bi[MAX], N;

bool Bi_Search(int value) {
	int r, l, m;
	l = 0;							//�� ����
	r = N - 1;					//�� ������
	while (l <= r) {
		m = (r + l) / 2;			//�߰� ���
		if (value == Bi[m]) {		//ã�� ���� �߰�
			return true;
		}
		else if (value > m) {		//ã�� ���� �߰����� ũ��
			l = m + 1;
		}
		else {						//ã�� ���� �߰����� �۴�
			r = m - 1;
		}
	}
	return false;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Bi[i];
	}
	sort(Bi, Bi + N);
	int ans;
	cin >> ans;
	while (ans--) {
		int q; cin >> q;
		if (Bi_Search(q)) cout << "exist" << endl;
		else cout << "no" << endl;
	}
	return 0;
}