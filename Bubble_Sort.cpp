/*
��ǰ����(Bubble Sort)�� ������ ���ҵ��� ��Ұ��踦 ���Ͽ� ������ ��Ұ��踦 �������� ���� ��, ������ ���Ҹ� ��ȯ�ϴ� ������� ����Ǵ� �����Դϴ�.
��ǰ������ �ð����⵵�� ����ؾ� �� ������ (�����ؾ� �� ������ ���� - 1) * (�ִ� ��ȯ ��)�̹Ƿ� �� O ( N ^ 2 ) �� �˴ϴ�.
�� ����, �� ���İ� ���� ���ĺ��� ����� ��ȿ�����̹Ƿ� ���� ������ �ʽ��ϴ�.
*/
#include<iostream>

#define MAXN 5005

using namespace std;

int arr[MAXN];
int N;
//�ٲٱ� �Լ�
void swap(int *a, int *b) {		//call by reference
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N-i-1; j++) {
			if (arr[i] > arr[j+1]) {			//���ϱ�
				swap(arr[i], arr[j+1]);		//swap�Լ�
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}