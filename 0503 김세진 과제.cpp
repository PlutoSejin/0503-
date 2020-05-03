#include <Bangtal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#pragma comment(lib, "Bangtal.lib")
int board[9] = { 0,0,0,0,0,0,0,0,0 }, cnt = 0;

SceneID scene1, scene2, scene3, scene4;
ObjectID p[9], whyButton, returnButton;
ObjectID startButton, endButton, restartButton, doll, first, second, line1, line2, line3, line4;


ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y) {
	ObjectID object = createObject(name, image);
	locateObject(object, scene, x, y);
	showObject(object);
	return object;
}

int win(const int board[9]) {
	unsigned wins[8][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6} };
	int i;
	for (i = 0; i < 8; ++i) {
		if (board[wins[i][0]] != 0 &&
			board[wins[i][0]] == board[wins[i][1]] &&
			board[wins[i][0]] == board[wins[i][2]])
			return board[wins[i][2]];
	}
	return 0;
}
void reader() {
	if (win(board) == 1 || win(board) == -1 || cnt == 5)
	{
		enterScene(scene4);
		if (win(board) == 1) {
			showMessage("당신이 졌습니다");
		}
		else if (win(board) == -1) {
			showMessage("당신이 이겼습니다");

		}
		else if (cnt == 5) {
			showMessage("비겼습니다");
		}
	}
}

void checker() {
	if (board[0] == 1) {
		setObjectImage(p[0], "1_x.png");
	}
	if (board[1] == 1) {
		setObjectImage(p[1], "2_x.png");
	}
	if (board[2] == 1) {
		setObjectImage(p[2], "3_x.png");
	}
	if (board[3] == 1) {
		setObjectImage(p[3], "4_x.png");
	}
	if (board[4] == 1) {
		setObjectImage(p[4], "5_x.png");
	}
	if (board[5] == 1) {
		setObjectImage(p[5], "6_x.png");
	}
	if (board[6] == 1) {
		setObjectImage(p[6], "7_x.png");
	}
	if (board[7] == 1) {
		setObjectImage(p[7], "8_x.png");
	}
	if (board[8] == 1) {
		setObjectImage(p[8], "9_x.png");
	}
}

int minimax(int board[9], int player) {
	int winner = win(board);
	if (winner != 0) return winner * player;

	int move = -1;
	int score = -2;
	int i;
	for (i = 0; i < 9; ++i) {
		if (board[i] == 0) {
			board[i] = player;
			int thisScore = -minimax(board, player * -1);
			if (thisScore > score) {
				score = thisScore;
				move = i;
			}
			board[i] = 0;
		}
	}
	if (move == -1) return 0;
	return score;
}

void mouseCallback(ObjectID object, int x, int y, MouseAction  action) {
	if (object == startButton) {
		enterScene(scene2);
	}
	else if (object == restartButton) {
		cnt = 0;
		hideObject(returnButton);
		for (int i = 0; i < 9; i++)
		{
			board[i] = 0;
		}
		setObjectImage(p[0], "one.png");
		setObjectImage(p[1], "two.png");
		setObjectImage(p[2], "3.png");
		setObjectImage(p[3], "4.png");
		setObjectImage(p[4], "5.png");
		setObjectImage(p[5], "6.png");
		setObjectImage(p[6], "7.png");
		setObjectImage(p[7], "8.png");
		setObjectImage(p[8], "9.png");
		enterScene(scene2);
	}
	else if (object == endButton) {
		endGame();
	}
	else if (object == returnButton) {
		enterScene(scene4);
	}
	else if (object == whyButton) {
		showObject(returnButton);
		enterScene(scene3);
	}
	else if (object == first) {
		hideObject(returnButton);
		enterScene(scene3);
	}
	else if (object == second) {
		hideObject(returnButton);
		cnt = 1;
		enterScene(scene3);
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
	}
	else if (object == p[0]) {
		checker();
		cnt++;
		if (board[0] == 0) {
			board[0] = -1;
			setObjectImage(p[0], "1_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[1]) {
		checker();
		cnt++;
		if (board[1] == 0) {
			board[1] = -1;
			setObjectImage(p[1], "2_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();

	}
	else if (object == p[2]) {
		checker();
		cnt++;
		if (board[2] == 0) {
			board[2] = -1;
			setObjectImage(p[2], "3_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[3]) {
		checker();
		cnt++;
		if (board[3] == 0) {
			board[3] = -1;
			setObjectImage(p[3], "4_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[4]) {
		checker();
		cnt++;
		if (board[4] == 0) {
			board[4] = -1;
			setObjectImage(p[4], "5_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[5]) {
		checker();
		cnt++;
		if (board[5] == 0) {
			board[5] = -1;
			setObjectImage(p[5], "6_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[6]) {
		checker();
		cnt++;
		if (board[6] == 0) {
			board[6] = -1;
			setObjectImage(p[6], "7_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[7]) {
		checker();
		cnt++;
		if (board[7] == 0) {
			board[7] = -1;
			setObjectImage(p[7], "8_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
	else if (object == p[8]) {
		checker();
		cnt++;
		if (board[8] == 0) {
			board[8] = -1;
			setObjectImage(p[8], "9_o.png");
		}
		int move = -1;
		int score = -2;
		int i;
		for (i = 0; i < 9; ++i) {
			if (board[i] == 0) {
				board[i] = 1;
				int tempScore = -minimax(board, -1);
				board[i] = 0;
				if (tempScore > score) {
					score = tempScore;
					move = i;
				}
			}
		}
		board[move] = 1;
		checker();
		reader();
	}
}

int main() {
	int player = 0;

	scene1 = createScene("틱택토", "틱택토.png");
	scene2 = createScene("틱택토", "틱택토2.png");
	scene3 = createScene("틱택토", "흰색.png");
	scene4 = createScene("틱택토", "검정.png");
	setMouseCallback(mouseCallback);

	startButton = createObject("시작 버튼", "start.png", scene1, 590, 201);
	restartButton = createObject("재시작 버튼", "restart.png", scene4, 590, 70);
	endButton = createObject("끝 버튼", "end.png", scene4, 590, 201);
	whyButton = createObject("이유 버튼", "why.png", scene4, 590, 135);
	returnButton = createObject("되돌아가기 버튼", "return.png", scene3, 30, 600);
	p[0] = createObject("버튼1", "one.png", scene3, 240, 720 - 233);
	p[1] = createObject("버튼2", "two.png", scene3, 482, 720 - 233);
	p[2] = createObject("버튼3", "3.png", scene3, 772, 720 - 233);
	p[3] = createObject("버튼4", "4.png", scene3, 240, 720 - 432);
	p[4] = createObject("버튼5", "5.png", scene3, 482, 720 - 432);
	p[5] = createObject("버튼6", "6.png", scene3, 772, 720 - 432);
	p[6] = createObject("버튼7", "7.png", scene3, 240, 720 - 632);
	p[7] = createObject("버튼8", "8.png", scene3, 482, 720 - 632);
	p[8] = createObject("버튼9", "9.png", scene3, 772, 720 - 632);
	line1 = createObject("선", "선1.png", scene3, 241, 720 - 239);
	line2 = createObject("선", "선1.png", scene3, 241, 720 - 436);
	line3 = createObject("선", "선2.png", scene3, 479, 720 - 642);
	line4 = createObject("선", "선2.png", scene3, 763, 720 - 642);
	first = createObject("first", "first.png", scene2, 30, 600);
	second = createObject("second", "second.png", scene2, 30, 500);
	doll = createObject("공", "ball1.png", scene1, 620, 300);
	scaleObject(doll, 0.1f);
	scaleObject(first, 0.1f);
	scaleObject(second, 0.1f);
	startGame(scene1);

}
