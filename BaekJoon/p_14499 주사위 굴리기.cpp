#pragma warning(disable:4996)
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define DONG 1
#define SEO 2
#define BOOK 3
#define NAM 4

struct point {						//좌표x,y
	int x;
	int y;
};

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int dice[4][3] = {  {0, 0, 0},		//주사위
					{0, 0, 0},
					{0, 0, 0},
					{0, 0, 0} };

void change(int dice[][3], int direction);

int main()
{
	int N, M,K;
	int command_con;
	point position;			//주사위 놓는 좌표
	cin >> N >> M;
	cin >> position.x >> position.y;
	cin >> K;				//명령개수
	vector<vector<int>> map(N, vector<int>(M,0));
	queue<int> command;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> command_con;
		command.push(command_con);
	}
	point cur;
	cur.x = position.x;
	cur.y = position.y;
	while (!command.empty()) {

		change(dice, command.front());
		int nx = dx[command.front() - 1];
		int ny = dy[command.front() - 1];

		cur.x += nx;
		cur.y += ny;
		if (cur.x < 0 || cur.y < 0 || cur.x >= N || cur.y >=M ) {
			
			if (command.front() == DONG) {
				change(dice, SEO);
			}
			else if(command.front() == SEO) {
				change(dice, DONG);
			}
			else if(command.front() == NAM) {
				change(dice, BOOK);
			}
			//BOOK
			else {
				change(dice, NAM);
			}
			cur.x -= nx;
			cur.y -= ny;
			command.pop();
			continue;
		}

		if (map[cur.x][cur.y] != 0) {
			dice[3][1] = map[cur.x][cur.y];
			map[cur.x][cur.y] = 0;
		}
		else {
			map[cur.x][cur.y] = dice[3][1];
		}
		cout << dice[1][1]<<"\n";
		command.pop();
	}

	return 0;
}


void change(int dice[][3], int direction) {
	int temp;

	switch (direction) {
	case DONG:
		temp = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = temp;
		break;
	case SEO:
		temp = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = temp;
		break;
	case BOOK:
		temp = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = dice[0][1];
		dice[0][1] = temp;
		break;
	case NAM:
		temp = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = temp;
		break;
	}
}
