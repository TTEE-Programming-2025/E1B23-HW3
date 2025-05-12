#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int MAX_TRY = 3;
    int i,j,t;
    int SIZE = 9;
    char PASSWORD[] = "2025";

    char seats[9][9];
    char assignedSeats[9][9];

    int attempts = 0;
    char input[10];

        for ( i = 0; i < 5; i++) 
		printf("* * * * * * * * * *\n-------------------\n");
		printf("\n");
		printf("* * 歡 迎 光 臨 * *\n");
		printf("\n");
		for ( i = 0; i < 5; i++) 
		printf("-------------------\n* * * * * * * * * *\n");
		system("pause");
		system("cls");

        while (attempts < MAX_TRY) {
        printf("請輸入 4 位數密碼：");
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("密碼正確，登入成功。\n");
            break;
        } else {
            printf("密碼錯誤！\n");
            attempts++;
        }
    }

    if (attempts == MAX_TRY) {
        printf("密碼錯誤已達三次，系統鎖定。\n");
        return 0;
    }

    for ( i = 0; i < SIZE; i++)
        for ( j = 0; j < SIZE; j++) {
            seats[i][j] = '-';
            assignedSeats[i][j] = '-';
        }

    srand(1);
    int count = 0;
    while (count < 10) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }

    char choice;
    while (1) {
        system("cls"); // 清除畫面（Windows）
        printf("\n----------[座位預約系統]----------\n");
        printf("a. 顯示目前座位狀況\n");
        printf("b. 系統自動安排座位\n");
        printf("c. 自行選擇座位\n");
        printf("d. 離開系統\n");
        printf("----------------------------------\n");
        printf("請輸入選項：");
        scanf(" %c", &choice);

        if (choice == 'a') {
            printf("  123456789\n");
            for ( i = SIZE - 1; i >= 0; i--) {
                printf("%d ", i + 1);
                for ( j = 0; j < SIZE; j++) {
                    if (assignedSeats[i][j] == '@')
                        printf("@");
                    else
                        printf("%c", seats[i][j]);
                }
                printf("\n");
            }
        } else if (choice == 'b') {
            int n;
            printf("請輸入需要的座位數量 (1~4)：");
            scanf("%d", &n);
            if (n < 1 || n > 4) {
                printf("輸入錯誤，請返回主選單。\n");
                continue;
            }

            int found = 0, r, c;
            for ( t = 0; t < 100 && !found; t++) {
                r = rand() % SIZE;
                c = rand() % (SIZE - n + 1);
                found = 1;
                for ( i = 0; i < n; i++) {
                    if (seats[r][c + i] != '-') {
                        found = 0;
                        break;
                    }
                }
            }

            if (!found) {
                printf("找不到可用座位，返回主選單。\n");
                continue;
            }

            for ( i = 0; i < n; i++) {
                seats[r][c + i] = '@';
                assignedSeats[r][c + i] = '@';
            }

            printf("系統為您安排的座位如下：\n");
            printf("  123456789\n");
            for ( i = SIZE - 1; i >= 0; i--) {
                printf("%d ", i + 1);
                for ( j = 0; j < SIZE; j++) {
                    if (assignedSeats[i][j] == '@')
                        printf("@");
                    else
                        printf("%c", seats[i][j]);
                }
                printf("\n");
            }

            char confirm;
            printf("您是否接受這些座位？(y/n)：");
            scanf(" %c", &confirm);

            for ( i = 0; i < n; i++) {
                if (confirm == 'y' || confirm == 'Y')
                    seats[r][c + i] = '*';
                else {
                    seats[r][c + i] = '-';
                    assignedSeats[r][c + i] = '-';
                }
            }

            if (confirm == 'y' || confirm == 'Y')
                printf("座位已確認！\n");
            else
                printf("您已取消。\n");

        } else if (choice == 'c') {
            int r, c;
            printf("請輸入欲選擇的座位 (格式如：2-5)：");
            scanf("%d-%d", &r, &c);

            if (r < 1 || r > SIZE || c < 1 || c > SIZE) {
                printf("輸入無效，返回主選單。\n");
                continue;
            }

            r--; c--;

            if (seats[r][c] != '-') {
                printf("此座位已被預約，請重新選擇。\n");
                system("pause");
                continue;
            }

            seats[r][c] = '@';
            assignedSeats[r][c] = '@';

            printf("  123456789\n");
            for(i = SIZE - 1; i >= 0; i--) {
                printf("%d ", i + 1);
                for ( j = 0; j < SIZE; j++) {
                    if (assignedSeats[i][j] == '@')
                        printf("@");
                    else
                        printf("%c", seats[i][j]);
                }
                printf("\n");
            }

            char confirm;
            printf("是否確認此座位？(y/n)：");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {
                seats[r][c] = '*';
                printf("座位已確認！\n");
            } else {
                seats[r][c] = '-';
                assignedSeats[r][c] = '-';
                printf("您已取消此選擇。\n");
            }

        } else if (choice == 'd') {
            char yn;
            printf("是否繼續使用系統？(y/n)：");
            scanf(" %c", &yn);
            if (yn == 'y' || yn == 'Y')
                continue;
            else {
                printf("感謝使用，再見！\n");
                break;
            }
        } else {
            printf("無效選項，請重新輸入。\n");
        }

        printf("請按 Enter 鍵繼續...");
        getchar(); getchar();
    }

    return 0;
}


