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
	int X;	//�ð�
	char C;	//L : ���� , D : ������
};

int main() {
	int N,K,L;		// N : ��, K = ����� , L = �� �����
	int Apple_x, Apple_y;
	cin >> N;
	vector<vector<int>>S_map(N, vector<int>(N,0));
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> Apple_x >> Apple_y;
		S_map[Apple_x-1][Apple_y-1] = -1;	// -1�� ���
	}
	cin >> L;

	dir d;			//�� ���� ����
	queue<pair<int, char>> direction;
	for (int i = 0; i < L; i++) {
		cin >> d.X >> d.C;
		direction.push({ d.X,d.C });
	}
	deque<pair<int,int>> snake;			//�� ����
	deque<pair<int, int>> snake_pre;		//����� �ε������� �Ǵ�����
	snake.push_back({ 0,0 });
	int sec=0;
	int cur_dir = RIGHT;			//ó�� ����
	bool collision = false;				//�Ӹ��� ���� �浹�ϴ��� ����

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
		//�ֱ����� snake�ȿ� �ִ��� = ����� �ε�����.
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
		//���� �ε����ų� ������ �Ӹ��� ������
		if (nx >= N || ny >= N || nx < 0 || ny < 0) break;
		
		if(!direction.empty()) {
			if (sec == direction.front().first) {
				//������
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
				//����
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
		//����� ������
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