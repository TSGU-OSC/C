#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_STUDENTS 100
#define FILENAME "students.dat"
typedef struct {
    char name[50];
    char id[20];
    float score;
} Student;
void printStudents(Student students[], int count) {
    printf("\n学生管理系统 - 学生列表\n");
    printf("----------------------------\n");
    printf("姓名\t学号\t成绩\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%.2f\n", students[i].name, students[i].id, students[i].score);
    }
    printf("----------------------------\n");
}
void saveStudentsToFile(Student students[], int count) {
    FILE *file = fopen(FILENAME, "wb");
    if (file == NULL) {
        printf("无法打开文件进行写入！\n");
        return;
    }
    fwrite(students, sizeof(Student), count, file);
    fclose(file);
    printf("学生信息已保存到文件。\n");
}
int loadStudentsFromFile(Student students[]) {
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL) {
        printf("无法打开文件进行读取！\n");
        return 0;
    }
    int count = 0;
    while (fread(&students[count], sizeof(Student), 1, file) == 1) {
        count++;
    }
    fclose(file);
    printf("%d名学生信息已从文件加载。\n", count);
    return count;
}
void sortStudentsByScore(Student students[], int count) {
    Student temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].score > students[j + 1].score) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
void modifyStudentScore(Student students[], int *count) {
    char id[20];
    printf("请输入要修改成绩的学生学号: ");
    scanf("%s", id);
    for (int i = 0; i < *count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("找到学生，当前成绩为: %.2f\n", students[i].score);
            printf("请输入新的成绩: ");
            scanf("%f", &students[i].score);
            printf("成绩已更新为: %.2f\n", students[i].score);
            saveStudentsToFile(students, *count);
            sortStudentsByScore(students, *count);
            return;
        }
    }
    printf("未找到指定的学生学号。\n");
}
int main() {
    Student students[MAX_STUDENTS];
    int studentCount = loadStudentsFromFile(students);
    char choice;
    do {
        printf("\n学生管理系统\n");
        printf("----------------------------\n");
        printf("1. 添加学生\n");
        printf("2. 显示学生列表\n");
        printf("3. 修改学生成绩\n");
        printf("4. 退出\n");
        printf("请输入您的选择: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1': {
                if (studentCount >= MAX_STUDENTS) {
                    printf("学生数量已达到上限！\n");
                    break;
                }
                printf("输入学生姓名: ");
                scanf("%s", students[studentCount].name);
                printf("输入学生学号: ");
                scanf("%s", students[studentCount].id);
                printf("输入学生成绩: ");
                scanf("%f", &students[studentCount].score);
                studentCount++;
                saveStudentsToFile(students, studentCount);
                sortStudentsByScore(students, studentCount);
                break;
            }
            case '2':
                printStudents(students, studentCount);
                break;
            case '3':
                modifyStudentScore(students, &studentCount);
                break;
            case '4':
                printf("退出学生管理系统。\n");
                break;
            default:
                printf("无效的选项，请重新输入。\n");
                break;
        }
    } while (choice != '4');
    return 0;
}
