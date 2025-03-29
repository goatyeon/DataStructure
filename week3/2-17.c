#include <stdio.h>

#define STUDENTS 10
#define SUBJECTS 3

int main() {
    // [학번][0:국어, 1:영어, 2:수학, 3:총점, 4:평균]
    int scores[STUDENTS][5];

    // 예시 점수 (임의 설정)
    int korean[STUDENTS] = {80, 70, 85, 90, 60, 75, 88, 92, 66, 78};
    int english[STUDENTS] = {70, 60, 82, 85, 64, 77, 81, 95, 72, 80};
    int math[STUDENTS] = {90, 85, 88, 95, 70, 83, 90, 96, 68, 79};

    // 데이터 저장 및 계산
    for (int i = 0; i < STUDENTS; i++) {
        scores[i][0] = korean[i];
        scores[i][1] = english[i];
        scores[i][2] = math[i];
        scores[i][3] = korean[i] + english[i] + math[i]; // 총점
        scores[i][4] = scores[i][3] / SUBJECTS;          // 평균
    }

    // 출력
    printf("학번  국어  영어  수학  총점  평균\n");
    printf("****************************************\n");
    for (int i = 0; i < STUDENTS; i++) {
        printf("%2d    %3d   %3d   %3d   %3d   %3d\n",
               i + 1,
               scores[i][0], scores[i][1], scores[i][2],
               scores[i][3], scores[i][4]);
    }

    return 0;
}
