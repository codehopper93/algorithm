/* 이진탐색_BInary_Search
이진 탐색(Binary Search)은 정렬된 배열에서 원하는 값을 시간복잡도 O(log N) 만에 찾아내는 탐색하는 방법입니다.

오름차순으로 정렬된 사이즈가 N인 배열 D에서 원하는 값 k를 찾는 방법은 다음과 같습니다.

먼저 탐색할 데이터의 범위를 두 개의 인덱스(왼쪽, 오른쪽)로 지정하고 
이를 L, R이라고 하겠습니다. 정렬되어있기 때문에 D[L]은 최솟값, D[R]은 최대값이 됩니다.

당연히 처음 탐색 시에는 전체영역이므로 L = 0, R = N - 1 입니다.
이중 중앙값(Median)을 찾아 찾으려는 값 k와 비교합니다. 중앙값 M은 (L+R)/2 로 구할 수 있습니다.

*/

#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 5005
using namespace std;

int Bi[MAX], N;

bool Bi_Search(int value) {
	int r, l, m;
	l = 0;							//젤 왼쪽
	r = N - 1;					//젤 오른쪽
	while (l <= r) {
		m = (r + l) / 2;			//중간 계산
		if (value == Bi[m]) {		//찾는 값이 중간
			return true;
		}
		else if (value > m) {		//찾는 값이 중간보다 크다
			l = m + 1;
		}
		else {						//찾는 값이 중간보다 작다
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