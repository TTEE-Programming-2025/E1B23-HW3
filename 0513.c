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
		printf("* * �w �� �� �{ * *\n");
		printf("\n");
		for ( i = 0; i < 5; i++) 
		printf("-------------------\n* * * * * * * * * *\n");
		system("pause");
		system("cls");

        while (attempts < MAX_TRY) {
        printf("�п�J 4 ��ƱK�X�G");
        scanf("%s", input);

        if (strcmp(input, PASSWORD) == 0) {
            printf("�K�X���T�A�n�J���\�C\n");
            break;
        } else {
            printf("�K�X���~�I\n");
            attempts++;
        }
    }

    if (attempts == MAX_TRY) {
        printf("�K�X���~�w�F�T���A�t����w�C\n");
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
        system("cls"); // �M���e���]Windows�^
        printf("\n----------[�y��w���t��]----------\n");
        printf("a. ��ܥثe�y�쪬�p\n");
        printf("b. �t�Φ۰ʦw�Ʈy��\n");
        printf("c. �ۦ��ܮy��\n");
        printf("d. ���}�t��\n");
        printf("----------------------------------\n");
        printf("�п�J�ﶵ�G");
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
            printf("�п�J�ݭn���y��ƶq (1~4)�G");
            scanf("%d", &n);
            if (n < 1 || n > 4) {
                printf("��J���~�A�Ъ�^�D���C\n");
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
                printf("�䤣��i�ήy��A��^�D���C\n");
                continue;
            }

            for ( i = 0; i < n; i++) {
                seats[r][c + i] = '@';
                assignedSeats[r][c + i] = '@';
            }

            printf("�t�ά��z�w�ƪ��y��p�U�G\n");
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
            printf("�z�O�_�����o�Ǯy��H(y/n)�G");
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
                printf("�y��w�T�{�I\n");
            else
                printf("�z�w�����C\n");

        } else if (choice == 'c') {
            int r, c;
            printf("�п�J����ܪ��y�� (�榡�p�G2-5)�G");
            scanf("%d-%d", &r, &c);

            if (r < 1 || r > SIZE || c < 1 || c > SIZE) {
                printf("��J�L�ġA��^�D���C\n");
                continue;
            }

            r--; c--;

            if (seats[r][c] != '-') {
                printf("���y��w�Q�w���A�Э��s��ܡC\n");
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
            printf("�O�_�T�{���y��H(y/n)�G");
            scanf(" %c", &confirm);

            if (confirm == 'y' || confirm == 'Y') {
                seats[r][c] = '*';
                printf("�y��w�T�{�I\n");
            } else {
                seats[r][c] = '-';
                assignedSeats[r][c] = '-';
                printf("�z�w��������ܡC\n");
            }

        } else if (choice == 'd') {
            char yn;
            printf("�O�_�~��ϥΨt�ΡH(y/n)�G");
            scanf(" %c", &yn);
            if (yn == 'y' || yn == 'Y')
                continue;
            else {
                printf("�P�¨ϥΡA�A���I\n");
                break;
            }
        } else {
            printf("�L�Ŀﶵ�A�Э��s��J�C\n");
        }

        printf("�Ы� Enter ���~��...");
        getchar(); getchar();
    }

    return 0;
}


