/* BFS
너비 우선 탐색은 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘 중 하나입니다.
현재 정점과 인접한 간선들을 검사하다가 방문하지 않은 정점들을 발견하면 
그 간선을 통해 방문하지 않은 정점들을 자료구조 큐에 넣습니다.
그리고 큐의 front 정점을 방문하고 pop합니다.
또 해당 정점에서 인접한 간선을 검사해 방문하지 않은 정점들을 큐에 넣고 방문하기는 과정을 반복하다가 
더 이상 방문할 수 있는 정점이 없으면 종료합니다. 
이러한 과정을 반복하여 큐에 더 이상 정점이 존재하지 않을 때까지 
실행하여 그래프의 모든 정점을 방문하는 알고리즘이 BFS 알고리즘입니다
*/

#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

vector<vector<int>> edge;		//인접리스트로 그래프 구현
vector<bool>visited;				//방문체크 , true = 방문

int N, M;						//N = 정점의 개수, M = 간선의 개수
int u, v;						// u = 시작정점 , v = 도착정점

void BFS(int current) {
	queue<int> q;
	visited[current] = true;		//방문한건 체크
	q.push(current);				//큐에 넣는다.
	while (!q.empty()) {
		int num = q.front();			//front 저장
		cout << num << " ";
		q.pop();						//큐 front 빼기
		for (int i = 0; i < edge[num].size(); i++) {
			int there = edge[num][i];	
			if (visited[there]) {
				continue;
			}
			visited[there] = true;
			q.push(there);
		}
	}
}

int main() {
	cin >> N>> M;

	edge.resize(N + 1);
	visited.resize(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
	}
	BFS(1);
	return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 5005

using namespace std;

vector<vector<int>> edge;
vector<bool>visit;
int N, M;
int u, v;

void BFS(int cur) {
	visit[cur] = true;
	queue<int> q;
	q.push(cur);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		cout << here << " ";
		for (int i = 0; i < edge[here].size(); i++) {
			int there = edge[here][i];
			if (visit[there]) {
				continue;
			}
			visit[there] = true;
			q.push(there);
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
	BFS(1);

	return 0;
}
*/
