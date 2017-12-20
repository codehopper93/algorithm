/*
삽입정렬(Insertion Sort)은 배열을 정렬된 부분, 정렬되지 않은 부분으로 나눈 후, 원소를 순차적으로 탐색하면서 해당 원소를 정렬이 된 부분에 끼워 넣는 정렬입니다.
시간복잡도는 각 원소에 대해 적당한 위치를 찾아주어야 하므로 총 원소의 개수 O( N ), 순차적으로 삽입 위치를 찾는데 O( N )이 들므로
O(N ^ 2)으로 힙정렬이나 합병정렬에 비해 비효율적(O(N log N))으로 잘 쓰이지 않습니다.
*/

#include<iostream>

#define MAXN 5005

using namespace std;

int arr[MAXN];
int N;

//자리 바꾸기
void swap(int &a, int &b) {
	int temp;			//임시 저장
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
		int temp = arr[i];			//임시 저장
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