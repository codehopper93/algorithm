/*
��������(Insertion Sort)�� �迭�� ���ĵ� �κ�, ���ĵ��� ���� �κ����� ���� ��, ���Ҹ� ���������� Ž���ϸ鼭 �ش� ���Ҹ� ������ �� �κп� ���� �ִ� �����Դϴ�.
�ð����⵵�� �� ���ҿ� ���� ������ ��ġ�� ã���־�� �ϹǷ� �� ������ ���� O( N ), ���������� ���� ��ġ�� ã�µ� O( N )�� ��Ƿ�
O(N ^ 2)���� �������̳� �պ����Ŀ� ���� ��ȿ����(O(N log N))���� �� ������ �ʽ��ϴ�.
*/

#include<iostream>

#define MAXN 5005

using namespace std;

int arr[MAXN];
int N;

//�ڸ� �ٲٱ�
void swap(int &a, int &b) {
	int temp;			//�ӽ� ����
	temp = a;
	a = b;
	b = temp;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int temp = arr[i];			//�ӽ� ����
		int j = i - 1;
		for (; j >= 0; j--) {
			if (arr[j] < temp) {
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}

	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	return 0;
}