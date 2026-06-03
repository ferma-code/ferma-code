#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[3];

    for (int i = 0; i < 3; i++) {
        printf("Введите число или цифру: ");
        system("clear");

        if (scanf("%d", &numbers[i]) != 1) {
            printf("Ошибка, вы что-то не так сделали!\n");
            return 1;
        }
    }

    int max = numbers[0];
    int min = numbers[0];

    for (int i = 0; i < 3; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < min) {
                min = numbers[i];
        }
    }
    system("clear");

    printf("Максимальное число(цифра): %d\n", max);
    printf("Минимальное число(цифра): %d\n", min);
    return 0;
}
