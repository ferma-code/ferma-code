#include <ncurses.h>

void calc_warning() {
    printw("Press any key to exit...\n");
    getch();
}

void calculator() {
    char op;
    int a, b;

    clear();
    echo();
    printw("Enter a example: ");
    scanw("%d %c %d", &a, &op, &b);

    switch (op) {
        case '+':
            printw("Answer: %d\n", a + b);
            calc_warning();
            break;
        case '-':
            printw("Answer: %d\n", a - b);
            calc_warning();
            break;
        case '*':
            printw("Answer: %d\n", a * b);
            calc_warning();
            break;
        case '/':
            if (b == 0) {
                printw("You cannot divide by zero!\n");
                calc_warning();
                break;
            } else {
                printw("Answer: %d\n", a / b);
                calc_warning();
                break;
            }
    }
    refresh();
}

void utilities_menu() {
    int key_u = 0;
    int selected_u = 0;

    while (1) {
        clear();
        noecho();
        printw("Tab: Utilities\n");

        mvprintw(2, 0, selected_u == 0 ? "> Calculator" : "  Calculator");
        mvprintw(3, 0, selected_u == 1 ? "> Exit tab: Utilities" : "  Exit tab: Utilities");

        key_u = getch();

        switch (key_u) {
            case KEY_UP:
                if (selected_u > 0)
                selected_u--;
                break;
            case KEY_DOWN:
                if (selected_u < 1)
                selected_u++;
                break;
            case '\n':
            if (selected_u == 1) {
                return;
            }
            if (selected_u == 0) {
                calculator();
            }
        }
        refresh();
    }
}

void main_menu() {
    int key = 0;
    int selected = 0;

    while (1) {
        clear();
        printw("Welcome to TUI-OS! (development)\n");

        mvprintw(2, 0, selected == 0 ? "> Utilities" : "  Utilities");
        mvprintw(3, 0, selected == 1 ? "> Exit" : "  Exit");

        key = getch();

        switch (key) {
            case KEY_UP:
                if (selected > 0)
                selected--;
                break;
            case KEY_DOWN:
                if (selected < 1)
                selected++;
                break;
            case '\n':
            if (selected == 1) {
                return;
            }
            if (selected == 0) {
                utilities_menu();
            }
        }
        refresh();
    }
}

int main() {
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    cbreak();

    main_menu();

    endwin();
    return 0;
}
