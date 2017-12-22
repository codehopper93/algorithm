/* DFS
깊이 우선 탐색은 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘 중 하나입니다.
현재 정점과 인접한 간선들을 검사하다가 방문하지 않은 정점을 발견하면 
그 간선을 통해 방문하지 은 정점으로 이동하는 것입니다.
이 과정을 반복하다가 더 이상 방문할 수 있는 정점이 없으면 마지막으로 통과한 간선을 통해 
뒤로 돌아가서 해당 정점에서 방문할 수 있는 정점을 탐색합니다. 
이러한 과정을 반복하여 그래프의 모든 정점을 방문하는 알고리즘이 DFS 알고리즘입니다.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> edge;		//인접리스트로 그래프 구현
vector<bool>visit;				//방문체크 , true = 방문
int N, M;						//N = 정점의 개수, M = 간선의 개수
int u, v;						// u = 시작정점 , v = 도착정점
int cnt;
void DFS(int current) {			//DFS 함수
	visit[current] = true;		//현재는 방문한걸로
	if (cnt == 0) {
		cout << current;
	}else{
		cout << "-> " << current;	//결과 출력
	}

	cnt++;
	for (int i = 0; i < edge[current].size(); i++) {
		int there = edge[current][i];
		if (visit[there]) {			//방문 한 거라면
			continue;
		}
		else {
			DFS(there);				//recursion
		}
	}
}

int main() {
	cin >> N >> M;
	edge.resize(N + 1);
	visit.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
	}
	DFS(1);

	return 0;
}