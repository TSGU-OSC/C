#include <stdbool.h>
#include <stdio.h>

const int maxa = 13;       // 最大值
int arry[maxa] = {0};      // 初始数组
bool flag[maxa] = {0}; // 标记数组
void generatep(int index);  // 递归插入数组
int n;
int main() {
  n = 3;
  generatep(1);
  return 0;
}
void generatep(int index) {
  if (index == n + 1) {
    for (int i = 1; i <= n; i++) { // 数组从1开始存元素
      printf("%d", arry[i]);
    }
    printf("\n");
  }
  for (int j = 1; j <= n; j++) {
    if (flag[j] == false) {
      arry[index] = j;
      flag[j] = true;       // 标记
      generatep(index + 1); // 递归下一个位置
      flag[j] = false;      // 还原
    }
  }
}

/*这段代码还原的执行时刻是在 `generatep`
函数中，当需要往数组中插入元素的时候。具体来说，当 `generatep`
函数递归到需要往数组中插入元素的位置时，会执行以下步骤：

1. 判断当前位置是否已经到了数组的末尾，如果是，则输出当前数组中的所有元素。
2. 否则，从1到n进行循环，如果当前数字没有被标记过（即 `flag[j] ==
false`），则将当前数字插入到数组中，并将 `flag[j]` 置为 `true`
以标记该数字已经使用过。然后递归执行 `generatep` 函数，下一个位置的值为 `index +
1`。
3. 在递归返回后，将 `flag[j]` 还原为 `false`，以便下次使用。

因此，这段代码还原的执行时刻就是每次往数组中插入新元素的时候。*/