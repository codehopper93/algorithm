/* DFS
���� �켱 Ž���� �׷����� ��� �������� Ư���� ������ ���� �湮�ϴ� �˰��� �� �ϳ��Դϴ�.
���� ������ ������ �������� �˻��ϴٰ� �湮���� ���� ������ �߰��ϸ� 
�� ������ ���� �湮���� �� �������� �̵��ϴ� ���Դϴ�.
�� ������ �ݺ��ϴٰ� �� �̻� �湮�� �� �ִ� ������ ������ ���������� ����� ������ ���� 
�ڷ� ���ư��� �ش� �������� �湮�� �� �ִ� ������ Ž���մϴ�. 
�̷��� ������ �ݺ��Ͽ� �׷����� ��� ������ �湮�ϴ� �˰����� DFS �˰����Դϴ�.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> edge;		//��������Ʈ�� �׷��� ����
vector<bool>visit;				//�湮üũ , true = �湮
int N, M;						//N = ������ ����, M = ������ ����
int u, v;						// u = �������� , v = ��������
int cnt;
void DFS(int current) {			//DFS �Լ�
	visit[current] = true;		//����� �湮�Ѱɷ�
	if (cnt == 0) {
		cout << current;
	}else{
		cout << "-> " << current;	//��� ���
	}

	cnt++;
	for (int i = 0; i < edge[current].size(); i++) {
		int there = edge[current][i];
		if (visit[there]) {			//�湮 �� �Ŷ��
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