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
    printf("玩家 %c，请输入您想下的位置（行 列）：", player);
    scanf("%d %d", &row, &col);

    if (makeMove(board, row - 1, col - 1, player)) {
      if (checkWin(board, row - 1, col - 1)) {
        printBoard(board);
        printf("玩家 %c 获胜！\n", player);
        break;
      }
      player = (player == 'X') ? 'O' : 'X';
    } else {
      printf("已经存在棋子，请重新输入。\n");
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
    return 1; // 成功放置棋子
  }
  return 0; // 位置无效或已被占用
}

int checkWin(char board[][BOARD_SIZE], int row, int col) {
  char player = board[row][col];
  int count;

  // 检查水平方向
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

  // 检查垂直方向
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

  // 检查左对角线
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

  // 检查右对角线
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

  return 0; // 未获胜
}