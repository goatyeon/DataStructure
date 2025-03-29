#include <stdio.h>

int main() {
    char strings[5][100]; // 5개의 문자열, 각 최대 99글자 + '\0'

    // 문자열 입력
    printf("문자열 5개를 입력하세요:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d번째 문자열: ", i + 1);
        fgets(strings[i], sizeof(strings[i]), stdin);
    }

    // 입력한 문자열 출력
    printf("\n입력한 문자열은 다음과 같습니다:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d: %s", i + 1, strings[i]);
    }

    return 0;
}
