#include <stdio.h>
#include <ctype.h> // 대소문자 판별 및 변환 함수 포함

int main() {
    char str[100];

    // 입력
    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    // 변환 및 출력
    printf("변환된 문자열: ");
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            // 대문자 → 소문자
            printf("%c", tolower(str[i]));
        } else if (islower(str[i])) {
            // 소문자 → 대문자
            printf("%c", toupper(str[i]));
        } else {
            // 공백, 숫자 등은 그대로 출력
            printf("%c", str[i]);
        }
    }

    return 0;
}
