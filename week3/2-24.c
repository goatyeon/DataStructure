#include <stdio.h>
#include <string.h>

#define MAX 100

// 주소록 항목 구조체 정의
typedef struct {
    char name[30];
    char phone[20];
    char address[100];
    char birthday[20];
} Contact;

Contact book[MAX];
int count = 0;

// 목록 출력
void listContacts() {
    printf("\n[주소록 목록]\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. 이름: %s\n   전화번호: %s\n   주소: %s\n   생일: %s\n", 
               i + 1, book[i].name, book[i].phone, book[i].address, book[i].birthday);
    }
    if (count == 0)
        printf("저장된 주소가 없습니다.\n");
}

// 주소 추가
void addContact() {
    if (count >= MAX) {
        printf("주소록이 가득 찼습니다.\n");
        return;
    }

    printf("이름: ");
    fgets(book[count].name, sizeof(book[count].name), stdin);
    strtok(book[count].name, "\n"); // 개행 제거

    printf("전화번호: ");
    fgets(book[count].phone, sizeof(book[count].phone), stdin);
    strtok(book[count].phone, "\n");

    printf("주소: ");
    fgets(book[count].address, sizeof(book[count].address), stdin);
    strtok(book[count].address, "\n");

    printf("생일: ");
    fgets(book[count].birthday, sizeof(book[count].birthday), stdin);
    strtok(book[count].birthday, "\n");

    count++;
    printf("주소가 추가되었습니다.\n");
}

// 주소 탐색
void searchContact() {
    char searchName[30];
    printf("찾을 이름: ");
    fgets(searchName, sizeof(searchName), stdin);
    strtok(searchName, "\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, searchName) == 0) {
            printf(">> 이름: %s\n   전화번호: %s\n   주소: %s\n   생일: %s\n", 
                   book[i].name, book[i].phone, book[i].address, book[i].birthday);
            found = 1;
        }
    }
    if (!found)
        printf("해당 이름이 없습니다.\n");
}

// 주소 삭제
void deleteContact() {
    char deleteName[30];
    printf("삭제할 이름: ");
    fgets(deleteName, sizeof(deleteName), stdin);
    strtok(deleteName, "\n");

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].name, deleteName) == 0) {
            for (int j = i; j < count - 1; j++) {
                book[j] = book[j + 1];
            }
            count--;
            found = 1;
            printf("삭제되었습니다.\n");
            break;
        }
    }
    if (!found)
        printf("해당 이름이 없습니다.\n");
}

// 메인 함수
int main() {
    int choice;

    while (1) {
        printf("\n[주소록 프로그램 메뉴]\n");
        printf("1. 목록 보기\n2. 추가하기\n3. 탐색하기\n4. 삭제하기\n5. 종료\n선택: ");
        scanf("%d", &choice);
        getchar(); // 버퍼 비우기

        switch (choice) {
            case 1: listContacts(); break;
            case 2: addContact(); break;
            case 3: searchContact(); break;
            case 4: deleteContact(); break;
            case 5: printf("프로그램을 종료합니다.\n"); return 0;
            default: printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}
