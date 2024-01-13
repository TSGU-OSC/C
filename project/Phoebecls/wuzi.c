#include <stdio.h>

#define BOARD_SIZE 15
#define EMPTY '.'

void initBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE]);
int makeMove(char board[][BOARD_SIZE], int row, int col, char player);
int checkWin(char board[][BOARD_SIZE], int row, int col);

int main() {
  char board[BOARD_SIZE][BOARD_SIZE];
  int row, col;
  char player = 'X';
  initBoard(board);

  while (1) {
    printBoard(board);
    printf("��� %c�������������µ�λ�ã��� �У���", player);
    scanf("%d %d", &row, &col);

    if (makeMove(board, row - 1, col - 1, player)) {
      if (checkWin(board, row - 1, col - 1)) {
        printBoard(board);
        printf("��� %c ��ʤ��\n", player);
        break;
      }
      player = (player == 'X') ? 'O' : 'X';
    } else {
      printf("�Ѿ��������ӣ����������롣\n");
    }
  }

  return 0;
}

void initBoard(char board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      board[i][j] = EMPTY;
    }
  }
}

void printBoard(char board[][BOARD_SIZE]) {
  printf("  ");
  for (int i = 0; i < BOARD_SIZE; i++) {
    printf(" %-2d", i + 1);
  }
  printf("\n");

  for (int i = 0; i < BOARD_SIZE; i++) {
    printf("%2d", i + 1);
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(" %c ", board[i][j]);
    }
    printf("\n");
  }
}

int makeMove(char board[][BOARD_SIZE], int row, int col, char player) {
  if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE &&
      board[row][col] == EMPTY) {
    board[row][col] = player;
    return 1; // �ɹ���������
  }
  return 0; // λ����Ч���ѱ�ռ��
}

int checkWin(char board[][BOARD_SIZE], int row, int col) {
  char player = board[row][col];
  int count;

  // ���ˮƽ����
  for (int i = -4; i <= 0; i++) {
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (col + i + j >= 0 && col + i + j < BOARD_SIZE &&
          board[row][col + i + j] == player) {
        count++;
      }
    }
    if (count == 5)
      return 1;
  }

  // ��鴹ֱ����
  for (int i = -4; i <= 0; i++) {
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (row + i + j >= 0 && row + i + j < BOARD_SIZE &&
          board[row + i + j][col] == player) {
        count++;
      }
    }
    if (count == 5)
      return 1;
  }

  // �����Խ���
  for (int i = -4; i <= 0; i++) {
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (row + i + j >= 0 && col + i + j >= 0 && row + i + j < BOARD_SIZE &&
          col + i + j < BOARD_SIZE &&
          board[row + i + j][col + i + j] == player) {
        count++;
      }
    }
    if (count == 5)
      return 1;
  }

  // ����ҶԽ���
  for (int i = -4; i <= 0; i++) {
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (row - i - j >= 0 && col + i + j >= 0 && row - i - j < BOARD_SIZE &&
          col + i + j < BOARD_SIZE &&
          board[row - i - j][col + i + j] == player) {
        count++;
      }
    }
    if (count == 5)
      return 1;
  }

  return 0; // δ��ʤ
}