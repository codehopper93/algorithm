#include<iostream>
#include<vector>
#include<deque>
#include<queue>
using namespace std;

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

struct dir {
	int X;	//시간
	char C;	//L : 왼쪽 , D : 오른쪽
};

int main() {
	int N,K,L;		// N : 맵, K = 사과수 , L = 뱀 방향수
	int Apple_x, Apple_y;
	cin >> N;
	vector<vector<int>>S_map(N, vector<int>(N,0));
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> Apple_x >> Apple_y;
		S_map[Apple_x-1][Apple_y-1] = -1;	// -1은 사과
	}
	cin >> L;

	dir d;			//뱀 방향 시점
	queue<pair<int, char>> direction;
	for (int i = 0; i < L; i++) {
		cin >> d.X >> d.C;
		direction.push({ d.X,d.C });
	}
	deque<pair<int,int>> snake;			//뱀 구현
	deque<pair<int, int>> snake_pre;		//몸통과 부딪히는지 판단위해
	snake.push_back({ 0,0 });
	int sec=0;
	int cur_dir = RIGHT;			//처음 방향
	bool collision = false;				//머리와 몸통 충돌하는지 여부

	while (1) {
		sec++;

		int nx = snake.front().first;
		int ny = snake.front().second;

		if (cur_dir == UP) {
			nx -= 1;
		}
		else if (cur_dir == DOWN) {
			nx += 1;
		}
		else if (cur_dir == LEFT) {
			ny -= 1;
		}
		//RIGHT
		else {
			ny += 1;
		}
		snake_pre.push_front({ nx,ny });
		//넣기전에 snake안에 있는지 = 몸통과 부딪혔다.
		if (!snake.empty()) {
			deque<pair<int, int>>::iterator it;
			for (it = snake.begin(); it != snake.end(); it++) {
				if (*it == snake_pre.front()) {
					collision = true;
				}
			}
			snake_pre.pop_front();
		}
		else {
			snake_pre.pop_front();
		}

		if (collision) break;

		snake.push_front({ nx,ny });
		//벽에 부딪히거나 꼬리와 머리가 같으면
		if (nx >= N || ny >= N || nx < 0 || ny < 0) break;
		
		if(!direction.empty()) {
			if (sec == direction.front().first) {
				//오른쪽
				if (direction.front().second == 'D') {
					if (cur_dir == UP) {
						cur_dir = RIGHT;
					}
					else if (cur_dir == DOWN) {
						cur_dir = LEFT;
					}
					else if (cur_dir == LEFT) {
						cur_dir = UP;
					}
					//RIGHT
					else {
						cur_dir = DOWN;
					}
				}
				//왼쪽
				else if (direction.front().second == 'L') {
					if (cur_dir == UP) {
						cur_dir = LEFT;
					}
					else if (cur_dir == DOWN) {
						cur_dir = RIGHT;
					}
					else if (cur_dir == LEFT) {
						cur_dir = DOWN;
					}
					//RIGHT
					else {
						cur_dir = UP;
					}
				}
				direction.pop();
			}
		}
		//사과를 만나면
		if (S_map[nx][ny] == -1) {
			S_map[nx][ny] = 0;
		}
		else {
			snake.pop_back();
		}
		
	}
	cout << sec;

	return 0;
}