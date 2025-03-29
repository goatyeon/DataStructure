#include <stdio.h>
#include <math.h>

int main() {
    int arr[] = {19, 2, 25, 92, 36, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // ① 배열 출력
    printf("배열 원소: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ② 최소값과 최대값
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("최소값: %d\n", min);
    printf("최대값: %d\n", max);

    // ③ 평균
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double avg = sum / n;
    printf("평균: %.2f\n", avg);

    // ④ 분산
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += (arr[i] - avg) * (arr[i] - avg);
    }
    variance /= n;
    printf("분산: %.2f\n", variance);

    return 0;
}
