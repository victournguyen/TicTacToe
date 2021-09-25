#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char board[3][3];

void print_board() {
	printf("    0   1   2\n\n");
	for (int r = 0; r < 3; r++) {
		//possible update to use letters as row identifiers
		printf("%c   %c | %c | %c\n", /*'A' +*/ r, board[r][0], board[r][1], board[r][2]);
		if (r < 2) printf("    ---------\n");
	}
	printf("\n");
}

void init() {
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			char c1 = ' ';
			board[r][c] = c1;
		}
	}
}

bool done() {
	//rows
	for (int r = 0; r < 3; r++) {
		if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != ' ') {
			system("CLS");
			print_board();
			printf("%c wins!\n", board[r][0]);
			return true;
		}
	}
	//columns
	for (int c = 0; c < 3; c++) {
		if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != ' ') {
			system("CLS");
			print_board();
			printf("%c wins!\n", board[0][c]);
			return true;
		}
	}
	//diagonals
	if (board[1][1] != ' ' && (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[2][0] == board[1][1] && board[2][0] == board[0][2])) {
		system("CLS");
		print_board();
		printf("%c wins!\n", board[1][1]);
		return true;
	}
	//draw
	bool draw = true;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == ' ') {
				draw = false;
				break;
			}
		}
	}
	if (draw) {
		system("CLS");
		print_board();
		printf("It's a draw!\n");
		return true;
	}
	return false;
}

int main() {
	init();
	print_board();
	printf("current: row column\n");
	char turn = 'X';
	while (!done()) {
		printf("%c: ", turn);
		
		//possible update to use letters as row identifiers
		//this part is not done yet
		//notes: switch to using string for cr and int for cc, so there is no problem with more than 2 characters in the input
		/*
		char cr, cc;
		cin >> cr >> cc;
		while (isdigit(cr) || !isdigit(cc) || !((cr <= 'C' && cr >= 'A') || (cr <= 'c' && cr >= 'a')) || !(cc <= '2' && cc >= '0')) {
			cout << "You are dum dum. ";
			if (isdigit(cr))
				cout << "Row is not supposed to be a number.";
			else if (!isdigit(cc))
				cout << "Column is supposed to be a number.";
			else if (!((cr <= 'C' && cr >= 'A') || (cr <= 'c' && cr >= 'a')) && !(cc <= '2' && cc >= '0'))
				cout << "Your row and column are bad. Row must be A-C or a-c and column must be 0-2.";
			else if (!((cr <= 'C' && cr >= 'A') || (cr <= 'c' && cr >= 'a')))
				cout << "Your row is bad. It must be in the range A-C or a-c.";
			else if (!(cc <= '2' && cc >= '0'))
				cout << "Your column is bad. It must be in the range 0-2.";
			cout << " Try again!\n" << turn << ": ";
			cin >> cr >> cc;
		}
		int r, c = cc - '0';
		if (cr <= 'C' && cr >= 'A')
			r = cr - 'A';
		else
			r = cr - 'a';
		*/

		int r, c;
		/*printf("Row: ");
		scanf("%d", &r);
		printf("Column: ");
		scanf("%d", &c);*/
		scanf("%d %d", &r, &c);
		while (r < 0 || r > 2 || c < 0 || c > 2) {
			printf("You are dum dum. Row and column must be in the range 0-2. Try again!\n%c: ", turn);
			scanf("%d %d", &r, &c);
		}
		while (board[r][c] != ' ') {
			printf("You are dum dum. This space is already occupied. Try again!\n%c: ", turn);
			scanf("%d %d", &r, &c);
		}
		board[r][c] = turn;
		system("CLS");
		print_board();
		printf("current: row column\n");
		if (turn == 'X') turn = 'O';
		else turn = 'X';
	}
	cin.get();
	cin.get();
}