#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

#define MAX 10

using namespace std;

struct point {
	int x, y;
};

int main(int argc, char** argv) {
	int n, m;

	point R, B;

	cin >> n >> m;
	vector<vector<char>> miro(n, vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> miro[i][j];
			if (miro[i][j] == 'B') {
				B.x = i;
				B.y = j;
			}
			if (miro[i][j] == 'R') {
				R.x = i;
				R.y = j;
			}
		}
	}
	queue<pair<pair<point, point>, int>> q;		//R,B,cnt
	bool check[MAX][MAX][MAX][MAX] = { false }; //Rx,Ry,Bx,By 탐색
	check[R.x][R.y][B.x][B.y] = { true };

	int dx[] = { -1,1,0,0 };		//x  좌표
	int dy[] = { 0,0,-1,1 };		//y  좌표

	q.push({ {R,B},0 });
	while ( !q.empty()) {
		R = q.front().first.first;
		B = q.front().first.second;
		int cnt = q.front().second+1;		//cnt세기
		q.pop();
		if (cnt > 10) { continue; }			//10회 넘어가면 out 

		//4방향 move
		for (int i = 0; i < 4; i++) {
			point nR = R;
			point nB = B;

			// R,B 4방향 move 
			while (miro[nR.x + dx[i]][nR.y + dy[i]] != '#') {
				nR.x += dx[i];
				nR.y += dy[i];
				if (miro[nR.x][nR.y] == 'O') break;
			}
			while (miro[nB.x + dx[i]][nB.y + dy[i]] != '#') {
				nB.x += dx[i];
				nB.y += dy[i];
				if (miro[nB.x][nB.y] == 'O') break;
			}

			//파란공이 나오면
			if (miro[nB.x][nB.y] == 'O')
				continue;
			//빨간공이 나오면
			if (miro[nR.x][nR.y] == 'O')
			{
				cout << cnt << "\n";
				return 0;
			}

			//겹친다면
			if (nR.x == nB.x && nR.y == nB.y) {
				if (dx[i] != 0) {
					if (R.x * dx[i] > B.x *dx[i])
						nB.x -= dx[i];
					else
						nR.x -= dx[i];
				}
				else {
					if (R.y *dy[i] > B.y*dy[i])
						nB.y -= dy[i];
					else
						nR.y -= dy[i];
				}

			}

			//방문안한것 큐 push
			if (check[nR.x][nR.y][nB.x][nB.y]) continue;
			q.push({ {nR,nB},cnt });
			check[nR.x][nR.y][nB.x][nB.y] = true;
		}
	}
	cout << -1;

	return 0;
}