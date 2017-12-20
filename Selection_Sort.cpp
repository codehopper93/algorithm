/*
선택 정렬은 매 차례마다 정렬되지 않은 원소들을 모두 확인하여 각 인덱스에 맞는 원소를 선택하여 해당 인덱스의 원소와 교환해주는 정렬입니다.
매 차례마다 남은 원소들을 모두 확인하기 때문에 시간 복잡도는 최악의 연산 횟수나 평균 연산 횟수나 O(N^2)입니다.

*/
#include<iostream>
#include<vector>

#define MAXN 5005			//최대치 설정

using namespace std;

int arr[MAXN];
int N;
//위치 바꾸기
void swap(int &a, int&b) {	
	int temp;				//임시 저장소
	temp = a;
	a = b;
	b = temp;
}

//Selection_Sort함수
void selection_sort(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		int MinN = i;			//최소숫자
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