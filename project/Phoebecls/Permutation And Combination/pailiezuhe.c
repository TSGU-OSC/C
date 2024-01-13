#include <stdio.h>

  void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void permute(int arr[], int n, int i) {
  if (i == n) {
    for (int j = 0; j < n; j++) {
      printf("%d ", arr[j]);
    }
    printf("\n");
  } else {
    for (int j = i; j < n; j++) {
      swap(&arr[i], &arr[j]);
      permute(arr, n, i + 1);
      swap(&arr[i], &arr[j]);
    }
  }
}

int main() {
  int arr[] = {1, 2, 3,4,5,6};
  int n = sizeof(arr) / sizeof(arr[0]);
  permute(arr, n, 0);
  return 0;
}