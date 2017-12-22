/* BFS
�ʺ� �켱 Ž���� �׷����� ��� �������� Ư���� ������ ���� �湮�ϴ� �˰��� �� �ϳ��Դϴ�.
���� ������ ������ �������� �˻��ϴٰ� �湮���� ���� �������� �߰��ϸ� 
�� ������ ���� �湮���� ���� �������� �ڷᱸ�� ť�� �ֽ��ϴ�.
�׸��� ť�� front ������ �湮�ϰ� pop�մϴ�.
�� �ش� �������� ������ ������ �˻��� �湮���� ���� �������� ť�� �ְ� �湮�ϱ�� ������ �ݺ��ϴٰ� 
�� �̻� �湮�� �� �ִ� ������ ������ �����մϴ�. 
�̷��� ������ �ݺ��Ͽ� ť�� �� �̻� ������ �������� ���� ������ 
�����Ͽ� �׷����� ��� ������ �湮�ϴ� �˰����� BFS �˰����Դϴ�
*/

#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>

using namespace std;

vector<vector<int>> edge;		//��������Ʈ�� �׷��� ����
vector<bool>visited;				//�湮üũ , true = �湮

int N, M;						//N = ������ ����, M = ������ ����
int u, v;						// u = �������� , v = ��������

void BFS(int current) {
	queue<int> q;
	visited[current] = true;		//�湮�Ѱ� üũ
	q.push(current);				//ť�� �ִ´�.
	while (!q.empty()) {
		int num = q.front();			//front ����
		cout << num << " ";
		q.pop();						//ť front ����
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