/*
���� ������ �� ���ʸ��� ���ĵ��� ���� ���ҵ��� ��� Ȯ���Ͽ� �� �ε����� �´� ���Ҹ� �����Ͽ� �ش� �ε����� ���ҿ� ��ȯ���ִ� �����Դϴ�.
�� ���ʸ��� ���� ���ҵ��� ��� Ȯ���ϱ� ������ �ð� ���⵵�� �־��� ���� Ƚ���� ��� ���� Ƚ���� O(N^2)�Դϴ�.

*/
#include<iostream>
#include<vector>

#define MAXN 5005			//�ִ�ġ ����

using namespace std;

int arr[MAXN];
int N;
//��ġ �ٲٱ�
void swap(int &a, int&b) {	
	int temp;				//�ӽ� �����
	temp = a;
	a = b;
	b = temp;
}

//Selection_Sort�Լ�
void selection_sort(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		int MinN = i;			//�ּҼ���
		for (int j = i + 1; j < size; j++) {
			if (arr[MinN] > arr[j]) {
				MinN = j;
			}
		}
		swap(arr[MinN], arr[i]);
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	selection_sort(arr, N);
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}