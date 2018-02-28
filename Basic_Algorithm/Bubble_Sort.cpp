/*
거품정렬(Bubble Sort)은 인접한 원소들의 대소관계를 비교하여 일정한 대소관계를 만족하지 않을 시, 인접한 원소를 교환하는 방법으로 진행되는 정렬입니다.
거품정렬의 시간복잡도는 고려해야 할 루프가 (정렬해야 할 원소의 개수 - 1) * (최대 교환 수)이므로 총 O ( N ^ 2 ) 가 됩니다.
힙 정렬, 퀵 정렬과 같은 정렬보다 상당히 비효율적이므로 자주 쓰이지 않습니다.
*/
#include<iostream>

#define MAXN 5005

using namespace std;

int arr[MAXN];
int N;
//바꾸기 함수
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
			if (arr[i] > arr[j+1]) {			//비교하기
				swap(arr[i], arr[j+1]);		//swap함수
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
